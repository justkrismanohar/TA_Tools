


public class RentalConsole
{
    /*ID: 816009134 NAME: JERREL WILLIAMS*/
 

   public static void main(String[] args)
   {
      
      java.util.Scanner sc = new java.util.Scanner(System.in);
      int choice;
      RentalSystem rs = new RentalSystem();
      do{
          
        System.out.println("1. Add a new Room");
        System.out.println("2. Display list of all Rooms");
        System.out.println("3. Add a new Booking");
        System.out.println("4. Display Booking");
        System.out.println("5. Display Bookings by Room");
        System.out.println("6. Display Bookings Grid");
        System.out.println("0. Exit");
        System.out.print("\nEnter Your Menu Choice: ");
        choice = sc.nextInt();
        
        switch(choice){
            case 1: 
               
                System.out.println("Enter a room name: ");
                String name=sc.next();
                System.out.println("Enter seating capacity: ");
                int seat=sc.nextInt();
                System.out.println(rs.addRoom(name,seat));
                break;
         
            case 2:
              System.out.println(rs.getRoomList());
               break;
            case 3:
                System.out.println("Enter description: ");
                String desc = sc.next();
                System.out.println("Enter duration: ");
                int dur = sc.nextInt();
                System.out.println("Enter seating: ");
                int seats = sc.nextInt();
                System.out.println(rs.addBooking(desc,dur,seats));
                break;
            case 4: 
                System.out.println("Enter booking ID: ");
                int bID = sc.nextInt();
                System.out.println(rs.getBooking(bID));
                break;
            case 5:
                System.out.println("Enter RoomID: ");
                String rID = sc.next();
                System.out.println(rs.getBookingsByRoom(rID));
                break;
            case 6:
                System.out.println(rs.getBookingGrid());
                break;
                
            case 0:
                 System.out.println("Exiting...");
                 System.exit(0);
                 break;
              default:
                System.out.println(choice + " is invalid. Try again\n");
              
                
                
            
            
            }
            }while(choice!=0);  
                
                
                
          
        
      
      
   }
  



}
