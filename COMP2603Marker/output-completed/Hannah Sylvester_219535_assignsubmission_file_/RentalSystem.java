
/*
 * Name: HANNAH SYLVESTER
 * ID: 816007999
 */

public class RentalSystem
{
    // instance variables - replace the example below with your own
    private Room[] rooms; 
    private int numRooms;

    /**
     * Constructor for objects of class RentalSystem
     */
    public RentalSystem()
    {
        // initialise instance variables
        this.numRooms=0;
        this.rooms= new Room[10];
        
    }


    public String addRoom(String name,int seatingCapacity)
    {
        int position = -1;
        String details;
        
        for(int i=0; i < rooms.length ; i++){
            if(name.length() == 3){
                details="";
                Room temp = new Room(name,seatingCapacity);
                rooms[i]=temp;
            }
            numRooms=i;
            
            return "New room "+ rooms[i].getRoomID() +" with seating capacity " + seatingCapacity;
        }
        
        return "Addition of room failed.";    
    }
    
    public String getRoomList()
    {
        String s;
        
        for(int i=0; i < this.rooms.length; i++){
            Room tRoom = rooms[i];
            if(tRoom != null){
              s=tRoom.toString()+ "\n";
              return s;
            }
        }
        
        return "No rooms in the system.";
    }
    
    public String addBooking(String description,int duration,int numSeats)
    {
        String r="";
        int i=0;
        
        while(i<rooms.length)
       {
                    
           if(rooms[i].canFitTime(duration) && rooms[i].canFitNumbers(numSeats)){
               rooms[i].addBooking(description,duration,numSeats);
           }
           r="Booking was added to: " +rooms[i].getRoomID() ;
           
           i++;
       }
           return "Booking not added.";
    }
    
    public String getBooking(int bookingID)
    {
      String str;
      int i=0;
      
      while(i<rooms.length){
          Room r=rooms[i];
          
          if(r.hasBooking(bookingID)){
              str="";
              str= "Room: " + r.getRoomID()+ r.getBookingDetails(bookingID);
              
              return str;
            }
            i++;
        }
        return "Booking ID was not found.";
    }
    
    public int getNumRooms(){
        return numRooms;
    }
    
    public String getBookingsByRoom(String roomID)
    {
        for(int i=0; i<numRooms; i++){
            if(rooms[i].getRoomID().equals(roomID))
            return rooms[i].getBookingList();
        }
        return "Room : " + roomID + " not found.";
    }
    
    public String getBookingGrid(){
        String g="";
        int i=0;
        
        while(i<rooms.length){
            g+=rooms[i].getRoomID()+rooms[i].getDetailedBookingGrid()+"     ";
            i++;
        }
        return g;
    }
}
