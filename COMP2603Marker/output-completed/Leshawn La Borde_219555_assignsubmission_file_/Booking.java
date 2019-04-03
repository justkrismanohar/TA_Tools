
//816007784

import java.util.Scanner;

public class Booking{
    private static int  bookingIDCounter=1; //generates unique identifiers starting from 1
    private int bookingID; //A unique identifier for a Booking e.g. 1
    private String description; //A description of the event for the Booking
    private int duration; //The duration (hours) of the booking
    private String location; //The Room allocated to the Booking 
    private int numSeating;// The seating capacity required for the Booking

//constructor
public Booking(String description, int duration, int numSeating){
    setDescription(description);
    setDuration(duration);
    setNumSeating(numSeating);
    setLocation(location);
    bookingID=bookingIDCounter;
    bookingIDCounter=bookingIDCounter+1;
}
public String toString (){
    String details= "ID: "+ bookingID +" "+ "Description: " + description+
    " "+ "Duration "+duration+" "+ "Location: "+ location;// "Seating "+numSeating;;
    return details;
}
 //Accessors 
 public int getBookingIDCounter(){
     return bookingIDCounter;
}
public int getBookingId(){
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
public int getNumSeating(int numSeating){
    return numSeating;
}
//Mutators
public int bookingIDIncrement(int bookingIDCounter){
    int increment=bookingIDCounter+1;
    return increment;
}
public void setDescription(String description){
    this.description=description;
}
public void setDuration(int duration){
    this.duration=duration;
}
public void setLocation(String location){
    this.location=location;
}
public void setNumSeating(int numSeating){
    this.numSeating=numSeating;
}
/*mutator for bookingID
public static void main(String[] args){
    
    /*Booking b= new Booking("Lecture",1,100);
    Booking b1= new Booking("Lab",2,47);
    Booking b2= new Booking("Exam",3,35);
    Booking b3= new Booking("Seminar",5,150);
    Booking b4= new Booking("Seminar",8,175);
    
    System.out.println(b.toString());
    System.out.println(b1.toString());
    System.out.println(b2.toString());
    System.out.println(b3.toString());
    System.out.println(b4.toString());
    */
}

/*
public static void main(String[] args){
    	Student s1 = new Student();
    	s1.setName("Beatrix Kiddo");
    	
    	Student s2 = new Student();
    	s2.setName("Dominic Toretto");
    	
    	System.out.println(s1.toString());
    	System.out.println(s2.toString());
    	
     }*/


