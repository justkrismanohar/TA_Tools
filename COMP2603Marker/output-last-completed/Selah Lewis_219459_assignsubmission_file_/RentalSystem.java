//816012230
public class RentalSystem{
    private Room[] rooms;
    private int numRooms;
    private static int i = 0;
    public RentalSystem(){
        numRooms = 0;
    }
    public String addRoom(String name, int seatingCapacity){
        if(numRooms < 10){
            rooms[numRooms] = new Room(name, seatingCapacity);
            numRooms++;
            return "Room added successfully.";
        }
        return "Cannot add room; Max rooms reached.";
    }
    public String getRoomList(){
        String details = "";
        if(numRooms == 0){
            details = "No rooms in the system. \n";
        }
        else{
            for(int j = 0; j < numRooms; j++){
                details += rooms[j].toString() + "\n";
            }
        }
        return details;
    }
    public String addBooking(String description, int duration, int numSeating){
        for(int j = 0; j < numRooms; j++){
            if(rooms[j].canFitTime(duration) && rooms[j].canFitNumbers(numSeating)){
                return rooms[j].addBooking(description, duration, numSeating);
            }
        }
        return "\n Cannot add booking. \n";
    }
    public String getBooking(int bookingID){
        for(int j = 0; j < numRooms; j++){
            if(rooms[j].hasBooking(bookingID))
                return rooms[j].getBookingDetails(bookingID);
        }
        return "\n Booking ID not found \n";
    }
    public String getBookingsByRoom(String roomID){
        String details = "\n Room ID not found \n";
        for(int j = 0; j < numRooms; j++){
            if(rooms[j].getRoomID().equals(roomID)){
                details = "Booking List for " +  rooms[j].getRoomID() + "\n" + rooms[j].getBookingList();
            }
        }
        return details;
    }
    public String getBookingGrid(){
        if (numRooms == 0)
            return "No rooms in the system";
        String Bgrid = "";
        for(int j = 0; j < numRooms; j++){
            Bgrid += rooms[j].getDetailedBookingGrid() + "\n";
        }
        return Bgrid;
    }
}
