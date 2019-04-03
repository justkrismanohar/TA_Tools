//816007834
import java.util.Scanner;

public class RentalConsole {
    public static void main(String[ ] args){
        RentalSystem RS1 = new RentalSystem();
        Scanner s=new Scanner(System.in);
        while(true) {
            System.out.println("Choose a menu option");
            System.out.println("1: Add a new Room");
            System.out.println("2: Display list of all Rooms");
            System.out.println("3: Add a new Booking");
            System.out.println("4: Display Booking");
            System.out.println("5: Diplay Bookings by Room");
            System.out.println("6: Display Booking grid");
            System.out.println("0: Exit");
            int choice=s.nextInt();
        
            if(choice==1) {
                System.out.println("Enter Room Name (Format ABC): ");
                String name=s.next();
                System.out.println("Enter Seating Capacity: ");
                int seatingCapacity=s.nextInt();
                String room=RS1.addRoom(name,seatingCapacity);
                System.out.println(room);
            }
        
            if(choice==2) {
                System.out.println("Room List");
                String list=RS1.getRoomList();
                System.out.println(list);
            }  
        
            
            if(choice==3) {
                System.out.println("Enter description of event: ");
                String description=s.next();
                System.out.println("Enter duration of event (in hours): ");
                int duration=s.nextInt();
                System.out.println("Enter number of people attending event: ");
                int numSeats=s.nextInt();
                String booking=RS1.addBooking(description,duration, numSeats);
                System.out.println(booking);
            }
            
            if(choice==4) {
                System.out.println("Enter booking ID: ");
                int bookingID=s.nextInt();
                String bookingDetails=RS1.getBooking(bookingID);
                System.out.println(bookingDetails);
            }
            
            if(choice==5) {
                System.out.println("Enter Room ID (Format ABC123): ");
                String roomID=s.next();
                String bookings=RS1.getBookingsByRoom(roomID);
                System.out.println(bookings);
            }
            
            if(choice==6) {
                System.out.println("Booking Grid");
                
            }
            
            if(choice==0)
                break;
        }
    }
}