//STUDENT ID: 816016181
//Assignment 1
//COMP 1602

#include <iostream>
#include <fstream>  //file stream
using namespace std;

char isPerfect(int n) { //Perfect function b)i)
    
    int sum =0; //sum variable
    int i; //variable for FOR loop
    
    for (i =1; i <=n/2; i=i+1) {
        if (n%i==0)
            sum=sum+i; //adds factor to sum
    }
    
    if (sum==n) { //compares sum of factors to original num
        return 'Y';
    }
    else
        return 'N';
}//ends perfect function

char isPrime (int n){ //prime numbeer function b)ii)
    
    int i;
    for (i=2; i<=n/2; i=i+1){ //checks for factors from 2 to half of number since 1 is not a prime number
        if (n%i==0)
            return 'N'; //if factor is found returns N
    }
    return 'Y'; //if not factors are found returns Y ie. PRIME
}//ends prime function

char isPerfectSquare (int n){ //perfect square function b)iii)
    double i;
    for (i=1.0; i<=(n/2); i=i+1){
        if ((i*i)==n) //checks if a number (between 2 to half n) squared equals n
            return 'Y'; //if n= square of a number returns Y
    }
    
    return 'N'; //returns N
} //ends perfect square function

char isSphenic (int n){ //sphenic function b)iv)
    
    int i, count=0, prod=1;
    
    for (i=2; i<n; i=i+1){
        if (n%i==0 && isPrime(i)=='Y'){ //check for factors of n and checks if these factors are prime
            prod=prod*i; //check if factors gives original value
            count=count+1; //count ensures that there are only 3 factors
        }//ends if
    }//ends for loop
    
    if (count==3 && prod==n)
        return 'Y'; //returns Y if conditions fulfilled
    
    else
        return 'N'; //returns N if number is not Sphenic
}//ends sphenic function

void binaryConversion (int n){ //converts number to binary b)v)
    
    int arr[8]; //declears array to store remainders
    int i=0;
    
    while (n>0){  //Converts to binary
        arr[i]=n%2;
        n= n/2;
        i=i+1; //increment array index
    }//ends while loop
    
    while(i<8){
        arr[i]=0; //fills remain array elements with zero to get leading zeros
        i++; //increment to next array element
    }//ends while loop
    
    for(i=i-1; i>=0; i=i-1){ //prints out conversion in (reverse of array)
        cout<<arr[i]; //
    }
    
}//ends binary function


int main (){
    
    int num, notReveal=0, numInvalid=0,valid=0; //variables for counting frequency of number types
    int j; //used in for loop to print table
    int r1to10=0, r11to20=0, r21to30=0, r31to40=0, r41to50=0, r51to60=0, r61to70=0, r71to80=0, r81to90=0, r91to100=0; //ranges for histogram
    int arr[101]; //declear arr for favourite number
    ifstream input; //input stream for file
    input.open("numbers.txt"); //opens file
    
    if (!input.is_open()){ //checks if file is found
        cout<<"File could not be found. Aborting!.."<<endl; //ends program is file is not found
        return 0;
    }
    
    for (j=0; j<=101; j=j+1) //initialize array with values of zero
        arr[j]=0;
    
    cout<<"---------------------------------------------------------------------------------"<<endl; //output header
    cout<<"\t\t\t\t\t\tSTUDENT'S FAVOURITE NUMBER POLL"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl<<endl<<endl;
    
    cout<<"Number\t\tPerfect?    \tPrime?    \tPerfect Square?    \tSphenic?   \tBinary Equiv."<<endl; //table header
    cout<<"======\t\t========    \t======    \t==============    \t========   \t============="<<endl;
    
    input>>num; //inputs first number from file (a)
    
    while (num!=-1){ //checks to ensure that the number is valid
        
        if (num>0 && num<=100){ //checks if number is valid
            valid=valid+1; //counts valid number choices
            arr[num]=arr[num]+1; //increase count of array element for valid number read in.
            
            if(num>=1 && num<=10) //counts number of times a number in the range was selected for histogram usage.
                r1to10++;
            
            else if(num>=11 && num<=20)  //else if- only looks through range if num did not satify previous range
                r11to20++;
            
            else if(num>=21 && num<=30)
                r21to30++;
            
            else if(num>=31 && num<=40)
                r31to40++;
            
            else if(num>=41 && num<=50)
                r41to50++;
            
            else if(num>=51 && num<=60)
                r51to60++;
            
            else if(num>=61 && num<=70)
                r61to70++;
            
            else if(num>=71 && num<=80)
                r71to80++;
            
            else if(num>=81 && num<=90)
                r81to90++;
            
            else if(num>=91 && num<=100)
                r91to100++;
        } // ends valid number check
        
        if (num==0)  //counts number of times students did not reveal their favourite number
            notReveal=notReveal+1;
        
        if (num<-1 || num>100) //counts number of times an invalid number was choosen
            numInvalid=numInvalid+1;
        
        input>>num; //reads in new numbe from file
    } //ends while loop
    
    input.close(); //closes file
    
    for (j=1; j<101; j=j+1){ //traverses the array to print valid distinct numbers choosen using function calls (b)
        if (arr[j]>0){ //ensures that the number was choosen at least once
            
            cout<<j<<"    \t\t"<<isPerfect(j)<<"       \t\t"<<isPrime(j)<<"      \t\t"<<isPerfectSquare(j)<<"                \t"<<isSphenic(j)<<"       \t";
            binaryConversion(j);
            cout<<endl;
        }
    }
    cout<<"---------------------------------------------------------------------------------"<<endl; //end of table
    
    int k=0; //counts number of numbers printed in the line
    input.open("numbers.txt"); // reopens file so it reads from first number (c)
    cout<<endl<<endl;
    cout<<"---------------------------------"<<endl; //invalid numbers header
    cout<<"    INVALID NUMBERS ENTERED"<<endl;
    cout<<"---------------------------------"<<endl;
    
    input>>num; //reads in first number
    while (num!=-1) { //checks for end of file
        if (num<-1 || num>100){ //checks if number satisfies invalid criteria
            cout<<num<<",   "; //cout numbers and comma
            k=k+1; //counts how many numbers have been outputed
            if (k%5==0) //prints endl when 5 numbers has been printed
                cout<<endl;
        }
        input>>num; //reads new value
    } //ends while loops
    
    cout<<endl<<endl<<endl; //skip lines
    
    cout<<"==========================="<<endl; //histogram header (d)
    cout<<"Range\t\tHistogram"<<endl;
    cout<<"==========================="<<endl;
    
    cout<<"1-10        |";  //prints range
    while (r1to10>=5){ //checks if (remaining) number of times choosen is 5 or greater
        cout<<"*"; //prints star
        r1to10-=5; //subtracts five from number of occurances
    }
    cout<<endl;
    
    cout<<"11-20       |";
    while (r11to20>=5){
        cout<<"*";
        r11to20-=5;
    }
    cout<<endl;
    
    cout<<"21-30       |";
    while (r21to30>=5){
        cout<<"*";
        r21to30-=5;
    }
    cout<<endl;
    
    cout<<"31-40       |";
    while (r31to40>=5){
        cout<<"*";
        r31to40-=5;
    }
    cout<<endl;
    
    cout<<"41-50       |";
    while (r41to50>=5){
        cout<<"*";
        r41to50-=5;
    }
    cout<<endl;
    
    cout<<"51-60       |";
    while (r51to60>=5){
        cout<<"*";
        r51to60-=5;
    }
    cout<<endl;
    
    cout<<"61-70       |";
    while (r61to70>=5){
        cout<<"*";
        r61to70-=5;
    }
    cout<<endl;
    
    cout<<"71-80       |";
    while (r71to80>=5){
        cout<<"*";
        r71to80-=5;
    }
    cout<<endl;
    
    cout<<"81-90       |";
    while (r81to90>=5){
        cout<<"*";
        r81to90-=5;
    }
    cout<<endl;
    
    cout<<"91-100      |";
    while (r91to100>=5){
        cout<<"*";
        r91to100-=5;
    }
    
    cout<<endl<<endl<<endl; //skips lines
    
    int totalNum=valid+numInvalid+notReveal;
    cout<<"The number of students who participated: "<<totalNum<<" students"<<endl; //prints number of students participated
    cout<<"The number of students who specified valid favourite numbers: "<<valid<<" students"<<endl;  //prints number of valid entries (e)(i)
    cout<<"The number of students who specified invalid favourite numbers: "<<numInvalid<<" students"<<endl;  //prints number of invalid entries (e)(i)
    cout<<"The number of students who did not reveal favourite numbers: "<<notReveal<<" students"<<endl<<endl; //prints number of not revealed entries (e)(i)
    
    cout<<"The number/s that was/were chosen the most: "; //(e)(ii)
    int max=1;
    for (j=1; j<101; j=j+1){ //traverse array
        if (arr[j]>=max) //compares number of times the valid number is choosen to the current highest number of times previous number was choosen.
            max=arr[j]; //updates max variable if new highest times choosen is found
    }
    
   for (j=1; j<101; j=j+1){ //traverse array
       if (arr[j]==max) //if the number of times chosen is equal to the max number of times a number was choosen
       cout<<j<<","; //prints the number. Takes in consideration that there may be mutiple numbers that have been choosen the same number of times.
  }
    
    cout<<endl<<endl; //skip lines
    
    cout<<"The number/s that was/were chosen the least: "; //(e)(iii)
    int min=INT_MAX;
    for (j=1; j<101; j=j+1){ //traverse array
        if (arr[j]<min && arr[j]>0) //compares value in array to conditions needed to be 'lowest choice'
            min=arr[j]; //updates least choice variable
    } //end for loop
    
    for (j=1; j<101; j=j+1){ //traverse array
        if (arr[j]==min) //if the number of times the number is choosen is equal to the lowest frequency
            cout<<j<<","; //prints the number. Takes in consideration that there may be mutiple numbers that have the same frequency.
    } //end for loop
    
    cout<<endl<<endl<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl; //output footer
    cout<<"\t\t\t\t\t\t         END OF REPORT    "<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl<<endl<<endl;
    
    return 0;
    
} //end main


        
