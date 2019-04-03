public class Booking{//STUDENT ID: 816010298
    protected int bookingIDCounter;
    protected int bookingID;
    protected String description;
    protected int duration;
    protected String location;
    protected int numSeating ;
    
    //Constructor
    public Booking(String description, int duration, int numSeating){
        this.description = description;
        this.duration = duration;
        this.numSeating = numSeating;
        bookingIDCounter = 0;
        System.out.println("Description: " + description + " Duration: " + duration + "Seats: " + numSeating); 
    }
    
    //accessors
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
    
    //Mutators
    public void descriptionValue(String descriptionVal){
        switch(descriptionVal){
            case "lecture":
            System.out.println("Lecture");
            break;
            
            case "lab":
            System.out.println("Lab");
            break;
            
            case "expo":
            System.out.println("Expo");
            break;
            
            case "event":
            System.out.println("Event");
            break;            
        }
    }
    
    public String toString(){
        return "BookingID: "+ bookingID + ", Description: " + description + ", Duration: " + duration + ", Location: " + location+".";    
    }
}