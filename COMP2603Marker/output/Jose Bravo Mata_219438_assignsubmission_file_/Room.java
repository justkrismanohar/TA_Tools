//andrez Bravo 816011156
public class Room
{
 
    private int numSlots=8;
    private static int roomIDCounter=100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;

   
    public Room(String name,int seatingCapacity)
    {
        
        this.seatingCapacity=seatingCapacity;
        roomID=GenerateRoomID(name);
        bookings=new Booking[8];
        
    }

    private String GenerateRoomID(String name)//generate a unique identifier for room
    {
        int s=roomIDCounter;
        roomIDCounter+=100;
        return name+s;
    }
    public String addBooking(String description, int duration, int seats) //adds a booking
    {
        if (canFitNumbers(seats) && canFitTime(duration) )
        {  
          Booking b=new Booking(description,duration,seats);
          b.setLocation(roomID);
        for(int i=1;i<=duration;i++){//array is stored in reverse
      bookings[numSlots-i]=b;
      bookings[numSlots-i].setLocation(roomID);
    }
      numSlots=numSlots-duration;//numslots updates
        return "Booking added to schedule.RoomID: "+roomID+ " bookingID: " + b.getBookingID() + " description: " + description +
        " duration: " + duration + "hr(s)  seats: " + seats;
    }
    else 
    return null;
    }
    
    public boolean canFitNumbers(int numSeats)
    {
       if (numSeats<=seatingCapacity)
       return true;
       else
       return false;
    }
    
    public boolean canFitTime(int duration)
    {
        if (duration<=numSlots)
        return true;
        else
        return false;
    }
    
    public String getBookingDetails(int bookingID)
    {
          for(int i=7;i>=0;i--){
           if(i>numSlots && (bookings[i].getBookingID()==bookingID))
           return " " + bookings[i].toString();
        }
        return"booking not found";
    }  
        public String getBookingList() {
        if (numSlots!=8) {
            for (int i=7;i>=numSlots;i-=bookings[i].getDuration())//so that spaces in array don't repeat for bookings more than an hour
            {
                String s="Booking ID: " +bookings[i].getBookingID()+" description: " +bookings[i].getDescription()+ " duration: " + bookings[i].getDuration() + "hr(s) seats: " +bookings[i].getNumSeating();//get id for booking
                System.out.println(s);// print details from getBookingDetails
            }
            return "";
        }
        else 
        return "No bookings were made";
    }
        
        public String getDetailedBookingGrid()//return grid of bookings
        {
            if(numSlots==8)
            return "no bookings were made";
            else{
                System.out.print(roomID+" | ");
            for (int i=7;i>=0;i-=1)
            {      
                if(i>=numSlots)
                System.out.print(bookings[i].getBookingID()+" | ");
                else
                System.out.print("  | ");
        }
     
    }
    return "";
  }
  
  public String getRoomID(){
      return roomID;
      
    }
    
  public boolean hasBooking(int bookingID){
       for(int i=7;i>=0;i--){
           if(i>numSlots && (bookings[i].getBookingID()==bookingID)){
            return true;
        }
         }
         return false;
        }
    
  public String toString(){
      return "ROOM ID: " + roomID + " Seating Capacity: " + seatingCapacity;
   
    }
}
