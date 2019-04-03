#include <iostream>
#include <fstream>
using namespace std;
int isDivisor(int a, int b){
	if(b%a==0)
	return a;
	else
return 0;
}
bool isPerfect(int n){
	int i,divisor,perfect;
	for (i=0;i<n;i++){
		divisor= isDivisor(n,i);
		perfect=perfect+divisor;
	}
	if(perfect==n)
	return true;
	else
return false;
}
bool isPrime(int n){
	int i;
	for(i=2;i<n/2;i++)
	if(n%i==0)
	return false;
	else
return true;
}
bool isPerfectSquare(int n){
	int sq;
	for(int i=1;i<=n/2;i++){
		sq=i*i;
		if(sq==n)
		return true;
		else
		return false;
	}
}
bool isSphenic(int n){
	int i,count=0,product=1;
	for(i=2;i<n/2;i++){
		if((n%i==0)&&(isPrime(i))){
			product=product*i;
			count=count+1;
		}
		if((count==3)&&(product==n))
		return true;
		else
		return false;
	}
}
void binaryNum(int n){
	int rem,i=0,j,arr[i];
	while(n>0){
		rem=n%2;
		arr[i]=rem;
		i++;
		n=n/2;
	}
	for(int w=8;w>i;w--){
		cout<<"0";
	}
	for(j=i-1;j>=0;j--){
	cout<<arr[j];
	}
	cout<<endl;
}
void histogram(int n){
	for(int i=0;i<n;i++)	
	cout<<"*";
	cout<<endl;
}
int main(){
	int invalids[100],max=-1,min=1,valid[350],range1,range2,range3,range4,range5,range6,range7,range8,range9,range10;
	bool perfect,prime,perfectsq,sphenic;
	int v=0,binarynum,n=0,student,invalid=0,count[10],num[101],a,empty=0,b,c,d,e,f,g,h,k,l,m;
	ifstream in;
	for(b=0; b<10; b++){
		count[b]=0;
	}
	for(c=1;c<101;c++){
		num[c]=0;
	}
	in.open("numbers.txt");
	if(!in.is_open()){
		cout<<"Error in opening file. Aborting....."<<endl;
		return 0;
	}
	
	cout<<"Number     Perfect?     Prime?      Perfect Square?   Sphenic?     Binary Equivalence"<<endl;
	cout<<"======     =======      ======      ===============   ========     =================="<<endl;	
	in>>student;
	while(student!=-1){ 
	if((student>=1)&&(student<=100)){
		v=v+1;
		cout<<student<<"          ";
		perfect=isPerfect(student);
		
		if(perfect==true)
		cout<<"Y               ";
		else
		cout<<"N               ";
	prime=isPrime(student);
		if(prime==true)
		cout<<"Y               ";
		else
		cout<<"N               ";
	perfectsq=isPerfectSquare(student);
		if(perfectsq==true)
		cout<<"Y               ";
		else
		cout<<"N               ";
	sphenic=isSphenic(student);
		if(sphenic==true)
		cout<<"Y               ";
		else
		cout<<"N               ";
		binaryNum(student);	
		num[student]++;
	}
		if(student==0){
			empty=empty+1;
		}
		if((student<0)||(student>100)){
			invalids[invalid]=student;
		invalid=invalid+1;
		}
	if((student>=1)&&(student<=10)){
			count[0]=count[0]+1;
		}
	if((student>=11)&&(student<=20)){
			count[1]=count[1]+1;
		}
	if((student>=21)&&(student<=30)){
			count[2]=count[2]+1;
		}
	if((student>=31)&&(student<=40)){
			count[3]=count[3]+1;
		}
	if((student>=41)&&(student<=50)){
			count[4]=count[4]+1;
		}
	if((student>=51)&&(student<=60)){
			count[5]=count[5]+1;
		}
	if((student>=61)&&(student<=70)){
			count[6]=count[6]+1;
		}
	if((student>=71)&&(student<=80)){
			count[7]=count[7]+1;
		}
	if((student>=81)&&(student<=90)){
			count[8]=count[8]+1;
		}
	if((student>=91)&&(student<=100)){
			count[9]=count[9]+1;
		}
	
	in>>student;
}
    	cout<<"The invalid numbers used are: "<<endl;
    	for(h=1;h<invalid;h++){
		cout<<invalids[h]<<" ";
		if(h%5==0)
		cout<<endl;
	}
	cout<<endl;
	cout<<"Range        Histogram"<<endl;
	cout<<"======================"<<endl;
	cout<<"1-10            |";
	range1=count[0]/5;
	histogram(range1);
	cout<<"11-20           |";
	range2=count[1]/5;
	histogram(range2);
	cout<<"21-30           |";
	range3=count[2]/5;
	histogram(range3);
	cout<<"31-40           |";
	range4=count[3]/5;
	histogram(range4);
	cout<<"41-50           |";
	range5=count[4]/5;
	histogram(range5);
	cout<<"51-60           |";
	range6=count[5]/5;
	histogram(range6);
	cout<<"61-70           |";
	range7=count[6]/5;
	histogram(range7);
	cout<<"71-80           |";
	range8=count[7]/5;
	histogram(range8);
	cout<<"81-90           |";
	range9=count[8]/5;
	histogram(range9);
	cout<<"91-100          |";
	range10=count[9]/5;
	histogram(range10);
	
	cout<<endl;
	cout<<endl;
	cout<<"Amount of students who specified valid favourite numbers: "<<v<<endl;
	cout<<"Amount of students who specified invalid favourite numbers: "<<invalid<<endl;
	cout<<"Amount of students that did not reveal their favourite number: "<<empty<<endl;
	cout<<"The number/s chosen the most was/were: ";
	for(d=1;d<=100;d++){
		if(num[d]>max)
		max=num[d];
	}
	for(e=1;e<=100;e++){
		if(num[e]==max)
		cout<<e<<"  ";
	}
	cout<<endl;
	cout<<"The number/s chosen the least was/were: ";
	for(f=1;f<=100;f++){
		if((num[f]<min)&&(num[f]>0))
		min=num[f];
	}
	for(g=1;g<=100;g++){
		if((num[g]==min)&&(num[g]>0))
		cout<<g<<"  ";
	}
	cout<<endl;
	in.close();
	return 0;
}

