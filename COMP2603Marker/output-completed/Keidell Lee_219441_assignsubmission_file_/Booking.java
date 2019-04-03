// 816009809

public class Booking{
    private static int bookingIDCounter = 1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
        
    public Booking(String description, int duration, int numSeating){
        bookingID = bookingIDCounter;
        bookingIDCounter++;
        this.description = description; 
        this.duration = duration; 
        location = null;
        this.numSeating = numSeating; 
    }
    
    public String getLocation(){
         return location;
    }
    
    public int getBookingID(){
        return bookingID;
    }
    
    public int getDuration(){
        return duration;
    }
        
    public void setLocation(String loc){
         location = loc;
    }     
    
    public String toString(){
        String details =" ";
        details += location + " "+ "Booking ID: "+ bookingID + " "+" Description: "+description+ " "+" Duration "+ duration;
        return details;
    }
    
}
