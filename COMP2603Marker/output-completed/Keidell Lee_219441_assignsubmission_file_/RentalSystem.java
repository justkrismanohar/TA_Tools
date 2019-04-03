// 816009809

public class RentalSystem{
    private Room[] rooms;
    private static int numRooms;
    
    public RentalSystem(){
        rooms = new Room[10];
        numRooms = 0;
    }
    
    public String addRoom(String name, int seatingCapacity){
        if(numRooms < 10){
            String message;
            Room r = new Room(name,seatingCapacity);
            rooms[numRooms] = r;
            message = "Room name: " + rooms[numRooms].getRoomID() + " Seating Capacity: " + seatingCapacity;
            numRooms++;
            return message;
            
    }
    return "Cannot add room; Max rooms reached.";        
    }
    
    public String getRoomList(){
        String message ="";        
        int i;
        for(i=0;i< numRooms;i++){
             message += rooms[i] + "\n";                       
             } 
             return message;               
               
    }
    
    public int getNumRooms(){
        return numRooms;
    }
    
    public String addBooking(String description, int duration, int numSeating){
        for(int i=0;i<rooms.length;i++){
            if(rooms[i].canFitTime(duration) && rooms[i].canFitNumbers(numSeating)){    
                rooms[i].addBooking(description,duration,numSeating);
                return "Booking added to " +rooms[i].getRoomID();
        }
    }
        return "Cannot add Booking";
    }
    
    public String getBooking(int bookingID){
        String s = "";
        for(int i=0;i<numRooms;i++){
            if(rooms[i].hasBooking(bookingID))
                s += rooms[i].getBookingDetails(bookingID);
        }
        return s;
        
    }
    
    public String getBookingByRoom(String roomID){
        String s="";
        for(int i=0;i<10;i++){
            
            if(rooms[i] == null)
            break;
            
            
            if(rooms[i].getRoomID().equals(roomID)){
            s+= (rooms[i].getBookingList());  
            return s;
        }
            
        }
        return "No rooms";
    }
    
    public String getBookingGrid(){
        String s= "";
        for(int i =0;i<numRooms;i++){
            s += rooms[i].getRoomID() +rooms[i].getDetailedBookingGrid() + "\n";
        }
        return s;
    }
    
    
}
