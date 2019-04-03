
/*
 * Student ID - 816004212
 */
public class Room
{
    // instance variables
    private final int numSlots = 8;
    private static int roomIDCounter = 100;
    private String roomID;
    private Booking [] bookings ;
    private int seatingCapacity;
    private int count;
    private int slotsRemaining;
    private int upTo;
    private int i;
    private int t;

    /*
     * Constructor for objects of class Room
     */
    public Room(String name, int seatingCapacity){
        // initialise instance variables
        roomID = name + Integer.toString(roomIDCounter);
        this.seatingCapacity = seatingCapacity;
        bookings = new Booking [numSlots] ;
        roomIDCounter+= 100;
        
    }
    
    public String addBooking(String description, int duration, int seats){

        count= 0;
        slotsRemaining = 0;
        
        if (canFitNumbers(seats) && canFitTime(duration)){
            Booking tempBooking = new Booking(description, duration, seats);
            
            for (i=0; i<bookings.length;i++){
              if(bookings[i] != null)
                 count++;    
            }
            
            if (count == 0){
                for(t=0;t<duration;t++)
                  bookings[t] = tempBooking;
            }
            else{
                slotsRemaining = numSlots - count;
                if((slotsRemaining + count) <= numSlots) { 
                    upTo = count + duration;
                    for(t=count;t<upTo;t++)
                       bookings[t] = tempBooking;
               }
            }
        
         
         return tempBooking.toString() +  " LOCATION: " + roomID;
        }
        else
            return null;
    }
 
    public boolean canFitNumbers(int numSeats){
        if (numSeats <= seatingCapacity)
            return true;
        return false;
    
    }
    
    public boolean canFitTime(int duration){
        int i, timeRemaining;
        int count = 0;
        for(i=0;i<numSlots;i++){
            if(bookings[i] != null){
                count++;
            }
        }
        timeRemaining = numSlots - count;
        
        if(duration <= timeRemaining)
            return true;
        return false;   
    }
   
    public String getBookingDetails(int bookingID){
            
       for (i=0;i<numSlots;i++){
         if (hasBooking(bookingID))
             return (bookings[i].toString() + " LOCATION: " + roomID + "\n");
       }
       return null;
    }

    public String getBookingList(){
        String details="";
        if (bookings[0] == null)
            return ("No bookings have made");
        else{
            for (i=0;i<numSlots;i++){
                if (bookings[i] == null)
                    break;
            
                details += bookings[i].toString() + " LOCATION: " + roomID + "\n";
            }
        }
      
        return(details);
    }
    
    public String getDetailedBookingGrid(){
        String room = roomID + "|   ";
        String grid = "";
        for (i=0;i<bookings.length;i++){
                if(bookings[i] == null)
                    grid += " " + "  | ";
                else
                    grid +=Integer.toString(bookings[i].getBookingID()) + "  | ";
         
        }
        
        room += grid;
        return room;
    }

    public String getRoomID(){
       return roomID;
    }
    
    public boolean hasBooking(int bookingID){
        int id;
        for (i=0;i<numSlots;i++){
           
           if(bookings[i] != null){
               id = bookings[i].getBookingID();
               if(id == bookingID)
                  return true;  
           }
        }
        return false;
    }
    
    public String toString(){
        String details;
        details = "ROOM ID: " + roomID + "  SEATS: " + seatingCapacity;
        return details;
    }
    
}
