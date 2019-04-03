//Name:Jehan Hunte
//ID#:816003696
//COMP 2603 Assignment 1

import java.util.Scanner;

public class RentalConsole
{
 
    public RentalConsole()
    {
       
    }

 public static void main(String[] args){
      RentalSystem rs = new RentalSystem();
      System.out.print("\n1: Add a new Room\n2: Display list of all Rooms\n3: Add a new Booking\n4: Display Booking\n5: Display Bookings by Room\n6: Display Booking grid\n0: Exit\n");
      Scanner input = new Scanner(System.in);
      int command = input.nextInt();
      
      do{
            switch(command){
                case(1):
                        System.out.print ("Enter room name (Format ABC):");
                        Scanner option = new Scanner(System.in);
                        String room = option.next();
                        System.out.print("Enter room capacity:");
                        Scanner option2 = new Scanner(System.in);
                        int capacity = option2.nextInt();
                        System.out.print(rs.addRoom(room,capacity));
                        break;
                case(2):
                        System.out.println(rs.getRoomList());
                        break;
                case(3):
                        System.out.println("Enter event description :");
                        Scanner a = new Scanner(System.in);
                        String description = a.next();
                        
                        
                        System.out.println("Enter event duration :");
                        Scanner b = new Scanner(System.in);
                        int duration = b.nextInt();
                        
                        
                        System.out.println("Enter attendance number :");
                        Scanner c = new Scanner(System.in);
                        int attendance = c.nextInt();
                        
                        if(attendance == 0 || duration <1 || duration > 8){
                              System.out.print("Error Please try again");
                              break;
                        }
                      
                        System.out.println(rs.addBooking(description,duration,attendance));
                        
                        break;
                case(4):
                        System.out.println("Enter booking ID:");
                        Scanner d = new Scanner(System.in);
                        int bookingID = d.nextInt();
                        System.out.println(rs.getBooking(bookingID));
                        
                        break;
                case(5):
                        System.out.println("Enter Room ID:");
                        Scanner e = new Scanner(System.in);
                        String roomID = e.next();
                        roomID = roomID.toUpperCase();
                        System.out.print(rs.getBookingsByRoom(roomID));
                        break;
                case(6):
                        System.out.print("BOOKING GRID");
                        System.out.println(rs.getBookingGrid());
                        break;
                default:
                        System.out.println("Invalid Entry");
                        break;
                case(0):System.out.println("\nExiting System.");
                        System.exit(0);
   
            }
            System.out.print("\n1: Add a new Room\n2: Display list of all Rooms\n3: Add a new Booking\n4: Display Booking\n5: Display Bookings by Room\n6: Display Booking grid\n0: Exit\n");
            command = input.nextInt(); 

        }while (command != 0); 
           System.out.println("\nExiting System.");    
   
    }
    
   
}
