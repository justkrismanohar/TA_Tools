 /**
 * 816009808
 *
 * 
 * 
 */
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.*;


public class RentalConsole
{
    public static void mainMenu()
        {
            System.out.println(" Choose a menu option ");
            System.out.println("\n");
            System.out.println(" 1: Add a new Room");
            System.out.println(" 2: Display list of all Rooms");
            System.out.println(" 3: Add a new Booking");
            System.out.println(" 4: Display Booking");
            System.out.println(" 5: Display Bookings by Room");
            System.out.println(" 6: Display Booking grid");
            System.out.println(" 0: Exit ");
       }
    
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        RentalSystem rental = new RentalSystem();
        
        int option;
        int seats;
        String name;
        int duration;
        int id;
        String description;
        String roomId;
        mainMenu();
        option = input.nextInt();
        while (option != 0)
        {
            switch(option) 
            {
              case 1:
                    System.out.print("Enter room Name ( Format ABC) : ");
                    name = input.next();
                    while(!name.matches("^[a-zA-Z]*$") || name.length() != 3)
                    {
                        System.out.println("Invalid room name entered please Re-Enter");
                        System.out.print("Enter room Name ( Format ABC): ");
                        name = input.next();
                        
                    }
                    System.out.print("Enter seating capacity: ");               
                    while(!input.hasNextInt())
                    {
                        System.out.print("Enter valid number of seats :");
                        input.next();
                    }
                    seats=input.nextInt();
                    System.out.println();
                    System.out.println(rental.addRoom(name,seats).toUpperCase()); 
                    System.out.println();
                    mainMenu();
                    option = input.nextInt();
                    break;
              case 2:
                    System.out.println("Room List"); 
                    System.out.println(rental.getRoomList().toUpperCase());
                    System.out.println();
                    mainMenu();
                    option = input.nextInt();
                    break;
              case 3:
                    System.out.print("Enter event description :");
                    description = input.next();
                    System.out.print("Enter event duration :");  
                    while(!input.hasNextInt())
                    {
                        System.out.print("Enter valid duration :");
                        input.next();
                    }
                    duration=input.nextInt();
                    System.out.print("Enter event seats :");  
                    while(!input.hasNextInt())
                    {
                        System.out.print("Enter valid seating accomodation :");
                        input.next();
                    }
                    seats=input.nextInt();
                    System.out.println();
                    System.out.println(rental.addBooking(description,duration,seats).toUpperCase());
                    System.out.println();
                    mainMenu();
                    option = input.nextInt();
                    break;
                case 4:
                    System.out.print("Enter booking ID : ");            
                    while(!input.hasNextInt())
                    {
                        System.out.print("Enter valid booking ID :");
                        input.next();
                    }
                    id = input.nextInt();
                    System.out.println(rental.getBooking(id));
                    System.out.println();
                    mainMenu();
                    option = input.nextInt();
                    break;
                case 5:
                    System.out.print("Enter the Room ID :");
                    roomId = input.next();
                    System.out.println(rental.getBookingsByRoom(roomId));
                    System.out.println();
                    mainMenu();
                    option = input.nextInt();
                    break;
                    case 6:
                    System.out.println();
                    System.out.println(rental.getBookingGrid().toUpperCase());
                    System.out.println();
                    mainMenu();
                    option = input.nextInt();
                    break;
                    case 0:
              default:
                    System.out.println("You entered a wrong number please Re-Enter");
                    mainMenu();
                    option = input.nextInt();
                    
            }     

        }
        System.out.println("Exiting System");
    }
}