/*
 * Student ID: 816004003
 * Name: Keanu Nichols
 */
public class Room{
    //Attributes
    private int numSlots;
    private static int roomIDCounter = 100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private int numBookings;
    
    //Constructor
    public Room(String name, int seatingCapacity){
        this.seatingCapacity = seatingCapacity;
        this.roomID = name + roomIDCounter;
        this.roomIDCounter = roomIDCounter + 100;
        this.bookings = new Booking[8];
        this.numSlots = 8;
        this.numBookings = 8;
    }
    
    //Accessors
    public int getNumSlots(){
        return numSlots;
    }
    
    public int getNumBookings(){
        return numBookings;
    }
    
    public int getRoomIdCounter(){
        return roomIDCounter;
    }
    
    public String getRoomID(){
        return roomID;
    }
    
    public int getSeatingCapacity(){
        return seatingCapacity;
    }
    
    //Methods
    public boolean canFitNumbers(int numSeats){
        return(getSeatingCapacity() >= numSeats);
    }
    
    public int totalOccupiedTime(){
        int sum=0;
        for(int i=0; i<bookings.length; i++){
            if(bookings[i] != null)
                sum+=bookings[i].getDuration();
        }
        return sum;
    }
    
    public boolean canFitTime(int duration){
        return( (totalOccupiedTime() + duration) <= getNumSlots());      
    }
    
    public String addBooking(String description, int duration, int seats){
        if(!canFitNumbers(seats) || !canFitTime(duration) || duration == 0)
            return null;
        bookings[getNumBookings()-1] = new Booking(description,duration,seats); 
        bookings[getNumBookings()-1].setLocation(this.roomID);
        numBookings -= duration; 
        return("Booking added to schedule:\n" + bookings[getNumBookings()+duration-1].toString());
    }
    
    public String getBookingDetails(int bookingID){
        for(int i=bookings.length - 1; i >= 0; i--){
            if(bookings[i] != null && 
               bookings[i].getBookingId() == bookingID)
                return(bookings[i].toString());                
        }
        return ("This booking was not made\n");
    }
    
    public String getBookingList(){
        boolean val = false;
        String details = "";
        for(int i=bookings.length-1; i>=0; i--){
            if(bookings[i] != null){
                details+=bookings[i].toString();
                val = true;
            }
        }
        if(!val)
            return("No bookings made\n");
        return details;
    }
    
    public String getDetailedBookingGrid(){
        String details = "";
        if(getRoomID().contains("1000"))
            details += roomID + "|";
        else
            details += roomID + " |";
        int k,hours;
        boolean val = false;
        for(int i=bookings.length-1; i>=0; i--){
            if(bookings[i] != null && (hasBooking(bookings[i].getBookingId())) ){
                k = i;
                val = true;
                for(int j=0; j<bookings[k].getDuration(); j++){
                    hours = bookings[k].getBookingId();
                    if(i == bookings.length-1)
                        details+= "  ";
                    else
                        details+= " ";
                    if(hours < 10)
                        details+= bookings[k].getBookingId() + "  | ";
                    else
                        details+= bookings[k].getBookingId() + " | ";
                    i--;
                }
                i+=1;
            }
            else{
                if(!val)
                    details += "     " + "|";
                else{
                    details += "    " + "|";
                    val = false;
                }
            }
        }
        return details;
    }
    
    public boolean hasBooking(int bookingID){
        for(int i=bookings.length - 1; i >= 0; i--){
            if(bookings[i] != null && 
               bookings[i].getBookingId() == bookingID){
               return true;
            }
        }
        return false;
    }
    
    public String toString(){
        return("RoomID: " + getRoomID() + " Seating Capacity: " +
               getSeatingCapacity() + "\n");
    }
    
}