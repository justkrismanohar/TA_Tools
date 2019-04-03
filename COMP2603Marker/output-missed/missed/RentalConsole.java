 import java.util.Scanner;

public class RentalConsole 
{

   // public static int code;
    public static Scanner screen = new Scanner(System.in);
    public static RentalSystem rs= new RentalSystem();

  
    public RentalConsole()
    {
     //RentalSystem rs= new RentalSystem();
    }

   
   public static void main(String[] args)
    {
     String key;
          /*if (code > 6 ){
         System.out.println( " Invalid input. ");
         printMenu();
        } */
     key = printMenu();  
     if (key == "1") 
     { 
      System.out.println( " Input Room name " );
      String name = screen.nextLine();
      System.out.println( " Input Seating Capacity " );
      int sC = screen.nextInt();
      System.out.println(rs.addRoom(name,sC));
      printMenu();
    }
     if (key == "2") 
     {
      System.out.println(rs.getRoomList());
      printMenu();
    }
     if (key == "3") 
     { 
      System.out.println( " Input Booking description " );
      String des = screen.next();
      System.out.println( " Input Duration ");
      int dur = screen.nextInt();
      System.out.println( " Input Seating Requirements " );
      int nS = screen.nextInt();
      System.out.println(rs.addBooking(des,dur,nS));
      printMenu();   
        
    }
     if (key == "4") 
     {
      System.out.println( " Input Booking ID. ");
      int bID = screen.nextInt();
      System.out.println(rs.getBooking(bID));
      printMenu();
    }
     if (key == "5") 
     {
      System.out.println(" Input Room ID.");
      String rID = screen.next();
      System.out.println(rs.getBookingsByRoom(rID));
      printMenu();
    }
     if (key == "6") 
     {
      System.out.println(rs.getBookingGrid());
      printMenu();
    }
     if (key == "0") 
     {
      System.out.println( " Exiting... " );
      return;
    }
    
   } 
    
    public static String printMenu() {
        String key;
    
     
      System.out.println( " Choose a menu option " );
      System.out.println( " 1: Add a new Room " ); 
      System.out.println( " 2: Display a list of all Rooms " ); 
      System.out.println( " 3: Add a new Booking " ); 
      System.out.println( " 4: Display Booking " ); 
      System.out.println( " 5: Display Bookings by Room " ); 
      System.out.println( " 6: Display Booking grid " ); 
      System.out.println( " 0: Exit ");
      key = screen.next();
            //code = Integer.parseInt(key);
      return key;
  }  
     
   
}
