
/*NAME:JOSHUA STAPLETON
 * STUDENT ID: 816010544
 * */
 
import java.util.Scanner;
public class RentalConsole {

 
 public static void menu() {
	 
	 System.out.println("Choose a menu Option");
	 System.out.println("1:	Add a new Room");
	 System.out.println("2:	Display List of all Rooms");
	 System.out.println("3:	Add a new Booking");
	 System.out.println("4:	Display Booking");
	 System.out.println("5:	Display Bookings by Room");
	 System.out.println("6:	Display Booking grid");
	 System.out.println("0:	Exit");
	 
 }
 
	public static void main(String[] args) {
		RentalSystem rental=new RentalSystem();
		menu();
		Scanner keyboard = new Scanner(System.in);
		System.out.println("enter an integer:");
		int choice = keyboard.nextInt();
		while(true) {
		if(choice==1) {
			System.out.println("Enter room name (format ABC):");
			String name=keyboard.next();
			System.out.println("Enter room capacity:");
			int roomCapacity=keyboard.nextInt();
		String num1=rental.addRoom(name,roomCapacity);
		System.out.println(num1);
		menu();
		
	}
		if(choice==2) {
			String t=rental.getRoomList();
			System.out.println(t);
			menu();
		}
		if(choice==3) 
		{
			Scanner keyboard1 = new Scanner(System.in);
				System.out.println("Enter description:");
				String description=keyboard1.next();
				System.out.println("Enter duration:");
				int duration=keyboard1.nextInt();
				System.out.println("Enter seating:");
				int numSeating=keyboard1.nextInt();
				
			String t=rental.addBooking(description, duration, numSeating);
			System.out.println(t);
			menu();
			
		}
		if(choice==4) {
			Scanner keyboard2 = new Scanner(System.in);
			System.out.println("Enter booking ID:");
			int bookingID=keyboard2.nextInt();
			String t=rental.getBooking(bookingID);
			System.out.println(t);
			menu();
			
		}
		if(choice==5) {
			Scanner keyboard3 = new Scanner(System.in);
			System.out.println("Enter RoomID:");
			String roomID=keyboard3.next();
			String t=rental.getBookingsByRoom(roomID);
			System.out.println(t);
			menu();
			
		}
		if(choice==6) {
			String t =rental.getBookingGrid();
			
			System.out.println(t);
			menu();
			
		}
		if(choice==0) {
			System.out.println("Exiting Rental Console");
			System.exit(0);
		}
		choice = keyboard.nextInt();
		

}
	}
	
}
