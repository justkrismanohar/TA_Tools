//816008254
public class RentalSystem{
    private Room[] rooms;
    private int numRooms;
    static private int roomIndex;

    public RentalSystem(){
           numRooms = 10;
           rooms = new Room[numRooms];
           roomIndex = 0;
    }   
    
   //addRoom Method
   public String addRoom(String name, int seatingCapacity){
       if(roomIndex < numRooms){
           name=name.toUpperCase();
           Room r = new Room(name,seatingCapacity);
           rooms[roomIndex]=r;
           roomIndex++;
           return "\nRoom: " + name.toUpperCase() + " RoomID: " + r.getRoomID() + " Seats: " + seatingCapacity;
       }
       else 
           return "\nCannot add room; Max rooms reached.";
    }
    
    public String getRoomList(){
        String output= "";
        if(roomIndex==0 ){
            return "No rooms in the system";
        }
        for(int i=0; i<roomIndex; i++){
          output = output + rooms[i].getRoomID() + "\n";
       }
        return output;
        //returns a list of all rooms managed by the system
   // return "No rooms in the system.";
    }
  
    public String addBooking(String description, int duration, int numSeating){
        int firstRoom=findAccomodation(duration, numSeating);
        if(firstRoom==-1)
            return "Cannot add Booking. ";
        else 
            return rooms[firstRoom].addBooking(description, duration, numSeating);
           
    }
    
    private int findAccomodation(int duration, int numSeating){
        for(int i=0; i<roomIndex; i++){
            if((rooms[i].canFitTime(duration)==true) && (rooms[i].canFitNumbers(numSeating)==true))
                return i;
        }
        return -1;
    }

   public String getBooking(int bookingID){
        for(int x=0; x<roomIndex; x++){
           if(rooms[x].hasBooking(bookingID))
                return rooms[x].getBookingDetails(bookingID);
        }
        return "Booking ID not found";
    }
    
   
   public String getBookingsByRoom(String roomID){
       String output="", final_output=" ";
       //need to check if roomID is found first
       for(int i=0; i<numRooms; i++)
           if(rooms[i].getRoomID().equals(roomID)){
                for(int x=0; x<8; x++){
                    output=getBooking(x);
                    final_output=final_output + output;
                }
              return final_output;
            }
       return "Room ID cannot be found";
    }
   
   public String getBookingGrid(){
       if(roomIndex==0)
       return "No rooms in system";
       String output="", final_output="";
       for(int i=0; i<numRooms; i++){
           output=rooms[i].getDetailedBookingGrid();
           final_output=final_output + output +"\n";
       }
       return final_output;
   }
   


}