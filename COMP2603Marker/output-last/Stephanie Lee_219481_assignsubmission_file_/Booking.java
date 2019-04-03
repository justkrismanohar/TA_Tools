/*
 * 816007792
 * Stephanie Lee
 * Assignment 1
 */

public class Booking{
    private static int bookingIDCounter = 1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
     //constructor 
    public Booking (String description, int duration, int numSeating){
         this.description = description;
         this.duration = duration;
         this.numSeating = numSeating;
         this.bookingID = bookingIDCounter;
         bookingIDCounter = bookingIDCounter + 1;
         location = null;
         
    }
     //accessor methods:
    
    public int getBookingID(){
        return bookingID;
    }
    
    public int getDuration(){
        return duration;
    }
    
    public String getLocation(){
        return location;
    }
    
    public void setLocation(String Location){
        this.location = Location;
    }
    /*
    public static void generateBookingID(){
        bookingIDCounter += 1;
        //bookingID = bookingIDCounter;
    }
    
    public void setBookingID(){
        bookingID = bookingIDCounter;
    }
    */
    //methods:
    public String toString(){
        return "Booking ID: " + bookingID +" Description: " + description + " Duration " + duration + " Location " + location;
    }
}