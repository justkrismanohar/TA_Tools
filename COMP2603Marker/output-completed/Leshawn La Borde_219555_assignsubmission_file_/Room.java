import java.util.Scanner;

public class Room {
    private static int numSlots=8;
    private int roomIDCounter=0;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private int count=0;

public Room(String name, int seatingCapacity){
}

/*public String toString(int roomID,int seating){
    int seats= seatingCapacity;
    Booking class2= new Booking(description,duration,seats);
    int bookingID=class2.getBookingId();
    String location=class2.getLocation();
    String description=class2.getDescription;
    String details= "BOOKING ID: "+ bookingID+ "TYPE: "+ duration +" HOURS"+" LOCATION: "+location; 
    return details;
}
*/

public String addingBooking(String description, int duration, int seats){
    bookings= new Booking[numSlots];
    //int changedDuration;
    for(int i=0; i<numSlots;i++){
       if((canFitNumbers(seats)) && (canFitTime(duration))){
           Booking temp= new Booking(description,duration,seats);
           bookings[i]=temp;
           //changedDuration=numSlots-duration;
        }
    return "Room successfully booked : "+bookings[i].toString();
}
return bookings.toString();
}


public boolean canFitNumbers(int numSeating){
    if(numSeating<=seatingCapacity)
        return true;
        return false;
}

public boolean canFitTime(int duration){
    if(duration <=numSlots)
        return true;
        return false;
}

public String getRoomID(String roomID){
    roomIDCounter=roomIDCounter+100;
    String details=roomID+Integer.toString(roomIDCounter);
    return details;
}

public String getBookingDetails(int bookingID){
    for(int i=0;i<numSlots;i++){
     if(hasBooking(bookingID))
        return bookings.toString();
     else
        System.out.println("RoomID not found");
}
return bookings.toString();
}

public String BookingList(){
    for(int i=0;i<numSlots;i++){
        if(bookings[i].equals(null))
          System.out.println("No booking made");
        else 
           return bookings[i].toString();
        }
            return bookings.toString();
}
public String getDetailedBookingGrid(String description,int seats,int duration){
    String details;
    Booking class1= new Booking(description,duration,seats);
    int bookingID=class1.getBookingId();
    for(int i=0;i<numSlots;i++){
     details= "BOOKING GRID \n"+ roomID+"|";
        for(int x=0;x<duration;x++){
            details=bookingID+"|";
        }
   
}
 return details;
}
public boolean hasBooking(int bookingID){
    for(int i=0;i<=numSlots;i++){
     if(bookings[i].equals(bookingID))
        return true;
        return false;
}
}
}
    
/* //String name;
    System.out.println("Enter room name (Format ABC): ");
    Scanner screen= new Scanner(System.in);
    roomID=screen.next();
    name=roomID;
    System.out.println("Enter room capacity: ");
    seatingCapacity =screen.nextInt();
    roomID= roomID + getRoomID();
    //Room[] rooms= new Room[];
    
    //for(int i=0;i<= bookings.length;i++)
       
        System.out.println("ROOM ID: "+roomID + " SEATS: "+ seats);
        count++;*/

