#include <iostream>
#include <fstream>
using namespace std;

char isPerfect(int test)
{
int n=2, sum=1;
if(test==1)
return 'N';
while(n<=test/2)
{
if (test%n==0)
{
sum=sum+n;
n++;
}
else
n++;
}
if(sum==test)
return 'Y';
else
return 'N';
}

bool isPrime(int test)
{
int n=2;
while(n<=test/2)
{
if (test%n==0)
return false;
else
n++;
}
return true;
}

bool isSquare(int test)
{
int n=2;
while(n<=test/2)
{
if (test==(n*n))
return true;
else
n++;
}
return false;
}


bool isSphenic(int test)
{
int arr[50], i=0, n=2, countprime=0;
while(n<=test/2)
{
if (isPrime(n))
{
arr[i]=n;
countprime++;
n++;
i++;
}
else
n++;
}
int countfactor=0;
i=0;
while(i<countprime)
{
if(((test%arr[i])==0)&&(test%(arr[i]*arr[i])!=0))
{
countfactor++;
i++;
}
else
i++;
}
if(countfactor==3)
return true;
else
return false;
}

void printArray(int arr[], int n)
{
int i;
for(i=0;i<n;i++)
cout<<arr[i];
}

void printArray2(int arr[], int n)
{
int i;
for(i=0;i<n;i++)
cout<<arr[i]<<" ";
}

void biNum(int num, int bits)
{
int i, arr[bits], binarr[bits];
for(i=0;i<bits;i++)
arr[i]=0;
for(i=0;num>0;i++)
{
arr[i]=num%2;
num=(num/2);
}
for(i=0;i<bits;i++)
binarr[i]=arr[bits-1-i];
printArray(binarr, bits);
}

void printTable(int arr[], int sizearr, int width)
{
int i=0, count;
for(count=1;count<=sizearr/width+1;count++)
{
	while(i<(count*width)&&(i<sizearr))
	{
	cout<<arr[i]<<" ";
	i++;
	}
	cout<<endl;
}
}

int main()
{

int num, i, count, n ;
int numarray[101], invalidarr[100];
int mostpop=0, mostpopfreq=0, lespop=0, lespopfreq=99, invalidcount=0, validnum=0, secretnum=0;
int invalidindex=0;
ifstream inFile;
inFile.open("numbers.txt");
if (!inFile.is_open())
{
cout<<"error open file";
return 0;
}
inFile>>num;
for(i=0;i<101;i++)
numarray[i]=0;
for(i=0;i<101;i++)
invalidarr[i]=0;
cout<<"Number	Perfect	Prime	Square	Sphenic	Binary\n";
cout<<"________________________________________________\n";
cout<<"------------------------------------------------\n";

while(!(num==-1)){

if((num>=1)&&(num<=100))
{
validnum=validnum+1;
numarray[num]=(numarray[num]+1);
cout<<num<<"	";
cout<<isPerfect(num);
if(isPrime(num))cout<<"	Y";else cout<<"	N";
if(isSquare(num))cout<<"	Y";else cout<<"	N";
if(isSphenic(num))cout<<"	Y";else cout<<"	N";
cout<<"	";
biNum(num, 8);
//return 0;
cout<<"\n";
}
/*
*/
//
if((num<0)||(num>100))
{
invalidarr[invalidindex]=num;
invalidindex++;
invalidcount=invalidcount+1;
}
if(num==0)
secretnum=secretnum+1;
inFile>>num;
}
inFile.close();
//
cout<<endl;
cout<<"Range	Frequency\n";
int tally=0;
for(count=0,i=1;count<10;count++)
{
cout<<(count*10)+1<<"-"<<(count+1)*10<<"	";
tally=0, n=1;	
while(i<=10*(count+1))
{
tally=tally+numarray[i];
i++;
}
while(n<=tally/5)
{
cout<<"*";
n++;
}
cout<<endl;
}
//
for(i=1;i<101;i++)
{
if(numarray[i]>mostpopfreq)
{
mostpopfreq=numarray[i];
mostpop=i;
}
if((numarray[i]<lespopfreq)&&(numarray[i]>0))
{
lespopfreq=numarray[i];
lespop=i;
}}
cout<<endl;

cout<<"Invalid entries\n";
printTable(invalidarr, invalidindex, 5);
cout<<endl;
cout<<"Valid numbers submitted: "<<validnum<<endl;
cout<<"Did not reveal favourite number: "<<secretnum<<endl;
cout<<"Provided invalid numbers: "<<invalidcount<<endl;
cout<<"Most popular favourite number: "<<mostpop<<", chosen "<<mostpopfreq<<" times."<<endl;
cout<<"Least popular favourite number: "<<lespop<<", ";
for(count=1,i=lespop+1,n=1;count<11;count++)
{
while((n<(10*count))&&(i<=(102-lespop)))
{
if(numarray[i]==lespopfreq)
{
cout<<i<<", ";
i++;
n++;
}
else 
{
n++;
i++;
}
}
cout<<endl;}
//cout<<", ";//<<lespopfreq;
if(lespopfreq==1)cout<<"chosen once."; 
if(lespopfreq>1)cout<<" chosen"<<lespopfreq<<" times.";
cout<<endl;

/*for(count=1,i=lespop+1,n=1;count<11;count++)
{
while((n<(10*count))&&(i<=(102-lespop)))
{
if(numarray[i]==lespopfreq)
{
cout<<i<<", ";
i++;
n++;
}
else 
{
n++;
i++;
}
}
cout<<endl;}
cout<<"were also as unpopular.\n\n";*/
/*
cout<<"Range	Frequency\n";
cout<<endl;
int tally=0;
for(count=0,i=1;count<10;count++)
{
cout<<(count*10)+1<<"-"<<(count+1)*10<<"	";
tally=0, n=1;	
while(i<=10*(count+1))
{
tally=tally+numarray[i];
i++;
}
while(n<=tally/5)
{
cout<<"*";
n++;
}
cout<<endl;
*/
return 0;
}






















