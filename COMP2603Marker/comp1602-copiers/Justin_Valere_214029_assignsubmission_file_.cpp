#include<iostream>
#include <fstream>
using namespace std;
bool perfect(int num){ 
if((num>=1)&&(num<=100)){

	int x;
	int sum=0;
	for(x=1;x<num;x++){
		if(num%x==0)
		sum=sum+x;
	}
	if(num==sum){
		return true;
	}
	else
		return false;
	}
}
bool isprime(int n){

	int i,p;
	bool prime=true;
	if((n==1) || (n<0))
		prime=false;
	else {
		for(i=2;i<=n/2;i++){
			p=n%i;
			if(p==0)
				prime=false;
		}
	}
	return prime;
}
	

bool isperf(int num){
	
	int i,sq;
	bool perf=false;
	if((num>=1)&&(num<=100)){
	for(i=1;i<=num;i++){
		sq=i*i;
		if(sq==num)
		perf=true;
	}
	return perf;
}
}

bool issphenic(int num){
	if((num>=1)&&(num<=100)){
		int x;
		int count=0;
		bool shp=false;
		for(x=1;x<=num;x++){
			bool s=isprime(x);
			if(s==true){
			
				if((num%x)==0)
					count++;
				}
		}
		
		cout << endl;
		
		if(count==3)
			shp=true;
		return shp;
	}
	}
	void binary(int num){
		int bin[8];
		int v;
		int x,y,rem;
		
		if((num>=1)&&(num<=100)){
		
		for(x=0;x<=7;x++){
		
			v=num%2;
			rem=num-v;
			num=rem/2;
			bin[x]=v;
		}
		cout<<" \t  ";
		for(x=7;x>=0;x--)
		cout<<bin[x];
	}
	}
int main(){	
int binn;
ifstream in;
in.open("numbers.txt");
int numz[1000];
bool perf,prime,perfsq,sphenic;
int bin[8];
int x,z;
int y=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0;
int ten=0,twent=0,thirty=0,forty=0,fifty=0,sixty=0,seventy=0,eight=0,nine=0,hun=0;
int valid=0;
int invalid=0;
int total=0;
int nonum=0;
int num;
int inv[100];
int invals;
int nums[1000];
int newinvalid=0;
in>>num;
cout<<"Number Perfect \t Prime \t Perfect square  Sphenic  Binary (ignore the right-most digit) "<<endl;
while(num!=-1){
	if((num>0) && (num <=100 )){
	nums[valid]= num;
	perf=perfect(num);
  	prime=isprime(num);
	perfsq=isperf(num);
	sphenic=issphenic(num);
	valid++;

cout<< num <<"\t";

if(perf==true){
cout<<"Y ";
}
else{
	cout<<"N ";
}

if(prime==true){
	cout<<"\t Y ";
}

else{
	cout<<"\t N";
}
if(perfsq==true){
	cout<<"\t Y ";
}

else{
	cout<<"\t N";
}

if(sphenic==true){
	cout<<"\t \t Y ";
}

else{
	cout<<"\t \t N";
}

binary(num);
 cout<<"    ";
}
		
 if((num<0) || (num >100)){
 	numz[invalid]=num;
	invalid++;	
}
if(num==0){
nonum++;
}
total++;

if(num>=1 && num<=10){
	ten++;
}
if(num>=11 && num<=20){
	twent++;

}
if(num>=21 && num<=30){
	thirty++;
	
}
if(num>=31 && num<=40){
	forty++;

}
if(num>=41 && num<=50){
fifty++;

}
if(num>=51 && num<=60){
	sixty++;
	
}
if(num>=61 && num<=70){
seventy++;
	
}

if((num>=71) && (num<=80)){
	eight++;
	
}

if(num>=81 && num<=90){
	nine++;
	
}

if(num>=91 && num<=100){
	hun++;

}

in>>num;	
}
			cout<<endl;
			for(x=0;x<invalid;x++){
				cout<<numz[x]<<" ";
				if((x%5)==0)
				cout<<endl;
			}
			cout<<endl;
			cout<<" Range 1-10: ";
			for(x=1;x<=ten;x++){
				if(x%5==0) 
				y++;
			}
				for(z=1;z<=y;z++){
				
				cout<<"*";
				if(z%5==0)
				cout<<endl;
			
			}
			cout<<endl;

			cout<<" Range 11-20: ";
			for(x=1;x<=twent;x++){
				if(x%5==0)
				a++;
			}
				for(z=1;z<=a;z++){
				
				cout<<"*";
				if(z%5==0)
				cout<<endl;
			}
				
			
			cout<<endl;

			cout<<" Range 21-30: ";
			for(x=1;x<=thirty;x++){
				if(x%5==0)
				b++;
			}
				for(z=1;z<=b;z++){
				
				cout<<"*";
				if(z%5==0)
				cout<<endl;
			
			}
			cout<<endl;

			cout<<" Range 31-40: ";
			for(x=1;x<=forty;x++){
				if(x%5==0)
					c++;
				}
				for(z=1;z<=c;z++){
				
				cout<<"*";
				if(z%5==0)
				cout<<endl;
			
			}
			cout<<endl;

			cout<<" Range 41-50: ";
			for(x=1;x<=fifty;x++){
				if(x%5==0)
					d++;
				}
				for(z=1;z<=d;z++){
				
				cout<<"*";
				if(z%5==0)
				cout<<endl;
			}
			
			cout<<endl;

			cout<<" Range 51-60: ";
			for(x=1;x<=sixty;x++){
				if(x%5==0)
					e++;
				}
				for(z=1;z<=e;z++){
				
				cout<<"*";
				if(z%5==0)
				cout<<endl;
			}
			
			cout<<endl;

			 
			cout<<" Range 61-70: ";
			for(x=1;x<=seventy;x++){
				if(x%5==0)
				f++;
			}
				for(z=1;z<=f;z++){
				
				cout<<"*";
				if(z%5==0)
				cout<<endl;
			}
			
			cout<<endl;

			 
			cout<<" Range 71-80: ";
			for(x=1;x<=eight;x++){
				if(x%5==0)
					g++;
				}
				for(z=1;z<=g;z++){
				
				cout<<"*";
				if(z%5==0)
				cout<<endl;
			}
			
			cout<<endl;

			
			cout<<" Range 81-90: ";
			for(x=1;x<=nine;x++){
				if(x%5==0)
					h++;
				}
				for(z=1;z<=h;z++){
				
				cout<<"*";
				if(z%5==0)
				cout<<endl;
			}
			
			cout<<endl;

			 
			cout<<" Range 91-100: ";
			for(x=1;x<=hun;x++){
				if(x%5==0)
					i++;
				}
				for(z=1;z<=i;z++){
				
				cout<<"*";
				if(z%5==0)
				cout<<endl;
			}
			cout<<endl;
			


cout<<"amount of students who chose valid numbers: "<<valid<<endl;
cout<<"amount of students who chose invalid numbers: "<<invalid<<endl;
cout<<"amount of students who chose not to reveal their number: "<<nonum<<endl;
int u,o,mostt=0,mostnum;
	int countt=0,leastt=0;
	int least[100];
for(u=1;u<valid;u++){

	for(o=1;o<valid;o++){
		if (nums[o]==u) 
		countt++;
		if(countt>mostt){
			mostt=countt;
			mostnum=u;
		}	
	}
	if(countt==1){
		leastt++;
		least[leastt]=u;
	}
}
if(mostt>1){
	cout<<"Number chosen most by students: "<<mostt<<endl;
}
if(leastt>=1){
	cout<<"Number chosen least by students: "<<	leastt;
}
in.close();
return 0;
}

 
