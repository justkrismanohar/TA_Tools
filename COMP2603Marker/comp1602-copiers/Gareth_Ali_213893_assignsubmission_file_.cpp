#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

bool PerfectNum(int num){
bool returnedPerfect=false;
int size=0,i=0,perfectSum=0;
size=num/2;
int perfectArr[size];
perfectArr[0]=0;
for(i=1;i<size;i=i+1){
if(num%i==0){
	perfectArr[i]=i;
}
else{
	perfectArr[i]=0;
}
}
for(i=0;i<size;i=i+1){
	perfectSum=perfectArr[i]+perfectSum;
}
if(perfectSum==num){
	returnedPerfect=true;
}
return returnedPerfect;
}

bool PrimeNum(int num){
bool returnedPrime=false;
int size=0, i=0, primeSum=0;
size=num/2;
int primeArr[size];
for(i=2;i<num;i=i+1){
	if(num%i!=0){
	primeArr[i]=i;
}
	else{
		primeArr[i]=0;
	}
 }
for(i=2;i<num;i=i+1){
	primeSum=primeArr[i]+primeSum;
}
if(primeSum!=0){
	returnedPrime=true;
}
return returnedPrime;
}

bool PerfectSQNum(int num){
int PotentialPerfectSQ=0;
bool returnedPerfectSQ=false;
PotentialPerfectSQ=sqrt(num);
if(PotentialPerfectSQ*PotentialPerfectSQ==num){
	returnedPerfectSQ=true;
}
return returnedPerfectSQ;
}

bool SphenicNum(int num){
bool returnedSphenicNum=false;
int size,r=2,l=2, i;
size=num/2;
int FactorNum[size];
for(i=2;i<size;i=i+1){
	if(num%i==0){
		FactorNum[r]=i;
	}
	else{
		r=r-1;
	}
r=r+1;
}
int PrimeNum[size];
for(i=2;i<size;i=i+1){
	if(FactorNum[i]==2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47){
		PrimeNum[l]=FactorNum[i];
	}
	else{
		l=l-1;
	}
l=l+1;
}
for(i=2;i<size;i=i+1){
	if(PrimeNum[i]*PrimeNum[i+1]*PrimeNum[i+2]==num){
		returnedSphenicNum=true;
	}
}
return returnedSphenicNum;
}

int BinaryNum(int num){
int BinaryArr[8];
int n, i, FullBinaryNumber, Rem;
for(i=0;num<=7;i=i+1){
	Rem=num%2;
    num=num/2;
    BinaryArr[i]=Rem;
}
for(i=7;i>=0;i=i-1){
	FullBinaryNumber=BinaryArr[i]*10^i+FullBinaryNumber;
}
return FullBinaryNumber;
}


int main(){
ifstream in;
in.open("numbers.txt");
if(!in.is_open()){
	cout<<"Error file not found...Aborting."<<endl;
	return 0;
}

int num=0,countSphenicNum=0,countPerfectSQ=0,countPrime=0,countPerfect=0,i=0,count=0,EntireBinaryNum=0;
char IsPerfectNum, IsPrimeNum, IsPerfectSQNum, IsSphenicNum;
bool TruthPerfectNum=false, TruthPrimeNum=false, TruthPerfectSQ=false, TruthSphenicNum=false;
int invalidNum[1000];
int Range[10];
int CountNumType[3];

for(i=0;i<=3;i=i+1){
	CountNumType[i]=0;
}

for(i=0;i<=1000;i=i+1){
	invalidNum[i]=-1;
}	
for(i=0;i<=10;i=i+1){
	Range[i]=0;
}
i=0;
cout<<"Number"<<"\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equivalent"<<endl;
cout<<"======"<<"\t"<<"========"<<"\t"<<"======"<<"\t"<<"==============="<<"\t"<<"========"<<"\t"<<"================"<<endl;
cout<<endl;
in>>num;
while(num!=-1){
	if((num>=1)&&(num<=100)){
		CountNumType[0]=CountNumType[0]+1;
		TruthPerfectNum=PerfectNum(num);
		PerfectNum(num);
		 if(TruthPerfectNum==true){
			IsPerfectNum='Y';
		}
		 else{
			IsPerfectNum='N';
		}
		TruthPrimeNum=PrimeNum(num);
	    PrimeNum(num); 
	     if(TruthPrimeNum==true){
	     	IsPrimeNum='Y';
	     }
	     else{
	     	IsPrimeNum='N';
		 }
		 TruthPerfectSQ=PerfectSQNum(num);
		PerfectSQNum(num);
		 if(TruthPerfectSQ==true){
	     	IsPerfectSQNum='Y';
	     }
	     else{
	     	IsPerfectSQNum='N';
		 }
		 TruthSphenicNum=SphenicNum(num);
		SphenicNum(num);
		 if(TruthSphenicNum==true){
	     	IsSphenicNum='Y';
	     }
	     else{
	     	IsSphenicNum='N';
		 }
		 EntireBinaryNum=BinaryNum(num);
		BinaryNum(num);	
cout<<num<<"\t"<<IsPerfectNum<<"\t"<<IsPrimeNum<<"\t"<<IsPerfectSQNum<<"\t"<<IsSphenicNum<<"\t"<<EntireBinaryNum;


if(num>=1&&num<=10){
	Range[0]=Range[0]+1;
}
else if(num>=11&&num<=20){
	Range[1]=Range[1]+1;
}
else if(num>=21&&num<=30){
	Range[2]=Range[2]+1;
}
else if(num>=31&&num<=40){
	Range[3]=Range[3]+1;
}
else if(num>=41&&num<=50){
	Range[4]=Range[4]+1;
}
else if(num>=51&&num<=60){
	Range[5]=Range[5]+1;
}
else if(num>=61&&num<=70){
	Range[6]=Range[6]+1;
}
else if(num>=71&&num<=80){
	Range[7]=Range[7]+1;
}
else if(num>=81&&num<=90){
	Range[8]=Range[8]+1;
}
else if(num>=91&&num<=100){
	Range[9]=Range[9]+1;
}
}

else{
	i=i+1;
	invalidNum[i]=num;
	 if(num!=0){
	CountNumType[1]=CountNumType[1]+1;
}
else{
	CountNumType[2]=CountNumType[2]+1;
}
}
in>>num;
}
cout<<"The Invalid Numbers are: "<<endl;
cout<<endl;
for(i=1;i<1000;i=i+1){
	while(invalidNum[i]!=-1){
	cout<<invalidNum[i]<<"     ";
	count=count+1;
}
if(count%5==0){
	cout<<endl;
}
}
for(i=0;i<=10;i=i+1){
	Range[i]=Range[i]/5;
}
cout<<"Range"<<"\t"<<"Histogram"<<endl;
cout<<"==========================="<<endl;
cout<<"1-10"<<"\t"<<"|";
while(Range[0]!=0){
	cout<<"*";
	Range[0]=Range[0]-1;
}
cout<<endl;
cout<<"11-20"<<"\t"<<"|";
while(Range[1]!=0){
	cout<<"*";
	Range[1]=Range[1]-1;
}
cout<<endl;
cout<<"21-30"<<"\t"<<"|";
while(Range[2]!=0){
	cout<<"*";
	Range[2]=Range[2]-1;
}
cout<<endl;
cout<<"31-40"<<"\t"<<"|";
while(Range[3]!=0){
	cout<<"*";
	Range[3]=Range[3]-1;
}
cout<<endl;
cout<<"41-50"<<"\t"<<"|";
while(Range[4]!=0){
	cout<<"*";
	Range[4]=Range[4]-1;
}
cout<<endl;
cout<<"51-60"<<"\t"<<"|";
while(Range[5]!=0){
	cout<<"*";
	Range[5]=Range[5]-1;
}
cout<<endl;
cout<<"61-70"<<"\t"<<"|";
while(Range[6]!=0){
	cout<<"*";
	Range[6]=Range[6]-1;
}
cout<<endl;
cout<<"71-80"<<"\t"<<"|";
while(Range[7]!=0){
	cout<<"*";
	Range[7]=Range[7]-1;
}
cout<<endl;
cout<<"81-90"<<"\t"<<"|";
while(Range[8]!=0){
	cout<<"*";
	Range[8]=Range[8]-1;
}
cout<<endl;
cout<<"91-100"<<"\t"<<"|";
while(Range[9]!=0){
	cout<<"*";
	Range[9]=Range[9]-1;
}
cout<<endl;
cout<<"The number of students who specified valid favourite numbers were: "<<CountNumType[0]<<endl;
cout<<"The number of students who specified invalid favourite numbers were: "<<CountNumType[1]<<endl;
cout<<"The number of students who did not reveal their favourite numbers were: "<<CountNumType[2]<<endl;	
in.close();
return 0;
}

