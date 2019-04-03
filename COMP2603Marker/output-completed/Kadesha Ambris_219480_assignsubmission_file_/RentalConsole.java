//816006483
import java.util.Scanner;
public class RentalConsole{
    public static void main(String [] args){
        RentalSystem r = new RentalSystem();
        Scanner screen = new Scanner(System.in);
        int option; 
        String details;
        String m;
        int l;
        int a;
        do{
            details = " ";
            System.out.println("Choose a Menu option: \n");
            System.out.println("1.Add a new room to the system \n");
            System.out.println("2.Display a list of all rooms managed by the system \n");
            System.out.println("3.Add a new booking to the system \n");
            System.out.println("4.Display an existing booking based on a unique ID \n");
            System.out.println("5.Display bookings by room \n");
            System.out.println("6.Display a booking grid of all rooms and booked slots \n");
            System.out.println("0:Exit \n");
            option = screen.nextInt();
            
            switch(option){
                case 1:
                System.out.println("Adding a new room to the system");
                System.out.println("Enter room name (Format ABC): \n");
                m = screen.next();
                System.out.println("Enter room capacity: \n");
                l = screen.nextInt();
                details = r.addRoom(m,l);
                System.out.println(details);
                break;
            
                case 2:
                System.out.println("Displaying a list of all rooms managed by the system");
                details = r.getRoomList();
                System.out.println(details);
                break;
           
            
                case 3:
                System.out.println("Adding a new booking to the system");
                System.out.println("Enter event description: \n");
                m = screen.next();
                System.out.println("Enter event duration (hours): \n");
                l = screen.nextInt();
                System.out.println("Enter attendance number: \n");
                a = screen.nextInt();
                details = r.addBooking(m,l,a);
                System.out.println(details);
                break;
            
            
                case 4:
                System.out.println("Enter booking ID: \n");
                l = screen.nextInt();
                details = r.getBooking(l);
                System.out.println(details);
                break;
            
            
                case 5:
                System.out.println("Enter room ID: \n");
                m = screen.next();
                details = r.getBookingsByRoom(m);
                System.out.println(details);
                break;
            
            
                case 6:
                details = r.getBookingGrid();
                System.out.println(details);
                break;
            
            
                case 0:
                System.out.println("Exiting System");
                System.exit(0);
                break;
            
                default:
                System.out.println("This is not a valid Menu Option. Please Select Another.");
                break;
            }
        }
        while(option <= 6);
    }
}