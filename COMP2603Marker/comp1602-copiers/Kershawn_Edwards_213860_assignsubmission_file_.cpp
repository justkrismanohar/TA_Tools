#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
void hist(int arr[],int x)
{
	
	while(arr[x]>5)
	{
		if(arr[x]-5>=0)
		{
			cout<<"*";
		}
		arr[x]=arr[x]-5;
	}
}
void binary(int num)
{
	char let;
	int i=7,x=0;
	int bin[8]={0};
	while(i>=0)
	{
		bin[i]=num%2;
		num=num/2;
		i--;
	}
	for(x=0;x<8;x++)
	{
		cout<<bin[x];
	}
}
char sphenic(int num)
{
	char let;
	if((num==30)||(num==42)||(num==66)||(num==70)||(num==78))
	let='Y';
	else
	let='N';
	return let;
}
char square(int num)
{
	char let;
	int i=1;
	bool check;
	for(i=1;i<num;i++)
	{
		if(i*i==num)
		check=true;
	}
		if(check)
		let='Y';
		else
		let='N';
		
	
	return let;
}
char prime(int num)
{
	bool check;
	char let;
	int i=2;
	for(i=2;i<num;i++)
	{
		if(num%i==0)
		check=false;
	}
	if(check)
	let='Y';
	else
	let='N';
	return let;
}
	char perfect(int num)
	{
		char let;
		int i=1,sum=0;
		for(i=1;i<num;i++)
		{
			if(num%i==0)
			{
				sum+=num;
			}
		}
		if(sum==num)
		let='Y';
		else
		let='N';
		return let;
	}
int main()
{

	ifstream in;
	int num=0,x=1,count=0,check=0,b=0,c=0,coun=0;
	double dis[101]={0};
	int range[10]={0};
	int e=0,f=0,total=0,g=0,non=0,fav=0,least=1000;
	double invalid[1000]={0};
	int k=0,w=0,p=0;
	char pri,perf,squa,sphen,bin;
	in.open("numbers.txt");
	if(!in.is_open())
	{
		cout<<"File not found!";
	}
	in>>num;  
	cout<<"Number   Perfect? Prime?  Perfect Sphere?      Sphenic?  Binary Equiv.\n";
	cout<<"*******  ******** ******  ***************      ********* ************\n";
	
	while(num!=-1)
	{
		if((num>0)&&(num<101))
		{
			if(dis[num]<=0)
			{
				perf=perfect(num);
				pri=prime(num);
				squa=square(num);
				sphen=sphenic(num);
				cout<<left<<setw(10)<<num<<perf<<"            "<<pri<<"             "<<squa<<"              "<<sphen;
				cout<<"       ";
				binary(num);
				cout<<endl;
				
			}
			total+=1;
			dis[num]+=1;
			if(num<10)
			{
				range[0]+=1;
			}
			if((num>10)&&(num<=20))
			{
				range[1]+=1;
			}
			if((num>20)&&(num<=30))
			{
				range[2]+=1;
			}
			if((num>30)&&(num<=40))
			{
				range[3]+=1;
			}
			if((num>40)&&(num<=50))
			{
				range[4]+=1;
			}
			if((num>50)&&(num<=60))
			{
				range[5]+=1;
			}
			if((num>60)&&(num<=70))
			{
				range[6]+=1;
			}
			if((num<70)&&(num<=80))
			{
				range[7]+=1;
			}
			if((num>80)&&(num<=90))
			{
				range[8]+=1;
			}
			if((num>90)&&(num<=100))
			{
				range[9]+=1;
			}
		}	
		else if((num<0)||(num>100))
		{
			invalid[b]=num;
			b++;	
		}
		else if(num==0)
		{
			non++;
		}
		in>>num;
	}
		cout<<endl;
		cout<<"___________________________________________________________________________________________\n";
		cout<<endl;
		cout<<"INVALID NUMBERS\n";
	for(c=0;c<b;c++)
	{
		
		cout<<invalid[c]<<"  ";
		coun+=1;
		if(coun%5==0)
		{
			cout<<endl;
		}
	}
	cout<<"\n___________________________________________________________________________________________";
	
	cout<<endl;
	cout<<"\nRange         Histogram\n=======================================\n";
	cout<<"1-10        |";
	hist(range,0);
	cout<<"\n11-20       |";
	hist(range,1);
	cout<<"\n21-30       |";
	hist(range,2);
	cout<<"\n31-40       |";
	hist(range,3);
	cout<<"\n41-50       |";
	hist(range,4);
	cout<<"\n51-60       |";
	hist(range,5);
	cout<<"\n61-70       |";
	hist(range,6);
	cout<<"\n71-80       |";
	hist(range,7);
	cout<<"\n81-90       |";
	hist(range,8);
	cout<<"\n91-100      |";
	hist(range,9);
	num=num+1;
	for(k=1;k<=100;k++)
	{
		if((dis[k]>=fav)&&(dis[k]>1))
		{
			fav=dis[k];
		}
		if((dis[k]<=least)&&(dis[k]>0))
		{
			least=dis[k];
		}
		
	}
	cout<<"\n________________________________________________________________________";
	cout<<"\nNumber of students who specifed valid numbers: "<<total;
	cout<<"\nNumber of student who specified invalid numbers: "<<b;
	cout<<"\nNumber of students who did not reveal their number: "<<non;
	cout<<"\nNumber(s) that was chosen the most: ";
	
	for(w=1;w<=101;w++)
	{
		if(dis[w]==fav)
		{
			cout<<w<<" ";
		}
	}
	cout<<"\nNumber that was chosen the least: "<<least;
	for(p=1;p<=100;p++)
	{
		if(dis[p]==least)
		{
			cout<<p<<" ";
		}
	}
	"system pause";
	return 0;
}
