//VERNESSA BOODRAM
//816006133

import java.util.Scanner;

public class Room {
    private final int numSlots = 8;
    private static int roomIDCounter = 100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private int countingSlots;
    
    //Constructor
    public Room (String name, int seatingCapacity) {
        bookings = new Booking[numSlots];
        this.roomID = name + Integer.toString(roomIDCounter);
        this.seatingCapacity = seatingCapacity;
        roomIDCounter = roomIDCounter + 100;
    }
    
    //Methods
    //1.
    public String addBooking (String description, int duration, int seats) {
        
        int count = 0;
        int timeRemaining = 0;
        
       if(canFitNumbers(seats)  && canFitTime(duration)) { //checking to see if there are slots and seats available
          
           Booking b1 = new Booking(description, duration, seats); //Created booking
             
           if (bookings[0] == null) { //checking to see if the first element in the array is empty
               
               for (int i=0; i<duration; i++) {
                   bookings[i] = b1; //save the new booking entry into the array
                   
                }
            }
            else {
                for (int i=0; i<numSlots; i++) {
                    if(bookings[i] != null) //its its not empty 
                        count = count + 1 ; //then count how much is taken up
                }
                
                timeRemaining = numSlots - count; //slots available still/ 
                
                int newDuration = count + duration; //stoping value in the loop 
                
                for (int i=0;i<newDuration;i++)
                       bookings[i] = b1;
                
            }
           return b1.toString() + roomID;
       }
       else
           return null;
    } 
    
    //2. 
    public boolean canFitNumbers (int numSeats) {
        if (numSeats < seatingCapacity)  //checking to see if the amount of seats can be accomodated 
            return true;
        else 
            return false;
    }
    
    //3.
    public boolean canFitTime (int duration) {
        
        countingSlots = 0;
        
        for (int i=0; i<numSlots; i++){ //Checking thru the number of slots from 0 - 7
            if (bookings[i] != null) // if its not null
                countingSlots++; //count the number of slots used 
        }
                if (duration <= (numSlots - countingSlots))
                    return true;
                else
                    return false;
    }
    
    //4.
    public String getBookingDetails (int bookingID) {
       
        for (int i=0; i<numSlots; i++){
            if (bookings[i].getBookingID() == bookingID) //comparing the booking ID entered to the booking ID in the array
               return bookings[i].toString() + roomID; //if a match is found then the data in that array elemnet is displayed 
        }
        
        return null;
    }
   
    //5.
    public String getBookingList () {
        
        String word="";
        
         for (int i=0; i<numSlots; i++){ //for loop to search thru the array 
            word = word + bookings[i].toString() + roomID + "\n"; //adding the strings to output 
        }
        
        if (word != null)
            return word;
            
        return null;
    }
   
    //6. 
    public String getDetailedBookingGrid () {
        
        String gridDetails = roomID + " "; //Displays the room and a space to start of the grid  
        int id;
                      
            for (int i=0; i<numSlots; i++) {
                
                if (bookings[i] == null) //if its empty 
                    gridDetails = gridDetails + " "  + " |  "; //empty grid
                    
                id = bookings[i].getBookingID();
                gridDetails = gridDetails + Integer.toString(id)   + " |  "; // bookings that occupy the slots 
            }
       
        return gridDetails;
    }
   
    //7.
    public String getRoomID () {
        return roomID;
    }
    
    //8.
    public boolean hasBooking (int bookingID) {
        
        for (int i=0; i<numSlots; i++){
            if (bookingID == (bookings[i].getBookingID())) //Comparing the value entered with each bokingID of the array
                return true;     //Only if a match is found 
        }
        return false;
    }
    
    //9. 
    public String toString() {
        
        String roomDetails;
        roomDetails = "ROOM ID: " + roomID + "   SEATING: " + seatingCapacity;
        return roomDetails;
    } 
    
    
    
    //Accessors********************************************************************************************************
    public int getRoomIDCounter(){
        return roomIDCounter;
    }
    
    public int getNumSlots() {
        return numSlots;
    }
     

} //end of Room class 