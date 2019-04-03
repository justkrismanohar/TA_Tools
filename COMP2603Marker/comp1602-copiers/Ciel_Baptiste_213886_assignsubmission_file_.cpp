#include <iostream>
#include <fstream>
using namespace std;

bool perfectNum (int num){
int a;
int sum=0;
for(int i=1;i<num;i++){
a=num%i;
if(a==0)
sum=sum+i;
        }
        if(sum==num)
return true;
return false;
}

bool isPrime(int num){
for(int i=2; i<=num/2 ;i++)
    if (num%i==0)
    return false;
    return true;
}

bool perfectSquare (int num){
for(int i=1;i<=num;i++){
if(num==i*i)
return true;}
return false;
}

bool is_sphenic(int num){
int i;
int j=0;
int pdt=1;
for(i=2;i<=num/2;i++){
if(num%i==0&&isPrime(i)){
pdt=pdt*i;
j=j+1;
}
}
if(j==3&&pdt==num)
return true;
return false;

}

void binary (int n){
int a[8];
int i=0;   
   int num;
   while(n>0){
   	num=n%2;
   	a[i]=num;
   	i++;
   	n=n/2;
   }
   for(int e=8;e>i;e--){
   	cout<<"0";
   }
   for(int r=i-1;r>=0;r--){
   	cout<<a[r];
   }
   cout<<endl;
   
}
   

void histogram (int a){
for(int i=0;i <a;i++)
cout<<"*";
cout<<endl;
}

int main (){
ifstream input;
int num;
int valid=0;
int invalid=1;
bool perfect,prime,sphenic,square;
int no_fav=0;
char pe, pr,sph,sq;
int arr[10];
int one,two,three,four,five,six,seven,eight,nine,ten;
int g;
int invalid_num[100];
int fav[101];

for(int w=1;w<101;w++){
	fav[w]=0;
}

input.open("numbers.txt");
if(!input.is_open()){
	cout<<"Error opening 'numbers' file. Aborting..."<<endl;
	return 0;
}

for(int s=0;s<10;s++){
	arr[s]=0;
}

cout<<"Number"<<"\t\t"<<"Perfect?"<<"\t\t"<<"Prime?"<<"\t\t"<<"Perfect Square?"<<"\t\t"<<"Sphenic?"<<"\t\t"<<"Binary Equiv"<<endl;
cout<<"======"<<"\t\t"<<"========"<<"\t\t"<<"======"<<"\t\t"<<"==============="<<"\t\t"<<"========"<<"\t\t"<<"============"<<endl;
   
    input>>num;
while(num!=-1){

if(num>=1 && num<=100){
  
valid=valid+1;
fav[num]++;

    prime=isPrime(num);
    if(prime==true)
    pr='Y';
    else
    pr='N';
    
    square=perfectSquare(num);
if(square==true)
sq='Y';
else
sq='N';
   
    perfect=perfectNum(num);
    if(perfect==true)
    pe='Y';
    else
    pe='N';
    
    sphenic=is_sphenic(num);
    if(sphenic==true)
    sph='Y';
    else
    sph='N';
    
    
    cout<<num<<"\t\t"<<pe<<"\t\t\t"<<pr<<"\t\t"<<sq<<"\t\t\t"<<sph<<"\t\t\t";
    binary(num);

    
}
    if(num<0||num>100){
    invalid_num[invalid]=num;
    invalid=invalid +1;
	}
    
    if(num==0)
		no_fav=no_fav+1;

	if(num>=1&&num<=10)
    arr[0]=arr[0]+1;
    if(num>=11&&num<=20)
    arr[1]=arr[1]+1;
    if(num>=21&&num<=30)
    arr[2]=arr[2]+1;
    if(num>=31&&num<=40)
    arr[3]=arr[3]+1;	
    if(num>=41&&num<=50)
    arr[4]=arr[4]+1;
    if(num>=51&&num<=60)
    arr[5]=arr[5]+1;
	if(num>=61&&num<=70)
    arr[6]=arr[6]+1;	
    if(num>=71&&num<=80)
    arr[7]=arr[7]+1;
    if(num>=81&&num<=90)
    arr[8]=arr[8]+1;
    if(num>=91&&num<=100)
    arr[9]=arr[9]+1;	



input>>num;
}

int max=-1;
int min=1;

cout<<endl;
cout<<"The invalid numbers are: "<<endl;
for (int d=1;d<invalid;d++){
	cout<<invalid_num[d]<<" ";
	if(d%5==0)
	cout<<endl;
}
cout<<endl;

one=arr[0]/5;
two=arr[1]/5;
three=arr[2]/5;
four=arr[3]/5;
five=arr[4]/5;
six=arr[5]/5;
seven=arr[6]/5;
eight=arr[7]/5;
nine=arr[8]/5;
ten=arr[9]/5;
cout<<endl;

cout<<"Range \t\tHistogram"<<endl;
cout<<"=====\t\t========="<<endl;
cout<<"1-10\t\t|";
histogram(one);
cout<<"11-20\t\t|";
histogram(two);
cout<<"21-30\t\t|";
histogram(three);
cout<<"31-40\t\t|";
histogram(four);
cout<<"41-50\t\t|";
histogram(five);
cout<<"51-60\t\t|";
histogram(six);
cout<<"61-70\t\t|";
histogram(seven);
cout<<"71-80\t\t|";
histogram(eight);
cout<<"81-90\t\t|";
histogram(nine);
cout<<"91-100\t\t|";
histogram(ten);
cout<<endl;


cout<<valid<<" student(s) specified valid numbers."<<endl;
cout<<invalid<<" student(s) specified invalid numbers."<<endl;
cout<<no_fav<<" student(s) did not reveal their favourite number."<<endl;

cout<<endl;

cout<<"The number(s) chosen the most was: ";

for(int p=1;p<=100;p++){
	if(fav[p]>max)
	max=fav[p];
}

for(int p=1;p<=100;p++){
	if(fav[p]==max)
	cout<<p<<" ";
}
cout<<endl;

cout<<"The number(s) chosen the least was: ";
for(int p=1;p<=100;p++){
	if(fav[p]<min && fav[p]>0)
	min=fav[p];
}

for(int p=1;p<=100;p++){
	if(fav[p]== min && fav[p]>0)
	cout<<p<<" ";
}
cout<<endl; 

input.close();
return 0;
}

