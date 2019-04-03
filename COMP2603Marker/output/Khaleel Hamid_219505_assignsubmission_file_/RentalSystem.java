public class RentalSystem{//STUDENT ID: 816010298
    protected Room[] rooms;
    private int numRooms;
    
    private static  Room[] roomList = new Room[10];
    public RentalSystem(){
        numRooms = 0;
        rooms = new Room[10];
    }
    
    public String addRoom(String name, int seatingCapacity){
        if (rooms[9]!=null){
            return "Maximum rooms reached.";
        }
        Room newRoom = new Room(name, seatingCapacity);
        newRoom.roomID = newRoom.getRoomID(name);
        for(int i=0;i<10;i++){
            if(rooms[i]==null){
                rooms[i]=newRoom;
                return "RoomID: "+newRoom.getRoomID(name)+". Seating Capacity: "+seatingCapacity+".";
            }
        }
        return "Could not add room.";
    }
    
    public String getRoomList(){
        System.out.println("Room List");
        if(rooms[0]==null){
            return "No rooms in the system.";
        }
        if(rooms[0]!=null&&rooms[1]==null){
        return "RoomID: "+rooms[0].roomID + " Room Capacity: "+rooms[0].seatingCapacity; 
        }
        if(rooms[1]!=null&&rooms[2]==null){
        return "RoomID: "+rooms[0].roomID + " Room Capacity: "+rooms[0].seatingCapacity+"\nRoomID: "+rooms[1].roomID + " Room Capacity: "+rooms[1].seatingCapacity;
        }
         if(rooms[2]!=null&&rooms[3]==null){
        return "RoomID: "+rooms[0].roomID + " Room Capacity: "+rooms[0].seatingCapacity+"\nRoomID: "+rooms[1].roomID + " Room Capacity: "+rooms[1].seatingCapacity+"\nRoomID: "+rooms[2].roomID + " Room Capacity: "+rooms[2].seatingCapacity;
        }
         if(rooms[3]!=null&&rooms[4]==null){
        return "RoomID: "+rooms[0].roomID + " Room Capacity: "+rooms[0].seatingCapacity+"\nRoomID: "+rooms[1].roomID + " Room Capacity: "+rooms[1].seatingCapacity+"\nRoomID: "+rooms[2].roomID + " Room Capacity: "+rooms[2].seatingCapacity+"\nRoomID: "+rooms[3].roomID + " Room Capacity: "+rooms[3].seatingCapacity;
        }
         if(rooms[4]!=null&&rooms[5]==null){
        return "RoomID: "+rooms[0].roomID + " Room Capacity: "+rooms[0].seatingCapacity+"\nRoomID: "+rooms[1].roomID + " Room Capacity: "+rooms[1].seatingCapacity+"\nRoomID: "+rooms[2].roomID + " Room Capacity: "+rooms[2].seatingCapacity+"\nRoomID: "+rooms[3].roomID + " Room Capacity: "+rooms[3].seatingCapacity+"\nRoomID: "+rooms[4].roomID + " Room Capacity: "+rooms[4].seatingCapacity;
        }
        if(rooms[5]!=null&&rooms[6]==null){
        return "RoomID: "+rooms[0].roomID + " Room Capacity: "+rooms[0].seatingCapacity+"\nRoomID: "+rooms[1].roomID + " Room Capacity: "+rooms[1].seatingCapacity+"\nRoomID: "+rooms[2].roomID + " Room Capacity: "+rooms[2].seatingCapacity+"\nRoomID: "+rooms[3].roomID + " Room Capacity: "+rooms[3].seatingCapacity+"\nRoomID: "+rooms[4].roomID + " Room Capacity: "+rooms[4].seatingCapacity+"\nRoomID: "+rooms[5].roomID + " Room Capacity: "+rooms[5].seatingCapacity;
        }
        if(rooms[6]!=null&&rooms[7]==null){
        return "RoomID: "+rooms[0].roomID + " Room Capacity: "+rooms[0].seatingCapacity+"\nRoomID: "+rooms[1].roomID + " Room Capacity: "+rooms[1].seatingCapacity+"\nRoomID: "+rooms[2].roomID + " Room Capacity: "+rooms[2].seatingCapacity+"\nRoomID: "+rooms[3].roomID + " Room Capacity: "+rooms[3].seatingCapacity+"\nRoomID: "+rooms[4].roomID + " Room Capacity: "+rooms[4].seatingCapacity+"\nRoomID: "+rooms[5].roomID + " Room Capacity: "+rooms[5].seatingCapacity+"\nRoomID: "+rooms[6].roomID + " Room Capacity: "+rooms[6].seatingCapacity;
        }
        if(rooms[7]!=null&&rooms[8]==null){
        return "RoomID: "+rooms[0].roomID + " Room Capacity: "+rooms[0].seatingCapacity+"\nRoomID: "+rooms[1].roomID + " Room Capacity: "+rooms[1].seatingCapacity+"\nRoomID: "+rooms[2].roomID + " Room Capacity: "+rooms[2].seatingCapacity+"\nRoomID: "+rooms[3].roomID + " Room Capacity: "+rooms[3].seatingCapacity+"\nRoomID: "+rooms[4].roomID + " Room Capacity: "+rooms[4].seatingCapacity+"\nRoomID: "+rooms[5].roomID + " Room Capacity: "+rooms[5].seatingCapacity+"\nRoomID: "+rooms[6].roomID + " Room Capacity: "+rooms[6].seatingCapacity+"\nRoomID: "+rooms[7].roomID + " Room Capacity: "+rooms[7].seatingCapacity;
        }
         if(rooms[8]!=null&&rooms[9]==null){
        return "RoomID: "+rooms[0].roomID + " Room Capacity: "+rooms[0].seatingCapacity+"\nRoomID: "+rooms[1].roomID + " Room Capacity: "+rooms[1].seatingCapacity+"\nRoomID: "+rooms[2].roomID + " Room Capacity: "+rooms[2].seatingCapacity+"\nRoomID: "+rooms[3].roomID + " Room Capacity: "+rooms[3].seatingCapacity+"\nRoomID: "+rooms[4].roomID + " Room Capacity: "+rooms[4].seatingCapacity+"\nRoomID: "+rooms[5].roomID + " Room Capacity: "+rooms[5].seatingCapacity+"\nRoomID: "+rooms[6].roomID + " Room Capacity: "+rooms[6].seatingCapacity+"\nRoomID: "+rooms[7].roomID + " Room Capacity: "+rooms[7].seatingCapacity+"\nRoomID: "+rooms[8].roomID + " Room Capacity: "+rooms[8].seatingCapacity;
        }
        if(rooms[9]!=null){
        return "RoomID: "+rooms[0].roomID + " Room Capacity: "+rooms[0].seatingCapacity+"\nRoomID: "+rooms[1].roomID + " Room Capacity: "+rooms[1].seatingCapacity+"\nRoomID: "+rooms[2].roomID + " Room Capacity: "+rooms[2].seatingCapacity+"\nRoomID: "+rooms[3].roomID + " Room Capacity: "+rooms[3].seatingCapacity+"\nRoomID: "+rooms[4].roomID + " Room Capacity: "+rooms[4].seatingCapacity+"\nRoomID: "+rooms[5].roomID + " Room Capacity: "+rooms[5].seatingCapacity+"\nRoomID: "+rooms[6].roomID + " Room Capacity: "+rooms[6].seatingCapacity+"\nRoomID: "+rooms[7].roomID + " Room Capacity: "+rooms[7].seatingCapacity+"\nRoomID: "+rooms[8].roomID + " Room Capacity: "+rooms[8].seatingCapacity+"\nRoomID: "+rooms[9].roomID + " Room Capacity: "+rooms[9].seatingCapacity;
        }
        return "No rooms in the System.";
    }
    
    public String addBooking(String description, int duration, int numSeating){
        if(rooms[0]==null){
            return "The are no rooms to be booked.";
        }
        else{
            for(int i=0;i<10;i++){
                if(rooms[i]!=null&&rooms[i+1]==null&&i!=9){
                    if(rooms[i].addBooking(description,duration,numSeating).equals("Error. Duration is too great. Unsupported duration length.")){
                        return "Error. Duration is too great. Unsupported duration length.";
                    }
                    if(rooms[i].addBooking(description,duration,numSeating).equals("Error. Insufficient time available in this room.")){
                        return "Error. Insufficient time available in this room.";
                    }              
                    if(rooms[i].addBooking(description,duration,numSeating).equals("Error. Not enough seats available.")){
                        return "Error. Not enough seats available.";
                    }
                    if(rooms[i].addBooking(description,duration,numSeating).equals("Booking added successfully to room.")){
                        return "Booking added successfully to room.";
                    }
                }
            }
        }
        return "Booking could not be added.";
        /*int j=0;
        for(int i=j;i<10;i++){
            if(rooms[0]==null){
                return "The are no rooms to be booked.";
            }//This is working
            //if(rooms[i].addBooking(description,duration,numSeating).equals("Error. Insufficient time available in this room.")){
                //return "Error. Insufficient time available in this room.";
            //}
            if(rooms[i].addBooking(description,duration,numSeating).equals("Error. Not enough seats available.")){
                return "Error. Not enough seats available.";
            }
            if(rooms[i].addBooking(description,duration,numSeating).equals("Duration too long.")){
                return "Error. Time not available in room.";
            }
                
                if(rooms[i].addBooking(description,duration,numSeating).equals("Booking has been made. ")){
                return "Booking added successfully to room.";
            }
            j=i;
        }
        return "Cannot add booking.";*/
    }
    
    public String getBooking(int bookingID){
        for(int i=0;i<10;i++){
            if(rooms[i]!=null){
                for(int j=0;j<8;j++){
                    if(rooms[i].bookings[j].bookingID==bookingID){
                        return "BookingID: "+bookingID+"\nDescription: "+rooms[i].bookings[j].description+"\nDuration: "+rooms[i].bookings[j].duration+"\nNo. of Seats: "+rooms[i].bookings[j].numSeating+".";
                }
            }
        }
    }
    return "Booking ID not found.";
}

public String getBookingsByRoom(String roomID){
    for(int i=0;i<10;i++){
        if(rooms[0].roomID==null){
            return "No rooms in the system.";
        }
        if(rooms[i].roomID==roomID){
            
            return rooms[i].getBookingList();
        }
    }
    return "Room ID not found.";
}

public String getBookingGrid(){
    if(rooms[0]==null){
        return "No rooms in the System.";
    }
    for(int i=0;i<10;i++){
        while(rooms[i]!=null){
            rooms[i].getDetailedBookingGrid();
            if(rooms[i]==null){
                return "No more rooms.";
            }
            i++;
        }
    }
    return "No rooms in the system.";
}
}