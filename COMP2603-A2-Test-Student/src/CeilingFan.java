

public class CeilingFan extends Fan{
    
    public CeilingFan(){
        super(0);
    }
    
    public String getID(){
        return "CFAN"+id;
    }
    
    public boolean isNoisy(){
        return false;
    }
    
    public int coolsBy(){ 
        return 3 ;
    }
       
    public String toString(){
        return "Breeziness "+ getBreeziness() + " Noisiness: " + getNoisiness();
    }
}