#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

char perfect(int a)
{
	int sum=0,i;
	for(i=2;i<=sqrt(a);i=i+1)
	{
		if(a%i==0)
		sum=sum+i+a/i;
		if(sum>a)
		return 'N';
	}
	if(sum+1==a)
	return 'Y';
	return 'N';
}

char prime(int a)
{
	int i;
	if((a==0)||(a==1))
	return 'N';
	
	if((a==2)||(a==3))
	return 'Y';
	
	for(i=2;i<=sqrt(a);i=i+1)
	{
		if(a%i==0)
		return 'N';
	}
	return 'Y';
}

char square(int a)
{
	int i;
	if(ceil(sqrt(a))==sqrt(a))
	return 'Y';
	return 'N';
}

char sphenic(int a)
{
	
	int factors[3],i;
	if(prime(a)=='Y')
	return 'N';
	for(i=2;i<=sqrt(a);i=i+1)
	{
		if(a%i ==0){
		factors[0]=a/i;
		factors[1]=i;
		break;
		}
	}
	
	if((prime(factors[1])=='Y')&&(prime(factors[0])=='Y'))
	return 'N';
	if((prime(factors[1])=='N')&&(prime(factors[0])=='N'))
	return 'N';
	
	if((prime(factors[0])=='N')&&square(factors[0])=='N')
	{
		for(i=2;i<=sqrt(factors[0]);i=i+1)
		{
			if(factors[0]%i==0){
				
				factors[2]=factors[0]/i;
				if((prime(factors[2])=='Y')&&(prime(i)=='Y')){
					factors[0]=i;
					if((factors[1]==factors[2])||(factors[1]==factors[0]))
					return 'N';
					
					return 'Y';	
				}
				else return 'N';
				
			}
		}
	}
	else if(square(factors[0])=='N')
	{
		for(i=2;i<sqrt(factors[1]);i=i+1)
		{
			if(factors[1]%i==0){
				
				factors[2]=factors[1]/i;
				if((prime(factors[2])=='Y')&&(prime(i)=='Y')){
					factors[1]=i;
					return 'Y';	
				}
				else return 'N';
				
			}
		}
	}
	return 'N';
}

void binary(int a)
{
	int i, bin[8];
	bin[0]=1;
	for(i=1;i<8;i=i+1)
		bin[i]=bin[i-1]*2;
		
	int j=0, final[8];
	for(i=7;i>=0;i=i-1)
	{
		if(a>=bin[i])
		{
			final[j]=1;
			a=a-bin[i];
		}
		else final[j]=0;
		
		j=j+1;
	}
	
	for(i=0;i<8;i=i+1)
	{
		cout<<final[i];
		if((i%7==0)&&(i!=0))
		cout<<endl;
	}
}

void histogram(int a)
{
	int i=0;
	a=a/5;
	for(i=1;i<=a;i=i+1)
		cout<<"*";
	cout<<endl;
}

void initialize_array(int a[],int size)
{
	int i;
	for(i=0;i<size;i=i+1)
		a[i]=0;
}


int main()
{
	ifstream fin;
	fin.open("numbers.txt");
	
	int number,count=0,invalnum=0,zeros=0;
	fin>>number;
	while (number!=-1)
	{
		count=count+1;
		if((number>100)||(number<1))
		{
			if(number==0)
			zeros=zeros+1;
			else
			invalnum=invalnum+1;
		}
		fin>>number;
	
	}
	
	fin.close();
	ifstream finn;
	finn.open("numbers.txt");
	
	int valnum,num;
	valnum=count-invalnum-zeros;
	int valid[valnum],invalid[invalnum];
	initialize_array(valid,valnum);
	initialize_array(invalid,invalnum);
	int i,val=0,inval=0;
	
	int all[100];
	initialize_array(all,100);
	
	
	finn>>num;
	
	for(i=0;i<count;i=i+1)
	{
		if((num<=100)&&(num>=1))
		{
			valid[val]=num;
			all[num-1]=all[num-1]+1;
			val=val+1;
		}
		else if(num!=0)
		{
			invalid[inval]=num;
			inval=inval+1;
		}
		finn>>num;
	}
	
	
	cout<<"Number"<<'\t'<<"Perfect?"<<'\t'<<"Prime?"<<'\t'<<"Square?"<<'\t'<<"Sphenic?"<<'\t'<<"Binary"<<endl;
	cout<<"======"<<'\t'<<"========"<<'\t'<<"======"<<'\t'<<"======="<<'\t'<<"========"<<'\t'<<"======"<<endl;
	
	for(i=0;i<valnum;i=i+1)
	{
		cout<<valid[i]<<'\t'<<perfect(valid[i])<<'\t'<<'\t'<<prime(valid[i])<<'\t'<<square(valid[i])<<'\t'<<sphenic(valid[i])<<'\t';
		cout<<'\t';
		binary(valid[i]);
	}
	cout<<endl;
	cout<<endl;
	cout<<"Invalid numbers in rows of 5 :"<<endl;
	for(i=0;i<invalnum;i=i+1)
	{
		cout<<invalid[i]<<'\t';
		if((i+1)%5==0)
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	
	int range[10],j,a;
	initialize_array(range,10);
		
	cout<<"Range"<<'\t'<<"Histogram"<<endl;
	cout<<"======================"<<endl;
	for(i=0;i<=9;i=i+1)
	{
		a=10*i;
		for(j=a;j<=a+9;j=j+1)
			range[i]=range[i]+all[j];
		
		cout<<a+1<<"-"<<a+10<<'\t';
		histogram(range[i]);
	}
	
	
	int greatest[100],smallest[100],numGreatest,numSmallest;
	initialize_array(greatest,100);
	
	initialize_array(smallest,100);
	greatest[0]=1;
	j=0;
	while(all[greatest[0]]<2)
	{
		j=j+1;
		greatest[0]=j;
		if(j==99)
		{;
			break;
		}
	}
	
if(j==99)
{
	cout<<"No number was chosen at least twice."<<endl;
}
else{
		greatest[0]=1;
		j=0;
	for(i=1;i<100;i=i+1)
	{
		if(all[i]==0)
		continue;
		if(all[i]==1)
		continue;
		if(all[i]==all[greatest[0]-1])
		{
			j=j+1;
			greatest[j]=i+1;
			continue;
		}
		if(all[i]>all[greatest[0]-1])
		{
			j=0;
			initialize_array(greatest,100);
			greatest[0]=i+1;
		}
		
	}
	if(j==0)
		cout<<"Most chosen number: "<<greatest[0]<<endl;
	else
	{
		cout<<"Most chosen numbers: "<<greatest[0];
		for(i=1;i<=j;i=i+1)
		{
			cout<<", "<<greatest[i];
		}
		cout<<endl;
	}
}
	

	smallest[0]=0;	
	j=0;
	while(all[smallest[0]]<1)
	{
		j=j+1;
		greatest[0]=j;
		if(j==99)
		{;
			break;
		}
	}
	if(j==99)
		cout<<"No number was chosen at least once."<<endl;
	else
	{
		smallest[0]=0;
		j=0;
		for(i=1;i<100;i=i+1)
		{
			if(all[i]==0)
			continue;
			if(all[i]==all[smallest[0]])
			{
				j=j+1;
				smallest[j]=i;
				continue;
			}
			if(all[i]<all[smallest[0]])
			{
				j=0;
				initialize_array(smallest,100);
				smallest[0]=i;
			}
		}
		
		if(j==0)
			cout<<"Least chosen number:"<<smallest[0]+1<<endl;
		else
		{
			cout<<"Least chosen numbers:"<<smallest[0]+1;
			for(i=1;i<=j;i=i+1)
			{
				cout<<", "<<smallest[i]+1;
			}
			cout<<endl;
		}
	}
	
	cout<<"Students who chose valid numbers   :"<<valnum<<endl;
	cout<<"Students who chose invalid numbers :"<<invalnum<<endl;
	cout<<"Students who chose not to say      :"<<zeros<<endl;
	
	
	
	return 0;
}
