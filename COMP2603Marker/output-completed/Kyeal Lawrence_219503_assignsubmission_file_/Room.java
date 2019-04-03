/**
 * 816009808
 *
 * 
 * 
 */
public class Room
{
    private final int numSlots=8;
    private static int roomIDCounter = 100;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private String name;
    private int remainingSlots=numSlots;
    private int bookingCounter;
    
    public Room(String name, int seatingCapacity)
    {
        this.name=name; 
        this.seatingCapacity=seatingCapacity;    
        remainingSlots = numSlots;
        setRoomID(name,roomIDCounter);
        roomIDCounter = roomIDCounter + 100;
        bookings = new Booking[numSlots];  
        
                
    }
    
    public String addBooking(String description, int duration, int seats)
    {
        String message = "Booking succesfully added to schedule : ";
     
        if (canFitTime(duration)&&canFitNumbers(seats))
            {
                 bookings[bookingCounter]=new Booking(description,duration,seats);
                 bookings[bookingCounter].setLocation(roomID);
                 message += bookings[bookingCounter].toString();
                 remainingSlots = numSlots - duration;
                 bookingCounter++;
                 return message;
            }
            return message;
    }
    
    public boolean canFitNumbers(int numSeats)
    {
        
            if (numSeats <= seatingCapacity)
            {
                return true;
            }
            else
            {
                return false;
            }
    }
      
    public boolean canFitTime(int duration)
    {

            if (duration <= remainingSlots)
            {
                return true;
            }
            else
            {
                return false;
             }
     }
            
    
    
    public String getBookingDetails(int bookingID)
    {
        
        for (int i=0;i<bookings.length;i++)
        {
            if (bookings[i].getBookingID()==bookingID)
            {
              String details = "Booking ID: "+bookingID+" Type: "+bookings[i].getDescription()+" Hours:  "+bookings[i].getDuration()+" Location: "+getRoomID();
              return details;
            }
        }
         
        return " No booking found";
    }
    
    public String getBookingList()
    {
        String message ="No bookings in the system";
        String info="";
        for(int i=0; i<10;i++)
        {
            if(bookings[i]==null)
            break;
            for(int k=0;k<bookings[i].getDuration();k++)
            {
                info += bookings[i].toString()+"\n";
            }
        }
        return info;
    }
    
    public String getDetailedBookingGrid()
    {        
        String grid=getRoomID()+"  |";
        int roomidnum=0;
        for(int i = 0; i<numSlots ; i++)
        {
            if(bookings[i]!=null)
            {
                roomidnum=bookings[i].getBookingID();
                if(roomidnum>9)
                {
                    int remainder =numSlots - bookings[i].getDuration();
                    for(int x=0 ; x<bookings[i].getDuration() ; x++)
                    {
                        grid+="   "+bookings[i].getBookingID() +"    |";
                    }
                    
                    for(int l=0;l < remainder;l++)
                    {
                        grid +="      |";
                    }
                    return grid;
                }
                
                if(roomidnum<9)
                {
                    int remainder =numSlots - bookings[i].getDuration();
                    for(int k=0;k<bookings[i].getDuration();k++)
                    {
                        grid+="      "+bookings[i].getBookingID()+"       |";
                    }
                    
                    for(int t=0;t < remainder;t++)
                    {
                        grid+="        |";
                    }
                    return grid;
                }

            }
            else
                {
                    grid +="       |";
                }
            
        }
        return grid + "\n";
    }
    
    public void setSeatingCapacity(int seats)
    {
        seatingCapacity = seats;
    }
    
    public int getSeatingCapacity()
    {
        return seatingCapacity;
    }
    
  
    public void setRoomID(String name, int idnumber)
    {
        roomID = name+""+idnumber;
    }
    public String getRoomID()
    {
        return roomID;
    }
    
    public boolean hasBooking(int bookingID)
    {
        for (int i = 0; i<numSlots;i++)
        {
            if(bookings[i] == null)
                break;
            if(bookings[i].getBookingID()==bookingID)
            {
                return true;         
            }
        } 
        return false;
    }
    
    public String toString()
    {
         String description="Room: "+name+" Seats: "+seatingCapacity;
         return description;
    }
     
} 

    
    
    

