
//Name: Zane Mohammed
//ID:816009832
//COMP 2603 Asssignment 1
public class Room{
    private final int numSlots=8;
    private static int roomIDCounter=100;
    private String roomID;
    private Booking[] bookings=new Booking[numSlots];
    private int seatingCapacity;
    private int availableSlots;
    
    public String addBooking(String description,int duration,int seats){
        boolean seatingFlag=canFitNumbers(seats);
        boolean timeFlag=canFitTime(duration);
        if(seatingFlag==false){
            return null;
        }
        if(timeFlag==false){
            return null;
        }
        String details="Booking added to schedule\n";
        if((seatingFlag && timeFlag)==true){
            int slot=findNextAvailableSlot();
            bookings[slot]=new Booking(description,duration,seats);
            bookings[slot].setLocation(roomID);
            details+=bookings[slot].toString();
            availableSlots-=1;
            if(duration>1){
                for(int durationCounter=0;durationCounter<duration;durationCounter++){
                    slot=findNextAvailableSlot();
                    bookings[slot]=bookings[slot-1];
                    availableSlots-=1;
                }
            }
        }
        return details;
    }
    
    public int findNextAvailableSlot(){
        int slot=-1;
        for(int x=0;x<numSlots;x++){
            if(bookings[x]==null){
                slot=x;
                break;
            }
        }
        return slot;
    }
    
    public String getBookingDetails(int bookingID){
        boolean flag=hasBooking(bookingID);
        String details;
        if(flag==false){
            return ("No booking for the room has been made with the corresponding ID!\n");
        }
        else{
            details= "Booking ID has been found. Details listed below:\n";
            for(int findBooking=0;findBooking<numSlots;findBooking++){
                if(bookings[findBooking].getBookingID()==bookingID){
                    details+=bookings[findBooking].toString();
                    break;
                }
            }
        }
        return details;
    }
    
    public String getBookingList(){
        String bookingList;
        if(bookings[0]==null)
            return "No bookings have been made yet!";
        else bookingList="Room: "+roomID+"Seats: "+seatingCapacity+"\n";
        for(int count=0;count<numSlots;count++){
            if(bookings[count]!=null){
                bookingList+=bookings[count].toString()+"\n";
            }
        }
        return bookingList;
    }
    
    public String getDetailedBookingGrid(){
        String grid=roomID;
        for(int count=0;count<numSlots;count++){
            if(bookings[count]!=null){
                    grid+="|  "+bookings[count].getBookingID()+"  ";
            }
            else if(bookings[count]==null){
                grid+="|     ";
            }
        }
        grid+="|";
        return grid;
    }
    
    public Room(String name, int seatingRequired){
        setRoomID(name);
        seatingCapacity=seatingRequired;
        for(int count=0;count<numSlots;count++){
            bookings[count]=null;
        }
        availableSlots=numSlots;
    }
    
    public boolean canFitNumbers(int numSeats){
        if(seatingCapacity>=numSeats && numSeats>=1)
            return true;
        else return false;
    }
    
    public boolean canFitTime(int duration){
        boolean flag=false;
        if((availableSlots-duration)<0)
            flag= false;
        else if((availableSlots-duration)>0 && duration>=1)
            flag= true;
        return flag;
    }
    
    public String toString(){
        String details=("Room ID: "+roomID+"\tSeats: "+seatingCapacity);
        return details;
    }
    
    public boolean hasBooking(int bookingID){
        for(int count=0;count<numSlots;count++){
            if(bookings[count]==null)
                return false;
            else if(bookings[count].getBookingID()==bookingID)
                return true;
        }
        return false;
    }
    
    public void setRoomID(String name){
        roomID=name+roomIDCounter;
        roomIDCounter+=100;
        return;
    }
    
    public String getRoomID(){
        return roomID;
    }
    
    public int getSeatingCapacity(){
        return seatingCapacity;
    }
}