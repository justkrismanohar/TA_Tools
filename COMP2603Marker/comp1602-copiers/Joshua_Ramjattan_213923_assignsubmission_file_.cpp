#include <iostream>
#include <fstream>
using namespace std;
char isPerfect(int n){
	char ans1;
	int i, sum=1;
	for(i=2;i<=(n-1);i=i+1){
		if((n%i)==0){
			sum=sum+i;
		}
	}
	if(sum==n){
		ans1='Y';
	}
	else{
		ans1='N';
	}
	return ans1;
}
char isPrime(int n){
	int i, count=0;
	char ans2;
	if(n==1){
		ans2='N'; // 1 is not a prime number
		return ans2;
	}
	if(n==2){
		ans2='Y'; // 2 is the only even number which is prime
		return ans2;
	}
	for(i=2;i<=(n/2);i=i+1){
		if((n%i)==0){
			count=count+1;
		}
	}
	if(count==0){
		ans2='Y';
		return ans2;
	}
	else{
		ans2='N';
		return ans2;
	}
}
char isPerfectSquare(int n){
	int i, square;
	char ans3;
	for(i=1;i<=n;i=i+1){
		square=i*i;
		if(square==n){
			ans3='Y';
			return ans3;
		}
	}
	ans3='N';
	return ans3;
}
char isSphenic(int n){
	int i, count, product;
	char ans4;
	count=0;
	product=1;
	for(i=1;i<=(n/2);i=i+1){
		if(((n%i)==0)&&(isPrime(i)=='Y')){
			product=product*i;
			count=count+1;
		}
	}
	if((product==n)&&(count==3)){
		ans4='Y';
	}
	else{
		ans4='N';
	}
	return ans4;
}
void Binarynum(int n){
	int arr[8];
	int a=7;
	int b;
	while(n!=0){
		arr[a]=n%2;
		n=n/2;
		a=a-1;
	}
	for(b=a;b>=0;b=b-1){
		arr[b]=0;
	}
	for(a=0;a<8;a=a+1){
		cout<<arr[a];
	}
}
int main(){
	char pft, prime, psq, sph;
	int num, x, y, z, validnum=0, max=-2, min=102, counter2=0, j, k, l, p=0, lower, higher, star;
	int favNum[102];
	ifstream in;
	in.open("numbers.txt");
	if(in.is_open()==false){
		cout<<"Error opening input file. Aborting...";
		return 0;
	}
	for(x=0;x<=101;x=x+1){
		favNum[x]=0;
	}
	in>>num;
	while(num!=-1){
		if(num==0){
			favNum[0]=favNum[0]+1;
		}
		if((num>0)&&(num<=100)){
			favNum[num]=favNum[num]+1;
		}
		if((num<0)||(num>100)){
			favNum[101]=favNum[101]+1;
		}
		in>>num;
	}
	in.close();
	cout<<"Number?"<<'\t'<<'\t'<<"Perfect?"<<'\t'<<"Prime?"<<'\t'<<"Perfect Square?"<<'\t'<<'\t'<<"Sphenic?"<<'\t'<<"Binary Equivalent"<<endl;
	cout<<"-------"<<'\t'<<'\t'<<"--------"<<'\t'<<"------"<<'\t'<<"---------------"<<'\t'<<'\t'<<"--------"<<'\t'<<"-----------------"<<endl;
	for(y=1;y<=100;y=y+1){
		if(favNum[y]!=0){
			pft=isPerfect(y);
			prime=isPrime(y);
			psq=isPerfectSquare(y);
			sph=isSphenic(y);
			cout<<y<<'\t'<<'\t'<<"  ";
			cout<<pft<<'\t'<<'\t'<<" ";
			cout<<prime<<'\t'<<'\t'<<" ";
			cout<<psq<<'\t'<<'\t'<<"   ";
			cout<<sph<<'\t'<<'\t'<<" ";
			Binarynum(y);
			cout<<endl;
		}
	}
	cout<<endl;
	ifstream input;
	input.open("numbers.txt");
	if(input.is_open()==false){
		cout<<"Error opening input file. Aborting...";
		return 0;
	}
	cout<<"The invalid numbers in the input are:"<<endl;
	input>>num;
	while(num!=-1){
		if((num<0)||(num>100)){
			p=p+1;
			cout<<num<<'\t';
		}
		if((p%5)==0){
			cout<<endl;
		}
		input>>num;
	}
	input.close();
	cout<<endl;
	cout<<endl;
	cout<<"Range    "<<"Histogram"<<endl;
	for(k=1;k<=10;k=k+1){
		lower=(k*10)-9;
		higher=(k*10);
		for(j=lower;j<=higher;j=j+1){
			counter2=counter2+favNum[j];
		}
		cout<<lower<<"-"<<higher<<'\t'<<"|";
		star=counter2/5;
		for(l=1;l<=star;l=l+1){
			cout<<"*";
		}
		cout<<endl;
		counter2=0;
	}
	cout<<endl;
	cout<<"Statistical Information:"<<endl;
	cout<<endl;
	for(z=1;z<=100;z=z+1){
		validnum=validnum+favNum[z];
	}
	cout<<"Number of students who specified valid favourite numbers: "<<validnum<<endl;
	cout<<"Number of students who specified invalid favourite numbers: "<<favNum[101]<<endl;
	cout<<"Number of students who did not reveal their favourite number: "<<favNum[0]<<endl;
	for(z=1;z<=100;z=z+1){
		if((favNum[z]>max)&&(favNum[z]>=2)){
			max=favNum[z];
		}
	}
	cout<<"The number(s) that was(were) chosen the most by students, if at least 2 students chose that(those) number(s) was(were): "<<endl;
	for(z=1;z<=100;z=z+1){
		if(favNum[z]==max){
			cout<<z<<endl;
		}
	}
	cout<<endl;
	for(z=1;z<=100;z=z+1){
		if((favNum[z]<min)&&(favNum[z]>=1)){
			min=favNum[z];
		}
	}
	cout<<"The number(s) that was(were) chosen the least by students, if at least 1 student chose that(those) number(s) was (were): "<<endl;
	for(z=1;z<=100;z=z+1){
		if(favNum[z]==min){
			cout<<z<<endl;
		}
	}
	return 0;
}
