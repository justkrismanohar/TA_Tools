package com.ta.core;

import java.io.File;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public abstract class TestCaseMarker extends Marker{

	
	protected abstract String[] getTestCaseClassNames();
	protected abstract String[] getStudentClassNames();
	
	private static Marksheet workingMarksheet;
	protected String sourceDir; 
	
	protected TestCaseMarker(String sourceDir){
		this.sourceDir = sourceDir;
	}
	
	public static Marksheet getWorkingMarksheet(){
		return workingMarksheet;
	}
	
	
	public static void resultReport(Result result) {
	    System.out.println("Finished. Result: Failures: " +
	      result.getFailureCount() + ". Ignored: " +
	      result.getIgnoreCount() + ". Tests run: " +
	      result.getRunCount() + ". Time: " +
	      result.getRunTime() + "ms.");
	}
	
	private CompilationResults complieAndLoadStudentClasses(){
		String[] classes = getStudentClassNames();
		String dirPath = getMarksheet().getDirPath();
		AutoMarker.clearExternallyLoadedClasses();
		return AutoMarker.loadAndComplieClassesFromDir(classes, dirPath);	
	}
	
	private String[] convertClassNamesToJavaFileNames(String[] names){
		String[] javaFileNames = new String[names.length];
		for(int i=0; i < names.length; i++){
			javaFileNames[i] = names[i]+".java";
		}
		return javaFileNames;
	}
	
	protected CompilationResults copyAndComplieTestClasses(){
		String[] testClasses = getTestCaseClassNames();
		String desPath = getMarksheet().getDirPath();
		BatchProcess.copyAndReplaceMultipleFiles(
				convertClassNamesToJavaFileNames(testClasses),
				sourceDir,
				desPath);
		return AutoMarker.loadAndComplieClassesFromDir(testClasses, desPath);	
	}
	
	protected  Class[] getSuccessfullyCompliedClasses(CompilationResults cr){
		//String[] testClasses = getTestCaseClassNames();
		String[] testClasses = cr.getSuccessCompilationArray();
		return AutoMarker.getExternallyLoadedClasses(testClasses);
	}
	
	@Override
	public void mark() {
		JUnitCore junit = new JUnitCore();
    	junit.addListener(new JUnitExecutionListener(System.out,getMarksheet()));
    	
    	CompilationResults studentClassesCR = complieAndLoadStudentClasses();
    	markStudentCompilation(studentClassesCR);
    	
		CompilationResults testCasesCR = copyAndComplieTestClasses();
		printTestCasesCompilation(testCasesCR);
		
		printHeader();
		Result result = junit.run(getSuccessfullyCompliedClasses(testCasesCR));
	    
        resultReport(result);    		
	
        this.totalOutOf = result.getRunCount();
        this.total = this.totalOutOf - result.getFailureCount() - result.getIgnoreCount();
	}
	
	protected void markStudentCompilation(CompilationResults cr){}
	
	protected void printTestCasesCompilation(CompilationResults cr){
		System.out.println("Test Cases Compilation");
		for(String className : cr.getFailureCompilationArray()){
			System.out.println(className + " does not complie");
		}

		for(String className : cr.getSuccessCompilationArray()){
			System.out.println(className + " complies");
		}
	}
	
	protected boolean isClassLoaded(String name){
 		return AutoMarker.getExternallyLoadedClass(name) != null;
	}
	
}
