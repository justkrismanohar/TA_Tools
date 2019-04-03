

public class Room
{
   /*ID: 816009134*/
     
    private static int numSlots = 8;
    private static int roomIDCounter = 100;
    private String name;
    public String roomID;
    private Booking[] bookings = new Booking[8];
    private int seatingCapacity;
    private int currentSlot;
    

    public Room(String name, int seatingCapacity)
    {
        currentSlot = 0;
        this.name = name;
        this.seatingCapacity = seatingCapacity;
        roomID = name + roomIDCounter;
        roomIDCounter += 100;
        
    }
    public boolean canFitNumbers(int numSeats){
        if(numSeats > seatingCapacity)
            return false;
        
        return true;
    }
    public boolean canFitTime(int duration){
        if( duration > (numSlots - currentSlot) )
            return false;
        
        return true;
    }

    public String addBooking(String description, int duration, int seats){
         if(!(canFitTime(duration) || canFitNumbers(seats)))
            return("Invalid parameters for booking entry.");
            
       else{
                int end = currentSlot + duration;
             for(int i=currentSlot; i<end; i++)
             {
                 bookings[i] = new Booking(description,duration,seats,roomID);
                 currentSlot+=1;
              }    
            String msg = "Booking added to schedule: ";
            return(msg+"\n ID: "+bookings[currentSlot-1].bookingID+" Description: "+description+" Duration: "+duration+"hrs "+ "Seats: "+ seats );
        } 
    }    
    public String getBookingDetails(int bookingID)
    {
        for(int i=0; i<currentSlot; i++)
         {
            if(this.bookings[i].bookingID == bookingID)
                return("\n" + "Description: " + bookings[i].description + " Duration: " + bookings[i].duration + "hrs " + " Seating: " + bookings[i].numSeating);
         }
         return("Not found!");
    }
    public String getBookList()
    {
        StringBuilder addStr = new StringBuilder();
       
        if(null == bookings[0])
                return("\nNo bookings found for " + roomID);
        for(int i=0; i<currentSlot; i+=(bookings[i].duration))
        {
             addStr.append("\nDescription: " + bookings[i].description + " Duration: " + bookings[i].duration + " Seats: " + bookings[i].numSeating);
        }
       String msg = "\nBookings found for " + roomID+":";
       return(msg + addStr.toString());    
    }
    public String getDetailedBookingGrid()
    {
       StringBuilder grid = new StringBuilder();
       grid.append("|");
       for(int i=0; i<numSlots; i++)
       {   
           if(!(null == bookings[i]))
           {
            // grid.append("     "+ bookings[i].bookingID + "     "+"|");
            grid.append(String.format("%5d%5s",bookings[i].bookingID, "|"));
            }
           else grid.append(String.format("%10s", "|"));      
       }
       return(grid.toString());
    }
    public String getRoomID(){
       return(name + this.roomID);
    }
    public boolean hasBooking(int bookingID){
        for(int i=0; i<currentSlot; i++)
        {
            if(bookings[i].bookingID == bookingID)
                return true;
        }
      return false;
    }
    public String toString(){
        return("Room ID: "+roomID + " the seating capacity is " + seatingCapacity);
    }
    
    
              
              
            
    
}
