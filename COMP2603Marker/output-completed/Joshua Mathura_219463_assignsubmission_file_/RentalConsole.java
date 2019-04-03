//816010691

import static java.lang.System.out;
import java.util.Scanner;
import java.util.InputMismatchException;

public class RentalConsole{
    public static void main(String[] args){
        RentalSystem rental = new RentalSystem();
        final short SENTINEL = 0;
        final String REGEX_ROOM_NAME_FORMAT = "^[A-Z]{3}$";
        final String REGEX_ROOM_ID_FORMAT = "^[A-Z]{3}(([1-9]0{2})|1[0]{3})$";
        final String menuString = "\n Choose a menu option\n 1: Add a new Room\n 2: Display list of all Rooms\n 3: Add a new Booking\n 4: Display Booking\n 5: Display Bookings by Room\n 6: Display Booking grid\n " + SENTINEL + ": Exit";
        short option;
        Scanner keyboard = new Scanner(System.in);
        
        out.println("\nWelcome to the Rental System Console");
        
        do {
            out.println(menuString);
            
            try {
                option = keyboard.nextShort();
            } catch (InputMismatchException e){
                keyboard.nextLine();
                out.print(" --> Error: Invalid option.\n");
                continue;
            }
            
            switch (option){
                case 1:
                    out.print("Enter room name (Format ABC): ");
                    keyboard.nextLine();
                    String roomName = keyboard.nextLine();
                    try{
                        if (!roomName.matches(REGEX_ROOM_NAME_FORMAT))
                            throw new InputMismatchException("Incorrect Format");
                    } catch(InputMismatchException e){
                        System.out.println(" --> Error: Incorrect Format.\n");
                        continue;
                    }
                    out.print("Enter room capacity: ");
                    try {
                        int roomCapacity = keyboard.nextInt();
                        out.println(rental.addRoom(roomName, roomCapacity) + '\n');
                    } catch (InputMismatchException e){
                        keyboard.nextLine();
                        out.print(" --> Error: Invalid value for the Room Capacity.\n");
                        continue;
                    }
                    break;
                case 2:
                    out.println(rental.getRoomList() + "\n\n");
                    break;
                case 3:
                    out.print("Enter event description: ");
                    keyboard.nextLine();
                    String eventDescription = keyboard.nextLine();
                    out.print("Enter event duration (hours): ");
                    int duration;
                    try {
                        duration = keyboard.nextInt();
                    } catch (InputMismatchException e){
                        keyboard.nextLine();
                        out.print(" --> Error: Invalid value for the event duration (Should be a whole number).\n");
                        continue;
                    }
                    out.print("Enter attendance number: ");
                    int attendanceNumber;
                    try {
                        attendanceNumber = keyboard.nextInt();
                    } catch (InputMismatchException e){
                        keyboard.nextLine();
                        out.print(" --> Error: Invalid value for the attendance number.\n");
                        continue;
                    }
                    out.println(rental.addBooking(eventDescription, duration, attendanceNumber));
                    break;
                case 4:
                    out.print("Enter booking ID: ");
                    try {
                        int bookingID = keyboard.nextInt();
                        if (bookingID < 1)
                            throw new InputMismatchException("Incorrect Format");
                        out.println(rental.getBooking(bookingID) + "\n\n");
                    } catch (InputMismatchException e){
                        keyboard.nextLine();
                        out.print(" --> Error: Invalid value for the Booking ID.\n");
                        continue;
                    }
                    break;
                case 5:
                    out.print("Enter room ID: ");
                    keyboard.nextLine();
                    String roomID = keyboard.nextLine();
                    try{
                        if (!roomID.matches(REGEX_ROOM_ID_FORMAT))
                            throw new InputMismatchException("Incorrect Format");
                    } catch(InputMismatchException e){
                        System.out.println(" --> Error: Incorrect Format.\n");
                        continue;
                    }
                    out.println(rental.getBookingsByRoom(roomID) + "\n\n");
                    break;
                case 6:
                    out.println(rental.getBookingGrid() + "\n\n");
                    break;
                case SENTINEL:
                    keyboard.close();
                    out.println("Exiting system");
                    System.exit(0);
                    break;
                default:
                    out.println(" --> Error: Invalid option.\n");
            }
        } while (true);
    }
}