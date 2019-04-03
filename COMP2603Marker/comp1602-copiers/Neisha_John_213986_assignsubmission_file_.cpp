#include <iostream>
#include <fstream>
using namespace std;


 bool isPerfect (int num){
        int sum=0;
        int div;
        int i;
    for (i=1; i < num; i++){
        div = num % i;
        if (div == 0)
        sum = sum + i;
    }
    if (sum == num){
       return true;
       }
    return false;
}

bool isPrime( int n){
int i;
for(i=2; i<=n/2; i++){
    if(n%i==0)
    return false;
}
return true;
}

bool isPerfectSquare(int n){
int square;
for(int i=1; i<=n; i++){
    square=i*i;
    if(square==n)
        return true;
}
return false;
}

bool isSphenic(int n){
int i;
int count=0;
int product=1;
for(i=2; i<=n/2; i++){
    if(n%i==0 && isPrime(i)){
    product=product*i;
    count=count+1;
if(count==3 && product==n){
    return true;
    }
}
}
return false;
}

int bin(int x){
int binary=0;
binary=x%2;
return binary;
}


int main(){
ifstream in;
    int x;
    int i;
	in.open("numbers.txt");
		if(!in.is_open()){
        cout<<endl<<" -----------ERROR in opening, aborting----------------"<<endl<<endl<<endl;
        return 0;
		}
		int num;
		int size=0;
		in>>num;
		while(num!=-1){
		size=size+1;
		in>>num;
	    }
        in.close();
        in.open("numbers.txt");
		if(!in.is_open()){
        cout<<endl<<" -----------ERROR in opening, aborting----------------"<<endl<<endl<<endl;
        return 0;
		}
		int numbers[size];
			in>>numbers[x];
			while(numbers[x]!=-1){
			x=x+1;
		in>>numbers[x];
}
        in.close();

int valid[size];
int invalid[size];
int j=0;
int k=0;
int count_zero=0;
for(i=0; i<size; i=i+1){
	if(numbers[i]>0 && numbers[i]<101){
    valid[j]=numbers[i];
    j=j+1;
    }
    else{
    if(numbers[i]<0 && numbers[i]>100){
    invalid[k]=numbers[i];
    k=k+1;
}
else
    count_zero=count_zero++;
}
}
cout<<"Number"<<"\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square"<<"\t"<<"Sphenic"<<"\t"<<"Binary Equivalent"<<endl;
cout<<"====="<<"========"<<"====="<<"====="<<"===="<<"========="<<"======"<<"========"<<endl;

int prime,perfect,perfectsquare,sphenic;
for(i=0; i<j; i++){
    cout<<valid[i]<<"\t";
    prime=isPerfect(valid[i]);
    if(prime==1)
        cout<<"Y \t";
    else
        cout<<"N \t";
    perfect=isPrime(valid[i]);
    if(perfect==1)
        cout<<"\t Y \t \t";
    else
        cout<<"\t N \t \t";
    perfectsquare=isPerfectSquare(valid[i]);
    if(perfectsquare==1)
        cout<<"Y \t \t";
    else
        cout<<"N \t \t";

    sphenic= isSphenic(valid[i]);
    if(sphenic==1)
        cout<<"Y \t";
    else
        cout<<"N \t";

cout<<endl;
}
int onecount,twocount,threecount,fourcount,fivecount,sixcount,sevencount,eightcount,ninecount,tencount=0;
for(int i=0; i<size; i++){
if(valid[i]>=0 && valid[i]<=10){
onecount++;
i++;
}
if(valid[i]>=11 && valid[i]<=20){
twocount++;
i++;
}
if(valid[i]>=21 && valid[i]<=30){
threecount++;
i++;
}
if(valid[i]>=31 && valid[i]<=40){
fourcount++;
i++;
}
if(valid[i]>=41 && valid[i]<=50){
fivecount++;
i++;
}
if(valid[i]>=51 && valid[i]<=60){
sixcount++;
i++;
}
if(valid[i]>=61 && valid[i]<=70){
sevencount++;
i++;
}if(valid[i]>=71 && valid[i]<=80){
eightcount++;
i++;
}if(valid[i]>=81 && valid[i]<=90){
ninecount++;
i++;
}
if(valid[i]>=91 && valid[i]<=100){
tencount++;
i++;
}


return 0;
}
}
