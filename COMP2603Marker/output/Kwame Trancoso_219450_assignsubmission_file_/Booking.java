//Kwame Trancoso 816005595
public class Booking 
{
   private int bookingIDCounter;
   private int bookingID;
   private String description;
   private String location;
   private int numSeating;
   private int duration;
   
   public Booking(String description, int duration, int seats){
       setDescription(description);
       setDuration(duration);
       setSeatingNum(numSeating);
       bookingIDCounter+=1;
       bookingID=bookingIDCounter;   
    }
     
   public void setSeatingNum(int seats){
        numSeating=seats;
    }
    
   public void setDuration(int duration){
        this.duration=duration;
    }
    
   public void setDescription(String description){
        this.description=description;
    }
    
   public void setLocation(String classLocation){
        location=classLocation;
    }
    
   public int getID(){
        return bookingID;
    }
    
   public int getSeatingNum(){
        return numSeating;
    }
    
   public int getDuration(){
        return duration;
    }
    
   public String getDescription(){
        return description;
    }
    
   public String toString(){
       String Details;
       Details =" ID: " + bookingID + " Description: "+description + " Num Seating: "+ numSeating + " Location " +location;
       return Details;
    }
}