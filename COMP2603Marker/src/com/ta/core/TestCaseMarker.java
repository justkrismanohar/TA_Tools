package com.ta.core;

import java.io.File;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public abstract class TestCaseMarker extends Marker{

	
	protected abstract String[] getTestCaseClassNames();
	protected abstract String[] getStudentClassNames();
	
	private static Marksheet workingMarksheet;
	protected String sourceDir; 
	protected String srcFilesToOpen;
	
	protected CompilationMarker compilationMarker;
	
	protected TestCaseMarker(String sourceDir){
		this.sourceDir = sourceDir;
		this.compilationMarker = new CompilationMarker(markingProcess);
	}
	
	public static Marksheet getWorkingMarksheet(){
		return workingMarksheet;
	}
	
//	@Override
//	public void setMarksheet(Marksheet m){
//		super.setMarksheet(m);
//		this.compilationMarker.setMarksheet(m);
//	}
	
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
	public void setMarkingProcess(MarkingProcess mp) {
		super.setMarkingProcess(mp);
		this.compilationMarker.setMarkingProcess(mp);
	}
	
	@Override
	public void mark() {
		
		Marksheet markingSlip = getMarksheet();
		
		
		markingProcess.openJavaFilesInNotepad(srcFilesToOpen);
		markingProcess.runCommand("start", markingSlip.getDirPath());
		//Compile student classes
    	CompilationResults studentClassesCR = complieAndLoadStudentClasses();
    	markStudentCompilation(studentClassesCR);
		
    	//Compile and run Test cases
    	CompilationResults testCasesCR = copyAndComplieTestClasses();
		printTestCasesCompilation(testCasesCR);

		JUnitCore junit = new JUnitCore();
    	junit.addListener(new JUnitExecutionListener(System.out,getMarksheet()));
		markingSlip.writeRowBoldln("Test Cases");
    	markingSlip.writeRowBoldln("Test Class","Test Method","Mark","OutOf","Comment");
		Result result = junit.run(getSuccessfullyCompliedClasses(testCasesCR));
	    
        resultReport(result);    		
	
        int actualTestsExecuted = result.getRunCount();
        int testsNotExecuted = (int)(totalOutOf - actualTestsExecuted);
        
        this.total = (totalOutOf == defaultTotalOutOf) ? actualTestsExecuted : totalOutOf;
        //this.total -= result.getFailureCount();//Seems to mess up the totals somehow. Just minus passed test from total test.
        //this.total -= result.getIgnoreCount();
        this.total -= testsNotExecuted;
        
        if(testsNotExecuted > 0){
        	markingSlip.writeRowBoldln("",testsNotExecuted+" tests did not compile", " Compilation errors");
        }
        
        markingSlip.writeRowln("","TOTAL",Float.toString(total),"/"+Float.toString(totalOutOf));
        System.out.println("TOTAL "+Float.toString(total)+"/"+Float.toString(totalOutOf));
	}
	
	
	protected void markStudentCompilation(CompilationResults cr){
		compilationMarker.setCompilationResults(cr);
		compilationMarker.mark();
	}
	
	protected void printTestCasesCompilation(CompilationResults cr){
		System.out.println("Test Cases Compilation");
		for(String className : cr.getFailureCompilationArray()){
			System.out.println(className + " does not complie");
		}

		for(String className : cr.getSuccessCompilationArray()){
			System.out.println(className + " compiles");
		}
	}
	
	protected boolean isClassLoaded(String name){
 		return AutoMarker.getExternallyLoadedClass(name) != null;
	}
	
	@Override
	public float getTotal(){
		return total + compilationMarker.getTotal();
	}
	
	
	@Override
	public float getTotalOutOf(){
		return totalOutOf + compilationMarker.getTotal();
	}
	
}
