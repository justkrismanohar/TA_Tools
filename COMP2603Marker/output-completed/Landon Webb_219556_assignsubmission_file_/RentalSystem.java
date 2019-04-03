//816004741
public class RentalSystem{
    private Room[] rooms;
    private int numRooms=0;
    
    
    public RentalSystem(){
        rooms=new Room[10];
       
    }
    
    public String addRoom(String name, int seatingCapacity){
        String s;
        if(rooms.length<10){
            rooms[numRooms]=new Room(name, seatingCapacity);
            s=rooms[rooms.length].toString();
            numRooms++;
            return s;
        }
        
        s="Cannot add room; Max rooms reached.";
        return s;
        
    }   
    
    
    public String getRoomList(){
        String s="";
        if(rooms.length>0){
            for(int x=0;x<numRooms;x++){
                s+=rooms[x].toString();
                s+=" \n";
            }
            return s;              
       }
       s="No rooms in the system";
       return s;
    }
    
    public String addBooking(String description,int duration, int numSeating){
         if(rooms.length>0){            
             for(int x=0;x<rooms.length;x++){
                if(rooms[x].canFitTime(duration) && rooms[x].canFitNumbers(numSeating)){
                    for(int k=rooms[x].numB();k<(x+duration);k++){
                        rooms[k].addBooking(description,duration,numSeating);
                        return "Booking Added";
                    }
                    }
            }
       }
       
       return "Cannot add booking";
    }   
    
    
    public String getBooking(int bookingID){
        String s;
        for(int x=0;x<rooms.length;x++){
            if(rooms[x].hasBooking(bookingID)){
                s=rooms[x].getBookingDetails(bookingID);
                return s;
            }
            
        }
        
        s="Booking ID not found";
        return s;
    
    }
    
    public String getBookingsByRoom(String roomID){
        String s="Room ID not found";
        for(int x=0;x<rooms.length;x++){
            if(rooms[x].getRoomID().equals(roomID)){
                s=rooms[x].getBookingList();
                }
            }
        return s;
    }
    
    public String getBookingGrid(){
        String s="\n";
        
        if(rooms.length>0){
            for(int i=0;i<rooms.length;i++){
                s+=rooms[i].getDetailedBookingGrid()+"\n";
            }
            return s;
        }
        s="No rooms in system";
        return s;
    }
        
    
    
    }
    
    

    
   

