//Aaron Meighoo
//816000303.cpp
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

//isPerfect function, returns Y or N appropriately
char isPerfect(int num){
	int sum=0,i,div;
	if(num>0){
		for(i=1; i<num; i++){
			div=num%i;
			if(div==0)
			sum=sum+i;
		}
		if(sum==num)
		return 'Y';
	else
	return 'N';
	}
}

//isPrime function, returns Y or N
char isPrime(int num){
	int i;
	for(i=2; i<=num/2; i++){
		if(num%i==0)
		return 'N';
	}
	return 'Y';
}

//isPerfectSquare function, returns Y or N
char isPerfectSquare(int num){
	int sq,i;
	for(i=1; i<num/2; i++){
		sq=i*i;
		if(sq==num)
		return 'Y';
	}
	return 'N';
}

//isSphenic function, returns Y or N
char isSphenic(int num){
	int i, count=0, product=1;
	for(i=2; i<=num/2; i++){
		if(num%i==0 && isPrime(i)=='Y'){
			product = product*i;
			count++;
		}
	}
	if(count==3 && product==num)
	return 'Y';
	else
	return 'N';
}

//returns the binary equivalent of an integer
int decimalToBinary(int num){
	int bin=0;
	int step=1, i=1, remainder;
	while(num!=0){
		remainder=num%2;
		num=num/2;
		bin=bin+remainder*i;
		i=i*10;
	}
return bin;
}

//Print stars function that prints one star per 5 values
char printStars(int n){
	float m = (ceil (n/5.0));
	while (m > 0) {
		cout<<"*";
		m=m-1;
	}
	return '*';
}

//main function or program

//variables
	int main(){
	int Freq[105];
	int mostFreq[105];
	int leastFreq[105];
	int size, i=0,votes=0, x=0;
	int notReveal=0, validVote=0, invalidVote[20];
	int j=0, count;
	int less10=0, less20=0,less30=0,less40=0,less50=0,less60=0,less70=0, less80=0,less90=0,less100=0;
	
//file stream open

	ifstream in;
	in.open("numbers.txt");
	if(!in.is_open()){
		cout << "Error...";
	}
	
	cout << "Number \t\t"<<"Perfect? \t"<<"Prime? \t\t"<<"Perfect Square\t\t"<<"Sphenic? \t"<<"Binary Equiv."<<endl;
	cout << "========\t"<<"========\t"<<"=======\t\t"<<"================\t"<<"========\t"<<"=============="<<endl;
	
//reading from file

	in>>i;
	while(i != -1){
		if(i==0)
			notReveal++;
		else if(i>= 1 && i<=100){
			cout<<i<<"\t\t"<<isPerfect(i)<<"\t\t"<<isPrime(i)<<"\t\t"<<isPerfectSquare(i)<<"\t\t\t"<<isSphenic(i)<<"\t\t"<<decimalToBinary(i)<<endl;
			if(i>=1 && i<= 10)
			less10++;
			else if(i>=11 && i<=20)
			less20++;
			else if(i>=21 && i<=30)
			less30++;
			else if(i>=31 && i<=40)
			less40++;
			else if(i>=41 && i<=50)
			less50++;
			else if(i>=51 && i<=60)
			less60++;
			else if(i>=61 && i<=70)
			less70++;
			else if(i>=71 && i<=80)
			less80++;
			else if(i>=81 && i<=90)
			less90++;
			else if(i>=91 && i<=100)
			less100++;
			Freq[x]=i;
			validVote++;
			x++;
		}
		else
		{
			invalidVote[j]=i;
			votes++;
			j++;
	}
	in>>i;
}
	cout <<endl;
	cout << "The invalid numbers are: "<<endl;
	for(j=0; j<votes; j++){
		cout <<invalidVote[j]<<" ";
		if((j+1)%5==0)
		cout <<endl;
	}
	cout<<endl<<endl;
	cout << "Range"<<"  	 " << "Histogram"<<endl;
	cout << "=====\t======="<<endl;
	cout << "1-10"<<"  	|";

	printStars(less10);
	cout << endl<<"11-20"<<"	|";
	
	printStars(less20);
	cout << endl <<"21-30"<<"	|";
	
	printStars(less30);
	cout << endl <<"31-40"<<"	|";
	
	printStars(less40);
	cout << endl <<"41-50"<<"	|";
	
	printStars(less50);
 	cout << endl <<"51-60"<<"   |";
 	
    printStars(less60);
	cout << endl <<"61-70"<<"	|";
	
	printStars(less70);
	cout << endl<<"71-80"<<"	|";
	
	printStars(less80);
	cout << endl <<"81-90"<<"	|";
	
	printStars(less90);
	cout << endl <<"91-100"<<"	|";
	printStars(less100);
	cout << endl<<endl;

	cout <<"The number of students who indicated a favorite number turned out to be "<<validVote<<" students"<<endl;
	cout <<"The number of students who indicated an invalid number turned out to be "<<votes<<" students"<<endl;
	cout <<"The number of students who chose not to indicate a favorite number turned out to be "<<notReveal<<" students"<<endl;
	cout <<endl;
	
	
	for(int i=0; i<105; i++){
		count=1;
		for(int j=i+1; j<105; j++){
			if(Freq[i]==Freq[j]){
				count++;
				mostFreq[j]=0;
			}
		}
		if(mostFreq[i]!=0){
			mostFreq[i]=count;
		}
		}
		cout <<"The Most Frequent numbers are: ";
		for(i=0; i<105; i++){
			if(mostFreq[i]>1){
				cout <<" "<< Freq[i];
			}
		}
		cout <<endl<<endl;
		
		for(i=0; i<105; i++){
			count=1;
			for(int j=i+1; j<105; j++){
				if(Freq[i]!=Freq[j]){
					count++;
					leastFreq[j]=0;
				}
			}
			if(leastFreq[i]==1){
				leastFreq[i]= count;
			}
		}
				cout <<"The least Frequent numbers are: ";
		for(i=0; i<105; i++){
			if(leastFreq[i]<=1){
				cout <<" "<< Freq[i];
			}
		}
		
	
	return 0;
}
