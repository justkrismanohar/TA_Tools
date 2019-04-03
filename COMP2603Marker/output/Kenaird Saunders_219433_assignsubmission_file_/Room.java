//816008473 Kenaird Saunders
public class Room
{
  private int numSlots;
  private static int roomIDCounter = 100;
  private String roomID;
  private Booking[] bookings;
  private int seatingCapacity;


  public Room(String name, int seatingCapacity){
      bookings = new Booking[8];//allocate memory for 8(max amt) booking slots (this code actually creates the arrow in the UML Diagram)
      roomID = name + roomIDCounter;// e.g. "FST"(from the parameter) + 100 => FST100
      roomIDCounter+=100;// increment for next roomID to be created
      numSlots = 0; // initially zero
      this.seatingCapacity = seatingCapacity;// set seatingCapacity
  }
  
  public String addBooking(String description, int duration, int seats){
        if(canFitNumbers(seats) == false || canFitTime(duration) == false){
            System.out.print("Cannot add booking due to lack of seating or length of time.");
            return null;
        }else{
            Booking book = new Booking(description, duration, seats);
            book.setLoc(roomID);
            for(int i=0; i<duration; i++){
                bookings[numSlots] = book;
                numSlots++;
            }
            return "Booking added to schedule: " + book.toString();
        }
    }
    
  public boolean canFitNumbers(int numSeats){
      if (seatingCapacity >= numSeats){
      return true;
    }else{
       System.out.print("The number of seats exceed that of the Capacity of the room.");
       return false;
    }
  }
    
  public boolean canFitTime(int duration){
       if (numSlots + duration >8){
           System.out.print("Unable to support the amount of time necessary.");
           return false;
        }else{
           return true;
       }
  }
  
  public String getBookingDetails(int bookingID){
       for(int i=0; i<numSlots; i++)     
           if(bookings[i].getBookingID()== bookingID)
                return bookings[i].toString();
       return "A booking with this ID '"+ bookingID + "' cannot be found.";
    }

    
  public String getBookingList(){
      String details = "";
      if(numSlots == 0){
      return "No rooms have been booked yet.";
    }else{
      for(int i=0; i<numSlots; i++)   
           details = details + bookings[i].toString();
        }
        return details;
   }
    
   public String getDetailedBookingGrid(){
        String result = " ";
       int in = 0;
       for (int i=0; i <8; i++){ // check all slots in the room
           result+= " ";
           if(i < numSlots){// once we are in a filled booking spot
            in = bookings[i].getBookingID();
            result+= in;// get the booking ID and append to string
           }else
            result+= " ";//put a space fill for unallocated booking spot
       }
       return result;
    }
    
  public String getRoomID(){
       return roomID;
     }
    
  public boolean hasBooking(int bookingID){
       for(int i=0; i<numSlots; i++)     
           if(bookings[i].getBookingID()== bookingID)
                return true;
       return false;
   }
    
  public String toString(){
      return "RoomID: " + roomID + "Seats: " + seatingCapacity + "\n";
   }
}
