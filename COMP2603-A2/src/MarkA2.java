

import java.io.File;

import com.ta.core.MarkingProcess;
import com.ta.core.Marksheet;
import com.ta.core.BatchProcess;
import com.ta.core.ManualMarker;
import com.ta.core.BatchProcess.ItemAction;
import com.ta.core.extraction.Extract;
import com.ta.core.Marker;
import com.ta.sample.InsertHeader;
/*
 * Need to have the sample student files and test files in a separate folder, so those .class files
 * are not in the classpath of the current java execution. Otherwise, the java runtime will ignore 
 * the .class files for the actual student code. That is, it will bind to the .class files from the 
 * sample student files.
 * 
 */

public class MarkA2 extends BatchProcess {
	
    public static void main(String[] args){
    	System.out.println("this is not working");
//<<<<<<< HEAD
    	//String outputDir = "C:\\Users\\krism\\Projects\\Java\\COMP2603Marker\\output-test";
    	//String outputDir = "C:\\Users\\krism\\Downloads\\A2\\9-Missed";
    	String outputDir = "C:\\Users\\jlm91\\Desktop\\A2\\Missed";
    	
//=======
    	
		String[] archiveFormats = {"zip","rar",".7z"};
		String[] format = {"java"};
		
		String sourceDir = "C:\\Users\\jlm91\\Desktop\\A2\\submissions";
		//String sourceDir = "C:\\Users\\krism\\Downloads\\A2\\submissions";
    	//String outputDir = "C:\\Users\\krism\\Downloads\\A2\\output";
    	//String outputDir = "C:\\Users\\krism\\Downloads\\A2\\3-Brave2";
		//String outputDir = "C:\\Users\\krism\\Downloads\\A2\\1-Kris";
    	//String outputDir = "C:\\Users\\krism\\Downloads\\A2\\4-Buggy";
		//String outputDir = "C:\\Users\\krism\\Downloads\\A2\\5-Others";
		//String outputDir = "C:\\Users\\krism\\Downloads\\A2\\8-Queries-zip";
		String markSlipDir = "C:\\Users\\jlm91\\Desktop\\A2\\markslips";
		
		//String outputDir = "C:\\Users\\krism\\Projects\\Java\\COMP2603Marker\\output-test";
//>>>>>>> 70c22c54adb73f1564c65293065ff971f0520836
    	String markingSlipName = "Assignment_2_Makring_Slip.xlsx";
    	//String testCasesDir = "C:\\Users\\krism\\Projects\\Java\\COMP2603-A2-Test-Student\\src";
    	String testCasesDir = "..\\COMP2603-A2-Test-Student\\src";
		String masterSheetName = "Master.xlsx";
    	
		ItemAction validateZip = new ItemAction(){

			@Override
			public boolean doAction(File item) {
				System.out.println("validate zip");
		    	if(item.isDirectory())
		    		return performActionInFile(item,this);
		    	else if(isAnAllowedArchive(item.getName(),archiveFormats)){
		    		return openArchive(item.getAbsolutePath());
		    	}
//		    	else{
//			    	System.out.println(item.getName() +" is not an allowed acrhive.");
//			    	return false;
//		    	}
		    	System.out.println("Check archive");
		    	System.out.println(item);
		    	return false;
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
			public boolean doAction(File fileItem) {
				System.out.println("We are in: ItemAtction markA1: doAction()");
				System.out.println("fileItem : "+fileItem.getAbsolutePath());
				if(fileItem.isDirectory()){
					String filename = markingSlipName;
					MarkingProcess pm = new MarkingProcess(fileItem,filename,"A2");
					
					String name = parseUWIFormat(fileItem.getName());
					System.out.println(name);
					pm.addMarker(new InsertHeader(name,"COMP 2603","Assignment #2"));
					
					//reflective checks for methods
					pm.addMarker(new MarkA2TestCases(testCasesDir));
					//pm.addMarker(new ManualMarker("Additional Comments", "C:\\Users\\krism\\Projects\\Java\\COMP2603-A2\\src\\"+"ac.txt"));
					System.out.println(System.getProperty("user.dir")); // this prints  C:\Users\jlm91\Documents\GitHub\TA_Tools\COMP2603-A2
					pm.addMarker(new ManualMarker("Additional Comments", "src\\"+"ac.txt"));
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
						String name = item.getName();
						name = name.split("_")[0];
						//TO DO Look up ID from DB later
						MarkingProcess.getMasterSheet(outputDir, masterSheetName).writeRowln(name,markingSlip.getTextFromColInLastRow(2));
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
					markingSlip.loadOrCreateSheet("A2");
					
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
        
        try{
        	//File file = new File(sourceDir);
        	//performActionInFile(file,validateZip);
        	//performActionInFile(file,extractArchive);
        	performActionInFile(new File(outputDir), markA1);
        	//performActionInFileFromStartToEnd(new File(outputDir), markA1, 13, -1);
        	//performActionInFileFromStartToEndAndCloseAction(new File(outputDir), buildMasterMarksheet,0,-1,saveMasterMarksheet)
        	//performActionInFileFromStartToEndAndCloseAction(new File(outputDir), buildMasterMarksheet,0,-1,saveMasterMarksheet);
        	//MarkingProcess.getMasterSheet(outputDir, masterSheetName).writeExcelFile();
        	//performActionInFile(new File(outputDir),gatherMarkingSlips);
        	
        }
        catch(Throwable t){
        	System.out.println("A2 Error");
        	//t.printStackTrace();
        }
        
        
    }
    
    private static String parseUWIFormat(String folderName){
		return folderName.split("_")[0];
    }
        
}
