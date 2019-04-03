/*
 * Kyle Borneo 
 * 815006227
 * Assignment One 
 * 18/02/19
 */
public class Room{
    private String name;
    private static final int numSlots = 8;
    private int counter;
    private static int roomIDCounter=100;
    private String roomID;
    public  Booking[] booking;
    private int seatingCapacity;
    private int num_Booking;


    public Room(String name, int seatingCapacity){
        this.name=name;
        this.seatingCapacity=seatingCapacity;
        roomID= name+roomIDCounter;
        roomIDCounter+= 100;
        booking=new Booking[numSlots];
        num_Booking= 0;
    }


    public String getRoomID(){
        return roomID;
    }

    public int getNumBookings(){
        return num_Booking;
    }
    
    
    public boolean canFitTime(int duration){
        return (num_Booking + duration <= numSlots);
    }


    public boolean canFitNumbers(int numSeats){
        System.out.println(seatingCapacity + " " + numSeats);
        return (seatingCapacity >= numSeats);
    }


    String addBooking (String description, int duration, int seats){
        String s = null;
        if(num_Booking >=0  && seatingCapacity >= seats){
            Booking b = new Booking(seats, description, duration);
            booking[num_Booking] = b;
            //counter--;
            b.setLocation(roomID);
            num_Booking++;
            s = "Booking added to schedule " + b.toString();
        }
        return s;
    }
   

    boolean hasBooking(int bookingID){
        for(int i=0; i<num_Booking; i++){
            int s = booking[i].get_bookingID();
            if(s == bookingID)
                return true;
        }
        return false;
    }


    String getBookingDetails(int bookingID){
        for(int i=0; i<num_Booking; i++){
            int s = booking[i].get_bookingID();
            if(s == bookingID)
                return booking[i].toString();
        }
        return (bookingID + "not found\n");
    }
    
    public String printSlots(int BookingID,int duration){
        String s="";
        if(BookingID == -1){
        for(int i=0; i<duration; i++){
            s+= ("| \t" + BookingID);
        }
        return s;
    }
    for(int i=0; i<duration; i++){
        s+= ("1" + BookingID);
    }
    return s;
}
    
    String getDetailedBookingGrid(){
        String s="";
        int count= 0;
        for(int i=0; i<num_Booking; i++){
            count= count + booking[i].get_duration();
          // count = booking[i].get_duration();
         //   for(int j = 0; j<count; j++){
               // s = s + booking[i].get_bookingID() + "|";
            s+= printSlots(booking[i].get_bookingID(),booking[i].get_duration());
        }


        int remainder= numSlots - count;
        s+= printSlots(-1,remainder);
        return s;
    }


    String getBookingList(){
        String s="";
        if(num_Booking == 0)
            s = "No Bookings made for this room\n";
        else{
            for(int i=0; i<num_Booking; i++)
                s = s + booking[i].toString()+ "\n" ;
        }
        return s;
    }

    public String toString(){
        String s=" ";
        s += "Room Id:"+ roomID+"\n Room Name: " + name+"\n"+"\nSeating Capacity: "+seatingCapacity + "\n";
        return s;
    }

}