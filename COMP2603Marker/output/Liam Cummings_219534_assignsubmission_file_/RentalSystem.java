public class RentalSystem
{
    //ID - 816003418
    public Room[] rooms = new Room[10];
    public static int numRooms = 0;
    
    public RentalSystem(){
        
    }
    
    public String addRoom(String name, int seatingCapacity){
        String details = "";
        
        if(numRooms < 10){
               rooms[numRooms] = new Room(name, seatingCapacity);
              
               details = "Room Added: " + rooms[numRooms].getRoomID() + 
               "\nSeating Capacity: " + seatingCapacity; 
               numRooms ++;
        } 
        
        else{
                details = "Cannot add room. Max rooms reached";
        }
            
        return details;
    }
   
    public String getRoomList(){
        String details = "";
        if(numRooms > 0){
            for(int i = 0; i < numRooms; i++){
                details = details + rooms[i].toString() + "\n";
            }
        }
        
        else{
            details = "No rooms in the system";
        }
        return details;
    }
    
    public String addBooking(String description, int duration, int numSeating){
        String details = "";
        int i = 0;
        Boolean check = false;
        while (i < numRooms || check == false){
            if(rooms[i].canFitNumbers(numSeating) == true && rooms[i].canFitTime(duration) == true){
                details = rooms[i].addBooking(description, duration, numSeating);
                check = true;
        }
            i++;
        }
        
        if(check == false){
            details = "Cannot add Booking";
        }
        
        return details;
    }
    
    public String getBooking(int bookingID){
        String details = "";
        int i = 0;
        while(i < numRooms || details == ""){
            details = rooms[i].getBookingDetails(bookingID);
            i++;
        }
        if(details.equals("")){
            details = "Booking ID not found";
        }
        
        return details;
    }
    
    public String getBookingByRoom(String roomID){
        String details = "";
        int i = 0;
        Boolean found = false;
        int loc = -1;
        while(i < numRooms || found == false){
            if(rooms[i].roomID.equals(roomID)){
                found = true;
                loc = i;
            } 
            i++;
        }
        if(loc != -1){
            details = rooms[loc].getBookingList();
        }
        
        else{
            details = "Room id not found";
        }
        return details;
    }
    
    public String getBookingGrid(){
        String details = "";
        for(int i = 0; i < numRooms; i++){
            details = details + rooms[i].getDetailedBookingGrid() + "\n";
        }
        
        return details;
        
    }
}
