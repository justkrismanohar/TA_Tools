public class Booking {
    private static int bookingIDCounter = 1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    //CONSTRUCTORS
    public Booking(String description, int duration, int numSeating){
        bookingID = bookingIDCounter;
        bookingIDCounter = bookingIDCounter + 1;
        this.description = description;
        this.duration = duration;
        this.numSeating = numSeating;
    }
    
    //MUTATORS 
    public void setLocation(String location){
        this.location = location;
    }
    //ACCESSORS
    public int getBookingID(){
        return bookingID;
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
    
    public int getNumSeating(){
        return numSeating;
    }
    
    //METHODS 
    public String toString(){
        String s;
        s = "ID: "+ bookingID + "Description: " + description + "Duration: " + duration + "Location: " + location;
        return s;
    }
}
