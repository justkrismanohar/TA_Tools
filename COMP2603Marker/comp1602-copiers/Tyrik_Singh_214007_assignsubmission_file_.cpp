#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
void perfect(int num){
	int sum=0,i=1;
	while(i<num){
		if(num%i==0)
		sum=sum+i;
		i=i+1;
	}
	if (sum==num)
	cout<<"Y";
	else
	cout<<"N";
}
void prime(int num){
int i,count=0;
if(num==0)
cout<<"N";
else{
for(i=2;i<num;i=i+1)
	if(num%i==0)
	count =count+1;	
}
if(count>1)
cout<<"N";
else
cout<<"Y";
}
void perfectsquare(int num){
	int r,i=1;
	while(r<num){
		i=i+1;
		r=i*i;
	}
	if(r==num)
	cout<<"Y";
	else
	cout<<"N";
}
void sphenic(int num){
	int i,c,arr[num],spe;
	arr[0]=0;
	arr[1]=1;
	spe=0;
	for(i=0;i<=num;i=i+1)
	arr[i]=1;
	for(i=2;i<=num;i=i+1){
		for(c=i+1;c<=num;c=c+1)
		if(c%i==0)
		arr[c]=0;
	}
	for(i=2;i<=num;i=i+1){
arr[i]==1;
}
	if(num%arr[i]==0){
		num=num/i;
		cout<<"Y";
		spe=spe+1;
	}
	else 
	cout<<"N";
	}
void binary(int num){
	int binaryNum = 0;
   int i = 1, rem;
   while (num != 0){
      rem = num % 2;
      num /= 2;
      binaryNum == rem * i;
      i *= 10;
   }

   cout << "Equivalent Binary Number: " << binaryNum << endl;
}
int main(){
ifstream in;
in.open("numbers.txt");
if(!in.is_open()){
	cout<<"File Not Found";
return 0;
}
ofstream out;
out.open("favorite");
int num,invalid[num],nodef[num],check=0;
in>>num;
	out<<"Nummber"<<"/t"<<"Perfect"<<"/t"<<"Prime"<<"/t"<<"Perfect Square"<<"/t"<<"Sphenic"<<"/t"<<"Binary Equivalent"<<endl;
	while(num!=-1){
		if((num>=0) && (num<=100))
	out<<num<<"/t"<<perfect<<"/t"<<prime<<"/t"<<perfectsquare<<"/t"<<sphenic<<"/t"<<binary<<endl;
	else{
		
		invalid[num]=num;
	}
	if(num=0)
	nodef[num]=num;
	in>>num;	
}
out<<invalid[num]<<endl;
out<<"Range"<<"/t"<<"/t"<<"Histogram"<<endl;
while(!in.eof()){
	if((num>0)&&(num<=10))
	check =check +1;
	if (check=5){
	check=0;
	out<<"*";
}
	else{
		if((num>10)&&(num<=20))
			check =check +1;
	if (check=5){
	check=0;
	out<<"*";
}
	}
	if((num>20)&&(num<=30)){
		check =check +1;
	if (check=5){
	check=0;
	out<<"*";
}
	}
	else{
		if((num>30)&&(num<=40)){
		check =check +1;
	if (check=5){
	check=0;
	out<<"*";
}
		}
	}
	if((num>40)&&(num<=50)){
			check =check +1;
	if (check=5){
	check=0;
	out<<"*";
}
	}
	else{
		if((num>50)&&(num<=60)){
				check =check +1;
	if (check=5){
	check=0;
	out<<"*";
}
		}
	}
	if((num>60)&&(num<=70)){
			check =check +1;
	if (check=5){
	check=0;
	out<<"*";
}
	}
	else{
		if((num>70)&&(num<=80)){
				check =check +1;
	if (check=5){
	check=0;
	out<<"*";
}
		}
	}
	if((num>80)&&(num<=90)){
			check =check +1;
	if (check=5){
	check=0;
	out<<"*";
}
	}
	else{
		if((num>90)&&(num<=100)){
				check =check +1;
	if (check=5){
	check=0;
	out<<"*";
}
		}
	}
		
}



return 0;
}
