/**
 * @author (Hudson Adams 816001214 )
 */
public class Booking
{
   private static int bookingIDCounter = 0; 
   private int bookingID; 
   private String description; 
   private int duration;
   private String location; 
   private int numSeating;  
   
  public Booking (String description, int duration, int numSeating) { 
       
       bookingIDCounter++; 
       bookingID = bookingIDCounter; 
       this.description = description; 
       this.duration = duration;  
       this.numSeating = numSeating; 
       
  }
   
  public String toString(int bookingID, String description, int duration, String Location) {
      
       String bookingDetails = "\nBOOKINGID: " + bookingID + " || TYPE: " + description + " || " + " Duration of " + duration + " HOUR(S) " + " || " + "LOCATION: " + location + "\n "; 
       return bookingDetails ; // Location is not the returned value double check 
   }
   
  public int getDuration () {
       return duration; 
  }
    
  public String getLocation () {
       return location; 
  }
   
  public void setLocation (String location) {
       this.location = location; 
  }
  
  public int getBookingID () {
      return bookingID; 
  }
  
  public String getBookingDescription() {
    return description; 
  }
  
  public String getBookingLocation() {
      return location; 
  }
  
  public int getBookingDuration() {
      return duration; 
  }
  
  public int getBookingIDCounter() {
      return bookingIDCounter; 
  }
}
