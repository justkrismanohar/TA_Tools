#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


void maxNumber(int data[], int max)
{
	for(int i=1; i<=100; i++)
	{
		if(data[i]==max)
			cout<<i<<" ";

	}

}
	
void minNumber(int data[], int min)
{
	for(int i=1; i<=100; i++)
	{
		if(data[i]==min)
			cout<<i<<"  ";
	}

}

bool isPrime(int n)
{
	for(int i=2; i<=n/2; i=i+1)
	{
		if(n%i==0)
			return false;
	}
	
	if((n==0)||(n==1))
		return false;	
	
	
	return true;	
	
}
		
bool isPerfect(int n)
{
	int sum=0;	
	for(int i=1;i<=n/2; i++)
	{
		if(n%i==0)
			sum=sum+i;
		
	}
	
	if(sum==n)
	{
		return true; 
	}
	  else
	{
	  
		return false;
	}
}

bool isPerfectSquare(int n)
{
		
	if(n<0)
	{
		return false;
	}
		
	else 
	{
	
		int root=sqrt(n);
		return n==root*root;
	}				
			
}

bool isSphenic(int n)
{

	int mult=1, count =0;
	
	for(int i=2; i<=n/2; i++)
	{
	
		if((isPrime(i)) && (n%i==0))
		{
			mult=mult*i;
			count++;
		}
		
	}
	
	if(count==3 && mult==n)
	{
		return true;
	}
	else
	{
		return false;
	}

	
}

void isBinaryEquilvalent(int n)
{

	int rem[8]={0};
	int i=7;

	while(n!=0)
	{
		rem[i]=n%2;
		n=n/2;
		i=i-1;		
	}
	
	for (int k=0; k<=7;k++)
	{
		cout << rem[k];
	}
	
}
		
		
int main ()
{
	int data[101]={};
	int size=101;
	int n;
	int valid=0;
	int invalid=0;
	int neither=0;
	int range[10]={0};
	ifstream in;
	in.open("Numbers.txt");
	int max=-999;
	int min=99999;
	int invalidA[1000]={0};
	
	if(!in.is_open())
	{
		cout<<"Error opening file."<<endl;
		
	return 0;
	}
	
	in>>n;	
	
		
	while(n!=-1)
	{
		if(n>=1 && n<=100)
		{
		
			data[n]=data[n]+1;
			  valid++;		
		}
		else if(n==0)
		{
	
			data[n]=data[n]+1;
			neither++;
		}
		else 
		{
			invalidA[invalid]=n;
			invalid++;		
			
		}	
		
		if((n>=1) && (n<=10))
		{
			range[0]=range[0]+1;
		}
		
		if((n>=11) && (n<=20))
		{
			range[1]=range[1]+1;
		}
		
		if((n>=21) && (n<=30))
		{
			range[2]=range[2]+1;
		}
		
		if((n>=31) && (n<=40))
		{
			range[3]=range[3]+1;
		}
		
		if((n>=41) && (n<=50))
		{
			range[4]=range[4]+1;
		}
		
		if((n>=51) && (n<=60))
		{
			range[5]=range[5]+1;
		}
		
		if((n>=61) && (n<=70))
		{
			range[6]=range[6]+1;
		}
		
		if((n>=71) && (n<=80))
		{
			range[7]=range[7]+1;
		}
		
		if((n>=81) && (n<=90))
		{
			range[8]=range[8]+1;
		}
		
		if((n>=91) && (n<=100))
		{
			range[9]=range[9]+1;
		}
			
		in>>n;
	}
	
	int i=0;
	
	cout<<"Number\tprime?\tperfect?perfectSquare?\tsphenic?Binary Equilvalent?"<<endl;
	cout<<"======\t======\t====== \t============= \t=====\t=============="<<endl;
		
	for(i=1; i<=100; i++)
	{
		if(data[i]>0)
		{
		
			cout<< i << "\t";
			
			if(isPrime(i)==true)
			{
				cout<< "Y\t";
			} else {
				cout<< "N\t";
			} 

			if(isPerfect(i)==true)
			{
				cout<< "Y\t";
			} else {
				cout<< "N\t";
			}	

			if(isPerfectSquare(i)==true)
			{
				cout<<  "Y\t";
			} else {
				cout<<  "N\t";	
			}	
			
			if(isSphenic(i)==true)
			{
				cout<< "\tY\t";
			} else {
				cout<< "\tN\t";
			}
			
			isBinaryEquilvalent(i);
			cout<<endl;
			
				
		 	if(data[i]>max)
		 	{
				max=data[i];	
		 	}
		
		 	if(data[i]<min)
			{
		 		min=data[i];	
			}
								
		}	
	}
	
	cout<<endl;
	cout<<"Range \t "<<"Histogram \t "<<endl;	
	cout<<"=========================="<<endl;
					
						
	for(int i=0; i<=9; i=i+1)
	{
		int hist=range[i]/5;
		cout <<10*(i)+1<<"-"<<10*(i+1)<<"\t\t|";
		for(int j=0;j<hist;j=j+1)
			cout<<"*";
		cout<<endl;
	}
	
	cout <<endl;
	
	
	cout<<"The amount of students who specified valid favourite numbers: "<<valid<<endl; 
	cout<<"The amount of students who specified invalid favourite numbers: "<<invalid<<endl;
	cout<<"The amount of students who did not reveal their favourite number: "<<neither<<endl;
	
		
		if (max>=2)
		{
			cout <<"The number/s that was/were chosen the most by the students: ";
			maxNumber(data,max);
			cout<<endl;
		}
		
		if (min>=1)
		{
			cout <<"The number/s that was/were chosen the least by the students: ";
			minNumber(data,min);
			cout<<endl;
		}
return 0;	
}
