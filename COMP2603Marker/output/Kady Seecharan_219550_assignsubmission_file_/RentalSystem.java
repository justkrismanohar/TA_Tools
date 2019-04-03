
/**
 Kady Seecharan
 816002036
 */
public class RentalSystem
{
    // instance variables - replace the example below with your own
    private Room rooms[];
    private int numRooms;
    public static final int MAXROOMS=10;
    
    //constructor
    public RentalSystem()
    {
        rooms = new Room[10];
        numRooms = 0;
    }

    //accessors
    
    public int getNumRooms(){
        return this.numRooms;
    }
    
     //mutators
    public void setNumRooms(int newNumRooms){
        this.numRooms=newNumRooms;
    
    }
    
      public String addRoom(String name, int seatingCapacity){
        String room="";
        String error = "Cannot add Room, Max rooms reached";
        Room newRoom;
        newRoom = new Room(name,seatingCapacity);
        int numR = getNumRooms();
        if (numR > MAXROOMS){
            return error;
        }
        else if (numR <= MAXROOMS ){
            this.rooms[numR] = newRoom;
            setNumRooms(++numR);
            System.out.println(newRoom.toString());
            return room;
        }  
    else{
            return null;
        }
}


}
