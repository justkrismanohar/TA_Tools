//Hemati Sahadeo 
//816001653
//Assignment 1
//OOP
public class RentalSystem{
    private Room[] rooms;
    private static int numRooms;
    
    public RentalSystem(){
        numRooms=0;
        rooms= new Room[10]; 
    }
    
    //Adds a new Room to the system and
    //returns the details of the room if
    //successful. Otherwise a message Cannot
    //add room; Max rooms reached. is returned
    public String addRoom(String name, int seatingCapacity){
        int i=0;
        
        if(numRooms<10){
            rooms[numRooms]= new Room(name,seatingCapacity);
            numRooms++;
            return rooms[numRooms].toString();
        }
        else
            return "Cannot add room. Max rooms reached";
        
    }
    
    //Returns a list of all of the rooms managed
//by the system if any, or otherwise a
//message No rooms in the system. is
//returned
    public String getRoomList(){
        String c=" " ;
         if(numRooms==0)
                 return "no rooms in the system";
         else { 
                for(int i=0;i<numRooms;i++){
                    c = c + rooms[i].toString();

              }
        return c;
         }
    }
  
    //Adds a booking to the system for the first
//room that accommodates the seating
//required and that fits the duration of time
//needed for the booking. Appropriate
//messages must be returned if successful,
//otherwise a message Cannot add Booking is returned
    public String addBooking(String description, int duration, int numSeating){
        String add=null;
        int x=0;
        while(x<numRooms && add==null){
            add=rooms[x].addBooking(description,duration,numSeating);
            x++;
        }
        
        if(add==null)
            return "Cannot add bookings";
         else
            return add;
    
    }
    
    //Returns the details of the booking with a
   //given ID if found in the system, otherwise
   //a message Booking ID not found is returned
   
    public String getBooking(int bookingID){
        int j=0;
        String s=" ";
        while(j<numRooms){
            if(rooms[j].hasBooking(bookingID)==true){
                j++;
                s= rooms[j].getBookingDetails(bookingID);
                return s;
            }
             else
                return "Booking ID not found";
        }
        return s;
    }
    
    //Returns the details of all bookings for a
    //Room with a given ID if found in the
    //system, otherwise a message Room ID 
    //not found is returned
    public String getBookingsByRoom(String roomID){
        int y=0;
        while(y<numRooms){
            if(roomID.equals(rooms[y].getRoomID())){
                y++;
                return rooms[y].getBookingList();
                
            }
        }
        return "Room ID not found";
        
    }
    
//Returns a String that visualises the
//booking schedule for all rooms in the
//system with filled and unfilled slots
//identified by booking IDs, otherwise if no
//rooms are in the system, a message No
//rooms in the system. is returned

    public String getBookingGrid(){
        int y;
        String g=" ";
        if(numRooms==0){
           return "No rooms in the system";
        } 
        
        for(y=0;y<numRooms;y++){
            g= rooms[y].getDetailedBookingGrid();
        }
    return g;
    }

}
    