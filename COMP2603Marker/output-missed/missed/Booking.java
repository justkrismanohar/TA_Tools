
public class Booking 
{
   
    public static int bookingIDCounter=1;
    public int bookingID;
    public String description;
    public int duration;
    public String location;
    public int numSeats;
    
    
    
    

    public Booking(String description, int duration, int numSeating)
    {
       description = description;
       duration = duration;
       numSeats = numSeating;
        
    }


    public String toString ()
    {
      String output;
      output =" Booking ID: " + bookingID + " Description: " + description + 
              " Duration: " + duration + " Location: " + location + " Seats: " 
                + numSeats + ".\n";
      return output;                                
 
       
    }
}
