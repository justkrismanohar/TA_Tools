//816004741
public class Booking{
    private static int bookingIDcounter;
    private int bookingID;
    private String description;
    private int duration;
    private String location;
    private int numSeating;



  public Booking (String description, int duration, int numSeating){
    description=this.description;
    duration=this.duration;
    numSeating=this.numSeating;
    bookingID=bookingIDcounter;
    bookingIDcounter++;
   }
   
   public String toString(){
    String s;
    s="ID: "+bookingID+" Description: "+description+" Duration: "+duration;
    return s;
    }
    
    public String getDesc(){
        return description;
        }
    
    public void setDesc(String d){
        description=d;
    }
    
        
    public String getLoc(){
        return location;
        }
    
    public void setLoc(String l){
        location=l;
    }
    
        
    public int getSeats(){
        return numSeating;
        }
    
    public void setSeats(int n){
        numSeating=n;
    }
    
    public int getBookingID(){
        return bookingID;
        }
    
    
 

 }
