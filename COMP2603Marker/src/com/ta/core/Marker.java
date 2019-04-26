package com.ta.core;

import java.io.File;
import java.io.IOException;

public abstract class Marker {
	
	protected final float defaultTotalOutOf = Float.MIN_VALUE;
	protected MarkingProcess markingProcess;
	protected float total;
	protected float totalOutOf;

		
	public Marker(){
		total = 0;
		totalOutOf = defaultTotalOutOf;
	}
	
	public Marker(MarkingProcess mp){
		setMarkingProcess(mp);
		total = 0;
	}
	
	public Marksheet getMarksheet(){
		return markingProcess.getMarkingSlip();
	}
	
	public void setMarkingProcess(MarkingProcess mp){
		this.markingProcess = mp;
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
	

}
