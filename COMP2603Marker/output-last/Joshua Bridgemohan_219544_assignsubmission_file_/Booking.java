import java.util.Scanner;

public class Booking{
    private static int bookingIDCounter = 0;
    public int bookingID=0;
    public String description;
    public int duration;
    public String location;
    public int numSeating;
    
    //constructor
    public Booking(String description, int duration, int numSeating){
        bookingID=bookingIDCounter++;
        description=description;
        duration=duration;
        numSeating=numSeating;
    }
    //accessors
    public int GetID(){
        return bookingID;
    }
    public String GetDescription(){
        return description;
    }
    public int GetDuration(){
        return duration;
    }
    public String GetLocation(){
        return location;
    }
    public int GetSeating(){
        return numSeating;
    }
    //accessor
    public String toString(){
        String BookingAsString=
            "\nBookingID:" + GetID() +
            "\nDescription: " +GetDescription()+
            "\nDuration: " + GetDuration()+
            "\nLocation: " + GetLocation() +
            "\nSeating :" + GetSeating();
        return BookingAsString;
    }
    
    
}