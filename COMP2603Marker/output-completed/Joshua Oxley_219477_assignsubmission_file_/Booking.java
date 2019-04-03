//816009424

public class Booking{
    //attributes
    private static int bookingIDCounter=1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;

    //constructor
    public Booking(String description, int duration, int numSeating){
        bookingID= bookingIDCounter;
        bookingIDCounter+=1;
        this.description= description;
        this.duration= duration;
        this.location= location;
        this.numSeating= numSeating; 
    }
    
    //mutators
    public String toString(){
        String details= toString();
        details+= "\nBooking ID: "+bookingID+ "\nDescription: " +description+ "\nDuration: " +duration+ "hours \nLocation: " +location;
        return details;
    }

    
    
    
    //accessors
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
}
