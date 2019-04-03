#include<iostream>
#include<fstream>
using namespace std;

//FUNCTION LIST STARTS

//1
void isPerfect (int x){
	int sum=0, i;
	for (i=1; i<x; i=i+1){
		if(x%i==0){
			sum=sum+i;
		}
	}
	if (sum==x)
		cout<<"Y";
	else 
	cout<<"N";
	}
//2
bool isPrime (int x){
	int i;
	bool prime;
	for (i=2; i<=x/2; i++){
		if (x%i==0){
		return false;
		} 
	}
	return true;
}

//3
char PerfSq(int x){
	int sq;
	int halfx;
	char Perf='N';
	halfx=(x/2);
	
	for(int i=1; i<=halfx; i++){
		sq=i*i;
		if(sq==x){
		Perf='Y';
		return Perf;
	}
}
	 return Perf;
}


//4
void isSphenic(int n){
	int i, count=0, prod=1;
	for (i=2; i<=n/2; i++){
		
		if( n%i==0 && isPrime(i)==true){
			prod=prod*i;
			count=count+1;
		}
}
	if(count==3 && prod==n)
	cout<<"Y";
	else
	cout<<"N";
}


//5
void calBinary (int x){
	int i, binarr[8];
	for (i=0; i<8; i++){
		binarr[i]=0;
	}
	for(i=7; i>=0; i=i-1){
		if (x>0){
		binarr[i]=x%2;
		x=x/2;
	}
	}
	for(i=0; i<8; i++)
		cout<<binarr[i];
}
//6
void DispInvalid (){
	int i=0, n;
	ifstream in;
	in.open("numbers.txt");
	in>>n;
	while(n!=-1){
	
	if (n<=-2 || n>100){
		cout<<n<<" ";
		i=i+1;
		if(i%5==0){
			cout<<endl;
		}
		in>>n;}
	else 
	in>>n;
}
}
//7
int NumInvalid (){
	ifstream in;
	in.open("numbers.txt");
	int n,i;
	i=0;
	in>>n;
		while(n!=-1){
	
	if (n<=-2 || n>100){
		i=i+1;
	}
		in>>n;
}
	return i;
}

//8
int NotRevealed (){
	ifstream in;
	in.open("numbers.txt");
	int n, zerocount;
	zerocount=0;
	in>>n;
	while(n!=-1){
	
	if (n==0){
	zerocount=zerocount+1;
	in>>n;
}

	in>>n;
}
return zerocount;
}
// star
void outStar (int x){
	int i, div;
	if (x>=5){
		div=x/5;
		for(i=1;i<=div;i++)
		cout<<"*";
	}
	
}
//9
void DispStar(){
	ifstream in;
	in.open("numbers.txt");
	
	int i, n, range[10];
	
	for(i=0; i<10; i++)
		range[i]=0;
	in>>n;
	while (n!=-1){
		
		if(n>=1 && n<=10){
			range[0]=range[0]+1;
			in>>n;}
		else if(n>=11 && n<=20){
			range[1]=range[1]+1;
			in>>n;}
		else if(n>=21 && n<=30){
			range[2]=range[2]+1;
			in>>n;}
		else if(n>=31 && n<=40){
			range[3]=range[3]+1;
			in>>n;}
		else if(n>=41 && n<=50){
			range[4]=range[4]+1;
			in>>n;}
		else if(n>=51 && n<=60){
			range[5]=range[5]+1;
			in>>n;}			
		else if(n>=61 && n<=70){
			range[6]=range[6]+1;
			in>>n;}
		else if(n>=71 && n<=80){
			range[7]=range[7]+1;
			in>>n;}
		else if(n>=81 && n<=90){
			range[8]=range[8]+1;
			in>>n;}
		else if(n>=91 && n<=100){
			range[9]=range[9]+1;
			in>>n;}
		else 
		in>>n;
	}
	cout<<"RANGE | HISTOGRAM"<<endl;
cout<<"======|=========================================="<<endl;
cout<<"1-10  | ";
outStar(range[0]);
cout<<endl<<"11-10 | ";
outStar(range[1]);
cout<<endl<<"21-10 | ";
outStar(range[2]);
cout<<endl<<"31-10 | ";
outStar(range[3]);
cout<<endl<<"41-10 | ";
outStar(range[4]);
cout<<endl<<"51-10 | ";
outStar(range[5]);
cout<<endl<<"61-10 | ";
outStar(range[6]);
cout<<endl<<"71-10 | ";
outStar(range[7]);
cout<<endl<<"81-10 | ";
outStar(range[8]);
cout<<endl<<"91-100| ";
outStar(range[9]);
cout<<endl;
}


void maxNum(int numarr[]){
	int maxn=2;
	for(int i=0;i<100;i++){
		if(numarr[i]>= maxn)
			maxn=numarr[i];
	}
	for(int i=0;i<100;i++){
		if(numarr[i]==maxn)
	cout<<i+1<<"\t";
}
}
//11
void minNum(int numarr[]){
	int minn=999999, minnactual=0;
	for(int i=0;i<100;i++){
		if(numarr[i]<=minn && numarr[i]>=1)
			minn=numarr[i];
	}
	for(int i=0;i<100;i++){
		if(numarr[i]==minn)
		cout<<i+1<<"\t";
	}
}


		
//FUNCTION LIST ENDS

int main (){
	int n, i, validcount, binary, invalidcount, unspec, range[10], numarr[100];
	bool prime;
	char perf;
	validcount=0;
	ifstream in;
	in.open("numbers.txt");
	if (!in.is_open()){
		cout<<"Program Aborted...Files Not Open!!!";
		return 0;
	}
	cout<<"Number"<<"\t"<<"Perfect"<<"\t"<<"Prime"<<"\t"<<"Perfect Square"<<"\t"<<"Sphenic"<<"\t"<<"Binary Equivalent"<<endl;
	cout<<"******"<<"\t"<<"*******"<<"\t"<<"*****"<<"\t"<<"**************"<<"\t"<<"*******"<<"\t"<<"*****************"<<endl;
	i=0;
	for(i=0;i<100;i++){
		numarr[i]=0;
	}
	in>>n;

	while (n!=-1){
		if(n>=1 && n <=100){
		numarr[n-1]=numarr[n-1]+1;
		validcount=validcount+1;}
		in>>n;
		}
		for(i=0; i<100; i++){
			if(numarr[i]!=0){
		cout<<i+1<<"\t";
		isPerfect(i+1);
		cout<<"\t";
		prime=isPrime(i+1);
		if (prime==true)
			cout<<"Y";
		
		else 
		cout<<"N";  
		cout<<"\t";
		perf=PerfSq(i+1);
		cout<<perf<<"\t"<<"\t";
		isSphenic(i+1);
		cout<<"\t";
		calBinary(i+1);		
		cout<<endl;
			}
		}	
	

cout<<"************************************************************************************************************************"<<endl;
cout<<"************************************************************************************************************************"<<endl;

//PART C STARTS HERE
cout<<"The invalid numbers five per line are: "<<endl;
DispInvalid();

cout<<endl;
cout<<"************************************************************************************************************************"<<endl;
cout<<"************************************************************************************************************************"<<endl;

//PART D STARTS HERE
DispStar();
cout<<endl;

//PART E STARTS HERE
cout<<"************************************************************************************************************************"<<endl;
cout<<"************************************************************************************************************************"<<endl;


cout<<"Number of students who chose a valid favorite number: "<<validcount<<endl;
invalidcount=NumInvalid();
cout<<"Number of students who chose an invalid favorite number: "<<invalidcount<<endl;
unspec= NotRevealed ();
cout<<"Number of students who did not reveal favorite number: "<<unspec<<endl;
cout<<"Number that was chosen the most is/are: "<<endl;
maxNum(numarr);
cout<<endl<<"Number that was chosen the least is/are: "<<endl;
minNum(numarr);
cout<<endl;

return 0;
}

