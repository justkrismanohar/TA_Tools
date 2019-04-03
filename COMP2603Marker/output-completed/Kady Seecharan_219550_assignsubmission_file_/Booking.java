
/**
Name: Kady Seecharan
ID: 816002036
 */
public class Booking
{
    
    private static int bookingIDCounter =0;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    //constructor
    public Booking(String description,int duration, int numSeating)
    {
    this.bookingIDCounter++;
    this.bookingID= bookingIDCounter;
    this.description= description;
    this.duration= duration;
    this.location= location;
    this.numSeating= numSeating;
    }
    
    //accessor methods
    public int getBookingID(){
        return this.bookingID;
    }
    
    public String getDescription(){
        return this.description;
    }
    
    public int getDuration(){
        return this.duration;
    }
    
    public String getLocation(){
        return this.location;  
    }
    
    public int getNumSeating(){
        return this.numSeating;  
    }
    
    //mutator methods
    public void setDuration(int newDuration){
        this.duration= newDuration;
    }
    
    public void setDescription(String newDes){
        this.description= newDes;
    }
    
    public void setLocation(String newLocation){
        this.location= newLocation;
    }
    
    public void setNumSeating(int newNumSeating){
        this.numSeating= newNumSeating;
    }
    
   
    
    public String toString(){
        String s;
        s= "";
        s+= "\nBookingID: " + getBookingID() + "\n";
        s+= "Description: " + getDescription() + "\n";
        s+= "Duration: " + getDuration() + "  hours\n";
        s+= "Location: " + getLocation() + "\n";
        s+= "Seats: " + getNumSeating() + "\n";
        return s;
    }
    
   

}
