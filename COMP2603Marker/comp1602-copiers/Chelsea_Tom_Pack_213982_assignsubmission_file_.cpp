#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

bool isPerfect(int num){
	int sum, i;
	for(i=1; i<= num/2; i++){
		if(num%i==0)
		sum+=i;
	}
	if(sum==num && num !=1)
	return true;
	else 
	return false;
}


bool isPrime(int num){
	int i;
	for(i=2; i<=num/2; i++){
		if(num%i != 0)
		return true;
		else
		return false;
	}
}




bool isPerfectSquare(int num){
	
	int square, i;
	for(i=1; i<=num/2; i++){
		square= i*i;
		if(square==num)
		
		return true;
		
	}
	
	return false;
	
}

bool isSphenic(int num){
	int i, j=0, product=1;
	
	
	for(i=2; i<=num/2; i++){
		if(num%i==0 && isPrime(i)){
			product= product*i;
			j++;
			
		}
	}
	if(j==3 && product==num)
	return true;
	else 
	return false;
}
void Binary(int num){
	int binumbers[100];
	
	int a, j;
	int i=0;
	
	
	while(num>0){
		binumbers[i]= num%2;
		num= num/2;
		i++;
	}
	for(a=8; a>i; a--){
		cout<<"0";
		
	}
	for(j= i-1; j>=0; j--)
	cout<< binumbers[j];
}
void stars(int num){
	int i;
	for(i=0; i<num; i++)
	cout<<"*";
	cout<<endl;
	
}
int main(){
	bool a, b, c, num, d, e;
	int arr[10];
	int j, g=1, k=0, t, count=0, i;
	
	int invalid[999];
	int valid[999];
	int zero[999];
	int invalidcount;
	int n;
	int histogram[10];
	int validcount[101];
	
	ifstream in;
	in.open("numbers.txt");
		if(!in.is_open()){
			cout<<"Error opening input file";
			return 0;
		}
		
		
		
		
cout<<"Number\tPerfect?\tPrime?\tPerfect Sqare?\tSphenic?\t\tBinary Equiv."<<endl;
cout<<"======\t========\t======\t==============\t========\t\t============="<<endl;
cout<<endl;

for(e=1; e<=100; e++){
	validcount[e]=0;
}


in>>n;
while(n !=-1){
	if(n>=1 && n<=100){
		
		valid[k]=n;
		
		k++;
		
		validcount[n]++;
		
		cout<<n<<"\t";
		
		

	a= isPerfect(n);
	if(a==true)
	cout<<"Y\t";
	else
	cout<<"N\t";

	c= isPrime(n);
	if(c==true)
	cout<<"Y\t";
	else
	cout<<"N\t";

	i= isPerfectSquare(n);
	if(i==true)
	cout<<"Y\t";
	else
	cout<<"N\t";

	d=isSphenic;
	if(d==true)
	cout<<"Y\t";
	else
	cout<<"N\t";

	Binary(n);
	cout<<endl;
	}
else
if(n==0){
	zero[t]=n;
	t++;
		
}
else{
	invalid[g]=n;
	g++;
		
}


	if(n>=1 && n<=10){
		histogram[0]++;
	}	
	if(n>=11 && n<=20){
		histogram[1]++;
	}
	if(n>=21 && n<=30){
		histogram[2]++;
	}
	if(n>=31 && n<=40){
		histogram[3]++;
	}
	if(n>=41 && n<=50){
		histogram[4]++;
	}
	if(n>=51 && n<=60){
		histogram[5]++;
	}
	if(n>=61 && n<=70){
		histogram[6]++;
	}
	if(n>=71 && n<=80){
		histogram[7]++;
	}
	if(n>=81 && n<=90){
		histogram[8]++;
	}
	if(n>=91 && n<=100){
		histogram[9]++;
	}
	
	in>>n;
	
}
cout<<"The invalid numbers from students: "<<endl;
for(d=1; d<g; d++){
	cout<<invalid[d]<<"\t";
	if(d%5==0){
		cout<<endl;
		
	}
}
cout<<endl;
cout<<endl;

cout<<"Range  \t  Histogram"<<endl;
cout<<"======================================="<<endl;

cout<<"1-10  \t  ";
histogram[0]=histogram[0]/5;
stars(histogram[0]);

cout<<"11-20  \t  ";
histogram[1]=histogram[1]/5;
stars(histogram[1]);

cout<<"21-30  \t  ";
histogram[2]=histogram[2]/5;
stars(histogram[2]);

cout<<"31-40  \t  ";
histogram[3]=histogram[3]/5;
stars(histogram[3]);

cout<<"41-50  \t  ";
histogram[4]=histogram[4]/5;
stars(histogram[4]);

cout<<"51-60  \t  ";
histogram[5]=histogram[5]/5;
stars(histogram[5]);

cout<<"61-70  \t  ";
histogram[6]=histogram[6]/5;
stars(histogram[6]);

cout<<"71-80  \t  ";
histogram[7]=histogram[7]/5;
stars(histogram[7]);

cout<<"81-90  \t  ";
histogram[8]=histogram[8]/5;
stars(histogram[8]);

cout<<"91-100  \t  ";
histogram[9]=histogram[9]/5;
stars(histogram[9]);

cout<<endl;
cout<<endl;

cout<<"Statistical information:"<<endl;
cout<<"The amount of sudents who specified valid favourite numbers: "<<k<<endl;
cout<<"The amount of students who specified invalid favourite numbers: "<<g<<endl;
cout<<"The amount of students who did not reveal their favourite numbers: "<<t<<endl;
cout<<endl;

int max=validcount[1];
int min=1;
cout<<"The number/s that was/were chosen the most by the students: "<<endl;
cout<<endl;

for(int r=1; r<=100; r++){
	if(validcount[r]>max){
		max=validcount[r];
	}
}
for(int r=1; r<100; r++){
	if(validcount[r]==max){
		cout<<r<<"\t";
	}
}
cout<<endl;
cout<<endl;

cout<<"The number/s that was/were chosen the least by the students: "<<endl;
cout<<endl;

for(int r=1; r<=100; r++){
	if(validcount[r]<min && validcount[r]>0){
		min=validcount[r];
	}
}
for(int r=1; r<100; r++){
	if(validcount[r]==min){
		cout<<r<<"\t";
	}
}
cout<<endl;
cout<<endl;

in.close();
return 0;
}
