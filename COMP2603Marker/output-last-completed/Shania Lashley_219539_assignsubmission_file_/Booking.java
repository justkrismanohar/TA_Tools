 // ID:816009920
 public class Booking{
   
    private int bookingIDCounter = 1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    // constructor
    public Booking(String description, int duration, int numSeating ){
        bookingID = bookingIDCounter;
        bookingIDCounter = bookingIDCounter + 1;
        this.description = description;
        this.duration = duration;
        this.numSeating = numSeating;  
    }
    
    // accessors
    public int getBookingIDCounter(){
        return bookingIDCounter;
    }
    
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
    
    //mutators
    public void setDescription(String description){
        this.description = description;
    }
    
    public void setDuration(int duration){
        this.duration = duration;
    }
    
    public void setLocation(String location){
        this.location = location;
    }
    
    public void setNumSeating(int numSeating){
        this.numSeating = numSeating;
    }
    
    public void setBookingID(){
        bookingID = bookingIDCounter;
    }
    
    public String toString(){
          return "ID: "+ bookingID + "Description: "+ description +"\t Duration: " + duration + " \t Location: " + location;
    }
    
    
    
    
}

