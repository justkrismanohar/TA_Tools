public class Booking{
    private static int bookingIDCounter = 1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    
    public Booking(String description, int duration, int numSeating){
        this.bookingID = bookingIDCounter;
        this.description = description;
        this.duration = duration;
        this.location = location;
        this.numSeating = numSeating;
        bookingIDCounter++;
    }
    
    // accessors
    public int getBookingID(){
        return this.bookingID;
    }
    
    public String getDescription(){
        return this.description;
    }
    
    public int getDuration(){
        return duration;
    }
    
    public String getLocation(){
        return location;
    }
    
    public int getNumSeating(){
        return numSeating;
    }
    
    // mutators
    public void setBookingID(int val){
        this.bookingID = val;
    }
    
    public void setDescription(String val){
        this.description = val;
    }
    
    public void setDuration(int val){
        this.duration = val;
    }
    
    public void setLocation(String val){
        this.location = val;
    }
    
    public void setNumSeating(int val){
        this.numSeating = val;
    }
    
    public String toString(){
        String details = "\nBooking ID: " + bookingID + "\tDescription: " +  description + "\tDuration: " + duration + " hours" + "\tSeats: " + numSeating;
        return details;
    }

    public static void main(String[] args) {
        Booking b1 = new Booking("Lecture", 1, 100);    
        Booking b2 = new Booking("Lecture", 2, 47);    
        System.out.println(b1.toString());
        System.out.println(b2.toString());
    }

}