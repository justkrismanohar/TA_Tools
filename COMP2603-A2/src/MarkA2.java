

import java.io.File;

import com.ta.core.MarkingProcess;
import com.ta.core.BatchProcess;
import com.ta.core.BatchProcess.ItemAction;
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
    	String outputDir = "C:\\Users\\krism\\Projects\\Java\\COMP2603Marker\\output-test";
    	String markingSlipName = "Assignment_2_Makring_Slip.xlsx";
    	String testCasesDir = "C:\\Users\\krism\\Projects\\Java\\COMP2603-A2-Test-Student\\src";
    	
        ItemAction markA1 = new ItemAction(){

			@Override
			public boolean doAction(File fileItem) {
				if(fileItem.isDirectory()){
					String filename = markingSlipName;
					MarkingProcess pm = new MarkingProcess(fileItem,filename,"A2");
					pm.addMarker(new InsertHeader(fileItem.getName(),"COMP 2603","Assignment #2"));
					
//					pm.addMarker(new Marker(){
//						@Override
//						public void mark() {
//							getMarksheet().writeRowBoldln("Test Class","Test Method","Comment");
//							
//						}
//					});
					
					//reflective checks for methods
					pm.addMarker(new MarkA2TestCases(testCasesDir));
					pm.markAll();
					pm.saveMarkingSlip();
					//should move files to a marked folder so don't accidentally overwrite them
				}
				return true;
			}
        	
        };
        
        performActionInFile(new File(outputDir), markA1);
        
        
    }
        
}
