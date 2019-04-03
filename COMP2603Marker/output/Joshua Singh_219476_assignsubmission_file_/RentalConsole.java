//JOSHUA SINGH 816008321
import java.util.Scanner;
public class RentalConsole{
  public static void main(String[] args){
    RentalSystem r = new RentalSystem();
    String menu =   "Please choose an option(0-6): \n" +
                    "1: Add a new Room \n" +
                    "2: Display list of all Rooms \n" +
                    "3: Add a new Booking \n" +
                    "4: Display Booking \n" +
                    "5: Display Bookings by Room \n" +
                    "6: Display Booking grid \n" +
                    "0: Exit";
    System.out.println(menu);
    Scanner keyboard = new Scanner(System.in);
    int option;
    option = keyboard.nextInt();
    String description, room, name;
    int duration, seats, id;
    String content;
    String nextOption = "\nPlease choose another option: ";
    while(option != 0){
        if(option == 1){
            content = "\nPlease enter the name of the room then the seating capacity.(eg 'ABC' then '100')";
            System.out.println(content);
            name = keyboard.next();
            seats = keyboard.nextInt();
            System.out.println(r.addRoom(name,seats));
            System.out.println(nextOption);
        }
       
         
        
        if (option == 2) {
            System.out.println(r.getRoomList());
            System.out.println(nextOption);
        }
        
        if (option == 3){
            content ="\nPlease enter the description,duration and seating required for the booking. eg'Lab'then'2'then'80'";
            System.out.println(content);
            description = keyboard.next();
            duration = keyboard.nextInt();
            seats = keyboard.nextInt();
            System.out.println(r.addBooking(description, duration, seats));
            System.out.println(nextOption);
        }
    
        if( option == 4){
            content ="Please enter the BookingID.(eg'1')";
            System.out.println(content);
            id = keyboard.nextInt();
            System.out.println(r.getBooking(id));
            System.out.println(nextOption);
        }
    
        if (option == 5){
            content ="\nPlease enter the ID of the room. eg'ABC100'";
            System.out.println(content);
            room = keyboard.next();
            System.out.println(r.getBookingsByRoom(room));
            System.out.println(nextOption);
        }
    
    
        if (option == 6){
            System.out.println(r.getBookingGrid());
            System.out.println(nextOption);
        }
        else 
        option = keyboard.nextInt();
    }
    content = "Exiting Program...";
    System.out.println(content);
    System.exit(0);
  }
}


