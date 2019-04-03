//andrez Bravo 816011156

public class Booking
{
    // instance variables - replace the example below with your own
    private static int bookingIDCounter=1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
   
    public Booking(String description, int duration, int numSeating)
    {
        this.description=description;
        this.duration=duration;
        this.numSeating=numSeating;
        this.bookingID=generateBookingID();
    }
    public  int generateBookingID()
    {
        bookingID=bookingIDCounter;
        bookingIDCounter+=1;
        return bookingID;
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
     public void setLocation(String location)
    {
        this.location=location;
    }
    public int getNumSeating()
    {
        return numSeating;
    }

    public String toString ()
    {
        return "BookingID: " + bookingID + " description: " + description +
        " duration: " + duration + "hr(s) location: " + location;
    }
    
    
}
