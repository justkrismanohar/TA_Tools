public class Room{//STUDENT ID: 816010298
    private int numSlots;
    private int roomIDCounter;
    protected String roomID;
    protected Booking[] bookings;
    protected int seatingCapacity;
    
    private static int timeAvailable1 = 8;
    private static int timeAvailable2 = 0;
    private static int idCounter = 0;
    private static String name;
    private static int roomIDNumber1 = 0;
    private static int roomIDNumber2 = 0;
    private static int roomIDNumber3 = 0;
    private static int roomIDNumber4 = 0;
    private static int i=0;
    private static int j=0;
    private static int l=0;
    private static int p=0;
    private static  Booking[] bookingList = new Booking[8];
    public Room(String name,int seatingCapacity){
        this.seatingCapacity = seatingCapacity;
        numSlots = 8;
        roomIDCounter = 0;
        roomID = null;
        bookings = new Booking[8];
    }
    
    public boolean canFitNumbers(int numSeats){
        if(numSeats<=seatingCapacity){
            return true;
        }
        return false;
    }
    public boolean canFitTime(int duration){
        if(duration<=timeAvailable1){
            return true;
        }
        if(duration>timeAvailable1){
            return false;
        }
        return false;
    }
    
    //attempt 6848...00000000000000
    public String addBooking(String description, int duration, int seats){
        /*if(bookings[0]==null){
            timeAvailable = 8;
        }
        else{
            
                while((p<8)&&(bookings[p]!=null)){
                    timeAvailable = timeAvailable-1;
                    p++;
                }
                
            
        }*/
        timeAvailable2 = timeAvailable1;
        
        if(duration>8){
            return "Error. Duration is too great. Unsupported duration length.";
        }
        if(duration>timeAvailable2){
            return "Error. Insufficient time available in this room.";
        }
        if(seats>seatingCapacity){
            return "Error. Not enough seats available.";
        }
        
        Booking newBooking = new Booking(description,duration,seats);
        while(l<=duration){
            for(int i=0;i<8;i++){
                if(bookings[i]==null){
                    bookings[i] = newBooking;
                    newBooking.bookingIDCounter=idCounter + newBooking.bookingIDCounter + 1;
                    newBooking.bookingID = i;
                    l=l+1;
                }
            }
        }
        //timeAvailable2=timeAvailable2-duration;
        //timeAvailable1=timeAvailable1-duration;
        return "Booking added successfully to room.";
         //if(!canFitTime(duration)){
             //return "Error. Insufficient time available in this room.";
             //}
        
        /*if(!canFitNumbers(seats)){
            return "Error. Not enough seats available.";
        }
        if(roomID == null){
            return "Error. No rooms added.";
        }
        if((canFitTime(duration))&&(canFitNumbers(seats))){
            Booking newBooking = new Booking(description,duration,seats);
            newBooking.bookingIDCounter=idCounter + newBooking.bookingIDCounter + 1;
            newBooking.bookingID = newBooking.bookingID + newBooking.bookingIDCounter + duration;
            newBooking.location = roomID;
            idCounter = idCounter + newBooking.bookingIDCounter;
            for(int i=j;i<(duration);i++){
             if(duration>8||duration>timeAvailable){
                 return "Error. Insufficient time available in this room.";
                }
             if(duration<=timeAvailable){
             bookings[i] = newBooking;
            }
            }
            timeAvailable=timeAvailable-duration;
            j=duration;
            numSlots = timeAvailable;
            return "Booking has been made. ";
        }
        return "Booking could not be made.";*/
    }

    public String getBookingDetails(int bookingID){
        for(int i=0;i<8;i++){
            if(i==0&&bookings[i]==null){
                return "No bookings have yet been made.";
            }
            if(bookings[i].bookingID == bookingID){
                return "Booking Description: " + bookings[i].description + ".\nBooking Duration: "+bookings[i].duration+".\nBooking Location: "+bookings[i].location+".\nSeats Booked: "+bookings[i].numSeating+".";
            }
        }
        return "No such booking exists.";
    }
    
    public String getRoomID(String name){
        if(name == null){
            return "No room name entered.";
        }
        if(name.equals("FST")){
            roomIDNumber1 = roomIDNumber1 + 100;
            roomIDCounter++;
            return name+roomIDNumber1;
        }
        if(name.equals("FFA")){
            roomIDNumber2 = roomIDNumber2 + 100;
            roomIDCounter++;
            return name+roomIDNumber2;
        }
        if(name.equals("ENG")){
            roomIDNumber3 = roomIDNumber3 + 100;
            roomIDCounter++;
            return name+roomIDNumber3;
        }
        if(name.equals("CLL")){
            roomIDNumber4 = roomIDNumber4 + 100;
            roomIDCounter++;
            return name+roomIDNumber4;
        }
        
        return "Room name entered does not exist.";
    }
    
    public boolean hasBooking(int bookingID){
        for(int i=0;i<8;i++){
            if(bookings[i].bookingID == bookingID){
                return true;
            }
        }
        return false;
    }
    
    //!!!!
    public String getBookingList(){
        System.out.println("Booking List");
        if(bookings[0]==null){
            return "No bookings have yet been made.";
        }        
        if(bookings[0]!=null&&bookings[1]==null){
        return "RoomID: "+bookings[0].bookingID + " Room Capacity: "+bookings[0].description; 
        }
        if(bookings[1]!=null&&bookings[2]==null){
        return "RoomID: "+bookings[0].bookingID + " Room Capacity: "+bookings[0].description+"\nRoomID: "+bookings[1].bookingID + " Room Capacity: "+bookings[1].description;
        }
         if(bookings[2]!=null&&bookings[3]==null){
        return "RoomID: "+bookings[0].bookingID + " Room Capacity: "+bookings[0].description+"\nRoomID: "+bookings[1].bookingID + " Room Capacity: "+bookings[1].description+"\nRoomID: "+bookings[2].bookingID + " Room Capacity: "+bookings[2].description;
        }
         if(bookings[3]!=null&&bookings[4]==null){
        return "RoomID: "+bookings[0].bookingID + " Room Capacity: "+bookings[0].description+"\nRoomID: "+bookings[1].bookingID + " Room Capacity: "+bookings[1].description+"\nRoomID: "+bookings[2].bookingID + " Room Capacity: "+bookings[2].description+"\nRoomID: "+bookings[3].bookingID + " Room Capacity: "+bookings[3].description;
        }
         if(bookings[4]!=null&&bookings[5]==null){
        return "RoomID: "+bookings[0].bookingID + " Room Capacity: "+bookings[0].description+"\nRoomID: "+bookings[1].bookingID + " Room Capacity: "+bookings[1].description+"\nRoomID: "+bookings[2].bookingID + " Room Capacity: "+bookings[2].description+"\nRoomID: "+bookings[3].bookingID + " Room Capacity: "+bookings[3].description+"\nRoomID: "+bookings[4].bookingID + " Room Capacity: "+bookings[4].description;
        }
        if(bookings[5]!=null&&bookings[6]==null){
        return "RoomID: "+bookings[0].bookingID + " Room Capacity: "+bookings[0].description+"\nRoomID: "+bookings[1].bookingID + " Room Capacity: "+bookings[1].description+"\nRoomID: "+bookings[2].bookingID + " Room Capacity: "+bookings[2].description+"\nRoomID: "+bookings[3].bookingID + " Room Capacity: "+bookings[3].description+"\nRoomID: "+bookings[4].bookingID + " Room Capacity: "+bookings[4].description+"\nRoomID: "+bookings[5].bookingID + " Room Capacity: "+bookings[5].description;
        }
        if(bookings[6]!=null&&bookings[7]==null){
        return "RoomID: "+bookings[0].bookingID + " Room Capacity: "+bookings[0].description+"\nRoomID: "+bookings[1].bookingID + " Room Capacity: "+bookings[1].description+"\nRoomID: "+bookings[2].bookingID + " Room Capacity: "+bookings[2].description+"\nRoomID: "+bookings[3].bookingID + " Room Capacity: "+bookings[3].description+"\nRoomID: "+bookings[4].bookingID + " Room Capacity: "+bookings[4].description+"\nRoomID: "+bookings[5].bookingID + " Room Capacity: "+bookings[5].description+"\nRoomID: "+bookings[6].bookingID + " Room Capacity: "+bookings[6].description;
        }
        if(bookings[7]!=null){
        return "RoomID: "+bookings[0].bookingID + " Room Capacity: "+bookings[0].description+"\nRoomID: "+bookings[1].bookingID + " Room Capacity: "+bookings[1].description+"\nRoomID: "+bookings[2].bookingID + " Room Capacity: "+bookings[2].description+"\nRoomID: "+bookings[3].bookingID + " Room Capacity: "+bookings[3].description+"\nRoomID: "+bookings[4].bookingID + " Room Capacity: "+bookings[4].description+"\nRoomID: "+bookings[5].bookingID + " Room Capacity: "+bookings[5].description+"\nRoomID: "+bookings[6].bookingID + " Room Capacity: "+bookings[6].description;
        }
        return "No bookings available.";
    }
    
    public String getDetailedBookingGrid(){
        if(bookings[0] == null){
            return "No bookings have yet been made.";
        }
        if(bookings[0]!=null&&bookings[1]==null){
        return "||Booking: "+bookings[0].bookingID+"||        ||        ||        ||        ||        ||        ||        ||";
        }
        if(bookings[1]!=null&&bookings[2]==null){
        return "||Booking: "+bookings[0].bookingID+"||Booking: "+bookings[1].bookingID+"||        ||        ||        ||        ||        ||        ||";
        }
        if(bookings[2]!=null&&bookings[3]==null){
        return "||Booking: "+bookings[0].bookingID+"||Booking: "+bookings[1].bookingID+"||Booking: "+bookings[2].bookingID+"||        ||        ||        ||        ||        ||";
        }
        if(bookings[3]!=null&&bookings[4]==null){
        return "||Booking: "+bookings[0].bookingID+"||Booking: "+bookings[1].bookingID+"||Booking: "+bookings[2].bookingID+"||Booking: "+bookings[3].bookingID+"||        ||        ||        ||        ||";
        }
        if(bookings[4]!=null&&bookings[5]==null){
        return "||Booking: "+bookings[0].bookingID+"||Booking: "+bookings[1].bookingID+"||Booking: "+bookings[2].bookingID+"||Booking: "+bookings[3].bookingID+"||Booking: "+bookings[4].bookingID+"||        ||        ||        ||";
        }
        if(bookings[5]!=null&&bookings[6]==null){
        return "||Booking: "+bookings[0].bookingID+"||Booking: "+bookings[1].bookingID+"||Booking: "+bookings[2].bookingID+"||Booking: "+bookings[3].bookingID+"||Booking: "+bookings[4].bookingID+"||Booking: "+bookings[5].bookingID+"||        ||        ||";
        }
        if(bookings[6]!=null&&bookings[7]==null){
        return "||Booking: "+bookings[0].bookingID+"||Booking: "+bookings[1].bookingID+"||Booking: "+bookings[2].bookingID+"||Booking: "+bookings[3].bookingID+"||Booking: "+bookings[4].bookingID+"||Booking: "+bookings[5].bookingID+"||Booking: "+bookings[6].bookingID+"||        ||";
        }
        if(bookings[7]!=null){
        return "||Booking: "+bookings[0].bookingID+"||Booking: "+bookings[1].bookingID+"||Booking: "+bookings[2].bookingID+"||Booking: "+bookings[3].bookingID+"||Booking: "+bookings[4].bookingID+"||Booking: "+bookings[5].bookingID+"||Booking: "+bookings[6].bookingID+"||Booking: "+bookings[7].bookingID+"||";
        }
    return "Could not get grid.";
    }
    
    public String toString(){
        return "RoomID: "+getRoomID(name)+". Seating Capacity: "+seatingCapacity+".";
    }
}
    
