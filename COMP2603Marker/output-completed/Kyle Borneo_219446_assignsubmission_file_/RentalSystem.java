/*
 * Kyle Borneo 
 * 815006227
 * Assignment One 
 * 18/02/19
 */

public class RentalSystem{
    int numRooms;
    Room [] rooms = new Room[10];

    public RentalSystem(){
        numRooms=0;
    }
    
    String addRoom(String name, int seatingCapacity){
        String s="";
        Room r = new Room(name, seatingCapacity);
        System.out.println("Option 1");
        if(numRooms >=10)
            s="Cannot add room.Max rooms reached.\n";
        else{
            rooms[numRooms] = r;
            numRooms++;
            s = "Room successfully added.\n";
        }
        return s;
    }
    
    
    String getRoomList(){
        String s="";
        if(numRooms == 0)
            s="No rooms in system.";
        else
            for(int i=0; i<numRooms; i++)
                s += rooms[i].toString();  
        return s;
    }
     
    
    String addBooking(String description, int duration, int numSeating){
        String s = "";
        boolean found  = false;
        int i = 0;
        
        while(!found && i <= numRooms-1){
            Room room = rooms[i];
            if(room.canFitTime(duration) && room.canFitNumbers(numSeating)){
                room.addBooking(description, duration, numSeating);
                s = "Booking sucessfully made";
                found = true;
            }
           i++;
        }
        if(!found)
            s = "Cannot add Booking";
        return s;   
    }
    
    String getBooking(int bookingID){
        String s = "RoomID not found";
        for(int i =0; i< numRooms; i++){
            for(int j=0; j< rooms[i].getNumBookings();j++){
            if(rooms[i].booking[j].get_bookingID()== bookingID){
                
                s= rooms[i].booking[j].toString();
            }
        }
            
        }
        return s;
    }
    
    
    String getBookingsByRoom(String roomID){
        String s ="";
        for(int i=0; i< numRooms; i++){
            if(rooms[i].getRoomID().compareTo(roomID) == 0){ 
                Room r = rooms[i];
                s = r.getBookingList();
                System.out.println(s);
        }
    }
        return s;
    }
    
    
    String getBookingGrid(){
        String s = "";
        //return s;
        for(int i=0; i< numRooms; i++){
            s = rooms[i].getRoomID()+ "|";
            s = s + rooms[i].getDetailedBookingGrid()+"\n";
        }
        return s;  
    }
}
