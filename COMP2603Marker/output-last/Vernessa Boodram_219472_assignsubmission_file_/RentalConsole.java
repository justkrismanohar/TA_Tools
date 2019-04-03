//VERNESSA BOODRAM
//816006133

import java.util.Scanner;

public class RentalConsole {
   public static void main(String[] args) {
    
       RentalSystem rental = new RentalSystem();

       //Displays the menu options 
       System.out.println("Welcome to the Rental System Console");
       System.out.println();
           
       System.out.println("Choose a menu option");
       System.out.println("1: Add a new room");
       System.out.println("2: Display list of all Rooms");
       System.out.println("3: Add a new Booking");
       System.out.println("4: Display Booking");
       System.out.println("5: Display Booking by Room");
       System.out.println("6: DisplayBooking Grid");
       System.out.println("0: Exit"); 
       System.out.println();
       
       Scanner option = new Scanner(System.in);
       int number = option.nextInt();
       System.out.println();

        
       while(number!= 0) {
           //Option #1:
           if(number == 1){
               
               String name;
               int seatingCapacity;
               int numRooms;
               
               System.out.print("Enter Room Name (Format ABC): ");
               name = option.next();
               
               System.out.print("Enter Room Capacity: ");
               seatingCapacity = option.nextInt();
               
               rental.addRoom(name, seatingCapacity); //Calling the method form RentalSystem class
                       
               System.out.println();
               System.out.println();
           }
           
           //Option #2:
           else if(number == 2){
               
               System.out.println("ROOM LIST: ");
               
               String option2;

               option2 = rental.getRoomList(); //Calling the method from RentalSystem class
               
               System.out.println();
               System.out.println();
           }
           
            
           //Option #3:
           else if(number == 3){
               String description;
               int duration;
               int numSeating;
               
               System.out.print("Enter event description: ");
               description = option.next();
                
               System.out.print("Enter event duration: ");
               duration = option.nextInt();
                
               System.out.print("Enter attendance number: ");
               numSeating = option.nextInt();

               rental.addBooking ( description, duration, numSeating);
               
               System.out.println();
               System.out.println();
           }
           
           //Option #4:
           else if(number == 4){
               
              int bookingID;
              
              System.out.print("Enter Booking ID: ");
              bookingID = option.nextInt();

              //rental.getBooking(bookingID);
              
              System.out.println();
              System.out.println();
           }
            
           //Option #5: 
           else if(number == 5){
               
               String roomID;
               
               System.out.print("Enter Room ID: ");
               roomID = option.next();

               //rental.getBookingsByRoom(roomID);
               
               System.out.println();
               System.out.println();
           }
            
           //Option #6:
           else if(number == 6){
               
               System.out.print("BOOKING GRID: ");

               //rental.getBookingsByRoom (roomID);
               
               System.out.println();
               System.out.println();
           }
  
           System.out.println("Choose a menu option");
           System.out.println("1: Add a new room");
           System.out.println("2: Display list of all Rooms");
           System.out.println("3: Add a new Booking");
           System.out.println("4: Display Booking");
           System.out.println("5: Display Booking by Room");
           System.out.println("6: DisplayBooking Grid");
           System.out.println("0: Exit"); 
           System.out.println();
           
           number = option.nextInt();
        }//CLose while loop
        
        System.out.println("You exited the program !!!");
       
   } //End Static main
} //End of RentalConsole 