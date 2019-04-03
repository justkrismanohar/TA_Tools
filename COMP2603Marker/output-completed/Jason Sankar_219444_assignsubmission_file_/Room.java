
/**
  Jason Sankar
 816001067
 */
public class Room
{
   public int numSlots;
   private static int roomIDCounter=new Integer(100);
   public String roomID;
   private Booking[] bookings;
   public int seatingCapacity;
   
   public Room(){
   this.bookings=new Booking[7];
   this.numSlots=0; 
   }
   public Room( String name, int seatingCapacity)
   {
   this.numSlots=8;
   this.seatingCapacity=seatingCapacity;
   String tp=String.valueOf(roomIDCounter);
   this.roomID=name+tp;
   this.roomIDCounter=this.roomIDCounter + 100;
   }

   public String addBooking( String description, int duration, int seats){
       
       this.bookings[1].Booking(description,duration,seats);
       this.bookings[1].location=this.roomID;
       String aB="Booking added to schedule. \n Name : "+this.bookings[1].description+" Room : "+this.bookings[1].location+" Seats : "+this.bookings[1].numSeating;
       return aB;
       
   }
   /**
   public boolean canFitNumbers(int numSeats){
       
   }
   public boolean canFitTime(int duration){
    
   }
   public String getBookingDetails(int bookingID){
    
   }
   public String getBookingList(){
    
   }
   public String getDetailedBookingGrid( ){
    
   }
   public String getRoomID( ){
    
   }
   public boolean hasBooking( int bookingID){
    
   }
   public String toString(){
    
   }
   */
}   