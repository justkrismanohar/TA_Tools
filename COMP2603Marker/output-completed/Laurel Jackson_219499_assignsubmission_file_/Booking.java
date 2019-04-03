
/*
 * Student ID - 816004212
 */
public class Booking
{
    // instance variables
    private static int bookingIDCounter = 1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    

    /**
     * Constructor for objects of class Booking
     */
    public Booking(String description, int duration, int numSeating)
    {
        // initialise instance variables
        bookingID = bookingIDCounter;
        this.description = description;
        this.duration = duration;
        this.numSeating = numSeating;
        bookingIDCounter++;
        
    }
   
    
    public String toString(){
        String details;
        
        details = "BOOKING ID: " + bookingID + " TYPE: " + description + " " +  duration + " HOURS"; 
        return details;
    }

    public int getBookingID(){
        return bookingID;
    }
    
    public int getnumSeating(){
        return numSeating;
    }
    
    public String getDescription(){
        return description;
    }
    
    
}
