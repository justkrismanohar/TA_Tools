#include <iostream>   
#include <fstream>   
#include <cmath>
using namespace std;  

//INTEGERS
int nc=0;                               //Number count
int arrrsize;
int count=0;
int fn=0;
int ac=0;
int a,b,c,d,e,f,g,hc,i,j,k;

//Char
string perf[100];
string prim[100];
string ps[100];
string sph[100];
string BE[100];

//ARRAYS
int numbers[500];
int invnum[101];
int allnum[101];
int array2[101];


void popular()
{
	int popular[101];
	for(int i=0; i<101; i++){
		popular[i]=0;
	}
	for(int i=0; i<count; i++){
		popular[numbers[i]]++;
	}
	int highfreqloc, highfreq=-1, lowfreqloc, lowfreq=1000;
	for(int i=0; i<nc; i++){
		if(popular[i]>highfreq && popular[i]>1){
			highfreq=popular[i];
			highfreqloc=i;
		}
		if(popular[i]<lowfreq && popular[i]>0){
			lowfreq=popular[i];
			lowfreqloc=i;
		}
	}
	cout <<"\nMost frequent number: " <<numbers[highfreqloc]<<endl;
	cout <<"\nLeast frequent number: " <<numbers[lowfreqloc]<<lowfreq;
}

histcounter(int num)
{
	if (num >= 1 && num<=10)
	{
		a++;
	}
		if (num >= 11 && num<=20)
	{
		b++;
	}
		if (num >= 21 && num<=30)
	{
		c++;
	}
		if (num >= 31 && num<=40)
	{
		d++;
	}
		if (num >= 41 && num<=50)
	{
		e++;
	}
		if (num >= 51 && num<=60)
	{
		f++;
	}
		if (num >= 61 && num<=70)
	{
		g++;
	}
		if (num >= 71 && num<=80)
	{
		hc++;
	}
		if (num >= 81 && num<=90)
	{
		i++;
	}
		if (num >= 91 && num<=100)
	{
		j++;
	}
}

void read()
{
	ifstream input_stream;
	input_stream.open("numbers.txt");
	int num;
	input_stream>>num;
	while(num!=-1)
	{	
		if(num > -1 && num<=100)
		{
			if(num==0)
				{
					fn++;
					nc++;
					ac++;
					allnum[ac]=num;
				}
			else{
			numbers[nc]=num;
			nc++;
			ac++;
			allnum[ac]=num;}
		}
		else
		{
			invnum[count]=num;
			count++;
			ac++;
			allnum[ac]=num;
		}
		histcounter(num);
		input_stream>>num;
	}
}


void perfect(int num)
{
	int i, div, sumI=0;
    for (int i=1; i < num; i++)
    {
        div = num % i;
        if (div == 0)
            sumI = sumI + i;
    }
    if (sumI == num)
        {cout <<"Y";}
    else{
        cout <<"N";}
}

void prime(int num)
{	
	int nI, i=1, iI, m=0;  
	bool flag=true;
	nI= num;
    m=nI/2;  
	for(iI = 2; iI <= m; iI++)  
  	{  
      if(nI % iI == 0)  
      {  
		flag = false;}
  	}  
	if (flag == true)
		{cout<<"Y";}
	else
		{cout<<"N";}
}

void perfectsquare(int num)
{
int r=1,iII=1;
float sq;
sq=sqrt(num);
if(sq==ceilf(sq))
	{cout<<"Y";}
else{
	cout<<"N";}
}

void sphenic(int num)
{
	if (num == 30 || num == 42 || num == 66 || num == 70 || num == 78)
	{
		cout<<"Y";
	}
	else 
	{cout<<"N";
	}
}

void binary(int nIV)
{
int a[10], iIV;       
for(iIV=0; nIV>0; iIV++)    
{    
	a[iIV]=nIV%2;    
	nIV= nIV/2;  
}      
	for(iIV=iIV-1 ;iIV>=0 ;iIV--)    
	{    
		cout<<a[iIV];    
	}
}

void Headerprint()
{
	cout<<"Number	Perfect?	Prime?	Perfect Square?		Sphenic?	Binary Equiv."<<endl;
	cout<<"=========================================================================================="<<endl;
}

void invprint()
{
	cout<<endl<<endl<<"~Invalid Numbers~"<<endl;
	int p=0;
	while(p<=count)
	{
		cout<<invnum[p]<<" ";
		p++;
		cout<<invnum[p]<<" ";
		p++;
		cout<<invnum[p]<<" ";
		p++;
		cout<<invnum[p]<<" ";
		p++;
		cout<<invnum[p]<<" ";
		p++;
		cout<<endl;
	}
}

hist()
{
	cout<<"\n\n"<<"Range\t"<<"  Histogram"<<endl;
	cout<<"==================================="<<endl;
	cout<<"1-10     : ";
		int aI=a/5;
		for(int h=1; h<=aI; h++)
		{
			cout<<"*";
		}
	cout<<endl;
	cout<<"11-20    : ";
		int bI=b/5;
		for(int h=1; h<=bI; h++)
		{
			cout<<"*";
		}
	cout<<endl;
	cout<<"21-30    : ";
		int cI=c/5;
		for(int h=1; h<=cI; h++)
		{
			cout<<"*";
		}
	cout<<endl;	
	cout<<"31-40    : ";
		int dI=d/5;
		for(int h=1; h<=dI; h++)
		{
			cout<<"*";
		}
	cout<<endl;		
	cout<<"41-50    : ";
		int eI=e/5;
		for(int h=1; h<=eI; h++)
		{
			cout<<"*";
		}
	cout<<endl;	
	cout<<"51-60    : ";
		int fI=f/5;
		for(int h=1; h<=fI; h++)
		{
			cout<<"*";
		}
	cout<<endl;	
	cout<<"61-70    : ";
		int gI=g/5;
		for(int h=1; h<=gI; h++)
		{
			cout<<"*";
		}
	cout<<endl;	
		cout<<"71-80    : ";
		int hI=hc/5;
		for(int h=1; h<=hI; h++)
		{
			cout<<"*";
		}
	cout<<endl;	
	cout<<"81-90    : ";
		int iI=i/5;
		for(int h=1; h<=iI; h++)
		{
			cout<<"*";
		}
	cout<<endl;	
	cout<<"91-100   : ";
		int jI=j/5;
		for(int h=1; h<=jI; h++)
		{
			cout<<"*";
		}
	cout<<endl;	
	
}

void amounts()
{
	cout<<"\n\nThe number of valid numbers are: "<<nc<<endl;
	cout<<"The number of invalid numbers are: "<<count<<endl;
	cout<<"The amount of students that did not reveal numbers: "<<fn<<endl;
	
	
}

int main()
{
	Headerprint();
	read();
	for(int i=0; i<nc; i++){
		cout <<numbers[i] <<"\t" ;
		perfect(numbers[i]); cout<<"\t\t" ; 
		prime(numbers[i]); cout<<"\t\t";
		perfectsquare(numbers[i]); cout<<"\t\t    ";
		sphenic(numbers[i]); cout<<"\t\t   ";
		binary(numbers[i]); cout<<"\t"; 
		cout <<endl;
	}
	invprint();
	hist();
	amounts();
	popular();
}
