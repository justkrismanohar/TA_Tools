//816009535 Simon Ramdath
//the console

import java.util.Scanner; //imports

public class RentalConsole{
    public static void main(String[] args){ //main
        Scanner keyInput = new Scanner(System.in);
        RentalSystem R= new RentalSystem();
        
        int input=-1;
        String sinput="";
        String name="";
        int seatingCapacity=0;
        String desc="";
        int duration=0;
        int Numseating=0;
        int bookID=0;
        String roomID="";
        
        while(input!=0){
            input=-1;              //reinitializing variables
            sinput="";
            name="";
            seatingCapacity=0;
            desc="";
            duration=0;
            Numseating=0;
            bookID=0;
            roomID="";

            System.out.println("1: Add a new room");  //menu
            System.out.println("2: Display list of all Rooms");
            System.out.println("3: Add a new Booking");
            System.out.println("4: Display Booking");
            System.out.println("5: Display Bookings by Room");
            System.out.println("6: Display Booking grid");
            System.out.println("0: Exit");

            if(keyInput.hasNextInt()){
                input=keyInput.nextInt();
                sinput = keyInput.nextLine();
                
                if (input==1){
                    System.out.println("Enter the name of the room, in format 'ABC'");
                    name=keyInput.nextLine();
                    System.out.println("Enter the seating capacity of the room");
                    seatingCapacity=keyInput.nextInt();
                    System.out.println(R.addRoom(name,seatingCapacity));
                }
                else if (input==2){
                    System.out.println("Room listing");
                    System.out.println(R.getRoomlist());
                }
                else if (input==3){
                    System.out.println("Enter the description of the event, e.g lecture");
                    desc=keyInput.nextLine();
                     System.out.println("Enter the duration of the event in hours");
                    duration=keyInput.nextInt();
                   System.out.println("Enter the number of seats needed");
                    Numseating=keyInput.nextInt();       
                    System.out.println (R.addBooking(desc, duration, Numseating));
                }
                else if (input==4){
                    System.out.println("Enter the booking ID");
                    bookID=keyInput.nextInt();
                    System.out.println(R.getBooking(bookID));
                }
                else if (input==5){
                    System.out.println("Enter the Room ID");
                    roomID=keyInput.nextLine();
                    System.out.println (R.getBookingsByRoom(roomID));
                }
                else if (input==6){
                    System.out.println (R.getBookingGrid());
                }
            }
        }
    }
}