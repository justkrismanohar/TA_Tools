

import static org.hamcrest.CoreMatchers.is;
import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class CeilingFanTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class CeilingFanTest
{
    private Device ceilingFan;
    private static Device sfN,sfM;
    private static int idNumberPart1, idNumberPart2;
    private static String idPrefix; 
    
    /**
     * Default constructor for test class CeilingFanTest
     */
    public CeilingFanTest()
    {
        ceilingFan = new CeilingFan();
    }


    @Test
    public void setUpClass(){
        sfN = new CeilingFan();
        sfM = new CeilingFan(); 
    }
    
    
    @Test
    public void testCFCreationID(){
    	idPrefix = sfN.getID().substring(0,4);
        try{
        	String sfID1 = sfN.getID();
        	Integer.parseInt(sfID1.substring(4,sfID1.length()));
        	assertThat("ID prefix should be CFAN not "+idPrefix, idPrefix,is("CFAN") );
        }
        catch(Throwable t){
        	assertThat("ID prefix should be CFAN not "+idPrefix, true,is(false) );
        }
    	
    }
    
    @Test
    public void testSFCreateIDIncrement(){

        try{
        	String sfID1 = sfN.getID();
            String sfID2 = sfM.getID();
        	idNumberPart1 = Integer.parseInt(sfID1.substring(4,sfID1.length()));
	        idNumberPart2 = Integer.parseInt(sfID2.substring(4,sfID2.length()));
        }
        catch(Throwable t){
        	assertThat("Incorrect CF ID format",false, is(true));
        	return;
        }
        
        assertThat("ID should increment by 1", idNumberPart2, is(idNumberPart1+1));
       
    }
    
    
    @Test
    public void testCeilingisBreezy(){
    	assertThat("isBreezy() returned false",ceilingFan.isBreezy(),is(true));
        //assertTrue(ceilingFan.isBreezy());   
    }
    
    @Test
    public void testCeilingFanBreeziness(){  
        int breeziness = ceilingFan.getBreeziness();
        assertThat("getBreziness() returns "+ breeziness + " should return 2",breeziness, is(2));       
    	//assertEquals(2,ceilingFan.getBreeziness());
    }
    
    @Test
    public void testCeilingFanisNoisy(){
    	assertThat("isNoisy() returned false",ceilingFan.isNoisy(),is(false));
    	//assertFalse(ceilingFan.isNoisy());   
    }
    
    @Test
    public void testCeilingFanNoisiness(){   
        int noisiness = ceilingFan.getNoisiness();
        assertThat("getNoisiness() returned "+ noisiness + "should return 0",noisiness,is(0));
        //assertEquals(0,ceilingFan.getNoisiness());
    }
    
    @Test
    public void testOnOffDefaultState(){
    	assertThat("isOn() should be false by default",ceilingFan.isOn(),is(false));
    }
    

    @Test
    public void testOnOffTurnOn(){
        ceilingFan.turnOn();
        assertThat("isOn() should return true after calling turnOn()",ceilingFan.isOn(),is(true));
    }
    
    

    @Test
    public void testOnOffTurnOnThenOff(){
        ceilingFan.turnOn();
        ceilingFan.turnOff();
        assertThat("isOn() should return false after calling turnOn() then turnOff()",ceilingFan.isOn(), is(false));
    }
    
    @Test
    public void testCools(){
        int coolsBy = ceilingFan.coolsBy();
        assertThat("coolsBy() returned "+coolsBy+" expected 3",ceilingFan.coolsBy(),is(3));
        //assertEquals(3,ceilingFan.coolsBy()); 
    }
    
    @Test
    public void testIsPortableDevice(){
    	assertThat("Should not implements PortableDevice ",ceilingFan instanceof PortableDevice,is(false));	
        //assertFalse(ceilingFan instanceof PortableDevice);
    }
    
    @Test
    public void testIsDevice(){
    	assertThat("Should implement Device",ceilingFan instanceof Device,is(true));
        //assertTrue(ceilingFan instanceof Device);
    }
    
    @Test
    public void testIsFan(){
    	assertThat("Should extend Fan",ceilingFan instanceof Fan,is(true));
        //assertTrue(ceilingFan instanceof Fan);
    }
}
