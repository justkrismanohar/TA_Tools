//JOSHUA SINGH 816008321
public class RentalSystem{
    private Room[] rooms;
    private int numRooms;
    
    //COMSTRUCTORS
    public RentalSystem(){
        rooms = new Room[10];
        numRooms = 0;
    }
    
    //ACCESSORS
    public int getNumRooms(){
        return numRooms;
    }
    
    public Room[] getRooms(){
        return rooms;
    }
    
    //METHODS
    public String addRoom(String name, int seatingCapacity){
        String content;
        if(numRooms < 10){
            Room r = new Room(name, seatingCapacity);
            rooms[numRooms] = r;
            numRooms = numRooms + 1;
            content = r.toString(name, seatingCapacity);
            return content;
        }
        return content = "Cannot add room; Max rooms reached";
    }
    
    public String getRoomList() {
        String message;
        if(numRooms != 0){
            message ="\nRooms available:";
            for(int i = 0; i < numRooms; i = i + 1)
            message = message + "\n" + rooms[i].getRoomID();
            return message;
        }
        message = "No rooms in the system.";
        return message;        
        
    }
    
    public String addBooking( String description, int duration, int numSeating){
        String content;
        if (numRooms != 0){
             for (int i = 0; i < numRooms; i = i + 1){
                 content = rooms[i].addBooking(description, duration, numSeating);
                 if(content != null){
                     return content;
                 }
             }
        }
        content = "Cannot add Booking.";
        return content;
    }
    
    public String getBooking(int bookingID){
        String content = "FOUND: ";
        if(numRooms != 0){
            for(int i = 0; i < numRooms; i = i + 1){
                if(rooms[i].hasBooking(bookingID) == true){
                    content = content + rooms[i].getBookingDetails(bookingID);
                    return content;
                }
                                
            }
        }
        content = "Booking ID not found.";
        return content;
    } 
        
    
    public String getBookingsByRoom(String roomID){
        String content;
        if(numRooms != 0){
            for (int i = 0; i < numRooms; i = i + 1){
                if (rooms[i].getRoomID() == (roomID))
                return rooms[i].getBookingList();
            }
        }
        content ="RoomID not found.";
        return content;
    }
        
    public String getBookingGrid(){
        String content= " Booking grid";
        if (numRooms != 0){
            for(int i = 0; i < numRooms; i = i + 1)
            content = content + rooms[i].getDetailedBookingGrid();
            return content;
        }
        content = "No rooms in the system.";
        return content;
    }
}
