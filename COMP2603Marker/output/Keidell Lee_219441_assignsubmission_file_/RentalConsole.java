// 816009809

import java.util.Scanner;

public class RentalConsole{
    public static void main(String [] args){
        RentalSystem rs = new RentalSystem();        
        
        int choice;
        int numSeats=0,duration=0,atten=0,bID=0;
        String rName,desc,rID;
        
        Scanner Keyboard = new Scanner(System.in);  
        
        menu();
        while(!Keyboard.hasNextInt()){
            Keyboard.next();
            System.out.println("Incorrect value entered. Try again");
        }
        choice = Keyboard.nextInt();
        
        
        while(choice != 0){
        switch(choice){
            case(1):
                System.out.print("Enter room name (Format ABC):");
                rName = Keyboard.next();
                while(rName.length()!= 3){
                System.out.print("Invalid Format. Enter room name (Format ABC):");
                rName = Keyboard.next();
            }
                System.out.print("Enter room capacity:");
                numSeats = Keyboard.nextInt(); 
                System.out.println("\n");
                System.out.println(rs.addRoom(rName,numSeats));                
                break;
            
            case(2):
                if(rs.getNumRooms() != 0){
                System.out.println("ROOMS LIST");
                System.out.println(rs.getRoomList());
            }
                else         
                System.out.println("No rooms in the system");        
                break;
                
            case(3):
                System.out.println("Enter event description : ");
                desc = Keyboard.next();
                System.out.println("Enter event duration (hours) : ");
                duration= Keyboard.nextInt();
                System.out.println("Enter attendance number: ");
                atten = Keyboard.nextInt();
                System.out.println(rs.addBooking(desc,duration,atten));
                break;
                
            case(4):
                System.out.println("Enter booking ID" );
                bID = Keyboard.nextInt();
                System.out.println(rs.getBooking(bID));
                break;
                
             case(5):
                System.out.println("Enter Room ID: ");
                rID = Keyboard.next();
                if(!rs.getBookingByRoom(rID).equals(null)){
                System.out.println(rs.getBookingByRoom(rID));
            }
                else{
                    System.out.println("No Bookings made");
                }
                break;
                
            case(6):
                System.out.println(rs.getBookingGrid());
                break;
                
            default:
                System.out.println("Invalid option. Please enter another number");
                choice = Keyboard.nextInt();                
                break;              
                
        
        }// end of switch
            System.out.println("\n");
            menu();
            choice = Keyboard.nextInt();
    }// end while
        
    }// end of main
    
    public static void menu(){
         System.out.println("   Choose a menu option\n");
         System.out.println("1. Add a new room to the system \n"); 
         System.out.println("2. Display a list of all rooms managed by the system \n");
         System.out.println("3. Add a new booking to the system \n");
         System.out.println("4. Display an existing booking based on a unique ID \n");
         System.out.println("5. Display bookings by room \n");
         System.out.println("6. Display a booking grid of all rooms and booked slots \n");
         System.out.println("0. Exit");
        }

}// end of rentalConsole class

