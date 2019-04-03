
/* Jade Chattergoon 816007199 COMP2603 OOP1 ASG1
 User Interface for the Application
 */
import java.util.Scanner;

public class RentalConsole
{
    // instance variables - replace the example below with your own
    
    public static void main(String[] args){
    int choice;
    RentalSystem rentalSystem= new RentalSystem();
    
    choice=rentalSystem.menu();
     while(choice!=0){
        
        if(choice==1){
            System.out.println("Enter room name (FORMAT ABC): ");
            
            Scanner roomNameInput=new Scanner(System.in);
            char roomNameToCharArray[];
            String enteredRoomName=roomNameInput.next();
            roomNameToCharArray=enteredRoomName.toCharArray();
            boolean validate=rentalSystem.roomNameValidation(roomNameToCharArray);
            while(validate==false){
                System.out.println("Please try again with format ABC:");
                
                enteredRoomName=roomNameInput.next();
                roomNameToCharArray=enteredRoomName.toCharArray();
                validate=rentalSystem.roomNameValidation(roomNameToCharArray);
            }
            
            System.out.println("Enter room capacity: ");
            Scanner capacityInput=new Scanner(System.in);
            char roomCapacityToCharArray[];
            String enteredRoomCapacity=capacityInput.next();
            roomCapacityToCharArray=enteredRoomCapacity.toCharArray();
            boolean isDigit=rentalSystem.validateInt(roomCapacityToCharArray);
            while(isDigit==false){
                System.out.println("Please try again with a whole number:");
                enteredRoomCapacity=capacityInput.next();
                roomCapacityToCharArray=enteredRoomCapacity.toCharArray();
                isDigit=rentalSystem.validateInt(roomCapacityToCharArray);
            }
            int validInput=Integer.parseInt(new String(roomCapacityToCharArray));
            
            String roomAdded=rentalSystem.addRoom(enteredRoomName,validInput);
            System.out.println(roomAdded);
            choice=rentalSystem.menu();
        }
        if(choice==2){
            System.out.println("ROOM LIST: ");
            String roomList=rentalSystem.getRoomList();
            System.out.println(roomList);
            choice=rentalSystem.menu();
        }
        if(choice==3){
            System.out.print("Enter event description: ");
            Scanner descriptionInput= new Scanner(System.in);
            String enteredDescription=descriptionInput.next();
            
            System.out.print("Enter event duration (hours): ");
            Scanner durationInput = new Scanner(System.in);
            String enteredDuration =durationInput.next();
            char durationToCharArray[];
            durationToCharArray=enteredDuration.toCharArray();
            boolean isDigit=rentalSystem.validateInt(durationToCharArray);
            while(isDigit==false){
                System.out.println("Please try again with a whole number:");
                enteredDuration=durationInput.next();
                durationToCharArray=enteredDuration.toCharArray();
                isDigit=rentalSystem.validateInt(durationToCharArray);
            }
            int validInput1=Integer.parseInt(new String(durationToCharArray));
            
            System.out.print("Enter attendance number: ");
            Scanner attendanceInput= new Scanner(System.in);
            String enteredAttendance= attendanceInput.next();
            char attendanceToCharArray[];
            attendanceToCharArray=enteredAttendance.toCharArray();
            isDigit=rentalSystem.validateInt(attendanceToCharArray);
            while(isDigit==false){
                System.out.println("Please try again with a whole number:");
                enteredAttendance=attendanceInput.next();
                attendanceToCharArray=enteredAttendance.toCharArray();
                isDigit=rentalSystem.validateInt(attendanceToCharArray);
            }
            int validInput2=Integer.parseInt(new String(attendanceToCharArray));
            
           
            String bookingAdded=rentalSystem.addBooking(enteredDescription,validInput1,validInput2);
            System.out.println(bookingAdded);
            choice=rentalSystem.menu();
        }
        if(choice==4){
            System.out.print("Enter a Booking ID : ");
            Scanner bookingIDInput=new Scanner(System.in);
            String enteredBookingID=bookingIDInput.next();
            char IDToCharArray[];
            IDToCharArray=enteredBookingID.toCharArray();
            boolean isDigit=rentalSystem.validateInt(IDToCharArray);
            while(isDigit==false){
                System.out.println("Please try again with a whole number:");
                enteredBookingID=bookingIDInput.next();
                IDToCharArray=enteredBookingID.toCharArray();
                isDigit=rentalSystem.validateInt(IDToCharArray);
            }
            int validInput1=Integer.parseInt(new String(IDToCharArray));
            
            
            
            String bookingGotten=rentalSystem.getBooking(validInput1);
            System.out.println(bookingGotten);
            choice=rentalSystem.menu();
        }
        if(choice==5){
            System.out.print("Enter Room ID: ");
            Scanner roomIDInput=new Scanner(System.in);
            String enteredRoomID=roomIDInput.next();
            String bookingListByRoom=rentalSystem.getBookingsByRoom(enteredRoomID);
            System.out.println(bookingListByRoom);
            choice=rentalSystem.menu();
        }
        if(choice==6){
            System.out.println("BOOKING GRID: ");
            String bookingGrid=rentalSystem.getBookingGrid();
            System.out.println(bookingGrid);
            choice=rentalSystem.menu();
        }
    }
    if(choice==0){
            System.exit(0);
        }
  
     
        
        
    }
    
    

    
    
}
