//816005390
public class RentalSystem{
    private Room[] rooms;
    private int numRooms;
    private int maxRooms;
    
    public RentalSystem(){
        this.numRooms = 0;
        this.maxRooms = 10;
        this.rooms = new Room[maxRooms];
    }
    
    public String addRoom(String name, int seatingCapacity){
        if(this.numRooms < this.maxRooms){
            this.rooms[this.numRooms] = new Room (name, seatingCapacity);
            this.numRooms ++;
            return "\nRoom ID: " + name + ". Capacity: " + seatingCapacity + " has been added.\n";
        }
        return "Cannot add room: Max rooms reached.\n";
    }
        
    public String getRoomList(){ 
        int i;
        String roomDetails = "";

        if(this.numRooms > 0 && this.numRooms < this.maxRooms){
            for (i=0; i<this.maxRooms; i++) {// check if rooms[i] is empty
                if(this.rooms[i] != null) {
                    roomDetails += this.rooms[i].toString() + "\n";
                }
            }
            return roomDetails;
        }
        return "No rooms in the system.";
    }
    
    public String addBooking(String description, int duration, int numSeating){
        int roomCount = 0;
        Room[] roomBookings = new Room[8];
        int[] roomDurations = new int[8];
        int roomDuration;
        int i;
        int num;
        String result = "";
        for(i = 0; i < this.maxRooms; ++i) {
            if(this.rooms[i] != null) {
                //System.out.println(this.rooms[i].canFitTime(duration) + " " + this.rooms[i].canFitNumbers(numSeating)); //debugging
                num = duration > 8 ? 8 : duration;
                if(duration > 0 && this.rooms[i].canFitTime(num) && this.rooms[i].canFitNumbers(numSeating)) { // && this.rooms[i].canFitTime(duration)
                    roomBookings[roomCount] = this.rooms[i];
                    if(duration > (this.rooms[i].getTimeSlots() - this.rooms[i].getNumSlots())) {
                        roomDuration = this.rooms[i].getTimeSlots() - this.rooms[i].getNumSlots();
                    }
                    else {
                        roomDuration = duration;
                    }
                    roomDurations[roomCount] = roomDuration;
                    duration -= roomDuration;
                    roomCount++;
                }
            }
        }
        for(i = 0; i < roomCount; ++i) {
            if(roomBookings[i] != null && roomDurations[i] > 0) {
                System.out.println("Adding booking at index " + i + ". duration: " + roomDurations[i]);
                result += roomBookings[i].addBooking(description, roomDurations[i], numSeating);
            }
        }
        if(result != "") {
            return result;
        }
        return "Cannot add booking. \n";
    }
    
    public String getBooking(int bookingID){
        int i;
        for(i = 0; i < this.maxRooms; ++i) {
            if(this.rooms[i] != null) {
                if(rooms[i].hasBooking(bookingID)) {
                    return this.rooms[i].getBookingDetails(bookingID);
                }
            }
        }
        return "No booking. \n";
    }

    public String getBookingsByRoom(String roomID){
        int i;
        for(i = 0; i < this.maxRooms; ++i) {
            if(this.rooms[i] != null) {
                if(this.rooms[i].roomID.equals(roomID)) {
                    return this.rooms[i].getBookingList();
                }
            }
        }
        return "Room ID not found. \n";
    }

    public String getBookingGrid() {
        int i;
        String bookingGrid = "";
        for(i = 0; i < this.maxRooms; ++i) {
            if(this.rooms[i] != null) {
                bookingGrid += this.rooms[i].getRoomID() +": " + rooms[i].getDetailedBookingGrid() + "\n";
                //return bookingGrid;
            }            
        }
        if(bookingGrid.equals(""))
            bookingGrid = "No rooms in the system. \n"; 
        return bookingGrid;
    }
}