package com.ta.core;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class MarkingProcess {
	
	private String dirPath;
	private Marksheet markingSlip;
	private List<Marker> markers;
	private File item;
	
	//TO DO: PULL FROM CONFIG FILE
	private static String finalTotalPrefix = "Final Total";
	private static String sheetWithMarksName = "A1";
	private static String sheetWithMasterMarksName = "Final Marks";
	
	private static Marksheet masterSheet = null;
	public static Marksheet getMasterSheet(String dirPath,String filename){
		if(masterSheet == null){
			masterSheet = new Marksheet(dirPath,filename);
			masterSheet.loadOrCreateSheet(sheetWithMasterMarksName);
		}
		return masterSheet;
	}
	
	
	public MarkingProcess(File item,String filename){
		initializeAttributes(item, filename);		
	}

	public MarkingProcess(File item, String filename, String sheetWithMarksName){
		initializeAttributes(item, filename);
		//TODO should we allow user to switch sheetWithMarksName???
		this.sheetWithMarksName = sheetWithMarksName;
		this.markingSlip.loadOrCreateSheet(sheetWithMarksName);
	}
	
	private void initializeAttributes(File item, String filename) {
		this.item = item;
		this.dirPath = item.getAbsolutePath();
		markers = new ArrayList<Marker>();
		markingSlip = new Marksheet(dirPath,filename);
	}
	
	public void addMarker(Marker m){
		if(markers!=null)
			markers.add(m);
	}
	
	public static String getSheetWithMarksName(){
		return sheetWithMarksName;
	}
	public static String getFinalTotalPrefix(){
		return finalTotalPrefix;
	}
	
	
	private String getAllFilesWithExtensionButNotIn(String extension, Set<String> haveFilenames) {
		ArrayList<String> out = new ArrayList<String>();
		
		File[] contents = item.listFiles();
		
		int endIndex = contents.length-1;
		
		File item;
		
		for(int k = 0; k < contents.length && k <= endIndex; k++){
			item = contents[k];
			if(!item.isDirectory()) {
				String itemName = item.getName();
				String[] parts = itemName.split("\\.");
				if(parts[parts.length-1].equals(extension) && !haveFilenames.contains(parts[0]))
					out.add(item.getName());
			}
		}
		
		String names = "";
		for(String n : out) {
			names += n+" ";
		}
		return names;
	}
	
	private String getAllFilesWithExtension(String extension) {
		return getAllFilesWithExtensionButNotIn(extension, new HashSet<String>());
	}
	
	public void markAll(){
		
		
		if(markers !=null && markingSlip !=null){
			
			//System call to open all .java files in notepad++
			//note real source but ok
			//https://stackoverflow.com/questions/5028209/notepad-always-in-multi-instance/10592300
			//System call to close all tabs in notepad++ and all .java files
			//https://notepad-plus-plus.org/community/topic/13482/closing-all-tabs-prior-to-starting-editor/2
			
			//openJavaFilesInNotepad();
			HashSet<String> haveFiles = new HashSet<String>();
			haveFiles.add(markingSlip.getFilename().split("\\.")[0]);
			
			String xlsxFiles = getAllFilesWithExtensionButNotIn("xlsx", haveFiles);
			String docxFiles = getAllFilesWithExtension("docx");
			
			runCommand("start winword "+docxFiles);
			runCommand("start excel "+ xlsxFiles);
			float totalMark = 0, totalOutOf = 0;
			for(Marker m : markers){
				m.setMarksheet(markingSlip);
				m.mark();
				totalMark += m.getTotal();
				totalOutOf += m.getTotalOutOf();
			}
			
			markingSlip.writeRowBoldln("",getFinalTotalPrefix(),Float.toString(totalMark),"/"+Float.toString(totalOutOf));
			
		}
	}
	
	private void runCommand(String cmdToExecute) {
	try {
		Runtime rt = Runtime.getRuntime();
		rt.exec("cmd.exe /c "+cmdToExecute, null, new File(item.getAbsolutePath()));
		
	} catch (IOException e) {
		e.printStackTrace();
	}
}
	

//	private void openJavaFilesInNotepad() {
//		try {
//			Runtime rt = Runtime.getRuntime();
//			rt.exec("cmd.exe /c "+openFilesCmd, null, new File(item.getAbsolutePath()));
//			
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
//	}
	
	public void saveMarkingSlip(){
		if(markingSlip!=null){
			markingSlip.writeExcelFile();
		}
	}

}
