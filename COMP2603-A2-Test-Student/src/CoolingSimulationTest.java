

import static org.junit.Assert.*;

import java.util.ArrayList;

import org.hamcrest.core.IsNull;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import static org.hamcrest.CoreMatchers.*;

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
    public void testRoomsCreatedIsNotNull(){
        java.util.ArrayList<Room> rooms = sim.getRooms();
        assertThat("getRomms() returned null", rooms, IsNull.notNullValue());
    }
    
    @Test
    public void testRoomsCreatedLength(){
        java.util.ArrayList<Room> rooms = sim.getRooms();
        try {
        	int length = rooms.size();
        	assertThat("romms.size() is "+ length+" + should be 4)", length, is(4));
        }
        catch(Throwable t){
        	assertThat("getRooms() returned null", true, is(false));
        }
    }
    
    @Test
    public void testDevicesCreatedRoom1(){
        Room r = sim.getRoom(1);
        try{
        	ArrayList<Device> devices = r.getDevices();
        	try{
        		int l = devices.size();
        		assertThat("room 1 has "+ l +" devices should have 5",l, is(5));
        	}//TO DO should really warp this up in a function
        	catch(Throwable t){
        		assertThat("room 1 getDevices() returns null",true,is(false));
        	}
        }
        catch(Throwable t){
        	assertThat("getRoom(1) returns null",true,is(false));
        }
    }
    
    
    @Test
    public void testDevicesCreatedRoom2(){
        Room r = sim.getRoom(2);
        try{
        	ArrayList<Device> devices = r.getDevices();
        	try{
        		int l = devices.size();
        		assertThat("room 2 has "+ l +" devices should have 7",l, is(7));
        	}//TO DO should really warp this up in a function
        	catch(Throwable t){
        		assertThat("room 2 getDevices() returns null",true,is(false));
        	}
        }
        catch(Throwable t){
        	assertThat("getRoom(2) returns null",true,is(false));
        }
    }
    
    @Test
    public void testDevicesCreatedRoom3(){
        Room r = sim.getRoom(3);
        try{
        	ArrayList<Device> devices = r.getDevices();
        	try{
        		int l = devices.size();
        		assertThat("room 3 has "+ l +" devices should have 5",l, is(5));
        	}//TO DO should really warp this up in a function
        	catch(Throwable t){
        		assertThat("room 3 getDevices() returns null",true,is(false));
        	}
        }
        catch(Throwable t){
        	assertThat("getRoom(3) returns null",true,is(false));
        }
    }
    
    @Test
    public void testDevicesCreatedRoom4(){
        Room r = sim.getRoom(4);
        try{
        	ArrayList<Device> devices = r.getDevices();
        	try{
        		int l = devices.size();
        		assertThat("room 4 has "+ l +" devices should have 3",l, is(3));
        	}//TO DO should really warp this up in a function
        	catch(Throwable t){
        		assertThat("room 4 getDevices() returns null",true,is(false));
        	}
        }
        catch(Throwable t){
        	assertThat("getRoom(4) returns null",true,is(false));
        }
    }
    
    
    @Test
    public void testRoom1ConditionsIsNull(){
        sim.coolRoom1();
        Room r = sim.getRoom(1);
        assertThat("getRoom(1) return null after calling coolRoom1()", r, IsNull.notNullValue());
    }
    
    
    @Test
    public void testRoom1ConditionsValues(){
        sim.coolRoom1();
        Room r = sim.getRoom(1);
        int temperature =-1, breeziness=-1, noisiness=-1; 
        try {
	        temperature = r.getTemperature();
	        breeziness = r.getBreeziness();
	        noisiness = r.getNoisiness();
        }
        catch(Throwable t){
        	assertThat("getRoom(1) returned null after calling coolRoom1()",true,is(false));
        }
        
        assertThat("After calling coolRom1() should have temperature : "+temperature+" breeziness : "+ breeziness +" noisiness" + noisiness +" expcted 24, 8, and 6 respectively",
        		temperature == 24 && breeziness == 8 && noisiness == 6, is(true));
    }

    @Test
    public void testRoom2ConditionsIsNull(){
        sim.coolRoom2();
        Room r = sim.getRoom(2);
        assertThat("getRoom(2) return null after calling coolRoom2()", r, IsNull.notNullValue());
    }
    
    
    @Test
    public void testRoom2ConditionsValues(){
        sim.coolRoom2();
        Room r = sim.getRoom(2);
        int temperature =-1, breeziness=-1, noisiness=-1; 
        try {
	        temperature = r.getTemperature();
	        breeziness = r.getBreeziness();
	        noisiness = r.getNoisiness();
        }
        catch(Throwable t){
        	assertThat("getRoom(2) returned null after calling coolRoom2()",true,is(false));
        }
        
        assertThat("After calling coolRom2() should have temperature : "+temperature+" breeziness : "+ breeziness +" noisiness" + noisiness +" expcted 25, 0, and 0 respectively",
        		temperature == 25 && breeziness == 0 && noisiness == 0, is(true));
    }

    @Test
    public void testRoom3ConditionsIsNull(){
        sim.coolRoom3();
        Room r = sim.getRoom(3);
        assertThat("getRoom(3) return null after calling coolRoom3()", r, IsNull.notNullValue());
    }
    
    
    @Test
    public void testRoom3ConditionsValues(){
        sim.coolRoom3();
        Room r = sim.getRoom(3);
        int temperature =-1, breeziness=-1, noisiness=-1; 
        try {
	        temperature = r.getTemperature();
	        breeziness = r.getBreeziness();
	        noisiness = r.getNoisiness();
	    }
        catch(Throwable t){
        	assertThat("getRoom(3) returned null after calling coolRoom3()",true,is(false));
        }
    
        assertThat("After calling coolRom3() should have temperature : "+temperature+" breeziness : "+ breeziness +" noisiness" + noisiness +" expcted 26, 4, and 0 respectively",
        		temperature == 26 && breeziness == 4 && noisiness == 0, is(true));
            
    }
    
    @Test
    public void testRoom4ConditionsIsNull(){
        sim.coolRoom4();
        Room r = sim.getRoom(4);
        assertThat("getRoom(4) return null after calling coolRoom4()", r, IsNull.notNullValue());
    }
    
    
    @Test
    public void testRoom4ConditionsValues(){
        sim.coolRoom4();
        Room r = sim.getRoom(4);
        int temperature = -1,breeziness = -1, noisiness =-1;
    
        try {
	        temperature = r.getTemperature();
	        breeziness = r.getBreeziness();
	        noisiness = r.getNoisiness();
	    }
        catch(Throwable t){
        	t.printStackTrace(System.out);
        	assertThat("getRoom(4) returned null after calling coolRoom4()",true,is(false));
        }
        
        boolean test = temperature == 7 && breeziness == 22 && noisiness == 20;
        assertThat("After calling coolRom4() should have temperature : "+temperature+" breeziness : "+ breeziness +" noisiness " + noisiness +" expcted 7, 22, and 20 respectively",
        		test, is(true));
          
    }
    
     @Test
    public void testSwapPortableDevicesRoom4Length(){
        sim.swapPortableDevices(sim.getRoom(3),sim.getRoom(4));
        try{
        	int l = sim.getRoom(4).getDevices().size();
        	assertThat("after swapPortableDevices call with room 3 and 4, room 4 has "+l+" devices, expected 5",
        			l, is(5));
        }
        catch(Throwable t){
        	assertThat("getRoom(4) returns null",true,is(false));
        }
    }
     
     @Test
    public void testSwapPortableDevices(){
        sim.swapPortableDevices(sim.getRoom(3),sim.getRoom(4));
        sim.coolRoom1();
        sim.swapPortableDevices(sim.getRoom(1),sim.getRoom(4));
       
        try{
        	int l = sim.getRoom(4).getDevices().size();
        	assertThat("after swapPortableDevices call with room 3 and 4, coolRoom1() then swap with Room 1 and 4, room 4 has "+l+" devices, expected 5",
        			l, is(5));
        }
        catch(Throwable t){
        	assertThat("getRoom(4) returns null",true,is(false));
        }
    }
   
}
