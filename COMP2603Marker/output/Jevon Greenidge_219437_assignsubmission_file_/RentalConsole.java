
/**
 816010441 Jevon greenidge
 */

import java.util.Scanner;
public class RentalConsole
{
    public static void main (String[] args){
    RentalSystem rsl= new RentalSystem();
    String menu= "\nChoose a menu option"+
                      "\n1: Add a new Room"+
                      "\n2: Display list of all Rooms"+
                      "\n3: Add a new Booking"+
                      "\n4: Display Booking"+
                      "\n5: Display Bookings by Room"+
                      "\n6: Display Booking grid"+
                      "\n0: Exit";
                      
     System.out.println(menu);
     Scanner keyboard=new Scanner(System.in);
     int choice;
     choice=keyboard.nextInt();
    
    String description,room,name;
    int duration, seats,id;
    
    
    String content;
    String nextOption="\nChoose another option";
    while(choice!=0){
        if (choice == 1){
            content="\nPlease enter the name of the room then the seating capacity. eg'FST'then'100'";
                System.out.println(content);
                name = keyboard.next();
                seats = keyboard.nextInt();
                System.out.println(rsl.addRoom(name, seats));
                System.out.println(nextOption);
            }
    
    
    if (choice ==2) {
    System.out.println(rsl.getRoomList());
                System.out.println(nextOption);
    }
    
    
    if (choice ==3){
        content ="\nPlease enter the description,duration and seating required for the booking. eg'Lab'then'2'then'80'";
                System.out.println(content);
                description = keyboard.next();
                duration = keyboard.nextInt();
                seats = keyboard.nextInt();
                System.out.println(rsl.addBooking(description, duration, seats));
                System.out.println(nextOption);
        
        
    }
    
    if( choice ==4){
        content ="Please enter the ID of the booking. eg'2'";
                System.out.println(content);
                id = keyboard.nextInt();
                System.out.println(rsl.getBooking(id));
                System.out.println(nextOption);
        
    }
    
    if (choice== 5)
    {
        
    content ="\nPlease enter the ID of the room. eg'FST100'";
                System.out.println(content);
                room = keyboard.next();
                System.out.println(rsl.getBookingsByRoom(room));
                System.out.println(nextOption);
            }
    
    
    if (choice == 6){
        System.out.println(rsl.getBookingGrid());
        System.out.println(nextOption);
    }
     else 
     System.out.println(nextOption);
         
     choice =keyboard.nextInt();
    }
   content ="Thank you, enjoy your day";
    System.out.println(content);
    System.exit(0);
}


}
     
    
    
    
    
    
    
    
    



