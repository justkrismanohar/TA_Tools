package com.ta.core;

import java.util.ArrayList;
import java.util.List;

public class RowData {


	private List<String> desc;
	private String mark;
	private List<String> comments;
	
	public RowData(){
		desc = new ArrayList<String>();
		mark ="";
		comments = new ArrayList<String>();
	}
	
	public void setMark(String s){
		mark = s;
	}
	
	public void addDesc(String s){
		desc.add(s);
	}
	
	public void addComment(String s){
		comments.add(s);
	}
	
	private String[] convertToArray(List<String> l){
		String[] out = new String[l.size()];
		
		for(int k = 0; k < l.size(); k++)
			out[k] = l.get(k);
		
		return out;
	}
	
	public String[] getDesc() {
		
		return convertToArray(desc);
	}

	public String getMark() {
		return mark;
	}

	public String[] getComments() {
		return convertToArray(comments);
	}
}
