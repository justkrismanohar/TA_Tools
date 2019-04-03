
/*
 * Name: HANNAH SYLVESTER
 * ID: 816007999
 */

import java.util.Scanner;


public class RentalConsole
{

    boolean exit;
    
    public static void main(String[] args)
    {
        RentalConsole menu = new RentalConsole();
        menu.runMenu();
    
    }
      
    
    public void runMenu()
    {
       while(!exit){
           printMenu();
           int choice = getInput();
           performAction(choice);
        }
    }
    
     
    private void printMenu()
    {
      System.out.println("     Choose a menu option     ");
      System.out.println("---------------------------------");
      System.out.println("     1. Add a new Room       ");
      System.out.println("     2. Display list of all Rooms");
      System.out.println("     3. Add a new Booking     ");
      System.out.println("     4. Display Booking       ");
      System.out.println("     5. Display Bookings by Room");
      System.out.println("     6. Display Booking grid  ");
      System.out.println("     0. Exit                  ");
    }
    
   
    public int getInput()
    {
        
        Scanner inp = new Scanner(System.in);
        int choice = -1;
        while(choice < 0 || choice > 6){
            System.out.println("Enter your choice: ");
            choice=inp.nextInt(); 
            
            if( choice < 0 || choice > 6)
                System.out.println("Invalid, Please try again.");   
            
        }
             return choice;
    }
    
    private void performAction(int choice)
    {
        String name = "";
        int size = 0;
        
        String details = "";
        int hours = 0;
        int numS = 0;
        
        int booking = 0;
        
        String room;
        
        Scanner scanner = new Scanner(System.in);
        RentalSystem info = new RentalSystem();
        
        switch(choice){
            case 0:
                  exit=true;
                  System.out.println("Thank you for using our facilities.");
                  break;
            case 1:
                  System.out.println("Please enter room name in all capital letters: ");
                  name = scanner.nextLine();
            
                  System.out.println("Please enter room capacity: ");
                  size = scanner.nextInt();
           
                  System.out.println(info.addRoom(name,size));
                  System.out.println("\n");
                  break;
            case 2:
                   System.out.println(info.getRoomList());
                   System.out.println("\n");
                  break;
            case 3:
                  System.out.println("Please enter description: ");
                  details = scanner.nextLine();
                  
                  System.out.println("Please enter duration: ");
                  hours = scanner.nextInt();
            
                  System.out.println("Please enter number of seats: ");
                  numS = scanner.nextInt();

                  System.out.println(info.addBooking(details,hours,numS));
                  System.out.println("\n");
                  break;
            case 4:
                  System.out.println("Please enter bookingID: ");
                  booking = scanner.nextInt();
            
                  System.out.println(info.getBooking(booking));
                  System.out.println("\n");
                  break;
            case 5:
                  System.out.println("Please enter roomID: ");
                  room = scanner.nextLine();
            
                  System.out.println(info.getBookingsByRoom(room));
                  System.out.println("\n");
                  break;
            case 6:
                  System.out.println(info.getBookingGrid());
                  System.out.println("\n");
                  break;
            default:
                  System.out.println("An unknown error has occured.");
        }
    }


}
