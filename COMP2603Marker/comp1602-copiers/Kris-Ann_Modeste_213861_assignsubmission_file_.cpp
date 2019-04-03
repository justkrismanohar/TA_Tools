#include <fstream>
#include <iostream>
using namespace std;

bool isPerfect (int num) {
	int sum=0, i;
	for(i=1; i<num; i=i+1){
		if (num%i==0)
		sum=sum+i;
	}
	
	if (sum==num)
		return true;

return false;

}

bool isPrime (int num) {
	int i;
	for(i=2; i<=num/2; i=i+1) {
		if (num%i==0)
			return false;
		}
return true;
		
}


bool PerfectSquare (int num) {
	int i;
	for(i=1; i<=num/2; i=i+1) {
		if (i*i==num)
			return true;
	}
return false;
}

bool isSphenic (int num) {
	int mult=1, i, count=0;
	for(i=2; i<=num/2; i=i+1) {
		if ( isPrime(i) && num%i==0 ) {
		mult=mult*i;
		count=count+1;
		}
	}
	
	if (count==3 && mult==num)
		return true;
		
return false;
	
}

void BinaryEquivalence (int num) {  
	int binary[8], i;    
	
	for(i=0; i<8; i=i+1)
		binary[i]=0;
		

		for(i=0; num>0; i=i+1) {    
			binary[i]=num%2;    
	  			num=num/2;  
		}    

		for(i=7; i>=0 ;i=i-1) {    
			cout<<binary[i];    
        } 
   
} 


void Histogram (int num) {
	int stars, i;
    stars=num/5;
for (i=0; i<stars; i=i+1) {
	cout<<"*";
}
cout<<endl;
}


int main () {
	int num, number, numbers[1000], i=0, binary[8], distinct[1000], nondistinct, distinctvalid=0, counter[100];
	int valid=0, count=0, invalidnum=0, invalid[1000], zeros=0, range[10], occurence=0, mode=0, modenum, least=1000, leastnum=0;
	ifstream input; 
	bool perfect=true, met=false;
	
input.open("numbers.txt");

	if (!input.is_open()) {
 		cout << "Error opening file." ;
		 return 0;
	}
	
	input>>num;
	
	while (num!=-1) {
		if (num!=0 && num>=1 && num<=100){
			numbers[i]=num;
			i=i+1;
			valid=valid+1;
		}
		else if (num==0) {
		zeros=zeros+1;
		invalid[invalidnum]=num;
		invalidnum=invalidnum+1;
		}
		else if (num<0 || num>100) {
			invalid[invalidnum]=num;
			invalidnum=invalidnum+1;
		}
	input>>num;
	}
	
input.close();

for (i=0; i<valid; i=i+1){
	distinct[i]=0;
}
	
for (i=0; i<valid; i=i+1) {
	for (count=0; count<distinctvalid; count=count+1)   // checks to see if the number has already been met in the distinct array
		if(numbers[i]==distinct[count])					// if it has already been met 
			met=true;      
			
			if (met==false) {
				distinct[distinctvalid]=numbers[i];
				distinctvalid=distinctvalid+1;
			}
	met=false;
}
	
	

cout<<"Number \t" <<"Perfect \t" <<"Prime \t" <<"Perfect Square \t" <<"Sphenic? \t" <<"Binary Equivalence \t" <<endl;



for (i=0; i<distinctvalid; i=i+1) {
	number=distinct[i];
	cout<<distinct[i] <<"\t";
	if (isPerfect(number))
		cout<<"Yes \t\t";
	else
		cout<<"No \t\t";

	
	if (isPrime(number))
		cout<<"Yes \t";
	else 
		cout<<"No \t";
	
	
	if (PerfectSquare(number))
		 cout<<"Yes \t\t";
	else
		cout<<"No \t\t";
		
	
	if (isSphenic(number))
		cout<<"Yes \t\t";
	else
		cout<<"No \t\t";
		
	BinaryEquivalence(number);
	
	cout<<endl <<endl;
	
}

cout<<"INVALID NUMBERS" <<endl;
for (i=0; i<invalidnum; i=i+1) {
	if (i%5==0)
	   cout<<endl;
	   cout<<invalid[i] <<" ";
	   
}

for (i=0; i<valid; i=i+1) {
			if ( (numbers[i]>=1) && (numbers[i]<=10) ) 
				range[0]=range[0]+1; 
			else if ( (numbers[i]>=11) && (numbers[i]<=20) )
				range[1]=range[1]+1; 
			else if ( (numbers[i]>=21) && (numbers[i]<=30) )
				range[2]=range[2]+1; 
			else if ( (numbers[i]>=31) && (numbers[i]<=40) )
				range[3]=range[3]+1; 
			else if ( (numbers[i]>=41) && (numbers[i]<=50) ) 
				range[4]=range[4]+1; 
			else if ( (numbers[i]>=51) && (numbers[i]<=60) )
				range[5]=range[5]+1; 
			else if ( (numbers[i]>=61) && (numbers[i]<=70) ) 
				range[6]=range[6]+1; 
			else if ( (numbers[i]>=71) && (numbers[i]<=80) ) 
				range[7]=range[7]+1; 
			else if ( (numbers[i]>=81) && (numbers[i]<=90) )
				range[8]=range[8]+1;
			else if (numbers[i]>=91 && numbers[i]<=100)
				range[9]=range[9]+1;
}
cout<<endl <<endl;
cout<<"Range \t\t" <<"Histogram" <<endl;
cout<<"1 to 10 \t"; Histogram(range[0]);
cout<<"11 to 20 \t"; Histogram(range[1]);
cout<<"21 to 30 \t"; Histogram(range[2]);
cout<<"31 to 40 \t"; Histogram(range[3]);
cout<<"41 to 50 \t"; Histogram(range[4]); 
cout<<"51 to 60 \t"; Histogram(range[5]);
cout<<"61 to 70 \t"; Histogram(range[6]);
cout<<"71 to 80 \t"; Histogram(range[7]);
cout<<"81 to 90 \t"; Histogram(range[8]);
cout<<"91 to 100 \t"; Histogram(range[9]);
			
cout<<endl <<endl;
			
for(i=0; i<distinctvalid; i=i+1){
occurence=0;
	for(count=0; count<valid; count=count+1) {
		if (distinct[i]==numbers[count]) 
			occurence=occurence+1;
	}
		if (occurence>mode){
			mode=occurence;
			modenum=distinct[i];
		}			
}



for(i=0; i<distinctvalid; i=i+1){
occurence=0;
	for(count=0; count<valid; count=count+1) {
		if (distinct[i]==numbers[count])
			occurence=occurence+1;
	}
			
		if (occurence<least){
			least=occurence;
			leastnum=distinct[i];
		}

				
}


for(i=0; i<distinctvalid; i=i+1) {
	for(count=0; count<valid; count=count+1) {
		if (distinct[i]==numbers[count])
			counter[i]=counter[i]+1;
	}
}



	
cout<<"The number of students who specified valid numbers: "<<valid <<endl;
cout<<"The number of students who specified invalid numbers: "<<invalidnum <<endl;
cout<<"The number of students who did not reveal their favourite number: "<<zeros <<endl;
	
cout<<"The number(s) chosen the most was/were ";
for(i=0; i<distinctvalid; i=i+1) {
	if(counter[i]==mode)
		cout<<distinct[i] <<" ";
}
cout<<"which was/were chosen " <<mode <<" time/s."<<endl;

		
	
	
	
cout<<"The number(s) chosen the least was/were(s) ";
for(i=0; i<distinctvalid; i=i+1) {
	if(counter[i]==least)
		cout<<distinct[i] <<" ";
}
cout<<"which was/were chosen " <<least <<" time(s)."<<endl;

return 0;

}
	
