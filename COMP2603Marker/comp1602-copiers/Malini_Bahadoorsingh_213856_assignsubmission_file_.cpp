#include<iostream>
#include<fstream>
using namespace std;
int perfect(int num);
int prime(int num);
int perfectsquare(int num);
int sphenic(int num);
int binary(int num);
int invalid1(int num);
int histogram(int num);
void display(int num);
int main()
{
	int stat1;
	int count=0;
	ifstream inputFile;
	int num,num1;
	int invalid[100];
	num1=0;
	inputFile.open("numbers.txt");
	inputFile>>num;
	cout<<"Number  Perfect?  Prime?  Perfect Square?   Binary Equivalent\n";
	cout<<"=============================================================\n";
	while(num!=-1)
	{
		if(num>=1&&num<=100)
		{
	      cout<<num<<"\t     ";
	    int perf=perfect(num);
	     if(perf==1)
	     {
	       cout<<"Y\t     ";
		 }
		 else
		 cout<<"N\t     ";
		int primenumber=prime(num);
		if(primenumber==1)
		{
		 cout<<"Y\t     ";
		}
		else
		cout<<"N\t     ";
		 int persq=perfectsquare(num);
		 if(persq==1)
		 {
		  cout<<"Y\t     ";
		 }
		 else
		 cout<<"N\t             ";
		 // sphenic( num);
		 binary( num);
		  
	}
		inputFile>>num;
	
		
	
	}
    invalid1(num);
    histogram(num);
    display(num);
    
   
    
	inputFile.close();
	return 0;
}
int perfect(int num)
{
	bool perf=1;
	int x=-1;
	if(num>=1&&num<=100)
	{
		if(((num/2)+(num/2)==num)||((num/4)*4==num))
		{
		return perf;
		}
		else
	     {
	     	perf=0;
	     	return perf;
				 }		
 }

 
	
}		
int prime(int num)
{
	int i;
	int p=1;
	int n=0;
	if(num>=1&&num<=100)
	{
	for(i=2;i<num/2;i++)
	{
		if((num%i==0))
		p=0;
		else
		n=1;
	}
	if(p==0)
	return 0;
	else if(p==1)
	return 1;
	else if(n==1)
	return 1;
	else if(n==0)
	return 0;
	
}

}
int perfectsquare(int num)
{
	if(num>=1&&num<=100)
	{
	int x=num/2;
	int i;
	int a=1;
	int b=0;
	for(i=2;i<=x;i++)
	{
		if((i*i==num))
		 a=0;
		 else
		 b=1;
				
	}
	if(a==0)
		return 1;
		else if(b==1)
     return 0;
}
}

int sphenic(int num)
{   int x,y,z,a;
	if(num>=1&&num<=100)
	{
		for(a=2;a<=num/2;a++)
		{
			if(num%a==1)
			{
				
			}
		}
	}
}
int binary(int num)
{
	int a[8];
	int x,y;
	int v=num;
	if(num>=1&&num<=100)
	{
		for(x=7;x>=0;x--)
		{
			a[x]=num%2;
			num=num/2;	
		}
	  for(x=0;x<8;x++)
	  cout<<a[x];
	  cout<<endl;
	}
	return a[8];
	
}
int invalid1(int num)
{
	int y;
	ifstream inputFile;
	inputFile.open("numbers.txt");
	inputFile>>y;
	
	int x;
	int count=0;
	int count2=0;
	cout<<"\n\n\n\n\n\\n\n";
	cout<<"=====================\n";
	cout<<"Invalid numbers :\n ";
	while(y!=-1)
	{
	if(y<1||y>100)
	{
	
		cout<<y<<"  ";
		count++;
		if(count==5)
	{
	  cout<<endl;
	  count=0;
    }
			
	}
	
	inputFile>>y;
}
	inputFile.close();
}
int histogram(int num)
{
	int x;
	ifstream inputFile;
	inputFile.open("numbers.txt");
	inputFile>>x;
    int ten=0;
    int twenty=0;
    int thirty=0;
    int forty=0;
    int fifty=0;
    int sixty=0;
    int seventy=0;
    int eighty=0;
    int ninety=0;
    int hundred=0;
    int inc1=0;
    int inc2=0;
    int inc3=0;
    int inc4=0;
    int inc5=0;
    int inc6=0;
    int inc7=0;
    int inc8=0;
    int inc9=0;
    int inc10=0;
    while(x!=-1)
    {
    	if(x>=1&&x<=10)
    	{
    	ten++;
        if(ten%5==0)
    	inc1++;
    }
    	else if(x>=11&&x<=20)
    	{
    	twenty++;
    	if(twenty%5==0)
    	inc2++;
    }
    	else if(x>=21&&x<=30)
    	{
    	thirty++;
    	if(thirty%5==0)
    	inc3++;
    }
    	else if(x>=31&&x<=40)
    	{
    	forty++;
    	if(forty%5==0)
    	inc4++;
    }
    	else if(x>=41&&x<=50)
    	{
    	fifty++;
    	if(fifty%5==0)
    	inc5++;
    }
    	else if(x>=51&&x<=60)
    	{
    	sixty++;
    	if(sixty%5==0)
    	inc6++;
    }
    	else if(x>=61&&x<=70)
    	{
    	seventy++;
    	if(seventy%5==0)
    	inc7++;
    }
    	else if(x>=71&&x<=80)
    	{
    	eighty++;
    	if(eighty%5==0)
    	inc8++;
    }
    	else if(x>=81&&x<=90)
    	{
    	ninety++;
    	if(ninety%5==0)
    	inc9++;
    }
    	else if(x>=91&&x<=100)
    	{
    	hundred++;
    	if(hundred%5==0)
    	inc10++;
    }
       inputFile>>x;
   
   }
	
	int a;
	cout<<"\n\n==================================\n\n\n";
	cout<<"RANGE\t\tHISTOGRAM\n";
	cout<<"========================\n";
	cout<<"1-10\t|";
	for(a=0;a<inc1;a++)
	 cout<<"*";
	cout<<"\n";
	cout<<"11-20\t|";
	for(a=0;a<inc2;a++)
	 cout<<"*";
	 cout<<"\n";
	 cout<<"21-30\t|";
	 for(a=0;a<inc3;a++)
	 cout<<"*";
	 cout<<"\n";
	  cout<<"31-40\t|";
	 for(a=0;a<inc4;a++)
	 cout<<"*";
	 cout<<"\n";
	  cout<<"41-50\t|";
	 for(a=0;a<inc5;a++)
	 cout<<"*";
	 cout<<"\n";
	  cout<<"51-60\t|";
	 for(a=0;a<inc6;a++)
	 cout<<"*";
	 cout<<"\n";
	  cout<<"61-70\t|";
	 for(a=0;a<inc7;a++)
	 cout<<"*";
	 cout<<"\n";
	  cout<<"71-80\t|";
	 for(a=0;a<inc8;a++)
	 cout<<"*";
	 cout<<"\n";
	  cout<<"81-90\t|";
	 for(a=0;a<inc9;a++)
	 cout<<"*";
	 cout<<"\n";
	  cout<<"91-100\t|";
	 for(a=0;a<inc10;a++)
	 cout<<"*";
	 cout<<"\n";
}
void display(int num)
{
  fstream openFile;
  openFile.open("numbers.txt");
  int x;
  int count=0;
  openFile>>x;
  while(x!=-1)
  {
  	if(x==0)
  	 count++;
  	 
	openFile>>x;
  }
  cout<<"Number of students that didn't give fave number ="<<count;

	
}
