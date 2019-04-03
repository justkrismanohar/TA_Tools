//Kerron Patram
//816003101

//RentalSystem class defining a RentalSystem object.
public class RentalSystem
{
    //declaration of attributes of RentalSystem class
    private Room[] rooms;
    private int numrooms;
    
    //constructor for RentalSystem
    public RentalSystem()
    {
        this.rooms= new Room[10];
        this.numrooms=0;
    }
    
    //Adds a room to the system once there is availability for an addition
    public String addRoom(String name, int seatingCapacity)
    {
        
        if(numrooms<10){
            
           Room room= new Room(name, seatingCapacity); 
           rooms[numrooms]=room;
           numrooms++;
           return rooms[numrooms-1].toString();
   
        }
           return "Cannot add room, maximum number of rooms reached";
    }
   
    //Returns a string of all valid rooms in the system
    public String getRoomlist()
    {
      String list="";
      for(int i=0; i<numrooms; i++){
          
          list+=rooms[i].toString();
      
      }
       if(list.equals("")){
        return "No rooms in system";
       }
      return list;
    } 
 
    //Adds a booking to the system
    public String addBooking(String type, int period, int numSeating)
    {
      if(numrooms>0)
      {
         for(int i=0; i<numrooms; i++){
             String A=rooms[i].addBooking(type, period, numSeating);
             if(A!=null)
             {
                 return A;
             }
         }
      }
      return"Invaid data!!! Cannot add Booking";
    }

    //Returns a string containing details of a room based on bookingID
    public String getBooking(int bookingID)
    {
       if(numrooms>0){
           for(int i=0; i<numrooms; i++){
              if(rooms[i].hasBooking(bookingID)){
                  return rooms[i].getBookingDetails(bookingID);
                }              
            }       
        }
        return"Booking ID not found";
    }
    
    //Returns a string containing details of bookings based on roomID
    public String getBookingsByRoom(String roomID)
    {
        if(numrooms>0){
            for(int i=0; i<numrooms; i++){
                if(rooms[i].getRoomID().equals(roomID)){
                    return rooms[i].getBookingList();
                }
            }
            
        }

        return " Room ID not found";
    }
    
    //Displays a grid containing valid bookings with the respective Room Names and Booking IDs
    public String getBookingGrid()
    {
        String grid="";
        if(numrooms>0){
            for(int i=0; i<numrooms; i++){
                grid+= rooms[i].getDetailedBookingGrid();
            }
        
            return grid;
        
        
        }
        return"No rooms in the system";
    
    }   

}