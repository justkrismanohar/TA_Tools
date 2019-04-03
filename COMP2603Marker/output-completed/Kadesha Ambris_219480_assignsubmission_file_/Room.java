//816006483
public class Room{
    private int numSlots;
    private static int roomIDCounter= 0;
    public String roomID;
    private Booking[] bookings;
    public int seatingCapacity;
    
    int i;
    int m;
    int l;
    int available; 
    String detail;
    String loc;
    String message;
    String det;
    
    public Room(String name,int seatingCapacity){
       this.seatingCapacity = seatingCapacity;
       numSlots = 8;
       available = 0;
       roomIDCounter = roomIDCounter + 100;
       roomID = name + roomIDCounter;
       bookings = new Booking[8];
    }
    
    public int getRoomCounter(){
        return roomIDCounter;
    }
    
    public int getSeatingCapacity(){
        return seatingCapacity;
    }
    
    public int getNumSlots(){
        return numSlots;
    }
    
    public int getAvailable(){
        return available;
    }
    
    public String addBooking(String description, int duration, int seats){
       if (canFitNumbers(seats) && canFitTime(duration)){
           Booking b1 = new Booking(description,duration,seats);
           loc = getRoomID();
           b1.setLocation(loc);
           for (i = 0; i < duration; i = i + 1){
               bookings[i] = b1;
               available = available + 1;
            }
           message = "Booking added to schedule: \n"+ b1.toString();
       }
       else{
           message = "Booking was unsuccesful";
        }
       return message;
    }
    
    public boolean canFitNumbers(int numSeats){
        i = getSeatingCapacity();
        if (numSeats <= i){
            return true;
        }
        else{
            return false;
        }
    }
    
    public boolean canFitTime(int duration){
        if(duration <= numSlots){
            return true;
        }
         else{
             return false;
            }
    }
    
    public String getBookingDetails(int ID){
        String details;
        details = "Details for booking " + ID + ": \n";
        for(i=0;i<numSlots;i++){
            Booking b1 = bookings[i];
            if (b1.getBookingID() == ID){
                details += b1.toString();
                return details;
            }
        }
       details += "booking ID was not found\n";
       return details;
    }
    
    public String getBookingList(){
        i = 0;
        detail = " ";
        if (bookings[i] == null){
            detail = "There are no booking for this room \n";
        }
        else{
           m = numSlots - 8;
           for (i = 0;i < m; i= i + 1){
               
               detail += bookings[i].toString();
           }
        }
        return detail;
    }
    
    public String getDetailedBookingGrid(){
        det = "|" + roomID + "| ";
        for (i=0;i<available;i++){
            Booking b1 = bookings[i];
            det += b1.getBookingID() + "|";
        }
        for (i=available;i<8;i++){
            det += " | ";
        }
        return det;
    }
    
    
    public boolean hasBooking(int ID){
        for (i=0;i<available;i++){
            l = bookings[i].getBookingID();
            if (l == ID)
                return true;
        }
        return false;
    }
    
    public String getRoomID(){
        return roomID;
    }
    
    public String toString(){
        String representation = " ";
        representation = "Name: " + roomID.substring(0, 3) + "  RoomID: " + roomID + "  Seats: " + seatingCapacity + "\n";
        return representation;
    }
}