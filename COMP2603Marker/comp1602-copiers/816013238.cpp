#include <iostream>
#include <fstream>
using namespace std;

bool isValid(int n){
	if (n!= 0 && n>0 && n<=100)
	return true;
	else
	return false;
}

bool isPerfectSquare (int n){
	int i,sq;
	for(i=1; i<n; i++){
	sq=i*i;
	if(sq==n)
}
	 return false;
}

bool isPrime(int n){
	int i,prime;
	for(i=2; i<n/2; i++){
		prime=n%i;
		if(prime==0)
		return true;
	}
	return false;
}

bool isSphenic(int n){
	int prod=1;
	int prime_num=0;
	int i;
	for(i=2; i<n/2;i++){
		if(n%i==0 && (isPrime(i)))){
			prod=prod-i;
			prime_num++;
		}
		if(prime_num==3 && prod==n)
		return true;
		return false;
	}
	
	void Binary(int n){
		int binary[b]= {};
		int i= 7;
		
		while(n!=0){
			if (n%2==0)
			binary[i] = 0;
			else if (n%2 == 1)
			binary [i] = 1;
			i--;
			n=n/2;
		}
		
		for(i=0; i<=7; i++)
		cout<<binary[i];
	}
	
	string Histogram(int n){
		if(n/5==1)
		return "*";
		else if(n/5==2)
		return "**";
		else if(n/5==3)
		return "***";
		if(n/5==4)
		return "****";
		if(n/5==5)
		return "*****";
	}
	
	int main(){
		ifstream in;
		bool is_numvalid;
		bool is_numprime;
		bool is_numdistinct;
		bool is_numperfect;
		bool is_perfectsq;
		bool check={};
		int valid[10000]={};
		int fav_num[10000]={};
		int is_distinct[10000]={};
		int invalid[10000]={};
		int totalinvalid[10000]={};
		int histogram[10]={};
		int numchosen[10000]={};
		int distinct_numchosen[10000]={};
		int numfav[10000]={;}
			}
}


for(x=0; x<totalvalid;x++){
	if(valid[x] >= 1 && valid[x] <=10)
	histogram[0]++;
	else if(valid[x] >= 11 && valid[x] <=20)
	histogram[1]++;
    else if(valid[x] >= 21 && valid[x] <=30)
	histogram[2]++;
	else if(valid[x] >= 31 && valid[x] <=40)
	histogram[3]++;
	else if(valid[x] >= 41 && valid[x] <=50)
	histogram[4]++;
	else if(valid[x] >= 51 && valid[x] <=60)
	histogram[5]++;
	else if(valid[x] >= 61 && valid[x] <=70)
	histogram[6]++;	
	else if(valid[x] >= 71 && valid[x] <=80)
	histogram[7]++;	
	else if(valid[x] >= 81 && valid[x] <=90)
	histogram[8]++;	
	else if(valid[x] >= 91 && valid[x] <=100)
	histogram[9]++;	
}

cout <<endl << endl << endl;

cout << "Range                Histogram"  <<endl;
cout << "---------------------------------- << endl;"
cout << "1-10"                 << Histogram(histogram[0]) <<endl;
cout << "11-20"                 << Histogram(histogram[1]) <<endl;
cout << "21-30"                 << Histogram(histogram[2]) <<endl;
cout << "31-40"                 << Histogram(histogram[3]) <<endl;
cout << "41-50"                 << Histogram(histogram[4]) <<endl;
cout << "51-60"                 << Histogram(histogram[5]) <<endl;
cout << "61-70"                 << Histogram(histogram[6]) <<endl;
cout << "71-80"                 << Histogram(histogram[7]) <<endl;
cout << "81-90"                 << Histogram(histogram[8]) <<endl;
cout << "91-100"                << Histogram(histogram[9]) <<endl;

cout << endl <<endl;

cout<<"Amount of students who specified valid favourite numbers: " <<totalvalid <<" students" <<endl;
cout<<endl;
cout<<"Amount of students who specified invalid favourite numbers: " <<totalinvalid <<" students" <<endl;
cout<<endl;
cout<<"Amount of students that did not reveal their favourite numbers: " <<numfav <<" students" <<endl;



int main(){
	ifstream in;
	in.open ("numbers.txt");
	if (!in.is_open ()){
		cout<<"Error opening file." <<endl;
		return 0;
	}
int n;
int count=0;
in>>n;
while (n!=-1){
	count ++;
	in>>n;	
}

return 0;


