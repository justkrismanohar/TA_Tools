//816008473 Kenaird Saunders
public class Booking{
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    private static int bookingIDCounter = 1;
    
    
    
    public Booking( String description, int duration, int numSeating){
         this.bookingID = bookingIDCounter;
         bookingIDCounter++;
         this.description = description;
         this.duration = duration;
         this.numSeating = numSeating;
    }
    
    public String toString(){
        String details= duration+" HOURS Seats: "+numSeating+" Location: "+ location;
        return "Description: " + description + " Duration: " + details + "\n";
    }
    
    public void setLoc(String location){
        location = location;
    }
    
    public int getBookingID(){
     return bookingID;
    }// you should create a function to access the bookingID especially for the Room class to use
    public static void main(String[] args){
        Booking[] test = new Booking[5];
        test[0] = new Booking("Lecture", 5, 200);
        test[1] = new Booking("Tutorial", 7, 78);       
        test[2] = new Booking("Expo", 8, 500);
        test[3] = new Booking("Seminar", 4, 50);
        test[4] = new Booking("meeting", 5, 100);
        for (int i = 0; i < 5; i++){
            System.out.println(test[i].toString());
        }
    }
}