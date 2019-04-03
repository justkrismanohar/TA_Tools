//ID: 816005793
public class Booking
{
    private static int bookingIDCounter = 1;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;
    
    public Booking(String description, int duration, int numSeating)
    {
       this.description = description;
       this.duration = duration;
       this.numSeating = numSeating;
       bookingID = bookingIDCounter;
       bookingIDCounter = bookingIDCounter + 1;      
    }
    
    public void setDescription(String desc){
        this.description=desc;
    }
    public void setDuration(int dur){
        this.duration=dur;
    }
    public void setLocation(String loc){
        this.location=loc;
    }
    public void setNumSeating(int num){
        this.numSeating=num;
    }
    public int getBookingIDCounter(){
        return bookingIDCounter;  
    }
    public int getBookingID(){
        return bookingID;
    }
    public String getDescription(){
        return description;
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
    public String toString(){
        return "ID: " + bookingID + " DESCRIPTION: "+description+" DURATION: "+duration+" hour(s) "+ "LOCATION: "+location;
    }
}
