package com.ta.core.extraction;

public class NoFileWithValidExtensionFoundException extends Exception{
	public NoFileWithValidExtensionFoundException(String message){
		super(message);
	}
}