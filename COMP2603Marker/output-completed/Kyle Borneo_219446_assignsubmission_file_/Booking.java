/*
 * Kyle Borneo 
 * 815006227
 * Assignment One 
 * 18/02/19
 */

import java.util.*;

public class Booking {
    private Scanner input = new Scanner(System.in);
    //private static final int Max= 10;
    private int bookingID;
    private String description="";
    private int duration;
    private String location;
    private int numSeating;
    private int bookingIDCounter=1;


    public Booking(int numSeating, String description, int duration){
        this.numSeating=numSeating;
        this.description=description;
        this.duration= duration;
        this.bookingID++;
    }

    public void set_description(String description){
        this.description= description;
    }

    public String get_description(){
        return this.description;
    }

    public void set_duration(int duration){
        this.duration= duration;
    }

    public int get_numSeating(){
        return this.numSeating;
    }

    public void set_numSeating(int numSeating){
        this.numSeating= numSeating;
    }

    public int get_duration(){
        return this.duration;
    }

    public int get_bookingID(){
        return this.bookingID;
    }

    public void setLocation(String l){
    	location = l;
    }

    public String getLocation(){
    	return location;
    }

     public String toString(){
        String s=" ";
        s="The BookingID:"+bookingID+"\nThe description: "+description+"\n"+"\nThe duration: "+duration+"\n"+"\nThe location: "+location+"\n"+s;
        return s;
    }
}