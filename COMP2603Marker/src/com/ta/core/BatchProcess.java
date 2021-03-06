package com.ta.core;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import java.util.Arrays;

import net.sf.sevenzipjbinding.IInArchive;
import net.sf.sevenzipjbinding.SevenZip;
import net.sf.sevenzipjbinding.SevenZipException;
import net.sf.sevenzipjbinding.impl.RandomAccessFileInStream;
import net.sf.sevenzipjbinding.simple.ISimpleInArchiveItem;

public class BatchProcess {
	
	public interface ItemAction{
		public boolean doAction(File item);
	}
	
	public static boolean openArchive(String archiveFilename) {
        RandomAccessFile randomAccessFile = null;
        IInArchive inArchive = null;
        
        try {        
		    randomAccessFile = new RandomAccessFile(archiveFilename, "r");
		    
		    inArchive = SevenZip.openInArchive(null, // Choose format automatically
		            new RandomAccessFileInStream(randomAccessFile));
		    
		    System.out.println("Opened "+archiveFilename);
		    
		    return true;
        }
        catch (Exception e) {
        	System.err.println(archiveFilename);
            System.err.println("Error occurs: " + e);
            return false;
        } 
        finally {
            if (inArchive != null) {
                try {
                    inArchive.close();
                } catch (SevenZipException e) {
                    System.err.println("Error closing archive: " + e);
                }
            }
            if (randomAccessFile != null) {
                try {
                    randomAccessFile.close();
                } catch (IOException e) {
                    System.err.println("Error closing file: " + e);
                }
            }
        }
	}
	
	public static boolean isAnAllowedArchive(String filename,String[] archiveFormats){
		String[] parts = filename.split("\\.");//escape dot in regex. Otherwise . means any char
		
		int lenght = parts.length;
		if(lenght >0){
			String ext = parts[parts.length-1];	
			for(String allowedFormat : archiveFormats){
				if(ext.equals(allowedFormat))
					return true;
			}
		}
		
		return false;
	}
	
	protected static boolean performActionInFileFromStartToEnd(File file, ItemAction action,int startIndex, int endIndex ){
		return performActionInFileFromStartToEndAndCloseAction(file, action, startIndex, endIndex, new ItemAction() {
			@Override
			public boolean doAction(File item) {	
				return true;
			}
		});//Null close action
	}
	
	protected static boolean performActionInFileFromStartToEndAndCloseAction(File file, ItemAction action,int startIndex, int endIndex, ItemAction close){
		
		try {
			if(file.isDirectory()){
				int count = startIndex;
				File[] contents = file.listFiles();
				
				if (endIndex == -1){
					//bit messy...but is an internal signal to process all items
					endIndex = contents.length-1;
				}
				
				File item;
				for(int k = startIndex; k < contents.length && k <= endIndex; k++){
					item = contents[k];
					System.out.println("Start folder "+count +" "+item.getName());
					if(!action.doAction(item))
						return false;
					System.out.println("Completed folder "+count+ " ");
					count++;
				}
				
				close.doAction(file);
				
			}
        }catch(Throwable t) {
            System.err.println("Error!");
            t.printStackTrace();
            return false;
        }	
		
		return true;
	}
	
	public static boolean performActionInFile(File file, ItemAction action){
		return performActionInFileFromStartToEnd(file, action, 0, -1);//internal signal to do all
	}

	protected static void copyFileIfDoesNotExistTo(String source, String destination){
		try {
			File src = new File(source);
			File des = new File(destination);
			
			if(!des.exists())
				Files.copy( (src.toPath()),
							des.toPath(), 
							StandardCopyOption.REPLACE_EXISTING);
		
		} catch (IOException e) {
			e.printStackTrace();
		}	
	}
	
	protected static void copyAndReplaceFileTo(String source, String destination){
		try {
			Path target  = new File(destination).toPath();
			
			Files.createDirectories(target.getParent());//does not throw error if parent directory already exists
			
			Files.copy( (new File(source).toPath()),
						target, 
						StandardCopyOption.REPLACE_EXISTING);
			
			
		} catch (IOException e) {
			e.printStackTrace();
		}	
	}
	
	protected static void copyAndReplaceMultipleFiles(String[] files, String srcDir, String desDir){
		for(String filename : files){
			copyAndReplaceFileTo(srcDir + File.separator + filename, desDir + File.separator + filename);
		}
	}
	
	protected static void writeStudentNameToMarkSlip(String markingSlipName, String sheetName, File dir) {
		Marksheet markingSlip = new Marksheet(dir.getAbsolutePath(), markingSlipName, true);
		markingSlip.loadOrCreateSheet(sheetName);
		
		String name = dir.getName();
		name = name.split("_")[0];
		System.err.println(name);
		
		markingSlip.setCurrentRow(0);
		markingSlip.writeRowln(name);
		markingSlip.writeRowln("");				
		markingSlip.writeExcelFile();
		markingSlip.close();
	
	}


}
