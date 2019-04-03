package com.ta.sample;

import java.lang.reflect.Constructor;
import java.lang.reflect.Method;

import com.ta.core.AutoMarker;
import com.ta.core.Marker;

public class HelloWorldMarker extends Marker {

	private String dirPath;
	
	@Override
	public void mark() {
		dirPath = getMarksheet().getDirPath();
		String filename = "HelloWorld.java";
		if (AutoMarker.checkIfFileExists(dirPath,filename)){
			if(AutoMarker.canComplie(dirPath,filename)){
				testHelloWorld();
			}
		}		
	}

	private void testHelloWorld() {
		
		Class c = AutoMarker.getClass("HelloWorld");
		System.out.println(c);
				
		Constructor construct = AutoMarker.getConstructor(c);
		System.out.println(construct);
		
		Object instance = AutoMarker.callConstructor(construct);
		System.out.println(instance);
		
		Method m = AutoMarker.getMethod(c, "testInt", String.class,int.class);
		if(m==null){
			System.out.println("0 marks, comment: missing");
		}
		else{
			System.out.println(m);
			AutoMarker.callMethodOnInstnace(instance, m, "Hi Args! Cool!",1);	
		}
		
	}
}
