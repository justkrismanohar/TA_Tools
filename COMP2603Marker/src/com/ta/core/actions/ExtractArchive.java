package com.ta.core.actions;
import java.io.File;

import com.ta.core.BatchProcess;
import com.ta.core.extraction.Extract;

public class ExtractArchive implements BatchProcess.ItemAction, Action {

	
	private String[] archiveFormats;
	String[] format = {"java"};
	private String outputDir;
	File file;
	
	public ExtractArchive(String[] archiveFormats, String[] format, File source, String outputDir){
		this.archiveFormats = archiveFormats;
		this.format = format;
		this.outputDir = outputDir;
		file = source;
	}
	
	public boolean doBefore(File item) {return true;}
	
	@Override
	public boolean doAction(File item) {
    	if(item.isDirectory())
    		return BatchProcess.performActionInFile(item,this);
    	else if(BatchProcess.isAnAllowedArchive(item.getName(),archiveFormats)){    		
    		return doBefore(item) && doExtraction(item) && doAfter(item);
    	}
    	
    	return true;
	}

	public boolean doExtraction(File item) {
		try{	
			Extract.extract(outputDir+File.separator+item.getParentFile().getName(), item.getAbsolutePath(),format);
			return true;
		}
		catch(Exception e){
			System.err.println("Error Extracting");
			System.err.println(item.getAbsolutePath());
			e.printStackTrace();
			return false;
		}
	}
	
	private boolean doAfter(File item){ return true;}

	@Override
	public void run() {
     	//if(BatchProcess.performActionInFile(file, this)){
		if(doAction(file)){
    		System.out.println("All archives extracted OK");
    		return;
    	}
	}

}
