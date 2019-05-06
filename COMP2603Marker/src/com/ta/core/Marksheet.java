package com.ta.core;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFPrintSetup;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.CellStyle;
import org.apache.poi.ss.usermodel.CellValue;
import org.apache.poi.ss.usermodel.Font;
import org.apache.poi.ss.usermodel.FormulaEvaluator;
import org.apache.poi.ss.usermodel.IndexedColors;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.VerticalAlignment;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.xssf.usermodel.XSSFCellStyle;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

public class Marksheet {

//	public static void main(String[] args){
//		
//		Marksheet m = new Marksheet(".\\","Assignment 1 Makring Slip.xlsx");		
//		m.createSheet("A1");
//		m.writeHeaderln("STUDENT ID","Assignment 1", "COMP 2603");
//		m.writeRowln("");
//		
//		m.writeHeaderln("Booking Class","CRITERIA","Marks","Out of","Areas/Comments");
//		m.displayAndWriteDescription("Class Declaration","public class Booking");
//		m.promptForMarkAndComment("/1","Missing","Incorrect","Incomplete");
//		m.writeExcelFile();
//	}
	
	public static void main(String[] args){
		Marksheet m = new Marksheet(".","Master.xlsx",true);
		m.loadOrCreateSheet("A1 Marks");
		m.writeHeaderln("STUDENT ID","Assignment 1", "COMP 2603");
		m.writeRowln("ooooo");
		m.writeExcelFile();
	}

	
	private Workbook workbook;
	private String filename;
	private CellStyle headerStyle;
	private CellStyle rowStyle;
	private CellStyle rowBoldSyle;
	
	private Sheet sheet;
	private int currentRow; 
	private int currentColumn;
	private Scanner keyboard;
	private String dir_path;
	
	public Marksheet(String dir_path, String filename, boolean append){
		if(append){
			try {
				//System.err.println(dir_path+File.separator+filename);
				this.workbook = new XSSFWorkbook(new FileInputStream(dir_path+File.separator+filename));				
			} catch (Throwable e) {
				//maybe file was not created yet
				e.printStackTrace();
				System.err.println(e.getCause());
				this.workbook = new XSSFWorkbook();
			
			}
		}
		else{
			this.workbook = new XSSFWorkbook();
		}
		
		initMarksheet(dir_path, filename);
		//System.err.println("CurrentRow "+currentRow);
	}
	
	public Marksheet(String dir_path, String filename){
		this.workbook = new XSSFWorkbook();
		initMarksheet(dir_path, filename);
	}
	
	public void copyColumnFromThatMarksheetCurrentSheetIntoThisMarksheetCurrentSheet(int col,Marksheet otherSheet) {
		int lastRow = sheet.getLastRowNum();
		for(int i=0; i < lastRow; i++) {
			
			try {
				Cell myCell = getCell(i,col);
				String text = otherSheet.getTextFromCell(i, col);
				//System.out.println(text);
				myCell.setCellValue(text);
			}
			catch(Throwable t) {
				//System.out.println("Cell "+i+" "+col+" probably blank");
				//System.exit(1);
			}
		}
	}
	
	
	private Cell getCell(int row, int col) throws Exception {
		try {
			return sheet.getRow(row).getCell(col);
		}
		catch(Throwable t){
			throw new Exception("Cannot get cell "+row +" "+ col);
			
		}
	}
	
	public boolean hasText(String finalMarkPrefix, int col){
		//checks to see if last row, has final mark in it
		int lastRow = sheet.getLastRowNum();
		System.err.println("Last row "+lastRow);
		String val = this.sheet.getRow(lastRow).getCell(col).getStringCellValue().trim();
		return val.equals(finalMarkPrefix);
	}
	
	public String getTextFromColInLastRow(int col){
		//return this.sheet.getRow(sheet.getLastRowNum()).getCell(col).toString();
		return getTextFromCell(sheet.getLastRowNum(), col);
	}
	
	public String getTextFromCell(int row, int col){
		if(this.sheet.getRow(row) == null ) return "";
		try {
			FormulaEvaluator evaluator = this.workbook.getCreationHelper().createFormulaEvaluator();
		
			Cell cell = this.sheet.getRow(row).getCell(col);			
			String val = evaluator.evaluate(cell).getStringValue();
			if(val == null) return "";
			return val;
		}
		catch(Throwable t) {
			return "";
		}
	}
	
	public void close(){
		try {
			this.workbook.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	private void initMarksheet(String dir_path, String filename) {
		this.dir_path = dir_path;
		this.filename = filename;
		this.sheet = null;
		this.currentRow = -1;
		this.currentColumn = -1;
		//Default styles 
		setHeaderStyle(true, (short) 14, IndexedColors.BLACK);
		setRowStyle(false, (short) 12, IndexedColors.BLACK);
		setRowBoldStyle(true, (short) 12, IndexedColors.BLACK);
		keyboard = new Scanner(System.in);
	}
	
	public String getDirPath(){
		return this.dir_path;
	}
	
	public void displayAndWriteDescription(String... description){
		writeRowln(description);
		printDescription(description);
	}
	
	private void printBlankRow(){
		System.out.println();
		System.out.println();
	}
	
	private void printDescription(String... description){
		for(int k =0; k<description.length;k++){
			System.out.print(description[k]+ " ");
		}
		
		printBlankRow();
	}
	
	public float getMarkAndPromptForComment(float outOf, String outOfStr,String... comments){
		Row row = sheet.getRow(getCurrentRow());
		//prompt for mark
		float mark = promptForMark(outOf, outOfStr);
		//write mark
		writeColumn(rowStyle, row, ""+mark);
		writeColumn(rowStyle, row, outOfStr);
		//prompt  for comment from list for comments
		if(comments.length > 0 ) writeColumns(rowStyle, row, promptForComments(comments));
		//writeColumn(rowStyle, row,);
		return mark;
	}
	
	private float promptForMark(float outOf, String outOfStr) {
		
		float mark = 0;
		do {
			System.out.print("Please enter Mark "+outOfStr+ ": ");
			mark = readMark();
		}
		while(!(0<= mark && mark <= outOf));
		
		System.out.println();
		
		return mark;
	}
	
	private float readMark(){
		float mark;
		try {
			mark = Float.parseFloat(keyboard.nextLine());
			//mark = keyboard.nextInt();
			//keyboard.nextLine();
			//https://stackoverflow.com/questions/14452613/issues-with-nextline
		}
		catch(Exception e){
			//Some not integer value was read in
			mark =-1;
		}
		return mark;
	}
	
	
	private int[] extractSelectionIds(String s) throws Exception{
		String[] parts = s.split(" ");
		int [] selections = new int[parts.length];
		for(int k =0; k < parts.length; k++){
			try{
				selections[k] = Integer.parseInt(parts[k]);
			}
			catch(Exception e){
				//maybe this should be a custom exception...s
				throw e;
			}
		}
		return selections;
	}
	
	private int validateSelections(int startRange, int endRange, int... selections){
		int numVaildSelctions = 0;
		for(int x : selections){
			if(startRange<= x && x <= endRange)
				numVaildSelctions++;
			else
				return 0;
		}
		return numVaildSelctions;
	}
	
	private String[] promptForComments(String... comments){
		int[] selections = promptForSelectedCommentIds(comments);
		String[] validSelections = new String[selections.length];
		
		for(int k =0; k < selections.length; k++){
			validSelections[k] = comments[selections[k]];
		}
		
		return validSelections;
	}

	private int[] promptForSelectedCommentIds(String... comments) {
		int numValidSelections;
		int[] selections = {};
		
		do {
			
			for(int k =0; k <comments.length; k++){
				System.out.print(k+ ") "+ comments[k]+ " ");
			}
			System.out.print("\nEnter selection(s) separated by a SINGLE space : ");
			String input = keyboard.nextLine();
			
			try{
				selections = extractSelectionIds(input);
				numValidSelections = validateSelections(0, comments.length-1, selections);	
			}
			catch(Exception e){
				numValidSelections = 0;
			}
			
			if(numValidSelections == 0){
				System.out.print("Please enter a valid selection\n");
			}
			
			printBlankRow();
		}
		while(numValidSelections == 0);
		return selections;
	}
	
	private void incrementCurrentColumn(){
		currentColumn++;
	}
	
	
	public void setCurrentRow(int i){
		this.currentRow = i;
	}
	
	public int getCurrentColumn(){
		return this.currentColumn;
	}
	
	public int getCurrentRow(){
		return this.currentRow;
	}
	
	private int incrementAndGetCurrentRow(){
		currentRow++;
		return currentRow;
	}
	
	public void setHeaderStyle(boolean bold, short height, IndexedColors color) {
		Font headerFont = makeFont(bold,height,color);
		headerStyle = makeCellStyle(headerFont);
	}

	public void setRowStyle(boolean bold, short height, IndexedColors color) {
		Font rowFont = makeFont(bold,height,color);
		rowStyle = makeCellStyle(rowFont);
	}

	public void setRowBoldStyle(boolean bold, short height, IndexedColors color) {
		Font rowFont = makeFont(bold,height,color);
		rowBoldSyle = makeCellStyle(rowFont);
	}
	
	public boolean createSheet(String sheetName){
		this.sheet = workbook.createSheet(sheetName);
		return this.sheet == null;
	}
	
	public boolean loadOrCreateSheet(String sheetName){
		try{
			
			
			this.sheet = workbook.getSheet(sheetName);
			
			//https://stackoverflow.com/questions/6743615/apache-poi-change-page-format-for-excel-worksheet
			this.sheet.getPrintSetup().setLandscape(true);
			this.sheet.getPrintSetup().setPaperSize(HSSFPrintSetup.A4_PAPERSIZE);
			
			this.sheet.autoSizeColumn(0);
			this.sheet.autoSizeColumn(1);
			
			//https://stackoverflow.com/questions/41847210/set-default-print-scalling-for-the-generated-excel-file-in-apache-poi
			//set page setup to fit to one page width but multiple pages height
			this.sheet.setFitToPage(true);
			this.sheet.getPrintSetup().setFitWidth((short)1);
			this.sheet.getPrintSetup().setFitHeight((short)0);
			  
			this.currentRow = this.sheet.getLastRowNum();
			this.currentRow = this.currentRow == 0 ? -1 : this.currentRow + 1;//code base increments currentRow before using it.
			//set to -1 if sheet has no rows
		}
		catch(Throwable e){ }
		finally{
			if (this.sheet == null){
				System.err.println("Cannot find sheet "+ sheetName+ " in "+ this.filename+" creating it");
				this.sheet = workbook.createSheet(sheetName);
			}
			//System.out.println(currentRow);
		}
		
		return this.sheet != null;
	}
	
	private void printErrln(Object s){
		println(true, s);
	}
	
	private void println(boolean error, Object s){
		if(error){
			System.out.println("Error: " + s);
		}
		else {
			System.out.println(s);
		}
	}
	
	public void writeExcelFile() {
		try {
			FileOutputStream fileOut;
			String fileLocation = dir_path+"\\"+filename;
			fileOut = new FileOutputStream(fileLocation);
			workbook.write(fileOut);
			fileOut.close();
			System.out.println("Saved "+fileLocation);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			printErrln(e.getMessage());
			e.printStackTrace();
		}
	}


	public void writeHeaderln(String... values){
		writeIthRow(incrementAndGetCurrentRow(), headerStyle, values);
	}

	public void writeRowBoldln(String... values){
		writeIthRow(incrementAndGetCurrentRow(), rowBoldSyle, values);
	}
	
	public void writeRowln(String... values){
		writeIthRow(incrementAndGetCurrentRow(), rowStyle, values);
	}

	private void writeIthRow(int i, CellStyle style, String... values){
		Row row = sheet.createRow(i);
		setCurrentColumn(0);
		writeColumns(style, row, values);
	}

	private void writeColumns(CellStyle style, Row row, String... values) {
		for (int k = 0; k < values.length; k++) {
	        writeColumn(style, row, values[k]);
	    }
	}

	private void setCurrentColumn(int start) {
		this.currentColumn = start;
	}

	private void writeColumn(CellStyle style, Row row, String val) {
		int col = getCurrentColumn();
		Cell cell = row.createCell(col);
		cell.setCellValue(val);
		cell.setCellStyle(style);
		sheet.autoSizeColumn(col);
		if(sheet.getColumnWidth(col) > 65*256){
			sheet.setColumnWidth(col, 65*256);
		}
		
		
		incrementCurrentColumn();
	}
	
	private Font makeFont(boolean bold,short height, IndexedColors color){
	    Font aFont = workbook.createFont();
	    aFont.setBold(bold);
	    aFont.setFontHeightInPoints(height);
	    aFont.setColor(color.getIndex());
	    return aFont;
	}
	
	private CellStyle makeCellStyle(Font font){
		CellStyle aCellStyle = workbook.createCellStyle();
		aCellStyle.setFont(font);
		aCellStyle.setWrapText(true);
		aCellStyle.setVerticalAlignment(VerticalAlignment.CENTER);
		return aCellStyle;
	}
	
	public String getFilename(){
		return filename;
	}
}
