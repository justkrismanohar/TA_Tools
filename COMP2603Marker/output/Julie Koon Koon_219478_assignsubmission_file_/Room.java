//816008254
import java.util.Scanner;
public class Room{

    private final int numSlots=8; // limit is 8
    static private int start=0;
    static private int roomIDCounter=0;
    private String roomID;
    private  Booking[] bookings= new Booking[8];
    private int seatingCapacity;
    private String name;
    
    //Constructor
    public Room(String name, int seatingCapacity){
    roomIDCounter=roomIDCounter + 100;
    roomID= name + roomIDCounter;
    this.seatingCapacity=seatingCapacity;
    }
   
 
    //addBooking method
    public String addBooking(String description, int duration, int seats){
        if((canFitTime(duration)==true) && (canFitNumbers(seats)==true)){
            Booking b1= new Booking(description, duration, seats); 
            b1.setLocation(roomID);
            int numBooking=duration+start;
            for(int i=start; i<numBooking; i++)
                 bookings[i]=b1;
            start=numSlots;
            return "Booking added to schedule: \nLocation: " + roomID + "   Description: " + description + "   Duration: " + duration + " hour/s   Seats: " + seats + "\n";
        }
        else
        return null;     
        
    }
    
    //*canFitNumbers method
    public boolean canFitNumbers(int numSeats){
        if(numSeats<=seatingCapacity)
        return true;
        else
        return false;
    }
    
    //*canFitTime method
    public boolean canFitTime(int duration){
        int temp=start+duration;
        if(temp<8 )
        return true;
        else 
        return false;
    }
    
    //*hasBooking Method
    public boolean hasBooking(int bookingID){
        for(int i=0; i<start; i++){
            if(bookings[i].getBookingID()==bookingID)
            return true;
        }
        
        return false; 
    }  
    
    //*getBookingDetails Method
    public String getBookingDetails(int bookingID){
        for(int i=0; i<start; i++){
            if(bookings[i].getBookingID()==bookingID)
            return "\nBookingID: " + bookings[i].getBookingID() + " Description: " + bookings[i].getDescription() + " Duration: " + bookings[i].getDuration() + " Seating Amount:" + bookings[i].getNumSeating();
        }
    return "\nNo Bookings have been found for BookingID: " + bookingID;
    }
    
    //*getBookingList Method
    public String getBookingList(){
       
        String final_output=""; 
        for(int i=0; i<bookings.length; i++){
            String output=getBookingDetails(bookings[i].getBookingID());
            final_output= final_output + output;
        }    
            return final_output;
        
    }
   
    public String getDetailedBookingGrid(){
        String output="BOOKING GRID\n " + getRoomID();
        for(int i=0; i<bookings.length; i++){
            output= output +"| " + bookings[i].getBookingID() + " | ";
        }
        return output;
    }
    //toString Method
    public String toString(){
    return " RoomID: " + roomID+ " Seats: " + seatingCapacity;
    }
    
    //Mutators
    
    public void setRoomID (String roomID){
        this.roomID=roomID;
    }
    
    public void setSeatingCapacity (int seatingCapacity){
        this.seatingCapacity=seatingCapacity;
    }
    
    public void setRoomName(String name){
        this.name=name;
    }
    
    //Accessors
    public int getSeatingCapacity(){
        return seatingCapacity;
    }
    
    public String getRoomName(){
       
        return name;
    }
    
    public int getNumSlots(){
        return numSlots;
    }
    
    public String getRoomID(){
       return roomID;
    }

 

}