#include <iostream>
#include <fstream>
using namespace std;

char isPerfect(int num[],int n){
	int i,sum=1,a;
	a=num[n];
	for(i=2;i<=a/2;i++){
		if(a%i==0){
			sum=sum+i;
		}
	}
		if ((n>0)&&(sum==a))
			return 'Y';
			
		return 'N';
}


char isPrime(int num[],int n){
	int i,a,k=0;
	a=num[n];
	for(i=2;i<=a/2;i++){
		if (a%i==0){
			k++;
		}
}
	if(k==0&&a!=1){
		return 'Y';
	}
	return 'N';
	
	
}

bool isPrimeSph(int n){
	int i,k=0;
	for(i=2;i<=n/2;i++){
		if (n%i==0){
			k++;
		}
}
	if(k==0&&n!=1){
		return true;
	}
	return false;
}

char isPerfectSquare(int num[],int n){
	int sq,i,a;
	a=num[n];
	for(i=1;i<=a/2;i++){
		sq=i*i;
		if(sq==a)
		return 'Y';
	}
	return 'N';
}

char isSphenic(int num[],int n){
	int i, count=0, product=1,a;
	char prime;
	a=num[n];
	for (i=2;i<=a/2;i++){
		prime=isPrimeSph(i);
		if ((n%i==0)&&(prime==true)){
		product=product*i;
		count=count+1;
		}
	}
		if ((product==n)&&(count==3)){
		return 'Y';
	}
	return 'N';
}

void isBinary(int num[],int n){
	int i=0,rem[8]={0},a;
	a=num[n];
	while (i<=7){
		rem[i]=a%2;
		a=a/2;
		cout<<rem[i];
		i++;
		}
}

int noReveal(int num[],int size){
	int i, noreveal=0;
	for (i=0;i<size;i++){
		if(num[i]==0)
		noreveal++;
	}
	return noreveal;
}

void isHist(int n){
	for(int i=1;i<=n/5;i++){
		cout<<"*";
	}
}

int main(){
	ifstream in;
	int n, num[200],i=0,invalidcount=0,validcount[200]={0},validNum[200]={0},invalidNum[200]={0},valid,range[10]={0},no,most=0, least=200, positionmax[200]={0},max,positionleast[200]={0},b=1,c=1,d,cnt=0;//,m,a,invalidcount=0,binary,no,valid=0;//most=1,least, validNum[200]={0}, mostNum[200]={0};
	int unique[200]={0};
	bool found=false;
	char per,pri,persq,sph;
	
	in.open("numbers.txt");
	if (!in.is_open()){
		cout<<"File not found...Aborting..."<<endl;
		return 0;
	}
	
	in>>n;
	
	while (n!=-1){
		num[i]=n;
		i++;
		in>>n;
	}
	

for(int r=0;r<i;r++){
		if ((num[r]<=100)&&(num[r]>=1)){
			validNum[r]=num[r];
			validcount[validNum[r]]++;
			valid++;
			}
	}
	
	
	cout<<"Number\t\tPerfect?\tPrime?\t\tPerfect Square?\t\tSphenic\t\tBinary Equiv."<<endl;
	cout<<"======\t\t========\t======\t\t===============\t\t========\t\t============="<<endl<<endl;
	
	for(int x=0;x<i;x++){
		if(validNum[x]!=0){
		per=isPerfect(validNum,x);
		pri=isPrime(validNum,x);
		persq=isPerfectSquare(validNum,x);
		sph=isSphenic(validNum,x);
		cout<<validNum[x]<<"\t\t"<<per<<"\t\t"<<pri<<"\t\t"<<persq<<"\t\t\t"<<sph<<"\t\t";
		isBinary(validNum,x);
		cout<<endl<<endl;
	}
	}
	
	cout<<"    Distinct Numbers"<<endl;
	cout<<"========================"<<endl;
	unique[cnt]=validNum[0];
	for(i=1;i<valid;i++){
		found=false;
		for(d=0;d<=valid;d++){
			if(validNum[i]==unique[d]){
				found=true;
			}
		}
		if(found==false){
			cnt=cnt+1;
			unique[cnt]=validNum[i];
		}
	}
	
	for(i=0;i<valid;i++){
		if(unique[i]!=0)
			cout<<unique[i]<<" ";
	}
	cout<<endl<<endl;
	cout<<"Invalid Numbers: "<<endl;
	for(int t=0;t<i;t++){
		if ((num[t]>100)||(num[t]<0)){
		invalidNum[t]=num[t];
		invalidcount++;
		if (t%4==0){
		cout<<endl;
	}
		cout<<invalidNum[t]<<" ";
		
		}
	}
	
	cout<<endl<<endl;
	for(int m=0;m<i;m++){
		if ((num[m]>=1) && (num[m]<=10))
		range[0]++;
		
		if ((num[m]>=11) && (num[m]<=20))
		range[1]++;
		
		if ((num[m]>=21) && (num[m]<=30))
		range[2]++;
		
		if ((num[m]>=31) && (num[m]<=40))
		range[3]++;
		
		if ((num[m]>=41) && (num[m]<=50))
		range[4]++;
		
		if ((num[m]>=51) && (num[m]<=60))
		range[5]++;
		
		if ((num[m]>=61) && (num[m]<=70))
		range[6]++;
		
		if ((num[m]>=71) && (num[m]<=80))
		range[7]++;
		
		if ((num[m]>=81) && (num[m]<=90))
		range[8]++;
		
		if ((num[m]>=91) && (num[m]<=100))
		range[9]++;
	}
	
	
	cout<<"Range\tHistogram"<<endl;
	cout<<"===================="<<endl;
	int begin=1;
	int end=10;
	int star;
	for(int a=0;a<10;a++){
	star=range[a];
	cout<<begin<<"-"<<end<<"\t:";
	isHist(star);
	cout<<endl;
	begin=begin+10;
	end=end+10;
	}
	cout<<endl<<endl;
	
	no=noReveal(num,i);
	
	cout<<"The amount of people who specified valid favourite numbers: "<<valid<<endl;
	cout<<"The amount of people who specified invalid favourite numbers: "<<invalidcount<<endl;
	cout<<"The amount of student who did not reveal their favourite number: "<<no<<endl;
	
	for (int h=1; h<valid; h++){
		if(validcount[h]>most){
			most=validcount[h];
			positionmax[0]=h;
		}
		
		if((validcount[h]<least)&&(validcount[h]>=1)){
			least=validcount[h];
			positionleast[0]=h;
		}
	}
	for (int s = 0; s<valid; s++){
		if ((s!=positionmax[0])&&(most==validcount[s])){
			positionmax[b]=s;
			b++;
		}
		if((s!=positionleast[0])&&(least==validcount[s])){
			positionleast[c]=s;
			c++;
		}
	}
	cout<<"The number(s) chosen the most: "<<endl;
	for (int z=0; z<=b; z++){
		cout<<positionmax[z]<<"\t";
	}
	cout<<endl;
	cout<<"The numbers chosen the least: "<<endl;
	for (int v=0; v<=c; v++){
		cout<<positionleast[v]<<"\t";
	}
	
	
	in.close();
	return 0;
}
	
