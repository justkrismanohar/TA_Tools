 /**
 * 816009808
 *
 * 
 * 
 */
public class RentalSystem
{
     private Room[] rooms;
     private static int numRooms=10;
     private int roomCounter=0;
     
     public RentalSystem()
     {
         rooms = new Room[numRooms];
         
     }
     
     public String addRoom( String name, int seatingCapacity)
     {
         String details = "Max room capacity reached room cannot be created";
         if (roomCounter < numRooms)
         {
             rooms[roomCounter]=new Room(name,seatingCapacity);
             details ="Your Room ID: "+rooms[roomCounter].getRoomID()+" Seating Capacity: "+seatingCapacity;             
             roomCounter++;
             return details;
         }
         
         return details;
     }
    
    public String getRoomList() 
    {
        String details="No rooms in System";
        if (roomCounter == 0)
              {                 
                  return details;
              }
               else
                {
                    details="";
                    for (int i=0; i<roomCounter; i++)
                    {
                        if(rooms[i]==null)
                        break;
                        
                        details +="Room ID: "+rooms[i].getRoomID()+"   Seating Capacity: "+rooms[i].getSeatingCapacity()+"\n";
                       
                    }
                     return details; 
                }     
      
    }
    
    public String addBooking(String description,int duration,int seats)
     {
         String message = " Booking cannot be added";
         for (int i=0;i<roomCounter;i++)
         {
             if(rooms[i].canFitTime(duration) && rooms[i].canFitNumbers(seats))
             {
                message= rooms[i].addBooking(description,duration,seats); 
                return message;
            }
         }
         return message;
      }
                 

    public String getBooking(int bookingID)
    {        
        String details = "No Booking with that ID";
        for (int i=0;i<roomCounter;i++)
        {            
            if(rooms[i].hasBooking(bookingID))
            {   
                details="";
                details += rooms[i].getBookingDetails(bookingID);
                return details;
            }
            if(rooms[i].equals(null))
            return details;
        }
        return details;
    
    }
    
    public String getBookingsByRoom(String roomID)
    {
        String message = " No Room with that ID ";
        
        
        for(int i = 0 ; i < numRooms ; i ++)
        {
           if(rooms[i]==null)
           break;

            if(rooms[i].getRoomID().equals(roomID))
            {   
               message =rooms[i].getBookingList();              
               return message;
            }
             
        }
        return message;
    }
    
    public String getBookingGrid()
    {
        String message=" No rooms in system";
        
            if(roomCounter==0)
               return message;
                
            message="";
            for(int i=0;i<6;i++)
            {

                message += rooms[i].getDetailedBookingGrid()+"\n";
                return message;
            }
           return message;
    } 
}
