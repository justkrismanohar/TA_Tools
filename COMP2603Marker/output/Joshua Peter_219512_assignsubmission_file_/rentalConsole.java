/*
StudentID: 816117607
StudenName: Joshua Peter:
Assignment: 1
*/
import java.util.Scanner;
public class rentalConsole
{
    public static void main(String[] args){
        String optionStr;
        int option=0;
        String room;
        String description;
        String roomID;
        String seating;
        String durationStr;
        int duration=0;
        String seatsStr;
        int seats=0;
        String bookingID;
        String bookingIDNum;
        RentalSystem room3 = new RentalSystem();
        
        run: while (true){
                System.out.println("Choose a menu option");
                System.out.println("1: Add a new room to the system");
                System.out.println("2: Display a list of all rooms managed by the system");
                System.out.println("3: Add a new booking to the system");
                System.out.println("4: Display an existing booking based on a unique ID");
                System.out.println("5: Display bookings by room");
                System.out.println("6: Display a booking grid of all rooms and booked slots");
                System.out.println("0: exit");
                
                Scanner screen = new Scanner(System.in);
                optionStr = screen.next();
                if (room3.validateNumbers(optionStr)){       
                    option =  Integer.parseInt(optionStr);
                }
                else System.out.println("Number Value was not entered\n");
                
                switch(option){
                    case 1:{
                        System.out.print("Please enter room name (Format ABC):");
                        room = screen.next();
                        System.out.print("Please enter room capacity: ");
                        seating = screen.next();
                        if (room3.validateNumbers(seating)){       
                            System.out.println(room3.addRoom(room,Integer.parseInt(seating)));
                        }
                        else System.out.println("Number Value was not entered\n");
                        
                        break;
                    }
                    case 2:{
                        System.out.println(room3.getRoomList());
                        break;
                    }
                    case 3:{
                        System.out.print("Please enter event description:");
                        description = screen.next();
                        
                        System.out.print("Please enter event duration: ");
                        durationStr = screen.next();
                        if (room3.validateNumbers(durationStr)){       
                            duration = Integer.parseInt(durationStr);
                        }
                        else System.out.println("Number Value was not entered\n");
                        
                        System.out.print("Please enter attendance number: ");
                        seatsStr = screen.next();
                        if (room3.validateNumbers(seatsStr)){       
                            seats = Integer.parseInt(seatsStr);
                        }
                        else System.out.println("Number Value was not entered\n");
                        
                        System.out.println(room3.addBooking(description,duration,seats));
                        break;
                    }
                    case 4:{
                        System.out.print("Please enter booking ID: ");
                        
                        bookingID = screen.next();
                        if (room3.validateNumbers(bookingID)){
                            System.out.println(room3.getBooking(Integer.parseInt(bookingID)));
                        }
                        else System.out.println("Number Value was not entered\n");
                        break;
                    }
                    case 5:{
                        System.out.print("Please enter Room ID:");
                        roomID = screen.next();
                        
                        System.out.println(room3.getBookingsByRoom(roomID));   
                        break;
                    }
                    case 6:{
                        System.out.println(room3.getBookingGrid());   
                        break;
                    }
                    case 0:
                        break run;
                    
            } 
        }
    }
    
    
}
