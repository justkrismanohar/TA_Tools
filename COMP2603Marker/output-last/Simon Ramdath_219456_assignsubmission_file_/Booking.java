//816009535 Simon Ramdath



public class Booking{
    private static int bookingIDCounter=1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numseating;
    
    public Booking(String description, int duration, int numSeating){//constructor
        this.description=description;
        this.duration=duration;
        this.numseating=numSeating;
        this.bookingID=bookingIDCounter;
        bookingIDCounter++; //increments on each booking instance
        this.location=null; //set to null for now
    }

    public String toString(){ 
        if (duration!=1){//just to say "hour" instead of "hours" when there is one hour
            return "\nBookingID :" + bookingID + " \nDescription:" + description +" \nDuration:" + Integer.toString(duration) + "hours " + "\nseats: "+ Integer.toString(numseating) +"\n";
        }
        return "\nBookingID :" + bookingID +" \nDescription:" + description +" \nDuration:" + Integer.toString(duration) + "hour " + "\nseats: "+ Integer.toString(numseating)+"\n";
    }
    
    public void setlocation(String room){ 
        location=room;
    }
    public int getID(){
        return bookingID;
    }
}