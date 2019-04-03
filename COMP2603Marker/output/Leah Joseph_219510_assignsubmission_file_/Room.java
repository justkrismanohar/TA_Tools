//816009481
public class Room{
   private final int numSlots = 8; //****
   private static int roomIDCounter = 100;
   private String roomID;
   private Booking[]bookings = new Booking[7];
   private int seatingCapacity;
   private String name;
   public Room(String name,int seatingCapacity){
       this.name = name;
       this.seatingCapacity = seatingCapacity;
    }
   //mutators
   public void setroomIDCounter(int roomIDCounter){
       this.roomIDCounter = roomIDCounter + 100;
    
    }
    //accessorss
   public Booking getBookings(int index) {
       return bookings[index];
    }
   public String getName(){
       return name;
    }
   public int getSeatingCapacity(){
       return seatingCapacity;
   }
   
    
   public String addBooking(String description,int duration,int seats){
       String b;
       if((duration<=numSlots) && (seats<= seatingCapacity)){
       //location.getLocation() = location;
       b ="Booking added to schedule:  " + " Description:  " + description + " Duration:  " + duration + " Seats:  " + seats ;
       return b;
       }
       else{
       return null;
       }
       
    }
    
    public boolean canFitNumbers(int numSeats){
        if(numSeats<=seatingCapacity){
            return true;
        }
        return false;
    }
    
    public boolean canFitTime(int duration){
        if(duration<=numSlots){
            return true;
        }
        return false;
    }
    
    public String getBookingDetails(int bookingID){
        String details= "Booking not found " ;
        boolean found=false;
        int i = 0;
        while (i<8){
            int b= bookings[i].getBookingID();
            if (b == bookingID){
                details = "Booking was found: " + bookings[i];
                found = true;
            }
            i++;
        }
        
        return details;
    }

    public String getBookingList(){
        String list =" No bookings have been made. ";
        String details;
        int i = 0;
        
        while ((i<8) && (bookings.length != 0) ){
            Booking b= bookings[i];
            if(b!= null)
            list = "Details: "+ bookings[i];
            System.out.println(list);
            i++;
        }
        return list;
    }
    
    public String getDetailedBookingGrid(){
        String grid;
        int i =0;
        if(bookings.length!=0)
        grid = roomID + "|" + bookings[0].getBookingID() + "|" + bookings[1].getBookingID() + "|"+ bookings[2].getBookingID() + "|" + bookings[3].getBookingID() + "|" + bookings[4].getBookingID() + "|" + bookings[5].getBookingID() + "|" + bookings[6].getBookingID() + "|"  + bookings[7].getBookingID() + "|"  + bookings[8].getBookingID() + "|" + bookings[9].getBookingID();
        grid = "There are no bookings for this room ";
        return grid;
    }
    
    public String getRoomID(){
        return roomID = name + roomIDCounter;
    }
    
    public boolean hasBooking(int bookingID){
        boolean present =false;
        int i = 0;
        int b= bookings[i].getBookingID();
        while ((i<8)&&(b!= bookingID)&&(bookings.length !=0)){
            if (b == bookingID){
                present = true;
            }
            i++;
            b= bookings[i].getBookingID();
        }
        return present;
    }
    
    public String toString(){
        String s;
        s= "RoomID: " + roomID + " Seating Capacity: " + seatingCapacity;
        return s;
    }

        
        
        
    
}
    
