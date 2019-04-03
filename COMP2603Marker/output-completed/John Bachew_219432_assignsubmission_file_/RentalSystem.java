//ID#:810003511

import java.util.Scanner;

public class RentalSystem
{
    // instance variables - replace the example below with your own
    private Room[] rooms = new Room[10];
    private int numRooms;
    private int numBooks;
    private String prevName;
    private int seatCount;
    private int numCounter =100;
    private int bookCount=1;
    
    Scanner input = new Scanner(System.in);
    
    public RentalSystem()
    {
        // initialise instance variables
        numRooms = 0;
        numBooks = 0;
        rooms[0]=new Room("",0);
        rooms[1]=new Room("",0);
        rooms[2]=new Room("",0);
        rooms[3]=new Room("",0);
        rooms[4]=new Room("",0);
        rooms[5]=new Room("",0);
        rooms[6]=new Room("",0);
        rooms[7]=new Room("",0);
        rooms[8]=new Room("",0);
        rooms[9]=new Room("",0);
        
      
       

    }
    public int getNumRooms(){
        return numRooms;
    }
    public String addRoom(String name, int seatingCapacity){
        
                if(numRooms>=10){
           return "Cannot add room; Max rooms reached";
        }
        
        /*if(numRooms==0){
            System.out.println("No rooms in the system.");
        }
        */
        //System.out.println("Enter room name (Format ABC): ");
        //name = input.nextLine();
        seatCount=seatingCapacity;
        prevName=name;
        rooms[numRooms].setName(name);
        rooms[numRooms].setRoomID(name);
        
        //System.out.println("Enter room capacity: ");
        //seatingCapacity = input.next();
        rooms[numRooms].setSeatingCapacity(seatingCapacity);
        System.out.println("ROOM ID: "+rooms[numRooms].getRoomID()+" SEATS: "+rooms[numRooms].getSeatingCapacity());
        
        
        
        
        numRooms++;
        rooms[numRooms].setRoomIDCounter(numCounter);
        numCounter=numCounter+100;
        
        
                   
               
        return numCounter+prevName+name+seatingCapacity;          
        
    }
    public String getRoomList(){
        if(numRooms==0){
            System.out.println("No rooms in the system.");
            return "No rooms in the system.";
        }
        System.out.println("ROOM LIST");
        for(int i=0; i<numRooms; i++){
        System.out.println("ROOM ID: "+rooms[i].getRoomID()+" SEATS: "+rooms[i].getSeatingCapacity());
    }
        return "This is all rooms managed by system.";
    }
    public String addBooking(String description, int duration, int numSeating){
        
        rooms[numBooks].setSeatingCapacity(seatCount);
        rooms[numBooks].addBooking(description,duration,numSeating);
        
        numBooks++;
        bookCount++;
        rooms[numBooks].setRoomID(prevName);
        rooms[numBooks].setBookCount(numBooks);
        
        
        
        
       
        //System.out.println("Booking ID:"+rooms[numRooms].
        return description+duration+numSeating+numBooks+bookCount;
        }
    public String getBooking(int bookingID){
       for(int i=0; i<10; i++){
         if(rooms[i].hasBooking(bookingID)==true){
               
               return rooms[i].getBookingDetails(bookingID);
            }
        }
       System.out.println("Booking ID not found");
       return "Booking ID not found";
    
    }  
    public String getBookingsByRoom(String roomID){
        //System.out.println("ROOM ID: "+rooms[numRooms].getRoomID()+" SEATS: "+rooms[numRooms].getSeatingCapacity());
        int j=0;
        for(int i=0; i<10; i++){
           if(roomID==rooms[i].getBookingList()){
               System.out.println(rooms[i].getBookingList());
               j=i;
               
               //System.out.println(rooms[i].getBookingList());
            }
            
        }
        
         //if(roomID!=rooms[j].getBookingList()){System.out.println("No bookings found.");}
        return "Room ID not found";
    }
    public String getBookingGrid(){
        
        for(int i=0; i<10; i++){
            if(rooms[i].getRoomIDCounter()==0){
            return "No rooms in the system.";
            }
        rooms[i].getDetailedBookingGrid();
        
        }
        return "All rooms in the system.";
        
    
    
    }    
        
        
          
        
    
        
    
 }
