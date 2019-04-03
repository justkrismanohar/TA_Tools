
//Name: Zane Mohammed
//ID:816009832
//COMP 2603 Asssignment 1
import java.util.*;
public class RentalConsole{

    public static void main(String[] args){
        RentalSystem rs=new RentalSystem();
        int choice=1;
        Scanner key = new Scanner(System.in);
        while(choice!=0){
            System.out.println("\n\nChoose a menu option:");
            System.out.println("1: Add a new Room");
            System.out.println("2: Display list of all Rooms");
            System.out.println("3: Add a new Booking");
            System.out.println("4: Display Booking");
            System.out.println("5: Display Bookings by Room");
            System.out.println("6: Display Booking grid");
            System.out.println("0: Exit");
            choice=key.nextInt();
            switch(choice){
                case 1:
                    String name;
                    int seatingCapacity;
                    String isRoomAdded;
                    System.out.println("Enter the room's name:");
                    name=key.next();
                    System.out.println("Enter a seating capacity for the room: ");
                    seatingCapacity=key.nextInt();
                    isRoomAdded=rs.addRoom(name,seatingCapacity);
                    System.out.println(isRoomAdded+"\n");
                    break;
                case 2:
                    String roomList=rs.getRoomList();
                    System.out.println(roomList);
                    break;  
                case 3:
                    String description;
                    int duration;
                    int numSeating;
                    System.out.println("Enter room description:");
                    description=key.next();
                    System.out.println("Enter duration of booking:");
                    duration=key.nextInt();
                    System.out.println("Enter seating required for booking:");
                    numSeating=key.nextInt();
                    String isBooked=rs.addBooking(description,duration,numSeating);
                    System.out.println(isBooked);
                    break;
                case 4:
                    int bookingID;
                    System.out.println("Enter booking ID:");
                    bookingID=key.nextInt();
                    String foundBooking=rs.getBooking(bookingID);
                    System.out.println(foundBooking);
                    break;
                case 5:
                    String foundRoom,roomID;
                    System.out.println("Enter room ID:");
                    roomID=key.next();
                    foundRoom=rs.getBookingsByRoom(roomID);
                    System.out.println(foundRoom);
                    break;  
                case 6:
                    String grid=rs.getBookingGrid();
                    System.out.println(grid);
                    break;
                case 0:
                    return;
                default:
                    System.out.println("Invalid option entered!");
                    System.out.println("Enter another option!");
                    break;   
            }
            
        }
    }
}