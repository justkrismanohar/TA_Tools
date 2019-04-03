//Kerron Patram
//816003101

//Booking class modelling a user's request to make a booking
public class Booking{
    //declaration of attributes of Booking class
    private static int bookingIDCounter=1;
    private int bookingID;
    private String type;
    private int period;
    private String location;
    private int numseating;
    
    //Constructor for Booking
    public Booking(String type, int period, int numSeating)
    {
        this.type=type;
        this.period=period;
        this.numseating=numSeating;
        this.bookingID=bookingIDCounter;
        bookingIDCounter++; //increments on each booking instance
        this.location=null; 
    }
     
    
    public void allocate(String room)
    { 
        location=room;
    }
    
    //returns the bookingID
    public int getID()
    {
        return bookingID;
    }
    
    //returns a string containing details of the booking
    public String toString()
    { 
        return "BookingID: " + bookingID +", " + "TYPE: " + type +", " + "period: " + Integer.toString(period) + " Hour(s)" + ", " +  "Number of seats: "+ Integer.toString(numseating) +", " + "Location: "+ location + "\n"; 
    }
}