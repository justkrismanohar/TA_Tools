//816009535 Simon Ramdath
public class RentalSystem{
 private Room[] rooms;
 private int numrooms;
 
    
    
    
    public RentalSystem(){
        this.rooms= new Room[10];
        this.numrooms=0;
        
        
        
        
        
    }
    
    public String addRoom(String name, int seatingCapacity){
        
        
        if(numrooms<10){
            
           Room room= new Room(name, seatingCapacity); 
           rooms[numrooms]=room;
           numrooms++;
           return rooms[numrooms-1].toString();
   
        
    
    
    
    
                }
           return "Cannot add room, max rooms reached";
    }
   
    
  
  
  public String getRoomlist(){
      String list="";
      for(int i=0; i<numrooms; i++){
          
          list+=rooms[i].toString();
      
      
      
      
    }
    if(list.equals("")){
        return "No rooms in system";
    }
    return list;
 }
 
 public String addBooking(String description, int duration, int numSeating)
 {
     if(numrooms>0){
         for(int i=0; i<numrooms; i++){
             String A=rooms[i].addBooking(description, duration, numSeating);
             if(A!=null){
                 return A;
        }
      }
     }
     return"Cannot add Booking";
   }

   public String getBooking(int bookingID){
       if(numrooms>0){
           for(int i=0; i<numrooms; i++){
              if(rooms[i].hasBooking(bookingID)){
                  return rooms[i].getBookingDetails(bookingID);
                }              
            }       
        }
        return"Booking ID not found";
    }
    
    public String getBookingsByRoom(String roomID){
        if(numrooms>0){
            for(int i=0; i<numrooms; i++){
                if(rooms[i].getRoomID().equals(roomID)){
                    return rooms[i].getBookingList();
                }
            }
            
        }

        return " Room ID not found";
    }
    
    public String getBookingGrid(){
        String grid="";
        if(numrooms>0){
            for(int i=0; i<numrooms; i++){
                grid+= rooms[i].getDetailedBookingGrid();
            }
        
            return grid;
        
        
        }
        return"No rooms in the system";
    
    }
    
    



}