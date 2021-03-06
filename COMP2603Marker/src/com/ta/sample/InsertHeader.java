package com.ta.sample;

import com.ta.core.MarkingProcess;
import com.ta.core.Marker;
import com.ta.core.Marksheet;

public class InsertHeader extends Marker {
	
	private String studentFolder;
	private String courseName, assignmentName;
	
	public InsertHeader(String studentFolder){
		this.studentFolder = studentFolder;
	}
	
	public InsertHeader(String studentFolder,String courseName, String assignmentName){
		this.studentFolder = studentFolder;
		this.courseName = courseName;
		this.assignmentName = assignmentName;
	}
	
	@Override
	public void mark() {
		Marksheet markingSlip = getMarksheet();
		markingSlip.loadOrCreateSheet(MarkingProcess.getSheetWithMarksName());
		//markingSlip.createSheet(A1Marker.getSheetWithMarksName());
		if(this.courseName != null && this.assignmentName!=null)
			markingSlip.writeHeaderln("STUDENT ID",this.assignmentName, this.courseName);
		else
			markingSlip.writeHeaderln("STUDENT ID","Assignment 1", "COMP 2603");//TODO legacy support for A1 code, update this later
		
		markingSlip.writeRowln(studentFolder);
		markingSlip.writeRowln("");
	}

}
