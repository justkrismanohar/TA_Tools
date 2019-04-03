#include <iostream>
#include <fstream>
using namespace std;

bool isValid (int num) {
	if (num>=0 && num<=100) 
		return true;
	return false;
}

bool distinctNum (int num, int arr[], int size) {
	for (int i=0; i<size; i++) {
		if (num==arr[i])
		return false;
	}
	return true;
}

bool isPerfect (int n) {
	int sum=0;
	for (int i=1; i<n; i++) {
		if (n%i==0) 
		sum=sum+i;
	}
	if (sum==n)
		return true;
	else
		return false;
}

bool isPerfectSquare (int n) {
	int sq;
	for (int i=1; i<=n/2; i++) {
		sq=i*i;
		if (sq==n)
		return true;
	}
	return false;
}

bool isPrime (int n) {
	int count=0;
	for (int i=1; i<n; i++) {
		if (n%i==0)
		count++;
	}
	if(count>1)
		return false;
	return true;
}

bool isSphenic (int n) {
	int count=0, product=1;
	for (int i=2; i<=n/2; i++) {
		if (n%i==0 && isPrime(i)==true) {
			product=product*i;
			count++;
		}
		if(count==3)break;
	}
	if (count==3 && product==n)
		return true;
	else
		return false;
}

void printBinary (int n) {
	int arr[8]={0,0,0,0,0,0,0,0}, i=0, k=0;
	 while (n!=0) {
	 	k=n%2;
	 	n=n/2;
	 	arr[i]=k;
	 	i++;
	 }
	 for (i=7; i>=0; i--)
	 	cout<<arr[i];
}

int main () {
	ifstream input; 
	input.open ("numbers.txt"); 
	
	int num, numbers[500], numElements=0, distinct[500]={0}, size=0, invalid[20]={0};
	input >>num;
	while (num != -1) {
		numbers[numElements] = num;
		numElements++;
		input>>num;	
	}
	cout<<"Number \t Perfect? \t Prime? \t Perfect Square? \t Sphenic? \t Binary Equivalent"<<endl;
	cout<<"====== \t ======== \t ====== \t =============== \t ======== \t ================="<<endl;
	cout<<endl;
		
	for(int i=0; i<numElements; i++) {
		if (isValid(numbers[i])==true) {
		    num=numbers[i];
		  
		    if (distinctNum(num,distinct,size)==true) {
				distinct[size] = num;
		    	size++;
		    }
		}	
	}

	for (int i=0; i<size; i++) {
		cout<<distinct[i]<<"\t ";
		if (isPerfect(distinct[i])==1) {
			cout<<"Y \t \t ";
		}
		else
		cout<<"N \t \t ";
		if (isPrime(distinct[i])==true) {
			cout<<"Y \t \t ";
		}
		else
		cout<<"N \t \t "; 
		if (isPerfectSquare(distinct[i])==true) {
			cout<<"Y \t \t \t ";
		}
		else 
		cout<<"N \t \t \t "; 
		if (isSphenic(distinct[i])==true) {
			cout<<"Y \t \t ";
		}
		else
		cout<<"N \t \t ";
		printBinary(distinct[i]);
		cout<<"\n";	
	}
	cout<<"\n";
	
	for(int i=0; i<numElements; i++) {
		if (isValid(numbers[i])==false) {
			if (i%5 == 0) 
				cout<<endl;
			else 
				cout<<numbers[i]<<"\t";
		}
	}
return 0;
}











