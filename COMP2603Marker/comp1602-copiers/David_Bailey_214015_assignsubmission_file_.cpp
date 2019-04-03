#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int valnum[100],invalnum[100],hidden[100];
//B (i)
bool isperfect(int num){
	int i=1,sum=0;
	for(i=1;i<num;i++){
		if(num%i==0)
		sum=sum+i;
	}
	if(sum==num)
		return true;
	return false;
}
//B (ii)
bool isprime(int num){
	int i;
	for (i=2;i<=num/2;i++){
	if(num%i==0)
		return false;//number isnt prime
}
return true;//number is prime	
}
//B (iii)
bool isperfectsqr(int num){
	int sqr;
	float halfnum=(num/2)*1.0;
	for(int i=1;i<halfnum;i++){
		sqr=i*i;
		if(sqr==num)
		return true;
	}
	return false;
}
//B (iv)
bool isSphenic(int num){
	int i,count,prod;
	prod=1;
	count=0;
	for(i=2;i<=num/2;i++){
		if(num%i==0&&isprime(i)){
			prod=prod*i;
			count++;
		}
	}
	if(count==3&&prod==num)
	return true;
return false;
}
void Binary_equiv(int num){
int biNum[8];
int i=0;
while (num>0){
	biNum[i]=num%2;
	num=num/2;
	i++;
}
for(int a=i-1;a>=0;a=a-1)
cout<<biNum[a];
}
void printstar(int num){
int i;
for(i=0;i<num;i++)
	cout<<"*";
	cout<<endl;
}
int main (){
	int num,i=0,valcount=0,invalco=0,c=0,valnum[100],invalnum[100],hidden[100],countINVAL=0;
	int range[10],bestnum[100];
	range[0]=0;
	range[1]=0;
	range[2]=0;
	range[3]=0;
	range[4]=0;
	range[5]=0;
	range[6]=0;
	range[7]=0;
	range[8]=0;
	range[9]=0;
	ifstream input;
	input.open("Numbers#1.txt");
	if(!input.is_open()){
		cout<<"Error opening Numbers file"<<endl;
}
cout<<"Number\tPerfect?\tPrime?\tPerfect Square?\tSphenic?\tBinary Equiv."<<endl;
cout<<"======\t========\t======\t===============\t========\t============="<<endl;
input>>num;
while(num!=-1){
	if(num>=1&&num<=100){//valid numbers
		valnum[valcount]=num;
		//isperfect
		if(isperfect(valnum[valcount]))
			cout<<valnum[valcount]<<"\tY";
		else
			cout<<valnum[valcount]<<"\tN";
		//isprime
		if(!isprime(valnum[valcount]))
			cout<<"\t\tN";
		else
			cout<<"\t\tY";
		//isperfectsqr
		if(isperfectsqr(valnum[valcount]))
			cout<<"\tY";
		else
			cout<<"\tN";
		if(isSphenic(valnum[valcount]))
			cout<<"\t\tY\t\t";
		else
			cout<<"\t\tN\t\t";
		//binaryconversion
		Binary_equiv(valnum[valcount]);
		cout<<endl;
		valcount++;
				
	}
	if(num<=-2||num>100){//invalid numbers
		invalnum[invalco]=num;
		invalco++;
	}
	if(num==0){//hidden favorite numbers
		hidden[c]=num;
		c++;
	}
	input>>num;
}
cout<<"==========================================================================\n====INVALID NUMBERS===="<<endl;
for(i=0;i<5;i++)
	cout<<invalnum[i]<<"\t";
	cout<<endl;
for(i=5;i<invalco;i++)
	cout<<invalnum[i]<<"\t";
	cout<<endl<<"======================================================================\nRANGE\tHISTOGRAM"<<endl;
	cout<<"======================================================================"<<endl;
//HISTOGRAM
int stars[10];
for(i=0;i<valcount;i++){
	if(valnum[i]>=1&&valnum[i]<=10){
		range[0]++;
		stars[0]=floor(range[0]/5);
	}
	if(valnum[i]>=11&&valnum[i]<=20){
		range[1]++;
		stars[1]=floor(range[1]/5);
	}
	if(valnum[i]>=21&&valnum[i]<=30){
		range[2]++;
		stars[2]=floor(range[2]/5);
	}
	if(valnum[i]>=31&&valnum[i]<=40){
		range[3]++;
		stars[3]=floor(range[3]/5);
	}
	if(valnum[i]>=41&&valnum[i]<=50){
		range[4]++;
		stars[4]=floor(range[4]/5);
}
	if(valnum[i]>=51&&valnum[i]<=60){
		range[5]++;
		stars[5]=floor(range[5]/5);
	}
	if(valnum[i]>=61&&valnum[i]<=70){
		range[6]++;
		stars[6]=floor(range[6]/5);
	}
	if(valnum[i]>=71&&valnum[i]<=80){
		range[7]++;
		stars[7]=floor(range[7]/5);
	}
	if(valnum[i]>=81&&valnum[i]<=90){
		range[8]++;
		stars[8]=floor(range[8]/5);
	}
	if(valnum[i]>=91&&valnum[i]<=100){
		range[9]++;
		stars[9]=floor(range[9]/5);
	}
}
	cout<<"1-10\t:";
		printstar(stars[0]);
	cout<<"11-20\t:";
		printstar(stars[1]);
	cout<<"21-30\t:";
		printstar(stars[2]);
	cout<<"31-40\t:";
		printstar(stars[3]);
	cout<<"41-50\t:";
		printstar(stars[4]);
	cout<<"51-60\t:";
		printstar(stars[5]);
	cout<<"61-70\t:";
		printstar(stars[6]);
	cout<<"71-80\t:";
		printstar(stars[7]);
	cout<<"81-90\t:";
		printstar(stars[8]);
	cout<<"91-100\t:";
		printstar(stars[9]);
		//E PART 1
	cout<<"======================================================================"<<endl;
	cout<<"valid favorite Numbers :"<<valcount<<endl;
	cout<<"invalid favorite Numbers :"<<invalco<<endl;
	cout<<"Hidden favorite Numbers :"<<c<<endl;
	// E PART 2 AND 3 NEED ASSISTANCE.
	int maxnum=valnum[1];
	int minnum=1;
	for(int t=1;t<=100;t++){
		if(valnum[t]>maxnum)
			maxnum=valnum[t];
	}
	for(int t=1;t<100;t++){
		if(valnum[t]==maxnum)
			cout<<t<<endl;
	}
		input.close();
return 0;
}
