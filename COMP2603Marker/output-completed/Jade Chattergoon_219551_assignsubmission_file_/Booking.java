
/*/* Jade Chattergoon 816007199 COMP2603 OOP1 ASG1
 Models a Booking for an event in a Room
 */
public class Booking
{
    // instance variables - replace the example below with your own
    public  static int bookingIDCounter=1;
    private  int bookingID=0;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
   
    public Booking(String description, int duration, int numSeating)
    {
        // initialise instance variables
        
        bookingID=bookingIDCounter;
        bookingIDCounter+=1;
        
        this.duration=duration;
        this.numSeating=numSeating;
        this.description=description;
       
        
        
    }

   
    
    public void setLocation(String location){
        this.location=location;
    }
    
    public int getBookingID(){
        return bookingID;
   
    }
    public String getLocation(){
        return location;
    }
    
    public String toString()
    {
        String concatenate;
        concatenate="ID: " + bookingID + " Description: " + description + " Duration: " + duration  + " HOUR(S)" + " Location: " + location;
        return concatenate;
    }
}
