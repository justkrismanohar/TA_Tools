/*NAME:JOSHUA STAPLETON
 * STUDENT ID: 816010544
 * */
 
public class Room {
private final int numSlots=8;
private static int roomIDCounter=100;
private String roomID;
private Booking[] bookings = new Booking[numSlots];
private int seatingCapacity;
private int count=0;




Room(String name,int seatingCapacity){
	roomID=name+roomIDCounter;
	roomIDCounter+=100;
	this.seatingCapacity=seatingCapacity;
	
}


public String addBooking(String description,int duration,int seats) {
			
	if(canFitNumbers(seats)==false || canFitTime(duration)==false) {
		return null;
	}else {
		
		bookings[count]= new Booking(description,duration,seats);
		bookings[count].setLocation(roomID.substring(0, 3));
		count++;
	}
	return "Booking added to schedule";
	
}

public boolean canFitNumbers(int numSeats) {
	if(numSeats>this.seatingCapacity)
		return false;
	else 
		return true;
}

public boolean canFitTime(int duration) {
	if(duration>numSlots) {
		return false;
	}
	else
		return true;
}

public String getBookingDetails(int bookingID) {
	for (int i=0;i<bookings.length;i++) {
		if(bookings[i].getBookingID()==bookingID) {
			return bookings[i].toString();
		}				
	}
	return "No bookings have been made with Booking ID:" + bookingID;
}

public String getBookingList() {
	String details="";
	if(count==0) {
		return "No bookings made";
	}
	System.out.println("BOOKING GRID");
	for (int i=0;i<count;i++) {
		details+="Name:" +bookings[i].getLocation()+" RoomID:" + roomID + " Seats:" + bookings[i].getNumSeating() +"\n";

}
	return details;
}
public String getDetailedBookingGrid() {
	String grid="";
	grid+=roomID;
	for (int i=0;i<count;i++) {
		
		for(int x=0; x<bookings[i].getDuration(); x++) {
			grid+=  "|"+bookings[i].getBookingID()+ "|" ;
		}	
		
	}
	return grid;
}
	
public String getRoomID() {
	return roomID;
}


public boolean hasBooking(int bookingID) {
	for(int i=0;i<count;i++) {
		if(bookings[i].getBookingID()==bookingID) {
			return true;
		}
	}
	return false;
}
public String toString() {
	String details="";
	details+="roomID:"+roomID+" Seating Capacity: "+ seatingCapacity;
	return details;
}

}