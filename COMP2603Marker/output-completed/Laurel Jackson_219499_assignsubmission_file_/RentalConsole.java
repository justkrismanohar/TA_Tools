/*
 * Student ID - 816004212
 */

import java.util.Scanner;
public class RentalConsole{
    

    //this method ensures that the room name entered is of length 3 and all uppercase
    private static boolean testString(String str){
        int count = 0;
         for(int i=0; i<str.length(); i++){
            char c = str.charAt(i);
            count += i;
            if(c >= 97 && c <= 122)  //once c falls between these values, it is a lowercase character
              return false;
            
          }
          
        if(count == 3)
           return true;
                
        return false;
            
    }
    
    public static void main(String [] args){
        
        RentalSystem r1 = new RentalSystem();
       
        Scanner scanner = new Scanner(System.in);

        //Variables for choices
        
        //For choice 1 
        String roomName = "";
        int seatingCapacity;
        boolean check;

        ///For choice 2
        String roomList;
        
        ///For choice 3
        String description;
        int duration;
        int attendance;
        String booking3;

        //For choice 4
        int bookingID;
        String booking4;
        
        //For choice 5
        String roomID;
        String bookingsByRoom;
        
        //For choice 6
        String bookingGrid;

        int input = -1; //holds choice selected from the user
        
        System.out.println("Welcome to the Rental System Console\n");
        
        while (input !=0){
            System.out.println(" Choose a menu option");
            System.out.println("1: Add a new room");
            System.out.println("2: Display list of all Rooms");
            System.out.println("3: Add a new booking");
            System.out.println("4: Display Booking");
            System.out.println("5: Display Booking by Room");
            System.out.println("6: Display Booking Grid");
            System.out.println("0: Exit");

            input = scanner.nextInt();
       
            if(input == 1){
                System.out.print("Enter room name (Format ABC): ");
                roomName = scanner.next();
                check = testString(roomName);
                while(!roomName.matches("[A-Z]+") && check != true){
                    System.out.print("Please enter room  name in a String format [ABC]: ");
                    roomName = scanner.next();
                    check = testString(roomName);
                }

                System.out.print("Enter room capacity: ");
                seatingCapacity = scanner.nextInt();

                String room = r1.addRoom(roomName, seatingCapacity);
                System.out.println(room);
            }
            else
                if(input == 2){
                    roomList = r1.getRoomList();
                    System.out.println(roomList);
                }
            else
                if(input == 3){
                   System.out.print("Enter event description: ");
                   description = scanner.next();
                   System.out.print("Enter event duration (hours): ");
                   duration = scanner.nextInt();
                   System.out.print("Enter attendance number: ");
                   attendance = scanner.nextInt();
                  
                   booking3 = r1.addBooking(description,duration,attendance);
                   System.out.println(booking3);
  
                }
            else
                if(input == 4){
                    System.out.print("Enter booking ID: ");
                    bookingID = scanner.nextInt();
                    booking4 = r1.getBooking(bookingID);
                    System.out.println(booking4);
                    
                }
            else
                if(input == 5){
                    System.out.print("Enter Room ID: ");
                    roomID = scanner.next();
                    bookingsByRoom = r1.getBookingsByRoom(roomID);
                    System.out.println(bookingsByRoom);
                    
                }
            else
                if(input == 6){
                   bookingGrid =  r1.getBookingGrid();
                   System.out.println(bookingGrid);
                }
 
        }
  
        System.out.println("Exiting system");
       
    }
    
}
