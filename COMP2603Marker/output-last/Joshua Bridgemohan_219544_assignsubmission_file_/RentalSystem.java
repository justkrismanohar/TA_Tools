import java.util.LinkedList;
import java.util.Scanner;
public class RentalSystem
{
    private static Room[] rooms = new Room[10];
    
    public static void main()
    {
        rooms[0] = new Room("Lecture Room 1",120);
        rooms[1] = new Room("Computer Science Lab 1",100);
        rooms[2] = new Room("Computer Science Lab 2",150);
        rooms[3] = new Room("Lecture Room 2", 300);
        rooms[4] = new Room("Lecture Room 3",70);
    
    for(int i = 0; i < 5; i++)
        {
            rooms[i].generateRoomID();
            System.out.println(rooms[i].GetRoomID());
        }
    }
    
    
}