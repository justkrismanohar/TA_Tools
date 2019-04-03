#include <iostream>
#include <fstream>
using namespace std;

bool isPerfect(int n)
{
	if (n==1)
		return false;
		
	int sum = 0;
	sum++; // 1 is always a divisor
	for(int i=2; i<=(n/2); i++)
	{
		if (n%i==0)
			sum+=i;
	}
	
	if (n==sum)
		return true;
	else
		return false;
}

bool isPrime(int n)
{
	if (n==1)
		return false;
	
	if (n==2)
		return true;
		
	if (n%2==0)
		return false;
			
	for (int i=3; i<=(n/2); i++)
	{
		if (n%i==0)
			return false;	
	}
	return true;
}

bool isPerfectSquare(int n)
{
	int square = 0;
	
	if (n==1)
		return true;
		
	for (int i=1; i<=(n/2); i++)
	{
		if (n%i==0)
		{
			square = i*i;
			if (n==square)
				return true;
		}
	}
	return false;
}

bool isSphenic(int n)
{
	int count = 0, prod = 1;
	for(int i=2; i<=(n/2); i++)
	{
		if (isPrime(i) && (n%i==0))
		{
			prod = prod * i;
			count++;
			if (prod==n && count==3)
				return true;
			else if (prod!=3 && count==3)
				count = 2;
		}
	}
	return false;
}

void binaryEqu(int n)
{
	int binary[8]={}; //at least 7 since from 1 to 100, the max number of bits that can be used is 7
	int num = n, bit = 7, result = 0;
	while(num>0)
	{
		binary[bit] = num%2;
		num = num/2;
		bit--;
	}
	
	for (int i=0; i<=7; i++)
	{
		cout << binary[i];
	}	
}

void printStars(int n)
{
	for(int i=1; i<=n; i++)
	{
		cout << "*";
	}
}

int main()
{
	int n = 0, invalidCount = 0, actualNum = 0, zeroCount = 0, validCount = 0;
	int numbers[100]={};
	int invalid[100]={};
	ifstream in;
	in.open("numbers.txt");
	if (!in.is_open())
	{
		cout << "Error opening file numbers.txt." << endl << "Aborting..." << endl;
		return 0;
	}	
	
	//part a
	in >> n;
	while(n!=-1)
	{
		if(n>0 && n<101)
		{	
			numbers[n-1]++;
			validCount++;
		}
		else if (n==0)
			zeroCount++;
		else 
		{
			invalid[invalidCount]=n;
			invalidCount++;
		}	
		in >> n;
	}
	
	
	//part b
	cout << "Number\t\tPerfect?\tPrime?\t\tPerfect Square\t\tSphenic?\t\tBinary Equiv." << endl;
	cout << "======\t\t=========\t=======\t\t=============\t\t=========\t\t============" << endl;
	for(int i=0;i<100;i++)
	{
		if (numbers[i]!=0)
		{
			actualNum=i+1;
			cout << actualNum << "\t\t";
			if (isPerfect(actualNum))
				cout << "Y\t\t";
			else
				cout << "N\t\t";
				
			if (isPrime(actualNum))
				cout << "Y\t\t";
			else
				cout << "N\t\t";
				
			if (isPerfectSquare(actualNum))
				cout << "Y\t\t\t";
			else
				cout << "N\t\t\t";
				
			if (isSphenic(actualNum))
				cout << "Y\t\t\t";
			else
				cout << "N\t\t\t";
				
			binaryEqu(actualNum);
			cout << endl;
		}
	}
	
	//part c
	int x = 1;
	cout << endl << "Invalid numbers present: " << endl;
	while (x<=100 && invalid[x-1]!=0)
	{
			cout << invalid[x-1] << "\t";
		if (x%5==0)
			cout << endl;
		x++;
	}
	
	//part d
	int upperLimit = 10, lowerLimit = 1, starCount = 0, sum = 0;
	cout << endl << endl << "Range\tHistogram" << endl;
	cout << "===================" << endl;
	while(upperLimit<=100)
	{
		sum = 0;
		cout << lowerLimit << "-" << upperLimit <<  "\t:";
		for(int i=(lowerLimit-1);i<=(upperLimit-1);i++)
		{
			sum = sum + numbers[i];
		}
		printStars(sum/5);
		cout << endl;
		lowerLimit+=10;
		upperLimit+=10;
	}
	
	//part e
	int mostAmt = 0, leastAmt = 101;
	cout << endl << "The amount of students who specified valid favourite numbers were: " << validCount;
	cout << endl << "The amount of students who specified invalid favourite numbers were: " << invalidCount;
	cout << endl << "The amount of students who did not reveal their favourite number were: " << zeroCount;
	cout << endl;
	for (int i=0; i<100; i++)
	{
		if (numbers[i]>mostAmt && numbers[i]>=2)
			mostAmt = numbers[i];
	}
	
	cout << endl << "The number(s) that was/were chosen the most by the students: "; 
	for (int i=0; i<100; i++)
	{
		if (numbers[i]==mostAmt)
			cout << i+1 << "\t";
	}
	cout << "with " << mostAmt << " vote(s)." << endl;
	
		for (int i=0; i<100; i++)
	{
		if (numbers[i]<leastAmt && numbers[i]>=1)
			leastAmt = numbers[i];
	}
	
	cout << endl << "The number(s) that was/were chosen the least by the students: "; 
	cout << endl;
	for (int i=0; i<100; i++)
	{
		if (numbers[i]==leastAmt)
			cout << i+1 << "\t";
	}
	cout << "with " << leastAmt << " vote(s)." << endl;
	
	in.close();
	return 0;
}
