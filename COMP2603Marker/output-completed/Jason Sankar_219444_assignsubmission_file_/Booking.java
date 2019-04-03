
/**
 Jason Sankar
 816001067
 */
public class Booking 
{
    // instance variables - replace the example below with your own
    private static int bookingIDCounter=1;
    public static int bookingID;
    public String description;
    public int duration;
    public String location;
    public int numSeating;

    /**
     * Constructor for objects of class Booking
     */
    public Booking(String description,int duration,int numSeating)
    {
    this.description=description;
    this.numSeating=numSeating;
    this.duration=duration;
    this.bookingID=this.bookingIDCounter;
    this.bookingIDCounter++;
    }
/**
    
    public String toString()
    {
        // put your code here
       
    }
*/
}
