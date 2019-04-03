/*
 * Student ID: 816004003
 * Name: Keanu Nichols
*/
import java.util.Scanner;

public class RentalConsole{
    
    
    public static void optionSix(RentalSystem r){
        System.out.println(r.getBookingGrid());
    }
    
    public static void optionFive(Scanner keyboard, RentalSystem r){
        System.out.println("\nEnter Room ID: ");
        String roomID = keyboard.next();
        String details = r.getBookingsByRoom(roomID);
        if(details.equals("Room ID not found\n")){
            System.out.println(details);
            return;
        }
        System.out.println(details);
        
        
        
    }
    
    
    public static void optionFour(Scanner keyboard, RentalSystem r){
        System.out.println("\nEnter booking ID: ");
        String num = keyboard.next();
        try{
            int bookingID = Integer.parseInt(num.trim());
            System.out.println(r.getBooking(bookingID));
        }catch(NumberFormatException nfe){
            System.out.println("Must be a number\n");
        }
    }
    
    public static void optionThree(Scanner keyboard, RentalSystem r){
        System.out.println("\nEnter event description: ");
        String description = keyboard.next();
        System.out.println("Enter event duration (hours): ");
        String num = keyboard.next();
        try{
            int duration = Integer.parseInt(num.trim());
            System.out.println("Enter attendance number: ");
            num = keyboard.next();
            try{
                int numSeats = Integer.parseInt(num.trim());
                System.out.println(r.addBooking(description,duration,numSeats));
            }catch(NumberFormatException nfe){
                System.out.println("Must be a number\n");
            }
        }catch(NumberFormatException nfe){
            System.out.println("Must be a number\n");
        }
    }
    
    public static void optionTwo(RentalSystem r){
        System.out.println("\nRoom List\n" + r.getRoomList() + "\n");        
    }
    
    
    public static void optionOne(Scanner keyboard, RentalSystem r){
        System.out.println("Enter room name (Format ABC): ");
        String name = keyboard.next();
        if(name.length() > 3){
            System.out.println("String is too long");
            return;
        }
        System.out.println("Enter a room capacity: ");
        //String userInput = keyboard.next();
        String num = keyboard.next();
        try{
            int seatingCapacity = Integer.parseInt(num.trim());
            System.out.println(r.addRoom(name,seatingCapacity));
        }catch(NumberFormatException nfe){
            System.out.println("Must be a number\n");
        }
        //int seatingCapacity = keyboard.nextInt();     
    }
    
    public static void console(){
        String details = "";
        details+=" Choose a menu option\n";
        details+="1. Add a new room to the system";
        details+="\n2. Display list of all Rooms";
        details+="\n3. Add a new booking";
        details+="\n4. Display Booking";
        details+="\n5. Display Bookings by Room";
        details+="\n6. Display Booking grid";
        details+="\n0. Exit";
        System.out.println(details);
    }
    public static void main(String[] args){
        RentalSystem r = new RentalSystem();
        r.RentalSystem();
        String choice = "1";
        Scanner keyboard = new Scanner(System.in);
        System.out.println("\nWelcome to the Rental System Console\n");
        while(!choice.equals("0")){
            console();
            choice = keyboard.next();
            //do switch cases instead of if
            if(choice.equals("1"))
                optionOne(keyboard,r);
            else if(choice.equals("2"))
                optionTwo(r);
            else if(choice.equals("3"))
                optionThree(keyboard,r);
            else if(choice.equals("4"))
                optionFour(keyboard,r);
            else if(choice.equals("5"))
                optionFive(keyboard,r);
            else if(choice.equals("6"))
                optionSix(r);
        }
    }
}