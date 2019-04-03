#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
int count_num()
{
	ifstream in;
	int count=0, num;
	in.open("numbers.txt");
	in>>num;
	while  (num!=-1)
	{
		count=count+1;
		in>>num;
	}
	return count;
}
int perfect(int numb)
{
	int sum=0, i,  div;
	
	for (i=1; i < numb; i++)
    {
        div = numb % i;
        if (div == 0)
            sum = sum + i;
    }
    if (sum == numb)
    {
    	return 0;
	}
	if (sum != numb)
	{
		return 1;
	}
}
int prime ( int numb)
{
	int i, count=0;
	for(i=2; i < numb; i++)                                              
	{
        if (numb % i == 0)
        count++;
    }
    if (count > 1)
    {
    	return 1;
	}
    if (count = 0)
    {
    	return 0;
	}
}

int perfect_square (int numb)
{
	int  i;
	for (i=1;i<=100;i++)
	{
		if (i*i==numb)
		return 0;
		else
		return 1;
	}
}
void binary(int numb)
{
	int i=0;
	int binary[100]; 
    while (numb > 0) 
    {
        binary[i] = numb % 2; 
        numb = numb / 2; 
        i++; 
    } 
    for (int x = i - 1; x>= 0; x--) 
    cout <<binary[x]; 
} 
int sphenic( int numb)
{
    int  i;
    int x=0, mult=1, n[3];
    i  =  1;
    while(  i  <=  numb  )
    {
        if( numb % i == 0 )
        {
            int j = 1, k = 0;
            while( j  <=  i)
            {
                if( i % j == 0 )
                k++;
                j++;
            }
            if( k == 2 )
            {
                n[x]=i;
                x=x+1;
			}
        }
        i++;
    }
    if (x==3)
    {
    	for (int l=0;l<3;l=l+1)
    	{
    		mult=mult*n[l];
		}
	}
	if (mult==numb){
	    return 0;
	}
    else{
    	return 1;
	}
}
int main()
{
	ifstream in;
	in.open("numbers.txt");
	int n,x,valid=0, invalid=0,nreveal=0,most,least,a=0,b=0,c=0,d=0,e=0,f=0,h=0,i=0,j=0,g=0;
	int perfectm, primem, square, sphenicm, binarym;
	n=count_num();
	int numb;
	cout<<"NUMBER"<<setw(20)<<"PERFECT?"<<setw(20)<<"PRIME?"<<setw(20)<<"PERFECT SQUARE?"<<setw(20)<<"Sphenic?"<<setw(20)<<"Binary"<<endl;
	for (x=0;x<n;x=x+1)
	{
		in >>numb;
		if (numb>=0||numb<=100)
		{
			valid=valid+1;
			if (numb==0)
			{
				nreveal=nreveal+1;
			}
			cout<<numb<<setw(20); 
			perfectm= perfect(numb);
			primem= prime(numb);
			square = perfect_square( numb);
			sphenicm=sphenic(numb);
			if (perfectm==0)
			{
				cout<<"Y"<<setw(20);
			}
			if (perfectm!=0)
			{
				cout<<"N"<<setw(20);
			}
			if (primem==0)
			{
				cout<<"Y"<<setw(20);
			}
			if (primem!=0)
			{
				cout<<"N"<<setw(20);
			}
			if (square==0)
			{
				cout<<"Y"<<setw(20);
			}
			if (square!=0)
			{
				cout<<"N"<<setw(20);
			}
			if (sphenicm==0)
			{
				cout<<"Y"<<setw(20);
			}
			if (sphenicm!=0)
			{
				cout<<"N"<<setw(20);
			}
			binary(numb);
			cout<<endl;
			if (numb>=1&&numb<=10)
			{
				a=a+1;
			}
			if (numb>=11&&numb<=20)
			{
				b=b+1;
			}
			if (numb>=21&&numb<=30)
			{
				c=c+1;
			}
			if (numb>=31&&numb<=40)
			{
				d=d+1;
			}
			if (numb>=41&&numb<=50)
			{
				e=e+1;
			}
			if (numb>=51&&numb<=60)
			{
				f=f+1;
			}
			if (numb>=61&&numb<=70)
			{
				g=g+1;
			}
			if (numb>=71&&numb<=80)
			{
				h=h+1;
			}
			if (numb>=81&&numb<=90)
			{
				i=i+1;
			}
			if (numb>=91&&numb<=100)
			{
				j=j+1;
			}
		}
	}
	cout<<"Valid:"<<valid<<endl;
	cout<<"Invalid:"<<valid-n<<endl;
	cout<<"Not revealed:"<<nreveal<<endl;
	int k,z,q;
	cout<<"RANGE"<<setw(20)<<"HISTOGRAM"<<endl;
	cout<<"1-10"<<setw(20);
	z=a/5;
	for (q=0;q<z;q=q+1)
	{
		cout<<"*";
	}
	cout<<endl;
	cout<<"11-20"<<setw(20);
	z=b/5;
	for (q=0;q<z;q=q+1)
	{
		cout<<"*";
	}
    cout<<endl;
	cout<<"21-30"<<setw(20);
		z=c/5;
		for (q=0;q<z;q=q+1)
		{
			cout<<"*";
		}
	cout<<endl;
	cout<<"31-40"<<setw(20);
		z=d/5;
		for (q=0;q<z;q=q+1)
		{
			cout<<"*";
		}
	cout<<endl;
	cout<<"41-50"<<setw(20);
	
		z=e/5;
		for (q=0;q<z;q=q+1)
		{
			cout<<"*";
		}
	cout<<endl;
	cout<<"51-60"<<setw(20);
	
		z=f/5;
		for (q=0;q<z;q=q+1)
		{
			cout<<"*";
		}
	cout<<endl;
	cout<<"61-70"<<setw(20);
	{
		z=g/5;
		for (q=0;q<z;q=q+1)
		{
			cout<<"*";
		}
	}
	cout<<endl;
	cout<<"71-80"<<setw(20);

		z=h/5;
		for (q=0;q<z;q=q+1)
		{
			cout<<"*";
		}
	cout<<endl;
	cout<<"81-90"<<setw(20);
		z=i/5;
		for (q=0;q<z;q=q+1)
		{
			cout<<"*";
		}
	cout<<endl;
	cout<<"91-100"<<setw(20);
		z=j/5;
		for (q=0;q<z;q=q+1)
		{
			cout<<"*";
		}
	cout<<endl;
	cout<<"Invalid Numbers"<<endl;
	
	
}
