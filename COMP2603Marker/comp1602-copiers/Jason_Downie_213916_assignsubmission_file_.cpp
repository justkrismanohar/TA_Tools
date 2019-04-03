#include <iostream>
#include <fstream>

using namespace std;

bool isPrime(int num);
bool isSphenic(int num);
bool isPerfect(int num);
bool isPerfectSquare(int num);
void inBinary(int num);

bool isPerfect(int num)
{
	int i,divisor,total=1;
	for (i=2;i<=num/2;i++)
	{
		if (num%i==0)
		{
			divisor=i;
			total += divisor;
		}
	}
	if (num==total)
		return true;
	return false;
	
	
}

bool isPrime(int num)
{
	int i;
	for (i=2;i<=num/2;i++)
	{
		if(num%i==0)
		return false;
	}
	return true;
}

bool isPerfectSquare(int num)
{
	int i;
	for (i=2;i<=num/2;i++)
	{
		if (i*i==num)
			return true;
	}
	return false;
}

bool isSphenic(int num)
{
	int i,product=1,count=0;

	for(i=2; i<=num/2; i++)
	{
		if(num%i ==0 && isPrime(i))
		{
		product = product * i;
			count = count + 1;
		}
	}
	
		if(count==3 && product ==num)
			return true;
		return false;
	
}

void inBinary(int num)
{
	int remainder[8];
	for (int i=0;i<8;i++)
	{
		remainder[i]=num%2;
		num /= 2;
	}
	
	for (int i=7;i>=0;i--)
	cout<<remainder[i];
	cout<<endl;
}
 
int isDistinct (int numbers[], int size, int x)
{
	
	for(int i=0; i<size; i++)
	{
		if(numbers[i]==x)
		return i;
	}
	return -1;
}

int main()
{
	int num,numElements=0,inv=0,i=0,histogram=0,noU=0,valid=0,sizeD=0,uniqueIndex=0;
	int numbers[500],invalid[500],range[10]={0,0,0,0,0,0,0,0,0,0},unique[500],valnum[500],countU[500];
	char perfect,prime,psqr,sphenic;

	for(i=0; i<500; i++){
		countU[i]=0;
	}
	
	ifstream in;
	in.open("Numbers.txt");
	
		if(!in.is_open())
		{
		cout << "Error 404 file not found" <<endl;
		return 1;
		}
	
	in >> num;
	
	while(num!=-1)
	{
		numbers[numElements] = num;
		numElements++;
	if(num>=1 && num <= 100)
	{
	    valnum[valid] = num;
		valid++;
	}
	else if (num == 0)
	{
	    noU++;
	}
	else
		{
		invalid[inv]=num;
	    inv++;
	    }
		in >> num;
	}
	
	for(i=0; i<numElements; i++)
	{
		int indexFound = isDistinct (unique, sizeD, numbers[i]);
		if (indexFound !=-1)
		{
			countU[indexFound]++;
		}
		else
		{
			unique[uniqueIndex] = numbers[i];
			countU[uniqueIndex]++;
			uniqueIndex++;
			sizeD++;
		}
	}
	
	cout <<"Number\t\t Perfect?\t Prime?\t\t Perfect Square?\t Sphenic?\t Binary Equiv" <<endl;
	cout <<"======\t\t ========\t ======\t\t ===============\t ========\t ============" <<endl;
	for(uniqueIndex=0; uniqueIndex<sizeD; uniqueIndex++)
	{
		if(unique[uniqueIndex]>=1 && unique[uniqueIndex] <=100)
		{
	    if(isPerfect(unique[uniqueIndex]))
		{
	    perfect = 'Y';
	    }
	    else
		{
	    perfect = 'N';;
		}
		
		if(isPrime(unique[uniqueIndex]))
		{
			prime = 'Y';
		}
		else
		{
			prime = 'N';
		}
		
		if(isPerfectSquare(unique[uniqueIndex]))
		{
			psqr = 'Y';
		}
		else
		{
			psqr = 'N';
		}
		if(isSphenic(unique[uniqueIndex]))
		{
			sphenic = 'Y';
		}
		else
		{
			sphenic = 'N';
		}
	cout <<unique[uniqueIndex] <<"\t\t "<<perfect <<"\t\t " <<prime <<"\t\t " <<psqr <<"\t\t\t " <<sphenic <<"\t\t ";
	inBinary(unique[uniqueIndex]);
	}
	}
	
	cout<<endl;
		cout<<"Invalid inputs: "<<endl;
	for (i=0;i<inv;i++)
	{
		cout<<invalid[i]<<" ";
		
		if((i+1)%5==0)
		{
			cout<<endl;
		}
	}
	
	for (i=0;i<numElements;i++)
	{
	if ((numbers[i]>=1) && (numbers[i]<=10))
		range[0]++;
	if ((numbers[i]>=11) && (numbers[i]<=20))
		range[1]++;
	if ((numbers[i]>=21) && (numbers[i]<=30))
		range[2]++;
	if ((numbers[i]>=31) && (numbers[i]<=40))
		range[3]++;
	if ((numbers[i]>=41) && (numbers[i]<=50))
		range[4]++;
	if ((numbers[i]>=51) && (numbers[i]<=60))
		range[5]++;
	if ((numbers[i]>=61) && (numbers[i]<=70))
		range[6]++;
	if ((numbers[i]>=71) && (numbers[i]<=80))
		range[7]++;
	if ((numbers[i]>=81) && (numbers[i]<=90))
		range[8]++;
	if ((numbers[i]>=91) && (numbers[i]<=100))
		range[9]++;		
	}
	
	cout<<endl;
	cout<<endl;
	histogram=range[0]/5;
	cout<<"1-10:\t";
	for (i=0;i<histogram;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	
	histogram=range[1]/5;
	cout<<"11-20:\t";
	for (i=0;i<histogram;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	
	histogram=range[2]/5;
	cout<<"21-30:\t";
	for (i=0;i<histogram;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	
	histogram=range[3]/5;
	cout<<"31-40:\t";
	for (i=0;i<histogram;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	
	histogram=range[4]/5;
	cout<<"41-50:\t";
	for (i=0;i<histogram;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	
	histogram=range[5]/5;
	cout<<"51-60:\t";
	for (i=0;i<histogram;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	
	histogram=range[6]/5;
	cout<<"61-70:\t";
	for (i=0;i<histogram;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	
	histogram=range[7]/5;
	cout<<"71-80:\t";
	for (i=0;i<histogram;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	
	histogram=range[8]/5;
	cout<<"81-90:\t";
	for (i=0;i<histogram;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	
	histogram=range[9]/5;
	cout<<"91-100:\t";
	for (i=0;i<histogram;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	
	
	cout<<"Number of students who specified valid favourite numbers: "<<valid;
	cout<<endl;
	cout<<"Number of students who specified invalid favourite numbers: "<<inv;
	cout<<endl;
	cout<<"Number of students who did not specify valid favourite numbers: "<<noU;
	cout<<endl;	
	cout<<"The numbers that were chosen the most by students: ERROR"; //not sure on how to do these
	
	cout<<endl;
	cout<<"The numbers that were chosen the least by students: ERROR";
	
	
	
	
	
	
	
	
	
}
