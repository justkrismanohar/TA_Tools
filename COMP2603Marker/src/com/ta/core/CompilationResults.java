package com.ta.core;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CompilationResults {
	//TO DO Need a better way to do this
	public static String CANNOT_COMPILE = "Cannot complie";
	public static String COMPLIES = "Compiles";
	public static String FILE_NOT_FOUND = "File not found";
	
	private List<String> success, failure,fileNotFound;
	
	public CompilationResults(){
		this.success = new ArrayList<String>();
		this.failure = new ArrayList<String>();
		this.fileNotFound = new ArrayList<String>();
	}
	
	public String[] getSuccessCompilationArray(){
		return this.success.toArray(new String[success.size()]);
	}
	
	public String[] getFailureCompilationArray(){
		return this.failure.toArray(new String[failure.size()]);
	}
	
	public void recordSuccess(String key){
		success.add(key);
	}
	
	public void recordFailure(String key){
		failure.add(key);
	}
	
	public void recordFileNotFound(String key){
		fileNotFound.add(key);
	}
	
	public int numFailures(){
		return this.failure.size();
	}
	
	public int numSuccess(){
		return this.success.size();
	}
	
	public int numFileNotFound(){
		return this.fileNotFound.size();
	}
}
