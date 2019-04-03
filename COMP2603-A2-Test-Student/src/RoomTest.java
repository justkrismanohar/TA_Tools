

import static org.junit.Assert.*;

import org.hamcrest.core.IsNull;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import static org.hamcrest.CoreMatchers.*;

/**
 * The test class RoomTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class RoomTest
{
    private Device ceilingF1;
    private Device standingF1;
    
    private Device aC1;
    private Room room1;

    Room room4 = new Room(25);
    Room room = new Room(30);
    Room room2 = new Room(35);
    Room room3 = new Room(37);
    
    /**
     * Sets up the test fixture.
     *
     * Called before every test case method.
     */
    @Before
    public void setUp()
    {
        ceilingF1 = new CeilingFan();
        standingF1 = new StandingFan();
        aC1 = new AC();
        room1 = new Room(30);
    }

    @Test
    public void testDeviceArrayList(){
        java.util.ArrayList<Device> devices = room1.getDevices();
        //assertNotNull(devices);
        assertThat("getDevices() should not return null ",devices, IsNull.notNullValue());
    }
    
    @Test
    public void testAddDevices(){
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        java.util.ArrayList<Device> devices =room1.getDevices();
        assertThat("Added 3 devices, the length of the devices ArrayList should be 3", devices.size(), is(3));
        //assertEquals(3,devices.size());
    }
    
    @Test
    public void testRemoveCeilingFan(){
        room1.addDevice(ceilingF1);
        //assertFalse(room1.removeDevice(ceilingF1));
        assertThat("Should not be able to move a ceilingFan ",room1.removeDevice(ceilingF1), is(false));
    }
    
    @Test
    public void testRemoveAC(){
        room1.addDevice(aC1);
        assertThat("Should not be able to moe an AC", room1.removeDevice(aC1), is(false));
        //assertFalse(room1.removeDevice(aC1));
    }

    
    @Test
    public void testRemoveStandingFan(){
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        assertThat("Added a Standing fan but could not remove it",room1.removeDevice(standingF1), is(true));
        //assertTrue(room1.removeDevice(standingF1));
    }

    @Test
    public void testRemoveLength(){
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        room1.removeDevice(standingF1);
        java.util.ArrayList<Device> devices =room1.getDevices();
        assertThat("Added 3 things removed 1, there should be only 2 devices",devices.size(),is(2));
    }
    
    @Test
    public void testGetDevices()
    {
        room1.addDevice(ceilingF1); 
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        
        java.util.ArrayList<Device> devices = room1.getDevices();
        int acCount = 0, cFCount = 0, sFCount = 0, otherCount = 0;
        
        for(Device d: devices){
            
        	if(d instanceof AC){
        		acCount++;
            }
            
        	else if(d instanceof CeilingFan){
            	cFCount++;
            }
            
        	else if(d instanceof StandingFan){
            	sFCount++;
            }
        	
        	else{
        		otherCount = 0;
        	}
        }
        
        assertThat("Added one AC, CF and SF but getDevices() returned " + acCount +" ACs "+ cFCount +" CFs "+ sFCount +" SFs and "+otherCount +" other devices",
        		acCount == 1 && cFCount == 1 && sFCount == 1 && otherCount == 0, is(true));
        
    }
    
    
    @Test
    public void testRoomBreezinessAllOff()
    {
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        int breeziness = room1.getBreeziness();
        assertThat("All devices off, getBreeziness() returned "+ breeziness +" should be 0",breeziness , is(0));
        //assertEquals(room1.getBreeziness(), 0);
    }

    
    @Test
    public void testRoomBreezinessSFOnly()
    {
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        //assertEquals(room1.getBreeziness(), 0);
        standingF1.turnOn();
        //assertEquals(room1.getBreeziness(), 2);
        int breeziness = room1.getBreeziness();
        assertThat("Only SF is on, getBreeziness() returned "+breeziness+" should be 2", breeziness, is(2));
    }
    
    @Test
    public void testRoomBreezinessSFAndCFOn()
    {
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        standingF1.turnOn(); 
        ceilingF1.turnOn();
        //assertEquals(room1.getBreeziness(), 4);
        int breeziness = room1.getBreeziness();
        assertThat("SF and CF is on, getBreeziness() returned "+ breeziness +" should be 4", breeziness, is(4));
    }
    

    @Test
    public void testRoomBreezinessSFandCFandACOn()
    {
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        standingF1.turnOn(); 
        ceilingF1.turnOn();
        //assertEquals(room1.getBreeziness(), 4);
        aC1.turnOn();
        //assertEquals(room1.getBreeziness(), 4);
        int breeziness = room1.getBreeziness();
        assertThat("SF, CF and AC is on, getBreeziness() return "+breeziness +" should be 4", breeziness, is(4));
    }
    
    
    @Test
    public void testRoomNoisinessAllOff()
    {
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        //assertEquals(room1.getNoisiness(), 0);
        int noisiness = room1.getNoisiness();
        assertThat("All devices off, getNoisiness() returned "+ noisiness +" should be 0",noisiness,is(0));
    }
    
    @Test
    public void testRoomNoisinessSFOn()
    {
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        //assertEquals(room1.getNoisiness(), 0);
        standingF1.turnOn();
        //assertEquals(room1.getNoisiness(), 2);
        int noisiness = room1.getNoisiness();
        assertThat("Only SF on, getNoisiness() returned "+ noisiness + " should be 2",noisiness,is(2));
    }
    
    @Test
    public void testRoomNoisinessSFandCFOn()
    {
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        //assertEquals(room1.getNoisiness(), 0);
        standingF1.turnOn();
        //assertEquals(room1.getNoisiness(), 2);
        ceilingF1.turnOn();
        //assertEquals(room1.getNoisiness(), 2);
        int noisiness = room1.getNoisiness();
        assertThat("Only SF and CF on, getNoisiness() returned "+ noisiness +" should be 2",noisiness, is(2));
    }
    
    @Test
    public void testRoomNoisinessSFandCFandACOn()
    {
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        //assertEquals(room1.getNoisiness(), 0);
        standingF1.turnOn();
        //assertEquals(room1.getNoisiness(), 2);
        ceilingF1.turnOn();
        //assertEquals(room1.getNoisiness(), 2);
        aC1.turnOn();
        //assertEquals(room1.getNoisiness(), 2);
        int noisiness = room1.getNoisiness();
        assertThat("Only SF, CF, and AC on, getNoisiness() returned "+ noisiness + " should be 2",noisiness, is(2));
    }
    
    @Test
    public void testTemperatureDropNothingOn()
    {
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        int tempDrop = room1.getTemperatureDrop();
        assertThat("getTemparatureDrop() returned "+ tempDrop + " should be 0",tempDrop,is(0));
        //assertEquals(room1.getTemperatureDrop(), 0);
    }
    
    @Test
    public void testTemperatureDropSFOn()
    {
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        standingF1.turnOn();
        int tempDrop = room1.getTemperatureDrop();
        assertThat("getTemperatureDrop() returned "+ tempDrop + " should be 1",tempDrop,is(1));
        //assertEquals(room1.getTemperatureDrop(), 1);
    }
    
    @Test
    public void testTemperatureDropSFAndCFOn()
    {
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        standingF1.turnOn();
        ceilingF1.turnOn();
        int tempDrop = room1.getTemperatureDrop();
        assertThat("getTemperatureDrop() returned "+ tempDrop + " should be 4",tempDrop,is(4));
        //assertEquals(room1.getTemperatureDrop(), 4);
    }
    
    @Test
    public void testTemperatureDropAllOn()
    {
        room1.addDevice(ceilingF1);
        room1.addDevice(aC1);
        room1.addDevice(standingF1);
        standingF1.turnOn();
        ceilingF1.turnOn();
        aC1.turnOn();
        int tempDrop = room1.getTemperatureDrop();
        assertThat("getTemperatureDrop() returned "+ tempDrop + " should be 9",tempDrop,is(9));
    }
    
//    @Test
//    public void testTemperatureRiseAC()
//    {
//        room1.addDevice(ceilingF1);
//        room1.addDevice(aC1);
//        room1.addDevice(standingF1);
//        standingF1.turnOn();
//        ceilingF1.turnOn();      
//        aC1.turnOn();
//        assertEquals(room1.getTemperatureDrop(), 9);
//        aC1.turnOff();
//        assertEquals(room1.getTemperatureDrop(), 4);
//        ceilingF1.turnOff();
//        assertEquals(room1.getTemperatureDrop(), 1);
//        standingF1.turnOff();
//        assertEquals(room1.getTemperatureDrop(), 0);
//    }
//    
//    @Test
//    public void testTemperatureRiseAndFall()
//    {
//        room1.addDevice(ceilingF1);
//        room1.addDevice(aC1);
//        room1.addDevice(standingF1);
//        standingF1.turnOn();
//        ceilingF1.turnOn();      
//        assertEquals(room1.getTemperatureDrop(), 4);      
//        ceilingF1.turnOff();
//        assertEquals(room1.getTemperatureDrop(), 1);
//        aC1.turnOn();
//        assertEquals(room1.getTemperatureDrop(), 6);
//        aC1.turnOff();
//        standingF1.turnOff();
//        assertEquals(room1.getTemperatureDrop(), 0);
//    }
}