//JOSHUA SINGH 816008321
public class Room{
    private static int numSlots = 8;
    private static int roomIDCounter = 100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private int count;
    
    //CONSTRUCTOR
    public Room(String name, int seatingCapactiy){ 
        roomID = name + roomIDCounter;
        roomIDCounter = roomIDCounter + 100;
        bookings = new Booking[8];
        this.seatingCapacity = seatingCapacity;
        numSlots = 8;
        count = 0;
    }
   
    //ACCESSORS
    public int getNumSlots(){
        return numSlots;
    }
    
    public String getRoomID(){
        return roomID;
    }
    
    public Booking[] getBookings(){
        return bookings;
    }
    
    public int getSeatingCapacity(){
        return seatingCapacity;
    }
    
    //METHODS 
    public Boolean canFitNumbers(int numSeats){
        if (numSeats <= seatingCapacity)
            return true;
        else 
            return false;
    }
    
    public Boolean canFitTime(int duration){
        if(duration <= numSlots)
            return true;
        else 
            return false;
    }
    
     public String getBookingDetails(int bookingID){
        int i = 0;
        while(i < count){
            if((bookings[i].getBookingID()) == (bookingID))        
                return bookings[i].toString() ;
            else
                i = i + 1;           
        }        
        String notFound = "The booking for BookingID: " + bookingID + "was not found.";
        return notFound;
    }
    
    public String getBookingList(){
        if(count != 0){
            String all = "Bookings for the Room: ";
            for (int i = 0; i < count; i = i + 1){
                all = all + "\nTime Slot " + (i + 1) + bookings[i].toString();
            }
       return all;
    }
    return "No bookings have been made.";
    }
    
    public String getDetailedBookingGrid(){
        String grid = "| " + roomID + " | ";
        for(int i = 0; i < count ; i = i + 1)
            grid = grid +  bookings[i].getBookingID()+" | ";
        for(int i = count; i < 8; i = i + 1)
            grid = grid + " | ";      
        return grid;    
    }
    
    public Boolean hasBooking(int bookingID){
        boolean found = false;
        for(int i = 0; i < count ; i = i + 1){
            if(bookings[i].getBookingID() == bookingID)
            return found;
        }
        return true;
    }
    
    public String addBooking(String description, int duration, int seats){
        if(canFitNumbers(seats) && canFitTime(duration) ){
         Booking a = new Booking(description, duration, seats);
         a.setLocation(getRoomID());
         for(int i = 0; i < duration; i = i + 1){
             bookings[count] = a;
             count = count + 1;
             numSlots = numSlots - 1;
            }
         String details = "Booking added to schedule: " + getBookingDetails(bookings[count].getBookingID());         
         return details;
       }
       String details = "The request cannot be processed.";
       System.out.println(details);
       return null ; 
    }
    
    public String toString(String name , int seatingCapacity){
        String s;
        s = "RoomID: " + roomID + " Capacity: " + seatingCapacity;
        return s;
    }
}

