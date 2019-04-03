//816004741

public class Room{ 
    public final int numSlots=8;
    private static int roomIDCounter=100;
    private String roomID;
    private Booking[]  bookings;
    private int seatingCapacity;
    
    public Room(String name, int seatingCapacity){
        roomID=name+roomIDCounter;
        seatingCapacity=this.seatingCapacity;
        roomIDCounter+=100;
        bookings=new Booking[8];
        
    }
    
    public String addBooking(String description, int duration, int seats){
        int n=bookings.length;
        
        if(canFitTime(duration) && canFitNumbers(seats)){
            bookings[n]=new Booking(description, duration, seats);
            return "Booking added to schedule:"+bookings[n].toString();
        }
        
        return null;
        
    }
    
    public String getRoomID(){
        return roomID;
        }
        
    public int getCap(){
        return seatingCapacity;
    }
    
    public String toString(){
        String s="RoomID: "+roomID+" Capacity: "+seatingCapacity;
        return s;
    }
    
    public boolean canFitNumbers(int numSeats){
        return numSeats<=seatingCapacity;
        
    }
    
    public boolean canFitTime(int duration){
        return duration<=(numSlots-bookings.length);
        }
        
    public String getBookingList(){
        String s=" ";
        
        if(bookings.length>0){
            for(int x=0;x<bookings.length;x++){
                s+=bookings[x].toString();
                s+=" ";
            }
        }
        else{ s="No bookings listed";
        }
        
        return s;
    }
    
       
    public String getBookingDetails(int bookingID){
        String s="ID not Found";
        
        for(int x=0;x<bookings.length;x++){
            if(bookings[x].getBookingID()==bookingID){
                return bookings[x].toString();
            }
            
        }
        
        return s;
        
    }
    
    public boolean hasBooking(int bookingID){
         for(int i=0;i<bookings.length;i++){
             if(bookingID==bookings[i].getBookingID()){
                 return true;
                }
            }
         return false;
    
    }
    
    
    public String getDetailedBookingGrid( ){
        
        String s=roomID+"|";
        int i;
        int x;
        for(i=0;i<bookings.length;i++){
            s+="  "+bookings[i].getBookingID()+"  |";
        }
        
        for(x=i;x<numSlots;x++){
            s+="     |";
        }
        
        return s;
        
    }
    
    public int numB(){
        return bookings.length;
    }
    
    

}
