//816007834
import java.util.Arrays;

public class Room {
    private int numSlots;
    private static int roomIDCounter=100;
    private String roomID;
    private Booking[] bookings=new Booking[8];
    private int seatingCapacity;
    
    Room(String name, int seatingCapacity) {
        roomID=name+roomIDCounter;
        this.seatingCapacity=seatingCapacity;
        roomIDCounter=roomIDCounter+100;
        numSlots=0;
    }
    
    public String addBooking(String description, int duration, int seats) {
        if(canFitTime(duration)==true && canFitNumbers(seats)==true) {
            bookings[numSlots]=new Booking(description, duration, seats);           
            bookings[numSlots].setLocation(roomID);
            numSlots=numSlots+duration;
            return "Booking added to schedule";
        }
        else
            return null;
    }
    
    public boolean canFitNumbers(int numSeats) {
        if(numSeats<=seatingCapacity)
            return true;
        else
            return false;    
    }
    
    public boolean canFitTime(int duration) {
        if(numSlots<8 && duration<=8-numSlots)
            return true;
        else
            return false;
    }
    
    public boolean hasBooking(int bookingID) {
        for(int i=0;i<bookings.length; i++) {
            if(bookings[i].getBookingID()==bookingID) {
                return true;
            }
        }
        return false;
    } 
    
    public String getBookingDetails(int bookingID) {
        if(hasBooking(bookingID)==true) {
            return bookings[bookingID-1].toString();
        }
        else
            return null;
    }
    
    public String getBookingList() {
        if(numSlots!=0) {
            String bookingList=Arrays.toString(bookings);
            return bookingList;
        }
        else
            return "No bookings in system";
    }
   
    public String getDetailedBookingGrid() {
        String grid=roomID + " | " + " | " + " | " + " | " + " | " + " | " + " | " + " | " + " |";
        return grid;
    }
    
    public String getRoomID() {
        return roomID;
    }

    public String toString() {
        return "Room ID: " + roomID + " Seating Capacity: " + seatingCapacity;
    }
}