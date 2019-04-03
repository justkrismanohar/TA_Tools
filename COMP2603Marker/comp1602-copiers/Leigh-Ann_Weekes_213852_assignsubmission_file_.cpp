#include <iostream>
#include <fstream>
using namespace std;
bool isPerfect(int num){
	int n,sum;
	sum=0;
	for (n=1;n<=num/2;n++){
		if (num%n==0)
		sum=sum+n;}
		if (sum==num)
		return true;
		else
		return false;
	}
bool isPrime(int num){
	int n;
	if (num<=1)
	return false;
	for (n=2; n<num; n++)
		if (num%n==0)
		return false;

		return true;
}
bool isPerfectSquare(int num){
	int i;
	for(i=1; i<=num; i++){
		if (num==i*i)
		return true;}
		return false;
}

bool isSphenic(int num){
	int count, product;
	count=0;
	product=1;
	for (int i=2; i<=num/2; i++){
		if (num%i==0 && isPrime(i)){
			product=product*i;
			count=count+1;
		}
	}
	if (count==3 && product==num)
	return true;
	else
	return false;
}

void bin(int n){ 
    if (n >= 1) 
        bin(n/2); 
    cout << n % 2; 
} 
int main (){
	ifstream inputFile;
	inputFile.open("numbers.txt");
	if (!inputFile.is_open()) {
		cout << "Error opening input file. Aborting ...";
		return 0;
	}

	int num, countv, countinv, count0, count1, count2, count3, count4, count5, count6, count7, count8, count9, count10, n;
	countv=countinv=count0=count1=count2=count3=count4=count5=count6=count7=count8=count9=count10=n=0;
	int invalid[100];
	int numbers[101];
	for (int j=0;j<=100;j++)
		numbers[j]=0;
	
	cout<<"Number \t Perfect? \t Prime? \t Perfect Square? \t Sphenic? \t Binary Equiv."<<endl;
	cout<<"====== \t ======== \t ====== \t =============== \t ======== \t ============="<<endl;
	
	inputFile>>num;
	while(num!=-1){
		if (num>=1 && num<=100){
			countv=countv+1;
			numbers[num]++;
		cout<<num<<"\t";
		bool perfect= isPerfect(num);
		if (perfect)
		cout<<" Y \t";
		else 
		cout<<" N \t";
		
		bool prime= isPrime(num);
		if (prime)
		cout<<"\t Y \t";
		else 
		cout<<"\t N \t";
		
		bool square= isPerfectSquare(num);
		if (square)
		cout<<"\t Y \t";
		else 
		cout<<"\t N \t";
		
		bool sphenic= isSphenic(num);
		if (sphenic)
		cout<<"\t\t Y \t\t ";
		else
		cout<<"\t\t N \t\t ";
		
		bin(num);
		cout<<endl;
		
	if (num<=10)
	count1=count1+1;
	else if (num<=20)
	count2=count2+1;
	else if (num<=30)
	count3=count3+1;
	else if (num<=40)
	count4=count4+1;
	else if (num<=50)
	count5=count5+1;
	else if (num<=60)
	count6=count6+1;
	else if (num<=70)
	count7=count7+1;
	else if (num<=80)
	count8=count8+1;
	else if (num<=90)
	count9=count9+1;
	else
	count10=count10+1;
	}
	if (num>100 || num<0){
	countinv=countinv+1;
	invalid[n]=num;
	n=n+1;}
	
	if (num==0)
		count0=count0+1;
		
		inputFile>>num;
		}
	
	cout<<endl;
	cout<<invalid[0]<<" ";
	for (int n=1; n<countinv; n++){
		cout<<invalid[n]<<" ";
		if (n%4==0)
		cout<<endl;}
		cout<<endl;
		cout<<endl;
	cout<<"Range \t Histogram"<<endl;
	cout<<"=========================="<<endl;
	
	cout<<"1-10 \t";
	for (int i=0; i<=count1; i=i+5)
		cout<<"*";
			cout<<endl;
	cout<<"11-20 \t";
	for (int i=0; i<=count2; i=i+5)
		cout<<"*";
			cout<<endl;
	cout<<"21-30 \t";
	for (int i=0; i<=count3; i=i+5)
		cout<<"*";
			cout<<endl;
	cout<<"31-40 \t";
	for (int i=0; i<=count4; i=i+5)
		cout<<"*";
			cout<<endl;
	cout<<"41-50 \t";
	for (int i=0; i<=count5; i=i+5)
		cout<<"*";
			cout<<endl;
	cout<<"51-60 \t";
	for (int i=0; i<=count6; i=i+5)
		cout<<"*";
			cout<<endl;
	cout<<"61-70 \t";
	for (int i=0; i<=count7; i=i+5)
		cout<<"*";
			cout<<endl;
	cout<<"71-80 \t";
	for (int i=0; i<=count8; i=i+5)
		cout<<"*";
			cout<<endl;
	cout<<"81-90 \t";
	for (int i=0; i<=count9; i=i+5)
		cout<<"*";
			cout<<endl;
	cout<<"91-100 \t";
	for (int i=0; i<=count10; i=i+5)
		cout<<"*";
			cout<<endl;
			cout<<endl;
	
	cout<<"The number of valid favourite numbers: "<<countv<<endl;
	cout<<"The number of invalid favourite numbers: "<<countinv<<endl;
	cout<<"The number of people who did not specify their favourite number: "<<count0<<endl;
	
	int max=numbers[1];
for (int n=1;n<=100;n++){
	if (numbers[n]>max)
	max=numbers[n];}
for (int n=1;n<100;n++){
	if(numbers[n]==max)
	cout<<"The most chosen favourite number: "<<n<<endl;}
	
	cout<<"The least chosen favourite numbers: ";
	int min=1;
for (int n=1;n<=100;n++){
	if (numbers[n]<max && numbers[n]>0)
	min=numbers[n];}
for (int n=1;n<100;n++){
	if(numbers[n]==min)
	cout<<n<<" ";}
	
	inputFile.close();
	return 0;
	}
