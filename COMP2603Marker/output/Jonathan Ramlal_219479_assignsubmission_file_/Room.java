public class Room{
    private int numSlots;
    private static int roomIDCounter = 100;
    private int ID;
    private String roomID;
    private Booking[] bookings;
    private int seatingCapacity;
    private String name;
    
    public Room(String name, int seatingCapacity){
        numSlots = 0;
        ID = roomIDCounter;
        bookings = new Booking[8];
        this.name = name;
        this.roomID = name + String.valueOf(roomIDCounter);
        this.seatingCapacity = seatingCapacity;
        roomIDCounter+=100;
    }
    
    // accessors
    public int getNumSlots(){
        return numSlots;
    }
    
    public String getName(){
        return this.name;
    }

    public String getRoomID(){
        return roomID;
    }
    
    public int getSeatingCapacity(){
        return seatingCapacity;
    }
    
    //mutators
    
    // public void setNumSlots(int val){
    //     if(val > 8 || val < 1){
    //         System.out.println("Error, invalid number.");
    //     }
    //     else this.numSlots = val;
    // }

    public void setSeatingCapacity(int val){
        this.seatingCapacity = val;
    }

    public void setName(String val){
        if(val.length() != 3){
            System.out.println("Error: Invalid Name.");
            return;
        }
        this.name = val;
        this.roomID = val + ID;
    }

    public String toString(){
        String details = "Name: " + name + "\tRoomID: " + roomID + "\tSeats: " + seatingCapacity;
        return details;
    }
    
    public String addBooking(String description, int duration, int seats){
        if(!canFitNumbers(seats)){
            System.out.println("error: cant fit seats");
            return null;
        }
        if(!canFitTime(duration)){
            System.out.println("error: cant fit time");
            return null;
        }
        if(this.bookings[7] != null){
            System.out.println("error: full");
            return null;
        }
        int max = this.numSlots + duration - 1;
        // System.out.println("add slots = " + this.numSlots);
        // System.out.println("add max = " + max);
        //System.out.println("Passed");
        if(max <= 7){
            //System.out.println("Passed");
            Booking b = new Booking(description, duration, seats);
            // System.out.println("duration = " + duration);
            String details = "Booking added to schedule:" + b.toString();
            while(this.numSlots <= max){
                this.bookings[numSlots] = b;
                //System.out.println("Add Booking, Added Booking\n\t" + this.bookings[numSlots]);
                numSlots++;
                // System.out.println("add slots = " + this.numSlots);
            }
            
            return details; 
        }
        return null;
    }
    
    public boolean canFitNumbers(int numSeats){
        if(numSeats > this.seatingCapacity) return false;
        return true;
    }
    
    public boolean canFitTime(int duration){
        duration--;
        System.out.println("duration: " + duration);
        if(duration + this.numSlots <= 7) return true;
        return false;
    }
    
    public String getBookingDetails(int bookingID){
        if(this.bookings[bookingID] == null) return "Error: Invalid Booking ID.";
        if(bookingID <= this.numSlots && bookingID >=0) return this.bookings[bookingID].toString();
        return "Error: Invalid Booking ID.";
    }
    
    public String getBookingList(){
        if(this.bookings[0] == null) return "Error: No bookings for this room.";
        String details = "";

        for(int i = 0; i < this.numSlots; i++){
            details += this.bookings[i].toString();
        }
        return details;
    }
    
    public String getDetailedBookingGrid(){
        String details = this.roomID + "|  ";
        int count = 1;
        //System.out.println("slots = " + this.numSlots);
        for(int i = 0; i < this.numSlots; i++){
            details += this.bookings[i].getBookingID() + "  |  ";
            count++;
        }
        //System.out.println("count = " + count);
        // if(count != 8) return details;
        // else System.out.println("error: too big");
        for(int i = count - 1; i < 8; i++){
            details += "  |  ";
            //System.out.println("YEET");
        }
        return details;
    }
    
   
    
    public boolean hasBooking(int bookingID){
        for(int i = 0; i < numSlots; i++){
            if(this.bookings[i].getBookingID() == bookingID) return true;
        }
        return false;
    }
    

    public static void main(String[] args) {
        Room r1 = new Room("FST", 100);
        Room r2 = new Room("CLL", 134);
        Room r3 = new Room("FFA", 214);
        Booking b1 = new Booking("Lecture", 1, 100);    
        Booking b2 = new Booking("Lecture", 2, 47); 

        // System.out.println("Testing Room Constructor and toString");
        // System.out.println(r1.toString());
        // System.out.println(r2.toString());
        // System.out.println(r3.toString());

        // System.out.println("Testing Accessors on Room 1");
        // System.out.println("Testing getNumSlots\n" + r1.getNumSlots());
        // System.out.println("Testing getRoomID\n" + r1.getRoomID());
        // System.out.println("Testing getSeatingCapacity\n" + r1.getSeatingCapacity());
        
        // System.out.println("\nTesting Mutators on Room 1");
        // r1.setName("AAA");
        // System.out.println("Changing FST to AAA setRoomName\n" + r1.getName());
        // System.out.println("Checking ID:\n" + r1.getRoomID());
        // r1.setSeatingCapacity(999);
        // System.out.println("Changing cap to 999\n" + r1.getSeatingCapacity());
        // System.out.println(r1.toString());

        System.out.println("\nTesting Helper Functions on Room 1 2 3");
        
        System.out.println("\nRoom 1");
        r1.addBooking("Lecture", 3, 5);
        System.out.println("---Testing addBooking and getBookingDetails---\n" + r1.getBookingDetails(0));
        System.out.println("---Testing getBookingList---\n" + r1.getBookingList());
        System.out.println("---Testing getDetailedBookingGrid---\n" + r1.getDetailedBookingGrid());
        System.out.println("---Testing hasBooking(0)---\n" + r1.hasBooking(0));
        System.out.println("---Testing hasBooking(7)---\n" + r1.hasBooking(7));
        System.out.println("---Testing toString---\n" + r1.toString());

        System.out.println("\nRoom 2");
        r2.addBooking("Lecture", 4, 645);
        System.out.println("---Testing addBooking and getBookingDetails---\n" + r2.getBookingDetails(0));
        System.out.println("---Testing getBookingList---\n" + r2.getBookingList());
        System.out.println("---Testing getDetailedBookingGrid---\n" + r2.getDetailedBookingGrid());
        System.out.println("---Testing hasBooking(0)---\n" + r2.hasBooking(0));
        System.out.println("---Testing hasBooking(7)---\n" + r2.hasBooking(7));
        System.out.println("---Testing toString---\n" + r2.toString());

        System.out.println("\nRoom 3");
        r3.addBooking("Lecture", 8, 2);
        System.out.println("---Testing addBooking and getBookingDetails---\n" + r3.getBookingDetails(0));
        System.out.println("---Testing getBookingList---\n" + r3.getBookingList());
        System.out.println("---Testing getDetailedBookingGrid---\n" + r3.getDetailedBookingGrid());
        System.out.println("---Testing hasBooking(0)---\n" + r3.hasBooking(0));
        System.out.println("---Testing hasBooking(7)---\n" + r3.hasBooking(7));
        System.out.println("---Testing toString---\n" + r3.toString());
    }
    
}