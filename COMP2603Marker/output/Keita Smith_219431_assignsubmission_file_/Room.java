//ID: 816005793 
public class Room
{
    private static final int numSlots = 8;
    private static int roomIDCounter=100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private int bookingCount=0;
    private int timeSlotsRemaining=8;
    private static int totalBookings=0;
    //private static int totalBookings = 0;

    public Room(String name, int seatingCapacity){
        this.seatingCapacity=seatingCapacity;
        roomID = name.toUpperCase() + Integer.toString(roomIDCounter);
        roomIDCounter = roomIDCounter + 100;
        bookings = new Booking[numSlots];
    }
    
    public String addBooking(String description, int duration, int seats){
            Booking b = new Booking(description,duration,seats);
            for(int x=bookingCount;x<bookingCount+duration;x++){
                //if (canFitTime(duration)){
                    bookings[x]=b;
                    bookings[x].setLocation(roomID);
                    bookingCount++;
                    timeSlotsRemaining-=duration;
                    totalBookings+=bookingCount;
                    return "Booking added to schedule" + "\nBooking Details - "+bookings[x].toString();
                        
        }
            return null;    
    }
    public boolean canFitNumbers(int numSeats){
        if (numSeats<=seatingCapacity)
            return true;
        else 
            return false;
    }
    
    public boolean canFitTime(int duration){
        //if ((numSlots - bookingCount) >= duration)
        if (timeSlotsRemaining-duration >= 0)
            return true;
        else
            return false;
    }
    public String getBookingDetails(int bookingID){
        for (int x=0;x<numSlots;x++){
            if (bookings[x].getBookingID() == bookingID)
                return bookings[x].toString();
                //return "BookingID: " + bookingID + "Description: " + bookings[x].getDescription() + " Duration: " + bookings[x].getDuration() + " Location: " + bookings[x].getLocation() + " NumSeats: " + bookings[x].getNumSeating();     
        }
        return "Booking ID not found";
    }
    public String getBookingList(){
        String booking="";
        String bookingList="";
        if (bookingCount==0)
            return "No bookings made";
        for (int x=0;x<bookingCount;x++){
                booking +=bookings[x].toString()+"\n";     
        }
        return booking;   
    }
    public String getDetailedBookingGrid(){
        String grid="";
        int id;
        int slots=0;
        int totalSlots=0;
        if (bookingCount==0){
            for(int x=0;x<numSlots;x++){
            grid+="   |";
            }
        }
        else{
        for (int x=0;x<bookingCount;x++){
            slots=bookings[x].getDuration();
            totalSlots+=slots;
            for(int y=0;y<slots;y++){
                id=bookings[x].getBookingID();
                if (id>=10)
                grid+=id+" |";
                else
                grid+=id+"  |";
            }
        }
        for (int x=0;x<numSlots-totalSlots;x++){
            grid+="   |";
        }
        }
        return grid;       
    }
    public String getRoomID(){
        return roomID;
    }
    public String getRoomName(){
        return roomID.substring(0,3);
    }
    public int getNumSlots(){
        return numSlots;
    }
    
    public boolean hasBooking(int bookingID){
        for(int x=0;x<bookingCount;x++){
            if (bookingID==bookings[x].getBookingID())
                return true;
        }
        return false;
    }
    public String toString(){
        return "RoomID: "+roomID+" Seats: "+seatingCapacity+ " | ";
    }   
    public int getSeatingCapacity(){
        return seatingCapacity;
    }
    public int getTimeSlotsRemaining(){
        return timeSlotsRemaining;
    }
}
