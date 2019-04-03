import java.util.Scanner;
public class RentalConsole
{
    //ID - 816003418
    public static void main(String[] args){
        int option;
        Scanner scanner = new Scanner(System.in);
        RentalConsole console = new RentalConsole();
        RentalSystem rental = new RentalSystem();
        console.menu();
        option = scanner.nextInt();
        while(option != 0){
            if(option == 1){
                System.out.println("Enter the name(ABC) of the room: ");
                String name = scanner.next();    
                System.out.println("Enter the seat capacity for the room: ");
                int seatCapacity = scanner.nextInt();
                System.out.println(rental.addRoom(name, seatCapacity));
            }
               if(option == 2){
                System.out.println(rental.getRoomList());
            }
               if(option == 3){
                System.out.println("Enter the description for the booking: ");
                String desc = scanner.next();
                System.out.println("Enter the duration for the booking: ");
                int duration = scanner.nextInt();
                System.out.println("Enter seat capacity for the booking: ");
                int seatC = scanner.nextInt();
                System.out.println(rental.addBooking(desc, duration, seatC));
            }
               if(option == 4){
                System.out.println("Enter the ID for the booking: ");
                int id = scanner.nextInt();
                System.out.println(rental.getBooking(id));
            }
               if(option == 5){
                System.out.println("Enter the Room ID: ");
                String roomID= scanner.next();
                System.out.println(rental.getBookingByRoom(roomID));
            }
              if(option == 6){
                System.out.println(rental.getBookingGrid());
            }
            console.menu();
            option = scanner.nextInt();
        }
        
    }
    public void menu(){
        System.out.println("Choose a menu option");
        System.out.println("1: Add a new Room");
        System.out.println("2: Display list of all Rooms");
        System.out.println("3: Add a new Booking");
        System.out.println("4: Display Booking");
        System.out.println("5: Display Bookings by Room");
        System.out.println("6: Display Bookings by grid");
        System.out.println("0: Exit");
    }
}
