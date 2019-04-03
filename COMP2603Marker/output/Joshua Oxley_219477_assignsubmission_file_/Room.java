//816009424

public class Room{
    //attributes
    private static int numSlots=8;
    private static int roomIDCounter=100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;

    //constructors
    public Room(String name, int seatingCapacity){
        name= name;
        roomID= name + roomIDCounter;
        roomIDCounter+= 100;
        this.seatingCapacity= seatingCapacity;
    }
    
    public String addBooking(String descritption, int duration, int seats){
        
        return "Booking added to schedule: ";
    }
    public boolean canFitNumbers(int numSeats){
        if(numSeats <= seatingCapacity){
            return true;
        }
        return false;
    }
    public boolean canFitTime(int duration){
        if(duration <= numSlots)
            return true;
        return false;
    }
    public String getBookingDetails(int bookingID){
        
        return"";
    }
    public String getBookingList(){
        
        return "";
    }
    public String getDetailedBookingGrid(){
        
        return "";
    }
    
    public String getRoomID(){
        return roomID;
    }
    public boolean hasBooking(int bookingID){
        
        return false;
    }
    public String toString(){
        String details = toString();
        details+= "\nRoom ID: " +roomID+ "\n Seating Capacity: " +seatingCapacity;
        return details;
    }
    
    

    
}
