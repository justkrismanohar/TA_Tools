#include <iostream>
#include <fstream>
using namespace std;

bool isPerfect (int n) {
	int j=0;
	int perf=0;
	int perfSum=0;
	for (j=1; j<=n/2; j++) {
		perf=n%j;
		if (perf==0)
			perfSum=perfSum+j;
	}	
	if (n>0 && n==perfSum)
		return true;
	else
		return false;
}

bool isPrime (int n) {
	int j=0;
	int prime=0;
	for (j=2; j<=n/2; j++) {
		prime=n%j;
		if (prime==0)
			return false;
	}
	return true;
}

bool isPerfectSquare (int n) {
	int j=0;
	int square=0;
	for (j=0; j<=n; j++) {
		square=j*j;
		if (square==n)
			return true;
	}
	return false;
}
	
bool isSphenic (int n) {
	int j=0;
	int count=0;
	int product=1;
	for (j=2; j<=n/2; j++) {
		if (n%j==0 && isPrime(j)) {
			product=product*j;
			count++;
		}
	}
		if (count==3 && product==n)
			return true;
	return false;	
}

void binary (int n) {
	int j=0;
	int num=0;
	int binary[8]={};
	num=n;
	for (j=0; j<8 || num!=0; j++) {
		binary[j]=num%2;
		num=num/2;
	}
	for (j=7; j>=0; j--)
		cout<<binary[j];
}

void histogram (int range[10], int i) {
	int star=0;
	int j=0;
	star=range[i]/5;
	for (j=0; j<star; j++)
		cout<<"*";
}

int main() {
	ifstream in;
	int student[10000]={};
	int valid[10000]={};
	int distinct[10000]={};
	int invalid[10000]={};
	int mostArr[10000]={};
	int leastArr[10000]={};
	int range[10]={};
	int count[101]={};
	int i=0;
	int j=0;
	int favnum=0;
	int maxStudent=0;
	int maxValid=0;
	int maxDistinct=0;
	int maxInvalid=0;
	int noReveal=0;
	int num=0;
	int most=0;
	int maxMost=0;
	int least=9999;
	int maxLeast=0;
	bool isDistinct=true;
	in.open("numbers.txt");
	if (!in.is_open()) {
		cout<<"Input file not found, aborting...";
		return 0;
	}
	in>>favnum;
	while (favnum!=-1) {
		student[maxStudent]=favnum;
		maxStudent++;
		in>>favnum;
	}
	
	for (i=0; i<maxStudent; i++) {
		if (student[i]>0 && student[i]<101) {
			valid[maxValid]=student[i];
			maxValid++;
		}
		else if (student[i]==0)
			noReveal++;
		else {
			invalid[maxInvalid]=student[i];
			maxInvalid++;
		}
	}
	
	for (i=0; i<maxValid; i++) {
		for (j=0; j<maxValid; j++) {
			if (valid[i]==distinct[j]) {
				isDistinct=false;
			}	
		}
		if (isDistinct) {
			distinct[maxDistinct]=valid[i];
			maxDistinct++;
		}
		isDistinct=true;
		if (valid[i]>90)
			range[9]++;
		else if (valid[i]>80)
			range[8]++;
		else if (valid[i]>70)
			range[7]++;
		else if (valid[i]>60)
			range[6]++;
		else if (valid[i]>50)
			range[5]++;
		else if (valid[i]>40)
			range[4]++;
		else if (valid[i]>30)
			range[3]++;
		else if (valid[i]>20)
			range[2]++;
		else if (valid[i]>10)
			range[1]++;
		else
			range[0]++;
	}

	cout<<"Number"<<"\t"<<"Perfect?"<<" "<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic?"<<" "<<"Binary Equivalent"<<"\t"<<endl;
	cout<<"-----------------------------------------------------------------------"<<endl;
	for (i=0; i<maxDistinct; i++) {
		favnum=distinct[i];
		cout<<distinct[i]<<"\t";
		if (isPerfect(favnum))
			cout<<"Y"<<"\t";
		else
			cout<<"N"<<"\t";
		if (isPrime(favnum))
			cout<<"Y"<<"\t";
		else
			cout<<"N"<<"\t";
		if (isPerfectSquare(favnum))
			cout<<"Y"<<"\t\t";
		else
			cout<<"N"<<"\t\t";
		if (isSphenic(favnum))
			cout<<"Y"<<"\t";
		else
			cout<<"N"<<"\t";
		binary(favnum);
		cout<<endl;
	}
	
	cout<<endl;
	cout<<"Invalid numbers: ";
	for (i=0; i<maxInvalid; i++) {
		if (i%5==0)
			cout<<endl;
		cout<<invalid[i]<<" ";
	}
	
	cout<<endl<<endl;
	cout<<"Range\t|"<<"Histogram"<<endl;
	cout<<"-----------------------"<<endl;
	cout<<"1-10\t|";
	histogram(range, 0);
	cout<<endl<<"11-20\t|";
	histogram(range, 1);
	cout<<endl<<"21-30\t|";
	histogram(range, 2);
	cout<<endl<<"31-40\t|";
	histogram(range, 3);
	cout<<endl<<"41-50\t|";
	histogram(range, 4);
	cout<<endl<<"51-60\t|";
	histogram(range, 5);
	cout<<endl<<"61-70\t|";
	histogram(range, 6);
	cout<<endl<<"71-80\t|";
	histogram(range, 7);
	cout<<endl<<"81-90\t|";
	histogram(range, 8);
	cout<<endl<<"91-100\t|";
	histogram(range, 9);
	
	cout<<endl<<endl;
	cout<<"Number of students who specified valid numbers: "<<maxValid<<endl;
	cout<<"Number of students who specified invalid numbers: "<<maxInvalid<<endl;
	cout<<"Number of students who did not reveal their favourite number: "<<noReveal<<endl;
	
	for (i=0; i<maxValid; i++) {
		num=valid[i];
		count[num]++;
	}
	for (i=1; i<101; i++) {
		if (count[i]>most && count[i]>=2) {
			most=count[i];
		}
		if (count[i]<least && count[i]>=1) {
			least=count[i];
		}
	}
	for (i=1; i<101; i++) {
		if (count[i]==most) {
			mostArr[maxMost]=i;
			maxMost++;
		}
		if (count[i]==least) {
			leastArr[maxLeast]=i;
			maxLeast++;
		}
	}
	cout<<endl;
	cout<<"Number/s that were chosen the most: ";
	for (i=0; i<maxMost; i++)
		cout<<mostArr[i]<<" ";
	cout<<endl<<"(Chosen "<<most<<" times)"<<endl;
	cout<<endl<<"Number/s that were chosen the least: ";
	for (i=0; i<maxLeast; i++)
		cout<<leastArr[i]<<" ";
	cout<<endl<<"(Chosen "<<least<<" time/s)"<<endl;
	in.close();	
	return 0;
}
