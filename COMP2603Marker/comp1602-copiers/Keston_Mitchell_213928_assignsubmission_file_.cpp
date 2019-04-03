#include<iostream>

#include<fstream>

using namespace std;

bool isPerfect(int n, int i,int sum);
bool isPrime(int k);
bool isPerfectSquare(int m);
bool isSphenic(int z);
int displayBinary(int a, int p, int w);

int main (){
	
	int n,i,sum,k,m,z,a,p,w;
	
	isPerfect(n,i,sum);
	isPrime(k);
	isPerfectSquare(m);
	isSphenic(z);
	displayBinary(a,p,w);
	
	ifstream numberFile;
	
	int s_fav_num [101];
	int countfav_num [101];
	int test;
	int val_s_fav_num;
	int inval_s_fav_num;
	int ns_fav_num;//Students who didn't reveal their favorite number
	numberFile.open("numbers.txt");
	
	if(!numberFile.is_open()){
		cout<<"Error opening number file. Aborting...";
		return 0;
	}
	
	numberFile >> s_fav_num;
	numberFile >> test;
	numberFile >> val_s_fav_num;
	numberFile >> inval_s_fav_num;
	numberFile >> ns_fav_num;
	
	if(s_fav_num < -1){
	numberFile << "The program has stopped...";
	}	
	
	if(ns_fav_num == 0){
	numberFile << "The number is stored but not revealed...";	
	}
	
	if(val_s_fav_num > 1 || val_s_fav_num <=100){
		cout<<"The favorite number is VALID";
	}
	
	bool isPerfect(int n, int i,int sum){
		cout<<"Enter a number:";
		cin>>n;
		while(i<n){
			if(n%i==0);
				sum=sum+i;
					i++;
		if(sum==n){
		}
		return true;
		}
		return false;
		} 
	}
		
		bool isPrime(int k){
			int i;
		for(i=2;i<=n/2;i++)	
		if(n%i==0);
		return false;
		}
		return true;
		}
		
		bool isPerfectSquare(int m){
			for(int i=1;i<=m/2;i++)
				int sq = i*i;
					if(sq==m);
						return true;
							}
								return false;
									}
		}
		
		bool isSphenic (int z){
			int count = 0;
			int product = 1;
			
			for(int i=2;i<=z/2;i++){
				if(n%i==0 && isPrime(k)){
					product=product*i;
						count=count+1;
				}
			}
		}
		if(cout==3 && product==n)
		return true;
	}
		return false;
	}
		
		int displayBinary(int a, int p, int w){
			a[10];
			cout<<"Enter the number to convert:";
			cin>>p;
			for(int i=0;w>0;i++){
				a[i]=w%2;
				w=w/2;
			}
			cout<<"Binary of the given number =";
			for(i=i-1;i>=0;i--){
				cout<<a[i];
			}
		}
		return 0;
		}
		
		cout<<"Number\t Perfect?\t Prime?\t Perfect Square?\t Sphenic?\t Binary Equivalent"<<endl;
		cout<<"======\t ========\t ======\t ===============\t ========\t =================="<<endl;
		
		while(test!=-1){
			if(test>=1 && test <=100){				
				cout<<test<<"\t";
				
				if(isPerfect(test)==true)
				cout<<"Y\t";
				else if(isPerfect(test)==false)
				cout<<"N\t";
				
				if(isPrime(test)==true)
				cout<<"Y\t";
				else if(isPrime(test)==false)
				cout<<"N\t";
				
				if(isPerfectSquare(test)==true)
				cout<<"Y\t";
				else if(isPerfectSquare(test)==false)
				cout<<"N\t";
				
				if(isSphenic(test)==true)
				cout<<"Y\t";
				else if(isSphenic(test)==false)
				cout<<"N\t";
				
				displayBinary(test); //Binary Generator
			}
			
				if(s_fav_num > 100){
		cout<<"The favorite number is INVALID"<<s_fav_num<<s_fav_num<<s_fav_num<<s_fav_num<<s_fav_num<<endl;
	}
	
	cout<<"Range\t \t Histogram"<<endl;
	cout<<"===================="<<endl;
	
	for(int range=5;range<=10;num++){
		cout<<"*"<<endl;
	}
	for(int range=11;range<=20;num++){
		cout<<"*"<<endl;
	}
	for(int range=21;range<=30;num++){
		cout<<"*"<<endl;
	}
	for(int range=31;range<=40;num++){
		cout<<"*"<<endl;
	}
	for(int range=41;range<=50;num++){
		cout<<"*"<<endl;
	}
	for(int range=51;range<=60;num++){
		cout<<"*"<<endl;
	}
	for(int range=61;range<=70;num++){
		cout<<"*"<<endl;
	}
	for(int range=71;range<=80;num++){
		cout<<"*"<<endl;
	}
	for(int range=81;range<=90;num++){
		cout<<"*"<<endl;
	}
	for(int range=91;range<=100;num++){
		cout<<"*"<<endl;
	}
	
	cout<<"The amount of students who specified valid favorite numbers:"<<val_s_fav_num;
	cout<<"The amount of students who specified invalid favorite numbers:"<<inval_s_fav_num;
	cout<<"The amount of students who did not reveal their favorite number:"<<ns_fav_num;
	cout<<"The number/s that was/were chosen the most by the students:"<<range;
	cout<<"The number/s that was/were chosen the least by the students:"<<range;
	
	numberFile.close();	
}

return 0;

}
}
		
		
		

