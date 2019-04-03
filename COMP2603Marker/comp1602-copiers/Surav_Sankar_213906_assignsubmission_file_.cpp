#include <iostream>
#include <fstream>
using namespace std;
int main () {
	int n,i,valid,invalid,notrev;
	int students[200];
	i=0;
	ifstream inputFile;
	inputFile.open("numbers.txt");
	if (!inputFile.is_open()) {
    cout <<"Error opening input file. Aborting ...";
    return 0;
    }
    while (n!=-1){
    inputFile>>students[i];
    n=students[i];
    i++;
    }
    //valid entry
    if(n>0||n<100)
    valid=valid++;

    //invalid entry
    else
    invalid=invalid++;
    
    notrev=0;
    if (n==0)
    notrev=notrev++;

    void perfectnum () {
    while (n!=-1){
    inputFile>>students[i];
    n=students[i];
    i++;
    
	int n,num,div,sum=0;
		div = num%i;
		if (div==0)
		sum=sum+i
	}
	if (sum==num)
	cout<<"Y"<<endl;
	else
	cout<<"N"<<endl;
	return 0;
    }
    //prime numbers
    void primenum (){
    while (n!=-1){
    inputFile>>students[i];
    n=students[i];
    int i ,count=0;
    if (n==0) {
    cout<<n<<"N"}
    else {
	for(i=2; i<n; i++)
	    if(num%i=0)
	    count++;
    }
    if (count>1)
    cout<<"N"<<endl;
    else
    count<<"Y"<<endl;
    return 0;
    }
    //perfect square
     void perfectsqr(){
	int n;
	while (n!=-1){
    inputFile>>students[i];
    n=students[i];
	int r=1,i=1;
	while(r<n){
		i++;
		r=i*i;
	}
	if(r==n)
	cout<<"Y"<<n<<endl;
	else
	cout<<"N"<<n<<endl;
	return 0;
    }
    //binary
    void binary(){
    while (n!=-1){
    inputFile>>students[i];
    n=students[i];
    i++;
    }
	while (n/2!=0){
	rem=n/2;
	rem>>remaining[100];
	while (num<8) {
	    if(remaining[100]>1.00)
	    cout<<1;
	    else
	    cout<<0;
	    }
    }
}
cout<<"Number\tPerfect?\tPrime?\tPerfect Square?\tSphenic?\tBinary Equiv."<<endl;
cout<<"------\t--------\t------\t---------------\t--------\t-------------"<<endl;
cout<<n<<"\t"<<perfectnum()<<"\t"<<primenum()<<"\t"<<perfectsqr()<<"\t"<<binary()<<endl;
cout<<"\nValid numbers: "<<valid<<endl;
cout<<"\nInvalid numbers: "<<invalid<<endl;
cout<<"\nNot reavled numbers: "<<notrev<<endl;
}
