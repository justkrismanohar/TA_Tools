package com.ta.core.extraction;

import java.io.File;
import java.nio.file.Path;
import java.nio.file.Paths;

import net.sf.sevenzipjbinding.SevenZipException;
import net.sf.sevenzipjbinding.simple.ISimpleInArchiveItem;

public class MossOutput implements MakeDir{
		public String itemName;
		public String outputDir;
		
		public MossOutput(String outputDir,String itemName){
			this.itemName = itemName;
			this.outputDir = outputDir;
		}
		
		@Override
		public File createDirAndFile(ISimpleInArchiveItem item) throws SevenZipException {
        	Path p = Paths.get(item.getPath());
			String[] extParts = p.getFileName().toString().split("\\.");
			
			if(extParts !=null){
				itemName += "."+ extParts[extParts.length-1];
			}
			
        	File file = new File(outputDir + File.separator + itemName);
        	
        	return file;
		}

	}