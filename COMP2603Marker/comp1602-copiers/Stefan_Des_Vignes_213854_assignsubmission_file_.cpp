#include<iostream>
#include<fstream>
using namespace std;
bool isPerfect(int num)
{
int i, sum=0;
for(i=1;i<num;i++)
	{
		if(n%i==0)
		sum=sum+i;	
	}	
	if(sum==n){
		return true;
	}
	else
	return false;
}
int binary(int num)
{
	int bits[8]={0};
	int i,j;
	for(i=0-;n>0;i++)
	{
		bits[i]=n%2;
		n=n/2;
	}
	cout<<"     ";
	for(j=7;j>=0;j--)
	cout<<bits[j];
	return 0;
}
bool isSphenic(int num){
int i, prod,c;
for(i=2;i<=n/2;i++)
	{
		if((n%i==0)&&isPrime(i))
		{
			prod=prod*i;
			c=c+1;
		}
		if((c==3)&&(prod==n))
		return true;
	}
	return false;
}
bool isPerfectSquare(int num){
int sq,i;
for(i=1;i<=n/2;i++){
sq=i*i;
if(sq==n)
return true;	
}
else
return false;
}
bool isPrime(int num){
int i;
for(i=2;i<=n/2;i++){
if(n%i==0)
return false;
}
return true;
}
int main(){
int num;
int num,unspecified=0,i=1,j,countvalid=0,num10=0,num20=0,num30=0,num40=0,num50=0,num60=0,num70=0,num80=0,num90=0,num100=0;
int a,numCount=0,count,nums[9999],countNum[9999],uniqueNum[9999],uniqueIndex,max=0,min=9999,invalid[25];
int b,c,totalnumbers=0;
ifstream fin;
fin.open("numbers.txt");
 if (!fin.is_open()) {
 cout << "Error opening input file. Aborting ...";
 return 0;
 }
 cout<<"Number"<<"Perfect?"<<"Prime?"<<"Perfect Square?"<<"Sphenic?"<<"Binary equiv."<<endl;
 cout<<"======================================================================================"<<;
 fin>>num;
 while(num!=-1)
 	{
	totalnumbers++;
	if(num==0)
	unspecified++;
	else
	if((num<1) || (num>100))
			{
			invalid[i]=num;
			i++;
			}
	else
{
 	nums[countvalid]=num;
		countvalid++;
			cout<<num;
		if(isPerfect(num))
			cout<<"\t\t"<<"Y";
		else
			cout<<"\t\t"<<"N";
		if(isPrime(num))
			cout<<"\t\t"<<"Y";
		else
			cout<<"\t\t"<<"N";
		if(isPerfectsquare(num))
			cout<<"\t\t"<<"Y";
		else
			cout<<"\t\t"<<"N";
		if(isSphenic(num))
			cout<<"\t\t\t"<<"Y";
		else
		cout<<"\t\t\t"<<"N";
		cout<<"\t";
		binary(num);
		cout<<endl;
	if ((num>=1) && (num<=10))
		num10++;
	if ((num>=11) && (num<=20))
		num20++;
	if ((num>=21) && (num<=30))
		num30++;
	if ((num>=31) && (num<=40))
		num40++;
	if ((num>=41) && (num<=50))
		num50++;
	if ((num>=51) && (num<=60))
		num60++;
	if ((num>=61) && (num<=70))
		num70++;
	if ((num>=71) && (num<=80))
		num80++;
	if ((num>=81) && (num<=90))
		num90++;
	if ((num>=91) && (num<=100))
		num100++;
	fin>>num;	
}
fin>>num;		
	}	
	cout<<endl<<"=========================================================================================================";
	cout<<endl<<"Invalid Numbers"<<endl;
	for(j=1;j<i;j++)
	{
		cout<<invalid[j]<<" ";
		if(j%5==0)
			cout<<endl;
	}
	cout<<endl<<"=========================================================================================================";
	int hCount=1;
	cout<<endl<<"Range	    	Histogram";
	cout<<endl<<"============================"<<endl;
	cout<<"1-10	";
	while (hCount <= num10/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;
cout<<"11-20	";
	while (hCount <= num20/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;
	cout<<"21-30	";
	while (hCount <= num30/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;
	cout<<"31-40	";
	while (hCount <= num40/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;
	cout<<"41-50	";
	while (hCount <= num50/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;
	cout<<"51-60	";
	while (hCount <= num60/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;
	cout<<"61-70	";
	while (hCount <= num70/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;
	cout<<"71-80	";
	while (hCount <= num80/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;
	cout<<"81-90	";
	while (hCount <= num90/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;
	cout<<"91-100	";
	while (hCount <= num100/5){
		cout<<"*";
		hCount++;
	}
cout<<endl;
hCount=1;
cout<<endl<<"====================================================================================================";
cout<<endl<<"Total Valid Favourite Numbers: "<<countvalid;
cout<<endl<<"Total Invalid Favourite Numbers: "<<i-1;
cout<<endl<<"Total Unrevealed Favourite Numbers: "<<unspecified;
cout<<endl<<"===================================================================================================";
	for(a=0;a<countvalid;a++)
	{
		countNum[a]=-1;
		uniqueNum[a]=0;
	}
int finalNum[9999];
int frequent[9999];
for(int b=0;b<countvalid;b++){
		count=1;
	for(int c=b+1;c<countvalid;c++){
		if(nums[b]==nums[c]){
			count++;
			countNum[c]=0;
			}
		}
	if(countNum[b] !=0)
		countNum[b]=count;
	}
for(int b=0;b<countvalid;b++){
	if(countNum[b]!=0){
		finalNum[uniqueIndex]=nums[b];
		frequent[uniqueIndex]=countNum[b];
		uniqueIndex++;
		}
	}
for(a=0;a<uniqueIndex;a++){
		if(frequent[a]>max)
		max= frequent[a];
		if(frequent[a]<min)
		min=frequent[a];
	}
cout<<endl<<"Number/s that were chosen the most: ";
for(a=0;a<uniqueIndex;a++){
	if(frequent[a]==max){
		cout<<finalNum[a];
		cout<<" ";
		}
	}
	cout<<endl;
	cout<<"Number/s that were chosen least: ";
	for(a=0;a<uniqueIndex;a++){
		if(frequent[a]==min){
			cout<<finalNum[a];
			cout<<" ";
		}
	}
	return 0;
}

