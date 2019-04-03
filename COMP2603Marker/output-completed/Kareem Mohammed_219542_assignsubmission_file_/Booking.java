/*
 Author: Kareem Mohammed
 ID: 816007247
 */
public class Booking{

    private static int bookingIDCounter = 1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    
    //Constructors
    
    public Booking(String description, int duration, int numSeating){
        
        this.description = description;
        this.duration = duration;
        this.numSeating = numSeating;
        bookingID = bookingIDCounter;
        bookingIDCounter++;
        
    }
    
    //Methods
    
    public void setLocation(String location){
        
        this.location = location;
    }
    
    public int getBookingID(){
        
        return this.bookingID;
    }
    
    
    public String toString(){
    
        return "Booking ID: " + bookingID + " Description: " + description + " Duration: " + duration + " Hours" + " Location: " + location;
    }
    
}
