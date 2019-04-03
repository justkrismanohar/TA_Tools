

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
    /**
     * Default constructor for test class CeilingFanTest
     */
    public CeilingFanTest()
    {
        ceilingFan = new CeilingFan();
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
    public void testID(){
            Device sfN = new CeilingFan();
            Device sfM = new CeilingFan(); 
            String sfID1 = sfN.getID();
            String sfID2 = sfM.getID();
            int idNumberPart1 = Integer.parseInt(sfID1.substring(4,sfID1.length()));
            int idNumberPart2 = Integer.parseInt(sfID2.substring(4,sfID2.length()));
            String idPrefix = sfID1.substring(0,4);     
            assertEquals(idPrefix, "CFAN");
            assertEquals(idNumberPart2,idNumberPart1+1);
    }
    
    @Test
    public void testCeilingisBreezy(){
        assertTrue(ceilingFan.isBreezy());   
    }
    @Test
    public void testCeilingFanBreeziness(){  
        assertEquals(2,ceilingFan.getBreeziness());
    }
    @Test
    public void testCeilingFanisNoisy(){
        assertFalse(ceilingFan.isNoisy());   
    }
    @Test
    public void testCeilingFanNoisiness(){   
        assertEquals(0,ceilingFan.getNoisiness());
    }
    @Test
    public void testOnOff(){
        assertFalse(ceilingFan.isOn()); 
        ceilingFan.turnOn();
        assertTrue(ceilingFan.isOn()); 
        ceilingFan.turnOff();
        assertFalse(ceilingFan.isOn()); 
    }
    @Test
    public void testCools(){
        assertEquals(3,ceilingFan.coolsBy()); 
    }
    @Test
    public void testIsPortableDevice(){
        assertFalse(ceilingFan instanceof PortableDevice);
    }
    @Test
    public void testIsDevice(){
        assertTrue(ceilingFan instanceof Device);
    }
    @Test
    public void testIsFan(){
        assertTrue(ceilingFan instanceof Fan);
    }
}
