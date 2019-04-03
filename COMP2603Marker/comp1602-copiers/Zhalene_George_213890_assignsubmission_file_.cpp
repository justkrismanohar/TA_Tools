#include<iostream>
#include<fstream>
using namespace std;

// Function 1
 char isperfect(int a){
	
	int i=0;
	int sum=0;
	for(i=1;i<a;i=i+1){
	
	if(a%i==0)
	sum=sum+i;
}
  if(sum==a)
return 'Y';
else
return'N';
 


}
//Function used in sphenic function
bool isprime(int x){

int i;
int count =0;
 for (i=1;i<=x;i=i+1){
 	if(x%i==0){
	 
 	count = count +1;
}
 }
 
if(count==2)
  return true;

  return false;
}


//Function 2

char isprime1(int b){

int i;
int count =0;
 for (i=1;i<=b;i=i+1){
 	if(b%i==0){
	 
 	count = count +1;
}
 }
 
if(count==2)
  return'Y';
else 
  return'N';
}

// Function 3
char isperfectsqu(int c) {
 int i;
 int sqr;
 

 for (i=1;i<=c/2;i=i+1){
 
 	sqr=i*i;
 	
 if(sqr==c)
 
return'Y';
}
return'N';
}
//fuction 4
char issphenic(int d) {
int i;
int v=0;
int prod=1;

prod=1;
for(i=2;i<=d/2;i=i+1){

if(d%i==0&&isprime(i)){
	prod=prod*i;
		v=v+1;
	}
}

	

if(v==3&&prod==d)
return 'Y';
else
return 'N';

}
//Function 5
void isbinary(int e){

	int a[10], i;    
   
for(i=0; e>0; i++){
   
a[i]=e%2;    
e= e/2;  
}    
 
for(i=i-1 ;i>=0 ;i--) {

   
cout <<a[i]; 
}
}  
void star(int f){

int i;
for(i=0;i<f;i=i+1)

cout<<"*";
cout<<endl;

}

int main () {

int num=0;
int u=0;
int k=0;
int i=0;
int j=0;
int nof=0;
int val=0;
int inval=0;
int invals[9]={0};
int fnum[101]={0};
int max=fnum[1];
int min=1;
int t;
int histo[10]={0};
 
ifstream in;
  in.open("numbers.txt");
	
	if (!in.is_open()) {
 cout << "Error opening input file. Aborting ...";
 return 0;
 } 
cout<<"Numbers" <<"  "<<"Perfect?"<<"   "<<"Prime?"<<"  "<<"Perfect Square?"<<"  "<<"   "<<"Sphenic"<<"  "<< "Binary Equiv"<<endl;
cout<<"=======" <<"  "<<"=======" <<"   "<<"===== "<<"  "<<"==============="<<"    "<<"============"<<"   "<<"============="<<endl;

in>> num;
while(num!=-1){
if(num>=1&&num<=100){
fnum[num]++;
   i=i+1;
cout<<num<<"           "<<isperfect(num)<<"           "<<isprime1(num)<<"              "<<isperfectsqu(num)<<"            "<<issphenic(num)<<"           ";
isbinary(num)  ;
cout<<endl;

}

 
else if (num<0||num>100){
invals[j]=num;
 j=j+1; 
}

else{

 k=k+1;
 
}

 if(num>=1&& num<=10){
 
  histo[0]++;
}
 if(num>=11&&num<=20){
 
 histo[1]++;
}
  if(num>=21&&num<=30){
  
  histo[2]++;
}
 if(num>=31&&num<=40){
 
  histo[3]++;
}
 if(num>=41&&num<=50){
 
  histo[4]++;
}
 if(num>=51&&num<=60){
 
  histo[5]++;
}
 if(num>=61&&num<=70){
 
  histo[6]++;
}
  if(num>=71&&num<=80){
  
  histo[7]++;
}
  if(num>=81&&num<=90){
  
  histo[8]++;
}
if(num>=91&&num<=100){

  histo[9]++;
}




in>>num;
}
in.close();

val=i;
inval=j;
nof=k;

//cout<<val<<endl;
//cout<<inval<<endl;


cout<<endl;


// Part c
cout<<"Invalid numbers 5 in  a row"<<endl;
for(int u=1;u<=inval;u++){
cout<<invals[u-1]<<"  ";
if(u%5==0)
cout<<endl;
}
//for(u=0; u<inval; u=u+5){

	//cout<<invals[u]<<"  "<<invals[u+1]<<"   "<<invals[u+2]<<"   "<<invals[u+3]<<"   "<<invals[u+4]<<endl;


cout<<endl;
cout<<"Range              Histogram"<<endl;
cout<<"============================="<<endl;

cout<<"1-10\t:";
histo[0]=histo[0]/5;
star(histo[0]);

cout<<"11-20\t:";
histo[1]=histo[1]/5;
star(histo[1]);

cout<<"21-30\t:";
histo[2]=histo[2]/5;
star(histo[0]);

cout<<"31-40\t:";
histo[3]=histo[3]/5;
star(histo[3]);


cout<<"41-50\t:";
histo[4]=histo[4]/5;
star(histo[4]);

cout<<"51-60\t:";
histo[5]=histo[5]/5;
star(histo[5]);

cout<<"61-70\t:";
histo[6]=histo[6]/5;
star(histo[6]);

cout<<"71-80\t:";
histo[7]=histo[7]/5;
star(histo[7]);

cout<<"81-90\t:";
histo[8]=histo[8]/5;
star(histo[8]);

cout<<"91-100\t:";
histo[9]=histo[9]/5;
star(histo[9]);

cout<<endl;

cout<<"The amount of students who specified valid favourite numbers :"<<i<<endl;
cout<<"The amount of students who specified invalid favourite numbers :"<<j<<endl;
cout<<"The amount of students who did not reveal they favourite numbers :" <<k<<endl;
cout<<endl;



 for(t=1;t<=100;t=t+1){
 if(fnum[t]>max){
 max=fnum[t];
}
}

for(t=1;t<100;t=t+1){
	if(fnum[t]==max)
	cout<<"The number chosen the most :"<<t<<"  "<<endl;
}

cout<<endl;

cout<<"The numbers chosen the least"<<endl;
cout<<endl;
for(t=1;t<=100;t=t+1){
if(fnum[t]<min&&fnum[t>0])
min=fnum[t];

}

for(t=1;t<100;t=t+1){
	if(fnum[t]==min){
	cout<<t<<"  ";
	}
}
return 0;

}


//Part D


