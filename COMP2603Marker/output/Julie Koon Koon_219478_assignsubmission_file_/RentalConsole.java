//816008254
import java.util.Scanner;

public class RentalConsole{
    
//RentalSystem rent1= new RentalSystem();  

    public static void main(String[] args){ 
      RentalSystem rentalSystem= new RentalSystem(); 
          
      int choice=-1;
      while(choice!=0){
        System.out.println("\nChoose a Menu option \n");
        System.out.println("1. Add a new room");
        System.out.println("2. Display a list of all Rooms");
        System.out.println("3. Add a new Booking");
        System.out.println("4. Display Booking");
        System.out.println("5. Display Bookings by Room");
        System.out.println("6. Display Booking grid");
        System.out.println("0. Exit\n");
        Scanner in= new Scanner (System.in);
        int selection=in.nextInt();
        choice=selection;
        //Switch Construct   
         
            switch(choice){
            case 1:
                System.out.println("Please enter the Room Name(Format abc): ");
                Scanner input= new Scanner(System.in);
                String name=input.nextLine();
                System.out.println("Please enter the Seating Capacity of the room: ");
                int seatingCapacity=input.nextInt();
                String output=rentalSystem.addRoom(name, seatingCapacity);
                System.out.println(output);
                break;
            case 2:
                output =rentalSystem.getRoomList();
                System.out.println(output);
                break;
            case 3:
                System.out.println("Please enter the Description: ");
                Scanner enter= new Scanner(System.in);
                String description=enter.nextLine();
                System.out.println("Please enter the Duration: ");
                int duration=enter.nextInt();
                System.out.println("Please enter the Number of Seats required: ");
                int numSeating=enter.nextInt();
                String output1=rentalSystem.addBooking(description,duration,numSeating);
                System.out.println(output1);
                break;
            case 4:
                System.out.println("Please enter the Booking ID: ");
                Scanner value= new Scanner(System.in);
                int bookingID=value.nextInt();
                String output2= rentalSystem.getBooking(bookingID);
                System.out.println(output2);
                break;
            case 5:
                System.out.println("Please enter the Room ID: ");
                Scanner ID= new Scanner(System.in);
                String roomID=ID.nextLine();
                roomID=roomID.toUpperCase();
                String output3=rentalSystem.getBookingsByRoom(roomID);
                System.out.println(output3);
                break;
            case 6:
                String output4=rentalSystem.getBookingGrid();
                break;
            case 0:
                System.exit(0);
                break;
            default:
                System.out.println("Invalid Choice");
                break;
            }
        }
            
    }            
}

