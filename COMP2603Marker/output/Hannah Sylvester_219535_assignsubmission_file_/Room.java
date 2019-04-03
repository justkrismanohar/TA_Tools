
/*
 * Name: HANNAH SYLVESTER
 * ID: 816007999
 */

public class Room
{
    // instance variables - replace the example below with your own
    private final int numSlots=8;
    private static int roomIDCounter=100;
    
    private String roomID;
    private int seatingCapacity;
    private int tempRoom;
    
    private int slotsRemain;
    private int seatsRemain;
    
    private Booking [] bookings;

    /**
     * Constructor for objects of class Room
     */
    public Room(String name,int seatingCapacity)
    {
        // initialise instance variable
        this.roomID=name+roomIDCounter;
        this.seatingCapacity=seatingCapacity;
        slotsRemain=numSlots;
        bookings= new Booking[numSlots];
        roomIDCounter=roomIDCounter+100;
        tempRoom=0;
        seatsRemain=seatingCapacity;
    }

    
    public String addBooking(String description,int duration, int seats)
    {   
        String str;
        
        if(canFitNumbers(seats) && canFitTime(duration)){
            Booking booking= new Booking (description,duration,seats);
            bookings[tempRoom]=booking;
            bookings[tempRoom].setLocation(roomID);
            tempRoom++;
            slotsRemain=slotsRemain-duration;
            seatsRemain=seatsRemain-seats;
            str="";
            str+="Booking added.";
            
        }
        
        
        return "Booking was not added.";
    }
   
    
    public boolean canFitNumbers(int numseats){
        
        if(numseats <= seatingCapacity)
           return true;
        else
           return false;
    }
    
     public boolean canFitTime(int duration){       
            if(duration <= slotsRemain)
               return true;
            else
               return false;
    }
    
    public String getRoomID(){
        return roomID;
    }
   
    
    public int getNumSlots(String roomID){
        int x=0;
        
        for(int i=0; i<bookings.length;i++){
            if(bookings[i].getLocation().equals(roomID))
            x++;
            
            if(bookings[i].equals(null))
            break;
            
        }
        
        return x;
    }
    
    public int getNumBooking(){
        return tempRoom;
    }
    
    public String getBookingDetails(int bookingID){
        String message;     
        int i=0;
        
        while(i<numSlots){
            
            if(bookings[i].bookingID == bookingID){
                      message="";
                      message+=bookings[i].toString();
                      return message;
                }
                
            if(bookings[i].equals(null))
               break;
               
             i++;
         }
   
            return "No Bookings with ID given.";
    }
    
    public String getBookingList(){
        String str;
        
        if(bookings[0].equals(null))
        return "No bookings in system.";
        
        int i=0; 
        while(i<bookings.length){
            
            if(bookings[i].getLocation().equals(getRoomID())){
                str="";
                int x=0;
                
                while(x < bookings[i].getDuration()){
                    str+=bookings[i].toString()+"     ";
                    x++;
                }
                return str;
            }
            
            if(bookings[i].equals(null))
            return "No bookings in system.";
            
            i++;
        }
        return "No bookings in system.";
    }
    
    public String getDetailedBookingGrid(){
        String g = "";
        int n = 0;    
        int i=0; 
        
        while(i<tempRoom){
           n = n + bookings[i].getDuration();
           g+=structGrid(bookings[i].getBookingID(),bookings[i].getDuration());
           i++;
         }
                
        return g;
    }
    
    public String structGrid(int bookingID, int duration){
        String s="";
        int i=0; 
        
        while(i<duration){
            if(bookingID == -1){
               s+="|\n"+"\n";
            }
            else{
               s+="|\n"+ bookingID+"\n";
            }
            i++;
        }
        return s;
        }
    
    public boolean hasBooking(int bookingID){
        int i=0; 
        
        while(i<bookings.length){
            
            if(bookings[i].getBookingID() == (bookingID))
            return true;
            
            if(bookings[i].equals(null))
            break;
            
            i++;
        }
        return false;
    }
    
    public String toString(){
       String details="RoomID: " +roomID+ " Seating: " +seatingCapacity;
        return details;
    }
}
