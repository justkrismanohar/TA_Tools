import java.util.Scanner;
import java.util.InputMismatchException;
/**
 *
 * @author (816001214)
 * @version (RentalConsole)
 */
public class RentalConsole {
    public static void main(String[] args) {
      int userChoice = 0; 
      boolean found = false; 
      menu();  
      RentalSystem roomManagement = new RentalSystem();
      Scanner userInput = new Scanner(System.in); 
      
      if (userInput.hasNextInt()) {
          int option = userInput.nextInt(); 
          while (option != 0) {   
              if (option == 1) { 
                  System.out.println("Enter the room name(Format ABC): ");
                  String roomName = userInput.next(); 
                  for (int i =0; i< roomName.length();  i++) 
                   {
                       char check = roomName.charAt(i); 
                       if (Character.isLetter(check) && (Character.isUpperCase(check))) {
                          found = true; 
                        }
                        else 
                            if (Character.isLetter(check) &&!Character.isUpperCase(check))
                        {
                            found = true; 
                        }
                        else {
                                found = false;
                                break; 
                       }
                  }   
            
                  if (found == true && roomName.length() == 3) {
                      System.out.println("\nEnter the room capacity: "); 
                      int newRoomAmount = userInput.nextInt(); 
                      System.out.println(roomManagement.addRoom(roomName.toUpperCase(), newRoomAmount)); 
                   }
                   else {
                        System.out.println("[ERROR] Wrong room name format was enterred. Please stick to the format ABC."); 
                  }

             }
            
             if (option == 2) {
                  String results = roomManagement.getRoomList(); 
                  System.out.println(results);  
             }
            
             if (option == 3) {
               boolean truth = false; 
               String test ="";
               int newDuration = 0;
               int newAttendance = 0; 
               String newDescription = ""; 
               
               System.out.println("Enter event Description: ");
               while (!truth) {
                   userInput.nextLine(); 
                   if (userInput.hasNextLine()) {
                       truth = true;
                       newDescription = userInput.nextLine();
                       break; 
                   }
                   else {
                        truth= false; 
                        System.out.println("Incorrect Data Type. ");
                   }
                   System.out.println("Enter event Description: ");
               }
               
               truth = false; 
               while(!truth) {
                  System.out.println("Enter event duration(hours): ");
                  if (userInput.hasNextInt()) {
                      newDuration = userInput.nextInt();
                      truth = true;
                      break;
                  }
                  else {
                      truth = false; 
                      System.out.println("Incorrect Data Type. Please enter an integer "); 
                  }
                  userInput.next(); 
               }
               truth = false;
               while (!truth) {
                 System.out.println("Enter attendance number: "); 
                 if (userInput.hasNextInt()){ 
                      newAttendance = userInput.nextInt();
                      truth = true; 
                      break;
                 }  
                 else {
                       truth = false; 
                       System.out.println("Incorrect Data Type. Please enter an integer "); 
                 }
                 userInput.next();
               }
               
               if (truth)
                    System.out.println(roomManagement.addBooking(newDescription, newDuration, newAttendance));  
               else {
                   System.out.println("Booking not added"); 
               }
            }
            
             if (option == 4) {
               int search = 0; 
               boolean truth = false; 
               System.out.println("\n Enter the booking ID: \n"); 
                 while(!truth) {
                  if (userInput.hasNextInt()) {
                    search= userInput.nextInt();
                    truth = true;
                    break; 
                  }
                  else {
                      truth = false; 
                      System.out.println("Incorrect Data Type. Please enter an integer "); 
                  }
                  System.out.println("\n Enter the booking ID: \n"); 
                  userInput.next(); 
               }
               System.out.println(roomManagement.getBooking(search));
             }
            
             if (option == 5) {
             System.out.println("\n Enter the room ID: \n"); 
             String userRoomIDRequest = userInput.next(); 
             char check = '\0'; 
             userRoomIDRequest = userRoomIDRequest.toUpperCase(); 
             for (int i =0; i< userRoomIDRequest.length();  i++) 
             {
                if (i < 3) { //Checks the first 3 characters of the Room ID example FST100 Checks FST 
                    check = userRoomIDRequest.charAt(i);
                    if (Character.isLetter(check) && (Character.isUpperCase(check))) {
                        found = true; 
                    }
                    else {
                        found = false;
                        break; 
                    }
                }
                
                if(i < 6 && i >= 3) {
                    check = userRoomIDRequest.charAt(i); 
                    if (Character.isDigit(check)) {
                        found = true;
                    }
                    else {
                        found = false;
                        break; 
                    }
                }
             }      
             
             if (found) 
                System.out.println(roomManagement.getBookingsByRoom(userRoomIDRequest));   
             else 
                System.out.println("[ERROR] Incorrect Room ID enterred. \nStick to the format XXXYYY with XXX being the first 3 characters of the room name and YYY being the 3 digits"); 
           }
            
         if (option == 6) {
              System.out.println(roomManagement.getBookingGrid());  
         }
         menu();
         option = userInput.nextInt(); 
         if (option == 0)
            System.out.println("You have exit the system.");
      }
    }
    else {
        System.out.println("Invalid input to start system. Please restart the system and try entering an integer between 0 - 6 next time");
   }
      
   }
    
    public static void menu() { 
         System.out.println("\nChoose a menu option");
         System.out.println("-------------------------\n");
         System.out.println("1 - Add a new room to the system");
         System.out.println("2 - Display a list of all rooms managed by the system");
         System.out.println("3 - Add a new booking to the system");
         System.out.println("4 - Display an existing booking based on a unique ID");
         System.out.println("5 - Display bookings by room");
         System.out.println("6 - Display a booking grid of all rooms and booked slots");
         System.out.println("0 - Exit "); 
    }
}
