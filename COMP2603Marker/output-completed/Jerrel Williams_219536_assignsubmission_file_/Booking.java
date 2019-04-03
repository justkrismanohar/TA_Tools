/*id: 816009134*/

public class Booking
{
    // instance variables - replace the example below with your own
    private static int bookingIDCounter = 1;
    public final int bookingID;
    public String description;
    public int duration;
    public String location;
    public int numSeating;

    
    public Booking(String description, int duration, int numSeats, String location)
    {
       this.bookingID = bookingIDCounter;
       this.bookingIDCounter = bookingIDCounter + 1;
       this.description = description;
       this.duration = duration;
       this.numSeating = numSeats;
       this.location = location;
       /*this.location = location;*/
    }
  /*  
    public void setDescription(String description){
        this.description = description;
    }
    public void setDuration(int duration){
        this.duration = duration;
    }
    public void setSeating(int numSeating){
        this.numSeating = numSeating;
    }
    public void setLocation(String location){
        this.location = location;
    }*/
    public String toString(){
        return("Description: " + this.description + "Duration: " + this.duration + " hours" + "Seats: " + numSeating);
    }
    
   
}
