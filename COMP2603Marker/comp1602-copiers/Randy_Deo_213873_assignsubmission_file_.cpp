#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// PART B1, PERFECT NUMBER FUNCTION
bool isPerfect (int num) {
	
	int n=num, i=1, total=0;
	bool perfect;
	
	for (n=num; i<n; i++){	
		
		if (n%i==0) {
			total=total+i;
		}
		
	if (total==num){
		perfect = true;
		}
		
		else {
			perfect = false;
		}
}

return perfect;

}

// PART B2, PRIME NUMBER FUNCTION
bool isPrime (int num){
	
	int n=num, i=2;
	bool prime=true;
	
		if (n==0 || n==1){
			prime = false;
		}
			
	for (n=num; i<n; i++){
		
		if (n%i==0){
			prime = false;
		}

}
		
return prime;
		
}

// PART B3, PERFECT SQUARE NUMBER FUNCTION
bool isPerfSq (int num) {
	
	int n=num, sq=1, i=1;
	bool square=false;
	
	for (i=1; i<=num; i++){
	
		sq = i * i;
			if (sq==n){
				square = true;
			}
	}
	
return square;

}

//PART B4, SPHENIC NUMBER FUNCTION
bool isSphenic (int num){
	int n=num, i=2, count=0, prod=1, half=n/2;
	bool sphenic;
	
	for (i=2; i<=half; i++){
		
		if (n%i==0 && isPrime(i)){
			prod= prod*i;
			count= count+1;
		}
}
	
		if (count==3 && prod==n){
			sphenic = true;
		}
		
		else{
			sphenic = false;
		}
		
return sphenic;
	
}

//PART B5, BINARY NUMBER FUNCTION
int binaryRep (int num){
	
	int n=num, i, bits[9]={0};
	
	//for (i=0; i<=7; i++){
	
		//bits[i]=0;

	//}	
	
	for (i=0; n>0; i++){
		
		bits[i]=n%2;
		n= n/2;
			
	}
	
	for (i=8; i>=1; i--){
		cout << bits[i];
	}
	
return 0;	

}

int main () {
	
// Variables
ifstream Input;
int leastNum[100]={0};
int num, numArr[100]={0}, i, perfect, prime, perfSq, sphenic, binary, count;
int valid=0, invalid=0, invalidNum[100]={0}, inCount;
int zero=0;
int Histogram[10]={0}, rangeI, stars, div;

	
	Input.open("numbers.txt");
	 
	 if (!Input.is_open()){
	 	cout <<"===============================";
	 	cout <<"|    Error: File not found    |";
	 	cout <<"===============================";
	 	return 0;
     } 



cout << "Number\t    Perfect?\t     Prime?\t Perfect Square?    Sphenic?\t    Binary Equiv." << endl;
cout << "======\t    ========\t     ======\t ===============    ========\t     =============" << endl;

Input >> num;

	while (num!=-1){
		
//ZERO CHECKS		
		if (num==0){
		zero++;
	}
	
//HISTOGRAM CHECKS	
		if(num>=1 && num<=10){
		Histogram[1]=Histogram[1]+1;
	}
	
	if(num>=11 && num<=20){
		Histogram[2]=Histogram[2]+1;
	}
	
	if(num>=21 && num<=30){
		Histogram[3]=Histogram[3]+1;
	}
	
	if(num>=31 && num<40){
		Histogram[4]=Histogram[4]+1;
	}
	if(num>=41 && num<50){
		Histogram[5]=Histogram[5]+1;
	}
	
	if(num>=51 && num<60){
		Histogram[6]=Histogram[6]+1;
	}
	
	if(num>=60 && num<70){
		Histogram[7]=Histogram[7]+1;
	}
	
	if(num>=71 && num<80){
		Histogram[8]=Histogram[8]+1;
	}
	
	if(num>=81 && num<90){
		Histogram[9]=Histogram[9]+1;
	}
	
	if(num>=91 && num<100){
		Histogram[10]=Histogram[10]+1;
	}
	
//VALID CHECKS		
		if (num >=1 && num <=100){
			
			valid++;
			
			numArr[num]=numArr[num]+1;
			
		if (numArr[num]==1){
			
			cout << num << "\t\t";
			
//B) PERFECT NUMBER
			perfect = isPerfect(num);
			if (perfect==1){
				cout << "Y\t\t";
			}
				else {
					cout << "N\t\t";
				}
			
//PRIME NUMBER
			prime = isPrime(num);
			if (prime==1){
				cout << "Y\t\t";
			}
				else {
					cout << "N\t\t";
				}
			
//PERFECT SQUARE	
			perfSq = isPerfSq(num);
			if (perfSq==1){
				cout << "Y\t\t";
			}
				else {
					cout << "N\t\t";
				}
			
//SPHENIC NUMBER
			sphenic = isSphenic(num);
			if (sphenic==1){
				cout << "Y\t\t";
			}
				else {
					cout << "N\t\t";
				}
			
//BINARY CONVERSION 8 BIT
			binary = binaryRep(num);
			cout << endl;
		}
	}
	 
			if (num<=-1 || num>=101){
				invalidNum[invalid]= num;
				invalid++;				
			}

		Input >> num;
			
	}
	
//C) INVALID NUMBERS
			cout << endl;
			cout << "========================" << endl;
			cout << "    INVALID NUMBERS     " << endl;
			cout << "========================" << endl;
			cout << endl;
			
		inCount=0;
		for (i=0;i<=invalid-1;i++){
			cout << invalidNum[i] << "  ";
			inCount++;
				if (inCount==5){
					cout << endl;
					inCount=0;
				}
		}
		
		cout << endl;
		
//D) HISTOGRAM	

		cout << endl;
		cout << "================================" << endl;
		cout << "Range               Histogram   " << endl;
		cout << "================================" << endl;	
		
		rangeI=0;
		
		for (i=1;i<=10;i++){
			
			rangeI=rangeI+1;
			cout << rangeI << " - ";
			rangeI=rangeI+9;
			cout << rangeI << "   \t |";
			
			div=Histogram[i]/5; 
				if (div>=1){
					for (stars=1;stars<=div;stars++){
						cout << "*";	
					}
					cout<< endl;
				}
				else {
					cout<< endl;
				}
		}
			
		
//E) STATISTICAL INFORMATION

		cout << endl;
		cout << "================================" << endl;
		cout << "    STATISTICAL INFORMATION     " << endl;
		cout << "================================" << endl;
		cout << endl;
				
		cout << "1) Students who gave Valid Favorite numbers: " << valid << endl;
		cout << "2) Students who gave Invalid Favorite numbers:  " << invalid << endl;
		cout << "3) Students who did not reveal their Favorite number: " << zero << endl;
		
rangeI=2;

		for (i=0;i<=100;i++){
			
			if (numArr[i]>=rangeI){
				rangeI=numArr[i];
				inCount=i;
			}
		}
		
		cout << "4) The number that was chosen the most is: " << inCount << endl;
		
rangeI=0;		
		for (i=0;i<=100;i++){
			if (numArr[i]==1){
				leastNum[i] = i;
				rangeI++;	
			}
		}
		
//LEAST AMOUNT OF NUMBERS

		cout << endl;
		cout << "5) The numbers that were chosen the least are: " << endl;	
		inCount=0;
		for (i=0;i<=100;i++){
			if (!leastNum[i]==0){
				
			cout << leastNum[i] << "\t";
			inCount++;
			
				if (inCount==5){
					cout << endl;
					inCount=0;
				}
		}
	}	
		cout << endl;
		cout << "============================================" << endl;
		
	return 0;
}
