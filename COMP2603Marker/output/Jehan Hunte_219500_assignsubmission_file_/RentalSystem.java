//Name:Jehan Hunte
//ID#:816003696
//COMP 2603 Assignment 1

public class RentalSystem
{
    public static Room[] rooms= new Room[10];
    private static int numRooms = 0;
    
    public RentalSystem()
    {
     
    }
    
    public String addRoom(String _name, int _seatingCapacity){
        
        final int MAX = 10;
        String error ="\nCannot add room, maxed room reached.\n";
        String success = "\nRoom sucessfully added.\n";
        
        if(numRooms > MAX-1 ) 
            return error;
        
        else{
             rooms[numRooms] = new Room(_name,_seatingCapacity);
             numRooms+=1;
             System.out.print(success);
             return rooms[numRooms-1].toString();
        }
        
        
    }
    
  
    public String getRoomList(){
        
        String error = "\nNo rooms in system.\n";
        String roomDetails = "";
        
        
        if (numRooms == 0) 
            return error;
        System.out.println("ROOM LIST");
        for(int i = 0; i < numRooms; i++){
            roomDetails += rooms[i].toString();
        }
        
        return roomDetails;
    }
    
    public String addBooking(String _description, int _duration, int _numSeating){
        String error = "\nCannot add Booking";
        String bookingDetails ="";
        boolean added = false;
        
        for(int i = 0; i < numRooms; i++){
            if(rooms[i].canFitTime(_duration) && rooms[i].canFitNumbers(_numSeating)){
               bookingDetails = rooms[i].addBooking(_description,_duration,_numSeating);
                return bookingDetails;
                
            }
        }
        
        return error;
           
    }
    
    public String getBooking (int _bookingID){ //check
        String error = "\nBooking ID not found.";
        String bookingDetail = "";
        
        
        for(int i = 0; i < numRooms; i++){
           for (int j=0; j<rooms[i].numSlots;j++){
            if(rooms[i].bookings[j].bookingID==(_bookingID)){
                bookingDetail = rooms[i].getBookingDetails(_bookingID);
                return bookingDetail;
            }
        }
        }
       
        return error;
    }
    
    public String getBookingsByRoom(String _roomID){ 
        
        String error = "\nRoom ID not found.";
        String details = "";
        for (int i = 0; i < numRooms; i++){
            if(rooms[i] != null && rooms[i].getRoomID().equals(_roomID)){
                System.out.print("ROOM ID: "+rooms[i].getRoomID() + " SEATS: "+ rooms[i].getseatingCapacity());
                return details+=rooms[i].getBookingList();
            
            }
            
        }
        
       return error;
    }

   
    public String getBookingGrid(){
        String bookingDetails = "\n";
        for (int i = 0; i < numRooms; i++){
            if(rooms[i] != null){
                bookingDetails+=rooms[i].getRoomID() +"|" +rooms[i].getDetailedBookingGrid()+"\n";
            }
        }
        bookingDetails+="\n";
        return bookingDetails;
    }
    
}
