import java.util.Scanner;
import java.lang.*;
public class RentalConsole{
    public static void main(String[] args){
     RentalSystem rs1 = new RentalSystem();
     System.out.println("Choose a menu option");
     System.out.println("1: Add a new room");
     System.out.println("2: Display a list of all rooms");
     System.out.println("3: Add a new booking");
     System.out.println("4: Display Booking" );
     System.out.println("5: Display Bookings by Room" );
     System.out.println("6: Display Booking grid");
     System.out.println("0: Exit");
     Scanner screen = new Scanner(System.in);
     int option = screen.nextInt();
     String name;
     int capacity;
     int bookingID;
     int i = 0;
     while(option!= 0){
         if(option == 1){
             System.out.print("Enter room name: ");
             name =screen.next();
             System.out.print("Enter seating capacity: ");
             capacity = screen.nextInt();
             rs1.addRoom(name,capacity);
             System.out.println("Choose a menu option");
             System.out.println("1: Add a new room");
             System.out.println("2: Display a list of all rooms");
             System.out.println("3: Add a new booking");
             System.out.println("4: Display Booking" );
             System.out.println("5: Display Bookings by Room" );
             System.out.println("6: Display Booking grid");
             System.out.println("0: Exit");
             
             option = screen.nextInt();
        }
        else if (option ==2){
             rs1.getRoomList();
             System.out.println("Choose a menu option");
             System.out.println("1: Add a new room");
             System.out.println("2: Display a list of all rooms");
             System.out.println("3: Add a new booking");
             System.out.println("4: Display Booking" );
             System.out.println("5: Display Bookings by Room" );
             System.out.println("6: Display Booking grid");
             System.out.println("0: Exit");
             
             option = screen.nextInt();
        }
        else if (option == 3){
        //opt 3
       }
        else if (option ==4){
            System.out.print("Enter booking ID: ");
            bookingID = screen.nextInt();
            rs1.getBooking(bookingID);
        }
        else if (option == 5){
        //opt 5
        }
        else if (option == 6){
        //opt 6
        }
        else if (option> 6){
        System.out.println("PLEASE TRY AGAIN");
        System.out.println("Choose a menu option");
        System.out.println("1: Add a new room");
        System.out.println("2: Display a list of all rooms");
        System.out.println("3: Add a new booking");
        System.out.println("4: Display Booking" );
        System.out.println("5: Display Bookings by Room" );
        System.out.println("6: Display Booking grid");
        System.out.println("0: Exit");
        option = screen.nextInt();
        }
        
    
     }
    }
   
}