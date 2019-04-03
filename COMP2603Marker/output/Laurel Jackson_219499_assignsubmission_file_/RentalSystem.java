/*
 * Student ID - 816004212
 */
public class RentalSystem
{
    // instance variables
    private static int numRooms = 0;
    private Room [] rooms;
    private Room r;

    /**
     * Constructor for objects of class RentalSystem
     */
    public RentalSystem(){  
        rooms = new Room [10];
    }

    public String addRoom(String name, int seatingCapacity){
        if (numRooms >= 10)
            return "Cannot add room: Max rooms reached \n";
        else{
            Room tempRoom = new Room(name,seatingCapacity);
            rooms[numRooms] = tempRoom; 
            numRooms += 1;
            return tempRoom.toString() + "\n";
        }
    }
    
    public String getRoomList(){
        String details = "";
        
        if(rooms[0] == null)
            return("No rooms in the system \n");
        for (int i=0;i<numRooms;i++){
            details += rooms[i].toString() + "\n"; 
        }
        return details;
    }
    
    public String addBooking(String description, int duration, int numSeating){
        int count = 0;
        String check ="";
       
        for(int t=0;t<numRooms;t++){
            
            //once a room has enough time and numbers, a booking will be added
            if(rooms[t].canFitNumbers(numSeating) && rooms[t].canFitTime(duration)){
                check = rooms[t].addBooking(description,duration,numSeating);
                return ("Booking successfully added to schedule: \n" + check + "\n");
            }
        }
        
        //if the for loop ends with adding a booking, an appropriate statement is returned
        return ("Cannot add Booking \n");
    }
    
    // the getBookingDetails() method from the Room class is called. Once the detail variable is not null, it is return else the bookingID was not found
        
    public String getBooking(int bookingID){
        String detail="";
        
        for (int i=0;i<numRooms;i++){
            detail = rooms[i].getBookingDetails(bookingID); 
            if (detail != null)
                return detail + "\n";    
        }
        return("Booking ID: " + bookingID + " not found. \n") ;
    }
    
    public String getBookingsByRoom(String roomID){
        String id;
        String details = "";
        for (int i=0;i<numRooms;i++){
            id = rooms[i].getRoomID();
            if(id.equals(roomID)){
                details = rooms[i].getBookingList();
                return (rooms[i].toString() + "\n" + details + "\n");
            }
        }
        return "Room ID not found\n";
    }
    
    public String getBookingGrid(){
        int count = 0;
        String details="BOOKING GRID\n";
         
        if(rooms[0] == null) //if the first room is empty, this means there is no rooms made
            return "No rooms in the system\n";
        
        
        for(int t=0;t<numRooms;t++){
           details += rooms[t].getDetailedBookingGrid() + "\n";
        }
        
        return details + "\n";
        
    }
    
}
