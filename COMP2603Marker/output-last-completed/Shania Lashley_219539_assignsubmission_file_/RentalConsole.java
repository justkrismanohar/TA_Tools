     



import java.util.Scanner;
// 816009920
/**
 * Write a description of class RentalConsole here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class RentalConsole{
   
    
   public void display_menu(){
           System.out.println("     Choose a Menu Option    ");
           System.out.println("1: Add a new Room");
           System.out.println("2: Display list of all Rooms");
           System.out.println("3: Add a new Booking");
           System.out.println("4: Display Booking");
           System.out.println("5: Display Booking by Room");
           System.out.println("6: Display Booking grid");
           System.out.println("0: Exit");
    }
    
  public RentalConsole() {
      Scanner in = new Scanner(System.in);
    //Scanner readme = new Scanner(System.in);
      RentalSystem r = new RentalSystem();
    
      display_menu();
  
        switch (in.nextInt()) {
        
            case 1:
        
                String name;
                int seatingCapacity;
                System.out.print( "Enter room name (Format ABC): ");
                name = in.next();
                System.out.print( "Enter room capacity: ");
                seatingCapacity = in.nextInt();
                //RentalSystem r = new RentalSystem();
                System.out.println(r.addRoom(name, seatingCapacity));
        
            new RentalConsole();
            break;
      
            case 2:
            System.out.println(r.listRoom().toString());
            
            new RentalConsole();
            break;
      
            case 3:
                String description;
                int duration;
                int numSeating;
                System.out.print( "Enter event description: ");
                description = in.next();
                System.out.print( "Enter event duration (hours): ");
                duration = in.nextInt();
                System.out.print( "Enter addendance number: ");
                numSeating = in.nextInt();
                
                System.out.println(r.addBooking(description, duration, numSeating).toString());
            
                new RentalConsole();
            break;
            
            case 4:
                int bookingID;
                System.out.print( "Enter Booking ID: ");
                bookingID = in.nextInt();
                
                System.out.println ( r.getBooking(bookingID));
                
                new RentalConsole();
            break;
            
            case 5:
                String roomID;
                System.out.print( "Enter Room ID: ");
                roomID = in.next();
                System.out.println ( r.getBookingsByRoom(roomID));
                
                new RentalConsole();
            break;
            
            case 6:
                 System.out.println ( r.getBookingGrid());
            
                 new RentalConsole();
            break;
            
            case 0:
            
            
            break;
            
            default:
                System.err.println ( "Unrecognized option" );
                new RentalConsole();
            break;
        }
    }
    
   public static void main(String[] args){
       RentalSystem RSystemInstance = new RentalSystem();  
             
       //Scanner input = new Scanner(System.in);
        
       //int number = input.nextInt();
       new RentalConsole();
       
 
   }
   
}