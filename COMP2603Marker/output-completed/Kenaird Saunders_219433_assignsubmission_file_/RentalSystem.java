//816008473 Kenaird Saunders
public class RentalSystem
{
    private Room[] rooms;
    private int numRooms;
    
    RentalSystem(){
        rooms = new Room[10];
        numRooms = 0;
        int i=0;
    }
    
    String addRoom(String name, int seatingCapacity){
        String details = "";
        if(numRooms >= 9){
            return "Cannot add room; Max rooms reached."; 
        }else{
            Room newRoom = new Room(name, seatingCapacity);
            rooms[numRooms] = newRoom;
            numRooms++;
       }
       return details = rooms[numRooms-1].toString();
    }
    
    String getRoomList(){
        String details = "";
        if(numRooms ==0){
            System.out.println("No rooms in the system.");
        }else{
            System.out.println("List of rooms is system:" );
            for (int i = 0; i < numRooms; i++){
                details = details + rooms[i].toString();
            }
        }
        return details;
    }
    
    String addBooking(String description, int duration, int numSeating){
        int i=0;
        boolean found = false;
        if(numRooms>9){
            return "Cannot add booking. ";
        }else{
            while(i<=numRooms && found == false){
                if(rooms[i].addBooking(description, duration, numSeating) == null){
                    i++;
            }else{
                found = true;
                return "\nBooking added successfully";
            }
            i++;
           }
        }
        return "\nNo room available.";
       }
    // public String getBooking(int bookingID){
        // String details = "";
        // for(int x =0; x<10; x++){
          // if (rooms[x].getBookingID() == bookingID){
              // details = rooms[x].roomID.getBookingDetails(bookingID);
        // }
    // }
    // return details;
 // }
 
}