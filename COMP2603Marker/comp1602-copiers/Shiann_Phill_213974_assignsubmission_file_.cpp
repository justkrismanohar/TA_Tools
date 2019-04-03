#include <iostream>
#include <fstream>
using namespace std;

char isPerfect(int n){
	int sum=0;
	int i;
	for(i=1;i<=n/2;i=i+1){
		if(n%i==0)
		sum=sum+i;
	}
	if(sum==n)
	return 'Y';
	else
	return 'N';
}

char isPrime(int n){
	int count=0;
	int i;
	for(i=2;i<=n/2;i=i+1){
		if(n%i==0)
		count=count+1;
	}
	if(count==0)
	return 'Y';
	else
	return 'N';
}

char isPerfectSquare(int n){
	int sq;
	int i;
	for(i=1;i<=n/2;i=i+1){
		sq=i*i;
		if(sq==n)
		return 'Y';
		else
		return 'N';
	}
}

char isSphenic(int n){
	int i;
	int count=0;
	int product=1;
	for(i=2;i<=n/2;i=i+1){
		if((n%i==0) && (isPrime(i))){
			product=product*i;
			count=count+1;
		}
	}
	if((count==3) && (product==n))
	return 'Y';
	else
	return 'N';
}

int Binary(int n){
	int bin;
	while(n>0){
		bin=n%2;
		return bin;
		n=n/2;
	}
	
}

int countArray(int array[],int size,int n){
	int i;
	int count=0;
	for(i=0;i<size;i=i+1){
		if(array[i]==n)
		count=count+1;	
	}
	return count;
}


int main () {
	ifstream inputfile;
	int array[1000];
	int i=0;
	int n;
	int count=0;
	int czero=0;
	char perfect,prime,perfectsq,sphenic;
	int countn;
	int max=2;
	int min=999;
	int maxNum,minNum;
	int j,k;
	int ran_ge=1;
	int range[];
	int numStars;
	
	inputfile.open("numbers.txt");
	if(!inputfile.is_open()) {
		cout<<"Error in opening inputfile. Aborting...";
		return 0;
	}
	inputfile>>n;
	cout<<"Number"<<"\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equiv."<<endl;
	cout<<"------"<<"\t"<<"--------"<<"\t"<<"------"<<"\t"<<"---------------"<<"\t"<<"--------"<<"\t"<<"-------------"<<endl;
	while(n!=-1) {
		array[i]=n;
		if((array[i]>=1)&&(array[i]<=100)) {
			perfect=isPerfect(array[i]);
			cout<<perfect<<"\t";
			prime=isPrime(array[i]);
			cout<<prime<<"\t";
			perfectsq=isPerfectSquare(array[i]);
			cout<<perfectsq<<"\t";
			sphenic=isSphenic(array[i]);
			cout<<sphenic<<"\t";
			cout<<Binary(n);
			
		}
		if((array[i]<=0)&&(array[i]>100)){
			cout<<array[i]<<"\t";
			count=count+1;
			if(count%5==0)
			cout<<endl;	
			
		}
		if(array[i]==0)
		czero=czero+1;
		
		countn=countArray(array[i], 100);
		if(countn>max){
		max=countn;
		maxNum=array[i];	
		}
		
		if(countn<min){
		min=countn;
		minNum=array[i];	
		}
		
		for(k=1;k<=10;k=k+1){
			cout<<ran_ge<<"-"<<ran_ge+9<<"           "<<"|";
			numStars=range[k]/5;
			for(j=1;j<=numStars;j=j+1){
				cout<<"*";
			}
			ran_ge=ran_ge+10;
			cout<<endl;
		}
		
		inputfile>>n;
		i=i+1;
		
	}
	
	
	
	cout<<"The number of students who had valid favourite numbers:"<<i<<endl;
	cout<<"The number of students who had invalid favourite numbers:"<<count<<endl;
	cout<<"The number of students who did not have a favourite number:"<<czero<<endl;
	cout<<"The number that was chosen the most:"<<maxNum<<endl;
	cout<<"The number that was chosen the least:"<<minNum<<endl;

inputfile.close("numbers.txt");	
return 0;
}
	
