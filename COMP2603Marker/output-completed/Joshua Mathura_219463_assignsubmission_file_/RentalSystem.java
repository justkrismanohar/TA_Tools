//816010691

public class RentalSystem{
    private static final String ERROR_MAX_ROOMS = "Cannot add room; Max rooms reached.";
    private static final String ERROR_NO_ROOMS = "No rooms in the system.";
    private static final String ERROR_MAX_BOOKINGS = "Cannot add Booking.";
    private static final String ERROR_BOOKING_ID_NOT_FOUND = "Booking ID not found.";
    private static final String ERROR_ROOM_NOT_FOUND = "Room ID not found.";
    private static final short MAX_ROOMS = 10;
    private Room[] rooms;
    private int numRooms;
    
    public RentalSystem(){
        rooms = new Room[MAX_ROOMS];
        numRooms = 0;
    }
    
    public String addRoom(String name, int seatingCapacity){
        if (numRooms < MAX_ROOMS){
            rooms[numRooms] = new Room(name, seatingCapacity);
            return "ROOM ID: " + rooms[numRooms].getRoomID() + "  SEATS: " + rooms[numRooms++].getSeatingCapacity();
        }
        return ERROR_MAX_ROOMS;
    }
    
    public String getRoomList(){
        if (numRooms > 0){
            StringBuilder roomList = new StringBuilder("ROOM LIST");
            for (int i = 0; i < numRooms; ++i)
                roomList.append("\nROOM ID: " + rooms[i].getRoomID() + "  SEATS: " + rooms[i].getSeatingCapacity());
            return roomList.toString();
        }
        return ERROR_NO_ROOMS;
    }
    
    public String addBooking(String description, int duration, int numSeating){
        String temp = null;
        for (int i = 0; i < numRooms; ++i){
            temp = rooms[i].addBooking(description, duration, numSeating);
            if (temp != null)
                return temp;
        }
        return ERROR_MAX_BOOKINGS;
    }
    
    public String getBooking(int bookingID){
        for (int x = 0; x < numRooms; ++x)
            if (rooms[x].hasBooking(bookingID))
                return rooms[x].getBookingDetails(bookingID);
        return ERROR_BOOKING_ID_NOT_FOUND;
    }
    
    public String getBookingsByRoom(String roomID){
        for (int x = 0; x < numRooms; ++x)
            if (rooms[x].getRoomID().equals(roomID))
                return rooms[x].toString() + rooms[x].getBookingList();
        return ERROR_ROOM_NOT_FOUND;
    }
    
    public String getBookingGrid(){
        if (numRooms > 0){
            StringBuilder roomGrids = new StringBuilder("BOOKING GRID");
            for (int i = 0; i < numRooms; ++i)
                roomGrids.append('\n' + rooms[i].getDetailedBookingGrid());
            return roomGrids.toString();
        }
        return ERROR_NO_ROOMS;
    }
}