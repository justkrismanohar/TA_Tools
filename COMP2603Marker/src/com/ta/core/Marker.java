package com.ta.core;

import java.io.File;

public abstract class Marker {
	
	private Marksheet markingSlip;
	protected float total;
	protected float totalOutOf;
	
	public Marker(){
		total = 0;
	}
	
	public Marker(Marksheet m){
		markingSlip = m;
		total = 0;
	}
	public Marksheet getMarksheet(){
	
		return markingSlip;
	}
	
	public void setMarksheet(Marksheet m){
		markingSlip = m;
	}
	
	public float getTotal(){
		return total;
	}
	
	protected void addToTotal(float mark){
		total += mark;
	}
	
	public float getTotalOutOf(){
		return totalOutOf;
	}

	public abstract void mark();
	
	protected void printHeader(){
		getMarksheet().writeRowBoldln("Test Class","Test Method","Comment");
	}
}
