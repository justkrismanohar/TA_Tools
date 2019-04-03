/*
 Author: Kareem Mohammed
 ID: 816007247
 */
public class Room{

    private static final int numSlots = 8;
    private static int roomIDCounter = 100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    
    
    //Constructors
    
    public Room(String name, int seatingCapacity){
        
        this.roomID = name + roomIDCounter;
        roomIDCounter+=100;
        this.seatingCapacity = seatingCapacity;
        this.bookings = new Booking[numSlots];
        
    }
    
    
    //Methods
    
    public String addBooking(String description, int duration, int seats){
        
        if(!canFitNumbers(seats))
        return null;
        
        if(!canFitTime(duration))
        return null;
        
        int durationCounter = duration;
        
        Booking holdBooking = new Booking (description, duration, seats);
        for(int x=0; x<numSlots; x++){
            
            if(bookings[x] == null && durationCounter > 0){
                
                bookings[x] = holdBooking;
                bookings[x].setLocation(this.roomID);
                durationCounter--;
                
            }
        }
        String bookingDetails = holdBooking.toString();
        return "Booking added to schedule:\n" + bookingDetails;
        
    }
    
   public boolean canFitNumbers(int numSeats){
    
       if(numSeats > this.seatingCapacity)
        return false;
        
       return true;
    }
    
   public boolean canFitTime(int duration){
    
       int freeSlots = 0;
        for(int x=0; x<numSlots; x++){
            
            if(bookings[x] == null)
            
            freeSlots++;
        }
       
       if(duration>freeSlots)
        return false;
        
       return true;
    }
    
   public String getBookingDetails(int bookingID){
    
    int bookingIDHold;
    
    for(int x=0; x<numSlots; x++){
        
        bookingIDHold = bookings[x].getBookingID();
        
        if(bookingIDHold == bookingID)
         return bookings[x].toString();
        
    }
    
    return "\nBooking not found";
    
    }
   
   private boolean isRoomEmpty(){
    
       boolean isEmpty = true;
       
       for(int x=0; x<numSlots; x++){
           
           if(bookings[x] != null)
           isEmpty = false;
           
        }
       
       return isEmpty;
    } 
   
   public String getBookingList(){
    

       if(isRoomEmpty())
        return "No bookings have been made for this room\n";
       
       String bookingList = "";
        
       for(int x=0; x<numSlots; x++){
           if(bookings[x] != null)
           bookingList += bookings[x].toString() + "\n";
        }
        
       return bookingList; 
    } 
    
   public String getDetailedBookingGrid(){
    
       String bookingRow;
       
       int bookingID;
       
       bookingRow = this.roomID + "|";
       
       for(int x=0; x<numSlots; x++){
           
           if(bookings[x]!= null){
           bookingID = bookings[x].getBookingID();
           
           bookingRow+= " " + bookingID + " |";
           }
           else
           bookingRow+= "   |";
        }
       
       return bookingRow;
    }
    
   public String getRoomID(){
    
        return this.roomID;
    }
    
   public boolean hasBooking(int bookingID){
    
    int bookingIDHold;
    
    for(int x=0; x<numSlots; x++){
        
        if(bookings[x]!= null){
        
        bookingIDHold = bookings[x].getBookingID();
        
        if(bookingIDHold == bookingID)
        return true;
     }
    }
    
    return false;
    }
   
   public String toString(){
    
        return "Room ID: " + roomID + " Seats: " + seatingCapacity + "\n";
    }
   
   
}
