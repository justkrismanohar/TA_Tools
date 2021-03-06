package com.ta.core.actions;

import java.io.File;

import com.ta.core.BatchProcess;
import com.ta.core.BatchProcess.ItemAction;

public class ValidateZip implements BatchProcess.ItemAction, Action {
	private String[] archiveFormats;
	private File file;
	public ValidateZip(File file, String[] archiveFormats){
		this.file = file;
		this.archiveFormats = archiveFormats;
	}
	
	@Override
	public boolean doAction(File item) {
    	if(item.isDirectory())
    		return BatchProcess.performActionInFile(item,this);
    	else if(BatchProcess.isAnAllowedArchive(item.getName(),archiveFormats)){
    		return BatchProcess.openArchive(item.getAbsolutePath());
    	}

    	return true;
	}

	@Override
	public void run() throws IncompleteActionException{
	    if(BatchProcess.performActionInFile(file,this)){
        	System.out.println("All archives OK");
        	return;
        }
		
    	throw new IncompleteActionException("Fix Archive");
		
	}

}
