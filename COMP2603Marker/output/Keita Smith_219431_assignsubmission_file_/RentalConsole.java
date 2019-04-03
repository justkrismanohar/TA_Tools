//ID: 816005793
import java.util.Scanner;

public class RentalConsole
{
    
    public static void main(String[] args){
        RentalSystem r1= new RentalSystem();
        Scanner scanner = new Scanner(System.in);
    while(true){
        int option=menu();
        if (option == 1){
            
            System.out.println("Enter name of Room:");
            String name=scanner.next();
            while (name.length()!=3){
               System.out.println("Room names must be 3 characters long, enter a valid name:");
               name=scanner.next();
            }
            while(!name.matches("[a-zA-Z]+")){
               System.out.println("Room names must only be made up of letters, enter valid name:");
               name=scanner.next();
            }
            System.out.println("Seating Capacity:");
            int SeatingCapacity=scanner.nextInt();
            System.out.println(r1.addRoom(name,SeatingCapacity)+"\n");           
        }
        else if (option==2){
            System.out.println(r1.getRoomList());  
        }
        else if (option==3){
            System.out.println("Description:");
            String desc=scanner.next();
            System.out.println("Duration (hours):");
            while(!scanner.hasNextInt()){
            System.out.println("Enter valid number of hours:");
            scanner.next();
            }
            int dur=scanner.nextInt();
            System.out.println("Number of seats required");
            while(!scanner.hasNextInt()){
                System.out.println("Invalid Entry, Enter number of seats required:");
                scanner.next();
            }
            int seats=scanner.nextInt();
            System.out.println(r1.addBooking(desc,dur,seats)+"\n");      
        }
        else if(option==4){
            System.out.println("Enter BookingID you are searching for:");
            while(!scanner.hasNextInt()){
                System.out.println("BookingIDs must be integers, Enter valid BookingID");
                scanner.next();
            }
            int b1=scanner.nextInt();
            System.out.println(r1.getBooking(b1)+"\n");         
        }
        else if(option==5){
        System.out.println("Enter RoomID to view Bookings: ");
        String roomID=scanner.next();
        
        System.out.println(r1.getBookingsByRoom(roomID.toUpperCase()));
        }
        else if(option==6){
            System.out.println(r1.getBookingGrid()+"\n");
        
        }
        else{
            System.out.println("Exiting...");
            System.exit(0);
        }
    }
    }  
    public static int menu(){
        int option=0;
        System.out.println("Rental Console User Interface");
        System.out.println("========================================================================");
        System.out.println("1. Add a new room to the system\n2. Display a list of all rooms managed by the system\n3. Add a new booking to the system\n4. Display an existing booking based on a unique ID\n5. Display bookings by room\n6. Display a booking grid of all rooms and booked slots\n");
        System.out.println("Enter any other number to exit");
        System.out.println("------------------------------------------------------------------------");
        do{
        try{
            System.out.println("Select an option:");
            Scanner scanner = new Scanner(System.in);
            option = scanner.nextInt(); 
        }
        catch(Exception e){
            System.out.println("Invalid Option");
        }
        }while (option==0);
        return option;
    }
}