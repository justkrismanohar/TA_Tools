package com.ta.core;

import java.io.PrintStream;

import org.junit.runner.Description;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;
import org.junit.runner.notification.RunListener;

public class JUnitExecutionListener extends RunListener {
	
    private final PrintStream writer;
    private Marksheet markingSlip;
    
    public JUnitExecutionListener(PrintStream out,Marksheet markingSlip){
    	this.writer = out;
    	this.markingSlip = markingSlip;
    }
    
    public void testFailure(Failure failure) throws Exception {
    	String[] parts = failure.getDescription().getClassName().split("\\.");
    	String className = parts[parts.length-1];
    	String methodName = failure.getDescription().getMethodName();
    	
    	//Not ideal but okay for now
    	String suggestion = failure.getMessage().split("\n")[0];
    	
    	this.markingSlip.writeRowln(className,methodName,suggestion);
        writer.println(className + " " + methodName + " -> "+suggestion);
    }

}