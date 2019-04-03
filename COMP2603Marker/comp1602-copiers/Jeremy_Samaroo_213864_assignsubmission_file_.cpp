#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

void isPerfect(int check)
{
	int sum=0;
	for(int i=1;i<=(check/2);i++)
	{
		if(check%i==0)
			sum += i;
	}
	if(sum==check)
		cout<<"\tY";
	else
		cout<<"\tN";
}
void isPrime(int check)
{
	bool Prime=true;
	for(int i=2;i<=(check/2);i++)
	{
		if(check%i==0)
			Prime=false;
	}
	if(Prime)
		cout<<"\t     Y";
	else
		cout<<"\t     N";
}

void isPerfectSquare(int check)
{
	bool PSquare = false;
	for(int i = 1;i*i<=check;i++)
	{
		if(i*i==check)
			PSquare=true;
	}
	if(PSquare)
		cout<<"\t\tY";
	else
		cout<<"\t\tN";
}

void isSphenic(int check)
{
	int Prime[6]={2, 3, 5, 7, 11, 13};
	bool sphenic = false;
	int Sum1;
	for(int i=2;i<6;i++)
	{
		Sum1=Prime[0]*Prime[1]*Prime[i];
		if(Sum1==check)
			sphenic = true;	
	}
	for(int i=4;i<6;i++)
	{
		Sum1=Prime[0]*Prime[i]*Prime[2];
		if(Sum1==check)
			sphenic = true;	
	}
	for(int i=4;i<6;i++)
	{
		Sum1=Prime[i]*Prime[2]*Prime[1];
		if(Sum1==check)
			sphenic = true;	
	}
	if(sphenic)
		cout<<"\t\t\tY\t";
	else
		cout<<"\t\t\tN\t";
}

void Binary(int check)
{
	int bits[7];
	for(int i=0;i<8;i++)
	{
		bits[i]=check%2;
		check = check/2;
	}
	for(int i = 7;i>=0;i--)
		cout<<bits[i];
}


int main()
{
	ifstream inputFile;
	int check;
	int invalid[999],invalidcount=1,valid=0,Valid[999];
	int zerocount=0;
	int Range[9];
	int arrcount[10000];// This was declared so large cause the program was not running with lower values
	int least;
	for(int i=0;i<10;i++)
		Range[i]=0;
	for(int i=0;i<10000;i++)
		arrcount[i]=0;
		
	inputFile.open("numbers.txt");
	if (!inputFile.is_open())
		{
 			cout << "Error opening input file. Aborting ...";
 			return 0;
		}
	cout<<"Number\tPerfect?     Prime\tPerfect Square?\t    Sphenic?\tBinary Equiv.\n======\t========     ======\t===============\t    ========\t=============\n";
	inputFile>>check;
	while(check!=-1)
	{
		if(check==0)
			zerocount++;
		if(check>=1&&check<=100)
		{
			arrcount[check]++;
			Valid[valid]=check;
			valid++;
			cout<<check;isPerfect(check);isPrime(check);isPerfectSquare(check);isSphenic(check);Binary(check);cout<<endl;
			if(check>=1&&check<=10)
				Range[0]++;
			if(check>=11&&check<=20)
				Range[1]++;
			if(check>=21&&check<=30)
				Range[2]++;
			if(check>=31&&check<=40)
				Range[3]++;
			if(check>=41&&check<=50)
				Range[4]++;
			if(check>=51&&check<=60)
				Range[5]++;
			if(check>=61&&check<=70)
				Range[6]++;
			if(check>=71&&check<=80)
				Range[7]++;
			if(check>=81&&check<=90)
				Range[8]++;
			if(check>=91&&check<=100)
				Range[9]++;			
		}
		if(check>100||check<0)
		{
			invalid[invalidcount]=check;
			invalidcount++;
		}
		inputFile>>check;
	}
	inputFile.close();
	cout<<"============================================\n";
	cout<<"\t     INVALID NUMBERS\n";
	cout<<"============================================\n";
	for(int i=1;i<invalidcount;i++)
	{
		cout<<invalid[i]<<" ";
		if(i%5==0)
			cout<<endl;
	}
	cout<<"\n============================================\n";
	cout<<"Range\t\tHistogram";
	cout<<"\n============================================\n";
	int j=0;
	for(int x=1;x<=100;x= x+10)
	{
		cout<<x<<"-"<<x+9<<"\t:";
		while(Range[j]>=5)
		{
			cout<<"*";
			Range[j]= Range[j] - 5;
		}
		cout<<endl;
		j++;
	}			
    	int h;
    	int pop = Valid[0];
    	int temp=0, tempCount, count=1;
   		for (int i=0;i<=valid;i++)
    		{
       			tempCount = 0;
       			temp=Valid[i];
      			tempCount++;
       			for(h=i+1;h<valid;h++)
        			{
            			if(Valid[h] == temp)
            			{
                			tempCount++;
                			if(tempCount > count)
                			{
                    			pop = temp;
                    			count = tempCount;
                			}
            			}
        			}			 
    		}	
	cout<<"\n============================================\n";
	cout<<"Amount of Valid Favoutrite Numbers					:"<<valid<<endl;
	cout<<"Amount of Invalid Favourite Numbers					:"<<invalidcount-1<<endl;;// -1 was placed there to take in account for setting invalidcount to 1 instead of 0.
	cout<<"Amount of Students that Didn`t Reveal their Favourite Number		:"<<zerocount<<endl;
	cout<<"Most Favourite Number 							:"<<pop<<endl;
	cout<<"Least Favourite Numbers							\n: ";
	int z=1;
	for(int i=0;i<100;i++)
	{
		if(arrcount[i]==1)
		{
			cout<<i<<"	";
			z++;
		}
		if(z==5)
		{
			z-=4;
			cout<<"\n: ";
		}
	}
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
