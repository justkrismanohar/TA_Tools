
/**
 Jason Sankar
 816001067
 */
public class RentalSystem 
{
    // instance variables - replace the example below with your own
    private Room[] rooms;
    private static int numRooms;
    private static int bk=0;

    /**
     * Constructor for objects of class RentalSystem
     */
    public RentalSystem()
    {
        this.rooms=new Room[9];
        numRooms=new Integer(0);
    }

    public String addRoom(String name, int seatingCapacity){
        String details="Cannot add room,Max rooms reached.";
        if(this.numRooms<=9){
        this.rooms[numRooms]=new Room(name,seatingCapacity);
        
        
        String sc=String.valueOf(seatingCapacity);
        details="Room ID : "+this.rooms[numRooms].roomID+" Seats : "+sc;
        this.numRooms++;
        }
        return details;
    }
    
    public String getRoomList(){
    String roomList="Room List "+"\n";
    for(int k=0;k<this.numRooms;k++){
    roomList=roomList+"Room ID : "+this.rooms[k].roomID+" Seats : "+this.rooms[k].seatingCapacity+"\n";
    }
    return roomList;
    }
    
    public String addBooking(String description, int duration, int numSeating){
    String ab="Cannot add booking";
    for(int j=0;j<this.numRooms;j++){
        if(this.rooms[j].seatingCapacity>=numSeating){
            if(this.rooms[j].numSlots>0){
            ab=this.rooms[j].addBooking(description,duration,numSeating);
            }
        }
       
    }
    return ab;
    }
    /**
    public String getBooking(int bookingID){
    
    }
    
    public String getBookingsByRoom(String roomID){
    
    }
    
    public String getBookingGrid(){
    
    }
    */
}
