/**
 816010441 Jevon Greenidge
 */
public class Room
{
    // instance variables - replace the example below with your own
    private static int numSlots=8;
    private static int roomIDCounter=100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private int counter;
    
    // Constructors
    
    public Room(String name, int seatingCapactiy)
    {
        roomID = name + roomIDCounter;
        roomIDCounter += 100;        
        bookings = new Booking[8];
        this.seatingCapacity = seatingCapacity;
        numSlots = 8;
        counter=0;
    }

    //Accessors 
    
    public String getRoomID(){
        return roomID;
    }
    
    public int getNumSlots(){
        return numSlots;
    }
    
    public int getSeatingCapacity(){
        return seatingCapacity;
    }
    
    public Booking[] getBookings(){
        return bookings;
    }
    
    //methods
    
    
    public boolean canFitNumbers(int numSeats){
        if(seatingCapacity >= numSeats)
            return true;
        else 
            return false;  
    }
    
     public boolean canFitTime(int duration){
        if(numSlots >= duration )
            return true;
        else            
            return false;
    }
    
    public String getBookingDetails(int bookingID){
        int i=0;
        while(i < counter ){
            if((bookings[i].getBookingID())==(bookingID))        
                return bookings[i].toString() ;
            else
                i++;           
        }        
        String notFound="\nThe booking with ID:"+bookingID+"was not found";
        return notFound;
    }
    
    
    
    
    
    
    public String addBooking(String description, int duration, int seats) {
    
     if (canFitNumbers(seats) && canFitTime(duration) ){
         Booking b= new Booking(description, duration, seats);
         b.makeLocation (getRoomID());
         
        for(int i=0; i<duration; i++){
                bookings[counter]= b;
                counter++;
                numSlots--;
            }
            String bookingDetails="\nBooking added to schedule: "+ getBookingDetails(b.getBookingID());         
            return bookingDetails;
       }
       String bookingDetails="\nThe room cannot accomodate the booking request.";
       System.out.println(bookingDetails);
       return null ; 
        
        
        
        
    }
    
    public String getBookingList(){
        
     if (counter !=0){
         String all= "\nAll bookings for the Room: ";
         
         for (int i=0; i<counter; i++){
             all+="\nTime Slot "+(i+1)+ bookings[i].toString(); 
    }
       return all;
}
    return "No bookings made";
}
    
    
    
    public String getDetailedBookingGrid(){
        String gridFormat = "\n| "+ roomID+" | " ;
        for(int i=0;i<counter;i++)
            gridFormat += bookings[i].getBookingID()+" | ";
        
        for(int i=counter;i<8;i++)
            gridFormat += "  | ";       
        return gridFormat;    
    }
    
    
    public boolean hasBooking(int bookingID){
        boolean found = false;
        for(int i=0; i<counter ;i++){
            if(bookings[i].getBookingID()==bookingID)
                found = true;            
        }
        return found;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
}
    
    




