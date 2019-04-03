#include <iostream>
#include <fstream>
using namespace std;
bool isPerfectNum(int n){
	int i, sum=0;
	for(i=1;i<n;i=i+1){
		if(n%i==0)
		sum=sum+i;
	}
	if(sum==n)
	return true;
	else return false;
}
bool isPrime(int n){
	int i;
	for(i=2;i<=n/2;i=i=i+1){
		if(n%i==0)
		return false;
	}
	return true;
}
bool isPerfectSq(int n){
	int i,sq;
	for(i=1;i<=n/2;i=i+1){
		sq=i*i;
		if(sq==n)
		return true;
	}
	return false;
}
bool isSphenic(int n){
	int i,prod=1,count=0;
	for(i=2;i<=n/2;i=i+1){
	if((n%i==0)&&(isPrime(i))){
		prod=prod*i;
		count=count+1;
	}
	}
	if((count==3)&&(prod==n))
	return true;
	else
	return false;
}
void Deter(bool n){
	if(n==true)
	cout<<"Y";
	else
	cout<<"N";
}
void BinaryEq(int n){
	int binary,i=0,bin[7];
	while(n>0){
		binary=n%2;
		bin[i]=binary;
		n=n/2;
		i=i+1;
	}
	for(int j=i-1;j>=0;j=j-1){
	cout<<bin[j];}
}
void Range(int n){
	int i=1;
	for(i=1;i<=n;i=i+1){
		if(i%5==0)
		cout<<"*";
	}
}
int main(){
	ifstream inputFile;
	int num,validfav=0,invalidfav=0,i=1,m,inval[1000], tracknum[101];
	int countA=0,countB=0,countC=0,countD=0,countE=0,countF=0,countG=0,countH=0,countI=0,countJ=0;
	inputFile.open("numbers.txt");
	if(!inputFile.is_open()){
	cout<<"Could not open numbers.txt"<<endl;
	return 1;
}
for(m=0;m<101;m=m+1)
tracknum[m]=0;
cout<<"Numbers"<<"\t\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t\t"<<"Perfect Square?"<<"\t\t"<<"Sphenic?"<<"\t"<<"Binary Equiv."<<endl;
cout<<"======"<<"\t\t"<<"======="<<"\t\t"<<"========"<<"\t"<<"============="<<"\t\t"<<"========"<<"\t"<<"============="<<endl;
inputFile>>num;
while(num!=-1){
	if((num>=0)&&(num<=100)){
		tracknum[num]=tracknum[num]+1;
		if(num!=0){
		cout<<num<<"\t\t";Deter(isPerfectNum(num));cout<<"\t\t";Deter(isPrime(num));cout<<"\t\t\t";Deter(isPerfectSq(num));cout<<"\t\t";Deter(isSphenic(num));cout<<"\t\t";
		BinaryEq(num);
		cout<<endl;
		validfav=validfav+1;
		if((num>=1)&&(num<=10))
		countA=countA+1;
		if((num>=11)&&(num<=20))
		countB=countB+1;
		if((num>=21)&&(num<=30))
		countC=countC+1;
		if((num>=31)&&(num<=40))
		countD=countD+1;
		if((num>=41)&&(num<=50))
		countE=countE+1;
		if((num>=51)&&(num<=60))
		countF=countF+1;
		if((num>=61)&&(num<=70))
		countG=countG+1;
		if((num>=71)&&(num<=80))
		countH=countH+1;
		if((num>=81)&&(num<=90))
		countI=countI+1;
		if((num>=91)&&(num<=100))
		countJ=countJ+1;}
	}
	else{
		inval[invalidfav]=num;
		invalidfav=invalidfav+1;
	}
	inputFile>>num;
	}
	inputFile.close();
	
	int j;
	cout<<"The invalid numbers are:"<<endl;
	for(j=0;j<invalidfav;j=j+1){
		cout<<inval[j]<<",";
		if((j+1)%5==0)
		cout<<endl;
	}
	cout<<endl;
	cout<<"Range"<<"\t"<<"Histogram"<<endl;
	cout<<"===================================="<<endl;
	cout<<"1-10"<<"\t";Range(countA);cout<<endl;
	cout<<"11-20"<<"\t";Range(countB);cout<<endl;
	cout<<"21-30"<<"\t";Range(countC);cout<<endl;
	cout<<"31-40"<<"\t";Range(countD);cout<<endl;
	cout<<"41-50"<<"\t";Range(countE);cout<<endl;
	cout<<"51-60"<<"\t";Range(countF);cout<<endl;
	cout<<"61-70"<<"\t";Range(countG);cout<<endl;
	cout<<"71-80"<<"\t";Range(countH);cout<<endl;
	cout<<"81-90"<<"\t";Range(countI);cout<<endl;
	cout<<"91-100"<<"\t";Range(countJ);cout<<endl;
	
	cout<<"Amount of students who specified valid favourite numbers:"<<validfav<<endl;
	cout<<"Amount of students who specified invalid favourite numbers:"<<invalidfav<<endl;
	cout<<"Amount of students who did not reveal their favourite number:"<<tracknum[0]<<endl;
	
	int n;
	cout<<"The number/s that was/were chosen the most by the students is/are:"<<endl;
	for(n=1;n<=100;n=n+1){
		if(tracknum[n]>=2)
		cout<<n<<",";
		}
		cout<<endl;
		
		int l;
		cout<<"The number/s that was/chosen the least by the students is/are:"<<endl;
		for(l=1;l<=100;l=l+1){
			if(tracknum[l]==1)
			cout<<l<<",";
		}
		cout<<endl;	
		
		return 0;
	}


