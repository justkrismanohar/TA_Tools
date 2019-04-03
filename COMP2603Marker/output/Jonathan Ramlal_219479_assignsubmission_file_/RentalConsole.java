import java.util.Scanner;

public class RentalConsole
{
    
    public static void main(String[] args){
        RentalSystem r1= new RentalSystem();
        Scanner scanner = new Scanner(System.in);
    while(true){
        int option=menu();
        if (option == 1){
            
            System.out.println("Name of Room:");
            String name=scanner.next();
            while (name.length()!=3){
               System.out.println("Name of room is limited to 3 characters, please re-enter a valid name::");
               name=scanner.next();
            }
            while(!name.matches("[a-zA-Z]+")){
               System.out.println("Room names consists of letters only, please re-enter a valid room name: ");
               name=scanner.next();
            }
            System.out.println("Seating Capacity:");
            int SeatingCapacity=scanner.nextInt();
            System.out.println(r1.addRoom(name,SeatingCapacity));           
        }
        else if (option==2){
            System.out.println(r1.getRoomList());  
        }
        else if (option==3){
            System.out.println("Description:");
            String description=scanner.next();
            System.out.println("Duration:");
            int duration=scanner.nextInt();
            System.out.println("Number of seats required");
            int seats=scanner.nextInt();
            System.out.println(r1.addBooking(description,duration,seats));      
        }
        else if(option==4){
            System.out.println("Enter BookingID:");
            int b1=scanner.nextInt();
            System.out.println(r1.getBooking(b1));
        }
        else if(option==5){
        System.out.println("Enter RoomID ");
        String roomID=scanner.next();
        
        System.out.println(r1.getBookingsByRoom(roomID.toUpperCase()));
        }
        else if(option==6){
            System.out.println(r1.getBookingGrid());
        
        }
        else if(option == 0){
            System.exit(0);
        }
    }
    }  
    public static int menu(){
        int option=0;
        System.out.println("Rental Console User Interface");
        System.out.println("========================================================================");
        System.out.println("1. Add a new room to the system\n2. Display a list of all rooms managed by the system\n3. Add a new booking to the system\n4. Display an existing booking based on a unique ID\n5. Display bookings by room\n6. Display a booking grid of all rooms and booked slots\n");
        System.out.println("0. Exit");
        System.out.println("------------------------------------------------------------------------");
        do{
        try{
            System.out.println("Select an option:");
            Scanner scanner = new Scanner(System.in);
            option = scanner.nextInt(); 
        }
        catch(Exception e){
            System.out.println("Invalid Option");
        }
        }while (option==0);
        return option;
    }
}
