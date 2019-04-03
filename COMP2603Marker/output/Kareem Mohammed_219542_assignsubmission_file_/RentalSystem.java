/*
 Author: Kareem Mohammed
 ID: 816007247
 */
public class RentalSystem{

    private Room[] rooms;
    private int numRooms;
    
    
    //Constructors
    
    public RentalSystem(){
    
        this.rooms = new Room[10];
    }
    
    //Methods
    
    public String addRoom(String name, int seatingCapacity){
    
        boolean isFull = false;
        int x=0;
        while(rooms[x]!=null && x<10){
            
        x++;
        if(x==9 && rooms[x]!=null)
        isFull = true;
        }
        if(isFull)
        return "Cannot add room; Max rooms reached.\n";
        
        Room holdRoom = new Room(name, seatingCapacity);
        
        rooms[x] = holdRoom;
        
        return rooms[x].toString();
    }
    
    private boolean isSystemEmpty(){
    
       boolean isEmpty = true;
       
       for(int x=0; x<10; x++){
           
           if(rooms[x] != null)
           isEmpty = false;
           
        }
       
       return isEmpty;
    } 
   
   public String getRoomList(){
    

       if(isSystemEmpty())
        return "No rooms in the system.\n";
       
       String roomList = "";
        
       for(int x=0; x<10; x++){
           if(rooms[x] != null)
           roomList += rooms[x].toString() + "\n";
        }
        
       return roomList; 
    }
    
   public String addBooking(String description, int duration, int numSeating){
    
    int x=0;
    
    while(rooms[x] != null && x<10){
    
        if(rooms[x].canFitNumbers(numSeating) && rooms[x].canFitTime(duration))
         return rooms[x].addBooking(description, duration, numSeating);
        
         else
         x++;
    }
    return "Cannot add booking.";
    
    }
    
   public String getBooking(int bookingID){
    
    boolean bookingIDFound;
    
    String bookingDetails;
    
    for(int x=0; x<10; x++){
        if(rooms[x] != null){
        bookingIDFound = rooms[x].hasBooking(bookingID);
        
        if(bookingIDFound){
        
         bookingDetails = rooms[x].getBookingDetails(bookingID);
         
         return bookingDetails;
        }
        }
    }
    
    return "Booking ID not found\n";
    }
    
    
   public String getBookingsByRoom(String roomID){  
       
    String bookingDetails = roomID + "\n";
    
    boolean roomFound = false;
    
    for(int x=0; x<10; x++){
    
     if(rooms[x] != null){
      if(roomID.equals( rooms[x].getRoomID())){

         bookingDetails+= rooms[x].getBookingList();
         
         roomFound=true;
         
      }
     }
    }
    
    if(roomFound == false)
    return "Room ID not found. \n";
    
    return bookingDetails;
    
    }
   
   public String getBookingGrid(){
    
     if(isSystemEmpty())
      return "No rooms in the system.\n";
      
     String bookingGrid = ""; 
      
     for(int x=0; x<10; x++){
        
        if(rooms[x] != null) 
        bookingGrid+= rooms[x].getDetailedBookingGrid() + "\n";
        }
     
     return bookingGrid;   
    }
    
}