//816010691

public class Booking{
    private static int bookingIDCounter = 1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    private void setBookingID(){
        bookingID = bookingIDCounter++;
    }
    
    private void setDescription(String description){
        this.description = description;
    }
    
    private void setDuration(int duration){
        this.duration = duration;
    }
    
    public void setLocation(String location){
        this.location = location;
    }
    
    private void setNumSeating(int numSeating){
        this.numSeating = numSeating;
    }
    
    public int getBookingID(){
        return bookingID;
    }
    
    private String getDescription(){
        return description;
    }
    
    private int getDuration(){
        return duration;
    }
    
    private String getLocation(){
        return location;
    }
    
    public Booking(String description, int duration, int numSeating){
        setDescription(description);
        setDuration(duration);
        setNumSeating(numSeating);
        setBookingID();
    }
    
    public String toString(){
        return "BOOKING ID: " + getBookingID() + " TYPE: " + getDescription() + ' ' + getDuration() + " HOUR" + ((getDuration() == 1) ? ' ' : "S ") + "LOCATION: " + getLocation();
    }
}