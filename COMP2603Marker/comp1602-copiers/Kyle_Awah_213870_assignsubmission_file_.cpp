//  Created by Kyle Awah on 27/01/2019.
//  UWI Studentd ID: 816012635
//  Assignment #1


#include <iostream>            // calling the header file input output to be used within the program
#include <fstream>             // calling the library file for files to be used within the program
using namespace std;      // Declaring standard output method to be used

// General Functions

void order(void);              // Prototyped functions so the C++ compiler can see it
void input(void);              // Prototyped functions so the C++ compiler can see it
void cal(void);                // Prototyped functions so the C++ compiler can see it
void output(void);             // Prototyped functions so the C++ compiler can see it
void output_header(void);      // Prototyped functions so the C++ compiler can see it
void output_footer(void);      // Prototyped functions so the C++ compiler can see it
void RESET(void);              // Prototyped functions so the C++ compiler can see it


// Functions for Calculations

bool perfect(int current_number);         // Prototyped functions so the C++ compiler can see it
bool prime(int current_number);           // Prototyped functions so the C++ compiler can see it
bool perfect_square(int current_number);  // Prototyped functions so the C++ compiler can see it
bool sphenic(int current_number);         // Prototyped functions so the C++ compiler can see it
void binary_conversion(void);              // Prototyped functions so the C++ compiler can see it
void histogram(void);                      // Prototyped functions so the C++ compiler can see it
void favenumbers(void);                    // Prototyped functions so the C++ compiler can see it



// Variables Declared golbally so that they can be acessed by all functions

// file variables
ifstream input_stream;      // this is the variable for input from a file

// number variables
int current_number = 0;                     // this holds the number entered buy the program
int this_holds_the_original_number = 0;     // this stores the number so that it is not manipuated

int all_numbers[101];                  // this holds all the numbers entred in the program
int all_numbers_pointer = 0;          // pointer for the above array
int all_numbers_scan_start = 0;       // pointer for the above array to scan from


int binary_conversion_holder = 0;   // holds the number to be converted to binary
int binary_conversion_array [8] = {'0','0','0','0','0','0','0','0'};    // this is an array to hold the binary conversion of the number
int binary_pointer = 0;            // this is used to incriment to the next position in the array to hold the binary digit
int pointer_start_position = 0;    // this scans the array to print all the variables in it

int invalid_array [101];            // this array holds all the invlaid numbers
int invalid_pointer = 0;           // this pointer points to varibales in the array
int invalid_print_start = 0;       // this scans the array to print all the variables in it

int new_line_counter =0;            // this tells when to indent after the 5 numbers

int historgram_array[10];           // this array holds the counter for each level in the array
int historgram_pointer = 0;         // this is a pointer for reading the array

int most_popular_number = 0;        // this holds the most popular number
int least_popular_number = 999;      // this holds the least popular number

int participant_counter = 0;        // holds how many participants there are
int valid_counter = 0;              // holds how many valid numbers there are
int invalid_counter = 0;            // holds how many invalid numbers there are
int hidden_fave_counter = 0;         // holds how many invalid numbers there are

int array_reset = 0;                // this is used to reset the binary array back to all 0's so that it correctly shows the binary conversion
bool distinct = false;                // this is used to see if the number is distinct and has not been in the file before
int fave_numbers_scan = 0;          // this is used to scan the array after and find the most popular number





int main()                  // This Just Tells it Where to Go
{
    order();
    return 0;
}





void order()                // This Tells The Program What Order To Do Things in
{
    input_stream.open("numbers.txt");          // linking the triath.txt file to the input_stream variable to be used within the program
    
    
    if (!input_stream.is_open())    // if it cannot find the file triath.txt notify the user by doing this
    {
        cout<<endl<<endl;
        cout<<"\t =============================================== \n";
        cout<<"\t     ERROR: FILE numbers.txt CANNOT BE FOUND     \n";
        cout<<"\t =============================================== \n";
        cout<<endl;
        cout<<"\t Please try moving the numbers.txt file to the same\n";
        cout<<"\t folder as your .cpp file and restart the program\n";
        cout<<endl<<endl<<endl;
        return;
        // returning without putting a 0 causes a void function to end its operations and return back to where ever it was called from, in this case, main
    }
    
    
    output_header();    // prints the header for the table before anything
    
    input();    // inputs the number before the while loop incase the first number is -1
    
    
    while (current_number != -1)    // this loops the entire program for all the numbers until -1 is found to signify the end
    {
        participant_counter++; // incriment the participant counter if its in this loop because that means there is a new participant
        
        
        
        if (current_number <= 100 && current_number >= 1)   // if current number is valid then do the program
        {
            valid_counter++;    // incriment the valid counter because this number is valid
            
            histogram();       // this checks for the histogram ranges wether the number is a new number (aka a distinct number) or not

            
            if (all_numbers[current_number] == 0)   // if the current number has not been processed before then it is distinct
            {
                distinct = true;
            }
            
            
            all_numbers[current_number]++;  // incriment the counter to say that the current number has had another entry

            
            
            if (distinct == true)    // if the number is a new or distinct number that has not been through the program yet then do this
            {
                cal();
                output();
            }
        }

        
        
        
        if (current_number == 0)    // if the participant didnt reveal their number then do this
        {
            hidden_fave_counter++;  // incriment the counter
        }
        
        
        
        
        
        if (current_number > 100 || current_number <= -2)    // else if the current number isnt valid then store it in the array
        {
            invalid_counter++;     // incriment the invalid counter because this number is invalid
            
            invalid_pointer++;     // incriment the pointer for the array so the new value doesnt overeride the last one
            invalid_array[invalid_pointer] = current_number;
        }
        
        RESET();   // this function reset's everything so that the program will funcition properly
        input();    // this inputs a new value into the program
    }   // end of the while loop which loops the entire program
    
    
    favenumbers();  // checks for the most & least popular numbers

    output_footer();    // prints the footer of the output after the program has finished executing
   
    
    
    
    
    input_stream.close();       // closing the input file stream
    
    // after here the program just goes back to main and ends
}








void input()   // inputs data
{
    input_stream >> current_number;               // inputs a new number to be run through the program
    this_holds_the_original_number = current_number;    // this holds the orignal number so that it isnt lost in the calculations
}









void RESET()    // this function is used for resetting things so that the program will function properly
{
    binary_pointer = 0;     // this resets the binary pointer back to the begining of the array so that the binary entred is still within the size of the array
    
    for (int array_reset = 0; array_reset < 7 ; array_reset++)  // this resets the array so that it accuratley converts the binary
    {
        binary_conversion_array [array_reset] = 0;
    }
    
    distinct = false;   // resets the distinct status to false to that it will accuratley tell the program if the current number is distinct or not
}







void cal()  // this does all the calculations
{
    // calling the functions to perform the calculations to be done in the program
    
    current_number = this_holds_the_original_number; // reseting the current number after it has been manipulated by the function
    perfect(current_number);

    
    current_number = this_holds_the_original_number; // reseting the current number after it has been manipulated by the function
    prime(current_number);

    
    current_number = this_holds_the_original_number; // reseting the current number after it has been manipulated by the function
    perfect_square(current_number);

    
    current_number = this_holds_the_original_number; // reseting the current number after it has been manipulated by the function
    sphenic(current_number);

    
    current_number = this_holds_the_original_number; // reseting the current number after it has been manipulated by the function
    binary_conversion();
}








void binary_conversion()    // this function converts a normal int into binary
{
    binary_conversion_holder = current_number;  // gives the variable for calculating the binary the current number in the loop
    
    while (binary_conversion_holder != 0 || binary_pointer < 7)      // while the number has not reached 0 or the array is full then do the conversion
    {
        binary_conversion_array[binary_pointer] = binary_conversion_holder % 2;
        binary_conversion_holder = binary_conversion_holder / 2;
        
        binary_pointer++;
    }
}






void favenumbers()  // this finds the most and least popular numbers
{
    
    for(fave_numbers_scan = 0 ; fave_numbers_scan <= 100 ; fave_numbers_scan++)
    {
        
        if (all_numbers[fave_numbers_scan] > most_popular_number && all_numbers[fave_numbers_scan] > 1)   // if the counter for the most popular number in the current position has a larger number then its the most popular
        {
            most_popular_number = fave_numbers_scan;
        }
        
        
        
        else if (all_numbers[fave_numbers_scan] < least_popular_number && all_numbers[fave_numbers_scan] > 0) // if the counter for the current number has a smaller count than the least then its the least popular number
        {
            least_popular_number = fave_numbers_scan;
        }
        
    }
}









void histogram()        // this function fills in the histogram
{
    // this function is used to check the range of the current number and assign it to a position in the array
    
    
    if(current_number >= 1 && current_number <= 10)     // check for if the number falls between 1 and 10
    {
        historgram_array[0]++;
    }
    
    
    if(current_number >= 11 && current_number <= 20)    // check for if the number falls between 11 and 20
    {
        historgram_array[1]++;
    }
    
    
    if(current_number >= 21 && current_number <= 30)    // check for if the number falls between 21 and 30
    {
        historgram_array[2]++;
    }
    
    
    if(current_number >= 31 && current_number <= 40)    // check for if the number falls between 31 and 40
    {
        historgram_array[3]++;
    }
    
    
    if(current_number >= 41 && current_number <= 50)    // check for if the number falls between 41 and 50
    {
        historgram_array[4]++;
    }
    
    
    if(current_number >= 51 && current_number <= 60)    // check for if the number falls between 51 and 60
    {
        historgram_array[5]++;
    }
    

    if(current_number >= 61 && current_number <= 70)    // check for if the number falls between 61 and 70
    {
        historgram_array[6]++;
    }
    

    if(current_number >= 71 && current_number <= 80)    // check for if the number falls between 71 and 80
    {
        historgram_array[7]++;
    }
    

    if(current_number >= 81 && current_number <= 90)    // check for if the number falls between 81 and 90
    {
        historgram_array[8]++;
    }
    
    
    if(current_number >= 91 && current_number <= 100)    // check for if the number falls between 91 and 100
    {
        historgram_array[9]++;
    }
}















bool perfect(int current_number)  // tests for the number being perfect
{
    int current_point = 1;
    int sum = 0;
    
    for (current_point = 1 ; current_point < current_number ; current_point++)
    {
        if (current_number % current_point == 0)
        {
            sum = sum + current_point;
        }
    }
    
    
    
    if (sum == current_number)
    {
        return true;
    }
    
    
    else
    {
        return false;
    }
}












bool prime(int current_number)    // tests for the number being a prime number
{
    if (current_number % current_number == 0 && current_number % 1 == current_number)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}







bool perfect_square(int current_number)   // tests for the number being a perfecg square
{
    int square = 1;
    int start_point = 1;

    for (start_point = 1 ; start_point <= current_number ; start_point++)
    {
        square = start_point * start_point;
        if ( square == current_number )
        {
            return true;
        }
    }

    return false;
    
}






bool sphenic(int number_from_file)       // tests for the number being sphenic
{
    int start_point;
    int counter = 0;
    int product = 1;
    int half = 0;
    half = number_from_file / 2;
    
    for (start_point = 2; start_point <= half ; start_point++) // this loops over all the possible factors of the number
    {
        if (number_from_file % start_point == 0 && prime(start_point))  // if the number found is prime and not 0 then do this
        {
            product = product * start_point;    // this is used to check if the product is equal to the number in the end
            counter++;                          // this adds 1 to the counter
        }
    }

    
    if (counter == 3 && product == number_from_file)    // if these conditions apply then the number is sphenic
    {
        return true;
    }
 
    
    else    // else the number isnt sphenic
    {
        return false;
    }
    
}







void output_header()    // prints the header for the output
{
    cout<<endl<<endl;
    cout<<"                                           ============================================                                      "<<endl<<endl;
    cout<<"                                           STUDENT'S FAVOURITE NUMBER STATISTICS SYSTEM                                     "<<endl<<endl;
    cout<<"                                           ============================================                                      "<<endl;
    cout<<endl<<endl<<endl<<endl;
    cout<<"    ==================================================================================================================="<<endl;
    cout<<"    Number          Perfect?          Prime?          Perfect Square?           Sphenic?          Binary Representation"<<endl;
    cout<<"    ==================================================================================================================="<<endl;
}







void output_footer()    // prints the footer for the output
{
    cout<<"    ==================================================================================================================="<<endl;
    cout<<endl<<endl;
    cout<<"                                       ======================================                                      "<<endl;
    cout<<"                                       GENERAL INFORMATION ABOUT PARTICIPANTS                                      "<<endl;
    cout<<"                                       ======================================                                      "<<endl;
    cout<<endl<<endl;
    
    
    cout<<"                                ================================================"<<endl;
    cout<<"                                | Total Number of Participants:            "<<participant_counter<<" |";
    cout<<endl;
    cout<<"                                |                                              |"<<endl;
    
    cout<<"                                | Number of VALID favorite numbers:        "<<valid_counter<<" |";
    cout<<endl;
    
    cout<<"                                | Number of INVALID favorite numbers:      "<<invalid_counter<<"   |";
    cout<<endl;
    
    cout<<"                                | Number of NON-REVEALED favorite numbers: "<<hidden_fave_counter<<"   |";
    
    
    
    
    cout<<endl;
    cout<<"                                |                                              |"<<endl;
    
    cout<<"                                | The Most Popular Number Was:             "<<most_popular_number<<"   |";
    cout<<endl;
    
    cout<<"                                | The Least Popular Number Was:            "<<least_popular_number<<" |";
    cout<<endl;
    cout<<"                                |                                              |"<<endl;
    
    
    
    
    if (invalid_pointer == 0)   // if there are no invalid numbers then do this
    {
        cout<<"                                |                                              |"<<endl;
        cout<<"                                | There are no invalid numbers                 |"<<endl;
        cout<<"                                |                                              |"<<endl;
        cout<<"                                  ";
        
    }
    
    
    
    
    else    // if there are invalid numbers then print the invalid numbers using this
    {
        
        cout<<"                                |                                              |"<<endl;
        cout<<"                                | Invalid Numbers Recieved from File were:     |";
        cout<<endl;
        cout<<"                                |                                              |"<<endl;
        cout<<"                                | ";
        
        
        
        // start off the below pointer for the loop at 1 to avoid the 0 from the array being an invalid number since it is valid
        for (invalid_print_start = 1 ; invalid_print_start <= invalid_pointer ; invalid_print_start ++) // this prints out all the invalid numvers which were stored in the array
        {
            cout<<invalid_array[invalid_print_start]<<" , ";
            new_line_counter++;
            if (new_line_counter % 5 == 0)   // if 5 numbers have passed then put the other numbers on a new line
            {
                cout<<"               |";
                cout<<endl;
                cout<<"                                | ";
            }
        }
        
        cout<<"                     |";
        
        
        cout<<endl;
        cout<<"                                |                                              |"<<endl;
        cout<<"                                ================================================"<<endl;
        
    }
    
    
    
    
    
    
    
    cout<<endl<<endl<<endl<<endl<<endl;

    
    
    cout<<"                                                ===================                                      "<<endl;
    cout<<"                                                  HISTOGRAM CHART                                        "<<endl;
    cout<<"                                                ===================                                      "<<endl;
    cout<<endl<<endl;
    
    cout<<"                                        ==================================                         "<<endl;
    cout<<"                                        |                                |"<<endl;
    cout<<"                                        |   RANGE           HISTOGRAM    |";
    cout<<endl;
    cout<<"                                        |   ==========================   |";
    cout<<endl;
    
    
    
    
    
    // this adds stars for range 0
    cout<<"                                        |   1 - 10          | ";
    while(historgram_array[0] != 0)
    {
        if (historgram_array[0] % 5 == 0)
        {
            cout<<"*";
        }
        historgram_array[0] --;
    }
    cout<<"         |"<<endl;
    
    
    
    // this adds stars for range 1
    cout<<"                                        |   11 - 20         | ";
    while(historgram_array[1] != 0)
    {
        if (historgram_array[1] % 5 == 0)
        {
            cout<<"*";
        }
        historgram_array[1] --;
    }
    cout<<"        |"<<endl;

    
    // this adds stars for range 2
    cout<<"                                        |   21 - 30         | ";
    while(historgram_array[2] != 0)
    {
        if (historgram_array[2] % 5 == 0)
        {
            cout<<"*";
        }
        historgram_array[2] --;
    }
    cout<<"         |"<<endl;

    
    // this adds stars for range 3
    cout<<"                                        |   31 - 40         | ";
    while(historgram_array[3] != 0)
    {
        if (historgram_array[3] % 5 == 0)
        {
            cout<<"*";
        }
        historgram_array[3] --;
    }
    cout<<"          |"<<endl;

    
    // this adds stars for range 4
    cout<<"                                        |   41 - 50         | ";
    while(historgram_array[4] != 0)
    {
        if (historgram_array[4] % 5 == 0)
        {
            cout<<"*";
        }
        historgram_array[4] --;
    }
    cout<<"          |"<<endl;

    
    // this adds stars for range 5
    cout<<"                                        |   51 - 60         | ";
    while(historgram_array[5] != 0)
    {
        if (historgram_array[5] % 5 == 0)
        {
            cout<<"*";
        }
        historgram_array[5] --;
    }
    cout<<"          |"<<endl;

    
    // this adds stars for range 6
    cout<<"                                        |   61 - 70         | ";
    while(historgram_array[6] != 0)
    {
        if (historgram_array[6] % 5 == 0)
        {
            cout<<"*";
        }
        historgram_array[6] --;
    }
    cout<<"        |"<<endl;

    
    // this adds stars for range 7
    cout<<"                                        |   71 - 80         | ";
    while(historgram_array[7] != 0)
    {
        if (historgram_array[7] % 5 == 0)
        {
            cout<<"*";
        }
        historgram_array[7] --;
    }
    cout<<"          |"<<endl;
 
    
    // this adds stars for range 8
    cout<<"                                        |   81 - 90         | ";
    while(historgram_array[8] != 0)
    {
        if (historgram_array[8] % 5 == 0)
        {
            cout<<"*";
        }
        historgram_array[8] --;
    }
    cout<<"          |"<<endl;

    
    // this adds stars for range 9
    cout<<"                                        |   91 - 100        | ";
    
    while(historgram_array[9] != 0)
    {
        if (historgram_array[9] % 5 == 0)
        {
            cout<<"*";
        }
        historgram_array[9] --;
    }
    cout<<"          |"<<endl;

    
    cout<<"                                        |   ===========================  |";
    cout<<endl;
    cout<<"                                        |                                |"<<endl;

    cout<<"                                        ==================================                           "<<endl;

    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    
}







void output()       // This outputs the core of the data for the program
{
    cout<<"    "<<this_holds_the_original_number<<"              ";
    
    
    if (perfect(current_number))  // if the number is perfect
    {
        cout<<"Yes               ";
    }
    
    else
    {
        cout<<"No                ";
    }
    
    
    
    
    
    
    if (prime(current_number))  // if the number is prime
    {
        cout<<"Yes             ";
    }
    
    else
    {
        cout<<"No              ";
    }
    
    
    
    
    
    
    if (perfect_square(current_number))  // if the number is perfect square
    {
        cout<<"Yes                       ";
    }
    
    else
    {
        cout<<"No                        ";
    }
    
    
    
    
    
    if (sphenic(current_number))  // if the number is sphenic
    {
        cout<<"Yes               ";
    }
    
    else
    {
        cout<<"No                ";
    }
    
    
    
    for(pointer_start_position = 0 ; pointer_start_position < 7 ; pointer_start_position ++) // this goes through the array and prints all the numbers so that the binary conversion of the number is printed
    {
        cout<<binary_conversion_array[pointer_start_position];
    }
    
    
    cout<<endl; // this starts the charateristics of the numbers on a new line for the next number comming from the file
}
