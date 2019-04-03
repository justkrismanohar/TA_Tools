//VERNESSA BOODRAM
//816006133

public class Booking {  
    //Declaring the Booking attributes 
    private static int bookingIDCounter = 1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    //Constructor
    public Booking (String description, int duration, int numSeating) {
        bookingID = bookingIDCounter; 
        this.description = description;
        this.duration = duration;
        this.numSeating = numSeating;
        bookingIDCounter++;
    }

    //To String Method 
    public String toString() {
        String s;
        s = "Booking ID: " + bookingID + " Description: " + description + " Duration:" + duration + " Location: ";
        return s;
    }    
 
    //Accessors
    public int getBookingID(){
        return bookingID;
    }
    
    public int getBookingIDCounter (){
        return bookingIDCounter;
    }

    //Mutators    

} //End of Booking class 