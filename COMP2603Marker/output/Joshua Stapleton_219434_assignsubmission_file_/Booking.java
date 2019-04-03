/*NAME:JOSHUA STAPLETON
 * STUDENT ID: 816010544
 * */
 
public class Booking {
 private static int bookingIDCounter =1;
 private int bookingID;
 private String description;
 private int duration;
 private String location;
 private int numSeating;
 
 public String getLocation() {
	 return location;
 }
 public int getNumSeating() {
	 return numSeating;
 }
 public int getBookingID() {
		return bookingID;
	}
	public void setLocation(String location) {
		this.location=location;
	}
Booking(String description,int duration,int numSeating){
	this.description=description;
	this.duration=duration;
	this.numSeating=numSeating;
	bookingID=bookingIDCounter;
	bookingIDCounter++;
	location=null;
}

public String toString() {
	String details="";
	details="Booking ID:" +bookingID + " Description: " + description + " Duration: "+duration + " Location: " + location;
	return details;
}
public int getDuration() {
	return duration;
}

}