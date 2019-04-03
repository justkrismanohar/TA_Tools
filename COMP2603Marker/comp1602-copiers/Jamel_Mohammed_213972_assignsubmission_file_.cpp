#include <iostream>
#include <fstream>
using namespace std;

bool isperfect(int num){
	int n=num,i=1,total=0;
	bool p;
	for(n=num;i<n;i++){
		if(n%i==0){
			total=total+i;
		}
	if(total==num){
		p=true;
	}
	else{
		p=false;
	}	
}
return p;
}//end of perfect function

bool isprime(int num){
	int n=num,i=2;
	bool prime=true;
	
		if(n==0 || n==1){
			prime=false;
		}
	for(n=num;i<n;i++){
		if(n%i==0){
			prime=false;
		}
	}
	return prime;
}//end of isprime function

bool isperfectsquare(int num){
	int n=num,sq=1,i=1;
	bool square=false;
	
	for(i=1;i<=num;i++){
		sq=i*i;
			if(sq==n){
				square=true;
			}
	}
	return square;
}//end of isperfectsquare function

bool issphenic(int num){
	int n=num,i=2,count=0,prod=1,half=n/2;
	bool sphenic;
	
	for (i=2;i<=half;i++){
		if(n%i==0&&isprime(i)){
			prod=prod*i;
			count++;
		}
	}
		if (count==3&&prod==n){
			sphenic=true;
		}
		else{
			sphenic=false;
		}
	return sphenic;
}//end of issphenic function

int findbinary(int num){
	int n=num,i,bits[8];
	
	for (i=0;i<=7;i++){
		bits[i]=0;
	}
	for(i=0;n>0;i++){
		bits[i]=n%2;
		n=n/2;
	}
	for(i=7;i>1;i--){
		cout<<bits[i];
		
	}
	return 0;
}//end of findbinary function



int main() {
	int numbers[1000]={0},i=0,fave,hate,valid=0,invalid=0,noreveal=0;
	bool ifperfect,ifprime,ifperfectsq,ifsphenic;
	int binaryeq;
	int range1=0,range2=0,range3=0,range4=0,range5=0,range6=0,range7=0,range8=0,range9=0,range10=0;
	ifstream in;
	in.open("/Users/nazimmohammed/Desktop/c++/816013068/numbers.txt");
	in>>numbers[i];
	
	while (numbers[i]!=-1){
		i++;
		in>>numbers[i];
		
	}// reading from the file
	
	fave=numbers[0];
	hate=numbers[0];
	
	cout<<"Number Perfect? Prime? Perfect Square? Sphenic? Binary Equiv."<<endl;
	cout<<"============================================================="<<endl;
	
	for (i=0;i<=999;i++){
		if (numbers[i]>=1&&numbers[i]<=100){
			valid++;
		
			if (numbers[i]==0){
			noreveal++;
			}
			if (fave==numbers[i]){
			fave=numbers[i];
			}
			else {
			hate=numbers[i];
			}
		
		ifperfect=isperfect(numbers[i]);
		ifprime=isprime(numbers[i]);
		ifperfectsq=isperfectsquare(numbers[i]);
		ifsphenic=issphenic(numbers[i]);
		binaryeq=findbinary(numbers[i]);
		
		cout<<numbers[i]<<ifperfect<<ifprime<<ifperfectsq<<ifsphenic<<binaryeq<<endl;	
	}
	else{
		invalid++;
		cout<<"invalid number:"<<numbers[i]<<endl;
	
	}
	
	}//end of for loop
	cout<<"range         histogram"<<endl;
	cout<<"======================="<<endl;
	
		for(i=0;i<=999;i++){
			if(numbers[i]>=1&&numbers[i]<=10)
				range1++;
			if(numbers[i]<=20)
				range2++;
			if(numbers[i]<=30)
				range3++;
			if(numbers[i]<=40)
				range4++;
			if(numbers[i]<=50)
				range5++;
			if(numbers[i]<=60)
				range6++;
			if(numbers[i]<=70)
				range7++;
			if(numbers[i]<=80)
				range8++;
			if(numbers[i]<=90)
				range9++;
			if(numbers[i]<=100)
				range10++;
		}//end of for loop
		
		cout<<"1-10 :"<<range1/5<<endl;
		cout<<"11-20:"<<range2/5<<endl;
		cout<<"21-30:"<<range3/5<<endl;
		cout<<"31-40:"<<range4/5<<endl;
		cout<<"41-50:"<<range5/5<<endl;
		cout<<"51-60:"<<range6/5<<endl;
		cout<<"61-70:"<<range7/5<<endl;
		cout<<"71-80:"<<range8/5<<endl;
		cout<<"81-90:"<<range9/5<<endl;
		cout<<"91-100:"<<range10/5<<endl;
		
		cout<<"number of valid entries:"<<valid<<endl;
		cout<<"number of invalid entries:"<<invalid<<endl;
		cout<<"number of unrevealed entries:"<<noreveal<<endl;
		
		cout<<"number chosen the most:"<<fave<<endl;
		cout<<"number chosen the least:"<<hate<<endl;
	
	return 0;
	
}//end of main