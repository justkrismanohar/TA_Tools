package com.ta.core.extraction;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.zip.ZipInputStream;

import net.sf.sevenzipjbinding.ExtractOperationResult;
import net.sf.sevenzipjbinding.IInArchive;
import net.sf.sevenzipjbinding.ISequentialOutStream;
import net.sf.sevenzipjbinding.SevenZip;
import net.sf.sevenzipjbinding.SevenZipException;
import net.sf.sevenzipjbinding.SevenZipNativeInitializationException;
import net.sf.sevenzipjbinding.impl.RandomAccessFileInStream;
import net.sf.sevenzipjbinding.simple.ISimpleInArchive;
import net.sf.sevenzipjbinding.simple.ISimpleInArchiveItem;


public class Extract {
	
//	public static void main(String[] args){
//		String[] format = {"java"};
//		try {
//			extract("C:\\Users\\krism\\Projects\\Java\\COMP2603Marker\\src\\output","C:\\Users\\krism\\Projects\\Java\\COMP2603Marker\\src\\test.zip",format);
//		} catch (SevenZipException | FileNotFoundException | NoFileWithValidExtensionFoundException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//	}
//	
	private static String extractFilename(String path){
		Path p = Paths.get(path);
		return p.getFileName().toString();
	}

    public static void extractForMoss(String outputDir, String itemName, String fileToUnzip,String[] format) throws SevenZipException, FileNotFoundException, NoFileWithValidExtensionFoundException{
    	extractFiles(new MossOutput(outputDir, itemName), fileToUnzip, format);
    }

    public static void extract(String outputDir, String fileToUnzip,String[] format) throws SevenZipException, FileNotFoundException, NoFileWithValidExtensionFoundException{
    	//TODO Replace with a Factory later, to reduce memory 
    	extractFiles(
    		new MakeDir() {
				@Override
				public File createDirAndFile(ISimpleInArchiveItem item) throws SevenZipException {
	            	String itemName = extractFilename(item.getPath());
	            	File file = new File(outputDir + File.separator + itemName);
	            	file.getParentFile().mkdirs();
	            	return file;
				}
    		}, 
    		fileToUnzip, 
    		format);
    }
    
    private static void extractFiles(MakeDir outputDir, String fileToUnzip,String[] format) throws SevenZipException, FileNotFoundException, NoFileWithValidExtensionFoundException{
        try {
        	
            SevenZip.initSevenZipFromPlatformJAR();
            System.out.println("7-Zip-JBinding library was initialized");
            RandomAccessFile randomAccessFile = new RandomAccessFile(fileToUnzip, "r");

            IInArchive inArchive = SevenZip.openInArchive(null, // Choose format
                                                                // automatically
                    new RandomAccessFileInStream(randomAccessFile));
            System.out.println(inArchive.getNumberOfItems());

            // Getting simple interface of the archive inArchive
            ISimpleInArchive simpleInArchive = inArchive.getSimpleInterface();

            System.out.println("   Hash   |    Size    | Filename");
            System.out.println("----------+------------+---------");
            int filesExtracted =0;
            
            for (ISimpleInArchiveItem item : simpleInArchive.getArchiveItems()) {
                final int[] hash = new int[] { 0 };
                if (!item.isFolder() && isAnAllowedItem(fileToUnzip + File.separator+ item.getPath(), format)) {
                	
                   // String filename = item.getPath();
                    
                	ExtractOperationResult result;
                	//Create the output file
                    
                    FileOutputStream fos;
                	File file = outputDir.createDirAndFile(item);
                	fos = new FileOutputStream(file);
                  
                    final long[] sizeArray = new long[1];
                    result = item.extractSlow(new ISequentialOutStream() {
                        public int write(byte[] data) throws SevenZipException {
                            //#Blog
                            //https://stackoverflow.com/questions/19403829/decompress-files-with-7z-extension-in-java/19403933#19403933
                            //https://www.javaworld.com/article/2074973/uncompressing-7-zip-files-with-groovy-and-7-zip-jbinding.html
                            
                            try {
                            	//Write to file
                            	fos.write(data);
                              
                            } catch (Throwable e) {
                                // TODO Auto-generated catch block
                                e.printStackTrace();
                            }
                        	
                        	hash[0] ^= Arrays.hashCode(data); // Consume data
//                            for (byte b : data) {
//                                System.out.println((char) b);
//                            }
                            sizeArray[0] += data.length;
                            return data.length; // Return amount of consumed                                                // data
                        }
                    });
                    
                    try {
						fos.close();
					} catch (IOException e) {
						e.printStackTrace();
					}

                    if (result == ExtractOperationResult.OK) {
                        System.out.println(String.format("%9X | %10s | %s", hash[0], sizeArray[0], item.getPath()));
                        filesExtracted++;
                    } else {
                        System.err.println("Error extracting item: " + result);
                    }
                }
            }
            
            if(filesExtracted == 0){
            	String s = "";
            	for(String f : format)
            		s+=f;
            	throw new NoFileWithValidExtensionFoundException("Archive did not contain any "+ s + " files.");
            }

        } catch (SevenZipNativeInitializationException e) {
            e.printStackTrace();
        } 
    	
    }

	public static String cleanFileName(String cleanItemName) {
		cleanItemName = cleanItemName.replaceAll("[^a-zA-Z0-9\\.\\-]", "_");
		cleanItemName = cleanItemName.replaceAll(" ", "");
		return cleanItemName;
	}
	
	private static boolean isBinaryFile(String filename){
	    FileInputStream fin =null;
	    ZipInputStream in =null;
	    File f;
		try {
			//f = new File(filename);
			fin = new FileInputStream(filename);
			in = new ZipInputStream(fin);
		    int size = in.available();
		    if(size > 1024) size = 1024;
		    byte[] data = new byte[size];
		    in.read(data);
		    in.close();

		    int ascii = 0;
		    int other = 0;

		    for(int i = 0; i < data.length; i++) {
		        byte b = data[i];
		        if( b < 0x09 ) return true;

		        if( b == 0x09 || b == 0x0A || b == 0x0C || b == 0x0D ) ascii++;
		        else if( b >= 0x20  &&  b <= 0x7E ) ascii++;
		        //else other++;
		        else return true;
		    }

		    return false;
			
		} catch (Throwable e) {
			e.printStackTrace();
			//some erorr, assume to be binary
			return true;
		} 
		finally{
			if(in!=null)
				try {
					in.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
		}
		
	}
	
	public static boolean isAnAllowedItem(String filename,String[] archiveFormats){
		//There does not seem to be a guaranteed way to determine if a file is textfile or binary.
		//There are some interesting suggestions
		//https://stackoverflow.com/questions/620993/determining-binary-text-file-type-in-java
		//TODO replace with a more robust check
		//For now just ignore the folder generated by MAC OS folder
		Path p = Paths.get(filename);
		for(int i=0; i < p.getNameCount(); i++)
			if(p.getName(i).toString().equals("__MACOSX"))
			//NOTE Might be forced to extract and then check is a binary, if it is delete it.
			//Can't seem to open "file" within the zip folder
			//if (isBinaryFile(filename))
				return false;
	
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

}