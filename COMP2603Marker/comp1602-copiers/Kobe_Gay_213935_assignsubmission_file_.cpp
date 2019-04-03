# include <iostream>
# include <fstream>
#include <cmath>
using namespace std;

bool perfectNo (int num)
{
int div, sum=0;
bool perfect;
    for (int i=1; i<num; i++)
    {
        div = num % i;
        if (div == 0)
            sum = sum + i;
       
    }
    if (sum == num)
    {
    return true; 
	}
    else
    {
    return false;     
	}

}

bool primeNo (int num)
{
bool prime;
	for(int i=2; i=num/2; i++)
	{	
		if  (num % i==0)
		{
		return  false;
		}
		else
		{
		return  true;
		num++;
		}
	}
}
bool perfectSq (int num)
{
	int root;
	root= sqrt(num);
	if (num==root*root)
	{
	return true;

	}
	else 
	{	
	return false;
	}
}
bool sphenicNo (int num)
{
int product=1, count=0;

    for (int i=2; i<=num/2;i++)
    {
		if (num % i==0)
		{
		product=product*i;
		count= count + 1;
		}
    }
		if ((count==3)&&(product==num))
		 return true;
		else 
		 return false;
}
void binaryEquiv (int num)
{
int i, bit[7];
while ((num>0)&&(num<=100))
{ 
	for(i=0; num>0; i++)    
	{    
	bit[i]=num%2;    
	num= num /2;  
	}     
	for(i=i-1 ;i>=0 ;i--)    
	{    
	cout<<bit[i];    
	}	
}
}
void stars(int num)
{
	for(int i=1;i<=(num/5);i++)
	cout<<"*";
}


int main ()
{
int n, z, i=0, invalid[101], valid[101], arr[105];
int ten=0, twenty=0, thirty=0, fourty=0, fifty=0, sixty=0, seventy=0, eighty=0, ninety=0, hundred=0;
int sum=0, high=0, low=9999;
char perfect, prime, square, sphenic;
	
	for(int c=0;c<=100;c++)
	{
		valid[c]=0;
	}
	for(int c=0;c<=100;c++)
	{
		invalid[c]=0;
	}
	for(int c=0;c<=105;c++)
	{
		arr[c]=0;
	}
	
ifstream infile;

infile.open("numbers.txt");

	if (infile.fail()==true) 
	{
 		cerr<< "Error opening file. Closing ...";
 		return 0;
	}


	infile>>n;
	
while (n!=-1)
{
	if((n>=0)&&(n<=100))
	{
	 valid[n]=valid[n]+1;
     
	infile>>n;
	}
	else
	{

		if((n<-1)||(n>100))
		{
		
		invalid[i]=n;
		i++;
		infile>>n;
		}
	}
	
 	
}	
cout<<endl;
cout<<"Number"<<"\t"<<"Prefect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equiv."<<endl;
cout<<"------"<<"\t"<<"--------"<<"\t"<<"------"<<"\t"<<"--------------"<<"\t"<<"--------"<<"\t"<<"-------------"<<endl;

	for(int c=1; c<=100;c++)
	{

		if(perfectNo (c)==true)
		{
		perfect='Y';
		}
		
		else
		{
		perfect='N';
		}
	
		if(primeNo (c)==true)
		{
		prime='Y';	
		}
		
		else
		{
		prime='N';	
		}
		
		if(perfectSq (c)==true)
		{
		square='Y';	
		}
		
		else
		{
		square='N';	
		}
		
		if(sphenicNo (c)==true)
		{
		sphenic='Y';	
		}
		
		else
		{
		sphenic='N';	
		}
		

cout<<c<<" \t"<<perfect<<" \t \t"<<prime<<"\t\t"<<square<<"\t"<<sphenic<<" \t\t";
binaryEquiv(c);
cout<<endl;

	}
for (int c=1;c<=10;c++)
	{
	ten=ten+valid[c];
	}
	for (int c=11;c<=20;c++)
	{
	twenty=twenty+valid[c];	
 	}
 	for (int c=21;c<=30;c++)
	{
	thirty=thirty+valid[c];	
 	}
 	for (int c=31;c<=40;c++)
	{
	fourty=fourty+valid[c];	
 	}
 	for (int c=41;c<=50;c++)
	{
	fifty=fifty+valid[c];	
 	}
 	for (int c=51;c<=60;c++)
	{
	sixty=sixty+valid[c];	
 	}
 	for (int c=61;c<=70;c++)
	{
	seventy=seventy+valid[c];	
 	}
 	for (int c=71;c<=80;c++)
	{
	eighty=eighty+valid[c];	
 	}
 	for (int c=81;c<=90;c++)
	{
	ninety=ninety+valid[c];	
 	}
 	for (int c=91;c<=100;c++)
	{
	hundred=hundred+valid[c];	
 	}


cout<<"Range                   Histogram"<<endl;
cout<<"_________________________________"<<endl;
cout<<"1-10         |";
stars(ten);
cout<<endl;
cout<<"11-20        |";
stars(twenty);
cout<<endl;
cout<<"21-30        |";
stars(thirty);
cout<<endl;
cout<<"31-40        |";
stars(fourty);
cout<<endl;
cout<<"41-50        |";
stars(fifty);
cout<<endl;
cout<<"51-60        |";
stars(sixty);
cout<<endl;
cout<<"61-70        |";
stars(seventy);
cout<<endl;
cout<<"71-80        |";
stars(eighty);
cout<<endl;
cout<<"81-90        |";
stars(ninety);
cout<<endl;
cout<<"91-100       |";
stars(hundred);
cout<<endl;
cout<<endl<<endl<<endl;

cout<<"the following were invalid input given:"<<endl;
	int x=0;
		for (int c=0;c <i;c++)	
		{
		x++;
		cout<<invalid[c]<<"\t";
			if (x%5==0)
			{
			cout<<endl;
			}
		}

	for (int c=1;c<=100;c++)
	{
	sum=sum+valid[c];
	}
cout<<endl<<endl;	
cout<<"The amount of students with valid favourite numbers:"<<sum<<endl;
cout<<"The amount of students with invalid favourite numbers:"<<i<<endl;
cout<<"the amount of students that didn't specify a favourite number:"<<valid[0]<<endl;


for(int c=0;c<105;c++)
     {
     infile>>z;	
	 arr[c]=z;
	 
	 }
	 
for (int c=0; c<105;c++)
	if (arr[c]>high) 
	{
		high=arr[c];
	}
for (int c=0; c<105;c++)
	if (arr[c]<low) 
	{
		low=arr[c];
	}
	
cout<<"The most popular number is: "<<high<<endl;
cout<<"the least popular number is: "<<low<<endl;	

infile.close();
return 0;	
}
