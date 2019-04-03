//Kwame Trancoso 816005595
import java.util.ArrayList;
public class RentalSystem {
    
    private ArrayList<Room>rooms;
    private int numRooms;
    
    public RentalSystem(){;
        rooms= new ArrayList<Room>();
        numRooms=0;
    }
    
    public String addRoom(String name,int seatingCapacity){
        String response;
        Room room;
        room=new Room(name,seatingCapacity);
        response=room.toString();
        
        if(response=="Check")
            response="Cannot add room";
        rooms.add(room);
        return response;
    }
}