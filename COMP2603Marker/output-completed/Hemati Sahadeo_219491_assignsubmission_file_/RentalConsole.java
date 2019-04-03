//Hemati Sahadeo 
//816001653
//Assignment 1
//OOP

import java.util.Scanner;

public class RentalConsole
{
    public static void main(String [] args)
    {
        RentalSystem r = new RentalSystem(); 
        Scanner input = new Scanner(System.in);

        int choice;

        
            System.out.println("------------------------------");
            System.out.println ( "1. Add a new room to the system" ) ;
            System.out.println ( "2. Display a list of all rooms managed by the system" );
            System.out.println ( "3. Add a new booking to the system" ) ;
            System.out.println ( "4. Display an existing booking based on unique ID" ) ;
            System.out.println ( "5. Display booking by room" ) ;
            System.out.println ( "6. Display a booking grid of all rooms and booked slots");
            System.out.println("------------------------------");
            System.out.println ( "\n\nEnter a number from 1 to 6" );
            choice = input.nextInt();
        
        if (choice==1){
                System.out.println("Please enter the name of the Room");
                String name = input.nextLine();
                System.out.println("Please enter the number of seats  of the Room");
                int seatingCapacity = input.nextInt();
                r.addRoom(name,seatingCapacity);
            }
            else if (choice==2){
                      r.getRoomList();
            }
            else if (choice==3){
                       System.out.println("Please enter the description of the Booking");
                       String description = input.nextLine();
                       System.out.println("Please enter the duration of the Booking");
                       int duration = input.nextInt();
                       System.out.println("Please enter the number of seating for the Booking");
                       int numSeating = input.nextInt();
                       r.addBooking(description,duration,numSeating);
            }
            else if (choice==4){
                        System.out.println("Please enter the booking ID for a given Booking");
                        int bookingID = input.nextInt();
                        r.getBooking(bookingID);
            }
            else if (choice==5){
                     System.out.println("Please enter the room ID for a given Booking of the Room");
                     String roomID = input.nextLine();
                     r.getBookingsByRoom(roomID);
            }
            else if (choice==6){
                     r.getBookingGrid();
            }
            
            else System.exit(0);
     
    
    }
}