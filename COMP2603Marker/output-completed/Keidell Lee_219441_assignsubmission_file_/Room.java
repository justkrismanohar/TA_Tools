// 816009809 

public class Room{
    private int numSlots = 8;
    private static int roomIDCounter = 100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private int arrCount = 0;
    private String name;
    private int rTime;
    private int rSeats;
    
    public Room(String name,int seatingCapacity){
        this.name = name;
        setRoomID(name,roomIDCounter);
        roomIDCounter+= 100;       
        this.seatingCapacity = seatingCapacity;
        bookings = new Booking[8];
        rTime = numSlots;
        rSeats =  seatingCapacity;               
    }
        
    
    public String addBooking(String description, int duration, int seats){
        if(canFitTime(duration)  && canFitNumbers(seats)){ 
           Booking b = new Booking(description,duration,seats);  
           bookings[arrCount] = b;
           bookings[arrCount].setLocation(roomID);
           rTime = rTime -duration;
           rSeats = rSeats - seats;
           arrCount++;
           return "Booking added to schedule";
        }
        else
            return "Not Enough space";
                               
                
    }
    
    public boolean canFitNumbers(int numSeats){
        if(numSeats < rSeats)
            return true;
        return false;
    }
    
    public boolean canFitTime(int duration){
        if(duration < rTime)
            return true;
        return false;
    }
    
    public String getBookingDetails(int bookingID){
        String s = "";
        for(int i=0;i<numSlots;i++){
            if(bookings[i] == null){
                break;
            }
            if(bookings[i].getBookingID() == bookingID)
                s+= "Room found, roomID: " + bookings[i].toString();             
        }        
            return s;
    }
   
    
    public String getBookingList(){
        String s="";
        if(bookings[0] == null){
            return "No bookings have been made";
        }
        
        for(int i=0;i<bookings.length;i++){
                if(bookings[i] == null){
                    return "No bookings";
                }
                
                if(bookings[i].getLocation().equals(getRoomID())){
                    for (int j=0;j<bookings[i].getDuration();j++){
                        s+= bookings[i].toString() + "\n";
                    }
                    
                }
                return s;
            }
            return s;
        }
    
    public String printSlots(int BookingID, int duration){
        String s = "";
        if(BookingID == -1){
            for(int i=0;i<duration;i++){
            s+= "| " + " ";
        }
        return s;
        }        
                    
        for(int i=0;i<duration;i++){
            s+= "| " + BookingID;
        }
        return s;
    }
     
    
    public String getDetailedBookingGrid(){
        String s="";
        int count = 0;
        for(int i=0;i<arrCount;i++){
            count += bookings[i].getDuration(); 
            s+= printSlots(bookings[i].getBookingID(),bookings[i].getDuration());
        }
        int rem = numSlots - count;
        s+= printSlots(-1,rem);       
        
        return s;
    }
    
    
    Boolean hasBooking(int bookingID){
        for(int i=0;i<arrCount;i++){            
            
            if(bookings[i].getBookingID() == bookingID)
            return true;
        }
        return false;
    }
    
    public String getRoomID(){
        return roomID;
    }
    
    public void setRoomID(String name, int ID){
       roomID = name+""+ID;
       
    }
    
    public String toString(){
        String details = " ";
        details +="RoomID "+ roomID + " " +" Seating Capacity "+ seatingCapacity;
        return details;
    }
    
    
}
