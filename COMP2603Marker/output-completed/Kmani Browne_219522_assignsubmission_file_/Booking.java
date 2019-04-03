//816005390
public class Booking{
    private static int bookingIDCounter = 0;
    private int bookingID;
    private String description;
    private int duration;
    private String roomID;
    private int numSeating;
    
    public Booking(String desc, int time, int seatingCapacity){
        this.description = desc;
        this.duration = time;
        this.numSeating = seatingCapacity;
        Booking.bookingIDCounter++;
        this.bookingID = Booking.bookingIDCounter;
    }   
    
    public String toString(){
        return "Booking ID: " + this.bookingID + " Description: " + this.description + " Duration: "+ this.duration + " Location: "+ this.roomID;
    }
    
    //accessors
    public int getBookingIDCounter(){
        return Booking.bookingIDCounter;
    }
    
    public int getBookingID(){
        return this.bookingID;
    }
    
    public String getDescription(){
        return this.description;
    }
        
    public int getDuration(){
        return this.duration;
    }
    
    public String getRoomID(){
        return this.roomID;
    }
    
    public int getNumSeating(){
        return this.numSeating;
    }
    
    //mutators
    
    public void setBookingID(int bookingID){
        this.bookingID = bookingID;
    }
    
    public void setDescription(String description){
        this.description = description;
    }
    
    public void setDuration(int duration){
        this.duration = duration;
    }
    
    public void setRoomID(String roomID){
        this.roomID = roomID;
    }
    
    public void setNumSeating(int numSeating){
        this.numSeating = numSeating;
    }
}