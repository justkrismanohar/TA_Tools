# include <iostream>
# include <fstream>
#include<sstream>
using namespace std;
bool isDistinct(int D){
if(D>0 && D<=100){
	return true;
}
	else
	return false;
}

bool isPerfect(int P){
int i;
int Divisor;
int Sum=0;
	for(i=1; i<P; i++){
		Divisor=P%i;
		if(Divisor==0){
		  	Sum=Sum+i;
		}
			
	}
	
	if(Sum==P){
	return true; 

	}
	
	else 
	return false;
	
}

bool isPrime(int A){
	int i;
	int n=1;
	for(i=2;i<=A;i++){
		if(A%i==0){
			n=n+1;
			
		}
		
	}

	if (n==2){
		return true;
	}
	
	else 
		return false;
}

bool isPerfectSquare(int a){
	int sqr=1;
	int count=1;
	int n;
	int square;
	for(int i=1;i<=n/2;i++){
		square=i*i;
		if(square==a){
			return true;
		}
					
	}
	return false; 
}

bool isSphenic(int n) {
	
int i, j,k;
int count= 0;
int product;

for(i=1; i <= n; i++){
	
	for (j=i+1;j<=n;j++){
	
	
		for(k=j+1;k<=n;k++){
			
			if(isPrime(i) && isPrime(j) && isPrime(k)){
				product = i*j*k;
				
					
			}
			
			
			if(product==n){
				return true;
			}
			
			
		}
}
}	

return false;	
	
}

void BNE (int b){
	int i;
	int binary[100];
	for(i=0; b>0; i++){
		
		binary[i] = b%2;
		b=b/2;
	}
	
	for(i=i-1;i>=0;i--){
		cout<<binary[i];
	}
}
void output (int number){
 int temp=0;
 int i;
 
 for(i=0;i<=number;i++){
 	
 	temp++;
 	
 	if(temp== 5){
 		cout<<"*";
 		temp=0;
	 }
 	
 	
 }
 
cout<<endl;

}

int main(){
	int num,zeros,L=0,temp2=0,first=0,second=0,third=0,fourth=0,fifth=0,sixth=0,seventh=0,eighth=0,ninth=0,tenth=0,z=0;
	int NotDisclosed=0;
	int Invalid[100];
	ifstream ifile;
	ifile.open("numbers.txt");
	if(!ifile.is_open()){
		cout<<"The File does not exist"<<endl;
		return 0;
		}
	cout<<"Number \t\tPerfect?\tPrime \t\tPerfect Square? \tSphenic? \tBinary Equiv "<<endl;
	cout<<"======\t\t"<<   "=======\t\t"<<  "=====\t\t"<<   "==========\t\t"<< "=======\t\t"<< "=========="<<endl;
	
		while(num!=-1){
			ifile>>num;
		if (num==0){
		NotDisclosed++;
		}	
			if(!(isDistinct(num)) && (num!=0)){
				Invalid[L]=num;
			
				L++;
				
				}
			
				if(isDistinct(num))	{   
				
						cout<<num<<"\t\t";
						bool Perfect=isPerfect(num);
						if(Perfect)
							cout<<"Y"<<"\t\t";
						else
							cout<<"N"<<"\t\t";
						bool Prime=isPrime(num);
						
						if(Prime) 
							cout<<"Y"<<"\t\t";
						else
							cout<<"N"<<"\t\t";
						bool PerfectSquare=isPerfectSquare(num);
						if(PerfectSquare)
						  	cout<<"Y"<<"\t\t\t";
						else
							cout<<"N"<<"\t\t\t";
						bool Sphenic=isSphenic(num);
						if(Sphenic)
							cout<<"Y"<<"\t\t";
						else
							cout<<"N"<<"\t\t";
							BNE(num);
							cout<<endl;
						}
				if(num>=1 && num <=10){
					
					first++;
				}
				
				else if(num>=11 && num <=20){
					
					second++;
				}
				
				else if(num>=21 && num <=30){
					
					third++;
				}
				
			  else	if(num>=31 && num <=40){
					
					fourth++;
				}
				
			  else 	if(num>=41 && num <=50){
					
					fifth++;
				}
				
			else	if(num>=51 && num <=60){
					
					sixth++;
				}
				
			else	if(num>=61 && num <=70){
					
					seventh++;
				}
				
			else 	if(num>=71 && num <=80){
					
					eighth++;
				}
				
			else	if(num>=81 && num <=90){
					
					ninth++;
				}
				
			else if(num>=91 && num <=100){
					
					tenth++;
				}
				
						
				}
				cout<<"Invalid Numbers are; "<<endl;
				for (z=0;z<L;z++){
					cout<<Invalid[z]<<" ";
					temp2++;
					
					if(temp2==5) {
						cout<<endl;
						temp2 =0;
					}
				}
			
			cout<<"Range\t"<<"Histogram"<<endl;
			cout<<"\t1-10\t"; output(first);
			cout<<"\t11-20\t"; output(second);
			cout<<"\t21-30\t"; output(third);
			cout<<"\t31-40\t"; output(fourth);
			cout<<"\t41-50\t"; output(fifth);
			cout<<"\t51-60\t"; output(sixth);
			cout<<"\t61-70\t"; output(seventh);
			cout<<"\t71-80\t"; output(eighth);
			cout<<"\t81-90\t"; output(ninth);
			cout<<"\t91-100\t"; output(tenth);
		cout<<NotDisclosed <<" students did not wish to disclose their favourite numbers"<<endl;
		}


		


