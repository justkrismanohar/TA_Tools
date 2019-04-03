/*
 * Student ID: 816004003
 * Name: Keanu Nichols
*/
public class Booking{
    //Attributes
    private static int bookingIDCounter = 1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    //Constructor 
    public Booking(String description, int duration, int numSeating){
        this.bookingID = bookingIDCounter;
        this.bookingIDCounter += 1;
        this.description = description;
        this.duration = duration;
        this.numSeating = numSeating;
    }
       
    //Accessors
    public int getBookingId(){
        return bookingID;
    }
    
    public int getBoookingIdCounter(){
        return bookingIDCounter;
    }
    
    public String getDescription(){
        return description;
    }
    
    public int getDuration(){
        return duration;
    }
    
    public String getLocation(){
        return location;
    }  
    
    public void setLocation(String location){
        this.location = location;
    }
        
    //Method
    public String toString(){
        return ("BOOKING ID: " + bookingID + " " +
                "TYPE: " + getDescription() + " " +
                getDuration() + " HOURS" + " " + 
                "LOCATION: " + getLocation() + "\n");
    }
    
}