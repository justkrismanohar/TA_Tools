/*
 * Student ID: 816004003
 * Name: Keanu Nichols
*/
public class RentalSystem{
    //Attributes
    private Room[] rooms;
    private int numRooms;
    
    //Constructor
    public void RentalSystem(){
        this.rooms = new Room[10];
        this.numRooms = 0;
    }
    
    //Methods
    public String addRoom(String name, int seatingCapacity){
        if(numRooms == 10){
            return("Cannot add room; Max rooms reached\n");
        }
        rooms[numRooms] = new Room(name,seatingCapacity);
        numRooms++;
        return (rooms[numRooms-1].toString());
    }
    
    public String getRoomList(){
        boolean val = false;
        String details = "";
        for(int i=0; i<rooms.length; i++){
            if(rooms[i] != null){
                val = true;
                details+=rooms[i].toString();
            }
        }
        if(!val){
            return("No rooms in the system");
        }
        return details;
    }
    
    public String addBooking(String description, int duration, int numSeating){
        String details;
        for(int i=0; i<rooms.length; i++){
            if(rooms[i] != null){
                details = rooms[i].addBooking(description,duration,numSeating);
                if(details != null)
                    return details;               
            }
            //System.out.println("Going");
        }
        return("Cannot add Booking\n");
    }
    
    public String getBooking(int bookingID){
        String details = "";
        boolean val = false;
        for(int i=0; i<rooms.length; i++){
            if(rooms[i] != null && rooms[i].hasBooking(bookingID)){
                details +=rooms[i].getBookingDetails(bookingID);
                val = true;
            }
        }
        if(!val)
            return("Booking ID not found\n");
        return details;
    }
    
    
    public String getBookingsByRoom(String roomID){
        for(int i=0; i<rooms.length; i++){
            if(rooms[i] != null && rooms[i].getRoomID().equals(roomID)){
                System.out.println(rooms[i].toString());
                return(rooms[i].getBookingList());
            }
        }
        return("Room ID not found\n");
    }
    
    public String getBookingGrid(){
        String details = "";
        boolean val = false;
        for(int i=0; i<rooms.length; i++){
            if(rooms[i] != null){
                details += rooms[i].getDetailedBookingGrid();
                val = true;
            }
            details+="\n";
        }
        
        if(!val){
            return("No rooms in the system");
        }
        return details;
    }
}