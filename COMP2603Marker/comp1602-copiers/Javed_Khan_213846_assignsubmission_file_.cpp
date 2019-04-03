#include <iostream>
#include <fstream>
using namespace std;

bool Perfect (int num){
	int sum = 0;
	int i = 0;
	
	for (i = 1; i <= num/2; i = i + 1 ){
		if (num % i == 0){
			sum = sum + i;
		}
	}
	if (sum == num){
		return true;
	}
	return false;	
}

bool Prime (int num){
 int i = 0;
 	if(num == 1)
 		return false;
   for( i=2; i <= num / 2; i = i + 1) {
      if( num % i == 0) {
         return false;
      }
   }
   return true;
	}
	
bool PerfectSquare (int num){
	int i =0;
	if (num == 1)
		return true;
	for (i = 1; i <= num/2; i = i + 1 ){
		if (i * i == num){
			return true;
		}
	}
	return false;
}

bool Sphenic (int num){
	int i = 0;
	int pqr = 0;
	int product = 1;
	for (i =2; i<= num/2; i = i + 1){
		if (num % i == 0 && Prime (i)){
			product = product * i;
			pqr = pqr + 1;
		}
	}
	if (pqr== 3 && product == num){
		return true;
	}
	return false;
}

void BinaryRep (int num){
int n = 0;
int i = 0;
int bits [8]= {0};

n = num;

for (i = 0; n>0; i= i +1){
	bits[i]= n % 2;
	n= n/2;
}
cout<<"\t\t";
for (i=7; i>=0; i = i - 1){
	cout <<bits[i];
}
}

void Histogram (int minrange, int maxrange, int valid [], int numvalid){
	int i = 0;
	int count = 0;
	for (i=0; i<=numvalid; i = i +1){
		if ( valid[i] >= minrange && valid[i] <= maxrange){
			count = count +1;
			if (count % 5 == 0){
				cout<<"*";
			}
		}
		
	}
	cout<<endl; 
}

int main () 
{
	ifstream read;
	
	int num = 0;
	int i = 0;
	int x = 0;
	
	int file [500];  
	int valid  [500];
	int invalid  [500];
	int repeats [100] = {0};
	
	int distinct = 0;
	int nochoice = 0;
	int numvalid = 0;
	int numinvalid = 0;
	int votes =0;
	int leastvotes =9999;
	
read.open("numbers.txt");	

read >> num;
while (num != -1)
	{
	file [i] = num;
	i = i + 1;
    read >>num;
	}
	
for (x=0; x <= i - 1; x = x+1)
	{
	if (file[x] == 0)
		{
		nochoice = nochoice + 1;
		}
	else if (file[x] < 0 || file [x] > 100)
		{
		invalid[numinvalid] = file [x];
		numinvalid = numinvalid + 1;
		}
	else if (file[x] > 0 || file [x] <= 100)
		{
		valid[numvalid] = file [x];
		numvalid = numvalid + 1;
		}
	}
	
cout<<"Number\tPerfect?\tPrime\tPerfect Square?\tSphenic?\tBinary Equiv."<<endl;
cout<<"========================================================================================"<<endl;
	
for (i = 0; i<numvalid; i= i + 1)
	{
	distinct = valid[i];
	if ( repeats[distinct - 1] == 0){
		repeats[distinct - 1] = repeats[distinct - 1] + 1;
		cout<<distinct;
		
       if (Perfect(distinct)== 0){
       	cout<<"\t"<<"N";
	   }
	   else{
	   	cout<<"\t"<<"Y";
	   }
	   
	   if (Prime(distinct)==0){	
	   cout<<"\t\t"<<"N";
	   }
	   else{
	   	cout<<"\t\t"<<"Y";
	   }
	   
	   if (PerfectSquare(distinct)==0){
	   		cout<<"\t"<<"N";
	   }
	   else{
	   	cout<<"\t"<<"Y";
	   }
	   
	   if (Sphenic(distinct)==0){
	   		cout<<"\t\t"<<"N";
	   }
	   else{
	   	cout<<"\t\t"<<"Y";
	   }
	   
	  	BinaryRep(distinct);
	  cout<<endl;
		}
	else
	{	
	  repeats[distinct - 1] = repeats[distinct - 1] + 1;
	  }	

	}
	
cout<<endl;
cout<<"Invalid Numbers List :"<<endl;
for (x=1; x <= numinvalid; x = x+1){
	if (x % 5 == 0){
	cout<<invalid[x-1]<<endl;
}
 	else
    cout<<invalid[x-1]<<" ";
}
cout<<endl<<endl;


cout<<"Range\t\tHistogram"<<endl;
cout<<"======================="<<endl;

cout <<" 1 - 10\t\t";
Histogram (1,10,valid,numvalid);
cout <<" 11 - 20\t";
Histogram (11,20,valid,numvalid);
cout <<" 21 - 30\t";
Histogram (21,30,valid,numvalid);
cout <<" 31 - 40\t";
Histogram (31,40,valid,numvalid);
cout <<" 41 - 50\t";
Histogram (41,50,valid,numvalid);
cout <<" 51 - 60\t";
Histogram (51,60,valid,numvalid);
cout <<" 61 - 70\t";
Histogram (61,70,valid,numvalid);
cout <<" 71 - 80\t";
Histogram (71,80,valid,numvalid);
cout <<" 81 - 90\t";
Histogram (81,90,valid,numvalid);
cout <<" 91 - 100\t";
Histogram (91,100,valid,numvalid);
	

for (i=0; i<100; i = i+1){
	if (repeats[i] > votes){
		votes=repeats[i];

	}
}

for (i=0; i<=100; i = i+1){
	if (repeats[i] < leastvotes && repeats[i] != 0){
		leastvotes = repeats[i];
	}
}



cout<<endl<<endl;
cout<<"Students Who Did Not Choose : "<<nochoice<<endl;
cout<<"Valid Choices : "<<numvalid<<endl;
cout<<"Invalid Choices : "<<numinvalid<<endl;
cout<<"Most Voted Number : ";
for (i=0; i<100; i = i+1){
	if (repeats[i] == votes){
		cout<<i+1<<" ";
	}
}
cout<<endl<<"Least Voted Number : ";
for (i=0; i<100; i = i+1){
	if (repeats[i] == leastvotes){
		cout<<i+1<<" ";
	}
}



read.close();

return 0;

}	

