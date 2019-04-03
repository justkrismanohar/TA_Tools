#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#define MAX 9999
#define HIST 5

using namespace std;
char perfect(int num){
	if (num==1)
		return 'N';
	int sum = 0;
	for (int i = 2; i<=sqrt(num); i++) {
		if(num%i==0) {
			sum+=i;
			sum+=num/i;
		}
	}
	sum++;//add 1 as a divisor
	if(sum==num)
		return 'Y';
	return 'N';
}
char prime (int num){
	if(num==0||num==1)
		return 'N';

	for(int i =2; i<=sqrt(num); i++) {
		if(num%i==0||num%(num/i)==0)
			return 'N';
	}

	return 'Y';
}
char PerSqr(int num){
	int innum = sqrt(num);
	float flnum = sqrt(num);
	if(innum == flnum)
		return 'Y';
	return 'N';
}
char sph(int num){
	int count = 0;

	for(int i = num/2; i>=2; i--) {
		if(prime(i)=='Y') {
			if(num%i==0) {
				count++;
				num = num/i;
			}
			if(count == 3) {
				if(num==1)
					return 'Y';
			}
		}
	}
	return 'N';
}
void disbinary(int num){
	bool arr[8];
	for(int i=0; i<8; i++) {
		if(num%2==1) {
			arr[i] = 1;
			num = num/2;
		}
		else{
			arr[i] = 0;
			num = num/2;
		}
	}
	for (int i = 7; i>=0; i--)
		cout<<arr[i];
}
void printTableline (int num){
	int width=20;
	cout<<setw(3)<<num<<setw(width)<<perfect(num)<<setw(width)<<prime(num)<<setw(width+5)<<PerSqr(num)<<setw(width)<<sph(num)<<setw(width);
	disbinary(num);
	cout<<endl;
}
void printvalidnum(int num,int arr[]){
	int count = 0;
	for (int i=1; i<=100; i++) {
		if (arr[i]==num) {
			cout<<i<<" ";
			count++;
			if((count)%5==0)
				cout<<endl;
		}
	}
	cout<<endl;
}
int main(){
	int invalarr[MAX],carr[101],valarr[MAX],invcount = 0,valcount = 0;
	ifstream ifile("numbers.txt");
	if(ifile.is_open()==false) {
		cout<<"Error opening file. Aborting";
		return 0;
	}


	int num, width=20;
	ifile>>num;

	cout<<"Number"<<setw(width)<<"Perfect?"<<setw(width)<<"Prime?"<<setw(width+5)<<"Perfect Square?"<<setw(width)<<"Sphenic?"<<setw(width)<<"Binary Equiv."<<endl;
	cout<<"======"<<setw(width)<<"========"<<setw(width)<<"======"<<setw(width+5)<<"==============="<<setw(width)<<"========"<<setw(width)<<"============="<<endl;

	while(num!=-1) {


		if(num>=0&&num<=100) {
			carr[num]++;
			if (num!=0) {
				valarr[valcount] = num;
				valcount++;
			}
		}
		else{
			invalarr[invcount] = num;
			invcount++;
		}
		ifile>>num;
	}
	ifile.close();

	for (int i = 0; i<valcount; i++) { //DISTINCT
		int j;
		for (j=0; j<i; j++) {
			if(valarr[i]==valarr[j])
				break;

		}
		if (i==j)
			printTableline (valarr[i]);
	}


	//INVALID numbers
	cout<<"\n\n\n\n";
	cout<<"\tInvalid Numbers\n\t===============\n";
	for (int i = 0; i<invcount; i++) {
		cout<<invalarr[i]<<" ";
		if((i+1)%5==0)
			cout<<"\n";
	}
	cout<<"\n\n\n";


//Histogram

	cout<<"Range"<<setw(width)<<"Histogram\n";
	cout<<"==========================\n";
	for (int i=1; i<=100; i+=10) {
		int sum=0;
		for (int j = i; j<=i+9; j++) {
			sum+=carr[j];
		}

		cout<<i<<"-"<<i+9<<"\t\t"<<":";
		//stars
		for(int k=HIST; k<=sum; k+=HIST)
			cout<<"*";
		cout<<endl;
	}


	//Statistics
	cout<<"\n\n\n\tStatistics\n\t==========\n";
	cout<<"Amount of students with Valid Favourite Numbers : "<<valcount<<endl;
	cout<<"Amount of students with invalid Favourite Numbers : "<<invcount<<endl;
	cout<<"Amount of students with hidden Numbers : "<<carr[0]<<endl;
	cout<<"\n\n";
	int max=0;
	int min = MAX;
	for(int i =1; i<=100; i++) {
		if(carr[i]>=2)
			if(carr[i]>max) max = carr[i];
		if (carr[i]>0)
			if (carr[i]<min) min = carr[i];

	}

	cout<<"The Most used valid and non-zero numbers were :\n ";//Assuming valid and non-zero
	printvalidnum(max,carr);
	cout<<"The Least used valid and non-zero numbers were :\n";//Assuming valid and non-zero
	printvalidnum(min,carr);
	//cout<<c<<endl;

	return 0;
}
