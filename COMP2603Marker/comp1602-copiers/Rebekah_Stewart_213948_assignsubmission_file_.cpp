#include <iostream>
#include <fstream>
using namespace std;
/*int isMost
*/		
char perfect(int n){
	char per;
	int sum=0;
	for(int i=1;i<=n/2;i++){// the numbers are less than the number itself 
		if(n%i==0){
			sum=sum+i;		
		}
		if(sum==n){
			per='Y';
		}
		else{
			per='N';
		}	
	}
	return per;
}

char isPrime(int n){
	int i;
	char pri;
	if(i%n==0){
		pri='Y';
	}
	else{
		 pri='N';
	}
	return pri;
}

bool isPerSq(int n){//this only getting N.
	int i;
	for(i=1;i<=n;i++){
		if(i*i==n)
			return true;		
	}
	return false;
}

bool isSphenic(int n){
	int prod=1,count=0,i;
	bool k;
	for(i=2;i<=n/2;i++){
		k=isPrime(i);
		if((k==true)&&(n%i==0)){
			prod=prod*i;
			count++;
		}
	}
	if(count==3)
		return true;
	return false;
	
}
void star(int n){
	int i;
	if(i%5==n){
		cout<<"*"<<endl;
	}
}	


void binary(int n){
	int i,div,mod,b[8];
	for(i=7;i>=0;i--){//first loop to extract the remainders and store them in an array.
		b[i]=n%2;
		div=n/2;
		n=div;
	}
		for(i=0;i<8;i++){ //second for loop to flip the bits 
		cout<<b[i];	
	} 	
}

	
int main (){
	ifstream in;
	char sph;
	in.open("numbers.txt");
	if(in.is_open()==false){
	cout<<"File is not opening. Aborting command.";
	return 0;
	}
	int n;
	int valid=0,invalid_counter=0,noReveal=0;
	int invalid[100];
	int arr[100];
	
	int b;
	char j;
	int i;
	int y=1;
	int x=10;
	bool key;
	bool pSq;
	char per;
	int count,most=-1;
	int range_counter[100], range0=0,range1=0,range2=0,range3=0,range4=0,range5=0,range6=0,range7=0,range8=0,range9=0;
	int counter1=0, counter2=0,counter3=0,counter4=0,counter5=0,counter6=0,counter7=0,counter8=0,counter9=0,counter10=0;
	cout<<"-----------------------------------------------------------------------"<<endl;
	cout<<"Number\tPerfect?\tPrime?\tPerfect Square\tSphenic?\tBinary"<<endl;
	cout<<"-----------------------------------------------------------------------"<<endl;
	in>>n;
	for (i = 0; i<100; i++){
		range_counter[i] = 0;
		invalid[i]= 0;
	}
	while(n!=-1){	
		if((n>=1)&&(n<100)){
			valid++;
		
			pSq=isPerSq(n);
			if(pSq){
				per='Y';
			}
			else{
				per='N';
			}
			key=isSphenic(n);
			if(key){
				sph='Y';
			}
			else{
				sph='N';
			}
			
			cout<<n<<"\t"<<perfect(n)<<"\t\t"<<isPrime(n)<<"\t\t"<<per<<"\t  "<<sph<<"\t\t";
			binary(n);
			cout<<endl;
			int a=n+1;	
			if(n==a){
				cout<<endl;
			}
		
			if((n>=1)&&(n<=10)){
				range0++;
			
			}
			if((n>=11)&&(n<=20)){
				range1++;
				
			}
			if((n>=21)&&(n<=30)){
				range2++;
			}
			if((n>=31)&&(n<=40)){
				range3++;
			}
			if((n>=41)&&(n<=50)){
				range4++;
			}
			if((n>=51)&&(n<=60)){
				range5++;
			}
			if((n>=61)&&(n<=70)){
				range6++;
			}	
			if((n>=71)&&(n<=80)){
				range7++;
			}
			if((n>=81)&&(n<=90)){
				range8++;
			}	
			if((n>=91)&&(n<=100)){
				range9++;
			}
			int count;
			for(i=0;i<=100;i++){
				count=0;
				for(j=0;j<=100;j++){
					if(arr[i]==arr[j])
					count++;
				}
				if(count>most){
					most=count;
					most=arr[i];
				}
			}//I tried i dont know what to so beyond this :(
			
		}
	
		
		if((n<0)||(n>100)){
			invalid[invalid_counter]=n;//
			invalid_counter++;
		}
			
			if(n==0){
				noReveal++;//counter for those who did not reveal their favorite number
			}
			
		
		in>>n;
	}
	cout<<"--------------------------------------------------------"<<endl<<endl;
	cout<<"All the invalid numbers: "<<endl;
		for(i=0;i<invalid_counter;i++){
		cout<<invalid[i]<<" ";
			if(i%5==4){//prints 5 numbers per line
				cout<<endl;
			}
		}
	cout<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"Range\t\tHistogram"<<endl;
	cout<<"-----------------------------------------"<<endl;
		
		cout<<"1-10	:";//range 1
		for(int i=1;i<=range0;i++){
			if(i%5==0){
				counter1++;}
		}
			for(int j=1;j<=counter1;j++){
				cout<<"*";
				if(j%5==0){
					cout<<endl;
			}
		}
		cout<<endl;
		
		cout<<"11-20	:";//range 2
		for(int i=1;i<=range1;i++){
			
			if(i%5==0){
				counter2++;}
		}
			for(int j=1;j<=counter2;j++){
				cout<<"*";
				if(j%5==0){
					cout<<endl;
			}
		}
		cout<<endl;
		
		cout<<"21-30	:";//range3
		for(int i=1;i<=range2;i++){
			
			if(i%5==0){
				counter3++;
			}
		}
			for(int j=1;j<=counter3;j++){
				cout<<"*";
				if(j%5==0){
					cout<<endl;
			}
		}
		cout<<endl;
		
		cout<<"31-40	:";//range 4
		for(int i=1;i<=range3;i++){
			
			if(i%5==0){
				counter4++;}
			}
			for(int j=1;j<=counter4;j++){
				cout<<"*";
				if(j%5==0){
					cout<<endl;
				}	
			}
			cout<<endl;
		
		cout<<"41-50	:";
		for(int i=1;i<=range4;i++){
		
			if(i%5==0){
				counter5++;}
		}
			for(int j=1;j<=counter5;j++){
				cout<<"*";
				if(j%5==0){
					cout<<endl;
			}
		}
		cout<<endl;
		
		cout<<"51-60	:";
		for(int i=1;i<=range5;i++){
			if(i%5==0){
				counter6++;}
		}
			for(int j=1;j<=counter6;j++){
				cout<<"*";
				if(j%5==0){
					cout<<endl;
			}
		}
		cout<<endl;
		
		cout<<"61-70	:";
		for(int i=1;i<=range6;i++){
			if(i%5==0){
				counter7++;}
		}
			for(int j=1;j<=counter7;j++){
				cout<<"*";
				if(j%5==0){
					cout<<endl;
			}
		}
		cout<<endl;
		
		cout<<"1-80	:";
		for(int i=1;i<=range7;i++){
			if(i%5==0){
				counter8++;}
		}
			for(int j=1;j<=counter8;j++){
				cout<<"*";
				if(j%5==0){
					cout<<endl;
			}
		}
		cout<<endl;
		
		cout<<"81-90	:";
		for(int i=1;i<=range8;i++){
			if(i%5==0){
				counter9++;}
		}
			for(int j=1;j<=counter9;j++){
				cout<<"*";
				if(j%5==0){
					cout<<endl;	
			}
		}
		cout<<endl;
		
		cout<<"91-100	:";
		for(int i=1;i<=range9;i++){
			if(i%5==0){
				counter10++;}
		}
			for(int j=1;j<=counter10;j++){
				cout<<"*";
				if(j%5==0){
					cout<<endl;
			}
		}
		cout<<endl;
	cout<<endl;
	cout<<"Amount of valid numbers: "<<valid<<endl;
	cout<<"Amount of invalid numbers: "<<invalid_counter<<endl;
	cout<<"No reveal: "<<noReveal<<endl;
	cout<<most<<" ";
	in.close();
	return 0;
}
