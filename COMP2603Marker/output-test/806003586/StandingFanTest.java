

import static org.hamcrest.CoreMatchers.is;
import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class StandingFanTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class StandingFanTest
{
    private Device standingFan;
    private static Device sfN,sfM;
    private static int idNumberPart1, idNumberPart2;
    private static String idPrefix;     
    /**
     * Default constructor for test class StandingFanTest
     */
    public StandingFanTest()
    {
     standingFan = new StandingFan();

    }
    
    @Test
    public void setUpClass(){
        sfN = new StandingFan();
        sfM = new StandingFan(); 
    }
    
    @Test
    public void testSFCreationID(){
    	idPrefix = sfN.getID().substring(0,4);
        try{
        	String sfID1 = sfN.getID();
        	Integer.parseInt(sfID1.substring(4,sfID1.length()));
        	assertThat("ID prefix should be SFAN not "+idPrefix, idPrefix,is("SFAN") );
        }
        catch(Throwable t){
        	assertThat("ID prefix should be SFAN", true,is(false) );
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
        	assertThat("Incorrect SF ID format",false, is(true));
        	return;
        }
        
        assertThat("ID should increment by 1", idNumberPart2, is(idNumberPart1+1));
       
    }
    
     @Test
    public void testStandingFanIsBreezy(){
    	 assertThat("isBreezy() returned false",standingFan.isBreezy(),is(true));
    	 //assertTrue(standingFan.isBreezy());   
    }
     
    @Test
    public void testStandingFanBreeziness(){  
        int breeziness = standingFan.getBreeziness();
        assertThat("getBreziness() returns "+ breeziness + " should return 2",breeziness, is(2));
    	//assertEquals(2,standingFan.getBreeziness());
    }
    
    @Test
    public void testStandingFanIsNoisy(){
        assertThat("isNoisy() returned false",standingFan.isNoisy(),is(true));
    	//assertTrue(standingFan.isNoisy());   
    }
    
    @Test
    public void testStandingFanNoisiness(){   
        int noisiness = standingFan.getNoisiness();
        assertThat("getNoisiness() returned "+ noisiness + "should return 2",noisiness,is(2));
    	//assertEquals(2,standingFan.getNoisiness());
    }
    
    @Test
    public void testOnOffDefaultState(){
    	assertThat("isOn() should be false by default",standingFan.isOn(),is(false));
    }
    

    @Test
    public void testOnOffTurnOn(){
        standingFan.turnOn();
        assertThat("isOn() should return true after calling turnOn()",standingFan.isOn(),is(true));
    }
    

    @Test
    public void testOnOffTurnOnThenOff(){
        standingFan.turnOn();
        standingFan.turnOff();
        assertThat("isOn() should return false after calling turnOn() then turnOff()",standingFan.isOn(), is(false));
    }
    
    @Test
    public void testCools(){
        int coolsBy = standingFan.coolsBy();
        assertThat("coolsBy() returned "+coolsBy+" expected 1",standingFan.coolsBy(),is(1));
    }
    
    @Test
    public void testIsPortableDevice(){
        assertThat("Should implement PortableDevice ",standingFan instanceof PortableDevice,is(true));
    	//assertTrue(standingFan instanceof PortableDevice);
    }
    
    @Test
    public void testIsDevice(){
        assertThat("Should implement Device",standingFan instanceof Device,is(true));
    }
    
    @Test
    public void testIsFan(){
    	assertThat("Should extend Fan",standingFan instanceof Fan,is(true));
    }
}


