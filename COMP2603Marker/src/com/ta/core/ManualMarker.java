package com.ta.core;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ManualMarker extends Marker{

	//protected abstract String[] getHeader();
	//protected abstract List<RowData> getRowData();
	protected List<RowData> testCases;
	protected String className;

	public ManualMarker(){
		totalOutOf =0;
	}
	
	public ManualMarker(String name, String filename){
		className = name;
		loadRowData(filename);
	}
	
	protected String[] getHeader() {
		String[] header = {className,"Criteria","Marks","Out of","Areas/Comments"};
		return header;
	}
	
	protected List<RowData> getRowData(){
		return this.testCases;
	}
	
	protected void loadRowData(String filename){
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			testCases = new ArrayList<RowData>();
			
			for(String line = br.readLine(); line!=null; line = br.readLine()){
				String[] parts = line.split(";");
				
				RowData row = new RowData();
				row.addDesc(parts[0]);
				row.addDesc(parts[1]);
				row.setMark(parts[2]);
				for(int k = 3; k < parts.length; k++)
					row.addComment(parts[k]);
				
				testCases.add(row);
			}
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	
	@Override
	public void mark() {
	//Handle marking in your own way...
		Marksheet markingSlip = getMarksheet();
		//markingSlip.writeHeaderln(getHeader());
		markingSlip.writeRowBoldln(getHeader());
		
		List<RowData> rowData = getRowData();
		
		float mark, outOf;
		totalOutOf = 0;
		
		for(RowData row : rowData){
			outOf = Float.parseFloat(row.getMark());
			totalOutOf+= outOf;
			markingSlip.displayAndWriteDescription(row.getDesc());	
			mark = markingSlip.getMarkAndPromptForComment(outOf,"/"+outOf,row.getComments());
			addToTotal(mark);
		}
		
		markingSlip.writeRowln("","TOTAL",Float.toString(getTotal()),"/"+totalOutOf);
	}

}
