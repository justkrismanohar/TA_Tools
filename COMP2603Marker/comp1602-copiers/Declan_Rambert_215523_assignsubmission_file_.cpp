#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

	//Functions
void numPerfect(int num){
int sum,i=0;
for(i=1;i<num;i++){
if(num%i == 0){
	sum = sum + i;
}
}
if (sum == num)
cout<<"Y";
else
cout<<"N";
}

bool numPrime(int num){
int i,sum=0;
for(i=2;i<num;i++){
if(num%i == 0){
	sum = sum + i;
}
}
if (sum == 0)
return true;
else
return false;
}

void numSquare(int num){
	if(num==1||num==4||num==9||num==16||num==25||num==36||num==49||num==64||num==81||num==100)
	cout<<"Y";
	else
	cout<<"N";
}

bool numSphenic(int num){
	if(num==30||num==42||num==66||num==70||num==78)
return true;
else
return false;
}

void numBin (int n) {
{
	
		 }		 int binaryNum[1000];
		  int i = 0; 
    while (n > 0) {
    	 binaryNum[i] = n % 2; 
        n = n / 2; 
        i++;
	}
	    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j];
}

void stars(int n){
	for(int i=1;i<=n;i++){
		cout<<"*";
	}
}
    //main
int main(){
	int invalid[1000],hist[1000],a,l,numValid,numInvalid,numNonum,numCount[1000],numFav[1000];
	float num;
	l=numValid=numInvalid=numNonum=0;
	bool prime ,sphenic;
	 
	 //Initialize arrays
	 for(a=0;a<1000;a++){
	 	hist[a]=0;
	 	invalid[a]=0;
	 	numFav[a];

	 }

	//File
ifstream Inputfile;
Inputfile.open("numbers.txt");
if(!Inputfile.is_open()){
	cout<<"File not file. Aborting.....";
}

	cout<<left<<setw(15)<<"Number";
	cout<<left<<setw(15)<<"Perfect?";
	cout<<left<<setw(15)<<"Prime?";
	cout<<left<<setw(15)<<"Perfect Square";
	cout<<left<<setw(15)<<"Sphenic?";
	cout<<right<<setw(15)<<"Binary Equiv.";
	cout<<endl;
	cout<<"________________________________________________________________________________________________"<<endl;
	cout<<endl;

	//while loop
	Inputfile>>num;
while (num != -1){
	

		
	//valid nums
	if(num>0 && num<101){
		numValid=numValid+1;
			
		
cout<<left<<setw(15)<<num;
cout<<left<<setw(15);
numPerfect(num);
cout<<left<<setw(15);

prime=numPrime(num);
if(prime == true){
	cout<<"Y";
}
else{
	cout<<"N";
}
cout<<left<<setw(15);


numSquare(num);
cout<<left<<setw(15);


sphenic = numSphenic(num);
if(sphenic == true){
	cout<<"Y";
}
else{
	cout<<"N";
}
cout<<right<<setw(15);

numBin(num);
cout<<left<<setw(15);
cout<<endl;

			if(num<=10 && num<=1){
			hist[1]=hist[1]+1;}
			
			if(num<=20 && num>=11){
			hist[2]=hist[2]+1;}	
			
			if(num>=21 && num<=30){
			hist[3]=hist[3]+1;}
				
			if(num>=31 && num<=40){
			hist[4]=hist[4]+1;}
			
			if(num>=41 && num<=50){
			hist[5]=hist[5]+1;}	
			
			if(num>=51 && num<=60){
			hist[6]=hist[6]+1;}
			
			if(num>=61 && num<=70){
			hist[7]=hist[7]+1;}
			
			if(num>=71 && num<=80){
			hist[8]=hist[8]+1;}
			
			if(num>=81 && num<=90){
			hist[9]=hist[9]+1;}	
			
			if(num>=91 && num<=100){
			hist[10]=hist[10]+1;}

}




//Invalid nums
	if(num<0 || num>100){
		invalid[l]=num;
		l++;
	numInvalid=numInvalid+1;
		}
		
		
//Nonums
if(num==0){
	numNonum=numNonum+1;
}


		Inputfile>>num;
}

//Listing Invalid nums
cout<<endl;
cout<<"Invalid Numbers:";
cout<<endl;
	cout<<invalid[0]<<",";
for(int s=1;s<1000;s++){
	if((invalid[s]!=0) && (s%5!=0)){
cout<<invalid[s]<<",";	
	}
	else{
		if((s%5==0) && (invalid[s]!=0)) {
			cout<<endl;
			cout<<invalid[s]<<",";
		}
	}
}

//Histogram stuff
cout<<endl;
cout<<endl;
cout<<left<<setw(15)<<"Range";
cout<<left<<setw(15)<<"Histogram";
cout<<endl;
cout<<"=====================================";
cout<<endl;
cout<<left<<setw(15)<<"1-10";
stars(hist[1]);
cout<<endl;
cout<<left<<setw(15)<<"11-20";
stars(hist[2]);
cout<<endl;
cout<<left<<setw(15)<<"21-30";
stars(hist[3]);
cout<<endl;
cout<<left<<setw(15)<<"31-40";
stars(hist[4]);
cout<<endl;
cout<<left<<setw(15)<<"41-50";
stars(hist[5]);
cout<<endl;
cout<<left<<setw(15)<<"51-60";
stars(hist[6]);
cout<<endl;
cout<<left<<setw(15)<<"61-70";
stars(hist[7]);
cout<<endl;
cout<<left<<setw(15)<<"71-80";
stars(hist[8]);
cout<<endl;
cout<<left<<setw(15)<<"81-90";
stars(hist[9]);
cout<<endl;
cout<<left<<setw(15)<<"91-100";
stars(hist[10]);
cout<<endl;
cout<<endl;

cout<<"No. of students who gave Valid numbers= "<<numValid<<endl;
cout<<"No. of students who gave Invalid numbers= "<<numInvalid<<endl;
cout<<"No. of students who did not give a number= "<<numNonum<<endl;
cout<<endl;
cout<<endl;

int numMax=numFav[1];
int numMin=1;
cout<<"No./Nos. choosen the most by the students: ";
for(int s=1;s<=100;s++){
	if(numFav[s]>numMax){
		numMax=numFav[s];
	}
}

for (int s=1;s<100;s++){
	if(numFav[s]==numMax){
		cout<<s<<"  ";
	}
}
cout<<endl;
cout<<"No./Nos. choosen the least be the students: ";
for(int t=1;t<=100;t++){
	if (numFav[t]<numMin && numFav[t]>0){
		numMin=numFav[t];
	}
}

for (int y=1;y<100;y++){
	if(numFav[y]==numMin){
		cout<<y<<"  ";
	}
}

Inputfile.close();
return 0;
}
