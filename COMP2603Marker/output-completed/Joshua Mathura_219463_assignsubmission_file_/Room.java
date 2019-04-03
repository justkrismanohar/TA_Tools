//816010691

public class Room{
    private static final String ERROR_BOOKING_ID_NOT_FOUND = "Booking ID not found.";
    private static final String ERROR_NO_BOOKINGS_FOUND = "No bookings have been made for this room.";
    private int numSlotsUsed; //The current number of time slots used for which the Room has been booked
    private static final int NUMSLOTS = 8;
    private static int roomIDCounter = 100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    
    private void setRoomID(String name){
        this.roomID = name + roomIDCounter;
        roomIDCounter += 100;
    }
    
    private void setSeatingCapacity(int seatingCapacity){
        this.seatingCapacity = seatingCapacity;
    }
    
    public int getSeatingCapacity(){
        return seatingCapacity;
    }
    
    public Room(String name, int seatingCapacity){
        numSlotsUsed = 0;
        setRoomID(name);
        setSeatingCapacity(seatingCapacity);
        bookings = new Booking[NUMSLOTS];
    }
    
    public String addBooking(String description, int duration, int seats){
        if (canFitTime(duration) && canFitNumbers(seats)){
            bookings[numSlotsUsed] = new Booking(description, duration, seats);
            bookings[numSlotsUsed].setLocation(roomID);
            for (int i = 1; i < duration; ++i)
                bookings[i + numSlotsUsed] = bookings[numSlotsUsed];
            int temp = numSlotsUsed;
            numSlotsUsed += duration;
            return "Booking added to schedule:\n" + bookings[temp].toString();
        }
        return null;
    }
    
    private boolean canFitNumbers(int numSeats){
        return (numSeats <= getSeatingCapacity()) ? true : false;
    }
    
    private boolean canFitTime(int duration){
        return ((duration > NUMSLOTS) || ((duration + numSlotsUsed) > NUMSLOTS)) ? false : true;
    }
    
    public String getBookingDetails(int bookingID){
        int i = -1;

        while ((++i < NUMSLOTS) && (bookings[i] != null))
            if (bookings[i].getBookingID() == bookingID)
                return bookings[i].toString();            
        return ERROR_BOOKING_ID_NOT_FOUND;
    }
    
    public String getBookingList(){
        StringBuilder roomBookings = new StringBuilder('\n');
        int i = -1;

        while ((++i < NUMSLOTS) && (bookings[i] != null))
            roomBookings.append('\n' + bookings[i].toString());
        if (i == 0)
            return ERROR_NO_BOOKINGS_FOUND;
        return roomBookings.toString();
    }
    
    public String getDetailedBookingGrid(){
        StringBuilder roomGrid = new StringBuilder(getRoomID() + ((getRoomID().length() < 7) ? " |" : '|'));
        int i = -1;
        
        while ((++i < NUMSLOTS) && (bookings[i] != null))
            roomGrid.append("  " + bookings[i].getBookingID() + ((bookings[i].getBookingID() < 10) ? "  " : ' ') + '|');
        while (i++ < NUMSLOTS)
            roomGrid.append("     |");
        return roomGrid.toString();
    }
    
    public String getRoomID(){
        return roomID;
    }
    
    public boolean hasBooking(int bookingID){
        int x = -1;
        while ((++x < NUMSLOTS) && (bookings[x] != null))
            if (bookings[x].getBookingID() == bookingID)
                return true;
        return false;
    }
    
    public String toString(){
        return "ROOM ID: " + getRoomID() + "  SEATS: " + getSeatingCapacity();
    }
}