
/**
Name: Kady Seecharan
ID: 816002036
 */
public class Room
{
    // instance variables - replace the example below with your own
    private int numSlots ;
    private int roomIDCounter=100;
    private String roomID;
    private Booking bookings[];
    private int seatingCapacity ;
    public static final int MAXBOOKINGS=8;


    public Room(String name,int seatCapacity)
    {
        this.numSlots=0;
        this.roomIDCounter = 100;
        this.roomID= name ;
        this.bookings= new Booking[8];
        this.seatingCapacity = seatingCapacity;
    }
    
    //accessor
    public int getNumSlots(){
        return this.numSlots;
    }

    public int getRoomIDCounter(){
        return this.roomIDCounter;
    }
    
    public String getRoomID(){
        return this.roomID;
    }
    
    public Booking getBooking(int index){
        return this.bookings[index];
    }
    
    public int getSeatingCapacity(){
        return this.seatingCapacity;
    }
    
    //mutator
    public void setSeatingCapacity(int newNum){
        this.seatingCapacity= newNum;
    }
    
    public void setNumSlots(int numS){
        this.numSlots = numS;
    }
    
    public void setRoomIDCounter(int counter){
        this.roomIDCounter = counter;
    }
    
     public void setRoomID(String roomID) {
        if(Character.isLetter(roomID.charAt(0)) &&  Character.isLetter(roomID.charAt(1)) && Character.isLetter(roomID.charAt(2)) && 
        Character.isDigit(roomID.charAt(3)) && Character.isDigit(roomID.charAt(4)) && Character.isDigit(roomID.charAt(5))) 
            this.roomID = roomID + roomIDCounter;
        else
            this.roomID = null;
    }
    //toSring Method
    public String toString(){
        String s="";
        s+= "RoomID: " + getRoomID()  + "\n" + "Seats: " + getSeatingCapacity() + "\n";
        return s;
    }
    
    public String addBooking(String description, int duration, int seats){
        String book="";
        Booking newBooking;
        newBooking = new Booking(description,duration,seats);
        String name = getRoomID();
        int numS = getSeatingCapacity();
        int timeSlots = getNumSlots();
        
        if(timeSlots <= MAXBOOKINGS && seats <= numS){
            this.bookings[timeSlots] = newBooking;
            this.bookings[timeSlots].setLocation(name);
            setNumSlots(timeSlots++);
            setRoomIDCounter(roomIDCounter + 100);
            book += "Booking added to schedule";
            System.out.println(newBooking.toString());
            return book;
        }
       
    else{
            return null;
        }
}

    public boolean canFitNumbers(int numSeats){
        int numS = getSeatingCapacity();
        if (numSeats <= numS){
            return true;       
        }
        else {
            return false;
        }
    }
    
    public boolean canFitTime(int duration){
        if (duration <= MAXBOOKINGS){
            return true;       
        }
        else {
            return false;
        }
    }
    
      public String getBookingDetails(int bookingID){
        String book="";
        String message ="No Booking" ;
        for(int i=0; i<getNumSlots(); i++){
            //search for booking by ID
            if(this.bookings[i].getBookingID() == bookingID){
                book += this.bookings[i].toString();
            }
            else
                return message;
            
        }
        return book;
    }
    
    public String getBookingList(){
    String details= "";
    String message = "No Bookings have been made";
    
    if(numSlots == 0)
        return message;
        
    else{
          for(int i = 0; i < numSlots; i++) {
                if(bookings[i] != null) {
                    details += bookings[i].toString(); 
                }
            }
            return details;
        }
    }
    
    public String getDetailedBookingGrid(){
        String details= "";
        for(int i=0; i<getNumSlots(); i++){
        details += roomID + "|" + bookings[i].getBookingID() + "|";
    }
    return details;
}
    
    public boolean hasBooking(int bookingID){
        for(int i=0; i<getNumSlots(); i++){
            //search for booking by ID
            if(this.bookings[i].getBookingID() == bookingID){
                return true;
            }
        }
        return false;
    }
}
    