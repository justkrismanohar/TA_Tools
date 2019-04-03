 /*
StudentID: 816117607
StudenName: Joshua Peter:
Assignment: 1
*/

public class Room
{
    private static final int numSlots=8;   
    private static int roomIDCounter=0;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private String name;
    private int x;
    private int availableSlots;
    private int curr;
    private String list;

    public Room(String name, int seatingCapacity)
    {
        this.roomID = name + generateRoomID();
        this.seatingCapacity=seatingCapacity;
        this.bookings = new Booking[numSlots];
        this.availableSlots = numSlots;
        
    }
        
    public String addBooking( String description,int duration, int seats){
                    
        if(canFitNumbers(seats)==true && canFitTime(duration)==true){ 
            this.bookings[curr] = new Booking(description,duration,seats);
            this.bookings[curr].setLocation(roomID);

            for(x = (curr+1); x<(duration+curr); x++){
                this.bookings[x] = this.bookings[x-1];
            }
            return "\nBooking added to schedule: \n" + this.bookings[curr].toString() +"\n";
        }
        else 
            return null;
    }
    
    public boolean canFitNumbers(int numSeats){
        if(this.seatingCapacity >= numSeats){
            return true;
        }
        else 
            return false;
    }
    
    public boolean canFitTime(int duration){    
        if(availableSlots >= duration && duration > 0){
            curr = numSlots-availableSlots;
            this.availableSlots -= duration;
            return true;
        }   
        else 
            return false;
    }
    
    public String getBookingDetails(int bookingID){
        for(x = 0; x < numSlots; x++){
            if (this.bookings[x] == null){
                break;
            }
            else if(this.bookings[x].getBookingID() == bookingID){
                return this.bookings[x].toString();
            }
        }
        return "Booking ID " + bookingID + " was not found in Room " + roomID + "\n";
    }
    
    public String getBookingList(){
        if(this.bookings[0] == null)
            return "no bookings made in room " + this.roomID + "\n";
        else{
            list = this.toString() + "\n";
            test: for(x = 0; x < numSlots; x++){
                      if(this.bookings[x] != null)
                          list = list + this.bookings[x].toString() + "\n";
                      else
                          break test;
                      }
            return list;
        }
    }
    
    public String getDetailedBookingGrid( ){
        list = this.getRoomID() +"|   ";
        for(x = 0; x < 8; x++){
            if(this.bookings[x] != null)
                list = list + this.bookings[x].getBookingID() + "   |   ";
            else{
                list = list +"    |   ";
            }
        }
        return list;
    }
        
    public String getRoomID(){
        return this.roomID;
    }
    
    public boolean hasBooking( int bookingID){
        for(x = 0; x < 8; x++){
            if(this.bookings[x] == null) 
                return false;
            else if (this.bookings[x].getBookingID() == bookingID)
                return true;
        }
        return false;
    }
    
    public String toString()
    {
        return "Room ID: "+ this.roomID + " Seating: " + this.seatingCapacity;
    }
    
    private int generateRoomID(){
        this.roomIDCounter += 100; 
        return this.roomIDCounter; 
    }
}
