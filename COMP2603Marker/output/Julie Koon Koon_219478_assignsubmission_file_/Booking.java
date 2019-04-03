
//816008254
import java.util.Scanner;

public class Booking {
   
    private static int bookingIDCounter=1;
    static private int bookingID=0;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    

    //Constructor
    public Booking(String description, int duration, int numSeating ){
    this.description=description;
    this.duration=duration;
    this.numSeating=numSeating;
    bookingID=bookingIDCounter;
    bookingIDCounter= bookingIDCounter +1;
    
    }
    //Mutators
         
    public void setDescription (int description){
        this.duration=duration;
    }
    
    public void setLocation (String location){
        this.location=location;
    }
    
    public void setNumSeating(int numSeating){
        this.numSeating=numSeating;
    }
    
    public void setBookingID (int bookingID){
        this.bookingID=bookingID;
    }
    //Accessors
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
    
    
    //toString Method
    public String toString(){
    return " Booking ID: " + bookingID + " Description: " + description + " Duration: " + duration + " Location: " + location;
    }
    
}
