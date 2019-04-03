//ID#:810003511
import java.util.Scanner;

public class RentalConsole
{
   
    public static void main(String[] args){
        RentalSystem rentals = new RentalSystem();
        Scanner keyboard = new Scanner(System.in);
        int i = -1;
        String roomName;
        String roomID;
        int roomCapacity;
        String description;
        int duration;
        int numSeating;
        int bookID;
        while(i!=0){
        System.out.println("Choose a menu option");
        System.out.println("1: Add a new Room");
        System.out.println("2: Display list of all Rooms");
        System.out.println("3: Add a new Booking");
        System.out.println("4: Display Booking");
        System.out.println("5: Display Bookings by Room");
        System.out.println("6: Display Booking grid");
        System.out.println("0: Exit");
        i=keyboard.nextInt();

        if(i>6){
            System.out.println("Not valid input try again");
        }
        if(i==1){
            System.out.print("Enter room name (Format ABC): ");
            roomName=keyboard.next();
            System.out.print("Enter room capacity: ");
            roomCapacity=keyboard.nextInt();
            rentals.addRoom(roomName,roomCapacity);
                      
            
        }
        if(i==2){
            rentals.getRoomList();  
            
            
        }
        if(i==3){
            System.out.print("Enter event description: ");
            description=keyboard.next();
            System.out.print("Enter event duration(hours): ");
            duration=keyboard.nextInt();
            System.out.print("Enter attendance number: ");
            numSeating=keyboard.nextInt();
            
            rentals.addBooking(description,duration,numSeating);
           
        }
        if(i==4){
            System.out.print("Enter booking ID: ");
            bookID=keyboard.nextInt();
            rentals.getBooking(bookID);
            
            
            
        }
        if(i==5){
            System.out.print("Enter Room ID: ");
            roomID=keyboard.next();
            rentals.getBookingsByRoom(roomID);
        
        }
        if(i==6){
            rentals.getBookingGrid();
         
        }
    }
    
    }
    
}
