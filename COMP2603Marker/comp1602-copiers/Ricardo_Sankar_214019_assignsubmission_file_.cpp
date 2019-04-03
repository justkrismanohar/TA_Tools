#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


bool Perfect(int x) {
int i;
int sum=0;
int num=x;
for(i=1; i<num; i++){
	if(num%1==0){
		return true;
	}
	else 
	return false;
	}
}


bool Prime (int x){
	int i;
	int prime;
	for(i=2; i<=x/2; i++){
		prime=x%i;
		if(prime==0)
		return false;
	}
	return true;
}


bool PerfectSquare(int x){
	int square=1;
	float i=1;
	for(int i=1; i<=x; i++){
		square=i*i;
		if(square=x){
			return true;
		}
		}
		return false;
	}
	
	
	
	
	bool Sphenic(int x){
		int i;
		int count=0;
		int prod=1;
		for(i=2; i<=x/2; i++){
			if(x%i==0 && Prime(i)){
				prod=prod*i;
				count++;
			}
		}
		if(count==3 && prod==x)
		return true;
		return false;	
		}
	
	
	
	int Binary (int x){
		int n=x;
		int i;
		int bits[7];
		
		for(i=0; i<=7; i++){
			bits[i]=0;
		}
		
		for(i=0; n>0; i++){
			bits[i]=n%2;
			n=n/2;
		}
	}

int main () {
	
	ifstream in;
	
	in.open("numbers.txt");
	if(!in.is_open()){
		cout<<"File not found.. Terminating program"<<endl;
		return 0;
	}
	
int x,z;
int invals;
int num;
bool perfect,prime,perfsq,sphenic;
int bin[8];
int numz[1000];
int nums[1000];
int inv[100];
int valid=0;
int invalid=0;
int total=0;
int nonum=0;
int newinvalid=0;
int y=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0;
int ten=0,twenty=0,thirty=0,forty=0,fifty=0,sixty=0,seventy=0,eighty=0,ninety=0,hundred=0;
	
in>>num;
	cout<<"Number"<<"\t"<<"Perfect"<<"\t"<<"Prime"<<"\t"<<"Perfect Square"<<"\t"<<"Sphenic"<<"\t"<<"Binary"<<endl;
	cout<<"======================================================"<<endl;

while(num!=-1){
	if((num>0) && (num <=100 )){
	nums[valid]= num;
	perfect=Perfect(num);
  	prime=Prime(num);
	perfsq=PerfectSquare(num);
	sphenic=Sphenic(num);
	valid++;

cout<<num<<"\t";

if(perfect==true){
cout<<"Y ";
}
else{
	cout<<"N ";
}

if(prime==true){
	cout<<" Y ";
}

else{
	cout<<" N";
}
if(perfsq==true){
	cout<<" Y ";
}

else{
	cout<<" N";
}

if(sphenic==true){
	cout<<" Y ";
}

else{
	cout<<" N ";
}

Binary(num);
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
	twenty++;
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
	eighty++;
	}

if(num>=81 && num<=90){
	ninety++;
}

if(num>=91 && num<=100){
	hundred++;
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
			for(x=1;x<=twenty;x++){
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
			for(x=1;x<=eighty;x++){
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
			for(x=1;x<=ninety;x++){
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
			for(x=1;x<=hundred;x++){
				if(x%5==0)
					i++;
				}
				for(z=1;z<=i;z++){
				cout<<"*";
				if(z%5==0)
				cout<<endl;
			}
			cout<<endl;
			


cout<<"Number of students who chose valid numbers: "<<valid<<endl;
cout<<"Number of students who chose invalid numbers: "<<invalid<<endl;
cout<<"Number of students who chose to not reveal their number: "<<nonum<<endl;
int k,p,most=0,mostnum;
	int count=0,least1=0;
	int least[100];
for(k=1;k<valid;k++){

	for(p=1;p<valid;p++){
		if (nums[p]==k) 
		count++;
		if(count>most){
			most=count;
			mostnum=k;
		}	
	}
	if(count==1){
		least1++;
		least[least1]=k;
	}
}

if(most>1){
	cout<<"Number chosen most by students: "<<most<<endl;
}

if(least1>=1){
	cout<<"Number chosen least by students: "<<	least1;
}

in.close();
return 0;
}

	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

