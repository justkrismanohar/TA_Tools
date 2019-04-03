

public final class StandingFan extends Fan implements PortableDevice{
    
    public StandingFan(){
        super(2);
    }
    
    public String getID(){
        return "SFAN"+id;
    }
    public boolean isNoisy(){
        return true;
    }
    public int coolsBy(){ 
        return 1;
    }
       
       
}
