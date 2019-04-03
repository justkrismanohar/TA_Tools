//VERNESSA BOODRAM
//816006133

public class RentalSystem {
    
    //Declaring the RentalSystem attributes 
    private Room[] rooms;
    private static int numRooms = 0;
    private Booking[] bookings = new Booking[8];
    private String roomID; 
    
    //Constructor
    public RentalSystem () {
         rooms = new Room[10];
    }

    //Methods
    //1. 
    public String addRoom (String name, int seatingCapacity) {
        
        if (numRooms < 10) {
            Room newRoom = new Room(name, seatingCapacity); //create the room 
            rooms[numRooms] = newRoom;//Save the information
            numRooms = numRooms + 1;//Increment the space used 
            return (newRoom.toString());//Output the details of the room created
        }
        else
            return "Cannot add room...Max room reached!";
    }
        
    //2. 
    public String getRoomList () {
        String list = " ";
        
        if (numRooms >= 1){ //Making sure that the list isn't empty
            for (int i=0; i<numRooms; i++)
                list = list + rooms[i].toString() + "\n";
                
            return list;
        }
        else
            return("No rooms in the system");
    }
  
    //3.
    public String addBooking (String description, int duration, int numSeating) {
        
        String added;
        
       for (int i=0; i<numRooms; i++) {
           added = rooms[i].addBooking(description, duration, numSeating); //adding a booking 
           
           if (added != null) {
               return "Booking successfully added to schedule \n" + added;
            }
       }   
           return "Cannot add Booking";  
    }
   
    //4.
      
    public String getBooking (int bookingID) {
        
        String details;
        
        for (int i=0; i<numRooms; i++) {
            details = rooms[i].getBookingDetails(bookingID);
        
                if (details == null) {
                    return "Booking ID not found";
                }
        } 
        return "Not found";
    }
     
    /*
    //5.
    public String getBookingsByRoom (String roomID) {
        if (numRooms >= 1){ //Making sure that the list isn't empty
            for (int i=0; i<numRooms; i++)
                if (roomID == rooms[i].getRoomID())
                    System.out.println(rooms[i].toString());
        }
        else
            System.out.println("Room ID not found");
            return "Empty";
    }
    
    //6.
    public String getBookingGrid () {
        
    }
    */  
} //End of RentalSystem class 