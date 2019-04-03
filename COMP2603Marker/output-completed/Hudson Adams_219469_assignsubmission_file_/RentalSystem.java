import java.util.Scanner;
/**
     * @author (Hudson Adams 816001214)
     * @version (Rental System)
     */
public class RentalSystem
{
   private Room[] rooms; 
   private int numRooms; 
        
   public RentalSystem() {     
     rooms = new Room[10];
     numRooms = 0; 
   }
       
   public String addRoom (String name, int seatingCapacity) { 
           
     String addRoomResults = "Room added."; 
     
     if (numRooms >= 10) {  
          addRoomResults = ("\nCannot add room; Max rooms reached \n");
          return addRoomResults;  
     }
     
     rooms[numRooms] = new Room(name, seatingCapacity);
     System.out.println(rooms[numRooms].toString()); 
     numRooms++;
     return addRoomResults; 
   }
      
   public String getRoomList() {
       String currRoomList = "No rooms in the System"; 
       int curr = 0;    
       
       if(numRooms == 0)
          return currRoomList; 
       
       currRoomList = ""; 
       System.out.println("\nList of rooms currently managed by the system: \n");
       for (curr = 0; curr < numRooms; curr++) {             
           currRoomList += rooms[curr].toString() + "\n";
       }
       return currRoomList;
    }
   
   public String addBooking(String description, int duration, int numSeating) {
     String currBookingList = "Cannot add Booking"; 
     int curr = 0;  
     Room searchRoom = rooms[curr];

     if(numRooms ==0 )
         return currBookingList; 
         
     for (curr = 0; curr < numRooms; curr++) {
           searchRoom = rooms[curr]; 
           if (searchRoom == null) 
               return currBookingList; 
                         
           if (searchRoom.canFitNumbers(numSeating) && searchRoom.canFitTime(duration)){    
                 currBookingList = searchRoom.addBooking(description,duration,numSeating);  
                 break;
           }        
       }
       return currBookingList;  
   }
    
   public String getBooking(int bookingID) { 
       String search = "Booking ID not Found.";
       
       for (int i = 0; i<numRooms; i++) {
            
           if (rooms[i] == null)
                return search; 
           
           if (rooms[i].hasBooking(bookingID)) {
                search = rooms[i].getBookingDetails(bookingID); 
                return search; 
           }
       }
       return search; 
   }
    
   public String getBookingsByRoom(String roomID) {
     String bookingResults = "Room ID not found";
     String foundRoomID = " "; 
     int count = 0; 
     Room searchRoom = rooms[count]; 
     boolean foundRoom = false;
        
     if (searchRoom ==  null) 
         return bookingResults;  
     
     for (count = 0; count < rooms.length;  count++) {
         searchRoom = rooms[count]; 
            
         if (searchRoom == null) 
              break;  
         foundRoomID = searchRoom.getRoomID(); 
         
         if (foundRoomID.equals(roomID) && searchRoom.getNumOfBookedSlots() > 0) { // Room exits within Rooms array and has booking
             foundRoom = true;  
             bookingResults = searchRoom.getBookingList() + "\n";
         }
     }
     return bookingResults; 
   }  
   
   public String getBookingGrid() { 
       
      String grid = "No rooms in the system!";
      for (int count = 0; count < numRooms; count++) { 
            Room searchRoom = rooms[count]; 
            if (searchRoom == null)
                return grid;
            
            if (searchRoom.getDetailedBookingGrid().equals(searchRoom.getRoomID())){
                 Room foundRoom = rooms[count];
                    
                 if (rooms[count] == null) {
                      grid = foundRoom.getRoomID() + " | " + " "+ " ";
                      for (int i = 1; i< 8; i++)
                            grid += " | ";  
                      return grid;
                 }
                   
                 grid = foundRoom.getRoomID() + " | " + " " + " ";
                 for (int i = 1; i< 8; i++)
                        grid += " | "  + " " + " ";  
                    
                 if (rooms[count+1] == null) {
                     return grid;
                    }
                    
                    else {
                            System.out.println(grid); 
                 }
            } 
            else {
                grid = searchRoom.getDetailedBookingGrid(); 
                    if (rooms[count+1] == null) {
                        return grid;
                    }
                System.out.println(grid); 
            }
      } 
      return grid; 
   }
}
