//andrez Bravo 816011156
public class RentalSystem
{
    private Room[] rooms;
    private int numRooms;
    public RentalSystem()
    {
        rooms=new Room[10];
        numRooms=0;
    }
    
    public String addRoom(String name, int seatingCapacity)
    {
       if(numRooms!=10){
          rooms[numRooms]=new Room(name,seatingCapacity);
          numRooms+=1;
          return "Name:" + name + " Seating Capacity: " + seatingCapacity;
        }
        else
        return "Cannot add room;Max rooms reached.";
       
    }
    public String getRoomList(){
       if(numRooms!=0){
         for (int i=0;i<numRooms;i++){
            System.out.println(rooms[i].toString());
            }
            return "";
        }
        else 
        return "No rooms in the system";
    }
    
    public String addBooking(String description,int duration, int numSeating)
    {
      for (int i=0;i<numRooms;i++){
          if(rooms[i].canFitTime(duration) && rooms[i].canFitNumbers(numSeating))
          {
              return rooms[i].addBooking(description,duration,numSeating);
               
            }
        }
        return "Cannot add booking";
       
    }
    
    public String getBooking(int bookingID){
        for(int i=0;i<numRooms;i++){
          
         if(rooms[i].hasBooking(bookingID)){
             return rooms[i].getBookingDetails(bookingID);
            }
        }
        return "Booking ID not found";
    }
        
    public String getBookingsByRoom(String roomID)
        {
            for (int i=0;i<numRooms;i++)
            {
                if(rooms[i].getRoomID().equals(roomID)){
                    return rooms[i].getBookingList();
                    
                }
            }
            return "Room ID not found";
        }
        
     public String  getBookingGrid(){
         if(numRooms==0)
         return "No rooms in the system.";
         
         for(int i=0;i<numRooms;i++)
         {
             System.out.println(rooms[i].getDetailedBookingGrid());
            }
           return "";
        }
}
