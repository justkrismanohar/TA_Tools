//Student ID - 816009413

import java.util.Scanner;

public class RentalConsole{
    // instance variables - replace the example below with your own
    private int x;
    private static RentalSystem rentalSys = new RentalSystem();;
    
    
    public RentalConsole(){
    }

    public static void main(String[] args){
        
        Scanner input = new Scanner(System.in);
        int choice;
       
        boolean exit = false;
        
        while(exit == false){
            System.out.print("\u000C");
            
            System.out.print("           Main Menu\n==============================" +
            "\nChoose an option: \n" +
            "\n1: Add a new Room" +
            "\n2: Display list of all Rooms" +
            "\n3: Add a new Booking" +
            "\n4: Display Booking" + 
            "\n5: Display Bookings by Room" +
            "\n6: Display Booking grid" +
            "\n0: Exit \n\n");
            
            choice = input.nextInt();
            
            
            if(choice == 1){
                option1();
            }else if(choice == 2){
                option2();
            }else if(choice == 3){
                option3();
            }else if(choice == 4){
                option4();
            }else if(choice == 5){
                option5();
            }else if(choice == 6){
                option6();
            }else if(choice == 0){
                exit = true;
                System.out.print("Shuting down system...");
            }
            
        }
    }
    
    
    public static void option1(){
        Scanner input = new Scanner(System.in);
        int num;
        
        Scanner input2 = new Scanner(System.in);
        String str;
        
        System.out.print("Enter the room's name: ");
        str = input2.nextLine();
        System.out.print("Enter the room's seating capacity: ");
        num = input.nextInt();
                
        String response = rentalSys.addRoom(str,num);
        System.out.print(response);
        promptEnterKey();
    }
    
    public static void option2(){
         String response =rentalSys.getRoomList();
         System.out.print(response);
         promptEnterKey();
    }
    
    public static void option3(){
        
         Scanner input1 = new Scanner(System.in);
         String str1;
         Scanner input2 = new Scanner(System.in);
         int num;
         Scanner input3 = new Scanner(System.in);
         int num2;
        
         System.out.print("Enter the booking's description: ");
         str1 = input1.nextLine();
         System.out.print("Enter the booking's duration: ");
         num = input2.nextInt();
         System.out.print("Enter the required number of seats: ");
         num2 = input3.nextInt();
        
         String response=rentalSys.addBooking(str1,num,num2);
         System.out.print(response);
         promptEnterKey();
    }
    
    public static void option4(){
         Scanner input = new Scanner(System.in);
         int id;
         
         System.out.print("Enter the booking's ID: ");
         id = input.nextInt();
         
         String response = rentalSys.getBooking(id);
         System.out.print(response);
         promptEnterKey();
    }
    
    public static void option5(){
        
        Scanner input = new Scanner(System.in);
        String roomID;
        
        System.out.print("Enter the roomID: ");
        roomID = input.nextLine();
        
        
        String response = rentalSys.getBookingsByRoom(roomID);
        System.out.print(response);
        promptEnterKey();
    }
    
    public static void option6(){
        String response = rentalSys.getBookingGrid();
        System.out.print(response);
        promptEnterKey();
    }
    
    public static void promptEnterKey(){
    Scanner pause = new Scanner(System.in);
    System.out.print("\n\npress Enter to continue");
    pause.nextLine();
    }


}
