#include <iostream>
#include <fstream>
using namespace std;

int isPerfect(int a) {
	int per, sum_fact;
	char Y, N;
	sum_fact=0;
	
	for(int i=1; i<a; i++){
		if (a % i == 0) 
			cout<<i<<endl;
			sum_fact=sum_fact+i;
	}
	return sum_fact;
}
	
bool isPrime(int b) {
	for(int i=2; i<=b/2; i++){
		if (b % i == 0) {
			return true;
		}
		else 
			return false;
	}
}

bool isPerfectSquare(int c) {
	int sqr;
	sqr=1;
	for(int i=1; i<=c/2; i++) {
		sqr=sqr*i;
		
	if (sqr==c) 
		return true;
	}
	return false;
}

bool isSphenic(int d) {
	char Y, N;
	if(d==30||d==42||d==66||d==70||d==78) {
		return true;
	}
	else 
		return false;
}

int binary(int e) {
	int arr[8];
	int div;
	while (e!=0) {
		for(int i=0; i<8; i++) {
			div=e%2;
			e=e/2;
			arr[i]=div;
		}
	}
	return arr[8];
}

int main () {
	ifstream in;
	
	in.open ("numbers.txt");
	if (!in.is_open()) {   
	cout << "File could not be opened";   
	return 0;  
	} 
	
	cout<<"Number\t"<<"Perfect? "<<"Prime?\t"<<"Perfect Square?\t"<<"Sphenic\t"<<"Binary Equiv."<<endl;
	cout<<"======\t"<<"======== "<<"======\t"<<"======= =======\t"<<"=======\t"<<"============="<<endl;
	
	int num, count;
	int sum_fact;
	int bin;
	int ten=0, twenty=0, thirty=0, forty=0, fifty=0, sixty=0, seventy=0, eighty=0, ninety=0, hundred=0;
	int valid, invalid, no_reveal;
	int numbers[100];
	count=0;
	valid=0;
	invalid=0;
	no_reveal=0;
	
	in>>num;
	
	while (num!=-1) {
		numbers[count]=num;
		count=count+1;
		in>>num;
	}
	
	for (int i=0; i<count; i++) {
	 	cout<<numbers[i]<<"\t";
	
		sum_fact=isPerfect((i));
		if (sum_fact==i) {
			cout<<"Y\t";
		}
		else {
		cout<<"N\t";
		}
		
		if (isPrime(i)) {
			cout<<"Y\t\t";
		}
			else {
				cout<<"N\t\t";
			}
	
		if (isPerfectSquare(i)) {
			cout<<"Y\t";
		}
			else {
				cout<<"N\t";
			}
	
		if (isSphenic(i)) {
			cout<<"Y\t";
		}
			else {
				cout<<"N\t";
			}
	
		bin=binary(i);
			cout<<bin<<endl;
	}
	
	cout<<endl;
	
	while (num!=-1) {
	if (num>1 && num<=100) {
		valid=valid+1;
	}
	
	if (num=0) {
		no_reveal=no_reveal+1;
	}
	
	if (num>0 && num<11) {
		ten=ten+1;
		
	}
	
	if (num>10 && num<21) {
		twenty=twenty+1;
	}
	
	if (num>20 && num<31) {
		thirty=thirty+1;
	}
	
	if (num>30 && num<41) {
		forty=forty+1;
	}
	
	if (num>40 && num<51) {
		fifty=fifty+1;
	}
	
	if (num>50 && num<61) {
		sixty=sixty+1;
	}
	
	if (num>60 && num<71) {
		seventy=seventy+1;
	}
	
	if (num>70 && num<81) {
		eighty=eighty+1;
	}
	
	if (num>80 && num<91) {
		ninety=ninety+1;
	}
	
	if (num>90 && num<101) {
		hundred=hundred+1;
	}
	num=num+1;
}
	
	
	cout<<"Range\t"<<"Histogram"<<endl;
	cout<<"================="<<endl;
	cout<<"1-10\t"<<ten<<endl;
	cout<<"11-20\t"<<twenty<<endl;
	cout<<"21-30\t"<<thirty<<endl;
	cout<<"31-40\t"<<forty<<endl;
	cout<<"41-50\t"<<fifty<<endl;
	cout<<"51-60\t"<<sixty<<endl;
	cout<<"61-70\t"<<seventy<<endl;
	cout<<"71-80\t"<<eighty<<endl;
	cout<<"81-90\t"<<ninety<<endl;
	cout<<"91-100\t"<<hundred<<endl;
	
	cout<<"The number of students with valid numbers were:"<<valid<<endl;
	cout<<"The number of students with invalid numbers were:"<<invalid<<endl;
	cout<<"The number of students who did not reveal their favourtie number:"<<no_reveal;
	return 0;
}
