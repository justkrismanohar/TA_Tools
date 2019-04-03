/*
Name:Rashid R. Edwards
STUDENT ID: 816009068
ASSINGMENT #1
*/
#include <iostream>
#include  <cmath>
#include <fstream>
using namespace std;

bool isPerfect (int num){

int i=0, divi=0, sum=0;

for(i=1; i<num; i=i+1){

    divi= num%i;
    if (divi==0)
        sum = sum + i;

}

if (sum == num)

    return true;
            //cout << "\n" << num <<" is a perfect number.";

        else

            //cout << "\n" << num <<" is not a perfect number.";
            return false;
}

bool isPrime(int n) {
   int i;
   int prime = 0;
   for(i=2; i<=n/2; ++i) {
      if(n%i==0) {
         prime=1;

      }
   }
   if (prime==0){
      //cout<<n<<" is a prime number"<<endl;
      return true;
   }
      //cout<<n<<" is not a prime number"<<endl;
      return false;
}

bool ispsquare(int n) {


    if (n < 0)

    return false;
    int r = sqrt(n);


        if  (n != r * r){
      //cout<<n<<" is  not a perfect square of "<<r <<" *2"<<endl;
      return false;
      }

      if  (n == r * r){
      //cout<<n<<" is  a perfect square of "<<r <<" *2"<<endl;
      return true;
      }
}

bool isSphenic (int n){

int test=2,i=0,pcount=0;
int prime[3];

while (test <= n)
    {
        if (!(n % test))
            //cout << test << " ";
            if (isPrime(test)==true){
                prime[i]= test;
                //cout << prime[i] << " ";
                pcount++;
                //cout << pcount << " ";
                i=i+1;
}
            test= test+1;

    }


   int  a= prime[0]*prime[1]*prime[2];
    //cout<<a;

    if (pcount <3){
            //cout<<"no";
        return false;
    }
if (pcount==3 && a==n)
{
    //cout<<"yes";

return true;
}
}

int Binary(int n){
int div=n, res=0;
	while(div!=0){
		res=(res*10)+(div%2);
		div=floor(div/2);
	}
	return res;
}

int Histogram(int n){
	for(int i=0; i<=(n/5); i++)
	cout<<"*";
}

int main () {

ifstream in;
ofstream out;

int n,low=999, x=0, i=0,count=0,r=0,high=0,vcount=0,noans=0;
bool p, pr, ps, s;
int invalid[1000];
int fav[1000];
int answers[1000];
int ten=0, twe=0, thi=0, fou=0, fif=0, six=0, sev=0, eig=0, nin=0, hun=0;

in.open("numbers.txt");

 if (!in.is_open()){


    cout<<"Error 404 file not found"<<endl;

    return -1;
 }

/*

testing..........
isPrime(78);
isPrime(2);

isPerfect(7);
isPerfect(6);


ispsquare(25);
ispsquare(26);

isSphenic(30);

cout<<"Number? "<<endl;
cin>>n;

Binary(n);
*/

cout<< "Number \t"<<"\t Perfect ? \t"<<"Prime ? \t"<<"Perfect Square? \t"<<"Sphenic ? \t"<<"Binary Equvilent  ? \t"<<endl;
cout<< "=======\t"<<"\t ========= \t"<<"======= \t"<<"================\t"<<"=========\t"<<"==================\t"<<endl;

in>>n;

while (n!=-1)
{
answers[i]=n;
invalid[i]=n;
i=i+1;

if((n>0)&&(n<10))
	ten=ten+1;
if((n>9)&&(n<20))
	twe=twe+1;
if((n>19)&&(n<30))
	thi=thi+1;
if((n>29)&&(n<40))
	fou=fou+1;
if((n>39)&&(n<50))
	fif=fif+1;
if((n>49)&&(n<60))
	six=six+1;
if((n>59)&&(n<70))
	sev=sev+1;
if((n>69)&&(n<80))
	eig=eig+1;
if((n>79)&&(n<90))
	nin=nin+1;
if((n>89)&&(n<101))
	hun=hun+1;

if ( (n>=1)||(n<100)){
        vcount=vcount+1;

}

if (n == 0){
    noans=noans+1;

}


fav[i]=n;

count=count+1;


cout<<n<<"\t	     ";
            if(isPerfect(n)==true)
cout<<"T		   ";
			else
                cout<<"F		   ";
			if(isPrime(n)==true)
cout<<"T		      ";
			else
                cout<<"F		      ";
			if(ispsquare(n)==true)
cout<<"T		            ";
			else
                cout<<"F		            ";
			if(isSphenic(n)==true)
cout<<"T		";
			else
                cout<<"F		";
cout<<Binary(n)<<endl;

in>>n;
}


cout<<endl;
cout<<endl;

cout<<"invalid numbers are :"<<endl;
for (i=0; i<count; i=i+1){

    if ((invalid[i]<=-1)||(invalid[i]>100)){
    x=x+1;
cout<<invalid[i]<<"    ";
        if (x%5==0){
cout<<endl;
}

}
}




cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;





cout<<"Range		Histogram"<<endl;
cout<<"__________________________"<<endl;
cout<<"1-10		|";
Histogram(ten);
cout<<endl;
cout<<"11-20		|";
Histogram(twe);
cout<<endl;
cout<<"21-30		|";
Histogram(thi);
cout<<endl;
cout<<"31-40		|";
Histogram(fou);
cout<<endl;
cout<<"41-50		|";
Histogram(fif);
cout<<endl;
cout<<"51-60		|";
Histogram(six);
cout<<endl;
cout<<"61-70		|";
Histogram(sev);
cout<<endl;
cout<<"71-80		|";
Histogram(eig);
cout<<endl;
cout<<"81-90		|";
Histogram(nin);
cout<<endl;
cout<<"91-100		|";
Histogram(ten);
cout<<endl;



cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;

vcount= vcount-x-noans;

cout<<"Valid numbers:"<<vcount<<endl;
cout<<"Invalid numbers:"<<x<<endl;
cout<<"Not revealed numbers:"<<noans<<endl;

cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;


cout<<"Most Popular number(s):";
        for( r=0;r<100;r=r+1){
            if(fav[r]>fav[high])
                high=r;
}
for(int r=0;r<100;r=r+1){
	if(fav[r]==fav[high])
		cout<<r+1<<" ";
}

cout<<endl;
cout<<endl;

cout<<"Least Popular number(s):";
for(int x=0;x<100;x++){
	if(fav[x]<fav[low])
		low=x;
}
for(int x=0;x<100;x++){
	if(fav[x]==fav[low])
		cout<<x+1<<" ";
}


cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;

return 0;

}


