package com.ta.sample;

import java.io.File;

import com.ta.core.MarkingProcess;
import com.ta.core.BatchProcess;
import com.ta.core.ManualMarker;
import com.ta.core.Marksheet;
import com.ta.core.BatchProcess.ItemAction;
import com.ta.core.extraction.Extract;

public class MarkA1 extends BatchProcess{
	
	public static void main(String[] args) {
		
		//TO DO: pull from a config file 
		String[] archiveFormats = {"zip","rar",".7z"};
		String[] format = {"java"};
		//String sourceDir = "C:\\Users\\krism\\Downloads\\Kris";
		//String sourceDir = "C:\\Users\\krism\\Downloads\\missed";
		String sourceDir = "C:\\Users\\krism\\Downloads\\moss-special";
		
		String outputDir = "C:\\Users\\krism\\Projects\\Java\\COMP2603Marker\\output-test";
		//String outputDir = "C:\\Users\\krism\\Projects\\Java\\COMP2603Marker\\output-missed";
		//String outputDir = "C:\\Users\\krism\\Projects\\Java\\COMP2603Marker\\output";
		//String outputDir = "C:\\Users\\krism\\Projects\\Java\\COMP2603Marker\\output-last";
		
		String markSlipDir = "C:\\Users\\krism\\Projects\\Java\\COMP2603Marker\\markslips";
		String markingSlipName = "Assignment_1_Makring_Slip-new.xlsx";
		String masterSheetName = "Master.xlsx";
		
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
		    	if(item.isDirectory())
		    		return performActionInFile(item,this);
		    	else if(isAnAllowedArchive(item.getName(),archiveFormats)){
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
		    	
		    	return true;
			}
        };
        
        ItemAction markA1 = new ItemAction(){

			@Override
			public boolean doAction(File item) {
				if(item.isDirectory()){
					String filename = markingSlipName;
					MarkingProcess pm = new MarkingProcess(item,filename);
					pm.addMarker(new InsertHeader(item.getName()));
					pm.addMarker(new ManualMarker("Booking Class", "BookClass.txt"));
					pm.addMarker(new ManualMarker("Room Class", "RoomClass.txt"));
					pm.addMarker(new ManualMarker("Rental System Class", "RentalSystemClass.txt"));
					pm.addMarker(new ManualMarker("Rental Console Class", "RentalConsoleClass.txt"));
					pm.addMarker(new TestCaseMaker("Working Program and Documentation","TestCases.txt"));
					pm.markAll();
					pm.saveMarkingSlip();
					//should move files to a marked folder so don't accidentally overwrite them
				}
				return true;
			}
        	
        };
        
        ItemAction buildMasterMarksheet = new ItemAction(){

			@Override
			public boolean doAction(File item) {
				
				if(item.isDirectory()){
					
					String filename = markingSlipName;
					Marksheet markingSlip = new Marksheet(item.getAbsolutePath(), filename, true);
					markingSlip.loadOrCreateSheet(MarkingProcess.getSheetWithMarksName());
					
					if(!markingSlip.hasText(MarkingProcess.getFinalTotalPrefix(), 1))
						System.out.print("CEHCK "+ item.getName());
					else{
						MarkingProcess.getMasterSheet(outputDir, masterSheetName).writeRowln(item.getName(),markingSlip.getTextFromColInLastRow(2));
						System.out.println(item.getName()+" " + markingSlip.getTextFromColInLastRow(2));
					}
					
					markingSlip.close();
				}
				return true;
			}
        	
        };
        
        ItemAction saveMasterMarksheet = new ItemAction(){
			@Override
			public boolean doAction(File item) {
				MarkingProcess.getMasterSheet(outputDir, masterSheetName).writeExcelFile();
				return true;
			}
        };
        
        ItemAction gatherMarkingSlips = new ItemAction(){

			@Override
			public boolean doAction(File item) {
				
				if(item.isDirectory()){
					
					String filename = markingSlipName;
					Marksheet markingSlip = new Marksheet(item.getAbsolutePath(), filename, true);
					markingSlip.loadOrCreateSheet("A1");
					
					String name = markingSlip.getTextFromCell(1, 0);
					name = name.split("_")[0];
					System.out.println(name);
					
					markingSlip.setCurrentRow(0);
					markingSlip.writeRowln(name);
					markingSlip.writeRowln("");
//					if(!markingSlip.hasText(A1Marker.getFinalTotalPrefix(), 1))
//						System.out.print("CEHCK "+ item.getName());
//					else{
//						A1Marker.getMasterSheet(outputDir, masterSheetName).writeRowln(item.getName(),markingSlip.getTextFromColInLastRow(2));
//						System.out.println(item.getName()+" " + markingSlip.getTextFromColInLastRow(2));
//					}
					
					
					markingSlip.writeExcelFile();
					markingSlip.close();
					
					//copy
					copyAndReplaceFileTo(item.getAbsolutePath() + File.separator + filename, markSlipDir + File.separator + name+ ".xlsx");
				}
				return true;
			}
        	
        };
        
		try {
            File file = new File(sourceDir);
			//performActionInFile(file, extractArchive);
            
			//performActionInFile(new File(outputDir), gatherMarkingSlips);
            if(performActionInFile(file,validateZip)){
            	System.out.println("All archives OK");
//            	//proceed with other actions
             	if(performActionInFile(file, extractArchive)){
//            		System.out.println("All archives extracted OK");
//            		performActionInFile(new File(outputDir), markA1);
//            		//performActionInFileFromStartToEnd(new File(outputDir), markA1,0,-1);
//            		//System.out.println("Finished Marking");
//            		//performActionInFileFromStartToEndAndCloseAction(new File(outputDir), buildMasterMarksheet,0,-1,saveMasterMarksheet);
//            
            	}
            }
//            else{
//            	System.out.println("Fix archive");
//            	System.exit(1);
//            }
     
        }catch(Exception e) {
            System.err.println("Error!");
        }

	}

}
