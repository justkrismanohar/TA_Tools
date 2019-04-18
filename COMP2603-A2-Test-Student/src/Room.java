

import java.util.ArrayList;

public class Room{
    
    private ArrayList<Device> devices;
    private int actualTemperature;
    private int lastTemperature;
    private int actualBreeziness;
    private int actualNoisiness;

    public Room(int startingTemperature){
        devices = new ArrayList<Device>();
        this.actualTemperature = startingTemperature;
    }

    public ArrayList<Device> getDevices(){
        return devices;
    }
    
    public int getTemperatureDrop(){
        int tempDrop = 0;
        for(Device d: devices){
         if(d.isOn())
          tempDrop += d.coolsBy();
        }
        return tempDrop;
    }
    
    public int getTemperature(){
        int tempDrop = getTemperatureDrop();
        
        if( (lastTemperature - tempDrop) != actualTemperature){
            lastTemperature = actualTemperature;
            actualTemperature = lastTemperature - tempDrop;
        }
        return actualTemperature;
    }
    
    public int getBreeziness(){
       int currentBreeziness=0; 
        for(Device d: devices){
         if(d.isOn() && d.isBreezy())
          currentBreeziness += d.getBreeziness();
        }
        if(currentBreeziness != actualBreeziness)
            actualBreeziness = currentBreeziness;
        return actualBreeziness;
    }
    
     public int getNoisiness(){
       int currentNoisiness=0; 
        for(Device d: devices){
         if(d.isOn() && d.isNoisy())
          currentNoisiness += d.getNoisiness();
        }
        if(currentNoisiness != actualNoisiness)
            actualNoisiness = currentNoisiness;
        return actualNoisiness;
    }
    
    public boolean addDevice(Device d){
        if(!devices.contains(d)){
            devices.add(d);     
            return true;
        }
        return false;
    }
   
    public boolean removeDevice(Device d){
        if(d instanceof PortableDevice){
            return devices.remove(d);
        }
        return false;
    }

    public void printState(){
        System.out.println("Temperature: "+getTemperature());
        System.out.println("Breeziness: "+getBreeziness());
        System.out.println("Noisiness: "+getNoisiness());
        for(Device d: devices){
           System.out.println(d.getID() +" "+  d.isOn());
            
        }
        
        System.out.println("----------------------");
        
    }

}