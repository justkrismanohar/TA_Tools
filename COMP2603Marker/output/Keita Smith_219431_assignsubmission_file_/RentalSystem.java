//ID: 816005793
public class RentalSystem
{
    private Room[] rooms;
    private static int numRooms=0;

    
    public RentalSystem(){
        rooms = new Room[10];
    }
    public String addRoom(String name, int seatingCapacity){
        Room r1 = new Room(name,seatingCapacity);
        if (numRooms==10)
            return "Cannot add room; Max rooms reached.";
        if (numRooms<10){
            rooms[numRooms]=r1;
            numRooms+=1;
        }
        return r1.toString();
        //"Name: "+ name.toUpperCase()+" | Seating Capacity: "+seatingCapacity;
    }
    
    public String getRoomList(){
        int x;
        if (numRooms==0)
            return "No rooms in the system.";
        System.out.print("List of Rooms managed by the system:\n");
        String r="";
        for(x=0;x<numRooms;x++){
            r+=rooms[x].toString();
            //"RoomID "+ rooms[x].getRoomID() +" Seats: "+rooms[x].getSeatingCapacity()+" | ";
        }
        return r + "\nNumRooms: "+numRooms;
    }
    public String addBooking(String description, int duration, int numSeating){
        String r1="";
        for (int x=0;x<numRooms;x++){
            if (rooms[x].canFitNumbers(numSeating)){
                if (rooms[x].canFitTime(duration)){
                    r1=rooms[x].addBooking(description,duration,numSeating);
                    return rooms[x].getRoomID() +"\n"+"TimeSlots Remaining: "+rooms[x].getTimeSlotsRemaining()+"\n"+r1;   
                }
            }    
        }
        return "Cannot add Booking";
    }
    public String getBooking(int bookingID){   
          for(int x=0;x<numRooms;x++){
                if (rooms[x].hasBooking(bookingID)==true)
                    return rooms[x].getBookingDetails(bookingID);
                }
        return "BookingID "+ bookingID +" not found";
    }
    public String getBookingsByRoom(String roomID){
        for(int x=0;x<numRooms;x++){
                if(rooms[x].getRoomID().equals(roomID))
                    return rooms[x].getBookingList();      
        }
        
        return "Room: "+roomID+" not found";
    }
    public String getBookingGrid(){
        String room="";
        String bookingGrid="";
        if (numRooms==0)
            return "No Rooms in the System";
        else
        for(int x=0;x<numRooms;x++){
            room=rooms[x].getRoomID();
            if(room.length()==6)
            room+=" |";
            else
            room+="|";
            bookingGrid+=room + rooms[x].getDetailedBookingGrid() + "\n";
        }
        return "BOOKING GRID\n"+bookingGrid;
    }   
}
