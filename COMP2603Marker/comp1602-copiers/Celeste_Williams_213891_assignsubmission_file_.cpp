#include <iostream>
#include <fstream>
using namespace std;


bool isPerfect(int num)
{
	int sum=0;
	int i=1;
	while(i<num){
		if(num%i==0)
			sum=sum+i;
		i++;
	}
	if (sum==num){
		return true;
	}
	else
		return false;
}

bool isPrime(int num)
{
	int i;
	for(i=2;i<=num/2;i++){
		if(num%i==0)
			return false;
	
			
	}
	return true;
}

bool isPerfectSq(int num)
{
	int sq;
	int i;
	for(i=1;i<=num/2;i++){
		sq=i*i;
		if(sq==num)
			return true;
	}
	return false;
}

bool isSphenic(int num)
{
	int i, count, prod;
	count=0;
	prod=1;
	for(i=2;i<=num/2;i++){
		if((num%i==0) && (isPrime(i))){
			prod=prod*i;
			count++;
		}
	}
		if((count==3) && (prod==num))
			return true;
	
	return false;
}

void Conversion(int num)
{
	int remainder[40];
	int j=0;
	while(num>0){
		remainder[j]=num%2;
		num=num/2;
		j++;
	}
	int a=0;
	a=j;
	while(a<=8){
			cout<<"0";
			a++;
	}
	
	int i;
	for(i=j-1;i>=0;i=i-1){
		cout<<remainder[i];
	}
}

int main()
{
	int num;
	ifstream fin;
	bool perfect, sphenic, perfectSq, prime;
	int nums[9999];
	int allNums[9999];
	int printCount=1;
	int a;
	int indexFound=0;
	int ivCount=0;
	int vCount=0;
	int nCount=0;
	int numCount=0;
	int num10=0;
	int num20=0;
	int num30=0;
	int num40=0;
	int num50=0;
	int num60=0;
	int num70=0;
	int num80=0;
	int num90=0;
	int num100=0;	
	int count=0;
	int uniqueIndex=0;
	int sizeU=0;
	int uniqueNum[9999];
	int countNum[9999];
	int max=0;
	int min=9999;
	
	fin.open("numbers.txt");
	
	cout<<"Number	Perfect?	Prime?	Perfect Square?	Sphenic?	Binary Equivalent"<<endl;
	
	fin>>num;
	while (num != -1){
		
		if(num == 0){
			nCount++;
			fin>>num;
		}
		allNums[count]=num;
		count++;	
		if ((num >= 1) && (num <= 100)){
			
			nums[numCount]=num;
			numCount++;
			
			vCount++;
			perfect= isPerfect(num);
			prime= isPrime(num);
			perfectSq= isPerfectSq(num);
			sphenic= isSphenic(num);
			
			cout<<num<<"	";
			if (perfect == 1)
				cout<<"Y";
			else
				cout<<"N";
				
			cout<<"		";
			
			if (prime == 1)
				cout<<"Y";
			else
				cout<<"N";
				
			cout<<"		";
			
			if (perfectSq == 1)
				cout<<"Y";
			else
				cout<<"N";
				
			cout<<"	";
			
			if (sphenic == 1)
				cout<<"Y";
			else
				cout<<"N";
				
			cout<<"		";
			
			Conversion(num);
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
		if((num>100) || (num<-1)){
			ivCount++;
		}
		fin>>num;
	}
	
	cout<<endl;
	cout<<"Invalid Numbers"<<endl;
	
	for(a=0;a<count;a++){	
		if(printCount > 5){
				cout<<endl;
				printCount=1;
			}
			else{
				if((allNums[a]>100) || (allNums[a]< -1)){
				cout<<allNums[a]<<" ";
				printCount++;
				}
			}
	}
	
	cout<<endl<<endl;	
	int hCount=1;
	
	cout<<"Range	Histogram"<<endl;
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
	cout<<endl;
	hCount=1;
	
	cout<<"Number of Students who chose valid numbers: "<<vCount<<endl;
	cout<<"Number of Students who chose invalid numbers: "<<ivCount<<endl;
	cout<<"Number of Students who did not choose a number: "<<nCount<<endl;
	
	
	for(a=0;a<numCount;a++)
	{
		countNum[a]=-1;
		uniqueNum[a]=0;
	}
			
	int finalNum[9999];
	int freq[9999];
	
	for(int i=0;i<numCount;i++){
		count=1;
		for(int j=i+1;j<numCount;j++){
			if(nums[i]==nums[j]){
				count++;
				countNum[j]=0;
			}
		}
		if(countNum[i] !=0)
			countNum[i]=count;
	}
	
	for(int i=0;i<numCount;i++){
		if(countNum[i]!=0){
			finalNum[uniqueIndex]=nums[i];
			freq[uniqueIndex]=countNum[i];
			uniqueIndex++;
		}
	}

	for(a=0;a<uniqueIndex;a++){
		if(freq[a]>max)
			max= freq[a];
		if(freq[a]<min)			
			min=freq[a];
	}
	
	cout<<"Number/s that were chosen the most: ";
	for(a=0;a<uniqueIndex;a++){
		if(freq[a]==max){
			cout<<finalNum[a];
			cout<<" ";
		}
	}
	cout<<endl;
	cout<<"Number/s that were chosen the least: ";
	for(a=0;a<uniqueIndex;a++){
		if(freq[a]==min){
			cout<<finalNum[a];
			cout<<" ";
		}
	}
}

