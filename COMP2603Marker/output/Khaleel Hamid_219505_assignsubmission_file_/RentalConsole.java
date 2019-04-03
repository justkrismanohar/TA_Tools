import java.util.Scanner;//STUDENT ID: 816010298
public class RentalConsole{
    public static void menu(){
        System.out.println("   Choose a menu option.");
        System.out.println("1: Add a new Room");
        System.out.println("2: Display list of all Rooms");
        System.out.println("3: Add a new Booking");
        System.out.println("4: Display Booking");
        System.out.println("5: Display Bookings by Room");
        System.out.println("6: Display Booking grid");
        System.out.println("0: Exit");
    }
    
    public static void main(String[] args){
        menu();
        int option = -1;
        Scanner scannerOptions = new Scanner(System.in);
        option = scannerOptions.nextInt();
        RentalSystem opt1 = new RentalSystem();
        while(option!=0){
            if(option==1){
                
                Scanner scannerRoomName = new Scanner(System.in);
                Scanner scannerRoomCapacity = new Scanner(System.in);
                System.out.println("Enter Room Name. Format(ABC)");
                String rName = scannerRoomName.nextLine();
                System.out.println("Enter Room Capacity.");
                int rCapacity = scannerRoomCapacity.nextInt();    
                String newRoom = opt1.addRoom(rName,rCapacity);
                System.out.println(newRoom);
                menu();
                option = scannerOptions.nextInt();
            }
            
            if(option==2){
                System.out.println(opt1.getRoomList());
                menu();
                option = scannerOptions.nextInt();
            }
            
            if(option==3){
                Scanner scannerBkingDescription = new Scanner(System.in);
                Scanner scannerBkingDuration = new Scanner(System.in);
                Scanner scannerBkingAttendance = new Scanner(System.in);
                System.out.println("Enter event description.");
                String bkDescription = scannerBkingDescription.nextLine();
                System.out.println("Enter event duration. (Hours)");
                int bkDuration = scannerBkingDuration.nextInt();
                System.out.println("Enter Attendance Number.");
                int bkAttendance = scannerBkingAttendance.nextInt();
                String newBooking = opt1.addBooking(bkDescription,bkDuration,bkAttendance);
                System.out.println(newBooking);
                menu();
                option = scannerOptions.nextInt();
            }
            
            if(option==4){
                Scanner scannerBkingID = new Scanner(System.in);
                System.out.println("Enter Booking ID(Note:BookingIDs start at 7): ");
                int bkID = scannerBkingID.nextInt();
                String bookingGet = opt1.getBooking(bkID);
                System.out.println(bookingGet);
                menu();
                option = scannerOptions.nextInt();
            }
            
            if(option==5){
                Scanner scannerRmID = new Scanner(System.in);
                System.out.println("Enter Room ID");
                String RmID = scannerRmID.nextLine();
                String bookingsByRoomGet = opt1.getBookingsByRoom(RmID);
                System.out.println(bookingsByRoomGet);
                menu();
                option = scannerOptions.nextInt();
            }
            if(option==6){
                int i=0;
                String totalGrid;
                while(opt1.rooms[i]!=null&&i<8){
                    totalGrid = opt1.getBookingGrid();
                    System.out.println(totalGrid);
                    i++;
                }
                menu();
                option = scannerOptions.nextInt();
            }
            if(option==0){
                System.out.println("This is the end.");
                break;
            }
        }
    }
}