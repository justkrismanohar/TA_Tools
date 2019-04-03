import java.util.Scanner;

public class RentalConsole{
    public int choice;
    public boolean exit=false;
    
public void printMenu(){
    
    System.out.println("Welcome to the Rental System Console");
    System.out.println("Choose a menu option");
    System.out.println("1: Add a new Room");
    System.out.println("2: Display list of all Rooms");
    System.out.println("3: Add a new Booking");
    System.out.println("4: Display Booking");
    System.out.println("5: Display Bookings by Room");
    System.out.println("6: Display Booking grid");
    System.out.println("0: Exit");

}
private void runMenu(){
        printMenu();
        choice=getInput();
        //performAction(choice);
}

private int getInput(){
    choice= -1;
    System.out.println("Enter your choice");
    Scanner screen= new Scanner(System.in);
    choice= screen.nextInt();
    
    while(choice>=0 || choice<=6){
    //if(choice<0 && choice<6)
        switch(choice){
            case 0:
            break;
            case 1:
            System.out.print("Enter room name (Format ABC): ");
            String name=screen.next();
            System.out.println("\n "+"Enter room capacity: ");
            int seatingCapacity =screen.nextInt();
            RentalSystem class1= new RentalSystem();
            String choice1=class1.addRoom(name,seatingCapacity);
            break;    
        
            case 2:
                RentalSystem class2= new RentalSystem();
                String choice2=class2.getRoomList();
                break;
            case 3:
                 System.out.print("\nEnter event description: ");
                 String description= screen.next();
                 System.out.print("\nEnter event duration(hours): ");
                 int duration=screen.nextInt();
                 System.out.println("Enter attendance number: ");
                 int seats=screen.nextInt();
                 break;
    }
}
return choice;
}

public static void main(String [] args){
    RentalConsole menu= new RentalConsole();
    menu.runMenu();    
       
    }
}

    
 