
/*
 Author: Kareem Mohammed
 ID: 816007247
 */
import java.util.Scanner;

public class RentalConsole{
    
    public static void printMenu(){
    System.out.println("Choose a menu option");
    System.out.println("1. Add a new room to the system");
    System.out.println("2. Display a list of all rooms managed by the system");
    System.out.println("3. Add a new booking to the system ");
    System.out.println("4. Display an existing booking based on a unique ID");
    System.out.println("5. Display bookings by room");
    System.out.println("6. Display a booking grid of all rooms and booked slots");
    System.out.println("0. Exit");
    }
    
    
    public static void main(String[] args){
        
        RentalSystem rentalSystem = new RentalSystem();

        
        Scanner screen = new Scanner(System.in);       
        
        printMenu();
        
        int choice = screen.nextInt();
        
        while(choice != 0){
        
            if(choice == 1){
            
             System.out.print("Enter room name (Format ABC): ");
             String roomName = screen.next();
             while(roomName.length()!=3 || !roomName.matches("[a-zA-Z]*")){
                System.out.print("Room name must 3 characters long and only letters, enter a new name: ");
                roomName = screen.next(); 
                }
              
             System.out.print("Enter room capacity: ");
             String roomCapacityString = screen.next();
             while(!roomCapacityString.matches("[0-9]*")){
             System.out.print("Room capacity must be a number, enter a new value: ");
                roomCapacityString = screen.next(); 
                }
                
             int roomCapacity = Integer.parseInt(roomCapacityString);
             rentalSystem.addRoom(roomName, roomCapacity);
             
             System.out.println("\n");
            }
            
            if(choice == 2){
                
                System.out.println("Room List\n");
                System.out.println(rentalSystem.getRoomList());
             
            }
            
            if(choice == 3){
            
             System.out.print("Enter description: ");
             String description = screen.next();
             
             System.out.print("Enter event duration (hours): ");
             String durationString = screen.next();
             while(!durationString.matches("[0-9]*")){
             System.out.print("Duration must be a number, enter a new value: ");
                durationString = screen.next(); 
                }
                
             int duration = Integer.parseInt(durationString);
             
             System.out.print("Enter attendance number: ");
             String attendanceString = screen.next();
             while(!attendanceString.matches("[0-9]*")){
             System.out.print("Attendance must be a number, enter a new value: ");
                attendanceString = screen.next(); 
                }
                
             int attendance = Integer.parseInt(attendanceString);
             
             System.out.println(rentalSystem.addBooking(description, duration, attendance));
            }
            
            if(choice == 4){
            
             System.out.print("Enter booking ID: ");
             String bookingIDString = screen.next();
             while(!bookingIDString.matches("[0-9]*")){
             System.out.print("Booking ID must be a number, enter a new value: ");
                bookingIDString = screen.next(); 
                }
                
             int bookingID = Integer.parseInt(bookingIDString);
             
             System.out.println(rentalSystem.getBooking(bookingID));
            }
            
            if(choice == 5){
            
             System.out.print("Enter room ID: ");
             String roomID = screen.next();
             
             System.out.println(rentalSystem.getBookingsByRoom(roomID));
            }
            
            if(choice == 6){
            
             System.out.println("Booking Grid: ");
             System.out.println(rentalSystem.getBookingGrid());
            }
            
            printMenu();
        
            choice = screen.nextInt();
        }
        
    }
    
            
        /*system.addRoom("FST",50);
        
        system.addRoom("FSS",60);
        
        System.out.println(system.addBooking("Lecture", 3, 55));
        System.out.println(system.addBooking("Lecture", 1, 25));
        System.out.println(system.addBooking("Lecture", 1, 25));
        System.out.println(system.addBooking("Lecture", 4, 30));
        
        System.out.println("\n\n");
        
        System.out.println(system.getBookingGrid());
        
        System.out.println("\n\n");
        
        System.out.println(system.getBooking(3));
        
        System.out.println("\n\n");
        
        System.out.println(system.getBookingsByRoom("FST100"));
        
        System.out.println("\n\n");
        
        System.out.println(system.getBookingsByRoom("QST100"));
        */
}
