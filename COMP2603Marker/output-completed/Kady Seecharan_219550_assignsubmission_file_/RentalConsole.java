
/**
Kady Seecharan
816002036
 */
import java.util.Scanner;

public class RentalConsole
{
    public static void main(String args[]){
        RentalSystem rentalSys;
        rentalSys= new RentalSystem();
        Scanner in= new Scanner(System.in);
        int choice=0;
        do{
            System.out.println("\n\nChoose a menu option\n");
            System.out.println("1: Add a new room");
            System.out.println("2: Display list of all Rooms");
            System.out.println("3: Add a new Booking");
            System.out.println("4: Display Booking");
            System.out.println("5: Display Bookings by Room");
            System.out.println("6: Display Booking grid");
            System.out.println("0: Exit console \n");
            
            do{
                System.out.print("Enter choice: ");
                choice = in.nextInt();
            }while(choice<1 || choice>6);
            System.out.println("\n");
            in.nextLine();
            switch(choice){
                case 1:
                    //add  a room
                    //must get name, capacity
                    String name;
                    int capacity;
                    System.out.print("Enter room name (Format ABC) : ");
                    name= in.nextLine();                   
                    System.out.print("\nEnter room capacity: ");
                    capacity= in.nextInt();
                    in.nextLine();
                    rentalSys.addRoom(name,capacity);
                    break;
                case 2:
                    //add a booking 
                    String description;
                    int duration;
                    int numSeating;
                    System.out.print("Enter event description: ");
                    description= in.nextLine();
                    System.out.print("Enter event duration: ");
                    duration= in.nextInt();
                    System.out.print("\nEnter attendance number: ");
                    numSeating= in.nextInt();
                    in.nextLine();
                    //rentalSys.addBooking(description,duration,numSeating);
                    break;
                
            }
            
        }while(choice!=3);
        
    }
   
}
