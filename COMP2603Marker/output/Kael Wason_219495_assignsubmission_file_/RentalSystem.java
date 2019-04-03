//Student ID - 816009413

public class RentalSystem{

    private Room[] rooms;
    private static int numRooms=0;


    public RentalSystem(){
        rooms = new Room[10];
    }

    
    public String addRoom(String name, int seatingCapacity){
       if(numRooms <= 10){
        numRooms++;
        rooms[numRooms-1] = new Room(name,seatingCapacity);
        return rooms[numRooms-1].toString();
        }else{
        return "Cannot add room; Max rooms reached.";
        }
    }
    
    public String  getRoomList(){
        String details="";
        if(numRooms==0){
            return "No rooms in the system.";
        }else{
            for(int i = 0; i<numRooms; i++){
                details += rooms[i].getRoomID() + " | ";
            }
            return details;
        }
    }
    
    public String addBooking(String description, int duration, int numSeating){
        String response = null;
        int i = 0;
        while(response == null && i<=numRooms){
            response = rooms[i].addBooking(description,duration,numSeating);
            i++;
        }
        
        
        if(response == null){
            return "Cannot add Booking";
        }else{
            return response;
        }
    }
    
    public String getBooking(int bookingID){
        String res = "Booking with that ID does not exist";
        int i = 0;
        while(i<numRooms && res.equals("Booking with that ID does not exist")){
            res = rooms[i].getBookingDetails(bookingID);
            i++;
        }
        
        if(res.equals("Booking with that ID does not exist")){
         return "Booking ID not found";
        }else{
            return res;
        }
    }
    
    public String getBookingsByRoom(String roomID){
        String bookingList ="";
        String roomToCompare;
        boolean found = false;
        int i = 0;
        while(!found && i <numRooms){
            roomToCompare = rooms[i].getRoomID();
            if(roomID.equals(roomToCompare)){
                found = true;
                bookingList += rooms[i].getBookingList();
            }
            i++;
        }
        
        if(!found){
            return "Room ID not found";
        }
        
        return bookingList;
    }
    
    public String getBookingGrid(){
        String grid = "";
        if(numRooms == 0){
            return "No rooms in the system.";
        }
        
        for(int i= 0 ; i < numRooms ; i++){
            grid+= rooms[i].getDetailedBookingGrid();
        }
        
        return grid;
    }
}
