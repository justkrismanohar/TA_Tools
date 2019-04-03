#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool isPerfect(int n){
	int i=1,sum=0;
	
	while (i<n){
		if (n%i==0)
		sum=sum+i;
		i++;
	}
	
	if (sum==n)
		return true;
	else 
		return false;
	
}

bool isPrime(int n){
  int i;
  for(i=2;i<=sqrt(n);i++){
    if(n%i==0)
    return false;
  }
  return true;
}

bool isPerfectSquare(int n){

int r=1,i=1;
	while(r<n){
		i++;
		r=i*i;
	}
	if(r==n)
	return true;
	else
	return false;
}

bool isSphenic(int n){
	int i, count=0, product=1;
	
	for(i=2;i<=n/2;i++){
		if(n%1==0 && isPrime(i)){
			product=product*i;
			count++;
		}
		if(count==3 && product==n)
		return true;
	}
	return false;	
} 

void binaryGen(int n){
	int i, a[8];
	for(i=0; n>0; i++){
		a[i]=n%2;    
		n= n/2;  
	}    
  
	for(i=i-1 ;i>=0 ;i--)    
	cout<<a[i];        
}


int main(){
	
	ifstream inFile;
	
	inFile.open ("numbers.txt");
	if(!inFile.is_open()){
		cout<<"Error opening file.... Aborting."<<endl<<endl;
		return 0; 
	}
	
		cout<<"Number\t Perfect?\t Prime?\t Perfect Square?\t Sphenic?\t Binary Equivalent\n";
		cout<<"======\t ========\t ======\t ===============\t ========\t =================\n\n";
		
	int favnum[101], favnumCounter[101],histarr[10];
	int inTest, i,didNotReveal=0,invalid=0,valid=0;
	
	for(i=0;i<=100;i++)
	favnum[i]=i;	
	
	inFile>>inTest;
	while(inTest!=-1){ 
		if(inTest>=1 && inTest<=100){
			favnumCounter[inTest]++;
			
			cout<<inTest<<"\t";
			
			if(isPerfect(inTest)==true)
			cout<<"Y\t\t";
			else if(isPerfect(inTest)==false)
			cout<<"N\t\t";
			
			if(isPrime(inTest)==true)
			cout<<"Y\t\t";
			else if(isPrime(inTest)==false)
			cout<<"N\t\t";
			
			if(isPerfectSquare(inTest)==true)
			cout<<"Y\t\t";
			else if(isPerfectSquare(inTest)==false)
			cout<<"N\t\t";
			
			if(isSphenic(inTest)==true)
			cout<<"Y\t\t";
			else if(isSphenic(inTest)==false)
			cout<<"N\t\t";
			
			binaryGen(inTest);
			cout<<"\n";
			
			if(inTest>=1 && inTest<=10)
				histarr[0]++;
		
			if(inTest>=11 && inTest<=20)
				histarr[1]++;
				
			if(inTest>=21 && inTest<=30)
				histarr[2]++;
				
			if(inTest>=31 && inTest<=40)
				histarr[3]++;
				
			if(inTest>=41 && inTest<=50)
				histarr[4]++;
				
			if(inTest>=51 && inTest<=60)
				histarr[5]++;
				
			if(inTest>=61 && inTest<=70)
				histarr[6]++;
				
			if(inTest>=71 && inTest<=80)
				histarr[7]++;
				
			if(inTest>=81 && inTest<=90)
				histarr[8]++;
				
			if(inTest>=91 && inTest<=100)
				histarr[9]++;
			
			
			valid++;
		}
		else if(inTest==0)
			didNotReveal++;
		else if(!(inTest>=1 && inTest<=100))
			invalid++;
		inFile>>inTest;
	}
	cout<<"===============================================================================\n\n";
	
	cout<<"Range\t"<<" Histogram\n";
	cout<<"========================\n";
	
	cout<<"1-10\t"<<"|";for(int n=0;n<=(histarr[0]%5==0);i++)cout<<"*";
	cout<<endl;
	
	cout<<"11-20\t"<<"|";for(int n=1;n<=(histarr[1]%5==0);i++)cout<<"*";
	cout<<endl;
	
	cout<<"21-30\t"<<"|";for(int n=3;n<=(histarr[2]%5==0);i++)cout<<"*";
	cout<<endl;
	
	cout<<"31-40\t"<<"|";for(int n=6;n<=(histarr[3]%5==0);i++)cout<<"*";
	cout<<endl;
	
	cout<<"41-50\t"<<"|";for(int n=8;n<=(histarr[4]%5==0);i++)cout<<"*";
	cout<<endl;
	
	cout<<"51-60\t"<<"|";for(int n=11;n<=(histarr[5]%5==0);i++)cout<<"*";
	cout<<endl;
	
	cout<<"61-70\t"<<"|";for(int n=11;n<=(histarr[6]%5==0);i++)cout<<"*";
	cout<<endl;
	
	cout<<"71-80\t"<<"|";for(int n=14;n<=(histarr[7]%5==0);i++)cout<<"*";
	cout<<endl;
	
	cout<<"81-90\t"<<"|";for(int n=17;n<=(histarr[8]%5==0);i++)cout<<"*";
	cout<<endl;
	
	cout<<"91-100\t"<<"|";for(int n=18;n<=(histarr[9]%5==0);i++)cout<<"*";
	cout<<endl;
	
	
	cout<<"Amount of students who specified valid favorite numbers: "<<valid<<endl;
	cout<<"Amount of students who specified invalid favorite numbers: "<<invalid<<endl;
	cout<<"Amount of students who did not reveal their favorite number: "<<didNotReveal<<endl;
	
	return 0;
}
	
