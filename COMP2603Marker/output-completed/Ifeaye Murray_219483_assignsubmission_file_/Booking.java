//816007834
public class Booking {
    private static int bookingIDCounter=1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    public Booking(String description, int duration, int numSeating) {
        this.description=description;
        this.duration=duration;
        this.numSeating=numSeating;
        bookingID=bookingIDCounter;
        bookingIDCounter++;
    }
    
    public int getBookingID() {
        return bookingID;
    }
    
    public void setLocation(String roomID) {
        this.location=roomID;
    }
    
    public String toString() {
        return "Booking ID: " + bookingID + " Description: " + description + " Duration: " + duration + " Location: " + location;
    }
}