
public class RentalSystem 
{
    
    private Room[] rooms = new Room[10];
    private int numRooms = 0 ;

    
    public RentalSystem(){}
    
    public String addRoom(String name, int seatingCapacity)
    {
        String output;
       if (numRooms == 10) output = " Max rooms reached.";
       if (numRooms < 10){
        Room r = new Room(name, seatingCapacity);
        rooms[numRooms] = r;
        numRooms++;
       }
       output = " Room successfully added.";
       return output;
    }

  
    public String getRoomList( )
    {
      String output=null;
      int i = 0;
      int j = 1;
      if (numRooms == 0) output = "No rooms added.\n";
      while (rooms[i] != null) 
      {
          output += "Room " + j + ": " + rooms[i].roomID + ".\n";
          i++;
          j++;
         }
      return output;   
    }
    
    public String addBooking(String description,int duration, int numSeating) 
    {
     int i = 0;
     String output=null;
     if (i == 10) output = " Unable to add Booking."; 
     while (i < 10)
     {
         
      if(rooms[i].canFitNumbers(numSeating) &&  rooms[i].canFitTime(duration))
      {
       return rooms[i].addBooking(description, duration, numSeating) ;
         }
      else if(!rooms[i].canFitNumbers(numSeating)) 
       { 
        output = " Unable to add Booking.";
        i++;
        }
      else if(!rooms[i].canFitTime(duration)) 
       { 
        output = " Unable to add Booking.";
        i++;
       }
      }
     return output; 
    }
    
    public String getBooking(int bookingID) 
    { String output=null;
      int i = 0;
      if(rooms[i].hasBooking(bookingID)) return rooms[i].getBookingDetails(bookingID) ;  
      while(!rooms[i].hasBooking(bookingID))
      {
       output = "Booking not found";
       i++;
       }
       return output;
    }
    
    public String getBookingsByRoom(String roomID) 
    {
     String output = null;
     int i=0;
     if (rooms[0]==null) return output = "No rooms in system";
     if (rooms[i].roomID==roomID) output = rooms[i].getBookingList();
     while (rooms[i].roomID!=roomID && i<10)
     {
      output = "Room not found\n";
      i++;
      }
      return output;
    }
    
    public String getBookingGrid( ) 
    {
     String output = null;
     int i = 0;
     if (rooms[0]==null) return output = "No rooms in system";
     while(i<10)
     {
      output += rooms[i].getDetailedBookingGrid( ); 
      if (rooms[i].numSlots<8)
      {
       output += " " + (8-rooms[i].numSlots) + "Hours free\n";  
        }
        }
     return output;   
    }
}
