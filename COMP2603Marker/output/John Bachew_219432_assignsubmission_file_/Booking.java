//ID#810003511

public class Booking
{
    // instance variables - replace the example below with your own
    private int bookingIDCounter;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;

    
    public Booking(String description, int duration, int numSeating)
    {
        // initialise instance variables
        this.description = description;
        this.duration = duration;
        duration = 0;
        this.numSeating = numSeating;
        bookingIDCounter = 1;
        bookingID = 1;
        location = "";
       
    }
    //Accesors
    public int getBookingID(){
        return bookingID;
    }
    public int getBookingIDCounter(){
        return bookingIDCounter;
    }
    public int getDuration(){
        return duration;
    }
    public int getNumSeating(){
        return numSeating;
    }
    public String getLocation(){
        return location;
    }
    
    public String toString(){
        String details = "BOOKING ID " +bookingID+" TYPE: "+ description + " " + duration  +" HOURS" + " LOCATION: " +location; 
        return details;
    }
    //Mutators
    public int setBookingID(int num){
        
        bookingID=bookingID+num;
         return getBookingID();
   
    }
    void setBookingIDCounter(){
        bookingIDCounter++;
    }
    void setDuration(int enterDuration){
        duration = enterDuration;
    }
    void setDescription(String enterDescription){
        description = enterDescription;
    }
    void setNumSeating(int enterNumSeating){
        numSeating = enterNumSeating;
    }
    void setLocation(String enterLocation){
        location = enterLocation;
    }
  }
