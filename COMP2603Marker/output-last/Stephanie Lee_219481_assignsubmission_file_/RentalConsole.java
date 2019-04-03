    import java.util.Scanner;
    
public class RentalConsole{ 
    
    public static void menu(){
        System.out.println("Choose a menu option: \n");
        System.out.println("1. Add a new Room ");
        System.out.println("2. Display list of all Rooms ");
        System.out.println("3. Add a new Booking ");
        System.out.println("4. Display Booking ");
        System.out.println("5. Display Bookings by Room ");
        System.out.println("6. Display Booking grid ");
        System.out.println("0. Exit ");
    }
        
    public static void main(String[] args){
          
        RentalSystem rentals = new RentalSystem();
           
        int option;
        int numberOfSeats = 0;
        int duration = 0;
        int attendance = 0;
        int bookingID = 0;
        String roomID, roomName, description;
           
        Scanner keyboard = new Scanner(System.in);
           
        menu();
           
        while(!keyboard.hasNextInt()){
            keyboard.next();
            System.out.println("Invalid entry");
        }
        
        option = keyboard.nextInt();
        
        while(option != 0){
            switch(option){
                case(1):
                    System.out.println("Enter a room name (Format ABC): ");
                    roomName = keyboard.next();
                    if(roomName.length() != 3){
                        System.out.println("Wrong format. Try again: ");
                        roomName = keyboard.next();
                    }
                    System.out.println("Enter capacity of room: ");
                    numberOfSeats = keyboard.nextInt();
                    System.out.println("\n" + rentals.addRoom(roomName, numberOfSeats));
                    break;
                    
                case(2):
                    if(rentals.getNumRooms() == 0)
                        System.out.println("No rooms stored in the system");
                    else{
                        System.out.println("List of Rooms: \n");
                        System.out.println(rentals.getRoomList());
                    }
                    break;
                    
                case(3):
                    System.out.println("Enter type of class: ");
                    description = keyboard.next();
                    System.out.println("Enter the duration (hours): ");
                    duration = keyboard.nextInt();
                    System.out.println("Enter the expected attendance: ");
                    attendance = keyboard.nextInt();
                    System.out.println(rentals.addBooking(description,duration,attendance));
                    break;
                    
                case(4):
                    System.out.println("Enter the booking ID: ");
                    bookingID = keyboard.nextInt();
                    System.out.println(rentals.getBooking(bookingID));
                    break;
                    
                case(5):
                    System.out.println("Enter the room ID: ");
                    roomID = keyboard.next();
                    if(rentals.getBookingByRoom(roomID).equals(null))
                        System.out.println("No bookings were made ");
                    else
                        System.out.println(rentals.getBookingByRoom(roomID));
                    break;
                    
                case(6):
                    System.out.println(rentals.getBookingGrid());
                    break;
                
                default:
                    System.out.println("Option does not exist. Enter a different option.");
                    option = keyboard.nextInt();
                    break;
                
            } //end switch
            
            System.out.println("\n\n");
            menu();
            option = keyboard.nextInt();

        } // end options while

    }
    
}   
