 //816012230
public class Room{
    private static final int numSlots = 8;
    private static int roomIDCounter = 100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private static int i = 1;
    private int num;
   public Room(String name, int seatingCapacity){
        generateRoomId(name);
        this.seatingCapacity = seatingCapacity;
        num = 0;
    }
   public void generateRoomId(String name){
       roomID = name + roomIDCounter;
       roomIDCounter += 100;
    }
   public String getRoomID(){
        return roomID;
    }
   public boolean canFitNumbers(int numSeats){
        if(seatingCapacity <= numSeats)
            return true;
        else
            return false;
    }
   public boolean canFitTime(int duration){
        if(num + duration <= numSlots)
            return true;
        else
            return false;
        }
   public String addBooking(String description, int duration, int seats){
        if(canFitNumbers(seats)){
            if(canFitTime(duration)){
                bookings[i] = new Booking(description, duration, seats);
                i++;
                num = num - duration;
                return "Booking added to schedule \n " + bookings[i-1].toString();
            }
            else{
                return "Times overlap. Cannot fit event.";
            }
        }
        else{
            return "Room cannot accommodate the expected numbers.";
        }
    }
   public String getBookingDetails(int bookingID){
        for (int j=0; j<num; j++){
            if (bookings[j].getID() == bookingID){
               return bookings[j].toString();
            }
        }
        return "Booking ID not found. Please try again.";
    }
   public String getBookingList(){
        String details = "";
        if(num == 0){
            details = "No bookings have been made for this room.\n";
        }
        else{
            for(int j = 0; j < num; j++){
                details += bookings[j].toString() + "\n";
            }
        }
        return details;
    }
   public String getDetailedBookingGrid(){
       String details = "";
       if(roomID.length()>6) 
        details = roomID + "|"; 
       else 
        details = roomID + " |";
       for(int j = 0; j < num; j++){
           if(bookings[j].getID() < 10)
            details += " " + bookings[j].getID() + "  |";
           else
            if(bookings[j].getID() >= 10)
            details += " " + bookings[j].getID() + " |";
       }
       for(int k = numSlots - num; k<numSlots ; k++){
           details += "       |";
        }
       details += "\n";
       return details;
    }
   public boolean hasBooking(int bookingID){
       for(int j = 0; j < num; j++){
           if(bookings[j].getID() == bookingID)
            return true;
        }
       return false;
    }
   public String toString(){
       String details = " Room ID: " + roomID + "Seating Capacity: " + seatingCapacity;
       return details; 
    }
}
