//816007834
import java.util.Arrays;

public class RentalSystem {
    private Room[] rooms=new Room[10];
    private int numRooms;
    
    public RentalSystem() {
        numRooms=0;
    }
    
    public String addRoom(String name, int seatingCapacity) {
        if(numRooms<10) {         
            rooms[numRooms]=new Room(name, seatingCapacity);  
            numRooms++;
            return rooms[numRooms-1].toString();
        }
        else
            return "Cannot add room; Max rooms reached.";
    }
    
    public String getRoomList() {
        if(numRooms>0) {
            String list=Arrays.toString(rooms);
            return list;
        }
        else
            return "No rooms in the system.";
    }
    
    public String addBooking(String description, int duration, int numSeating) {
        for(int i=0; i<numRooms; i++) {
            String result=rooms[i].addBooking(description, duration, numSeating);
            if(result!=null) 
                return result;  
        }
        return "Cannot add Booking";  
    }
    
    public String getBooking(int bookingID) {
        for(int i=0; i<numRooms; i++) {
            String details=rooms[i].getBookingDetails(bookingID);
            if(details!=null)
                return details;
        }
        return "Booking ID Not Found";
    }
    
    public String getBookingsByRoom(String roomID) {
        String list;
        for(int i=0; i<numRooms; i++) {
            if(rooms[i].getRoomID().equals(roomID)) {
                list=rooms[i].getBookingList();
                return list;
            }
        }
        return "Room ID not Found";
    }
    
    /*public String getBookingGrid() {
        for(int i=0; i<numRooms; i++) {
            String grid=rooms[i].getDetailedBookingGrid();
            return grid;
        }
    }*/

    public int getNumRooms() {
        return numRooms;
    }
}
