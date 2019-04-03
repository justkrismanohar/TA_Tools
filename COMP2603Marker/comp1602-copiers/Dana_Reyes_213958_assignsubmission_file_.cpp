#include<iostream>
#include<fstream>
using namespace std;
bool isPerfect(int n){
	int i, sum=1;
	for(i=1; i<=n/2; i++){
		if(n%i==0)
		sum=sum+i;
	}
	if(sum==0)
	return true;
	else
	return false;
}

bool isPrime(int n){
	for(int i=2; i<=n/2; i++){
		if(n%i==0)
		return false;
	}
	return true;
}

bool isPerfectSquare(int n){
	for(int i=1; i<n/2; i++){
		if((i*i)==n)
		return true;
	}
	return false;
}

bool isSphenic(int n){
	int primefactors=0, product=1;
	
	for(int i=2; i<=n/2; i++){
		if(n%i==0){
			if(isPrime(i)=='Y'){
				primefactors=primefactors+1;
				product=product*i;
				if ((product==n) && (primefactors==3))
					return true;
			}
		}
	}
	return false;	
}

void binarynum(int n){
	int binArr[8];
	for(int i=0; i<8; i++)
	binArr[i]=0;
	int i=0, count;
	while(n!=0){
		binArr[i]=n%2;
		n=n/2;
		i++;
	}
	for(count=0; count<i; count++)
	cout<<binArr[count];
}

void printStars(int n){
	for(int i=1; i<=n/5; i++)
	cout<<"*";
}

int main(){
	ifstream in;
	in.open("numbers.txt");
	if(!in.is_open()){
		cout<<"File not found. Aborting..."<<endl;
		return 0;
	}
	
	int numbers[101];
	for(int j=0; j<101; j++){
		numbers[j]=0;
	}
	int n, valid=0, invalid=0, count0=0, c=1;
	int invalidnums[101];
	for(int i=0; i<101; i++)
	invalidnums[i]=0;
	in>>n;
	
	while(n!=-1){
		if( (n>0) && (n<101) ){
			valid=valid+1;
			
			for(int i=1; i<=100; i++){
				if(n==i)
				numbers[i]=numbers[i]+1;
			}
		}
		else{
			if(n==0)
			count0=count0+1;
			else{
			invalid=invalid+1;
			invalidnums[c]=n;
			}
		}
		in>>n;
		c++;	
	}
	
	cout<<"Number \t Perfect? \t Prime? \t Perfect Square? \t Sphenic? \t Binary Equiv."<<endl;
	cout<<"====== \t ======== \t ====== \t =============== \t ======== \t ============="<<endl;
	cout<<endl;
	
	bool perfect, prime, perfsq, sphenic;
	
	for(int i=1; i<=100; i++){
		if(numbers[i]!=0){
			perfect=isPerfect(i);
			prime=isPrime(i);
			perfsq=isPerfectSquare(i);
			sphenic=isSphenic(i);
			
			cout<<i<<" \t\t "<<perfect<<" \t\t "<<prime<<" \t\t "<<perfsq<<" \t\t "<<sphenic<<" \t\t ";
			binarynum(i);
			cout<<endl;
		}
	}
	
	cout<<"Invalid numbers: "<<endl;
	
	c=0;
	in>>n;
	while (invalidnums[c]!=0){
			cout<<invalidnums[c];
			if(c+1 % 5 == 0)
			cout<<endl;
		in>>n;
		c++;
	}
	in.close();
	
	int range[10];
	for(int i=0; i<10; i++){
		range[i]=0;
	}
	
	for(int i=1; i<=10; i++)
	range[0]=range[0]+numbers[i];
	
	for(int i=11; i<=20; i++)
	range[1]=range[1]+numbers[i];
	
	for(int i=21; i<=30; i++)
	range[2]=range[2]+numbers[i];
	
	for(int i=31; i<=40; i++)
	range[3]=range[3]+numbers[i];
	
	for(int i=41; i<=50; i++)
	range[4]=range[4]+numbers[i];
	
	for(int i=51; i<=60; i++)
	range[5]=range[5]+numbers[i];
	
	for(int i=61; i<=70; i++)
	range[6]=range[6]+numbers[i];
	
	for(int i=71; i<=80; i++)
	range[7]=range[7]+numbers[i];
	
	for(int i=81; i<=90; i++)
	range[8]=range[8]+numbers[i];
	
	for(int i=91; i<=100; i++)
	range[9]=range[9]+numbers[i];
	
	cout<<endl;
	
	cout<<"Range \t Histogram"<<endl;
	cout<<"=================="<<endl;
	cout<<endl;
	
	for(int i=1; i<=91; i=i+10){
		int n=range[i/10];
		cout<<i<<"-"<<i+9<<" \t :";
		printStars(n);
		cout<<endl;
	}
	
	cout<<endl;
	
	cout<<"Number of students who specified valid favourite numbers: "<<valid<<endl;
	cout<<"Number of students who specified invalid favourite numbers: "<<invalid<<endl;
	cout<<"Number of students who did not reveal their favourite number: "<<count0<<endl;
	
	int max=2, maxlocation, min=10000, minlocation;
	
	for(int i=1; i<101; i++){
		if((numbers[i]>max) && (numbers[i]!=0)){
			max=numbers[i];
			maxlocation=i;
		}
		if((numbers[i]<min) && (numbers[i]!=0)){
			min=numbers[i];
			minlocation=i;
		}
	}
	
	cout<<"Number/s chosen most by students: "<<endl;
	for(int i=1; i<101; i++){
		if(numbers[i]==max)
		   cout<<i<<endl;
	}
	
	cout<<"Number/s chosen least by students: "<<endl;
	for(int i=1; i<101; i++){
		if(numbers[i]==min)
		   cout<<i<<endl;
	}
	return 0;	
}
