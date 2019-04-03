//816005390
public class Room{
    private int numSlots;
    private static int roomIDCounter =100;
    public String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private int maxTimeSlots;
    
    public Room(String name, int seatingCapacity){
        this.roomID = name + roomIDCounter;
        this.seatingCapacity = seatingCapacity;
        this.numSlots = 0;
        this.maxTimeSlots = 8;
        Room.roomIDCounter += 100;
        this.bookings = new Booking[this.maxTimeSlots];
    }
        
    public String addBooking(String description, int duration, int seats){
       if(this.numSlots < this.maxTimeSlots){
          Booking newBooking = new Booking(description, duration, seats);
          newBooking.setRoomID(this.getRoomID());
          int i;
          for(i=this.numSlots; i < (duration + this.numSlots); i++) {
              this.bookings[i] = newBooking;
          }
          this.numSlots += duration;
          String str = "Booking successfully added to schedule.\n";
          str += "BOOKING ID: " + newBooking.getBookingID() + ". TYPE: " + newBooking.getDescription() + ". " + newBooking.getDuration() + " HOURS. " + "LOCATION: " + this.getRoomID() + "\n";
          return str;
       }
       else{
            return "Error! Booking cannot be added to schedule..\n";
       }       
    }
        
    public boolean canFitNumbers(int numSeats){
       return numSeats <= this.getSeatingCapacity();
    }
        
    public boolean canFitTime(int duration){
       return duration <= (this.maxTimeSlots - this.numSlots);
    }
        
    public String getBookingDetails(int bookingID){
       int i;
       for(i=0; i < this.maxTimeSlots; i++) {
          if(this.bookings[i] != null && this.bookings[i].getBookingID() == bookingID)
             return this.bookings[i].toString();
       }
       return "The room with Booking ID " + bookingID + " was not found.";
    }
        
    public String getBookingList(){        
       if(getNumSlots() == 0)
           return "No bookings have been made..\n";
       else{
            String list = "Bookings made in room " + roomID + " are: \n\n";
            int i;
            for(i = 0; i < this.maxTimeSlots; i++) {
                if(this.bookings[i] != null) {
                    list += this.bookings[i].toString() + "\n";
                }
            }
            return list;
       }
            
    }
        
    public String getDetailedBookingGrid(){
        String grid="";
        for (int i=0; i < this.maxTimeSlots;i++){
            if(this.bookings[i]!=null && this.bookings[i].getRoomID().equals(this.roomID)){
               grid += " | " + this.bookings[i].getBookingID()+" | ";
            }
            else
               grid += " | "+" "+" | ";
        }
        return grid;        
    }
        
    public String getRoomID(){
       return this.roomID;
    }
        
    public boolean hasBooking(int bookingID){
        for(int i = 0; i < this.numSlots; i++){
           if(this.bookings[i] != null) {
              if(this.bookings[i].getBookingID() == bookingID)
                  return true;
           }
        }
        return false;
    }    
        
    public String toString(){
        return "Room ID: " + this.roomID + ". Seating Capacity: " + this.seatingCapacity + "\n";
    }
        
    //accessors
    public int getNumSlots(){
       return this.numSlots;
    }
    
    public int getTimeSlots() {
        return this.maxTimeSlots;
    }
        
    public int getRoomIDCounter(){
       return Room.roomIDCounter;
    }    
        
    /*public Booking[] getBookings(){
         return bookings; 
    }*/
        
    public int getSeatingCapacity(){
        return this.seatingCapacity;
    }
        
    //mutators    
    public void setNumSlots(int numSlots){
        this.numSlots = numSlots;
    }
        
    public void setRoomIDCounter(int roomIDCounter){
        Room.roomIDCounter = roomIDCounter;
    }
        
    public void setRoomID(String roomID){
        this.roomID = roomID;
    }
        
    /*public void setBookings(Booking[] bookings){
        /*this.bookings = bookings;
    }*/
        
    public void setSeatingCapacity(int seatingCapacity){
        this.seatingCapacity = seatingCapacity;
    }
}