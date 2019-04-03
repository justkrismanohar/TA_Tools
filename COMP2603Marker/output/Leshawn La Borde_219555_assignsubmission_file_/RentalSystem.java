import java.util.Scanner;
import java.lang.reflect.Method;
public class RentalSystem{
    private Room[] rooms;
    private int numRooms=10;
    private String roomID;
//constructor
public RentalSystem(){
}
public String toString (String roomID,int seatingCapacity){
    String details= "ROOM ID: "+ roomID+"SEATS: "+ seatingCapacity;
    return details;
}
public String addRoom(String name, int seatingCapacity){
    int count=0;
    Room class1= new Room(name,seatingCapacity);
    String details;
    rooms= new Room[numRooms];
    
        if(count<=numRooms){
        
            roomID= class1.getRoomID(name);
        
            Room temp= new Room(name,seatingCapacity);
            rooms[count]=temp;
            count++;
        }
        
        else 
            System.out.println("Room capacity is full");
            
            details= "ROOM ID: " +roomID+ "SEATS: "+seatingCapacity;
            //return details;
            return rooms[count].toString();
        //}
}

public String getRoomList(){
    String roomID;
    int seatingCapacity;
    
    for(int i=0; i<=numRooms;i++){
        if(rooms[i].equals(null))
            System.out.println("No rooms in the system");
        else    
            System.out.println(rooms[i].toString());
}
    return rooms.toString();
}

public String addBooking(String description,int duration,int numSeating){
        
    Room class1= new Room(roomID,numSeating);
    String choice1=class1.addingBooking(description,duration,numSeating);
    return choice1;
}
 
public String getBooking(int bookingID,int numSeating){
    Room class2= new Room(roomID,numSeating);
    String choice2=class2.getBookingDetails(bookingID);
    return choice2;
}

public String getBookingsByRoom(String roomID,int numSeating){
    Room class3= new Room(roomID,numSeating);
    String choice3=class3.BookingList();
    return choice3;
}

public String getBookingGrid(int numSeating){
   
    Room class4= new Room(roomID,numSeating);
    String choice4=class4.getDetailedBookingGrid();
    return choice4;
}
}
