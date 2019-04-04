package com.ta.core;

import java.io.File;
import java.io.IOException;

public abstract class Marker {
	
	protected final float defaultTotalOutOf = Float.MIN_VALUE;
	private Marksheet markingSlip;
	protected float total;
	protected float totalOutOf;
	protected String openFilesCmd = "\"C:\\Program Files (x86)\\Notepad++\\notepad++.exe\" -nosession -multiInst ";
	protected String srcFilesToOpen = " *.java";
		
	public Marker(){
		total = 0;
		totalOutOf = defaultTotalOutOf;
	}
	
	public Marker(Marksheet m){
		markingSlip = m;
		total = 0;
	}
	
	public Marksheet getMarksheet(){
	
		return markingSlip;
	}
	
	public void setMarksheet(Marksheet m){
		markingSlip = m;
	}
	
	public float getTotal(){
		return total;
	}
	
	protected void addToTotal(float mark){
		total += mark;
	}
	
	public float getTotalOutOf(){
		return totalOutOf;
	}

	public abstract void mark();
	
	protected void openJavaFilesInNotepad() {
		runCommand(openFilesCmd  +srcFilesToOpen, getMarksheet().getDirPath());
//		try {
//			Runtime rt = Runtime.getRuntime();
//			rt.exec("cmd.exe /c "+openFilesCmd  +srcFilesToOpen, null, new File(getMarksheet().getDirPath()));
//			
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
	}
	
	protected void runCommand(String command,String path){
		try {
			Runtime rt = Runtime.getRuntime();
			File dir = new File(path);			
			rt.exec("cmd.exe /c " +command, null, dir);
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
