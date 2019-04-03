

//Name:Jehan Hunte
//ID#:816003696
//COMP 2603 Assignment 1

public class Booking
{
   public static int bookingIDCounter = 1;//A class variable for generating unique identifiers for a Booking starting from 1 and incrementing by 1
   public int bookingID;// A unique identifier for a Booking eg 1
   private String description;
   private int duration;
   public String location;
   private int numSeating;
   
    public Booking(String _description, int _duration, int _numSeating)
    {   // various MUTATORS 
        this.description = _description;
        this.duration = _duration;
        this.numSeating = _numSeating; 
        this.bookingID = bookingIDCounter;
        //this.bookingIDCounter++;
        //this.bookingID+=1;
    }

    public String toString(){
       
       String bookingDetails = " ";
       
       
       if (duration == 1){
           bookingDetails += "\nBOOKING ID: "+ bookingID +" TYPE: "+ description + " "+ duration +" hour " + " Seats: "+numSeating + " LOCATION: "+ location;
        }
       else if (duration > 1){
           bookingDetails += "\nBOOKING ID: "+ bookingID +" TYPE: "+ description + " " + duration +" hours " + " Seats: "+numSeating + " LOCATION: " + location;
        }
       return bookingDetails;
        }
       
      
    
    //ACCESSORS
    public int getBookingID(){
        return bookingID;
    }

    public int getBookingIDCounter(){
        return bookingIDCounter;
    }
    
    public String getDescription(){
        return description;
    }
    
    public int getDuration(){
        return duration;
    }
    
    public int getnumSeating(){
        return numSeating;
    }
    
}



