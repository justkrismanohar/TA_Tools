#include <iostream>
#include <fstream>
using namespace std;

int isperfect(i){
	int sum=0;
	for(i=num, i<=num/2, i=i+1){
		if(num%i==0){
			sum=sum+num;
		}
		if(sum==num){
			cout<<num<<" is perfect"<<endl;
		}
	}
}

int isprime(i){
	for(i=2, i<=num/2, i=i+1){
		if(num%i!=0){
			cout<<num<<" is prime"<<endl;
		}
	}
}

int perfectsquare(i){
	for(i=1, i<=num/2, i=i+1){
		if(i*i==num){
			cout<<num<<" is a perfect square"<<endl;
		}
	}
}

int main(){
ifstream inputfile;
int num;

inputfile.open("numbers.txt");

if (!inputfile.is_open()) {
 cout << "Error opening input file. Aborting ...";
 return 0;
 } 
 
 inputfile >> num;
 
 while(num!=-1){
 	isperfect(num);
 	isprime(num);
 	perfectsquare(num);
 }

return 0;
}
