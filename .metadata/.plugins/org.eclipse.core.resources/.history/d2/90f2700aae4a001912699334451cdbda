

import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class CoolingSimulationTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class CoolingSimulationTest
{
    private CoolingSimulation sim;
   
    /**
     * Default constructor for test class CoolingSimulationTest
     */
    public CoolingSimulationTest()
    {
    }

    /**
     * Sets up the test fixture.
     *
     * Called before every test case method.
     */
    @Before
    public void setUp()
    { 
        sim = new CoolingSimulation();
        sim.createRooms();
        sim.createDevices();
        
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
    public void testRoomsCreated(){
        java.util.ArrayList<Room> rooms = sim.getRooms();
        assertNotNull(rooms);
        assertEquals(4,rooms.size());
    }
    @Test
    public void testDevicesCreatedRoom1(){
        java.util.ArrayList<Room> rooms = sim.getRooms();
        Room r = sim.getRoom(1);
        assertEquals(r.getDevices().size(),5);
    }
    @Test
    public void testDevicesCreatedRoom2(){
        java.util.ArrayList<Room> rooms = sim.getRooms();
        Room r = sim.getRoom(2);
        assertEquals(r.getDevices().size(),7);
    }
    @Test
    public void testDevicesCreatedRoom3(){
        java.util.ArrayList<Room> rooms = sim.getRooms();
        Room r = sim.getRoom(3);
        assertEquals(r.getDevices().size(),5);
    }
    @Test
    public void testDevicesCreatedRoom4(){
        java.util.ArrayList<Room> rooms = sim.getRooms();
        Room r = sim.getRoom(4);
        assertEquals(r.getDevices().size(),3);
    }
    @Test
    public void testRoom1Conditions(){
        sim.coolRoom1();
        Room r = sim.getRoom(1);
        assertNotNull(r);
        int temperature = r.getTemperature();
        int breeziness = r.getBreeziness();
        int noisiness = r.getNoisiness();
        assertEquals(24,temperature);
        assertEquals(8,breeziness);
        assertEquals(6,noisiness);
    }
    @Test
    public void testRoom2Conditions(){ 
        sim.coolRoom2();
        Room r = sim.getRoom(2);
        assertNotNull(r);
        int temperature = r.getTemperature();
        int breeziness = r.getBreeziness();
        int noisiness = r.getNoisiness();
        assertEquals(25,temperature);
        assertEquals(0,breeziness);
        assertEquals(0,noisiness);
    }
    @Test
    public void testRoom3Conditions(){
        sim.coolRoom3();
        Room r = sim.getRoom(3);
        assertNotNull(r);
        int temperature = r.getTemperature();
        int breeziness = r.getBreeziness();
        int noisiness = r.getNoisiness();
        assertEquals(26,temperature);
        assertEquals(4,breeziness);
        assertEquals(0,noisiness);
    }
    @Test
    public void testRoom4Conditions(){
        sim.coolRoom1();
        sim.coolRoom2();
        sim.coolRoom3();
        sim.coolRoom4();
        Room r4 = sim.getRoom(4);
        assertNotNull(r4);
        int temperature = r4.getTemperature();
        int breeziness = r4.getBreeziness();
        int noisiness = r4.getNoisiness();
        assertEquals(10,temperature);
        assertEquals(16,breeziness);
        assertEquals(14,noisiness);
    }
    
     @Test
    public void testSwapPortableDevices(){
        sim.swapPortableDevices(sim.getRoom(3),sim.getRoom(4));
        assertEquals(5,sim.getRoom(4).getDevices().size());
        sim.coolRoom1();
        sim.swapPortableDevices(sim.getRoom(1),sim.getRoom(4));
        assertEquals(5,sim.getRoom(4).getDevices().size());

    }
   
}
