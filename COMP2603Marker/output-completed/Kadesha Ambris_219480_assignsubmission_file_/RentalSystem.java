//816006483
public class RentalSystem{
    public Room[] rooms = new Room[10];
    private static int numRooms = 0;
    String message;
    int i;
    public RentalSystem(){
        //numRooms = numRooms + 1;
    }
    
    public String addRoom(String name, int seatingCapacity){
        if (numRooms <= 10){
            Room r1 = new Room(name,seatingCapacity);
            rooms[numRooms] = r1;
            numRooms = numRooms + 1;
            message = "Room was successfully added \n" + r1.toString();
       }
       else
            message = "Cannot add room; Max rooms reached.";
       return message;
    }
    
    public String getRoomList(){
        if (numRooms == 0)
            message = "No rooms in the system \n";
        else{
            for(i= 0; i<numRooms; i++){
            message += rooms[i].toString();
            }
        }
        return message;
    }
    
    public String addBooking(String description, int duration, int numSeating){
        if (numRooms == 0){
            message = "No rooms in the system\n";
            return message;
        }
        
        else{
            for(i=0;i<=numRooms;i++){
                if(rooms[i].getAvailable() < rooms[i].getNumSlots()){
                   String booked = rooms[i].addBooking(description,duration,numSeating) + "\n";
                   message = "Booking was successfully added to room: \n" + booked;
                   return message;
                }
            }
            message = "No space available in any existing room \n";
        }
        return message;
                    
    }
    
    public String getBooking(int ID){
        for (i=0;i<numRooms;i++){
            if(rooms[i].hasBooking(ID)){
                message = rooms[i].getBookingDetails(ID);
                return message;
            }
        }
        message = "No booking with bookingID" + ID + " exists \n";
        return message;
    }
    
    public String getBookingsByRoom(String roomID){
        if (numRooms == 0){
            message = "No rooms in the system\n";
            return message;
        }
        
        for (i=0;i<numRooms;i++){
            Room r1 = rooms[i];
            if(r1.getRoomID() == roomID){
                message += r1.getBookingList();
            }
        }
        //message += "There is no room with that roomID \n";
        return message;
    }
    
    public String getBookingGrid(){
        if (numRooms == 0){
            message = "No rooms in the system\n";
            return message;
        }
        
        for (i=0;i<numRooms;i++){
            Room r1 = rooms[i];
            message += r1.getDetailedBookingGrid() +"\n";
        }
        return message;
    }
    
}