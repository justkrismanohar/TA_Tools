//816009481
public class Booking{

private static int bookingIDCounter =1;
private int bookingID;
private String description;
private int duration;
private String location;
private int  numSeating;

public Booking(String description,int duration,int numSeating){
    this.description = description;
    this.duration = duration;
    this.numSeating = numSeating;

}
//mutators
public void setBookingIDCounter(int BookingIDCounter){
    this.bookingIDCounter = bookingIDCounter + 1;
}
public void setBookingID(int BookingID){
    this.bookingID = bookingIDCounter;
}
public void setDescription(String description){
    this.description = description;
}
public void setDuration(int duration){
    this.duration = duration;
}
public void setLocation(String location){
    this.location = location;
}
public void setNumSeating(int numSeating){
    this.numSeating  = numSeating;
}
//accessors
public int getBookingIDCounter(){
    return bookingIDCounter;
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
public String getDetails(){
    String details;
    details = "ID: " + bookingID + " Description: " + description + " Duration " + duration + " Location: " + location;
    return details;
}
public String toString(){
    String s;
    s= "ID: " + bookingID + " Description: " + description + " Duration " + duration + " Location: " + location;
    return s;
    
} 

}