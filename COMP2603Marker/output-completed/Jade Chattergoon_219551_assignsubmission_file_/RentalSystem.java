
/*/* Jade Chattergoon 816007199 COMP2603 OOP1 ASG1
Operates Bookings and Rentals
 */
import java.util.Scanner;
public class RentalSystem
{
    // instance variables - replace the example below with your own
    private static Room[] rooms; 
    private int numRooms;
    private String roomList;
    private static String bookingAdded;
    private String bookingDetails;
    private String bookingGrid="";
    private String bookingGridPrint="";
    private int countRooms;
    private int charCounter;
    

  
  public RentalSystem()
    {
        // initialise instance variables
       rooms=new Room[10];
       numRooms=0;
       
    }

  public String getBookingsByRoom(String roomID){
        
        for(countRooms=0;countRooms<numRooms;countRooms++){ //search all rooms
            
            if(rooms[countRooms].getRoomID().equals(roomID)){ //if there is a match
                System.out.println(rooms[countRooms].toString()); //print room details
                return rooms[countRooms].getBookingList(); //return bookingList
            }
        }
        return "Room ID is not found";
    }
          
  public String getBookingGrid(){
        if(numRooms==0){
            return " No rooms in the system";
        }
        bookingGrid="";
        for(countRooms=0;countRooms<numRooms;countRooms++){
             bookingGrid=bookingGrid + "\n" + rooms[countRooms].getDetailedBookingGrid();
            
        }
        return bookingGrid;
     }
     
  public String getBooking(int bookingID){
        for(countRooms=0;countRooms<numRooms;countRooms++){
               
               bookingDetails=rooms[countRooms].getBookingDetails(bookingID);
                if(!(bookingDetails.equals("No such BookingID exists."))){
               return bookingDetails;
               }
               
            }
          
        return "Booking ID not found.";
        }  
        
  public String getRoomList(){
        if(numRooms==0){
            return "No rooms in the system.";
        }
        roomList=rooms[0].toString();
        for(countRooms=1;countRooms<numRooms;countRooms++){
            roomList=roomList + "\n" + rooms[countRooms].toString();
        }
        
        return roomList;
    }     
    
  public String addRoom(String name, int seatingCapacity)
    {
        if(numRooms<10){ // less than max 
        Room room= new Room(name,seatingCapacity); //new room can be added
        rooms[numRooms]=room; //adds room obj to array
        numRooms+=1; // increment numRooms
        
        return (room.toString());
        }
        return "Cannot add room; Max rooms reached.";
    }
    
  public  String addBooking(String description,int duration, int numSeating){
        if(numRooms==10){
            return "Cannot add Booking.";
        }
        
        for(countRooms=0;countRooms<numRooms;countRooms++){
           
            bookingAdded=rooms[countRooms].addBooking(description,duration,numSeating);
            if(bookingAdded!=null){
               return bookingAdded;
            }
       
        }
       return "Cannot add Booking.";
    }
    
  public int menu(){
        System.out.println("Choose a menu option");
        System.out.println("1: Add a new Room");
        System.out.println("2: Display list of all Rooms");
        System.out.println("3: Add a new Booking");
        System.out.println("4: Display Booking");
        System.out.println("5: Display Bookings by Room");
        System.out.println("6: Display Booking grid");
        System.out.println("0: Exit");
        
        Scanner input= new Scanner(System.in);
        String choice=input.next();
        char choiceToCharArray[];
        choiceToCharArray=choice.toCharArray();
            boolean isDigit=validateInt(choiceToCharArray);
            while(isDigit==false || choiceToCharArray.length!=1 || choiceToCharArray[0]<'0' || choiceToCharArray[0]>'6' ){
                System.out.println("Please try again with a whole number between 0 and 6:");
                choice=input.next();
                choiceToCharArray=choice.toCharArray();
                isDigit=validateInt(choiceToCharArray);
            }
            int validInput=Integer.parseInt(new String(choiceToCharArray));
        
        return validInput;
    }
           
  public  boolean roomNameValidation(char roomNameInput[]){
      charCounter=0;
      while(charCounter<roomNameInput.length){
          if(roomNameInput[charCounter]>'Z' || roomNameInput[charCounter]<'A'){
             
            return false;
            }
          else{
              if(charCounter==roomNameInput.length-1 && charCounter==2){
                  return true;
                }
   
            }
          charCounter++;
          
        }
        return false;
    }
        
  public  boolean validateInt(char roomCapacityToCharArray[]){
     charCounter=0;
     while(charCounter<roomCapacityToCharArray.length){
         if(Character.isDigit(roomCapacityToCharArray[charCounter])==false){
             return false;
            }
           else{
               charCounter++;
            }
           
        }
         return true;
    }
    }
    
    
