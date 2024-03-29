

public abstract class Fan implements Device{
    private int breeziness;
    private int noisiness;
    private boolean isOn;
    protected String id;
    private static int idCounter = 1;
    
    public Fan(int noisiness){
        this.breeziness = 2;
        this.noisiness = noisiness;
        id = ""+idCounter;
        idCounter++;
    }
     
    public boolean isOn(){return isOn;}
  
    
    public int getBreeziness(){
        return breeziness;
    }
    public int getNoisiness(){
        return noisiness;
    }
    
    public boolean isBreezy(){
        return true;
    }
    
    
    public void turnOn(){ isOn= true;}
    public void turnOff(){ isOn = false;}
 
    public boolean equals(Device d){
        return d.getID().equals(this.id);
    }
    public String toString(){
        return "" + id;
    }
    
}