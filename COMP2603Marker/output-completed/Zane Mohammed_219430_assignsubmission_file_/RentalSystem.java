
//Name: Zane Mohammed
//ID:816009832
//COMP 2603 Asssignment 1
import java.util.*;
    
public class RentalSystem{
    
    private Room[] rooms = new Room[10];
    private int numRooms;
    private final int max=10;
    
    public RentalSystem(){
        numRooms=0;
        for(int count=0;count<max;count++){
            rooms[count]=null;
        }
    }
   
    public String addBooking(String description,int duration,int numSeating){
        if(numRooms==0)
            return "Cannot add booking!";
        String booking="Cannot add booking!";
        boolean foundRoom=false;
        for(int roomCounter=0;roomCounter<numRooms;roomCounter++){
            booking=rooms[roomCounter].addBooking(description,duration,numSeating);
            if(booking!=null){
                foundRoom=true;
                break;
            }
        }
        if(foundRoom==false)
            booking="Cannot add booking!";
        return booking;
    }
    
    public String addRoom(String name,int seatingCapacity){
        if(numRooms>=max)
            return "Cannot add room. Max rooms reached!";
        rooms[numRooms]=new Room(name,seatingCapacity);
        String details=rooms[numRooms].toString();
        numRooms++;
        return details;
    }
    
    public String getBookingGrid(){
        String grid=" ";
        if(numRooms==0)
            grid="No rooms in the system!";
        else{
            grid="BOOKING GRID\n";
            for(int roomCounter=0;roomCounter<numRooms;roomCounter++){
                grid+=rooms[roomCounter].getDetailedBookingGrid()+"\n";
            }
        }
        return grid;
    }
    
    public String getRoomList(){
        String systemRoomDetails="No rooms in the system";
        if(numRooms==0)
            return systemRoomDetails;
        else{
            systemRoomDetails="Rooms List:\n";
            for(int roomCount=0;roomCount<numRooms;roomCount++){
                systemRoomDetails+=rooms[roomCount].toString()+"\n";
            }
        }
        return systemRoomDetails;
    }
    
    public String getBooking(int bookingID){
        if(numRooms==0)
            return "Booking ID not found!";
        boolean found=false;
        String bookingDetails="Booking Details:\n";
        for(int roomCount=0;roomCount<numRooms;roomCount++){
            if(rooms[roomCount].hasBooking(bookingID)==true){
                bookingDetails=rooms[roomCount].getBookingDetails(bookingID);
                found=true;
                break;
            }
        }
        if(found==false)
            bookingDetails="Booking ID not found!";
        return bookingDetails;
    }
    
    public String getBookingsByRoom(String roomID){
        int foundRoom=findRoom(roomID);
        if(foundRoom==-1)
            return ("Room ID not found!");
        return rooms[foundRoom].getBookingList();
    }
    
    public int findRoom(String roomID){
        for(int roomCounter=0;roomCounter<numRooms;roomCounter++){
            if(rooms[roomCounter].getRoomID().equals(roomID))
                return roomCounter;
        }
        return -1;
    }
}

