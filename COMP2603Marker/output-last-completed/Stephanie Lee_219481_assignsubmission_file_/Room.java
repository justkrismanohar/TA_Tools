/*
 * 816007792
 * Stephanie Lee
 * Assignment 1
 */
public class Room{
    private static final int numSlots = 8;
    private static int roomIDCounter = 100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private String name;
    private int availableSlots;
    private int currentSlot;

    
    //constructor
    
    public Room(String name, int seatingCapacity){
      this.name = name;
      this.seatingCapacity = seatingCapacity;
      setRoomID(name,roomIDCounter);
      roomIDCounter = roomIDCounter + 100;
      bookings = new Booking[8];
      this.availableSlots = numSlots;
        
    }
    
    //methods
    
    public String addBooking(String description, int duration, int seats){
        if(this.canFitNumbers(seats) && this.canFitTime(duration)){
           
            this.bookings[currentSlot] = new Booking(description, duration, seats);
            this.bookings[currentSlot].setLocation(roomID);
            currentSlot = currentSlot + 1;
            return "Booking added to schedule: " + bookings[currentSlot-1].toString();
        }
        return "Unable to add booking";
    }
    
    public String getRoomID(){
        return roomID;
    }
    
    public void setRoomID(String name, int numberID){
         roomID = name+ numberID;
    }
    
    
    public boolean canFitNumbers(int numSeats){
        if(numSeats <= this.seatingCapacity){
            return true;
        }
        else 
            return false;
    }
    
    public boolean canFitTime(int duration){
        
        if(duration <= availableSlots){
            currentSlot = numSlots - availableSlots;
            this.availableSlots = this.availableSlots - duration;
            return true;
        }
        return false;
    }
    
    public String getBookingDetails(int bookingID){
        String details="";
        for(int i = 0; i < numSlots; i++) {
            if(bookings[i] ==null){
               break;
            }
            
            if(bookings[i].getBookingID() == bookingID){
                details+= bookings[i].toString();
            }
        } 
        return details;
    }
    
   
     public String getBookingList(){
         String s = "";
       
        for(int i = 0; i < numSlots; i++){
            
            if(bookings[i].getLocation().equals(getRoomID())){
                
                for(int l = 0; l < bookings[i].getDuration(); l++){
                    s += "TESTING HERE " + bookings[i].toString() + "\n";
                }
            }
            return s;
            }
        return "No bookings have been made";
       
      
    }
    
    public String printSlotLines(int bookedID, int duration){
        String p = "";
        if(bookedID == -1){
            for(int i = 0; i < duration; i++)
                p = p + "|  ";
                return p;
            }
        for(int i = 0; i < duration; i++)
            p = p + "|   " + bookedID;
           
            return p;
    }
    
    
    public String getDetailedBookingGrid(){
        String p="";
        int counting = 0;
        for(int i = 0; i < currentSlot; i++){
            counting += bookings[i].getDuration(); 
            p+= printSlotLines(bookings[i].getBookingID(),bookings[i].getDuration());
        }
        int remainder = numSlots - counting;
        p+= printSlotLines(-99,remainder);       
        
        return p;
    }
    
    public boolean hasBooking(int bookingID){
        int i =0;
        while(bookings[i] != null){
            
            if(this.bookings[i].getBookingID() == bookingID)
                return true;
            i++;
        } 
        return false;
    }
    
    public String toString(){
        return "Room ID: " + roomID + 
        " \nSeating Capacity: " + seatingCapacity;
    }
}
