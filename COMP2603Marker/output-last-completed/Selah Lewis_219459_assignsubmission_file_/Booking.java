//816012230
public class Booking{
    private static int bookingIDCounter = 1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    public Booking(String description, int duration, int numSeating){
        bookingID = bookingIDCounter;
        bookingIDCounter = bookingIDCounter + 1;
        this.description = description;
        this.duration = duration;
        this.numSeating = numSeating;
    }
    public int getID(){
        return bookingID;
    }
    public String toString(){
        return "Booking ID: " + bookingID + " Description: " + description + " Duration: " + duration + " Location: " + location;
    }
    
}
