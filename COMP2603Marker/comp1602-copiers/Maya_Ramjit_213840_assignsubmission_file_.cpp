#include <iostream>
#include <fstream>
using namespace std;

char isPerfect(int number){           //function determining if a number is a perfect number
	int sum = 0;
	for(int i=1;i<=number/2;i++){     //since 1 and itself is not included in the sum of the proper divisors
		if (number% i==0){            //determining if it has proper divisors
			sum = sum + i;
		}
	}
	if (number==sum)
	return 'Y';
	return 'N';
}

char isPrime(int number){              //function determining if a number is a prime number
	if (number==1){						//since 1 is not considered a prime number
  		return 'N';
	  }
	for (int i=2; i<=number/2; i++){     //since all numbers including prime numbers have divisors of 1 and itself, i=1 and i=number is not tested 
		if(number% i==0)               //testing for other divisors
		return 'N';
	}
	return 'Y';		
}

char isPerfectSquare (int number){		//function determining if a number is a perfect square
	int square;
	for (int i=1; i<=number; i++){    //Since square numbers start at 1
	 	square= i*i;
	 		if (square==number)
	 		return 'Y';
	 }
	return 'N';	
}

char isSpenic (int number){   			       	//function determining if a number is a spenic number
	int i, count=0,prod=1;
	for (i=2; i<=number/2; i++){                 //checking the range for all possible proper divisors
		if((number%i==0)&&(isPrime(i))){			 //checking for a prime number within the divisors
			prod=prod*i; 
			count=count+1;						 //counting the amount ofprime divisors in the product
		}
	}
	if((count==3)&&(prod==number))
		return 'Y';
	else	
		return 'N';
}

void Binary(int number){
int bin[8], i=0, j=0;
for(j=0; j<8 ;j++){
	bin[j]=0;
}
while( number!=0 || i<7){
	bin[i]=number%2;
	number=number/2;
	i++;
}
for(j=7; j>=0 ;j=j-1){
	cout<<bin[j];
}
}	

int main(){
	int num, number;
	int norevealcount=0, validcount=0,invalidcount=0;
	char perfect, prime, perfectsq, sphenic, binary;
	
	//input file opening
	ifstream in;
	in.open("numbers.txt");
	if (!in.is_open()){
		cout<<"Error in locating the file";
		return 0;
	}
	
	//part a and ei)
	in>>num;
	while (num != -1){														
		if (num==0){									//counting how many students didn't reveal their favourite number'
			norevealcount=norevealcount+1;
		}
		else{
			if ((num>=1) && (num<=100)){				//counting how many students favourite number was a valid number (within the range 1 to 100)
				validcount=validcount+1;
			}
			else{
				invalidcount=invalidcount+1;			//counting how many students favourite number was invalid to the range 
			}
		}
	in>>num;	
	}
	
	//initializing arrays
	int i;
	int validnum[101];							//holds the valid numbers (1 to 100) and number, zero
			for(i=0;i<101;i++){
				validnum[i]=i;
			}
	int valid[101];								//holds the count for each valid number and zero 
			for(i=0;i<101;i++){
				valid[i]=0;
			}
	int invalid[invalidcount];					//holds all the invalid numbers
			for(i=0;i<invalidcount;i++){
				invalid[i]=0;
			}
	
	//closing and reopening the file to reread data		
	in.close();
	in.open("numbers.txt");
	
	//reading data into the array valid (which includes 0 for ease of calculations) and array invalid
	i=0;
	in>>num;
	while (num != -1){														
			if ((num>=0) && (num<=100)){				
				valid[num]=valid[num]+1;
			}
			else{
				invalid[i]=num;
				i++;			
			}
	in>>num;	
	}
	
	
//part b output	using the data from the valid and validnum arrays		
	cout<<"Num  Perfect?  Prime?  Perfect Square?  Sphenic?  Binary Equiv"<<endl;  //Table heading
	cout<<"===  ========  ======  ===============  =======   ============"<<endl;  //Table heading
	
	
	for(int i=1;i<101;i++){  				//starting at 1 because 0 is unrevealed favourite numbers
		if(valid[i]!=0){
			number=validnum[i];
				perfect=isPerfect(number);
				prime=isPrime(number);
				perfectsq=isPerfectSquare(number);
				sphenic=isSpenic(number);
		cout<<number<<'\t'<<perfect<<'\t'<<prime<<'\t'<<'\t'<<perfectsq<<'\t'<<sphenic<<'\t'<<'\t';
		Binary(number);
		cout<<endl;			
		}
	}

cout<<endl<<endl;
	
	//part c
	cout<<"All Invalid numbers entered are:"<<endl;
	for(i=0;i<invalidcount;i++){
		cout<<invalid[i]<<'\t';
		if ((i+1)% 5==0){
			cout<<endl;
		}
	}
	
cout<<endl<<endl;

//part d	
	int range[10]; 										//holds the total of each group
	for(i=0;i<10;i++){									//initializing range
		range[i]=0;
	}			
	int start=1;										
	int count=0;
	while (count<10){									//ensuring only the ten spaces in range is filled
		for (i=start;i<(start+10);i++){
			range[count]=range[count]+valid[i];			//adding the values that are within the range to the range array
	}
	count++;											//adding to couunt toincrease the range
	start=start+10;										//increasing the range within the valid array to the appropriate range
	}
cout<<endl;
cout<<"-------------------------------"<<endl;
		int c=11, b=20;
		cout<<"  Range "<<'\t'<<"    Histogram"<<endl; 		//Heading for the histogram table
 		cout<<"========="<<'\t'<<"    ========="<<endl;
 		cout<<" 1 To 10 "<<'\t'<<'\t';						//outputing 1 to 10 separately to that it lines up
 		for(i=1;i<=range[0];i++){							//for every 5 input, outputing a star
		 if(i%5==0){
		 cout<<"*";
		}
		}
		 cout<<endl;	
		for (int j=1;j<10;j=j+1){     					   	//outputing the groups
			cout<<c<<" To "<<b<<'\t'<<'\t';
					for(i=1;i<=range[j];i++){				//for every 5 input outputing a star
		 				if(i%5==0){
		 				cout<<"*";
						}
					}
					cout<<endl;
		c=c+10;
		b=b+10;	
		}
		cout<<"-------------------------------"<<endl;
cout<<endl<<endl;

//part ei)
cout<<"Number of students who favourite valid numbers: "<<validcount<<endl;
cout<<"Number of students who favourite invalid numbers: "<<invalidcount<<endl;
cout<<"Number of students who didn't reveal their favourite number: "<<norevealcount<<endl;
cout<<endl;

//part eii) 
int highest=valid[1];
cout<<"Highest non-zero valid number chosen: ";

for(int k=1;k<101;k++){						//getting the highest frequency  of a number (not the number itself) from the valid array
	if((valid[k]>=highest)&&(valid[k]>0)){	//has to be more than zero in the frequency because entries with zero in the valid array are numbers that were not entered in the file
	highest=valid[k];						
	}
}	
for(int k=1; k<101; k++){					//getting the number of numbers with the highest frequncey found above
	if(valid[k]==highest){
		cout<<validnum[k]<<'\t';
	}
}
cout<<endl<<endl;

//part eiii)
int lowest=highest;							//lowest taken as the highest which will guarantee that there are frequences lower than that value
cout<<"Lowest non-zero valid number chosen: ";

for(int l=1;l<101;l++){						//getting the lowest frequency of a number (not the number itself) from the valid array
	if((valid[l]<=lowest)&&(valid[l]>0)){	//frequencies of zero are not included because they are numbers that were not in by the file
	lowest=valid[l];						
	}
}	
for(int l=1; l<101; l++){					//getting the number of numbers with the lowest frequncey found above
	if(valid[l]==lowest){
		cout<<validnum[l]<<'\t';
	}
}
cout<<endl;
	in.close();
	return 0;
}

