package com.ta.core;

import java.util.Map;

public class CompilationMarker extends Marker {

	private CompilationResults cr;
	private float[][] scheme;
	
	public CompilationMarker(){}
	
	public CompilationMarker(MarkingProcess m){
		super(m);
	}
	
	public void setCompilationResults(CompilationResults cr){
		this.cr = cr;
	}
	
	public void setTotalOutOf(float amt){
		this.totalOutOf = amt;
	}
	
	public void setScheme(float[][] s){
		this.scheme = s;
	}
	
	@Override
	public void mark() {
		
		Marksheet m = getMarksheet();
		m.writeRowBoldln("Compilation","Comment");
		
		for(String className : cr.getFailureCompilationArray()){
			System.out.println(className + " does not compile");
			m.writeRowln(className+".java","Does not compile");
		}

		for(String className : cr.getSuccessCompilationArray()){
			System.out.println(className + " compiles");
			m.writeRowln(className+".java","Compiles");
		}
		
		if(scheme!=null){
			int numCompiled = cr.numSuccess();
			for(int i = scheme.length-1; i >=0; i--){
				float[] rule = scheme[i];
				if(numCompiled >= rule[0]){
					m.writeRowln("","TOTAL",Float.toString(rule[1]),"/"+Float.toString(totalOutOf));
					total = rule[1];
					break;
				}
			}
		}
	}
	
	
	

}
