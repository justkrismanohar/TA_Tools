
//Jade Chattergoon 816007199 COMP2603 OOP1 ASG1

public class Room
{
    // instance variables - replace the example below with your own
    private int numSlots=0;
    private static int roomIDCounter=100;
    private String roomID;
    private Booking[] bookings= new Booking[8];
    private int seatingCapacity;
    private String roomLocation;
    private String bookingGrid="";
    private String bookingList="";
    private int foundBookingID;
    private int slotsAvailable;
    private int countSlots;
    public Room(String name,int seatingCapacity)
    {   
        
        roomID= name + roomIDCounter; // will be generated when room object is created
        roomIDCounter+=100;
        this.seatingCapacity=seatingCapacity;
        
    }

    public String getRoomID(){ //accessor
        return roomID;
    }
    
    public String getBookingDetails(int bookingID){ //displays booking details for a room given the bookingID
         if(hasBooking(bookingID)){
            for( countSlots=0;countSlots<numSlots;countSlots++){
                
                if( bookings[countSlots].getBookingID()==bookingID){
                return bookings[countSlots].toString();
                
                }
            }
         }
         return "No such BookingID exists."; 
      }
    
   
    public String getBookingList(){
        bookingList="";
        for(int countSlots=0;countSlots<numSlots;countSlots++){
            
            if(bookings[countSlots]==null){
                return null ;
            }
     
            foundBookingID=bookings[countSlots].getBookingID();
            bookingList= bookingList +  "\n" + getBookingDetails(foundBookingID);
        }
        if(bookingList==null){
         return "There are currently no bookings in this room.";
        }
        
        return bookingList;
    }
    
    public String getDetailedBookingGrid(){
        
        bookingGrid=roomID + "  |   ";
        slotsAvailable=8-numSlots;
        if(numSlots==0){
            for(countSlots=0;countSlots<8;countSlots++){
                bookingGrid+= "   |   ";
        }
    }
    else{
        for(int countSlots=0;countSlots<numSlots;countSlots++){
            foundBookingID=bookings[countSlots].getBookingID();
            if(foundBookingID>9){
                bookingGrid= bookingGrid + foundBookingID  + "  |   ";
            }
            else{
            bookingGrid= bookingGrid + foundBookingID  + "  |   "; 
            }
        }
        for(int countSlots=numSlots;countSlots<8;countSlots++){
            bookingGrid+= "   |   ";
        }
    }
        return bookingGrid;
    
}
public String addBooking(String description, int duration, int seats)
    {
        if(canFitNumbers(seats) && canFitTime(duration)){
            
            Booking b=new Booking(description,duration,seats); //create Booking
            
            b.setLocation(roomID);
            for(countSlots=numSlots;countSlots<(numSlots+duration);countSlots++){
             bookings[countSlots]=b; // puts booking obj in array
            }
            numSlots+=duration;
            return "Booking successfully added to schedule: " + b.toString();
               
        }
        
        return null;
    }
private  boolean canFitNumbers(int numSeats){
        if(numSeats<=seatingCapacity){
            return true;
        }
        else{
            return false;
        }
    }
private boolean canFitTime(int duration){
        slotsAvailable=8-numSlots;
        if(duration<=slotsAvailable){
            return true;
        }
        else{
            return false;
        }
        
    }
   


public boolean hasBooking(int bookingID){
    
        
        for( countSlots=0;countSlots<numSlots;countSlots++){
            if(bookings[countSlots]==null){
               return false;
            }
            foundBookingID=bookings[countSlots].getBookingID();
            
            if(foundBookingID == bookingID){
                return true;
            }
            
        }
        return false;
    }
    
public String toString(){
        return "Room ID: " + roomID + "  Seating Capacity: " + seatingCapacity;
    }
    
    
}
