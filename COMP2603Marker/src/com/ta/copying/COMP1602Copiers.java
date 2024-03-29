package com.ta.copying;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;

import com.ta.core.BatchProcess;
import com.ta.core.BatchProcess.ItemAction;
import com.ta.core.extraction.Extract;

public class COMP1602Copiers extends BatchProcess{
	
	public static void main(String[] args) {
		
		//TODO pull from a config file 
		String[] archiveFormats = {"zip","rar",".7z"};
		String[] format = {"cpp"};
		//String sourceDir = "C:\\Users\\krism\\Downloads\\OneDrive-2019-03-12";
		String sourceDir = "C:\\Users\\krism\\Downloads\\moss-special";
		//String outputDir = "C:\\Users\\krism\\Projects\\Java\\COMP2603Marker\\comp1602-copiers";
		String outputDir = "C:\\Users\\krism\\Projects\\Java\\COMP2603Marker\\comp1602-special";
		
		ItemAction validateZip = new ItemAction(){

			@Override
			public boolean doAction(File item) {
		    	if(item.isDirectory())
		    		return performActionInFile(item,this);
		    	else if(isAnAllowedArchive(item.getName(),archiveFormats)){
		    		return openArchive(item.getAbsolutePath());
		    	}
//		    	else{
//			    	System.out.println(item.getName() +" is not an allowed acrhive.");
//			    	return false;
//		    	}
		    	return true;
			}
        	
        };
        
        ItemAction extractArchive = new ItemAction(){

			@Override
			public boolean doAction(File item) {
		    	if(item.isDirectory()){//is a folder so recurse
		    		return performActionInFile(item,this);
		    	}
		    	else if(isAnAllowedArchive(item.getAbsolutePath(),archiveFormats)){//is an archive so extract 
		    		try{	
		    			String cleanItemName = Extract.cleanFileName(item.getParentFile().getName());
						Extract.extractForMoss(outputDir,cleanItemName, item.getAbsolutePath(),format);
						return true;
					}
					catch(Exception e){
						System.err.println("Error Extracting");
						System.err.println(item.getAbsolutePath());
						e.printStackTrace();
						return false;
					}
		    	}
		    	else if(Extract.isAnAllowedItem(item.getAbsolutePath(), format)){//is a file so copy
		    		//https://stackoverflow.com/questions/16433915/how-to-copy-file-from-one-location-to-another-location
		    		try {
						Files.copy(item.toPath(),(
								new File(
										outputDir+File.separator+Extract.cleanFileName(item.getParentFile().getName()
									)+".cpp"
								)).toPath(), StandardCopyOption.REPLACE_EXISTING);
						
					} catch (IOException e) {
						e.printStackTrace();
					}	    			
		    	}
		    	
		    	return true;
			}


        };
                
		try {
			
            File file = new File(sourceDir);
            if(performActionInFile(file,validateZip)){
            	System.out.println("All archives OK");
            	//proceed with other actions
             	if(performActionInFile(file, extractArchive)){
            		System.out.println("All archives extracted OK");
            		System.out.println("\n1. Copy all files to folder in /home for cygwin64");
            		System.out.println("2. Copy moss.pl to same dir");
            		System.out.println("3. cd to that directory");
            		System.out.println("4. Execute ./moss.pl -l cc *.cpp"); 
            	}
            }
            else{
            	System.out.println("Fix archive");
            	System.exit(1);
            }
     
        }catch(Exception e) {
            System.err.println("Error!");
        }

	}

}
