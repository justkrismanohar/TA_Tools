import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class ACTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class ACTest
{
    
     private AC ac1;
    /**
     * Default constructor for test class ACTest
     */
    public ACTest()
    {
        ac1 = new AC();
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
    public void testACCreation(){     
        Device acN = new AC();
        Device acM = new AC(); 
        String acID1 = acN.getID();
        String acID2 = acM.getID();
        int idNumberPart1 = Integer.parseInt(acID1.substring(2,acID1.length()));
        int idNumberPart2 = Integer.parseInt(acID2.substring(2,acID2.length()));
        String idPrefix = acID1.substring(0,2);     
        assertEquals(idPrefix, "AC");
        assertEquals(idNumberPart2,idNumberPart1+1);
    }
    
    @Test
    public void testACisBreezy(){
        assertFalse(ac1.isBreezy());   
    }
    @Test
    public void testACBreeziness(){ 
        assertEquals(0,ac1.getBreeziness());
    }
    @Test
    public void testAC_isNoisy(){
        assertFalse(ac1.isNoisy());      
    }
    @Test
    public void testACNoisiness(){     
        assertEquals(0,ac1.getNoisiness());
    }
    @Test
    public void testOnOff(){
        assertFalse(ac1.isOn()); 
        ac1.turnOn();
        assertTrue(ac1.isOn()); 
        ac1.turnOff();
        assertFalse(ac1.isOn()); 
    }
    
     public void testCools(){
        assertEquals(5,ac1.coolsBy()); 
    }
    @Test
    public void testIsDevice(){
        assertTrue(ac1 instanceof Device);
    }
    @Test
    public void testIsPortableDevice(){
        assertFalse(ac1 instanceof PortableDevice);
    }
    
}

