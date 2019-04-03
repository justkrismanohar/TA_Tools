
public class RentalSystem{
    //private Room[] rooms;
    private int numRooms;
    private static Room[] rooms;
    //constructor
    public RentalSystem(){
        rooms = new Room[10];
        numRooms = 0;
    }
    
    public int getNumRooms(){
        return numRooms;
    }
    
    public String addRoom(String name, int seatingCapacity){
        if(numRooms < rooms.length){
            Room room = new Room(name, seatingCapacity);
            rooms[numRooms] = room;
            String details = rooms[numRooms].toString();
            numRooms = numRooms + 1;
            return details;
        }
       
        return "Unable to add room, max rooms reached";
    }
    
    public String getRoomList(){
        String list = "";
        if(numRooms == 0)
        return "No rooms in the system";
        
        for(int i = 0; i < numRooms; i++)
            list += rooms[i] +"\n";
        return list;
    }
    
    public String addBooking(String description, int duration, int numSeating){
        int i = 0;
        while(i < rooms.length){
            if(rooms[i].canFitNumbers(numSeating) && rooms[i].canFitTime(duration)){
                rooms[i].addBooking(description, duration, numSeating);
                i++;
                return "Your booking has been successfully added!";
               
            }
            return "Sorry, cannot add booking";
        }
        return "Sorry, cannot add booking";
    }
    
    public String getBooking(int bookingID){
        int i = 0;
        String p = "";
        while(i < numRooms){
            if( rooms[i].hasBooking(bookingID))
                p = p + rooms[i].getBookingDetails(bookingID);
                
            else 
                p = "Booking ID not found";
        }
        return p;
    }
    
    public String getBookingByRoom(String roomID){
        String p = "";
            for(int r = 0; r < rooms.length; r++){
                if(rooms[r] == null)
                    break;
                
                if(rooms[r].getRoomID().equals(roomID)){
                    p += (rooms[r].getBookingList());
                return p;
                }
            }
        return "Room ID not found";
    }
    
    public String getBookingGrid(){
        String p = "";
        int i = 0;
        while(i < numRooms){
            String detailedGrid = rooms[i].getRoomID() + rooms[i].getDetailedBookingGrid();
            p += detailedGrid +"\n";
            i++;
        }
        return p;
    }
}
