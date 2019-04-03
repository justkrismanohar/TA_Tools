
/*
 * Kyle Borneo 
 * 815006227
 * Assignment One 
 * 18/02/19
 */


import java.util.*;

public class RentalConsole{
    
    static void process(RentalSystem rs){
        int choice = 1;
        Scanner keyboard = new Scanner(System.in);
        printMenu();
       
        
        
        while(choice != 0){
            
            choice = keyboard.nextInt();
            

            while(choice < 0 || choice >6){
                System.out.println(choice + " an invalid choice.");
                choice = keyboard.nextInt();
            }

            if (choice == 1){
                System.out.print("Please enter a room name:\n");
                String name = keyboard.next();
                System.out.print("Please enter Seating Capacity:\n");
                int c = keyboard.nextInt();
                String result = (rs.addRoom(name, c));
                System.out.print(result);
            }
            else{
                if (choice == 2){
                    String result= rs.getRoomList();
                    System.out.println(result);
                }
                else{
                     if (choice == 3){
                         System.out.println("Please enter the descrption:");
                         String s = keyboard.next();
                         System.out.println("Please enter the duration:");
                         int d = keyboard.nextInt();
                         System.out.println("Please enter the capacity:");
                         int c = keyboard.nextInt();
                         String result= rs.addBooking(s,d,c);
                         System.out.println(result);
                     }
                     else{
                         if (choice == 4){
                             System.out.println("Enter the booking id: "); 
                             int id  = keyboard.nextInt(); 
                             System.out.println(rs.getBooking(id));
                          }
                          else{
                               if (choice == 5){
                                   System.out.println("Enter the room id: "); 
                                   String roomID  = keyboard.next(); 
                                   System.out.println(rs.getBookingsByRoom(roomID));
                               }
                               else{
                                   if (choice == 6){
                                       System.out.println(rs.getBookingGrid());
                                   }
                                   else{
                                        if (choice == 0){
                                            System.exit(1);
                                        }
                                    }
                               }
                         }
                     }
                }
            }   
           printMenu();
        }
    }
    
    static void printMenu(){
        int choice;
        //System.out.println();
        System.out.println("Choose a menu option:");
        System.out.println("***********MENU***********");
        System.out.println("1.	Add a new Room");
        System.out.println("2.	Display List of all Rooms");
        System.out.println("3.	Add a new Booking");
        System.out.println("4.	Display Booking");
        System.out.println("5.	Display Bookings by Room");
        System.out.println("6.	Display Booking grid");
        System.out.println("0.	Exit");

       
}


    public static void main(String [] args){
        RentalSystem rs = new RentalSystem();
        process(rs);
    
    }
    
}