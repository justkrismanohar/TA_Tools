
 /**
 * 816009808
 *
 * 
 * 
 */
public class Booking
{
    private static int bookIDCounter=1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    // Constructer 
    public Booking (String description, int duration, int numSeating)
    {
        this.description = description;
        this.duration = duration;
        this.numSeating =numSeating;
        bookingID=bookIDCounter;
        bookIDCounter++;
               
            
    }
    
    public String toString()
    {
        String bookingDetails ="\nBooking ID: "+bookingID+" Type : " +description+" "+duration+" Hours  Location: "+getLocation();
        return bookingDetails;
    }
    
    public int getBookingID()
    {
        return bookingID;
    }
    
    public String getLocation()
    {
        return location;
    }
    
    public String getDescription()
    {
        return description;
    }
    
    public int getDuration()
    {
        return duration;
    }
    
     public void setLocation(String name)
   {
       location = name;
    }
    
}
