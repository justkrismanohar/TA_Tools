
/**
 816010441 Jevon Greenidge
 */
public class Booking
{
    
    private static int bookingIDCounter=1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;

    
    public Booking(String description, int duration, int numSeating)
    {
        bookingID=bookingIDCounter;
        bookingIDCounter ++;
        this.description=description;
        this.duration=duration;
        this.numSeating=numSeating;
    }

    
    public String toString()
    {
        
        String details="booking ID" + bookingID +"Description"+ description + "Duration" + duration + "Number of Seating" + numSeating;
        
        return details;
    }
    
    // Accessors 
    
    public int getBookingID(){
        return bookingID;
    }
    
    public String getDescription(){
        return description;
    }
    
    public int getDuration(){
        return duration;
            }
    
     public String getLocation(){
        return location;
    }
    
    public int getNumSeating(){
        return numSeating;
    }
    
    
    // mutators
    
    public void makeLocation( String location){
        this.location=location;
    }
     
    
    
    
    
    
    
}
