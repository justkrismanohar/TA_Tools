#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream in;
ofstream out;

bool perfect(int num){
	int x=0;
	int ans=0;
	int total=1;
	
	for(x=2;x<=num;x++){
		if(num%x==0){
			ans=num/x;
			total+=ans;
		}
	}
	if(total==num)
		return true;
	else
		return false;
}

bool prime(int num){
	int x=0;

	if(num==2)
		return true;
	if((num==0) || (num==1))
		return false;
	for(x=2;x<=num/2;x++){
		if(num%x==0)
			return false;
		else
			return true;
	}
}

bool persquare(int num){
	int rem=0;
	
	rem=sqrt(num);
	if(rem*rem==num)
		return true;
	else
		return false;
}

bool sphenic(int num){
	if(num==30)
		return true;
	if(num==42)
		return true;
	if(num==66)
		return true;
	if(num==70)
		return true;
	if(num==78)
		return true;
	else
		return false;
}

void binB2(int num){
	int rem=0;
	int arr[7];
	int x=7;
	
	while(num!=1){
		rem=num%2;
		num/=2;
		arr[x]=rem;
		x--;
	}
	if(num==1)
		arr[x]=1;
	for(x=0;x<=7;x++){
		cout<<arr[x];
	}
}

int main(){
	int count=0;
	int num=0;
	int numbers[500];
	int n=0;
	int invalidNos[100];
	int invalCount=0;
	int i=0;
	int hidCount=0;
	int d=0;
	int rangeC[9];
	int calc=0;
	int w=0;
	
	in.open("numbers.txt");
	if(!in.is_open()){
		cout<<"Error...."<<endl;
		return 0;
	}
	else{
		in>>num;
		while (num!=-1){
			if((num>=1) && (num<=100)){
				numbers[count]=num;
				count++;
			}
			else{
				if(num<0){
					invalidNos[invalCount]=num;
					invalCount++;	
				}
				if(num==0){
					hidCount++;
				}
				count--;
			}
			in>>num;
		}
		in.close();
		cout<<"Number\t Perfect\t Prime\t Perfect Square\t Sphenic\t Binary Equiv."<<endl;
		cout<<"------\t -------\t -----\t --------------\t -------\t -------------"<<endl;
		for(d=0;d<=count;d++){
			num=numbers[d];
			cout<<numbers[d]<<"\t ";
			cout<<perfect(num)<<"\t ";
			cout<<prime(num)<<"\t ";
			cout<<persquare(num)<<"\t ";
			cout<<sphenic(num)<<"\t ";
			binB2(num);
			cout<<endl;
		}
		cout<<"The following is numbers that were considered invalid"<<endl;
		for(i=0;i<=invalCount;i++){
			cout<<invalidNos[i]<<" ";
			if(i%5==0)
				cout<<endl;
		}
		cout<<"The following is a histogram representing the data collected"<<endl;
		for(d=0;d<=count;d++){
			num=numbers[d];
			if((num>=1) && (num<=10))
				rangeC[0]+=1;
			if((num>=11) && (num<=20))
				rangeC[1]+=1;
			if((num>=21) && (num<=30))
				rangeC[2]+=1;
			if((num>=31) && (num<=40))
				rangeC[3]+=1;
			if((num>=41) && (num<=50))
				rangeC[4]+=1;
			if((num>=51) && (num<=60))
				rangeC[5]+=1;
			if((num>=61) && (num<=70))
				rangeC[6]+=1;
			if((num>=71) && (num<=80))
				rangeC[7]+=1;
			if((num>=81) && (num<=90))
				rangeC[8]+=1;
			if((num>=91) && (num<=100))
				rangeC[9]+=1;
		}
		for(d=1;d<=10;d++){
			cout<<"Range "<<d<<"\t";
			calc=((rangeC[d])/5);
			for(w=0;w<=calc;w++){
				cout<<"*";
			}
			cout<<endl;
		}
		cout<<count<<" students specified a favourite number"<<endl;
		cout<<hidCount<<" students withheld their favourite number"<<endl;
		cout<<invalCount<<" students gave invalid numbers"<<endl;
		
	}
	return 0;
}
