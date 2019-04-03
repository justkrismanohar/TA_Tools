//816008473 Kenaird Saunders
import java.util.Scanner;
public class RentalSystemConsole
{
    public static void main (String[] args){
         int x = 1;
        while (x>0 && x<7 ){
            System.out.println("1. Add a new room to the System");
            System.out.println("2. Display list of all Rooms");
            System.out.println("3. Add a new Booking");
            System.out.println("4. Display Booking");
            System.out.println("5. Display Bookings by Room");
            System.out.println("6. Display Booking grid");
            System.out.println("0. Exit");
            Scanner keyboard = new Scanner(System.in);
            x = keyboard.nextInt();
        }
        System.out.println("Goodbye.");
    }
}
