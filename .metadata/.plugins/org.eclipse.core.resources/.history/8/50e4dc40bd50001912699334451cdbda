

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
    /**
     * Default constructor for test class StandingFanTest
     */
    public StandingFanTest()
    {
     standingFan = new StandingFan();
    }

    /**
     * Sets up the test fixture.
     *
     * Called before every test case method.
     */
    @Before
    public void setUp()
    {
    }

    /**
     * Tears down the test fixture.
     *
     * Called after every test case method.
     */
    @After
    public void tearDown()
    {
    }


    @Test
    public void testID()
    {
        Device sfN = new StandingFan();
        Device sfM = new StandingFan(); 
        String sfID1 = sfN.getID();
        String sfID2 = sfM.getID();
        int idNumberPart1 = Integer.parseInt(sfID1.substring(4,sfID1.length()));
        int idNumberPart2 = Integer.parseInt(sfID2.substring(4,sfID2.length()));
        String idPrefix = sfID1.substring(0,4);     
        assertEquals(idPrefix, "SFAN");
        assertEquals(idNumberPart2,idNumberPart1+1);
    }
     @Test
    public void testStandingFanIsBreezy(){
        assertTrue(standingFan.isBreezy());   
    }
    @Test
    public void testStandingFanBreeziness(){  
        assertEquals(2,standingFan.getBreeziness());
    }
    @Test
    public void testStandingFanIsNoisy(){
        assertTrue(standingFan.isNoisy());   
    }
    @Test
    public void testStandingFanNoisiness(){   
        assertEquals(2,standingFan.getNoisiness());
    }
    @Test
    public void testOnOff(){
        assertFalse(standingFan.isOn()); 
        standingFan.turnOn();
        assertTrue(standingFan.isOn()); 
        standingFan.turnOff();
        assertFalse(standingFan.isOn()); 
    }
    @Test
    public void testCools(){
        assertEquals(1,standingFan.coolsBy()); 
    }
    @Test
    public void testIsPortableDevice(){
        assertTrue(standingFan instanceof PortableDevice);
    }
    @Test
    public void testIsDevice(){
        assertTrue(standingFan instanceof Device);
    }
    @Test
    public void testIsFan(){
        assertTrue(standingFan instanceof Fan);
    }
}


