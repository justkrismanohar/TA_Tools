#include <iostream>
#include<fstream>
#include<cmath>
using namespace std;

void perfect(int number){
	int sum=0;
	for(int i=1; i<=number/2;i++){
	
		if (number%i==0){
			sum=sum+i;
		}
}
	
if (sum==number)
	cout <<"Y";
	
else
cout << "N";	
	
}


void prime(int number){
		int sum=0;				//simply reusing code from previous function
	for(int i=1; i<=number/2;i++){
	
		if (number%i==0){
			sum=sum+i;
		}
}
if (sum==1) //if sum is 1, then 1 is the only proper divisor, meaning that the number is prime 
	cout<<"Y";
else
cout <<"N";	
	
	
	
	
}

void Psquare(int number){
	float root=sqrt(number);  // a number would be a perfect square if its square root is a whole number
	
	int base=floor(root);    // this can also be done with a for loop and checking the square of individual divisors
							// to determine if the number is a perfect square 
	
	if((root-base)==0)      
	cout <<"Y";
	
	else 
		cout <<"N";
	
	
	
	
	
}

void sphenic(int number){
	int count=0;
	int product=1;
	int sum=0;
 	for(int i=2; i<=number; i++){
	 
 		if ((number%i)==0){ // determining first if the number is a factor,
 							// then determining if its a prime factor
 			
 			 sum=0;                         // this is the same prime code
 			for(int k=1; k<=i/2;k++){
	
		if (i%k==0)
			sum=sum+k;
		}
			
 			if (sum==1)	{
			 
 			count=count+1;               //if it passes both checks, then 
 										// increment count, and multiply
 			product=product*i;
 		
		 }
	
}
}

 if ((count==3) && (product==number))     // by definition of sphenic
 cout <<"Y";
 
 else 
 cout <<"N";
	
	
	
	
	
	
}



void bin(int number){
	
	int rem=0;
	int array[8];
	int count=0;
	
	for(int i=0; i<8; i++)
	array[i]=0;
	
	
	while(number!=0){
	
	rem=number%2;
	if(rem==0)
		array[count]=0;
		
	else
	array[count]=1;
	
	
	
	number=number/2;
	
	
	count=count+1;
}
	
	
for(int i=7; i>=0; i--){
	cout <<array[i];
	
	
}	
	
	
}

void printstars(int num){
	for(int i=0; i<num; i++)
	cout <<"*";
	
	
}






int main(){
	ifstream fin;
	ofstream fout;
	fin.open("numbers.txt");
	
	
	int number;
	int invalidcount=0;
	int zerocount=0;
	
	
	
		cout <<"Number       Perfect?         Prime?     Perfect Sqaure        Sphenic          Binary ";
		cout <<endl;
		cout <<"---------------------------------------------------------------------------------------------------------------";
		cout <<endl;
	
	int distinct[101];
	for (int i=0; i<=100; i++){
		distinct[i]=0;
	}
	
		int invalid[56000];   //just some big number, i couldn't find an efficient way to print after, without using an array which i dont know the size of. i would have to read the file twice.
	for (int i=0; i<=56000; i++){
		invalid[i]=0;
	}
	
	fin >>number;
	while(number!=-1){
		if((number>=1) &&(number<=100)){
		
		
		
			if(distinct[number]==0){
		
		
		
			cout << number <<"\t";  cout <<"\t";
			perfect(number); cout <<"\t"; cout <<"\t";
			prime(number);   cout <<"\t"; cout <<"\t";
			Psquare(number);   cout <<"\t";  cout <<"\t";
			sphenic(number);  cout <<"\t"; cout <<"\t";
			bin(number);       cout <<"\t"; cout <<"\t";
			cout <<endl;
		
	
	}
	distinct[number]++;      
}
	else {
	
		invalid[invalidcount+1]=number;	//position 0 will be empty, just for formatting sake, 1st invalid number is at position 1 etc
		invalidcount++;			
}

if (number==0)
zerocount++;



		fin >>number;
		
		
	
		
	
	
}

cout <<endl <<"Invalid Numbers  " <<endl;
int i=1;
	if((invalid[i])!=0){	 
while((invalid[i])!=0){

cout <<invalid[i] << "     ";
	if ((i%5)==0)
	cout <<endl;
	
i++;
	
}
}	
	
cout <<endl <<endl;

int total=0;
cout<<"Range                      Histogram" <<endl 
	<< "-----------------------------------------------------" <<endl;
	
	for(int i=1; i<=100; i=i+10){
		total=0;
	
	cout <<i << "-" <<i+9;
	cout <<"\t                         ";
		for (int hold=i; hold<=i+9; hold++){
		
		
		total = total+distinct[hold];
}
	printstars(total/5);
	cout <<endl;
	

	
	
}


cout <<endl <<endl;
int valid=0;
for(i=1; i<=100; i++){
	valid= valid+distinct[i]; //recall that the array positions represent the actual number chosen in thsis case, therefore this sum would represent the total number of valid numbers and not the sum of the valid numbers 
		
}
cout <<"Valid number count  : " <<valid <<endl;
cout <<"Invalid number count : " <<invalidcount <<endl;
cout <<"Persons who did not reveal their favorite number: " <<zerocount <<endl;


cout <<endl;

int maxval=0;
int max=0;
int min=99999;
int minval=99999;

for(int i=1; i<=100; i++){
	if((distinct[i]>1)&&(distinct[i]>maxval)){
	
	maxval=distinct[i];
	max=i;
}

}

cout <<"The  number(s) most frequenly chosen is/are " <<max;

// i'm assuming this is valid numbers, if its invalid as well, then i'd have to put the most frequent valid numbers in an array and then compare instead of couting immediately
// its a bit hard because i won't be able to account for ties in this manner, and would have to go through both arrays.
for(int i=1; i<=100; i++){
	if((distinct[i]==maxval) && (i!=max))    // this accounts for ties, will display all numbers
	cout << ", " << i;

}




cout <<endl;



for(int i=1; i<=100; i++){
	if((distinct[i]>0)&&(distinct[i]<minval)){
	
	minval=distinct[i];
	min=i;
}
}
cout <<"The  number(s) least frequenly chosen is/are " <<min;


for(int i=1; i<=100; i++){
	if((distinct[i]==minval) && (i!=min))   
	cout << ", " << i;

}









	
	return 0;
}
