//816009535 Simon Ramdath

public class Room{
    private int numSlots;
    private static int roomIDCounter=100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;


    public Room(String name, int seatingCapacity){
        this.roomID=name + Integer.toString(roomIDCounter); //like FST 100
        this.seatingCapacity= seatingCapacity;
        this.numSlots=0; //represents slots used, can also start this at 8 to represent slots available instead
        this.bookings = new Booking[8];
        roomIDCounter+=100; //increment counter
        
        
    }
    
    public String addBooking(String description, int duration, int seats){
        if(canFitTime(duration) && canFitNumbers(seats)){ 
            Booking book= new Booking(description, duration,seats);
            book.setlocation(roomID); 
            for(int i=numSlots; i<(numSlots+duration); i++){
                bookings[i]=book;
            }
            numSlots+=duration;
            return "Booking added to schedule: " + book.toString() ;            
        }
        return null;
    }
    
    public boolean canFitNumbers(int Numseats){
        if (seatingCapacity >=Numseats)
        return true;
        return false;
    
 
    
    }   
    public boolean canFitTime(int duration){
        if((numSlots + duration)<=8)
        	return true;
        
        return false;
    }
    public String getBookingDetails(int bookingID){
        for(int i=0; i<numSlots; i++){
            if(bookings[i].getID()==bookingID){
            	return "Room ID: "+ roomID +" " + bookings[i].toString();
        	}
       	}
        return "Booking not found";
    }
    
    public String getBookingList(){
     
        String list="";
        
        
        for(int i=0; i<numSlots; i++){
            list+=bookings[i].toString();
        }
        
        if (!list.equals(""))
        return list;
        
        return "no bookings";
        
        
        
        
        
    }
    public String getDetailedBookingGrid(){
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
    
    
    
    public String getRoomID(){
     return roomID;
    }
    
    public boolean hasBooking(int BookingID){
        if (!getBookingDetails(BookingID).equals("Booking not found")){
        return true;
       }
            return false;
        
        
        
    }
    public String toString(){
        
        return "RoomID: " + roomID  + " Seats:" +Integer.toString(seatingCapacity) +"\n";
    }
        
    
    
    
}