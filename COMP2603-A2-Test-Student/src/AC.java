

public class AC implements Device{
    private boolean isOn;
    private String id;
    private static int idCounter = 1;
    
    
    public AC(){
        isOn = false;
        id = "AC"+idCounter;
        idCounter++;
    }
    
        
    public boolean isOn(){return isOn;}
    public int getBreeziness(){return 0;}
    public int getNoisiness(){return 0;}
    
    public String getID(){return id;}
    public boolean isBreezy(){ return false;}
    public boolean isNoisy(){ return false;}
    public void turnOn(){ isOn= true;}
    public void turnOff(){ isOn = false;}
    public int coolsBy(){ return 5 ;}
    
}