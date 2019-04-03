//816009424

import java.util.Scanner;
public class RentalConsole{
    
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        int a=0;
        
        System.out.println("Welcome to the Rental System Console");
        while(true){
            System.out.println("\n\n1. Add a new room to the system");
            System.out.println("2. Display a list of all rooms managed by the system");
            System.out.println("3. Add a new booking to the system");
            System.out.println("4. Display an existing booking based on a unique ID");
            System.out.println("5. Display bookings by room");
            System.out.println("6. Display a booking grid of all rooms and booked slots");
            System.out.println("7. Exit");
            System.out.println("Please chose an option number: ");
            a=sc.nextInt();
        
            switch(a){
                case 1:
                    
                    break;
                case 2:
                    
                    break;
                case 3:
                    
                    break;
                case 4:
                    
                    break;
                case 5:
                    
                    break;
                case 6:
                    
                    break;
                case 7:
                    System.out.println("Exiting Program...");
                    return;
                default:
                    System.out.println("Error in choice. Plese try again.");
                    break;
            }
        }
        
    }

    //constructors
    public RentalConsole(){
        
        
    }

    //mutators
    
    
    //accessors
    public int sampleMethod(int y){
        
        return 0;
    }
}
