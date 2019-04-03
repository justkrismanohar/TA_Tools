 import java.util.Scanner;//import scanner class
//andrez Bravo 816011156
public class RentalConsole
{
   private RentalSystem rentalSystem;
    public RentalConsole()
    {
     
        
    }

        
       
        public static void main(String[] args)
      {
         
          RentalSystem rentalSystem=new RentalSystem();//create new instance of rentalsystem
          int x; String y;
          int i=1;
          Scanner screen=new Scanner( System.in );//create new scanner
          while(i!=0){ //loop the main
              
              System.out.println(" RentalConsole: Options ");
              System.out.println("1.Add a room");
              System.out.println("2.Display rooms managed by system ");
              System.out.println("3.Add a new booking");
              System.out.println("4.Display booking");
              System.out.println("5.Display room bookings");
              System.out.println("6.Display booking grid for all rooms");
              System.out.println("0.exit");
              x=screen.nextInt(); 
              y=screen.nextLine();//fix an issue with nextline input;
              switch(x){//access the menu functions
                  case 1:
                  System.out.println("enter room name and Seating capacity");
                  String name;
                  name=screen.nextLine();
                  int seatingCapacity;
                  seatingCapacity=screen.nextInt();
                  System.out.println(rentalSystem.addRoom(name,seatingCapacity));
                  break;
                
                   case 2:
                  System.out.println("Displaying rooms");
                  System.out.println(rentalSystem.getRoomList());
                   break;
                  
                   case 3:
                  System.out.println("enter description then the duration and then the numSeating");
                  String description=screen.nextLine();
                  int duration=screen.nextInt();  int numSeating=screen.nextInt();
                   System.out.println(rentalSystem.addBooking(description,duration,numSeating));
                  break;
                  
                   case 4:
                  System.out.println("enter bookingID");
                  int bookingID=screen.nextInt();
                   System.out.println(rentalSystem.getBooking(bookingID));
                  break;
                  
                   case 5:
                  System.out.println("enter roomID");
                  String roomID=screen.nextLine();
                   System.out.println(rentalSystem.getBookingsByRoom(roomID));
                  break;
                  
                   case 6:
                  System.out.println("Displaying booking grid");
                   System.out.println(rentalSystem.getBookingGrid());
                  break;
                  
                   case 0:
                  System.out.println("Exiting");
                  i=0;
                  break;
                }//end switch
            }//endwhile
          
          
      }//end main
}
