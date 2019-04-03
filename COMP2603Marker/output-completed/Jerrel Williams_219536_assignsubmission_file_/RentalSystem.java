
public class RentalSystem
{
    /*ID: 816009134*/

    private Room[] rooms = new Room[9];
    private int numRooms;

 
    public RentalSystem()
    {
       
        numRooms = 0;
    }
    
    public String addRoom(String name, int seatingCapacity){
        if(numRooms == 9)
            return("Max rooms reached");
        
        rooms[numRooms] = new Room(name, seatingCapacity);
        String msg = rooms[numRooms].toString();
        numRooms += 1;
        
        return("Room successfully added to schedule.\n" + msg + "\n");       
    }
    
    public String getRoomList(){
        if(null == rooms[0])
            return("No rooms in the system");
            
        StringBuilder roomList= new StringBuilder();
        roomList.append("Rooms managed by the system: ");
        for(int i=0; i<numRooms; i++){
            roomList.append("\n" + rooms[i].roomID);
        }
        return(roomList.toString());
    }
    
    public String addBooking(String description, int duration, int numSeating){
        int loc;
        for(int i=0; i<numRooms; i++)
        {
            if(rooms[i].canFitNumbers(numSeating) && rooms[i].canFitTime(duration))
            {
                
                String msg = rooms[i].addBooking(description, duration, numSeating);
                return(msg + "\n");
                
            }
           
        }
      return("Cannot create booking");
    }
  
    public String getBooking(int bookingID)
    {
        String queryResult = "No booking found";
        for(int i=0; i<numRooms; i++)
        { 
           if(rooms[i].hasBooking(bookingID))
           {
               queryResult = rooms[i].getBookingDetails(bookingID);
              
           }
            
        }
      return(queryResult);
    }
    
    public String getBookingsByRoom(String roomID)
    {
        String queryResult="No Room found";
        for(int i=0; i<numRooms; i++)
        {
            if(this.rooms[i].roomID.equals(roomID))
            {
                queryResult=rooms[i].getBookList();
            }
            
        }
       return queryResult;
    }
    
    public String getBookingGrid()
    {
        if(null == rooms[0])
            return("No rooms in the system");
        
        StringBuilder sysGrid = new StringBuilder();
        for(int i=0; i<numRooms; i++)
        {
            sysGrid.append("\n" + rooms[i].roomID + rooms[i].getDetailedBookingGrid());
            
  
        }
       return(sysGrid.toString());    
    }
    
    
}

