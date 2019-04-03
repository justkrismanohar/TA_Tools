//ID#:810003511

public class Room
{
    // instance variables - replace the example below with your own
    private int numSlots;
    private int roomIDCounter;
    private String roomID;
    private Booking[] bookings = new Booking[8];
    private int seatingCapacity;
    private String name;
    private int[] num = new int[9];
    private int roomCount;
    private int bookCount;

   
    //Constructor for objects of class Room
    
    public Room(String name, int seatingCapacity)
    {
        // initialise instance variables
        this.name = name =" ";
        this.seatingCapacity = seatingCapacity;
        numSlots = 8;
        roomIDCounter =100;
        roomCount =0;
        bookCount = 0;
        roomID = name+roomIDCounter;
        bookings[0]=new Booking("",0,0);
        bookings[1]=new Booking("",0,0);
        bookings[2]=new Booking("",0,0);
        bookings[3]=new Booking("",0,0);
        bookings[4]=new Booking("",0,0);
        bookings[5]=new Booking("",0,0);
        bookings[6]=new Booking("",0,0);
        bookings[7]=new Booking("",0,0);
        
        
        
        
    }
    //Accessors
   
    public String getRoomID(){
        return roomID;
    
    }
    public String getName(){
        return name;
    }
    public int getRoomIDCounter(){
        return roomIDCounter;
    }
    public int getSeatingCapacity(){
        return seatingCapacity;
    }
    public int getNumSlots(){
        return numSlots;
    }
    
    //public String getBookingDetails(int bookingID){
        
    //}
    
    //Mutators
    void setName(String enterName){
        name = enterName;
     }
    void setSeatingCapacity(int enterSeat){
        seatingCapacity = enterSeat;
    }
    void setRoomIDCounter(int counterValue){
        roomIDCounter=counterValue;
        
     }
    void setRoomID(String enterName){
        roomID = enterName+roomIDCounter;
    }
    void setRoomCount(){
        roomCount++;
               
    }
    public int setBookCount(int num){
        bookings[bookCount].setBookingID(num);
        return num;
    }
    //Methods
    
    public String toString(){
        String roomDetails = "Name: "+ name + " RoomID: " + roomID + " Seats: " + seatingCapacity;
        return roomDetails;
    }
    public boolean canFitNumbers(int numSeats){
        if (bookings[bookCount].getNumSeating()<=seatingCapacity){ return true;}
       return false;
       
    }
    
    public boolean canFitTime(int duration){
        int j=0;
       for(int i=0; i<bookCount; i++){
          if(bookings[i].getDuration()!=0){j= bookings[i].getDuration()+j;}
        }
       
    if(duration<=(8-j)){return true;}
    return false;
    }
    
    public Booking[] addBooking(String description, int duration, int seats){
       int i=0;
        bookings[bookCount].setNumSeating(seats);
       bookings[bookCount].setDuration(duration);
        if(canFitTime(duration)==false){
          System.out.println("Cannot make booking");
          
          bookings[bookCount].setDuration(0);
          return null;
      }
      if(canFitNumbers(seats)==false){
          System.out.println("Cannot make booking");
          bookings[bookCount].setNumSeating(0);
          return null;
        
        }
     
        bookings[bookCount].setDescription(description);
        
        
        bookings[bookCount].setLocation(roomID);
        System.out.println("Booking added to schedule: ");
        System.out.println(bookings[bookCount].toString());
        
        //i++;
        //bookCount++;
        //bookings[bookCount].setBookingID(num);
        
        
       
        
       
        
        return bookings;
    }
    public String getBookingDetails(int bookingID){
        for(int i=0; i<8; i++){
            if(bookingID==bookings[i].getBookingID()){
                System.out.println(bookings[i].toString());
                return bookings[i].toString();
            }
        }
            return "No booking with that ID was found";
        
    }
    public String getBookingList(){
        for(int i=0; i<8; i++){
            if(roomID==bookings[i].getLocation()){
                System.out.println(bookings[i].toString());
                int j=0;
                
                num[j]=i;
                j++;
               }
            return ("All booking that were found");
        }
        return ("No bookings for room found");
    }
    
    public String getDetailedBookingGrid(){
        
        
        System.out.println(getRoomID()+"|"+bookings[num[0]].getDuration()+"|"+bookings[num[1]].getDuration()+"|" +bookings[num[2]].getDuration()+"|"+bookings[num[3]].getDuration()+"| "+bookings[num[4]].getDuration()+"|"+bookings[num[5]].getDuration()+"|"+bookings[num[6]].getDuration()+"| "+bookings[num[7]].getDuration()+"|");
    return null;
    }
    public boolean hasBooking(int bookingID){
        for(int i=0; 0<8; i++){
            if(bookingID==bookings[i].getBookingID()){
                return true;
            }
            return false;
        }
    }
    
}
