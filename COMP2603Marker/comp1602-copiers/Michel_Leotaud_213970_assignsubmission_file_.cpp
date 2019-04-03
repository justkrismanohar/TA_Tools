#include <iostream>
#include <fstream>
using namespace std;

	bool isPerfect(int n){
		int sum=0;
		
		for(int i=1; i<=n/2; i=i+1){
			
			if(n%i==0)
			sum=sum+i;
		}
		if(sum==n){
			cout<<"Y";
			return true;
		}
		else{
			cout<<"N";
			return false;
		}
	}
	
	bool isPrime(int n){
		for(int i=2; i<=n/2; i=i+1){
			
			if(n%i==0){
				cout<<"N";
				return false;
			}
		}
		cout<<"Y";
		return true;
	}	
	
	bool isPsquare(int n){
		int sum;
		
		for(int i=1; i=n/2; i=i+1){
			sum=i*i;
			
			if(sum==n){
				cout<<"Y";
				return true;
			}
		}
		cout<<"N";
		return false;
	}

//	bool isSphenic(int n){
//	int p=0, q=0, r=0;
//	int sphenic, prime, temp;
	
//		for(int i=2; i=n/2; i=i+1){
//		if(isPrime(i)){
//			prime=i;
//			}
		
//	}


int main(){
	
	ifstream inFile;
	inFile.open("numbers.txt");
	
	if(!inFile.is_open()){
		cout<<"Error opening file. Aborting.."<<endl;
		return 0;
	}
	
	int allNumbers[200];
	int num, binary;
	int numValid[123];
	int numInvalid[123];
	int w=0; // for all numbers
	int i=0; // for all valid numbers
	int j=0; // for all INVALID numbers
	char perfect, prime, perfectS, sphenic;
	
	inFile>>num;
	
	while(num!=-1){
			
			allNumbers[w]=num;
			w++;
			
			if(num>0 && num<101){
			numValid[i]=num;
			i=i+1;
			}
			
			else{
			numInvalid[j]=num;
			j++;
			}	
			
	inFile>>num;			
	}
	
	cout<<"Number"<<"\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equiv."<<endl;
	cout<<"======"<<"\t"<<"========"<<"\t"<<"======"<<"\t"<<"==============="<<"\t"<<"========"<<"\t"<<"============="<<endl;
	
	int index=0;
		
	while(index<=i){ 
				
	cout<<numValid[index]<<"\t";
	isPerfect(numValid[index]);
	cout<<"\t \t";
	isPrime(numValid[index]);
	cout<<"\t \t";
	isPsquare(numValid[index]);
	cout<<"\t \t";
	
	cout<<endl;
	
	
/*	if( isPerfect(numValid[index]) )
			perfect='Y';
		else
			perfect='N';
	

	if( isPrime(numValid[index]) )
			prime='Y';
		else
			prime='N';
	
	if( isPsquare(numValid[index]) )
			perfectS='Y';
		else
			perfectS='N';

	cout<<numValid[index]<<"\t"<<perfect<<"\t \t"<<prime<<"\t \t"<<perfectS<<"\t \t";
				
*/
	
	index++;		
	}
cout<<endl<<endl;
cout<<j<<endl<<endl;

cout<<"Part C - The invalid numbers are:"<<endl;
for(int index2=0; index2<=j; index2++){
	for(int m=0; m<5; m++){
		cout<<numInvalid[index2]<<" ";
		if(m<4)
		index2++;
		
		if(index2>j)
		break;
	}
cout<<endl;
}

int range1=0;
int range2=0;
int range3=0;
int range4=0;
int range5=0;
int range6=0;
int range7=0;
int range8=0;
int range9=0;
int range10=0;

cout<<"Range"<<"\t"<<"Histogram"<<endl;
cout<<"================================"<<endl;

	for(int index2=0; index2<=i; index2++){
	
	if(numValid[index]>=1 && numValid[index]<=10){
		range1++;
	}
	if(numValid[index]>=11 && numValid[index]<=20){
		range2++;
	}
	if(numValid[index]>=21 && numValid[index]<=30){
		range3++;
	}
	if(numValid[index]>=31 && numValid[index]<=40){
		range4++;
	}
	if(numValid[index]>=41 && numValid[index]<=50){
		range5++;
	}
	if(numValid[index]>=51 && numValid[index]<=60){
		range6++;
	}
	if(numValid[index]>=61 && numValid[index]<=70){
		range7++;
	}
	if(numValid[index]>=71 && numValid[index]<=90){
		range8++;
	}
	if(numValid[index]>=81 && numValid[index]<=90){
		range9++;
	}
	if(numValid[index]>=91 && numValid[index]<=100){
		range10++;
	}
	
}

cout<<"1-10 \t"<<range1/5<<endl;

cout<<"11-20 \t"<<range2/5<<endl;
cout<<"21-30 \t"<<range3/5<<endl;
cout<<"31-40 \t"<<range4/5<<endl;
cout<<"41-50 \t"<<range5/5<<endl;
cout<<"51-60 \t"<<range6/5<<endl;
cout<<"61-70 \t"<<range7/5<<endl;
cout<<"71-80 \t"<<range8/5<<endl;
cout<<"81-90 \t"<<range9/5<<endl;
cout<<"91-100 \t"<<range10/5<<endl;


}
