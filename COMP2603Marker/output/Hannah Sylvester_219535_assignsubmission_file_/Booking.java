
/*
 * Name: HANNAH SYLVESTER
 * ID: 816007999
 */

public class Booking
{
    // instance variables - replace the example below with your own
    private static int bookingIDCounter=1;
    public int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    

    /**
     * Constructor for objects of class Booking
     */
    public Booking(String description,int duration,int numSeating)
    {
        this.description=description;
        this.duration=duration;
        this.numSeating=numSeating;
        bookingID=bookingIDCounter;
        bookingIDCounter++;
    }
    
    
    public int getBookingID()
    {
        return bookingID;
    }
    
    public String getDescription()
    {
        return description;
    }
    
    public int getDuration()
    {
        return duration;
    }
    
    public String getLocation()
    {
        return location;
    }
    
    public int getNumSeating()
    {
        return numSeating;
    }
    
    public void setLocation(String n){
        location=n;
    }  
    
    public String toString()
    {
        String details="Booking ID: " + bookingID + "Description: " + description + "Duration: "+ duration + "Location: " + location;
        return details;
    }
}
