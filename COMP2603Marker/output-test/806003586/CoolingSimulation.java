
import java.util.ArrayList;

public class CoolingSimulation{
    
    private ArrayList<Room> rooms;

    public CoolingSimulation(){
        rooms = new ArrayList<>();
        
    }
    
    public ArrayList<Room> getRooms(){
        return rooms;
    }
    
    public Room getRoom(int i){
        if(i>0 || i<5)
            return rooms.get(i-1);
        return null;
    }
    
    public void createRooms(){   
        rooms.add(new Room(30));
        rooms.add(new Room(35));
        rooms.add(new Room(37));
        rooms.add(new Room(25));
    }
    
     public void createDevices(){   
        for(Room r: rooms){
            r.addDevice(new AC());
            r.addDevice(new CeilingFan());
            r.addDevice(new StandingFan());
        }
        getRoom(1).addDevice(new StandingFan());
        getRoom(1).addDevice(new StandingFan());        
        
        getRoom(2).addDevice(new AC());
        for(int i = 0;i<3; i++)
            getRoom(2).addDevice(new StandingFan());
        
        getRoom(3).addDevice(new CeilingFan());
        getRoom(3).addDevice(new StandingFan());    
    }
    
    public void coolRoom1(){      
        ArrayList<Device> devices = getRoom(1).getDevices();
        for(Device d: devices){
            if(d.isBreezy() || d.isNoisy())
                d.turnOn();
        }
    }
    
    public void coolRoom2(){
        ArrayList<Device> devices = getRoom(2).getDevices();
         for(Device d: devices){
            if(!d.isBreezy() && !d.isNoisy())
                d.turnOn();
        }
        
    }
    
    public void coolRoom3(){
        ArrayList<Device> devices = getRoom(3).getDevices();
        for(Device d: devices){
            if(!d.isNoisy())
                d.turnOn();
        }
    }
    
    public void coolRoom4(){
        swapPortableDevices(getRoom(1), getRoom(4));
        swapPortableDevices(getRoom(2), getRoom(4));
        swapPortableDevices(getRoom(3), getRoom(4));
        for(Device d: getRoom(4).getDevices())
            d.turnOn();

    }
    
    public void swapPortableDevices(Room firstRoom, Room secondRoom){
        for(int i=0; i<firstRoom.getDevices().size(); i++){
            Device d = firstRoom.getDevices().get(i);
            if(d instanceof PortableDevice && !d.isOn()){
                firstRoom.removeDevice(d);
                i--;
                secondRoom.addDevice(d);
            }
        }     
    }
    
    public void printStates(){
        for(Room r: rooms)
            r.printState();
    }
    
    
    public static void main(String[] args){
        CoolingSimulation sim = new CoolingSimulation();
        sim.createRooms();
        sim.createDevices();
        sim.coolRoom1();
        sim.coolRoom2();
        sim.coolRoom3();
        sim.coolRoom4();
        sim.printStates();  
    }
    
}