
//Name: Zane Mohammed
//ID:816009832
//COMP 2603 Asssignment 1
public class Booking{
    private static int bookingIDCounter=1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    public Booking(String bookingDescription,int bookingDuration, int bookingSeating){
        setBookingID();
        description=bookingDescription;
        duration=bookingDuration;
        numSeating=bookingSeating;
        location=null;
    }

    public String toString(){
        String details=("Booking ID: "+bookingID+"\tType: "+description+"\tDuration: ");
        if(duration>1)
            details+=(duration+" hours \t"+"Seats: "+numSeating);
        else details+=(duration+" hour  \t"+"Seats: "+numSeating);
        details+="\tLocation: "+location;
        return details;
    }
    
    public void setBookingID(){
        bookingID=bookingIDCounter;
        bookingIDCounter+=1;
        return;
    }  
    
    public void setLocation(String bookingLocation){
        location=bookingLocation;
        return;
    }
    
    public void setBookingDescription(String bookingDescription){
        description=bookingDescription;
        return;
    }
    
    public void setDuration(int bookingDuration){
        duration=bookingDuration;
        return;
    }
    
    public void setBookingSeating(int seats){
        numSeating=seats;
        return;
    }
    
    public String getDescription(){
        return description;
    }
    
    public String getLocation(){
        return location;
    }
    
    public int getSeats(){
        return numSeating;
    }
    
    public int getDuration(){
        return duration;
    }
    
    public int getBookingID(){
        return bookingID;
    }
}