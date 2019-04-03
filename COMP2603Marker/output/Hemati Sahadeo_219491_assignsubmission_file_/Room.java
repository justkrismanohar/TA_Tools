//Hemati Sahadeo 
//816001653
//Assignment 1
//OOP

import java.util.Scanner;
import static java.lang.System.out;

public class Room{
    private static final int numSlots=8;
    private static int roomIDCounter=0;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    
  

    public Room(String name, int seatingCapacity){
        roomIDCounter=roomIDCounter+100;
        roomID=name+ roomIDCounter;
        this.seatingCapacity= seatingCapacity;
        bookings=new Booking[8];
        
    }
    
    public void setNull(){
          for(int i=0;i<numSlots;i++){
              bookings[i]=null;
        }
    }
   
    public String addBooking(String description, int duration, int seats){
        int i=0;
        if(canFitTime(duration) && canFitNumbers(seats)){
            Booking val=new Booking(description,duration,seats);
            while(bookings[i]!=null && i<numSlots){
              i++; 
            }
            duration=duration+i;
            for(int j=i;j<duration;j++){         
                bookings[i]=val;
            }
            String details= val.toString(); 
            System.out.println("Booking added to schedule. \n" + details); 
            return details;
        }else 
            return null;

    }
    
    //Returns true if the Room can accommodate the number of seats and false otherwise
    public boolean canFitNumbers(int numSeats){
        if(numSeats<=seatingCapacity)
            return true;
        else
            return false;
         
    }
    
   //Returns true if the Room can accommodate the event for the duration (hours) and false otherwise
    public boolean canFitTime(int duration){
        int i=0;
        while(bookings[i]!=null && i<numSlots){
              i++; 
        }
            duration=duration +i;
            if(duration<=numSlots){
                return true;
            }
            else
                return false;
       
   }
        
    
    public String getBookingDetails(int bookingID){
       int i=0;
       while(i<numSlots && bookings[i]!=null){
           if(bookings[i].getBookingID() == bookingID){
               return bookings[i].toString();
 
            } 
               i++;              
        }
         System.out.println("No booking was made for this room");
         return null;
    }
    
    
    public String getBookingList(){
        int x=0;
        String msg="";
            while(bookings[x]!=null){
                msg= msg + bookings[x].toString() + " ";
                return msg;
            }

                return "Room Available at all hours";
        }

    public String getDetailedBookingGrid(){
        int i=0;
        String grid= roomID+ "|" + " ";
        while(bookings[i]!=null){
              grid= grid+ bookings[i].getBookingID() + "| "+ " "; 
              i++;
        }
            for(int y=i;y<numSlots;y++){
                grid=grid+" ";
            }
        return grid;
    }

    public String getRoomID(){
        return roomID;
    }
    
    public boolean hasBooking(int bookingID){
        int y=0;
        while(y<numSlots && bookings[y]!=null){
            if(bookings[y].getBookingID() == bookingID)
               return true;
            else
                y++;
        }
        return false;
    }
    
    public String toString(){
        String r= "Room ID: " + roomID + "Seating Capacity: "+ seatingCapacity; 
        return r;
    
   }
    
}
