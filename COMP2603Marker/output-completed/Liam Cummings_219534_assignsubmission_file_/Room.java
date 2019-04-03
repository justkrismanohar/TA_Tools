public class Room
{
    //ID - 816003418
    public int numSlots = 0;
    private static int roomIDCounter = 0;
    public String roomID;
    public Booking[] bookings = new Booking[8]; // object made
    public int seatingCapacity;
    public String className;
    private int id;
 
    //room being created 
    public Room(String name,int seatingCapacity){
        className = name;
        this.seatingCapacity = seatingCapacity;
        
        roomIDCounter+= 100;
        id = roomIDCounter;
        roomID = name+id;
    }
    
    
    public String addBooking(String description, int duration, int seats){
       String details = null;
        int i = numSlots;
         bookings[numSlots] = new Booking(description, duration, seats);
        if(canFitNumbers(seats) == true && canFitTime(duration) == true){
           bookings[numSlots].location = getRoomID();
            while(i < duration + numSlots){
                bookings[i] = bookings[numSlots];
                i++;
            } 
            
            details = "Booking added to schedule: " +"ID: " + 
            bookings[numSlots].getBookingID() + " | "
            + description + 
            " | Booking Length: " + duration + "hrs | Seats: " + seats;
            numSlots += duration;
          
        }
        
        return details;
    }
    
    //done
    public boolean canFitNumbers(int numSeats){
        if(numSeats <= seatingCapacity){
            return true;
        }
        
        return false;
    }
    
    public boolean canFitTime(int duration){
        if(duration + numSlots <= 8){
            return true;
        }
        
        return false;
    }
    
    public String getRoomID(){
        return roomID;
    }
    
    public String toString(){
        String details = "Room ID: " + getRoomID()
        + "\nSeating Capacity: " + seatingCapacity;
        return details;
    }
    
    public String getBookingDetails(int bookingID){
        String details = null;
        int i = 0;
        Boolean found = false;
        if(hasBooking(bookingID) == true){ 
            while(i < numSlots || found == false){
                if(bookings[i].getBookingID() == bookingID){
                    details = bookings[i].toString();
                    found = true;
                }
                i++;
            }
        }
        return details;
    }
    
    public String getBookingList(){
        String details = null;
        for(int i = 0; i < numSlots; i++){
            details =  details + bookings[i].toString() + "\n";
        }
        return details;
    }
    
    public String getDetailedBookingGrid(){
        String details = getRoomID() + "| ";
        int i = 0;
        while(i < numSlots){
            details = details + bookings[i].getBookingID() + " |";
            i++;
        }
        return details;
    }
    
    public boolean hasBooking(int bookingID){
        for(int i = 0; i < numSlots; i++){
            if(bookings[i].getBookingID() == bookingID){
               return true;
            }
        }
        return false;
    }
}
