//Kwame Trancoso 816005595
import java.util.ArrayList;
public class Room 
{   
    private String name;
    private final int numslots=8;
    private int roomIDCounter=0;
    private String roomID;
    private ArrayList<Booking>bookings;
    private int seatingCapacity;
    
    public Room(String name,int seatingCapacity)
    {
      bookings = new ArrayList<Booking>();
      roomIDCounter+=100;
      setRoomID(name,roomIDCounter);
      setCapacity(seatingCapacity);
    }
    
    public void setRoomID(String name, int ID){
      roomID=name+ID;
    }
    
    public void setCapacity(int capacity){
      seatingCapacity=capacity;
    }
    
    public String getRoomID(){
        return roomID;
    }
    
    public int getNumSlots(){
        return numslots;
    }
    
    public int getSeatingCapacity(){
        return seatingCapacity;
    }
    
    public ArrayList getBookings(){
        return bookings;
    }
    
    public String addBooking(String description, int duration, int seats){
       String response;
       int count;
       if (canFitNumbers(seats)){
           if(canFitTime(duration)){
               Booking book = new Booking(description,duration,seats);
               for(count=0;count<duration;count++){
                   book.setLocation(roomID);
                   bookings.add(book);
               }
               response="Booking added to schedule:Description ";
               response+= book.getDescription(); 
               response+=" Duration: ";
               response+=book.getDuration(); 
               response+="hour/s"+ "Seats:"; 
               response+=book.getSeatingNum();
            }
           else 
               response="Duration requested not available.";
         
        }
        else 
            response="Seating Capacity not adequate.";
         
        return response;
   }
   
    
    public boolean canFitNumbers(int numSeats){
        if(numSeats>seatingCapacity)
            return false;
        return true;
    }
    
    public boolean canFitTime(int duration){
        int free = numslots-bookings.size();
        if(free>=duration)
            return true;
        return false;
    }
    
    public String getBookingDetails(int bookingID){
        int size = bookings.size();
        int count;
        Booking book;
        String details;
        for (count=0;count<size;count++)
        {
            book=bookings.get(count);
            if(book.getID()==bookingID)
            {
                details=book.toString();
                return details;
            }
        }
        
        details="No Booking found for BookingID: "+bookingID;
        return details;
    }
    
    public void getBookingList(){
    }
    
    public void getDetailedBookingGrid(){
    }
        
    public boolean hasBooking(int bookingID){
        int count;
        int size=bookings.size();
        Booking book;
        for(count=0;count<size;count++){
            book=bookings.get(count);
            if(book.getID()==bookingID)
                return true;
            count++;
        }
        return false;
    }
    
    public String toString(){
        String Details="Check";
        Details="RoomID: "+ roomID + " Seats: "+ seatingCapacity;
        return Details;
    }
}