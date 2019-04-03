//Name:Jehan Hunte
//ID#:816003696
//COMP 2603 Assignment 1

public class Room 
{
   public int numSlots = 0;  
   private static int  roomIDCounter = 0;
   private String roomID;
   public Booking[] bookings = new Booking[8];
   private int seatingCapacity;
   
    public Room(String _name, int _seatingCapacity)
    {
      // various mutators
      this.roomIDCounter+=100;
      this.roomID = _name.toUpperCase()+roomIDCounter;
      this.seatingCapacity = _seatingCapacity;
      
    }
    
    //Accessors
    public String getRoomID(){
        return roomID;
    }
    
    public int getseatingCapacity(){
        return seatingCapacity;
    }
    
    public int getroomIDCounter(){
        return roomIDCounter;
    }
    
    
    
    public String addBooking(String _description , int _duration, int _seats){ 
        
        String error = "\nnull";
        String success = "\nBooking successfully added to schedule:";
        String bookDetails = "";
        
        if(canFitTime(_duration) && canFitNumbers(_seats)){

            for(int i = numSlots; i < numSlots + _duration; i++){
                bookings[i] = new Booking(_description,_duration,_seats);
                bookings[i].location = roomID;
                bookDetails = bookings[i].toString();
        }
        bookings[numSlots].bookingIDCounter++;
        numSlots = numSlots + _duration;
        return success + bookDetails;
    }
    
     return null; 
    }
    
   
     public boolean canFitNumbers(int _numSeats){
        
        return (seatingCapacity >= _numSeats);
        
    }
    
     
    public boolean canFitTime(int _duration){
        
        return ((8-numSlots)>=_duration);
        
    }
    
     
    public String getBookingDetails(int _bookingID){
    
        String bookingDetails = "";
        String error = "null";
        for (int i = 0; i < numSlots; i++){
            if(bookings[i].getBookingID() == _bookingID){
                return bookings[i].toString();
            }
        }
        return error;
        
    }
    

    public String getBookingList(){
        String error = "\nNo bookings have been made";
        String details = "";
        if (numSlots == 0) return error;
        for(int i = 0; i < numSlots; i++){
           details += bookings[i].toString();
        }
        return details;
    }
   
   
   
    public String getDetailedBookingGrid(){
        
        final int maxBook = 7;
        String Grid = "";
       
        for(int i = 0; i <= maxBook; i++){
           if(bookings[i] != null){
                Grid += bookings[i].bookingID+" |";
            }
            else 
                Grid +=" "+" |";
           
        
    }
        return Grid;
}
    
    
    
    public boolean hasBooking(int _bookingID){
        
        boolean result = false;
        
        for(int i = 0; i < numSlots; i++){
            if(_bookingID == bookings[i].bookingID){
                    result = true;
                        break;
            }
           
        }
        return result;
           
    }
    
    
     public String toString(){
         
        String roomDetails = " ";
        roomDetails = "\nROOM ID: "+ roomID + "  SEATS " + seatingCapacity + "\n";
        return roomDetails;
        
    }
    
    
}
