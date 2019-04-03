public class RentalSystem{
    public Room[] rooms;
    public int numRooms;
    
    public int getNumRooms(){
        return numRooms;
    }
    
    public RentalSystem(){
        numRooms = 0;
        rooms = new Room[10];
        
    }
    public String addRoom(String name, int seatingCapacity){
        if(this.rooms[10]!=null) return "Cannot add room; Max rooms reached";
        if(this.numRooms<10){
            Room r = new Room(name,seatingCapacity);
            String details = "Rooms added to schedule:" + r.toString();
            while(this.numRooms<=10){
                this.rooms[numRooms] = r;
                numRooms ++;
            }
            return details;
        }
        return null;
    }
    public String getRoomList(){
        return null;
    }
    public String addBooking(String description, int duration, int numSeating){
        return null;
    }
    public String getBooking(int bookingID){
        return null;
    }
    public String getBookingsByRoom(String roomID){
        return null;
    }
    public String getBookingGrid(){
        return null;
    }
    
    public static void main(String[] args){
        Room r1 = new Room("FST", 100);
       // r1.addRoom("FTS",100);
    }
}