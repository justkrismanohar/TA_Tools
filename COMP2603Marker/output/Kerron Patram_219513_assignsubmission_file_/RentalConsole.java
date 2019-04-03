//Kerron Patram
//816003101
import java.util.Scanner; //Import statement for using a java.time.LocalDate object. Refer to API

//Rental class providing and executing menu options
public class RentalConsole
{
    //declaration of attributes of RentalConsole class
    private static RentalConsole console = new RentalConsole();
    public static Scanner keyboard = new Scanner(System.in);//accepts input from user via the keyboard
    private RentalSystem R = new RentalSystem(); //Creates a RentalSystem object
    private String name="";
    private int seatingCapacity=0;
    private String eventType="";
    private int period=0;
    private int Numseating=0;
    private int bookID=0;
    private String roomID="";
        
    //Main
    public static void main(String[] args)
    {
        console.mainMenu();
    }
    
    //Displays User Interface
    public void mainMenu()
    {
        System.out.println("**************MAIN MENU**************");
        System.out.println("1: Add a new room");  
        System.out.println("2: Display list of all Rooms");
        System.out.println("3: Add a new Booking");
        System.out.println("4: Display Booking");
        System.out.println("5: Display Bookings by Room");
        System.out.println("6: Display Booking grid");
        System.out.println("0: Exit");
        System.out.println("*************************************");        
        
        int choice = keyboard.nextInt();
        
        //When the variable being switched on is equal to a case, the statements following that case will execute until a break statement is reached
        switch(choice){
            case 1: console.option1();
            break;//When a break statement is reached, the switch terminates, and the flow of control jumps to the next line following the switch statement
            
            case 2: console.option2();
            break;
           
            case 3: console.option3();
            break;
            
            case 4: console.option4();
            break;
            
            case 5: console.option5();
            break;
            
            case 6: console.option6();
            break;
             
            case 0: System.out.println("BYE BYE >_< ");//Exit
            break;
            
            default: System.out.println("Invalid option \n");//if any number outside 0-6 is entered
            console.mainMenu();
            break;
        }    
    }
    
    //Adds a new room to the system
    public void option1()
    {
        System.out.println("Enter room name (FORMAT ABC): ");
        name = keyboard.next();
        while (name.length()!=3){
               System.out.println("Room names must be 3 characters long, enter a valid name:");
               name=keyboard.next();
            }
            while(!name.matches("[a-zA-Z]+")){
               System.out.println("Room names must only be made up of letters, enter valid name:");
               name=keyboard.next();
            }
        System.out.println("Enter the seating capacity of the room: ");
        seatingCapacity=keyboard.nextInt();
        System.out.println(R.addRoom(name,seatingCapacity));
        console.mainMenu();
    }
    
    //Displays all the rooms managed  by the system
    public void option2()
    {
        System.out.println("Room listing:");
        System.out.println(R.getRoomlist());
        console.mainMenu();
    }
    
    //Checks if character is uppercase
    public boolean isCapitalChar(char ch)
    {
        if (ch>=65 && ch<=90)
            return true;
         return false;
    }
    
    
    public boolean isNum(char num)
    {
        if (num>=48 && num<=57)
            return true;
        return false;
    }
    
    //Add a new booking to the system 
    public void option3()
    {
        System.out.println("Enter the type of the event, e.g Lab, Lecture: ");
        eventType=keyboard.next();
        System.out.println("Enter the period of the event in hours: ");
        while(!keyboard.hasNextInt())
        {
            System.out.println("Invalid!!!Enter valid number of hours:");
            keyboard.next();
        }
        period=keyboard.nextInt();
        System.out.println("Enter the number of seats needed: ");
        while(!keyboard.hasNextInt())
        {
                System.out.println("Invalid Entry!!! Enter number of seats required:");
                keyboard.next();
        }
        Numseating=keyboard.nextInt();       
        System.out.println (R.addBooking(eventType, period, Numseating));
        console.mainMenu();
    }
    
    //Displays an existing booking based on a unique ID
    public void option4()
    {
        System.out.println("Enter booking ID: ");
        while(!keyboard.hasNextInt())
        {
                System.out.println("Invalid!!! Booking IDs must be integers, Enter valid BookingID");
                keyboard.next();
        }
        bookID=keyboard.nextInt();
        System.out.println(R.getBooking(bookID));
        console.mainMenu();     
    }
    
    //Display bookings by room
    public void option5()
    {
        System.out.println("Enter Room ID: ");
        roomID=keyboard.next();
        System.out.println (R.getBookingsByRoom(roomID));
        console.mainMenu();
    }
    
    //Display a booking grid of all rooms and booked slots
    public void option6()
    {
        System.out.println (R.getBookingGrid());
        console.mainMenu();
    }
   
}