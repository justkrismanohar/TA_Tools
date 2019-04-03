
/**
 Jason Sankar
 816001067
 */
import java.util.Scanner;
public class RentalConsole{
   
   public static void main(String[] args) {  
        int option=1;
        RentalSystem rentals=new RentalSystem();
        Scanner input = new Scanner(System.in);
        System.out.println("Choose a menu option");
        System.out.println("1. Add a new room to the system");
        System.out.println("2. Display a list of all rooms managed by the system");
        System.out.println("3. Add a new booking to the system");
        System.out.println("4. Display an existing booking based on a unique ID");
        System.out.println("5. Display bookings by room");
        System.out.println("6. Display a booking grid of all rooms and booked slots");
        System.out.println("0. Exit");
        
        option = input.nextInt();
        //System.out.println("Op" + option);
        while(option!=0){
        if(option>6){
        System.out.println("Not an option");
        }
        
        if(option==1){
        System.out.print("Enter room name (Format ABC): ");    
        String name=input.next();
        System.out.print("Enter room capacity : ");
        int sc=input.nextInt();
        String decide=rentals.addRoom(name,sc);
        System.out.println(decide);
        //System.out.println(name+sc);
        }
        
        if(option==2){
            String rlist=rentals.getRoomList();
            System.out.println(rlist);
        }
        if(option==3){
        System.out.print("Enter description: ");    
        String desc=input.next();
        System.out.print("Enter duration : ");
        int dur=input.nextInt();   
        System.out.print("Enter number of seats : ");
        int seatz=input.nextInt(); 
        String o3=rentals.addBooking(desc,dur,seatz);
        System.out.println(o3);
        }
        
        System.out.println("Choose a menu option");
        System.out.println("1. Add a new room to the system");
        System.out.println("2. Display a list of all rooms managed by the system");
        System.out.println("3. Add a new booking to the system");
        System.out.println("4. Display an existing booking based on a unique ID");
        System.out.println("5. Display bookings by room");
        System.out.println("6. Display a booking grid of all rooms and booked slots");
        System.out.println("0. Exit");
        
        option = input.nextInt();
    }
   }
}
