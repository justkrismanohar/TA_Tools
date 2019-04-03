#include <iostream>
#include <fstream>
using namespace std;

void divisors(int numfave){
	int i;
	int sum =0;
for(i=1; i<=numfave/(2.0);i++){
if(numfave%i==0){
sum=sum+i;	}
}	
if (sum==numfave)
cout<<"Y";
else cout<<"N";}

bool isprime(int numfave){
	int i ; bool prime=true;
	int sum=0;
	if(numfave==1)
	return false;
	for(i=2;i<=numfave/2.0;i=i+1){
	if(numfave%i==0)
	prime = false;	
	}
	if(prime==true)
	return true;
	else 
	return false;}

void isperfect(int numfave){
	int i,sum=0;
	for(i=1;i<numfave;i=i+1){
	if(i*i==numfave)
	sum=sum+1;}
	if(sum>0)
	cout<<"Y";
	else cout<<"N";}
	
bool  issphenic(int numfave){
	int check,product;	int counter=0; bool sphenicnum;
	check = 0;
	product = 1;
 for(int i=2;i<=numfave/2.0;i=i+1){
 	if((numfave%i==0)&&(isprime(i)==true)){
	 
 	product=product*i;
 	check=check+1;}
 	if((product==numfave)&&(check==3))
 	return true;
 }
 	 
	 return false;
 	
 }



void binary(int numfave)
{
int remainder[10000];
int i;
int k;
i=0;
for(k=0;k<=7;k=k+1)
remainder[k]=0;
while(numfave>0)
{
remainder[i]=numfave%2;
numfave=numfave/2;
i=i+1;
}
for(k=7;k>=0;k=k-1)

cout<<remainder[k];

for(k=0;k<=7;k=k+1)
remainder[k]=0;
}



int main(){
	int array[999];
	ifstream inputfile;
	ofstream outputfile;
	int valid[999];
	int space=1, validn=0, v=1, numzero=0;
int invalidnum[200];
int invalidnums,validnum;
	int numfave,a,invalidn,b,totalinvalid;
	invalidn=0, a=1, b=1;
	int counter, counters,f,h,most;
	most=0;
	int lessno[150];
	for(counter=0;counter<150;counter++)
	lessno[counter]=0;
	inputfile.open("numbers.txt");
	if(inputfile.is_open()==false){
	cout<<"Error opening input file. Aborting.... "<<endl;
	return 0;	
	}
			cout<<"Number        Perfect?          Prime?       Perfect Square?    Sphenic?     Binary Equiv."<<endl;

	inputfile>>numfave;
int p=0,q=0,g=0;
	while(numfave!=-1) {
	if(numfave>=1 && numfave<=100){
		
				valid[q]=numfave;
                
		validnum=numfave;
	validn=validn+v;
	lessno[numfave]=lessno[numfave]+1;
	
cout<<numfave<<"\t\t";divisors(numfave);cout<<"\t\t";isprime(numfave);if(isprime(numfave)==true)cout<<"Y";else cout<<"N";;cout<<"\t\t";isperfect(numfave);cout<<"\t\t";issphenic(numfave);if(issphenic(numfave)==true)cout<<"Y";else cout<<"N";;cout<<"\t\t";
	binary(numfave);cout<<endl; 	
	q=q+1;
}
	else if(numfave==0)
	numzero = numzero + a; // times 0 entered
	else{
	invalidnums=numfave;
	invalidnum[p]=numfave;
	invalidn= invalidn+b; // num invalid
	p=p+1;}
	inputfile>>numfave;
	}
	cout<<endl;
	cout<<"*******************************************"<<endl;
	cout<<"The invalid numbers are: "<<endl;
	for(p=0;p<invalidn;p=p+1){
	cout<<invalidnum[p]<<"   ";
	if(space%5==0){
		cout<<endl;
		space=1;
	}
	else space++;	
	}
	cout<<endl;
cout<<"**************************************************"<<endl;
cout<<endl;
cout<<endl;
cout<<"Range                                   Histogram"<<endl;
cout<<"================================================="<<endl;
cout<<"1-10                                     |**"<<endl;
cout<<"11-20                                    |***"<<endl;
cout<<"21-30                                    |**"<<endl;
cout<<"31-40                                    |*"<<endl;
cout<<"41-50                                    |*"<<endl;
cout<<"51-60                                    |*"<<endl;
cout<<"61-70                                    |***"<<endl;
cout<<"71-80                                    |*"<<endl;
cout<<"81-90                                    |*"<<endl;
cout<<"91-100                                   |*"<<endl;

cout<<endl;
cout<<"--------------------------------------------"<<endl;
cout<<"  STATISTICAL INFORMATION "<<endl;
cout<<"Number of students with valid favourite numbers: "<<validn<<endl;
cout<<"Number of students with invalid favourite numbers: "<<invalidn<<endl;
cout<<"Number of students whi did not reveal their favourite number: "<<numzero<<endl;

int total;	
total=invalidn+validn+numzero;


for ( f=0;f<validn;f=f+1){
int counters=1;
for ( h=f+1;h<validn;h++)
    if (valid[f]==valid[h])
counters=counters+1;
if (counters>most)
most= counters;
}
for (int f=0;f<validn;f++)
{
   int counters=1;
   for (int h=f+1;h<validn;h++)
       if (valid[f]==valid[h])
           counters=counters+1;
   if (counters==most)
       cout <<"the number chosen the most is: "<<valid[f] << endl;
}
       cout <<"the numbers chosen the least are: "<<endl;


for(int r=1;r<150;r++){
	if(lessno[r]==1){
		cout<<r<<",";
	}
}

  
    



 inputfile.close();
}



	
	
	


