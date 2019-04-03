//816009481
public class RentalSystem{
    Room[]rooms = new Room[9];
    int numRooms;
    
    public RentalSystem (){
        this.numRooms=numRooms;
    }
    public String addRoom(String name,int seatingCapacity){
        String details =" ";
        int i ;
        Room r= new Room (name,seatingCapacity);
        for(i=0;i<10;i++){
        rooms[i]=r;
        details="New room added: " + rooms[i];
        }
        if (i==10)
        details = " Cannot add room; Max rooms reached ";
        
        return details;
    }
    
    public String getRoomList(){
        String list =" No rooms in the system. ";
        int i = 0;
        while ((rooms.length != 0) && rooms[i] != null){
            return list = "Room: " + rooms[i];
        }
        return list;
    }
    
    /*public String addBooking(String description, int duration, int numSeating){
        int i =0;
        String booking="Cannot add booking";
        boolean found =false;
        while(!found){
            if((rooms[i].getSeatingCapacity()>=numSeating)&&((8-bookings.length)>=duration) )
                
        }
    return booking;    
    }*/
    public String getBooking(int bookingID){
        String booking = "Booking ID not found";
        int i = 0;
        boolean found = false;
        while(!found){
            if (rooms[i].hasBooking(bookingID)== true){
                found = true;
                booking = bookingID + "was found " ;
        }
            i++;
        
        }
        return booking;
    }
    
    /*public String getBookingsByRoom(String roomID){
        int i = 0;
        String bookingsByRoom;
    while((rooms.length!=0) && (rooms[i]!=null)){
        String b = bookings[i].getRoomID;
        if(b == roomID)
        bookingsByRoom = "Room ID found" + rooms[i] ;
    }
    }*/
    
    /*public String getBookingGrid(){
        int i =0;
        String g;
        //Room r = new Room();
        while(rooms[i]!=null){
        return g= Room.getDetailedBookingGrid();
        i++;
        }
        return g;
    }*/
}
