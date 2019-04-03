//Student ID - 816009413

public class Booking{
  
    private static int bookingIDCounter=0;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;

 
    public Booking(String description, int duration, int numSeating){
       bookingIDCounter++;
       bookingID = bookingIDCounter;
       this.description = description;
       this.duration = duration;
       this.numSeating = numSeating;
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
    
     public void setLocation(String loc){
        this.location = loc;
    }
    
    public String toString(){
       String objAsString = 
            "ID: " + getBookingID() +
            "\nDescription: " + getDescription() +
            "\nDuration: " + getDuration() +
            "\nLocation: " + getLocation();
            
        return objAsString;
    }
}
