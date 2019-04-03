/**
 *
 * @author (Hudson Adams 816001214)
 * @version (Room Class)
 */
public class Room {
   private String roomID; 
   private int seatingCapacity;
   private static final int numSlots = 8;  
   private static int roomIdCounter = 100; 
   private int bookingsIndex; // This was used as the array index when intializing to ensure the array is properly formatted with no null fields in between
   private Booking[] bookings; 
   private int bookedSlots; // this was used to keep tracked of the number of bookedSlots for each room. 

   public Room(String name, int seatingCapacity) {
        bookedSlots = 0;  
        bookings = new Booking[numSlots];
        roomID = name+roomIdCounter; 
        roomIdCounter = roomIdCounter + 100; 
        this.seatingCapacity = seatingCapacity; 
   }; 
    
   public String addBooking(String description, int duration, int seats) {
      String status= "There are currently no rooms with available slots to book. \n" + "Please check back at another time";
      int amount; 
        
      if (canFitTime(duration) && canFitNumbers(seats)) { // Checks if room can accomadate the time & number of seats requested.
       
           bookings[bookingsIndex] = new Booking (description, duration, seats); 
           Booking place = bookings[bookingsIndex]; 
           amount = place.getDuration();
           place.setLocation(getRoomID()); 
           String roomLoc = place.getLocation(); 
           bookedSlots = bookedSlots + duration;   
           bookingsIndex++;
           System.out.println("Booking added to schedule. Details below: \n"); 
           status = place.toString(place.getBookingID(), place.getBookingDescription(), place.getDuration(), place.getLocation()); 
           return status;
      }
      return status;  
   }
    
   public boolean canFitNumbers (int numSeats ) { 
 
       if (numSeats <= getSeatingCapacity()) 
            return true; 
            
       return false; 
   }
    
   public boolean canFitTime(int duration) { 
            
        if ((getNumOfBookedSlots() + duration) <= 8) 
              return true; 
                
        return false;
   }
    
   public String getBookingDetails(int bookingID) {
    String response="The bookingID was not found."; 
    int count = 0;   
     
    if (hasBooking(bookingID)) { // It was checked before doing the getBookingDetails call but i double checked 
        for (count = 0; count < bookings.length; count++) {
                
            if (bookings[count] == null)  
                 return response;  
                
            int foundID = bookings[count].getBookingID();
            if (foundID == bookingID) {
                String foundDescription = bookings[count].getBookingDescription(); 
                String foundLocation = bookings[count].getBookingLocation(); 
                int foundDuration = bookings[count].getBookingDuration(); 
                response =(bookings[count].toString(foundID,foundDescription,foundDuration,foundLocation)); 
                return response; 
            }
      }
    }
      return response; 
   }
    
   public String getBookingList() {
        
        String bookingList = "No booking list was found "; 
        int count = 0;
        
        if (bookings[count] == null) 
            return bookingList; 
         
        bookingList = ""; // If it reaches here then bookings exist so clear the string to allow concatenate
        if (bookings[count].getBookingLocation().equals(getRoomID())) {
            for (count = 0; count < bookings.length; count++) {
        
                 if (bookings[count] == null) 
                        break; 
                   
                 int foundID =bookings[count].getBookingID();
                 String foundDescription = bookings[count].getBookingDescription(); 
                 String foundLocation = bookings[count].getBookingLocation(); 
                 int foundDuration = bookings[count].getBookingDuration();
                 
      
                 bookingList +=(bookings[count].toString(foundID,foundDescription,foundDuration,foundLocation));
               
            }
        }       
        return bookingList; 
   }
    
   public String getDetailedBookingGrid() {    
      String bookingGrid = "" ; 
      int gridCount = 0; 
      int foundID = 0; 
      int foundBookings = 0;
      int remainder = 8; 
      int countSpaces = 0; 
       
      Booking display = bookings[gridCount]; 
      bookingGrid = getRoomID(); 
      
      while (gridCount < 8) {
        
       display = bookings[gridCount]; 
             
       if (display == null) // If the array is empty then exit loop and booking grid remains unchanged 
            break;  
       // If the program reaches here it means there's a booking search for the location and compare with the current roomID 
       if(getRoomID().equals(display.getBookingLocation())) {// If compared it means this room has a booking 
          foundID = display.getBookingID(); ////Returns the booking ID needed for printing 
          foundBookings = display.getDuration(); // Gets the duration to know the number of times the number must be repeated 
          countSpaces = countSpaces + foundBookings ;
          if (foundID >= 10) { // Conditional statement for double digits when printing the grid
            for (int i = 1;  i<= foundBookings ; i++) {//Stars formating the string with the location first
              bookingGrid = bookingGrid + " | " + foundID; // Starts adding the number of times the number must be repeated        
            }     
          }
          else { // conditon for single digits when printing the grid
                for (int i = 1;  i<= foundBookings ; i++) {//Stars formating the string with the location first
                        bookingGrid = bookingGrid + " | " + foundID  + " "; // Starts adding the number of times the number must be repeated       
                }
          }
       }
       gridCount = gridCount+ 1; 
      }
 
      if ((remainder - countSpaces) > 0 && countSpaces > 0) { 
          remainder = remainder - countSpaces; 
          for (int i =0; i<remainder; i++) {
                 bookingGrid = bookingGrid + " | " + " " + " "; 
          }
          return bookingGrid; // no need to go below because the string was formatted 
      }
      return bookingGrid;
   }
    
   public String getRoomID() {
        return roomID; 
   }
    
   public int getSeatingCapacity() {
       return seatingCapacity; 
   }
    
   public int getNumOfBookedSlots () { 
       return bookedSlots; 
   }
   
   public boolean hasBooking (int bookingID) {
      for (int i = 0; i < bookings.length ;  i++) 
      {
            if (bookings[i] == null){
                return false; 
            } 
            
            if (bookings[i].getBookingID() == bookingID) {
                return true; 
            }
      }
      return false;
   }
    
   public String toString() {
       
       return "\nROOM ID: " + roomID + " Seats: " + seatingCapacity; 
   }
   
   private int getBookingID (String location) { // To reduce the complexitiy of some methods this was created to aid my understanding of how to achieve the full functionality of this assignment.
       int bookingID = 0; 
       Booking search; 
       for (int i = 0; i<getNumOfBookedSlots(); i++) {
            search = bookings[i];  
            if (search == null)  // ensures it's not pointed to nothing 
                return bookingID; 
            
            if (search.getBookingLocation().equals(location) ) { // If there is a booking location that matches the roomID 
                bookingID = search.getBookingID(); // If enterred then there exists a booking so request the bookingID.
                return bookingID;
            }
       }   
       return bookingID; 
   }
   
   public int getCurrentBookingIndex () { 
       return bookingsIndex; 
   }
}
