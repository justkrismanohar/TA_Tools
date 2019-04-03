
//Student ID - 816009413

public class Room{
    private static final int numSlots = 8;
    private static int roomIDCounter=0;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private int slotNum;

    
    public Room(String name, int seatingCapacity){
        roomIDCounter += 100; 
        roomID = name + Integer.toString(roomIDCounter);
        this.seatingCapacity = seatingCapacity;
        bookings = new Booking[8];
        slotNum = 0;
    }

    
    public String addBooking(String description, int duration, int seats){
        String details="Booking added to schedule: \n";
        if(canFitNumbers(seats) && canFitTime(duration)){
            int total = duration+slotNum;
            int j;
            Booking temp = new Booking(description,duration,seats);
            temp.setLocation(roomID);
            for(j = slotNum; j < total; j++){
                bookings[j] = temp;
                bookings[j].setLocation(roomID);
            }
            details += bookings[slotNum].toString();
            slotNum+=duration;
            return details;
        }else{
            return null;
        }
    }

    public boolean canFitNumbers(int numSeats){
        if(numSeats<=seatingCapacity){
            return true;
        }else return false;
    }
    
    
    public boolean canFitTime(int duration){
        int needed = slotNum + duration;
        if(needed <= numSlots){
            return true;
        }else return false;
    }
    
    public String getBookingDetails(int bookingID){
        boolean found = false;
        int i=-1;
        while(i<=slotNum && !found){
            i++;
            if(bookings[i].getBookingID() == bookingID){
                    found=true;
            }
        }
        
        if(found){
            String bookDetails = bookings[i].toString();
            return bookDetails;
        }else{
            return "Booking with that ID does not exist";
        }
        
    }
    
    public String getBookingList(){
        String List  = roomID + ":\n ";
        if(roomIDCounter!=0){
            for(int i=0;i<slotNum;i++){    
                List += bookings[i].toString() + "\n\n";
            }
            return List;
        }else{
            return "No Bookings available for this room";
        }
    }
    

    public String getDetailedBookingGrid(){
        String Grid  = roomID + "| ";
        for(int i=0;i<slotNum;i++){
            Grid += " "+ Integer.toString(bookings[i].getBookingID()) +" |";
            }
        for(int r=0;r<(numSlots-slotNum);r++){
            Grid += "   |";
        }
        Grid +="\n";
        return Grid;
    }
    
    public String getRoomID(){
        return roomID;
    }
    
    public boolean hasBooking(int bookingID){
        for(int i= 0; i < slotNum;i++){
            if(bookingID == bookings[i].getBookingID()){
                return true;
            }
    }
    return false;
   }
    
    
    public int getSeatingCapacity(){
        return seatingCapacity;
    }
    
    public String toString(){
        String str = "RoomID: " + getRoomID() + "\nSeating Capacity: " +  getSeatingCapacity();
        return str;
    }
    
    
}

