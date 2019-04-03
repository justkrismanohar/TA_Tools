//816006483
public class Booking{
    private static int bookingIDCounter = 0;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    
    public Booking(String description, int duration, int numSeating){
       this.description = description;
       this.duration = duration;
       this.numSeating = numSeating;
       bookingIDCounter = bookingIDCounter + 1;
       bookingID = bookingIDCounter;
    }
    
    public String toString(){
        String representation = " ";
        representation = "ID: " + bookingID + " Description: " + description + " Duration: " + duration + " Location: " + location + "\n";
        return representation;
    }
    
    public void setLocation(String loc){
        this.location = loc;
    }
    
    public String getDescription(){
        return description;
    }
    
    public int getDuration(){
        return duration;
    }
    
    public int getBookingID(){
        return bookingID;
    }
    
    public String getLocation(){
        return location;
    }
    
    public int getNumSeats(){
        return numSeating;
    }
}