#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool isPerfect(int num);
bool isPrime(int num);
bool isPrfSqr(int num);
bool isSphenic(int num);
void binary(int num);

int main(){
	ifstream input;
	input.open("numbers.txt");
	if(!input.is_open()){
		cout<<"Error, file not found. Terminating program . . ."<<endl;
		return 0;
	}
	int i, num, valid=0, invalid=0, noChoice=0, highest=2, lowest=99999, Range[10]={0}, Numbers[100]={0};
	bool perfect, prime, square, sphenic;
	cout<<"Number\t\tPerfect?\tPrime?\t\tPerfect Square?\t\tSphenic?\tBinary Equiv."<<endl;
	cout<<"------------------------------------------------------------------------------------------------------"<<endl;
	input>>num;
	while(num!=-1){
		if((num>=1)&&(num<=100)){
			valid++;
			if(Numbers[num-1]==0){
				cout<<num<<"\t\t";
				perfect= isPerfect(num);
				if(perfect)
					cout<<"Y\t\t";
				else
					cout<<"N\t\t";
				prime= isPrime(num);
				if(prime)
					cout<<"Y\t\t\t";
				else
					cout<<"N\t\t\t";
				square= isPrfSqr(num);
				if(square)
					cout<<"Y\t\t";
				else
					cout<<"N\t\t";
				sphenic= isSphenic(num);
				if(sphenic)
					cout<<"Y\t\t";
				else
					cout<<"N\t\t";
				binary(num);
			}
			if(num<=10)
				Range[0]++;
			else if(num<=20)
				Range[1]++;
			else if(num<=30)
				Range[2]++;
			else if(num<=40)
				Range[3]++;
			else if(num<=50)
				Range[4]++;
			else if(num<=60)
				Range[5]++;
			else if(num<=70)
				Range[6]++;
			else if(num<=80)
				Range[7]++;
			else if(num<=90)
				Range[8]++;
			else
				Range[9]++;
			Numbers[num-1]++;
		}
		if((num<0)||(num>100)){
			invalid++;
		}
		if(num==0){
			noChoice++;
		}
	input>>num;
	}
	cout<<"\n\n\n";
	input.close();
	int invalidNum[invalid];
	input.open("numbers.txt");
	if(!input.is_open()){
		cout<<"Error, file not found. Terminating program . . ."<<endl;
		return 0;
	}
	cout<<"Invalid Numbers Entered: "<<endl;
	input>>num;
	i=1;
	while(num!=-1){
		if((num<0)||(num>100)){
			cout<<num<<" ";
			if(i%5==0)
				cout<<endl;
			i++;
		}
		input>>num;
	}
	input.close();
	cout<<"\n\n\n";
	cout<<"Range \tHistogram"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"1-10\t|";
	for(i=1;i<=(Range[0]/5);i++)
		cout<<"*";
	cout<<"\n11-20\t|";
	for(i=1;i<=(Range[1]/5);i++)
		cout<<"*";
	cout<<"\n21-30\t|";
	for(i=1;i<=(Range[2]/5);i++)
		cout<<"*";
	cout<<"\n31-40\t|";
	for(i=1;i<=(Range[3]/5);i++)
		cout<<"*";
	cout<<"\n41-50\t|";
	for(i=1;i<=(Range[4]/5);i++)
		cout<<"*";
	cout<<"\n51-60\t|";
	for(i=1;i<=(Range[5]/5);i++)
		cout<<"*";
	cout<<"\n61-70\t|";
	for(i=1;i<=(Range[6]/5);i++)
		cout<<"*";
	cout<<"\n71-80\t|";
	for(i=1;i<=(Range[7]/5);i++)
		cout<<"*";
	cout<<"\n81-90\t|";
	for(i=1;i<=(Range[8]/5);i++)
		cout<<"*";
	cout<<"\n91-100\t|";
	for(i=1;i<=(Range[9]/5);i++)
		cout<<"*";
	cout<<"\n\n\n";
	cout<<"Students That Gave Valid Numbers:    "<<valid<<endl;
	cout<<"Students That Gave Invalid Numbers:  "<<invalid<<endl;
	cout<<"Students That Did Not Reveal Number: "<<noChoice<<endl;
	for(i=0;i<=99;i++){
		if(Numbers[i]>highest)
			highest= Numbers[i];
		if((Numbers[i]<lowest)&&(Numbers[i]!=0))
			lowest= Numbers[i];
	}
	cout<<"\n\nNumber(s) Chosen The Most: ";
	for(i=0;i<=99;i++){
		if(Numbers[i]==highest)
			cout<<i+1<<" ";
	}
	cout<<"\n\nNumber(s) Chosen The Least: ";
	for(i=0;i<=99;i++){
		if(Numbers[i]==lowest)
			cout<<i+1<<" ";
	}
	cout<<endl;
	return 0;
}

bool isPerfect(int num){
	int sum=1;
	for(int i=2;i<=num/2;i++){
		if(num%i==0)
			sum= sum+i;
	}
	if((sum==num)&&(num!=1))
		return true;
	return false;
}

bool isPrime(int num){
	for(int i=2;i<=num/2;i++){
		if(num%i==0)
			return false;
	}
	if(num==1)
		return false;
	return true;
}

bool isPrfSqr(int num){
	for(int i=2;i<=num/2;i++){
		if(i*i==num)
			return true;
	}
	return false;
}

bool isSphenic(int num){
	int count=0, product=1;
	for(int i=2;i<=num/2;i++){
		if((num%i==0)&&(isPrime(i))){
			count++;
			product= product*i;
		}
	}
	if((product==num)&&(count==3))
		return true;
	return false;
}

void binary(int num){
	int rep[8]={0}, i=7;
	while(num!=0){
		rep[i]= num%2;
		num= num/2;
		i--;
	}
	for(i=0;i<=7;i++)
		cout<<rep[i];
	cout<<endl;
}























