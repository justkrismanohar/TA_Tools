

import static org.junit.Assert.*;

import java.lang.reflect.Constructor;

import org.junit.After;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

import static org.hamcrest.CoreMatchers.*;

/**
 * The test class ACTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class ACTest
{
    
     private static Device ac1,acN,acM;
     private static int idNumberPart1, idNumberPart2;
     private static String idPrefix;     

     /**
     * Default constructor for test class ACTest
     */
    
    @BeforeClass
    //https://garygregory.wordpress.com/2011/09/25/understaning-junit-method-order-execution/
    public static void setUpClass(){
    	ac1 = new AC();
    	System.out.println(ac1.getID());
    	acN = new AC();
    	acM = new AC();
    }

    @Test
    public void testACCreationID(){
    	
    	try{
        	String acID1 = acN.getID();
        	idPrefix = acN.getID().substring(0,2);
        	
        	Integer.parseInt(acID1.substring(2,acID1.length()));
        	assertThat("ID prefix should be AC not "+idPrefix, idPrefix,is("AC") );	
    	}
    	catch(Throwable t){
    		assertThat("ID prefix should be AC not "+idPrefix, true,is(false) );
    	}
    }
    
    @Test
    public void testACCreateIDIncrement(){

        try{
        	String acID1 = acN.getID();
            String acID2 = acM.getID();
        	idNumberPart1 = Integer.parseInt(acID1.substring(2,acID1.length()));
	        idNumberPart2 = Integer.parseInt(acID2.substring(2,acID2.length()));
        }
        catch(Throwable t){
        	assertThat("Incorrect AC ID format",false, is(true));
        	return;
        }
        
        assertThat("ID should increment by 1", idNumberPart2, is(idNumberPart1+1));
       
    }
    
    @Test
    public void testACisBreezy(){
        assertThat("isBreezy should be false",ac1.isBreezy(),is(false));
    	//assertFalse(ac1.isBreezy());   
    }
    
    @Test
    public void testACBreeziness(){ 
        assertThat("getBreeziness() should return 0",ac1.getBreeziness(),is(0));
    	//assertEquals(0,ac1.getBreeziness());
    }
    
    @Test
    public void testAC_isNoisy(){
        assertThat("isNoisy() should return false",ac1.isNoisy(),is(false));
    	//assertFalse(ac1.isNoisy());      
    }
    
    @Test
    public void testACNoisiness(){     
        assertThat("getNoisiness() should return 0",ac1.getNoisiness(),is(0));
    	//assertEquals(0,ac1.getNoisiness());
    }
    
    @Test
    public void testTurnOn(){
        //assertFalse(ac1.isOn()); 
        ac1.turnOn();
        assertThat("Called turnOn() so isOn() should return true",ac1.isOn(),is(true));
        //assertTrue(ac1.isOn()); 
    }
    
    @Test
    public void testTurnOff(){
        ac1.turnOff();
        assertThat("Called turnOff() so isOn() should return false",ac1.isOn(),is(false));
        //assertFalse(ac1.isOn()); 
    }
    
    @Test
    public void testCools(){
        assertThat("AC should cool by 5",ac1.coolsBy(),is(5));
    	//assertEquals(5,ac1.coolsBy()); 
    }
    
    @Test
    public void testIsDevice(){
        assertThat("AC should be an instance of Device", ac1 instanceof Device,is(true));
    	//assertTrue(ac1 instanceof Device);
    }
    
    @Test
    public void testIsPortableDevice(){
    	assertThat("AC should not be an instance of PortableDevice", ac1 instanceof PortableDevice,is(false));
        //assertFalse(ac1 instanceof PortableDevice);
    }
    
}

