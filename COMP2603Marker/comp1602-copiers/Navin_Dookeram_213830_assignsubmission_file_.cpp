#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
char is_perfect(int distinct){
	char perfect;
	int n,m,rem;
	int divisors[50];
	int sum;
	m=0;
	for(n=1;n<=distinct/2;n=n+1){
		rem=distinct%n;
		if(rem==0){
			divisors[m]=n;
			m=m+1;	
		}
	}
	sum=0;
	for(n=0;n<m;n=n+1)
	sum=sum+divisors[n];
	if(sum==distinct && distinct!=0)
	perfect='Y';
	else
	perfect='N';
	return(perfect);
}
char is_prime(int distinct){
	char prime;
	int p,rem;
	if(distinct==1)
	prime='N';
	for(p=2;p<=distinct/2;p=p+1){
		rem=distinct%p;
		if(rem==0){
			prime='N';
			break;
		}
	}
	if (prime!='N')
	prime='Y';
	return(prime);
}
char is_perfsq(int distinct){
	char perfsq;
	double root;
	root = sqrt(distinct);
	if(root==floor(root))
	perfsq='Y';
	else
	perfsq='N';
	return (perfsq);
}
char is_sphenic(int distinct){
	char sphenic;
	bool prime;
	int numprime;
	int k,n,m,rem,product;
	int divisors[50];
	int primes[30];
	m=0;
	for(n=1;n<=distinct/2;n=n+1){
		rem=distinct%n;
		if(rem==0){
			divisors[m]=n;
			m=m+1;	
		}
	}
	numprime=0;
	for(n=0;n<m;n=n+1){
		prime=true;
		if(divisors[n]==1)
		prime=false;
		for(k=2;k<=divisors[n]/2;k=k+1){
			rem=divisors[n]%k;
			if(rem==0){
				prime=false;
				break;
			}
		}
		if (prime!=false){
			primes[numprime]=divisors[n];
			numprime=numprime+1;
		}
	}
	product=1;
	for(n=0;n<numprime;n=n+1)
	product=product*primes[n];
	if(numprime==3 && product==distinct)
	sphenic='Y';
	else
	sphenic='N';
	return(sphenic);
}		
void binary(int distinct){
	int binary[7];
	int n,b,quotient,rem;
	quotient=distinct;
	b=0;
	while(b<7){
		rem=quotient%2;
		binary[b]=rem;
		quotient=quotient/2;
		b=b+1;
	}
	for(n=b-1;n>=0;n=n-1)
	cout<<binary[n];
}
void asterisks(int range){
	int q, numasterisk;
	numasterisk=range/5;
	for(q=1;q<=numasterisk;q=q+1)
	cout<<"*";
}
		
int main(){
	int number; int i,j,h,k,a,b,d;
	int numbers[500];
	int secrets[500];
	int invalids[500];
	int distincts[500];
	int count[500];
	int ranges[50];
	bool repeat;
	int max,min;
	ifstream inputFile;
	inputFile.open("numbers.txt");
	if (!inputFile.is_open()) {
		cout << "Error opening input file. Aborting...";
		return 0;
	}
 	else{
 		i=0;j=0;h=0;
 		inputFile>>number;
 		while(number!=-1){
			if(number>0 && number<=100){
			  numbers[i]=number;
			  i=i+1;
			}
			else{
				if(number==0){
					secrets[h]=number;
					h=h+1;
				}
				else{
					invalids[j]=number;
					j=j+1;
				}
			}
			inputFile>>number;
 		}
 		d=0;
 		distincts[d]=numbers[0];
 		a=1;
 		while(a<i){
 			for(b=0;b<a;b=b+1){
 				repeat=false;
 				if(numbers[b]==numbers[a]){
 					repeat=true;
 					break;
 				}
			}
			if(repeat!=true){
				d=d+1;
				distincts[d]=numbers[a];
			}
			a=a+1;
 		}
 		cout<<"Number	Perfect?	Perfect Square?	Sphenic?	Prime?	Binary Equiv."<<endl;
 		cout<<"_____________________________________________________________________________"<<endl;
 		for(a=0;a<=d;a=a+1){
 		cout<<distincts[a]<<"	"<<is_perfect(distincts[a])<<"		"<<is_perfsq(distincts[a])<<"		"<<is_sphenic(distincts[a])<<"		"<<is_prime(distincts[a])<<"	";
 		binary(distincts[a]);
 		cout<<endl;
		}
		cout<<endl;
		cout<<"Invalid Numbers:"<<endl;
		cout<<endl;
		k=0;
		while(k<j){
			cout<<invalids[k]<<" ";
			k=k+1;
			if (k%5==0)
			cout<<endl;
		}
		cout<<endl;
		cout<<endl;
		cout<<"Range"<<"	"<<"Histogram"<<endl;
	 	cout<<"_____________________"<<endl;
	 	for(k=0;k<10;k=k+1)
	 	ranges[k]=0;
	 	for(k=0;k<i;k=k+1){
			if((numbers[k]>0)&&(numbers[k]<=10))
	 		ranges[0]=ranges[0]+1;
	 		if((numbers[k]>10)&&(numbers[k]<=20))
	 		ranges[1]=ranges[1]+1;
	 		if((numbers[k]>20)&&(numbers[k]<=30))
	 		ranges[2]=ranges[2]+1;
	 		if((numbers[k]>30)&&(numbers[k]<=40))
	 		ranges[3]=ranges[3]+1;
	 		if((numbers[k]>40)&&(numbers[k]<=50))
	 		ranges[4]=ranges[4]+1;
	 		if((numbers[k]>50)&&(numbers[k]<=60))
	 		ranges[5]=ranges[5]+1;
	 		if((numbers[k]>60)&&(numbers[k]<=70))
	 		ranges[6]=ranges[6]+1;
	 		if((numbers[k]>70)&&(numbers[k]<=80))
	 		ranges[7]=ranges[7]+1;
	 		if((numbers[k]>80)&&(numbers[k]<=90))
	 		ranges[8]=ranges[8]+1;
	 		if((numbers[k]>90)&&(numbers[k]<=100))
	 		ranges[9]=ranges[9]+1;
	 	}
		cout<<"1-10"<<"	";
		asterisks(ranges[0]);
		cout<<endl;
	 	cout<<"11-20"<<"	";
		asterisks(ranges[1]);
		cout<<endl;
	 	cout<<"21-30"<<"	";
		asterisks(ranges[2]);
		cout<<endl;
	 	cout<<"31-40"<<"	";
		asterisks(ranges[3]);
		cout<<endl;
	 	cout<<"41-50"<<"	";
		asterisks(ranges[4]);
		cout<<endl;
	 	cout<<"51-60"<<"	";
		asterisks(ranges[5]);
		cout<<endl;
	 	cout<<"61-70"<<"	";
		asterisks(ranges[6]);
		cout<<endl;
	 	cout<<"71-80"<<"	";
		asterisks(ranges[7]);
		cout<<endl;
	 	cout<<"81-90"<<"	";
		asterisks(ranges[8]);
		cout<<endl;
	 	cout<<"91-100"<<"	";
		asterisks(ranges[9]);
		cout<<endl;
		cout<<endl;
		cout<<"Amount of students who specified valid favourite numbers: "<<i<<endl;
		cout<<"Amount of students who specified invalid favourite numbers: "<<j<<endl;
		cout<<"Amount of students who did not reveal their favourite number: "<<h<<endl;
		for(a=0;a<=d;a=a+1){
			count[a]=0;
			for(b=0;b<i;b=b+1){
				if(distincts[a]==numbers[b])
				count[a]=count[a]+1;
			}
		}
		max=count[0];
		min=count[0];
		for(a=1;a<=d;a=a+1){
			if(count[a]>max)
			max=count[a];
			if(count[a]<min)
			min=count[a];
		}
		cout<<endl;
		cout<<"Number/s that was/were chosen the most by the students:"<<endl;
		for(a=0;a<=d;a=a+1){
			if(count[a]==max)
			cout<<distincts[a]<<endl;
		}
		cout<<endl;
		cout<<"Number/s that was/were chosen the least by the students:"<<endl;	
		for(a=0;a<=d;a=a+1){
			if(count[a]==min)
			cout<<distincts[a]<<endl;
		}
	}
 	return 0;
 }
	
