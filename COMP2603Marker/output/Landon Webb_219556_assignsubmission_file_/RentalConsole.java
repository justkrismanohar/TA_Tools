import java.util.Scanner;
//816004741
public class RentalConsole
{
  
     public static void main(String[] args){  
         
         RentalSystem rs=new RentalSystem();
         
         Scanner scanner = new Scanner(System.in);
         
         int choice;
         System.out.println("  Choose a menu option");
         System.out.println("1: Add a new Room");
         System.out.println("2: Display list if all Rooms");
         System.out.println("3: Add a new Booking");
         System.out.println("4: Display Booking");
         System.out.println("5: Display Bookings by Room");
         System.out.println("6: Display Booking Grid");
         System.out.println("0: Exit");
         
         choice=scanner.nextInt();
         String name;
         int sc;
         String des;
         int dur;
         int size;
                  
         while(choice!=0){
             switch(choice){
                 case 1: {System.out.println("Enter Room Details: ");
                          name=scanner.next();
                          sc=scanner.nextInt();
                          rs.addRoom(name,sc);}
                          break;
                 case 2: System.out.println(rs.getRoomList());
                         break;
                 case 3: {System.out.println("Enter Booking Details: ");
                          des=scanner.next();
                          dur=scanner.nextInt();
                          size=scanner.nextInt();
                          rs.addBooking(des,dur,size);}
                          break;
                 case 4: {System.out.println("Enter Booking ID: ");
                          int id=scanner.nextInt();
                          System.out.println(rs.getBooking(id));}
                          break;
                 case 5: {System.out.println("Enter Room ID: ");
                          String ID=scanner.next();
                          System.out.println(rs.getBookingsByRoom(ID));}
                          break;
                 case 6: System.out.println(rs.getBookingGrid());
                         break;
                 default: choice=0;
                          break;
             
                 
                  
        
                }
                
                System.out.println("  Choose a menu option");
                System.out.println("1: Add a new Room");
                System.out.println("2: Display list if all Rooms");
                System.out.println("3: Add a new Booking");
                System.out.println("4: Display Booking");
                System.out.println("5: Display Bookings by Room");
                System.out.println("6: Display Booking Grid");
                System.out.println("0: Exit");
         
                choice=scanner.nextInt();
         
        }
    }

    
}
