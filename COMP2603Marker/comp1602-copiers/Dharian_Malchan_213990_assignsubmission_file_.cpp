#include<iostream>
#include<fstream>
using namespace std;
	
	bool perfect (int a){
		int sum = 0;
		int i;
		for(i=1; i<=a/2; i++){
			if (a%i==0){
			sum+=i;	
			}
		}
			if (sum==a){
				return true;
			}
	return false;
	}
	
	bool prime (int a){
		int i;
		int check = 0;
		for(i=2; i<=a/2; i++){
			if (a%i==0){
			return false;
			}
		}
	return true;
	}
	
	bool perfectsquare (int a){
		int i;
		int mul=1;
		for(i=1; i<=10; i++){
			mul=i*i;
			if (mul==a){
			return true;	
			}
		}
	return false;	
	}
	
	bool sphenic (int a){
		int i, product, count;
		product=1;
		count=0;
		for(i=2; i<=a/2; i++){
			if (a%i==0 && prime(i)){
				product = product * i;
				count++;
					}
			}
		if(count==3 && product==a){
			return true;
		}
	return false;
	}
	
	int binaryEq (int a, int binary[8]){
		int i, mod;
		
		for (i=0; i<8; i++){
			mod = a%2;
			a/=2;             
			binary[i]=mod;
		}
	return 0;	
	}
	
	void histo (int range[10], int n){
		int a, i;
		a=range[n]/5;
		for(i=0; i<a; i++){
			cout<<"*";
		} 
	}
	
	int main () {
	ifstream numbers;		
	int num, binary[8], range[10], distinct[100], invalid[500], stats[101], i, count, j, valid, inval, notreveal;
	int lower, upper, count1=1;
	int l=1, r;
	bool dist=false, check=false;
	j=0;
	inval=0;
	valid=0;
	notreveal=0;	
	for(i=0; i<101; i++){
		stats[i]=0;
	}
	for(i=0; i<500;i++){
		invalid[i]=0;
	}
	for(i=0;i<8;i++){
		binary[i]=0;
		}	
	for(i=0;i<100;i++){
		distinct[i]=0;
	}
	for(i=0;i<10;i++){
		range[i]=0;
	}
	numbers.open("numbers.txt");
	
	if(!numbers.is_open()){
		cout<<"Input File not Found"<<endl;
		return 0;
		}	
			cout<<"Numbers          Perfect?      Prime?   Perfect Square?   Sphenic?      Binary Equiv."<<endl;
			cout<<"======           =======       ======   ===============   ========      ============="<<endl;;	
		
		numbers>>num;
		while(num != -1){
			for(i=0;i<100;i++){
				if(num==distinct[i]){
					dist=true;
				if(num>=1 && num<=100){
				valid += 1;	
				}
				}	
				else if(num<1 || num>100){
				dist = true;
				}
				}
			
			lower=1;
			upper=10;
			for(i=0;i<10;i++){
				if(num>=lower && num<=upper){
					range[i]+=1;
				}
				lower+=10;
				upper+=10;
				
			}
			
			if(num >= 1 && num <= 100 && !dist){
			dist=false;
			distinct[j]=num;
			j++;	
			valid++;
			
			cout<<num;
			
			if(perfect(num)){
			cout<<"                  Y";
			}	
			else
			cout<<"                 N"; 
			
			
			if(prime(num)){
			cout<<"             Y";
			}
			else
			cout<<"             N";
				
		
			if(perfectsquare(num)){
			cout<<"          Y";
			}
			else
			cout<<"          N";
			
			
			if(sphenic(num)){
			cout<<"                Y           ";	
			}
			else
			cout<<"                N           ";
			
			
			binaryEq(num, binary);
			for(i=7;i>=0;i--){
			cout<<binary[i];	
			} 
			cout<<endl;
			
			}
			else if(dist){
				dist=false;
				invalid[l]=num;
				l++;
				
				if(num<1 ||num>100)
				inval++;
				
				if(num==0){
				notreveal++;	
				}	
				}
			numbers>>num;		
		}
			cout<<endl;
			cout<<"Invalid Numbers"<<endl;
			cout<<"================"<<endl;
			for(count=1; count<l; count++){
				
				if(invalid[count]<0 || invalid[count]>100 ||invalid[count]==0 && !check){
				if(count1%5!=0){
				cout<<invalid[count]<<" ";
				count1++;
				if(invalid[count]==0){
					check=true;
				}
				}
				else{
				cout<<invalid[count];
				cout<<endl;	
				count1++;
				}
				}  
		}
			
			lower=1;
			upper=10;		
			cout<<endl;
			cout<<"Range     Histogram"<<endl;
			cout<<"===================="<<endl;
			for(i=0; i<10; i++){
			if(lower==1 && upper==10){
			cout<<lower<<"-"<<upper<<"       |";
			}
			else if(lower==91 && upper==100){
			cout<<lower<<"-"<<upper<<"     |";	
			}
			else{
			cout<<lower<<"-"<<upper<<"      |";	
			}
			histo(range, i);
			cout<<endl;	
			lower+=10;
			upper+=10;
			}  
			
			
			
			cout<<endl;
			cout<<"Statistics"<<endl;
			cout<<"==========="<<endl;
			cout<<"Valid student's numbers :"<<valid<<endl;
			cout<<"Invalid student's numbers :"<<inval<<endl;
			cout<<"Number of students who did not reveal :"<<notreveal<<endl;
			cout<<"The number/s that was/were chosen the most :"<<endl;
			for(i=1;i<101; i++){
				for(r=0; r<j; r++){                             
				if(distinct[r]==i){
				stats[i]+=1;		
				}	
				}
				for(r=0; r<l; r++){                               
				if(invalid[r]==i)
				stats[i]+=1;	
			}
			if(stats[i]>=2){
				cout<<i<<endl;
			}
			}
			cout<<endl;
			cout<<"The number/s that was/were chosen the least :"<<endl;
			for(r=1; r<101; r++){
				if(stats[r]==1){
					cout<<r<<endl;
				}
			}
			cout<<endl;
		numbers.close();
		return 0;
	}
