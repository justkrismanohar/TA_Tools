import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import com.ta.core.AutoMarker;
import com.ta.core.CompilationResults;
import com.ta.core.Marker;
import com.ta.core.Marksheet;

public class MarkA3 extends Marker{
	
	String packageName = "gradingapplication";
	
	String [] studentClassNames = new String[] {
			packageName+".GradeSlip"
			,packageName+".MasterMarkSheet"
			,packageName+".GradingGUI"
			,packageName+".GradingApplication"
	};
	
	
	private CompilationResults complieAndLoadStudentClasses(){
		String[] classes = studentClassNames;
		String dirPath = markingProcess.getPath();
		AutoMarker.clearExternallyLoadedClasses();
		return AutoMarker.loadAndComplieClassesFromDir(classes, dirPath);	
	}
	
	@Override
	public void mark() {
		//move java files to folder
		//markingProcess.runCommand("mkdir "+packageName);
		
		//Seems to be some lag between making the dir via cmd prompt and java getting the updates
		//this cause null list of files when there was acutally files
		//recommend using java apis for all file operations as much and possible, seems internally
		//this api tracks state....weird.....
		markingProcess.makeDir(markingProcess.getPath()+File.separator+packageName);
		
		markingProcess.runCommand("move *.java "+packageName);
			
		//compile files
		CompilationResults cr = complieAndLoadStudentClasses();
		for(String c : cr.getFailureCompilationArray())
			System.err.println(c);

        //run gui
		markingProcess.openJavaFilesInNotepadFrom(packageName);
		markingProcess.openMarkingSlip();
		markingProcess.runCommand("java "+packageName+".GradingApplication");
		markingProcess.runCommand("start echo \"java "+packageName+".GradingApplication\"");
		
		
		pauseWithMessage("Start Next Folder");
		

		
	}

	private void pauseWithMessage(String message) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print(message);
        try {
			String s = br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
