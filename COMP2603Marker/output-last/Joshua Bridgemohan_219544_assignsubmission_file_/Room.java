import java.util.Scanner;
public class Room{
    public String name;
    public int numSlots;
    public int numSeats;
    public static int roomIDCounter=100;
    public int seatingCapacity;
    public String roomID;
    public static Room[] rooms = new Room[10];
    Booking bookings[];
    boolean hasBooking;
    private static int roomIdFinder=0;
    
    //constructor
    public Room(String name,int seatingCapacity){
        numSeats=seatingCapacity;
        hasBooking=false;
        name=name;
        roomID="FST";
        
    }
  
    //Accessors
    public String GetRoomID(){
        return roomID;
    }
    public int GetSeating(){
        return numSeats;
    }
    public String toString(){
        String RoomAsString=
            "\nRoomID:" + GetRoomID() +
            "\nSeating Capacity: " + GetSeating();
            return RoomAsString;
            
    }
    
    public Boolean canFitNumbers(int numSeats){
        if(numSeats<seatingCapacity)
            return true;
           else return false;
        
    }
    public Boolean canFitTime(int duration){
        if(duration<=duration)
            return true;
           else return false;
           
    }
    public boolean hasBooking(){
        if(hasBooking==true)
            return true;
           else return false;
    }
    public void generateRoomID()
    {
        roomID +=roomIdFinder+=1;
    }
    
    
      //public String addBooking(String description,int duration,int seats){
        //return description;
    //}
    
    
    /*public String getBookingDetails(int bookingID){
        String RoomAsString=
            "\nRoomID:" + GetID() +
            "\nDescription: " +GetDescription()+
            "\nDuration: " + GetDuration()+
            "\nLocation: " + GetLocation() +
            "\nSeating :" + GetSeating();
        return BookingAsString;
    }*/
    

    
}
