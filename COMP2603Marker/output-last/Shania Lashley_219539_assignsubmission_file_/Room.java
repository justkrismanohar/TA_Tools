// 816009920
/**
 * Write a description of class Room here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Room{
    // instance variables - replace the example below with your own
    private int numSlots;
    private final int maxSlots = 8;
    private static int roomIDCounter = 0;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private static Room[] rooms = new Room[10];
    private static Booking[] booking = new Booking[8];

    /**
     * Constructor for objects of class Room
     */
    public Room(String name, int seatingCapacity){
        // initialise instance variables
        
        roomID = roomID;
        roomIDCounter = roomIDCounter + 100;
        seatingCapacity = seatingCapacity;
               
   
    }
       
    //accessors
    public int getNumSlots(){
        return  numSlots;
    }
    

    public int getSeatingCapacity(){
        return  seatingCapacity;
    }

        
     //mutators
     public void setNumSlots(int numSlots) {
         if(numSlots > maxSlots)
              System.out.println("Cant save");
         else 
            numSlots += numSlots;
      
     }
   
    public void setRoomIDCounter(int roomIDCounter){
        this.roomIDCounter = roomIDCounter;
    }
    
     public void setRoomID(String roomID){
         this.roomID = roomID;   
     }
    
    public void setSeatingCapacity(int seatingCapacity){
        this.seatingCapacity = seatingCapacity;
    }
    
    public String getRoomID(){
        roomID = roomID + roomIDCounter;
        return roomID;
    }
    
    public String toString(){
          roomID = getRoomID();
          return " RoomID: "+ roomID +  "\t  SEATS: "+ seatingCapacity; 
    }
    
     public String addBooking(String description, int duration, int seats){
         String n="";
         
         for(int i=0; i< rooms.length; i++)
                if(rooms[i].seatingCapacity <= seats && (numSlots + duration < maxSlots) ){
                Booking b = new Booking(description, duration, seats);
                        b.setDescription(description);
                        b.setDuration(duration);
                        b.setLocation(roomID);
                        b.setNumSeating(seats);
                        numSlots += duration;
                        booking[numSlots] = b;
                 n = "Booking successfully added to schedule: \n" + b.toString();
                  }
               else 
                    n =  "";
         return n;
     }
     
     public Boolean canFitNumbers(int numSeats){
         String p = "false";
         int i = 0;
            while(rooms[i].toString() != ""){
                if(rooms[i].seatingCapacity == numSeats)
                    p = "true";
                i++;
            }   
            if(p == "true")
                return true;
            else
                return false;
     }
     
     public Boolean canFitTime(int duration){
         String p = "false";
         
            for(int i=0; i< rooms.length; i++)
                if(rooms[i].numSlots < duration || rooms[i].numSlots == duration)
                    p = "true";
                 
            if(p == "true")
                return true;
            else
                return false;
     }
     
     public String getBookingDetails(int bookingID){
         Boolean p = false;
         int n = 0;
         
         for(int i = 0; i<booking.length; i++)
                if(booking[i].getBookingID() == bookingID){
                    p = true;
                    n = i;
                }
         
            if (p == true)
                return booking[n].toString();
            else
                return "No Booking for " + bookingID + "could be found!";
     }
      
     public String getBookingList(){
         String n = "";
         if(numSlots < 0)
                for(Room i: rooms)
                    n += booking.toString();
         else        
               n = "No Booking was found!";
         
         return n;
        }
     
     public String getDetailedBookingGrid(){
            String n ="";
            
                for(int j = 0; j < numSlots; j++)
                    n += rooms + " | " + booking[j] + " | " + booking[j +1] + " | " + 
                            booking[j + 2] + " | " + booking[j + 3] + " | " + booking[j + 4] +
                            " | " + booking[j + 5] + " | " + booking[j + 6] + " | " + 
                            booking[j + 7]  + " | " + booking[j + 8];
            
            return n;
     }
     
     public Boolean hadBooking(int bookingID){
            for (int i = 0; i<booking.length; i++)
                if(booking[i].getBookingID() == bookingID)
                    return true;
                    
            return false;
     }
     
     public String BookingFromLocation(String RoomID){
         String n = "";
         
         for(int i = 0; i<booking.length; i++)
                if(booking[i].getLocation() == RoomID){
                   n += booking[i].toString();
                    
                }
                
         return n;
     }
}


    
    
    

