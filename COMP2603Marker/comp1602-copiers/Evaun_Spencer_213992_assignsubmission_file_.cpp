#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

char isPerfect (int num) {
	int div;
	int sum = 0;
	char per;
	
	for (int i = 1; i < num; i++) {
        div = num % i;
	if (div == 0)
     	sum = sum + i;
   	}
    
   		if (sum == num)
        	return 'Y';
    	else
    	    return 'N';   
} 

char isPrime (int num) {
	int div;
	int sum = 0;
	
	for (int i = 1; i <= num; i++) {
   	   	if ((num%i) == 0){
    		sum = sum + 1;
    	}
	}
	
	if (sum == 2)
		return 'Y';
	else
		return 'N';
}

void BinaryNumber (int num) {
	int a[10]; 
	int i;
	  
	for (i=0; num>0; i++) {    
	a[i] = num%2;
	num = num/2;  
	}
	for (i=i-1; i>=0; i--) {    
	cout<<a[i];  
	}
}

char perfectSquare (int num) {
    int sqr = 0;
	
	for(int i=1 ; sqr >= num; i++)
    	sqr = i*i;
    	
	if (sqr == num) 
     	return 'Y';
	else
		return 'N';
}

char isSphenic (int num) {
	
	
}


int main () {
	
//Declaring streams
ifstream inputFile;

//Declaring variables
int favNum, i;
char per, ans;
int invalid [50], in = 0, v = 0, ds = 0;
int cul1 = 0, cul2 = 0, cul3 = 0, cul4 = 0, cul5 = 0, cul6 = 0, cul7 = 0 , cul8 = 0, cul9 = 0, cul10 = 0;

//Initializing array to zero
for (i=0; i<50; i++) {
	invalid	[i] = 0;
}
	



//To open input file
inputFile.open("numbers.txt");
if (inputFile.is_open() == false) {
	cout << "Error opening input file. Aborting ...";
	return 0;
}

//To print to table header
cout << "Number" << "     " << "Perfect" << "     " << "Prime" << "     " << "Perfect Square?" << "     " << "Sphenic" << "     " << "Binary Eqiv" << endl;
cout << "======" << "     " << "=======" << "     " << "=====" << "     " << "===============" << "     " << "=======" << "     " << "===========" << endl;

//While loop for table
inputFile >> favNum;
while (favNum != -1){
	
if ((favNum > 0) && (favNum < 101)) {
	
	
	cout << favNum << "            " << isPerfect (favNum) << "         " << isPrime (favNum) << "          " << perfectSquare (favNum) << "                  " 
	<< isSphenic (favNum) << "           ";
	BinaryNumber (favNum);
	cout << "\n";
}

if ((favNum > 0) && (favNum < 11))
	cul1 = cul1 + 1;	
if ((favNum > 10) && (favNum < 21))
	cul2 = cul2 + 1;
if ((favNum > 20) && (favNum < 31))
	cul3 = cul3 + 1;
if ((favNum > 30) && (favNum < 41))
	cul4 = cul4 + 1;
if ((favNum > 40) && (favNum < 51))
	cul5 = cul5 + 1;
if ((favNum > 50) && (favNum < 61))
	cul6 = cul6 + 1;
if ((favNum > 60) && (favNum < 71))
	cul7 = cul7 + 1;
if ((favNum > 70) && (favNum < 81))
	cul8 = cul8 + 1;
if ((favNum > 80) && (favNum < 91))
	cul9 = cul9 + 1;	
if ((favNum > 90) && (favNum < 101))
	cul10 = cul10 + 1;

if ((favNum < 1) || (favNum > 100)) {
	invalid [in] = favNum;
	in = in+1;
}
if ((favNum > 0) && (favNum < 101))
	v = v+1;
if (favNum == 0)
	ds = ds+1;

inputFile >> favNum;
}

//Valid vs invalid numbers
cout << "\n\n";
cout << "Invalid Numbers:" << endl;
for (i=0; i<=in; i = i + 5) {
	cout << invalid [i] << "     " << invalid [i+1] << "     " 
	<< invalid [i+2] << "     " << invalid [i+3] <<  "     " << invalid [i+4] << endl;
}

// Histogram
cout << "\n\n";
cout << "Range" << "       " << "Histogram" << endl;
cout << "=====" << "       " << "=========" << endl;
	
cout << "01 - 10" << "     ";
for (i=0; i<cul1; i=i+5) {
	cout << "*";
}
cout << endl;

cout << "11 - 20" << "     ";
for (i=0; i<cul2; i=i+5) {
	cout << "*";
}
cout << endl;


cout << "21 - 30" << "     ";
for (i=0; i<cul3; i=i+5) {
	cout << "*";
}
cout << endl;

cout << "31 - 40" << "     ";
for (i=0; i<cul4; i=i+5) {
	cout << "*";
}
cout << endl;

cout << "41 - 50" << "     ";
for (i=0; i<cul5; i=i+5) {
	cout << "*";
}
cout << endl;

cout << "51 - 60" << "     ";
for (i=0; i<cul6; i=i+5) {
	cout << "*";
}
cout << endl;

cout << "61 - 70" << "     ";
for (i=0; i<cul7; i=i+5) {
	cout << "*";
}
cout << endl;

cout << "71 - 80" << "     ";
for (i=0; i<cul8; i=i+5) {
	cout << "*";
}
cout << endl;

cout << "81 - 90" << "     ";
for (i=0; i<cul9; i=i+5) {
	cout << "*";
}
cout << endl;

cout << "91 - 100" << "    ";
for (i=0; i<cul10; i=i+5) {
	cout << "*";
}
cout << endl;


//Valid, invalid and did not specify
cout << "\n\n";
cout << "Valid: " << v << endl;
cout << "Invalid: " << in << endl;
cout << "Did not specify: " << ds << endl;


inputFile.close();
	
return 0;
}
