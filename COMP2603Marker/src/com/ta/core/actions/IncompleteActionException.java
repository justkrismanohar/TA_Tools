package com.ta.core.actions;

public class IncompleteActionException extends Exception {

	public IncompleteActionException(String string) {
		super(string);
	}

	@Override
	public String getMessage() {
		return "Incomplete Action: "+ super.getMessage();
	}
}
