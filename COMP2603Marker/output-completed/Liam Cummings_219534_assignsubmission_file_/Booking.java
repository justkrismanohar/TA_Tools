public class Booking
{
    //ID - 816003418
    private static int bookingIDCounter = 0;
    public int bookingID;
    public String description;
    public int duration;
    public String location;
    public int numSeating;
    
    public Booking(String description, int duration, int numSeating){
        this.description= description;
        this.duration = duration;
        this.numSeating = numSeating;
        bookingIDCounter += 1;
        bookingID = bookingIDCounter;
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
    
    //fix
    public String toString(){
        String details = "ID: " + getBookingID() +
        "\nDescription: " + getDescription()
        + "\nDuration: " + getDuration() + 
        "\nLocation: " + getLocation();
        return details;
    }
   
   
}
