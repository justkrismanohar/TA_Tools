#include <iostream>
#include <fstream>
using namespace std;

char isPerfect(int x){
	int sum=0,i;
	char perfect;
	for(i=1;i<x;i++){
		if(x%i==0)
			sum+=i;
	}
	if(sum==x){
		perfect='Y';
	}else{
		perfect='N';
	}
	return perfect;
}//end of isPerfect

char isPrime(int x){
	int i,count=0;
	char prime;
	for(i=2;i<=x/2;i++){
		if(x%i==0){
			count=count+1;
		}
	}
	if(count==0){
		prime='Y';
	}else{
		prime='N';
	}
	return prime;
}//end of isPrime

char isPerfectSquare(int x){
	int i,sq=0;
	char perfectSquare;
	for(i=1;i<=x;i++){
		sq=i*i;
		if(sq==x){
			perfectSquare='Y';
		}else{
			perfectSquare='N';
		}
	}
	return perfectSquare;
}//end of isPerfectSquare

char isSphenic(int x){
	int i,count=0,prod=1;
	char sphenic;
	for(i=2;i<=x/2;i++){
		if(x%i==0 && isPrime(i)=='Y'){
			prod=prod*i;
			count=count+1;
		}
	}
	if(prod==x && count==3){
		sphenic='Y';
	}else{
		sphenic='N';
	}
	return sphenic;
}//end of isSphenic

void binary(int x){
	int arr[8];
	int i,rem=x;
	
	for(i=0;i<8;i++){
		arr[i]=0;
	}
	i=7;
	while(rem!=0 && i>=0){
		arr[i]=rem%2;
		rem=rem/2;
		i--;
	}
	for(i=0;i<8;i++){
		cout<<arr[i];
	}
}//end of binary

int main(){
	ifstream in;
	in.open("numbers.txt");
	if(!in.is_open()){
		cout<<"Error opening file."<<endl;
		return 0;
	}
	
	int num,i,j,a,k;
	char perfect,prime,perfectSquare,sphenic;
	int invalidNums[100];
	string range[10];
	int histo[10];
	int valid=0,invalid=0,zero=0;
	int count[101];
	
	for(a=0;a<100;a++){
		count[a]=0;
	}
	
	for(a=0;a<10;a++){
		histo[a]=0;
	}
	
	range[0]="1-10";
	range[1]="10-20";
	range[2]="21-30";
	range[3]="31-40";
	range[4]="41-50";
	range[5]="51-60";
	range[6]="61-70";
	range[7]="71-80";
	range[8]="81-90";
	range[9]="91-100";
	
	cout<<"Number		Perfect?	Prime?		Perfect Square?		Sphenic?	Binary Equiv."<<endl;
	cout<<"======		========	======		===============		========	============="<<endl;
	in>>num;
	while(num!=-1){
		if(num>0 && num<=100){
			valid=valid+1;
		
			k=num;
			if(count[k]==0){
				count[k]++;
			}else
				count[k]++;
		
			perfect=isPerfect(num);
			prime=isPrime(num);
			perfectSquare=isPerfectSquare(num);
			sphenic=isSphenic(num);
			
			cout<<num<<"		"<<perfect<<"		"<<prime<<"		"<<perfectSquare<<"			"<<sphenic<<"		";
			binary(num);
			cout<<endl;
			
			if(num>=1 && num<=10){
				histo[0]=histo[0]+1;
			}
			if(num>=11 && num<=20){
				histo[1]=histo[1]+1;
			}
			if(num>=21 && num<=30){
				histo[2]=histo[2]+1;
			}
			if(num>=31 && num<=40){
				histo[3]=histo[3]+1;
			}
			if(num>=41 && num<=50){
				histo[4]=histo[4]+1;
			}
			if(num>=51 && num<=60){
				histo[5]=histo[5]+1;
			}
			if(num>=61 && num<=70){
				histo[6]=histo[6]+1;
			}
			if(num>=71 && num<=80){
				histo[7]=histo[7]+1;
			}
			if(num>=81 && num<=90){
				histo[8]=histo[8]+1;
			}
			if(num>=91 && num<=100){
				histo[9]=histo[9]+1;
			}
			
		}else 
			if(num<-1 || num>100){
				invalid=invalid+1;
				invalidNums[i]=num;
				i++;
			}else
				if(num==0){
					zero=zero+1;
				}
	
		in>>num;
	}

	cout<<endl<<endl<<"Invalid numbers: "<<endl;
	for(j=0;j<i;j++){
		if(j%5==0 && j>1)
			cout<<endl;
		cout<<invalidNums[j]<<"	";
	}//display invalid numbers
	
	
	cout<<endl<<endl<<endl<<"Range		Histogram"<<endl;
	cout<<"========================="<<endl;
	for(i=0;i<10;i++){
		cout<<range[i]<<"		:";
		for(j=0;j<histo[i]/5;j++){
		cout<<"*";
		}
		cout<<endl;
	}//display histogram
	
	cout<<endl<<"Amount of students who specified valid favourite numbers:"<<valid<<endl;
	cout<<"Amount of students who specified invalid favourite numbers:"<<invalid<<endl;
	cout<<"Amount of students who did not reveal their favourite number:"<<zero<<endl;
	
	cout<<endl<<"Numbers that were chosen the most:"<<endl;
	for(k=0;k<100;k++){
		if(count[k]>=2)
			cout<<k<<endl;
	}
	
	cout<<endl<<endl;
	cout<<"Numbers that were chosen the least:"<<endl;
	for(k=0;k<100;k++){
		if(count[k]==1)
			cout<<k<<endl;
	}
	
	in.close();
}
