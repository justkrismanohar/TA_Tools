/*NAME:JOSHUA STAPLETON
 * STUDENT ID: 816010544
 * */
 
public class RentalSystem {

private static int numRooms=0;
private static int count=0;
private final int maxRooms=10;
private Room[] rooms= new Room[maxRooms];

RentalSystem(){
	numRooms++;
}

public String addRoom(String name,int seatingCapacity) {
	if(count<=maxRooms) {
		
		rooms[count]=new Room(name,seatingCapacity);
		count++;
		
		
		
		return "Room added successfully";
	}
	else
		return "Cannot add room; Max rooms reached";
}

public String getRoomList() {
	
	if(count<1) {
	
		return "No rooms in System";
	}
	
	String[] manRooms=new String[maxRooms];
	String listRooms="";
	
	for(int i=0;i<count;i++) {
		//System.out.println(rooms[i].getRoomID());
		manRooms[i]=rooms[i].getRoomID();
		//System.out.print(manRooms[i]);
		
	}
	for(int i=0;i<count;i++) {
		
		listRooms+=manRooms[i] +"\n";
	}
	//System.out.print("TEST");
	//System.out.print(listRooms);
	return listRooms;
	
}
public String addBooking(String description,int duration, int numSeating) {
	for(int i=0;i<count;i++) {
		
	if(rooms[count-1].canFitNumbers(numSeating)==true&&rooms[count-1].canFitTime(duration)==true) {
		rooms[count-1].addBooking(description,duration,numSeating);
		return "Booking added successfully";	
	}
					
}
		return "Cannot add booking";

}

public String getBooking(int bookingID) {
	for(int i=0;i<count;i++) {
	if(rooms[count-1].hasBooking(bookingID)==true) {
		return rooms[count-1].getBookingDetails(bookingID);
		
	}
}
	
		return "Booking ID not found";
}
public String getBookingsByRoom(String RoomID) {
	for(int i=0;i<count;i++) {
	if(rooms[count-1].getRoomID().equals(RoomID)) {
		return rooms[count-1].getBookingList();
	}
		
}
	return "Room ID not found in system";
}
public String getBookingGrid() {
	String grid="";
	for (int i=0;i<count;i++) {
		grid+=rooms[i].getDetailedBookingGrid();
	}
	return grid;
}
}
