#include<iostream>
#include<fstream>
using namespace std;

//perfect number
bool isperfect(int n){
	int mod;
	int sum=1;
	if(n>-1){
		for(int k=2;k<=n/2;k=k+1){
			mod=n%k;
			if(mod==0){
				sum=sum+k;
			}
		}
		if(sum==n){
			return true;
		}
		return false;
	}
	
}

//perfect square
bool isperfectsquare(int n){
	int mod,square;
	for(int k=1;k<=n/2;k=k+1){
		mod=n%k;
		square=k*k;
		if(mod==0&&square==n){
			return true;
		}
		
	}
	return false;
}

//prime number
bool isprime(int n){
	int mod;
	for(int k=2;k<=2;k=k+1){
		mod=n%k;
		if(mod==0){
			return false;
		}
	}
	return true;
}

//sphenic number
bool issphenic(int n){
	int count=0;
	int prod=1;
	int mod;
	for(int k=2;k<n/2;k=k+1){
		mod=n%k;
		if(mod==0&&isprime(k)){
			prod=prod*k;
			count=count+1;
			if(prod==n&&count==3){
				return true;
			}
			else{
			 return false;
			 }
		}
		
	}
	
}

void binary(int n){
	int divide;
	int mod;
	int run=0;
	int binary[9];
	
	
	divide=n/2;
	mod=n%2;
	while(divide!=0){
		binary[run]=mod;
		run=run+1;
		divide=divide/2;
		mod=divide%2;
	}
	for(int i=run;i>=0;i=i-1){
		cout<<binary[i];
	}
	
	
	
}

//void histogram stars
void star(int n){
	for(int i=1;i<=n;i=i+1){
		if(i%5==0){
			cout<<"*";
		}
	}
}

int main(){
	ifstream inputfile;
	int num,bineqi;
	int r1=0;
	int r2=0;
	int r3=0;
	int r4=0;
	int r5=0;
	int r6=0;
	int r7=0;
	int r8=0;
	int r9=0;
	int r10=0;
	int valid=0;
	int invalid=0;
	int noresponse=0;
	int histogram[10];
	int inv[600];
	
	inputfile.open("numbers.txt");
	if(!inputfile.is_open()){
	cout<<"Error opening the file. Aborting...";
	return 0;
}




cout<<"Number      Perfect?      Prime?      Perfect Square?     Sphenic?    Binary Equivalent "<<endl;
cout<<"=============================================================================================="<<endl;
inputfile>>num;
while(num!=-1){
	if(num>=1&&num<=100){
		cout<<num;
		cout<<"  ";
		valid=valid+1;
		if(isperfect(num)){
			cout<<"Y  ";
			
		}
		cout<<"N  ";
		
	
	if(isprime(num)){
		cout<<"Y  ";
		

	}
	cout<<"N   ";
	
	
	if(issphenic(num)){
		cout<<"Y   ";
		
	
	}
	cout<<"N   ";
	
	
	
	
	binary(num);
	cout<<endl;
	
	
	

}


//histogram totals
if((num>=1)&&(num<=10)){
	r1=r1+1;
	histogram[0]=r1;
	}
if((num>=11)&&(num<=20)){
	r2=r2+1;
	histogram[1]=r2;
	}
if((num>=21)&&(num<=30)){
	r3=r3+1;
	histogram[2]=r3;
	}
if((num>=31)&&(num<=40)){
	r4=r4+1;
	histogram[3]=r4;
	}
if((num>=41)&&(num<=50)){
	r5=r5+1;
	histogram[4]=r5;
	}
if((num>=51)&&(num<=60)){
	r6=r6+1;
	histogram[5]=r6;
	}
if((num>=61)&&(num<=70)){
	r7=r7+1;
	histogram[6]=r7;
	}
if((num>=71)&&(num<=80)){
	r8=r8+1;
	histogram[7]=r8;
	}
if((num>=81)&&(num<=90)){
	r9=r9+1;
	histogram[8]=r8;
	}
if((num>=91)&&(num<=100)){
	r10=r10+1;
	histogram[9]=r10;
	}
	
if(num==0){
	noresponse=noresponse+1;
}

if((num<0)||(num>100)){
    inv[invalid]=num;
	invalid=invalid+1;
}


inputfile>>num;
	

}

inputfile.close();


cout<<endl;
cout<<endl;


//printing invalid numbers.
cout<<"Invalid Numbers."<<endl;
for(int i=1;i<=invalid;i=i+1){
	cout<<inv[i]<<"   ";
	if(i%5==0){
		cout<<endl;
	}
}


cout<<endl;
cout<<endl;


//printing histogram
cout<<"Range     Histogram"<<endl;
cout<<"==================="<<endl;

int beginning=1;
int final=10;
for(int i=0;i<10;i=i+1){
	cout<<beginning<<"-"<<final;
	cout<<"       ";
	star(histogram[i]);
	cout<<endl;
	beginning=beginning+10;
	final=final+10;
}


//checking the most and least favourite
int numbers[101];
for(int k=0;k<101;k=k+1){
	numbers[k]=0;
}

int max=1;
int min=110;
int votes[1000];
int mostvotes;
int i=0;
int leastvotes;

inputfile.open("numbers.txt");
if(!inputfile.is_open()){
	cout<<"Error opening the input file. Aborting...";
	return 0;
}

inputfile>>num;
while(num!=-1){
	votes[i]=num;
	i=i+1;
	inputfile>>num;	
	}
	inputfile.close();
	
	
	for(int j=0;j<i;j=j+1){
	
	for(int k=1;k<101;k=k+1){
		if(votes[j]==k){
			numbers[k]=numbers[k]+1;
			
		}
		
			
		}
	}
		
		for(int most=1;most<101;most=most+1){
			if(numbers[most]>max){
				max=numbers[most];
				mostvotes=most;
			}
			if(numbers[most]<min){
				min=numbers[most];
				leastvotes=most;
			}
		}
		
		
		cout<<"The amount of valid favourite numbers: "<<valid<<endl;
		cout<<"The amount of invalid favourite numbers: "<<invalid<<endl;
		cout<<"The amount of students that gave no response: "<<noresponse<<endl;
		cout<<"The number that was chosen the most: "<<mostvotes<<" with a total of "<<max<<" votes."<<endl;
		cout<<"The number that was chosen the least: "<<leastvotes<<" with a total of "<<min<<" votes."<<endl;
		return 0;



}


