#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;


bool perfect(int[],int);
bool prime(int[],int);
bool perfect_sq(int[],int);
bool sphenic(int[],int);
void binary(int[],int);
bool isprime(int);
void print_star(int [],int );



int main(){
	
	int num;int k=0;
	int numbers[300];
	int size=0;int a;
	int histogram[]={0,0,0,0,0,0,0,0,0,0};
	int invalid[300];int val_nums[300];
	int j=0;int freq[100];
	ifstream inputfile;
	inputfile.open("numbers.txt");
	
	if(inputfile==NULL)
     {
      cout<<"Sorry. Error opening file.\nCheck to see if file exists.";
     }
     
     else
	 {	
	 	cout<<"Number       Perfect?      Prime?      Perfect Square?       Sphenic?      Binary Equiv."<<endl;
     	inputfile>>num;
     	
		while(num!=-1)
		{	
			numbers[size]=num;
			inputfile>>num;
			size++;
		}
			
			
			for(int i=0;i<size;i++){
	
			if((numbers[i]>=1)&&(numbers[i]<=100))
			{
			val_nums[j]=numbers[i];
			
			if(val_nums[j]<=10){
				histogram[0]++;
			}
			else if(val_nums[j]<=20){
				histogram[1]++;
			}
			else if(val_nums[j]<=30){
				histogram[2]++;
			}
			else if(val_nums[j]<=40){
				histogram[3]++;
			}
			else if(val_nums[j]<=50){
				histogram[4]++;
			}
			else if(val_nums[j]<=60){
				histogram[5]++;
			}
			else if(val_nums[j]<=70){
				histogram[6]++;
			}
			else if(val_nums[j]<=80){
				histogram[7]++;
			}
			else if(val_nums[j]<=90){
				histogram[8]++;
			}
			else if(val_nums[j]<=100){
				histogram[9]++;
			}
			
			cout<<val_nums[j]<<"            ";
			
			if(perfect(val_nums,j)==true)
			{
				cout<<"Y          ";
			}
			else if(perfect(val_nums,j)==false){
				
				cout<<"N          ";
			}
			
			if(prime(val_nums,j)==true)
			{
				cout<<"Y                  ";
			}
			else if(prime(val_nums,j)==false){
				
				cout<<"N                  ";
			}
			
			if(perfect_sq(val_nums, j)==true)
			{
				cout<<"Y                  ";
			}
			else if(perfect_sq(val_nums, j)==false){
				
				cout<<"N                  ";
			}
			
			if(sphenic(val_nums, j)==true)
			{
				cout<<"Y                  ";
			}
			else if(sphenic( val_nums, j)==false){
				
				cout<<"N                  ";
			}
			
			binary( val_nums,j);
			
			
			cout<<endl;
			}
			else{
				invalid[k]=numbers[i];
				k++;
				j--;
			}
			j++;
			
			
			}
			
		}
		
		cout<<endl<<endl;
		int reveal=0;
		cout<<"Invalid Numbers: "<<endl;
			for( a=0;a<k;a++)
			{
				if(a%5==0){
					cout<<endl<<invalid[a]<<" ";
				}
				else
				{
					cout<< invalid[a]<<" ";
				}
				if(invalid[a]==0){
					reveal++;
				}
		}
		
		cout<<endl<<endl;
		
		int b=1;int c=10;
		cout<<"Range           Histogram"<<endl;
		for(int x=0;x<10;x++){
			cout<<b<<"-"<<c<<"            |";
			print_star(histogram,x);
			cout<<endl;
			b=b+10;
			c=c+10;
		}
		
		for(int w=0;w<100;w++){
			freq[w]=0;
		}
	
		
		for(int t=0;t<j;t++){
			
			freq[val_nums[t]-1]++;
			
			}
			
			
			int u=0;
			int d=0;
			int most=-1;
			int least=10000;
			int least_num[200];
			int most_num[200];
			
			for(int y=0;y<100;y++)
			{
				if(freq[y]>=2){
				
				if(most<freq[y]){
					
					most=freq[y];
					most_num[0]=y+1;
				}
				
			}
				
			
			 if(freq[y]>=1){
			
				if(least>freq[y]){
					
					least=freq[y];
					least_num[0]=y+1;
		
				}
			}
		}
		
		for(int n=0;n<100;n++){
			
			if(n!=most_num[0]-1){
			
			if(most==freq[n]){
				most_num[1+u]=n+1;
				u++;
			}
		   }
		   
			if(n!=least_num[0]-1){
			
			if(least==freq[n]){
				least_num[1+d]=n+1;
				d++;
			}
		  }
		  
		}
		
		
		
		int check=0;
		cout<<"Amount of students with valid numbers: "<<j<<endl;
		cout<<"Amount of students with invalid numbers: "<<a<<endl;
		cout<<"Amount of students who did not reveal their numbers: "<<reveal<<endl;
		
		cout<<"Number choosen the most: ";
		while(check<=u){
			
			cout<<most_num[check]<<" ";
			check++;
		}
		cout<<endl;
		
		check=0;
		cout<<"Number choosen the least:";
		while(check<=d){
			cout<<least_num[check]<<" ";
			check++;
		}
		
	inputfile.close();
	return 0;
}


bool perfect(int val_nums[],int j)
{
	bool perfect_num=false;
	int sum=0;
	for(int i=1;i<=(val_nums[j]/2);i++)
	{	
		if((val_nums[j]%i)==0)
		{
			sum=sum+i;
		}
	}
	
	if(sum==val_nums[j])
	{
		perfect_num=true;
	}
	else
	{
		perfect_num=false;
	}
	return perfect_num;
}

bool prime(int val_nums[],int j)
{
	bool prime_num=true;
	
	for(int i=2;i<=(val_nums[j]/2);i++)
	{
		if((val_nums[j]%i)==0)
		{
			prime_num=false;
			break;
		}
		
	}
	
	return prime_num;
}

 bool perfect_sq(int val_nums[],int j)
{
	bool sq_num=false;
	
	for(int i=1;i<=(sqrt(val_nums[j]));i++){
		
		if((sqrt(val_nums[j])==i))
		{
			sq_num=true;
			break;
		}
		else
		{
			sq_num=false;
		}
	}

	return sq_num;
}

 
 bool sphenic(int val_nums[],int j)
{
	
	bool sph=false;
	int count=0;
	int pri[20];
	for(int i=2;i<(val_nums[j]/2);i++)
	{
		if(val_nums[j]%i==0)
		{
			if(isprime(i)==true){
				pri[count]=i;
				count++;
			
			}
		}
		
	}
	int q=1;
	int r=2;
	
	for(int p=0;p<=count-3;p++)
		{
			if((pri[p]*pri[q]*pri[r])==val_nums[j])
			{
				sph=true;
				break;
			}
			r++;
			q++;
		}

	return sph;
}

bool isprime(int i)
{
	bool primes=true;
	for(int l=2;l<=(i/2);l++)
	{
		if((i%l)==0)
		{
			primes=false;
			break;
		}
		
	}
	return primes;
}



void  binary(int val_nums[],int j)
{
	int bin[]={0,0,0,0,0,0,0,0};
	int i=0;
	int num=val_nums[j];
	while(i<8)
	{
		bin[7-i]=num%2;
		num=num/2;
		
		i++;
		
	}
	for(int h=0;h<8;h++){
		cout<<bin[h];
	}
	
}


void print_star(int histogram[],int x){
	for(int z=1;z<=histogram[x]/5;z++){
		cout<<"*";
	}
	
}
