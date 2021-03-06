
import java.io.File;

import com.ta.core.MarkingProcess;
import com.ta.core.BatchProcess;
import com.ta.core.ManualMarker;
import com.ta.core.Marksheet;
import com.ta.core.BatchProcess.ItemAction;
import com.ta.core.extraction.Extract;
import com.ta.sample.InsertHeader;
import com.ta.sample.TestCaseMaker;

public class COMP0200 extends BatchProcess{
	
	public static void main(String[] args) {
		
		//TO DO: pull from a config file 
		String[] archiveFormats = {"zip","rar",".7z"};
		String[] format = {"docx","xlsx"};
		
		//Folders that were unzipped from the zip file in my elearning
		String sourceDir = "C:\\Users\\krism\\Downloads\\COMP0200\\source";
		
		String outputDir = "C:\\Users\\krism\\Downloads\\COMP0200\\output";
		
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
			public boolean doAction(File item) {
				if(item.isDirectory()){
					String filename = markingSlipName;
					MarkingProcess pm = new MarkingProcess(item,filename);
					pm.addMarker(new InsertHeader(item.getName(),"COMP 0200","Lab Exam"));
					pm.addMarker(new ManualMarker("MicrosoftWord", "MicrosoftWord.txt"));
					pm.addMarker(new ManualMarker("MicrosoftExcel", "MicrosoftExcel.txt"));
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
					markingSlip.loadOrCreateSheet("LabExam");
					
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
			
			//Step 1 validate zips
			File file = step1(sourceDir, validateZip);
            
            //Step 2 extract archives
            step2(extractArchive, file);

         	//Step 3 mark files 
            //UPDATE WITH FILES FROM EMAIL
            int startingFolder = 0, endingFolder = -1;
         	//step3(outputDir, markA1,startingFolder,endingFolder);

         	//Step 4
         	//step4(outputDir, buildMasterMarksheet, saveMasterMarksheet);
     
        }catch(Exception e) {
            System.err.println("Error!");
        }

	}

	private static void step4(String outputDir, ItemAction buildMasterMarksheet, ItemAction saveMasterMarksheet) {
		printSection("START BUILDING MARKSHEET");
		performActionInFileFromStartToEndAndCloseAction(new File(outputDir), buildMasterMarksheet,0,-1,saveMasterMarksheet);
		printSection("END BUILDING MARKSHEET");
	}

	private static void step3(String outputDir, ItemAction markA1,int startingFolder, int endingFolder) {
		printSection("START MARKING");
		performActionInFileFromStartToEnd(new File(outputDir), markA1,startingFolder,endingFolder);
		printSection("END MARKING");
	}

	private static void step2(ItemAction extractArchive, File file) {
		printSection("START EXTRACT ARCHIEVES");
		if(performActionInFile(file, extractArchive)){
			System.out.println("All archives extracted OK");
		}
		else {
			System.out.println("Error extracting archive...weird");
		}
		printSection("END VALIDATE ARCHIEVES");
	}

	private static File step1(String sourceDir, ItemAction validateZip) {
		printSection("START VALIDATE ARCHIEVES");
		File file = new File(sourceDir);
		if(performActionInFile(file,validateZip)){
			System.out.println("All archives OK");            
		}
		else{
			System.out.println(
					  "Can't unzip archive.\n"
					+ "1. Try to unzip manually."
					+ "2. Delete the first zip file."
					+ "3. Re-zip the unzipped folder as a standard zip archive."
					);
		
			System.exit(1);
		}
		printSection("END VALIDATE ARCHIEVES");
		return file;
	}

	public static void printSection(String sectionName) {
		System.out.println();
		printRepeats("=",5); printRepeats(sectionName,1); printRepeats("=",5);
		System.out.println();
	}
	
	public static void printRepeats(String s, int n) {
		for(int i =0; i <n; i++)
			System.out.print(s);
	}

}