
public class Room 
{
    
    public int numSlots;
    private static int roomIDCounter = 100;
    public String roomID;
    public Booking[] bookings;
    public int seatingCapacity;

  
    public Room(String name, int seatC)
    {
     roomID = name + roomIDCounter;
     seatingCapacity = seatC; 
     roomIDCounter += 100;
     bookings = new Booking[8];
     numSlots = 0;
    }

 
    public String addBooking (String description, int duration, int seats)
    {
      String output= null;
       if (canFitTime(duration) && canFitNumbers(seats)){
       int j = duration;
       Booking b = new Booking(description, duration, seats);
       b.location = roomID;
       b.bookingID=b.bookingIDCounter;
       while (j>0)
       { 
        bookings[numSlots] = b;     
        numSlots++;
        j--;
       } 
       b.bookingIDCounter++;
       output = " Booking successfully added. ";
       }
      else if (!canFitTime(duration)) 
      {
       output += " Invalid. Unable to fit time. ";
       
       }
       else if (!canFitNumbers(seats)) 
       {
        output += " Invalid seating capacity. ";
        
        }
       return output;
    }
    
    
     boolean canFitNumbers (int numSeats){
    
      if (numSeats > seatingCapacity) return false;
      else return true;
    }
    
    public boolean canFitTime(int duration) 
    {
      if (numSlots + duration > 8) return false;
      else return true;
    }
    
    public String getBookingDetails(int bookingID) 
    {
     int ID=bookingID;
     int i=0;
     String output=null;
     while (i<8)
     {
         if (bookings[i].bookingID==ID)
         {
            output += bookings[i].toString();
            return output;
         }
         else 
         {
           output = "Booking not found. \n";
           i++;         
        }
      }
     return output;  
    }    
    
    public String getBookingList()
    {
      int ID;
      int i=0;
      String output=null;
      if (bookings[i] == null) output = "No bookings found. \n";
      while (bookings[i] != null && i<8)
       {
       ID = bookings[i].bookingID;
       output += bookings[i].toString();
       i++;                                  
         while (ID == bookings[i].bookingID) i++;
      
      }
      return output;
    }
    
    public String getDetailedBookingGrid( ) 
    {
      String output = "Booking Schedule " + roomID + ".\n";
      int i=0;
      int j=1;
      int ID;
      if (bookings[0] == null) output = "No bookings found. \n";
      while (bookings[i] != null && i<8 && j<=8)
      {
       ID = bookings[i].bookingID;
       output += "Time slot " + j + " :\n " + " Description: " + bookings[i].description + 
                 " Seats: " + bookings[i].numSeats + " Duration: " + bookings[i].duration + ".\n";
         i++;
         j++;          
         while (ID == bookings[i].bookingID){
         i++;
         j++;
       }
         }
      return output;
    }
    
    public String getRoomID( ) 
    {
      return roomID;
    }
    
    public boolean hasBooking( int bookingID) 
    {
      int ID=bookingID;
      int i=0;
      while (i<8)
      {
          if (bookings[i].bookingID==ID) return true;
          else i++;
          }
      return false;    
    }
    
    public String toString( ) 
    {
        String output;
      output =" Room ID: " + roomID + " Seating Capacity: " + seatingCapacity;
      return output;
    }
}
