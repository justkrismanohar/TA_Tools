//816005390

import java.util.Scanner;

public class RentalConsole{
    private static RentalSystem rentalSystem;
    
    public static void main(String[] args){
        rentalSystem = new RentalSystem();
        
        while (RentalConsole.showMenu() == true){
        }
    }
    
    private static boolean showMenu() {
        System.out.println("Choose a menu option");
        System.out.println("====================");
        System.out.println("1: Add a new room to the system");
        System.out.println("2: Display a list of all rooms managed by the system");
        System.out.println("3: Add a new booking to the system");
        System.out.println("4: Display an existing booking based on a unique ID");
        System.out.println("5: Display bookings by room");
        System.out.println("6: Display a booking grid of all rooms and booked slots");
        System.out.println("0: Exit");
            
        Scanner keyboard = new Scanner(System.in);
        
        int choice = keyboard.nextInt();
        String roomName;
        int capacity;
        String description;
        int time;
        int attendance;
        
        switch(choice) {
                case 0: 
                        System.out.println("You have exited the system.");
                        return false;
                    
                case 1:
                        System.out.println("Enter room name (ABC format): ");
                        roomName = keyboard.next();
                        if(roomName.compareTo("AAA")>=0 && roomName.compareTo("ZZZ")<=0){
                            roomName = roomName.toUpperCase();
                            System.out.println("Enter the room capacity: ");
                            capacity = keyboard.nextInt();
                            String newRoom = rentalSystem.addRoom(roomName, capacity);
                            if(newRoom != null) {
                                System.out.println(newRoom + "\n");
                            } else {
                                System.out.println("Room not created\n");
                            }
                            return true;
                        }else{ 
                            System.out.println("Invalid! Room name must be set to 3 capitalized letters.\nPlease pick an option.. \n ");
                            return true;
                        }
                case 2:
                        System.out.println("ROOM LIST \n ");
                        System.out.println(rentalSystem.getRoomList()+ "\n");
                        return true;  
                case 3:
                        System.out.println("Enter event description: ");
                        description = keyboard.next();
                        System.out.println("Enter event duration (hours): ");
                        time = keyboard.nextInt();
                        System.out.println("Enter attendance: ");
                        attendance = keyboard.nextInt();
                        System.out.println(rentalSystem.addBooking(description, time, attendance) + "\n");
                        return true;
                case 4:
                        System.out.println("Enter booking ID: ");
                        int bookingID = keyboard.nextInt();
                        System.out.println(rentalSystem.getBooking(bookingID));
                        return true;
                case 5:
                        System.out.println("Enter room ID: ");
                        String roomID = keyboard.next();
                        System.out.println(rentalSystem.getBookingsByRoom(roomID));
                        return true;
                case 6:
                        System.out.println(rentalSystem.getBookingGrid()+"\n");
                        return true;
                        
                default: //If the option is out of range
                        System.out.println("Invalid option. Please choose from options 0-6.\n");
                        return true;
                        
            }
    }
}
