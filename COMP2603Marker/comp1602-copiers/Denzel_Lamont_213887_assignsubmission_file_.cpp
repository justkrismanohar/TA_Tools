#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
const int top = 1000;
vector<int>least_pf(top,0);
void leastfrequent(int valid[],int vamt)
//816015213
{
	int min = vamt + 1;
	int least = -1;
	int count = 1;
	for(int toll = 1;toll<vamt;toll++)
	{
		if(valid[toll]==valid[toll - 1])
		count++;
		else
		{
			if(count<min)
			{
				min=count;
				least = valid[toll-1];
			}
		count = 1;
		}
	}
	if(count<min)
	{
		min=count;
		least=valid[vamt-1];
	}
	cout<<least<<"."<<endl;
}
void frequentnumber(int valid[],int vamt)
{
	int max = 0;
	for( int toll = 0; toll<vamt; toll++)
	{
		int count = 1;
		for ( int z = toll + 1; z<vamt;z++)
			if(valid[toll] == valid[z])
			count++;
			if(count>max)
			max = count;
	}
	for( int toll = 0;toll<vamt;toll++)
	{
		int count = 1;
		for(int z = toll+1;z<vamt;z++)
			if (valid[toll]==valid[z])
			count++;
		if(count==max)
		cout<<valid[toll]<<"."<<endl;
	}
}
void leastPrimefACTOR(int num)
{
	least_pf[1] = 1;
	for( int count = 2; count<=num; count++)
	{
		if(least_pf[count] == 0)
		{
			least_pf[count] = count;
			for( int i = 2 * count;i<=num; i+=count)
			{
				if (least_pf[i] ==0)
				least_pf[i] = count;
			}
		}
	}
}
bool isperfect(int num)
{
	int count = 0;
	int div = 0;
	int sum = 0;
	for ( count = 1; count<num; count++)
	{
		div = num % count;
		if ( div == 0)
		{
		sum += count;
	    }
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
bool isprime(int num)
{
	int count = 0;
	for( count = 2; count<=(num/2); count++)
	{
		if( num % count == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
bool isperfectsquare(int num)
{
	int count = 1, i = 1;
	while( count < num )
	{
		i++;
		count = i * i;
	}
	if (count==num)
	{
	return true;
	}	
	else
	{
	return false;
	}
}
bool issphenic(int num)
{
	set<int>s;
	while(num > 1)
	{
		int lpf = least_pf[num];
		int init_size = s.size();
		s.insert(lpf);
		if( s.size() == init_size||s.size()>3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
void dbconvert(int num)
{
	int binary[1000];
	int i = 0;
	while( num > 0)
	{
		binary[i] = num % 2;
		num = num / 2;
		i++;
	}
	for (int j = i - 1;j>=0;j--)
	{
		cout<<left<<binary[j];
	}
	cout<<endl;
}
int main()
{
	ifstream in;
	int num = 0;
	in.open("numbers.txt");
	in>>num;
	int lim = 0;
	int ulim = 0;
	int invalid[1000];
	int valid[1000];
	int iamt = 0;
	int vamt = 0;
	int zero = 0;
	cout<<left<<setw(10)<<"Numbers"<<setw(10)<<"Perfect?"<<setw(10)<<"Prime?"<<setw(20)<<"Perfect Square?"<<setw(10)<<"Sphenic?"<<setw(15)<<"Binary Equiv."<<endl;
	cout<<left<<setw(10)<<"======="<<setw(10)<<"========"<<setw(10)<<"======"<<setw(20)<<"=============="<<setw(10)<<"========"<<setw(15)<<"============="<<endl;
	cout<<" "<<endl;
	while(num!=-1)
	{
	if(num == 0)
	{
		zero+=1;
	}
if(num<1||num>100)
{
	invalid[iamt] = num;
	iamt++;
}
else
{

	valid[vamt] = num;
	bool perfect = isperfect(num);
	bool sphenic = issphenic(num);
	bool prime = isprime(num);
	bool psquare = isperfectsquare(num);
	cout<<left<<setw(10)<<num;
	if (perfect == true)
	{
		cout<<left<<setw(10)<<"Y";
	}
	else
	{
		cout<<left<<setw(10)<<"N";
	}
	if (prime == true)
	{
		cout<<left<<setw(10)<<"Y";
	}
	else
	{
		cout<<left<<setw(10)<<"N";
	}
	if (psquare == true)
	{
		cout<<left<<setw(20)<<"Y";
	}
	else
	{
		cout<<left<<setw(20)<<"N";
	}
	if (sphenic == true)
	{
		cout<<left<<setw(10)<<"Y";
	}
	else
	{
		cout<<left<<setw(10)<<"N";
	}
	vamt+=1;
	dbconvert(num);
	cout<<" "<<endl;
}
in>>num;
}
cout<<" "<<endl;
cout<<"The invalid numbers in the input are: "<<endl;
for (lim = 0; lim < iamt; lim++)
{
	for( int j = 0;j + 1<6;j++)
	{
		cout<<setw(4)<<invalid[lim]<<" ";
		lim++;
	}
	cout<<'\n';
}
//816015213
int histArray[10];
int check = 0;
while(check <= vamt)
{
	if(valid[check]>0 && valid[check]<11)
	{
		histArray[0]+=1;
	}
	else if( valid[check]>10 && valid[check]<21)
	{
		histArray[1]+=1;
	}
	else if( valid[check]>20 && valid[check]<31)
	{
		histArray[2]+=1;
	}
	else if( valid[check]>30 && valid[check]<41)
	{
		histArray[3]+=1;
	}
	else if( valid[check]>40 && valid[check]<51)
	{
		histArray[4]+=1;
	}
	else if( valid[check]>50 && valid[check]<61)
	{
		histArray[5]+=1;
	}
	else if( valid[check]>60 && valid[check]<71)
	{
		histArray[6]+=1;
	}
	else if( valid[check]>70 && valid[check]<81)
	{
		histArray[7]+=1;
	}
	else if( valid[check]>80 && valid[check]<91)
	{
		histArray[8]+=1;
	}
	else if( valid[check]>90 && valid[check]<101)
	{
		histArray[9]+=1;
	}
	check++;
}
//816015213
cout<<" "<<endl;
cout<<" "<<endl;
cout<<left<<setw(11)<<"Range"<<setw(20)<<"Histogram"<<endl;
cout<<left<<"==============================";
int rangeL = 1;
int rangeU = 10;
int count = 0;
int amt=0;
cout<<" "<<endl;

for (check = 0;check<10;)
{
	cout<<setw(2)<<rangeL<<setw(2)<<" - "<<setw(6)<<rangeU<<"|";
	while( histArray[amt]>0)
	{
		if(histArray[amt]>=5)
	{
		cout<<"*";
		count+=1;
		histArray[amt]-=5;
	}
	else break;
	}
	cout<<endl;
	check+=1;
	rangeL+=10;
	rangeU+=10;
	amt+=1;
}
int freq = 0;
cout<<endl;
cout<<endl;
cout<<left<<vamt<<" Students submitted a valid favourite number."<<endl;
cout<<left<<iamt<<" Students submitted an invalid favourite number."<<endl;
cout<<left<<zero<<" Students did not submit a favourite number."<<endl;
cout<<left<<"The most chosen number was ";
frequentnumber(valid,vamt);
cout<<left<<"The least chosen number was ";
leastfrequent(valid,vamt);
in.close();
//816015213
}


