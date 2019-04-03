/*
StudentID: 816117607
StudenName: Joshua Peter:
Assignment: 1
*/

public class Booking
{
    private static int bookingIDCounter=0;
    private int bookingID;  
    private String description;
    private int duration;
    private int numSeating; 
    private String location;  
    
    public Booking(String description, int duration, int numSeating)
    {
        this.description =description;
        this.duration = duration;
        this.numSeating = numSeating;
        this.location=null;
        this.bookingID = generateBookingID();
        
    }
    
    public void setLocation(String location){
        this.location = location;
    }
    
    public void setBookingID(){
        generateBookingID();
        this.bookingID = bookingIDCounter;
    }
    
    public int getBookingID(){
        return this.bookingID;
    }
    
    
    private  int generateBookingID(){
        bookingIDCounter += 1;
        return bookingIDCounter; 
    }
    
    public String toString()
    {
        return "Booking ID: "+ bookingID + " description: " + description +" duration: " + duration + " hour location: " + location;
    }
    

    
}
