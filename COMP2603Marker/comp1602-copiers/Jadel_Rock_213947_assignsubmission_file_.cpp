#include<iostream>
#include<fstream>
using namespace std;

bool IsPerfect(int n){
	int i,sum;
		for(i=1;i<n; i++)
	{
		if(n%i==0)
			sum=sum+i;
	}
	if(sum==n && n!=1)
		return true;
	else
		return false;
}

bool IsPrime(int n){
	int i;
	
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
			return false;
	}	
	return true;
}

bool IsPerfectSquare(int n){
	int i;
	
	for(i=1;i<=n/2;i++)
	{
		if(i*i == n)
			return true;
	}
	return false;	
}

bool IsSphenic(int n){
	int i,c=0,prod=1;
	
	for(i=2;i<=n/2;i++)
	{
		if((n%i==0) && IsPrime(i))
		{
			prod=prod*i;
			c++;
		}
		if((c==3) && (prod==n))
			return true;
		return false;
	}
}

int Binaryeq(int n){
	int bits[8]={0};
	int i,j;
	for(i=0;n>0;i++)
	{
		bits[i]=n%2;
		n=n/2;
	}
	cout<<"		";
	for(j=7;j>=0;j--)
		cout<<bits[j];
	return 0;
}


int main(){
	int invalid[25];
	int range[10];
	int num,unspecified=0,i=1,j,countvalid=0,num10=0,num20=0,num30=0,num40=0,num50=0,num60=0,num70=0,num80=0,num90=0,num100=0;
	int a,numCount=0,count,nums[9999],countNum[9999],uniqueNum[9999],uniqueIndex,max=0,min=9999;
	int totalnums=0,b,c;
	ifstream in;
	
	in.open("numbers.txt");
	
	if (!in.is_open()) 
	{
		cout << "Error opening input file.";
		return 0;
	}
	
	in>>num;
	cout<<"Number \t"<<"Perfect \t"<<"Prime \t"<<"Perfect Square \t"<<"Sphenic \t"<<"Binary Equiv \t"<<endl;
	cout<<"====== \t"<<"======= \t"<<"===== \t"<<"============== \t"<<"======= \t"<<"============="<<endl;
	while(num!=-1)
	{
		totalnums++;
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
				if(IsPerfect(num))
					cout<<"\t\t"<<"Y";
				else
					cout<<"\t\t"<<"N";	
				if(IsPrime(num))
					cout<<"\t\t"<<"Y";
				else
					cout<<"\t\t"<<"N";
				if(IsPerfectSquare(num))
					cout<<"\t\t"<<"Y";
				else
					cout<<"\t\t"<<"N";
				if(IsSphenic(num))
					cout<<"\t\t\t"<<"Y";
				else
					cout<<"\t\t\t"<<"N";
				cout<<"\t";
				Binaryeq(num);
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
			}
		in>>num;
	}
	cout<<endl;
	cout<<endl<<"Invalid Numbers"<<endl;
	for(j=1;j<i;j++)
	{
		cout<<invalid[j]<<" ";
		if(j%5==0)
			cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	int Hiscount=1;
	cout<<"RANGE \t \t HISTOGRAM"<<endl;
	cout<<" --------------------"<<endl;
	cout<<"1-10		";
	while (Hiscount <= num10/5){
		cout<<"*";
		Hiscount++;
	}
	cout<<endl;
	Hiscount=1;
	
	cout<<"11-20		";
	while (Hiscount <= num20/5){
		cout<<"*";
		Hiscount++;
	}
	cout<<endl;
	Hiscount=1;
	
	cout<<"21-30		";
	while (Hiscount <= num30/5){
		cout<<"*";
		Hiscount++;
	}
	cout<<endl;
	Hiscount=1;
	
	cout<<"31-40		";
	while (Hiscount <= num40/5){
		cout<<"*";
		Hiscount++;
	}
	cout<<endl;
	Hiscount=1;
	
	cout<<"41-50		";
	while (Hiscount <= num50/5){
		cout<<"*";
		Hiscount++;
	}
	cout<<endl;
	Hiscount=1;
	
	cout<<"51-60		";
	while (Hiscount <= num60/5){
		cout<<"*";
		Hiscount++;
	}
	cout<<endl;
	Hiscount=1;
	
	cout<<"61-70		";
	while (Hiscount <= num70/5){
		cout<<"*";
		Hiscount++;
	}
	cout<<endl;
	Hiscount=1;
	
	cout<<"71-80		";
	while (Hiscount <= num80/5){
		cout<<"*";
		Hiscount++;
	}
	cout<<endl;
	Hiscount=1;
	
	cout<<"81-90		";
	while (Hiscount <= num90/5){
		cout<<"*";
		Hiscount++;
	}
	cout<<endl;
	Hiscount=1;
	
	cout<<"91-100		";
	while (Hiscount <= num100/5){
		cout<<"*";
		Hiscount++;
	}
	cout<<endl;
	Hiscount=1;
	
	cout<<endl;
	cout<<endl<<"Total Valid Favourite Numbers: "<<countvalid;
	cout<<endl<<"Total Invalid Favourite Numbers: "<<i-1;
	cout<<endl<<"Total Unrevealed Favourite Numbers: "<<unspecified;
	cout<<endl;
	
	
	for(a=0;a<countvalid;a++)
	{
		countNum[a]=-1;
		uniqueNum[a]=0;
	}
			
	int finalNum[9999];
	int freq[9999];
	
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
			freq[uniqueIndex]=countNum[b];
			uniqueIndex++;
		}
	}

	for(a=0;a<uniqueIndex;a++){
		if(freq[a]>max)
			max= freq[a];
		if(freq[a]<min)			
			min=freq[a];
	}
	
	cout<<endl<<"Numbers that were chosen the most: ";
	for(a=0;a<uniqueIndex;a++){
		if(freq[a]==max){
			cout<<finalNum[a];
			cout<<" ";
		}
	}
	cout<<endl;
	cout<<"Numbers that were chosen the least: ";
	for(a=0;a<uniqueIndex;a++){
		if(freq[a]==min){
			cout<<finalNum[a];
			cout<<" ";
		}
	}
	
	
	return 0;
}
