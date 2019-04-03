//Kerron Patram
//816003101

//Room class modelling a user's request to book a room
public class Room
{
    //declaration of attributes of Room class
    private int numSlots;
    private static int roomIDCounter=100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;

//constructor for Room 
    public Room(String name, int seatingCapacity)
    {
        this.roomID=name + Integer.toString(roomIDCounter); //Example: FSS 300
        this.seatingCapacity= seatingCapacity;
        this.numSlots=0; //represents slots used
        this.bookings = new Booking[8];
        roomIDCounter+=100; //increments by 100 each time
        
        
    }
    
    //Adds a booking to the system
    public String addBooking(String type, int period, int seats)
    {
        if(timeAvail(period) && seatAvail(seats)){ 
            Booking book= new Booking(type, period,seats);
            book.allocate(roomID); 
            for(int i=numSlots; i<(numSlots+period); i++){
                bookings[i]=book;
            }
            numSlots+=period;
            return "Booking successfully added to schedule: " + book.toString() ;            
        }
        return null;
    }
    
    //Checks to see if room has the desired amount of seating
    public boolean seatAvail(int Numseats)
    {
        if (seatingCapacity >=Numseats)
        return true;
        return false;
    }   
    
    
    public boolean timeAvail(int period)
    {
        if((numSlots + period)<=8)
            return true;
        return false;
    }
    
    //return string containing details of a booking such as its Room ID
    public String getBookingDetails(int bookingID)
    {
        for(int i=0; i<numSlots; i++){
            if(bookings[i].getID()==bookingID){
                return "Room ID: "+ roomID +" " + bookings[i].toString();
            }
        }
        return "Booking not found";
    }
    
    
    //Displays a list of all valid bookings
    public String getBookingList()
    {
     
        String list="";
        
        
        for(int i=0; i<numSlots; i++){
            list+=bookings[i].toString();
        }
        
        if (!list.equals(""))
        return list;
        
        return "no bookings";
    }
    
    //Displays a grid containing valid bookings with the respective Room Names and Booking IDs
    public String getDetailedBookingGrid()
    {
        String s = roomID+"|";
		for(int i=0;i<8;i++){
		    if(bookings[i]!=null){
		         int id = bookings[i].getID();
		         if(id>9){ 
		              s+="  "+id+"  |";
		         }
		         else{ //to accomodate double digit numbers
		              s+="  "+id+"   |"; 
		         }
		     }
		     else{
		          s+="      |";
		     }
		}
   		return s + "\n";
    }
    
    
    //return string containing the room ID
    public String getRoomID()
    {
     return roomID;
    }
    
    //checks to see if valid booking exists
    public boolean hasBooking(int BookingID)
    {
        if (!getBookingDetails(BookingID).equals("Booking not found")){
        return true;
       }
            return false;
    }
    
    //return string containing details of the room
    public String toString()
    {
        return "RoomID: " + roomID  + " Seats:" +Integer.toString(seatingCapacity) +"\n";
    }
    
    
}