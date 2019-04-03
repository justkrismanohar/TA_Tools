#include <iostream>                    //you may want to run this program twice for correct output...
#include <fstream>
#include <cmath>
using namespace std;

//perfect function
void perfect(int n){
int sum=0;

for(int count=1;count<=n/2;count++){
	
if (n%count==0){
sum=sum+count;
}

}

if (sum==n){

cout<<"Y";
}
else{
cout<<"N";
}
}




//prime function

void prime(int n){

bool prime=true;
        for (int count=2; count*count<=n; count++)
        {
            if (n % count == 0) 
            {
                prime=false;
                break;    
            }
        } 

if(prime){

cout<<"Y";
}
else{
cout<<"N";
}
}






//perfect square function
void perfect_sq(int n){

int square;

for(int count=1;count<n;count++){

square=count*count;

if(square==n){

cout<<"Y";
break;
}
}

if (square!=n){
cout<<"N";

}
}






//sphenic function

void sphenic(int n){

int i,count=0,product=1;


for(i=2;i<=n;i++){
	
if (n%i==0){
count=count+1;
product=product*i;

}
}

if ((product==n)||(count==3)){
cout<<"Y";
}
else
{
cout<<"N";
}

}



//binary equ. function

int binary1(int n){

int arr[8];
int bin;
int counter=1;
int i=0;

while (n> 0)
{
counter= n%2;
arr[i]=counter;

n= n/2;

i= i+1;

}

for(int q=7;q>=i;q--){
	
cout<<"0";
}
for(int j=i-1;j>=0;j--){
	
cout<<arr[j];
}


}


//star function

void star(int s){

s=s/5;


for(int i=1;i<=s;i++){
	

cout<<"*";
}

}



int main () {
	
int arr[50];
int num;
ifstream fin;
ofstream fout;

int pop[200]={0};




fin.open("numbers.txt");


if (!fin.is_open()){

cout<<"Couldn't find file'"<<endl;
return 0;
}



int range1=0,range2=0,range3=0,range4=0,range5=0,range6=0,range7=0,range8=0,range9=0,range10=0;


fin>>num;

int count=1;
int num_val;
while(num!=-1){

//collecting values for range & filling up array with valid numbers
if (num>0&&num<101){

arr[count]=num;

pop[num]++;

if(num>=1&&num<=10){
range1++;
}


if(num>=11&&num<=20){
range2++;
}


if(num>=21&&num<=30){
range3++;
}


if(num>=31&&num<=40){
range4++;
}


if(num>=41&&num<=50){
range5++;
}


if(num>=51&&num<=60){
range6++;
}


if(num>=61&&num<=70){
range7++;
}


if(num>=71&&num<=80){
range8++;
}


if(num>=81&&num<=90){
range9++;
}


if(num>=91&&num<=100){
range10++;
}



count=count+1;
}


fin>>num;

}



//various outputs

cout<<"Number"<<"\t"<<"Perfect?"<<"    "<<"Prime?"<<"   "<<"Perfect Square?"<<"   "<<"Sphenic"<<"    "<<"Binary Equiv."<<"\t"<<endl;
cout<<"======"<<"\t"<<"========"<<"    "<<"======"<<"   "<<"==============="<<"   "<<"======="<<"    "<<"============="<<"\t"<<endl;
cout<<endl;

int i=1;
while (arr[i]!=0){


cout<<arr[i]<<"\t   ";
perfect(arr[i]);
cout<<"\t       ";
prime(arr[i]);
cout<<"\t      ";
perfect_sq(arr[i]);
cout<<"\t          ";
sphenic(arr[i]);
cout<<"\t        ";
binary1(arr[i]);
cout<<endl;


i=i+1;
}
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;

fin.close();
int invalid_arr[106];

int nos;
fin.open("numbers2.txt");
fin>>nos;


int count1=1;
int zero=0;


while(nos!=-1){

if (nos<=0||nos>=101){

invalid_arr[count1]=nos;

count1=count1+1;

if (nos==0){

zero=zero+1;
}
}



fin>>nos;

}



int a=1,b=2,c=3,d=4,e=5;
cout<<"Invalid numbers list"<<endl;
cout<<endl;

for(int j=1;j<4;j++){

cout<<invalid_arr[a]<<"\t"<<invalid_arr[b]<<"\t"<<invalid_arr[c]<<"\t"<<invalid_arr[d]<<"\t"<<invalid_arr[e]<<endl;

a=a+5;
b=b+5;
c=c+5;
d=d+5;
e=e+5;
}



cout<<endl;
cout<<endl;
cout<<endl;



cout<<"Range"<<"            "<<"Histogram"<<endl;
cout<<"=================================="<<endl;
cout<<"1-10"<<"               "<<":";
star(range1);
cout<<endl;
cout<<"11-20"<<"              "<<":";
star(range2);
cout<<endl;
cout<<"21-30"<<"              "<<":";
star(range3);
cout<<endl;
cout<<"31-40"<<"              "<<":";
star(range4);
cout<<endl;
cout<<"41-50"<<"              "<<":";
star(range5);
cout<<endl;
cout<<"51-60"<<"              "<<":";
star(range6);
cout<<endl;
cout<<"61-70"<<"              "<<":";
star(range7);
cout<<endl;
cout<<"71-80"<<"              "<<":";
star(range8);
cout<<endl;
cout<<"81-90"<<"              "<<":";
star(range9);
cout<<endl;
cout<<"91-100"<<"             "<<":";
star(range10);
cout<<endl;




fin.close();


cout<<endl;
cout<<"The amount of students who specified valid favourite numbers = "<<count<<endl;
cout<<endl;
cout<<"The amount of students who specified invalid favourite numbers= "<<count1<<endl;
cout<<endl;
cout<<"The amount of students who did not reveal their favourite number= "<<zero<<endl; 
cout<<endl;


int max=0;

for(count=1;count<=100;count++){

if(pop[count] > max){
	max =pop[count];
}

}



for(count=1;count<=100;count++){

if(pop[count]==max){

cout<<"The most popular number was "<<count<<" and it occured "<<max<<" times"<<endl;

}

}


int min=1000;

for(count=1;count<=100;count++){

if(pop[count] < min&&pop[count]>=1){
	min =pop[count];
}

}



for(count=1;count<=100;count++){

if(pop[count]==min){

cout<<"One of the lowest numbers was "<<count<<" that occured "<<min<<" time"<<endl;

}

}






return 0;















}
