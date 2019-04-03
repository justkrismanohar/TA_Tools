package com.ta.core.extraction;

import java.io.File;
import net.sf.sevenzipjbinding.SevenZipException;
import net.sf.sevenzipjbinding.simple.ISimpleInArchiveItem;

public interface MakeDir{
	public File createDirAndFile(ISimpleInArchiveItem item) throws SevenZipException;
}
