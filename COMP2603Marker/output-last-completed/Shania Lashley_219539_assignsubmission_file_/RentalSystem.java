// 816009920
/**
 * Write a description of class RentalSystem here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class RentalSystem
{
    // instance variables - replace the example below with your own
    private Room[] rooms;
    private static int numRooms;
    

        /**
         * Constructor for objects of class RentalSystem
         */
        public RentalSystem()
        {
            // initialise instance variables
            
            rooms = new Room[10];
            numRooms = numRooms;
           
        }
    
    
    
        public String addRoom(String name, int seatingCapacity){
              
              Room  r = new Room(name,seatingCapacity);
                    r.setRoomID(name);
                    r.setSeatingCapacity(seatingCapacity);
                    
              if( numRooms <= 2){
                  rooms[numRooms] = r;
                  numRooms = numRooms + 1;
                  
                  return r.toString() + numRooms;
              }
              else 
                  return "Cant Add Room; Rooms Reach its max";
                
              
              //n = System.out.println(toString)());
        }
   
        public String listRoom(){
            String n = " ";
            n = "List of Rooms: \n";
            
            if( numRooms > 0 )
                for(int i = 0; i < numRooms; i++ ){
                    n+= rooms[i].toString() ;
                }
            else
                 n = "No rooms in the system";
            
            return n;
        }   
     
        public String addBooking(String description, int duration, int numSeating){
            String n = "";
            boolean f = false;
            int i = 0;
            Room r = rooms[i];
            
            while(i < numRooms && !f ){
                
                
                if( r.canFitTime(duration) == true && r.canFitNumbers(numSeating) == true){
                    n += r.addBooking(description, duration, numSeating).toString();
                    //s = "Booking sucessfully made";
                    f = true;
                }
                r = rooms[i];
                i++;
            }
            
            if( f == true )
                return n;
            else {
                n = "Cannot add Booking";
                return n;
            }
                
              
            
         }
        
         public String getBooking(int bookingID){
            Room r = rooms[numRooms];
            
            return r.getBookingDetails(bookingID);
                    
         }
        
           public String getBookingsByRoom(String roomID){
                String  n = "";
                Boolean F = false;
                int i=0, j = 0;
                Room r = rooms[i];
                
                 while (i < numRooms && !F){
                             r = rooms[i];
                    if(r.getRoomID() == roomID){
                        n += r.toString();
                        F = true;                
                    }
                }
                //System.out.println(n);
                if(F == true)
                    return n + r.BookingFromLocation(roomID).toString();
                else
                    return "Room ID not found";    
          } 
          
          public String getBookingGrid(){
                  String n = "";
                  
                    for(int i =0; i<numRooms; i++){
                       Room r = rooms[i];
                       n += r.getDetailedBookingGrid();
                    }  
                    
                        if(numRooms > 0)
                            return n;
                        else{
                            n = "No rooms in the system.";
                            return n;
                        }
        }
 }


