/*
StudentID: 816117607
StudenName: Joshua Peter:
Assignment: 1
*/

public class RentalSystem
    {
    private Room[] rooms;
    private int numRooms;
    private String list;
    private int x;
    
    public RentalSystem()
    {
        this.rooms = new Room[10];
        this.numRooms=0;
    }
    
    public String addRoom(String name,int seatingCapacity){
        if(!validateRoomName(name)){
            return "Invalid Room name\n";
        }; 
        if(seatingCapacity <= 0){
            return "Invalid Seating Capacity\n";
        };
                        
        if(numRooms <10){
            this.numRooms +=1;
            this.rooms[numRooms-1] = new Room(name,seatingCapacity);
            return this.rooms[numRooms-1].toString() + "\n";
        }
        else
            return "Cannot add room; Max rooms reached\n";
    }
    
    public String getRoomList(){
        if(this.numRooms == 0)
            return "No rooms in the system\n";
        else{
            list = "Room List: \n";
            for(x = 0; x < numRooms; x++){
                list = list + rooms[x].toString() + "\n";
            }
            return list;
        }
    }
    
    public String addBooking(String description,int duration, int numSeating){
        for(x = 0; x < numRooms; x++){
            list = rooms[x].addBooking(description,duration,numSeating);
            
            if (list != null){
                return list;
            }
        }
        return "Cannot Add Booking\n";
    
    }

    public String getBooking(int bookingID){
        for(x = 0; x < numRooms; x++){
            if (rooms[x].hasBooking(bookingID)){
                return rooms[x].getBookingDetails(bookingID) + "\n";
            }
        }
        return "Booking ID not Found \n";
    }

    public String getBookingsByRoom(String roomID){
        if(!validateRoomID(roomID)){
            return "Invalid Room ID entered \n";
        }
        for(x = 0; x < numRooms; x++){
            if (rooms[x].getRoomID().equals(roomID)){
                return rooms[x].getBookingList();
            }
        }
        return "roomID not Found\n";
    }

    public String getBookingGrid(){
        if (numRooms ==0){
            return "No rooms in the system\n";
        }
        
        list="";
        for(x = 0; x < numRooms; x++){
            list= list + rooms[x].getDetailedBookingGrid() + "\n";
        }
        return list;
    }
    
    private boolean validateRoomName(String roomName){
        String [] arr = roomName.split("");
        if(arr.length != 3){
            return false;
        }
        for(x=0; x<arr.length; x++){
            if (arr[x].compareTo("A") < 0 || arr[x].compareTo("Z") > 0)
                return false;
        }
        
        return true;
    }
    
    public boolean validateNumbers(String number){
        String [] arr = number.split("");
        for(x=0; x<arr.length; x++){
            if (arr[x].compareTo("0") < 0 || arr[x].compareTo("9") > 0)
                return false;
        }
        
        return true;
    }

    private boolean validateRoomID(String bookingID){
        String [] arr = bookingID.split("");
        for(x=0; x<3; x++){
                if (arr[x].compareTo("A") < 0 || arr[x].compareTo("Z") > 0)
                return false;
        }
        
        for(x=3; x<arr.length; x++){
            
            if (arr[x].compareTo("0") < 0 || arr[x].compareTo("9") > 0)
                return false;
                
        }
        return true;
    }
    
    private boolean validateDescription(String description){
        String [] arr = description.split("");
        if(arr.length != 3){
            return false;
        }
        for(x=0; x<arr.length; x++){
            if (arr[x].compareTo("A") < 0 || arr[x].compareTo("Z") > 0)
                return false;
        }
        
        return true;
    }

}
