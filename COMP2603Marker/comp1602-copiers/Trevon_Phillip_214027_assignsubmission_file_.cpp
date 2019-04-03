/* Trevon Phillip. 816017146. COMP 1602 Assignment 1. */

//Initialising Program
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Establishing Fucntion to Determine if Number is Perfect
bool Perfect (int num){
	int sum = 0;
	int i = 0;
	
	for (i = 1; i <= num/2; i = i + 1 ){
		if (num % i == 0){
			sum = sum + i;
		}
	}
	if (sum == num){
		return true;
	}
	return false;	
}

//Establishing Fucntion to Determine if Number is Prime
bool Prime (int num){
 int i = 0;
   for( i=2; i <= num / 2; i = i + 1) {
   	  if (num == 1){
   	  	 return false;
		 }
      if( num % i == 0) {
         return false;
      }
   }
   return true;
	}

//Establishing Fucntion to Determine if Number is a Perfect Square
bool PerfectSquare (int num){
	int i =0;
	
	for (i = 1; i <= num/2; i = i + 1 ){
		if (num == 1){
			return true;
		}
		if (i * i == num){
			return true;
		}
	}
	return false;
}

//Establishing Fucntion to Determine if Number is Sphenic
bool Sphenic (int num){
	int i = 0;
	int pqr = 0;
	int product = 1;
	for (i =2; i<= num/2; i = i + 1){
		if (num % i == 0 && Prime (i)){
			product = product * i;
			pqr = pqr + 1;
		}
	}
	if (pqr== 3 && product == num){
		return true;
	}
	return false;
}

//Establishing Fucntion to Determine the Binary Equivalent
void BinaryRep (int num){
int n = 0;
int i = 0;
int bits [8]= {0};

n = num;

for (i = 0; n>0; i= i +1){
	bits[i]= n % 2;
	n= n/2;
}
cout<<right<<setw(12)<<" ";
for (i=7; i>=0; i = i - 1){
	cout <<bits[i];
}
}

//Establishing Fucntion to Determine Histogram for Number Ranges
void Histogram (int minrange, int maxrange, int ValidA [], int valid){
	int i = 0;
	int count = 0;
	for (i=0; i<=valid; i = i +1){
		if ( ValidA[i] >= minrange && ValidA[i] <= maxrange){
			count = count +1;
			if (count % 5 == 0){
				cout<<"*";
			}
		}
		
	}
	cout<<endl; 
}

//Establishing Main Program
int main (){
	//Initialising Variables
	
	ifstream read;
	
	int num = 0;
	int i = 0;
	int x = 0;
	
	int choices   [9999]; 
	int ValidA    [9999];
	int InvalidA  [9999];
	int numbers   [100] = {0};
	
	int tableentry = 0;
	int nochoice = 0;
	int valid = 0;
	int invalid = 0;
	
	int mostvotes =0;
	int votes =0;
	int leastvotes =9999;
	
//Opening Files for Manipulation
read.open("numbers.txt");	

//Creating While Loop To Read Values from .txt File
read >> num;
while (num != -1){
	choices [i] = num;
	i = i + 1;
    read >>num;
}
// Determining Number of Valid, Invalid and Null Choices
for (x=0; x <= i - 1; x = x+1){
	if (choices[x] == 0){
		nochoice = nochoice + 1;
	}
	else if (choices[x] < 0 || choices [x] > 100){
		InvalidA[invalid] = choices [x];
		invalid = invalid + 1;
	}
	else if (choices[x] > 0 || choices [x] <= 100){
		ValidA[valid] = choices [x];
		valid = valid + 1;
	}
}

//Creating Table to Display Distinct Valid Numbers and Their States
cout <<left  << setw(11)<<" Number";
cout<<right  << setw(11)<<" Perfect?";
cout<<right  << setw(11)<<" Prime?";
cout<<right  << setw(21)<<" Perfect Square?";
cout<<right  << setw(14)<<" Sphenic?";
cout<<right  << setw(24)<<" Binary Equivalent "<<endl;
cout<<"============================================================================================"<<endl;


for (i = 0; i<valid; i= i + 1){
	tableentry = ValidA[i];
	if ( numbers[tableentry - 1] == 0){
		numbers[tableentry - 1] = numbers[tableentry - 1] + 1;
		cout <<left  << setw(11)<<tableentry;
		//Calling Perfect Function for Determined Value
       if (Perfect(tableentry)== 0){
       	cout<<right  << setw(11)<<"N";
	   }
	   else{
	   	cout<<right  << setw(11)<<"Y";
	   }
	   //Calling Prime Function for Determined Value
	   if (Prime(tableentry)==0){	
	   cout<<right  << setw(11)<<"N";
	   }
	   else{
	   	cout<<right  << setw(11)<<"Y";
	   }
	   //Calling PerfectSquare Function for Determined Value
	   if (PerfectSquare(tableentry)==0){
	   		cout<<right  << setw(18)<<"N";
	   }
	   else{
	   	cout<<right  << setw(18)<<"Y";
	   }
	   //Calling Sphenic Function for Determined Value
	   if (Sphenic(tableentry)==0){
	   		cout<<right  << setw(15)<<"N";
	   }
	   else{
	   	cout<<right  << setw(15)<<"Y";
	   }
	   //Calling Binary Function to Convert to Binary
	  	BinaryRep(tableentry);
	  cout<<endl;
		}
	else
	{	
	  numbers[tableentry - 1] = numbers[tableentry - 1] + 1;
	  }	

}

//Creating Invalid Numbers List
cout<<endl;
cout<<"Invalid Numbers List :"<<endl;
for (x=1; x <= invalid; x = x+1){
	if (x % 5 == 0){
	cout<<InvalidA[x-1]<<endl;
}
else{
    cout<<InvalidA[x-1]<<" ";
}
}
cout<<endl<<endl;

//Creating Range Histogram Table
cout <<left  << setw(11)<<" Range ";
cout<<right  << setw(11)<<" Histogram"<<endl;
cout<<"======================="<<endl;
//Calling Histogram Function for Each Range
cout <<left  << setw(15)<<" 1 - 10 ";
Histogram (1,10,ValidA,valid);
cout <<left  << setw(15)<<" 11 - 20";
Histogram (11,20,ValidA,valid);
cout <<left  << setw(15)<<" 21 - 30 ";
Histogram (21,30,ValidA,valid);
cout <<left  << setw(15)<<" 31 - 40 ";
Histogram (31,40,ValidA,valid);
cout <<left  << setw(15)<<" 41 - 50 ";
Histogram (41,50,ValidA,valid);
cout <<left  << setw(15)<<" 51 - 60 ";
Histogram (51,60,ValidA,valid);
cout <<left  << setw(15)<<" 61 - 70 ";
Histogram (61,70,ValidA,valid);
cout <<left  << setw(15)<<" 71 - 80 ";
Histogram (71,80,ValidA,valid);
cout <<left  << setw(15)<<" 81 - 90 ";
Histogram (81,90,ValidA,valid);
cout <<left  << setw(15)<<" 91 - 100 ";
Histogram (91,100,ValidA,valid);


//Creating Loop to Determine Most Voted Number
for (i=0; i<100; i = i+1){
	if (numbers[i] > votes){
		votes=numbers[i];
		mostvotes = i + 1;
	}
}
//Creating Loop to Determine Least Voted Number
for (i=0; i<=100; i = i+1){
	if (numbers[i] < leastvotes && numbers[i] != 0){
		leastvotes = i +1;
	}
}


//Output for Part E
cout<<endl<<endl;
cout<<"Students Who Did Not Choose : "<<nochoice<<endl;
cout<<"Valid Choices : "<<valid<<endl;
cout<<"Invalid Choices : "<<invalid<<endl;
cout<<"Most Voted Number : ";
for (i=0; i<100; i = i+1){
	if (numbers[i] == votes){
		cout<<i+1<<" ";
	}
}
cout<<endl<<"Least Voted Number : ";
for (i=0; i<100; i = i+1){
	if (numbers[i] == leastvotes){
		cout<<i+1<<" ";
	}
}

//Closing Files
read.close();
//Terminating Program
return 0;

}
