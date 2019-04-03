//Hemati Sahadeo 
//816001653
//Assignment 1
//OOP

public class Booking{
    private int bookingIDCounter;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    public Booking(String description,int duration, int numSeating){
        this.duration=duration;
        this.description = description;
        this.numSeating  =numSeating;
    }
    
    //Returns a String representation of theBooking (ID, description, duration,location)
    public String toString(){
        String b= "Booking Id" + bookingID + "Description" + description + "Duration" + duration + "Location" + location;
        return b;
    }
    
    //Accessors
    public int getBookingID(){
        return bookingID;
    }
    
    public int getDuration(){
        return duration;
    }
    
    public String getLocation(){
        return location;
    }
    
    public String getDescription(){
        return description;
    }
    
    public int getNumSeats(){
        return numSeating;
    }
    
    

}