#include<iostream>
#include<fstream>
using namespace std;
 
bool isValid(int n){
	if(n!=0 && n>0 && n<=100)
		return true;
	else
		return false;
}

bool isPerfect(int n){
	int i;
	int sum=0;
	for(i=1; i<n/2; i=i+1){
		if(n%i==0)
		sum=sum+i;
	}
	if(sum==n)
		return true; 
	return false;
}

bool isPrime(int n){
	int i;
	int prime;
	for (i=2; i<=n/2; i=i+1){
		prime=n%i;
		if(prime==0)
			return false;
		}
		return true;
}

bool isPerfectSq(int n){
	int sq, i;
	for (i=1; i<n; i+=i+1){
		sq=i*i;
		if(sq==n)
			return true;
		}
		return false;
}

bool isSphenic(int n){
	int i, count, product;
	count=0;
	product=1;
	for(i=2; i<=n/2; i=i+1){
	if(n%i==0 && isPrime(i)){
		product=product*i;
		count=count+1;
		}	
	}
	if(count==3 && product==n)
		return true;
	return false; 
}

void bin(int n){
	int bin[8]= {};
	int i=7;
	while (n!=0){
		if(n%2==0)
		bin[i]=0;
		else if (n%2==1)
			bin[i]=1;
		i=i-1;
		n=n/2;
	}
	for(i=0; i<=7; i=i+1)
	cout<<bin[i];
}

string histogram(int n){
	if(n/5==1)
	return "*";
	else if(n/5==2)
	return "**";
	else if(n/5==3)
	return "***";
	else if(n/5==4)
	return "****";
	else if(n/5==5)
	return"*****";
}

int main(){
	ifstream input;
	bool valid_ch, perfect_ch, prime_ch, perfectsq_ch, sphenic_ch, distinct_ch;
	int num_fav[100000]={};
	int valid[100000]={};
	int invalid[100000]={};
	int distinct[100000]={};
	int hist[10]={};
	int choose_most[100000]={};
	int choose_least[100000]={};
	int choose[101]={};
	int a=0;
	int m=0;
	int l=0;
	int stu =0;
	int inval=0;
	int val=0;
	int dist=0;
	int valid_num=0;
	int no_reveal=0;
	int most=0;
	int least=99999;
	int num, tot_stu, tot_val, tot_inval, tot_dist, b, tot_most, tot_least; 
	
	input.open("numbers.txt");
	if(!input.is_open()){
		cout<<"ERROR! This file cannot be accessed. The program will now close."<<endl;
		return 0;
	}
	
	input>>num;
	while(num!=-1){
		num_fav[a]=num;
	 	a=a+1;
	 	stu=stu+1;
	 	input>>num;
	}
	tot_stu=stu;
	for(a=0;a<tot_stu;a=a+1){
		valid_ch=isValid(num_fav[a]);
		if(valid_ch){
			valid[val]=num_fav[a];
			val=val+1;
		}
		else if(!valid_ch){
			invalid[inval]=num_fav[a];
			inval=inval+1;
		}
	}
	tot_val= val;
	tot_inval= inval;
	
	for(a=0; a<tot_inval; a=a+1){
		if(invalid[a]==0)
		no_reveal=no_reveal+1;
	}
	for(a=0; a<tot_val; a=a+1){
		for(a=0; a<=tot_inval; a=a+1){
			if(valid[a]==distinct[a]){
			distinct_ch=false;
			}
		}
		if(distinct_ch){
			distinct[dist]=valid[a];
			dist=dist+1;
		}
		distinct_ch=true;
	}
	tot_dist= dist;
	
	cout<<"Number"<<"	"<<"Perfect?"<<"	"<<"Prime?"<<"		"<<"Perfect Square?"<<"		"<<"Sphenic?"<<"	"<<"Binary Equiv."<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	for(a=0; a<tot_dist; a=a+1){
		cout<<distinct[a]<<"	";
		
		perfect_ch=isPerfect(distinct[a]);
		if(perfect_ch)
		cout<<"Y"<<"	";
		else
		cout<<"N"<<"	";
		
		prime_ch=isPrime(distinct[a]);
		if(prime_ch)
		cout<<"Y"<<"	";
		else
		cout<<"N"<<"	";
		
		perfectsq_ch=isPerfectSq(distinct[a]);
		if(perfectsq_ch)
		cout<<"Y"<<"	";
		else
		cout<<"N"<<"	";
		
		sphenic_ch=isSphenic(distinct[a]);
		if(sphenic_ch)
		cout<<"Y"<<"	";
		else
		cout<<"N"<<"	";
		
		bin(distinct[a]);
		cout<<endl;
	}
	
	cout<<"List of Invalid Numbers:"<<endl;
	for(a=0; a<tot_inval; a=a+1){
		if (a%5==0 && a!=0)
		cout<<endl;
		cout<<invalid[a]<<"	";
	}
	for(a=0; a<tot_val; a=a+1){
		if(valid[a]>=1 && valid[a]<=10)
		hist[0]=hist[0]+1;
		else if(valid[a]>=11 && valid[a]<=20)
		hist[1]=hist[1]+1;
		else if(valid[a]>=21 && valid[a]<=30)
		hist[2]=hist[2]+1;
		else if(valid[a]>=31 && valid[a]<=40)
		hist[3]=hist[3]+1;
		else if(valid[a]>=41 && valid[a]<=50)
		hist[4]=hist[4]+1;
		else if(valid[a]>=51 && valid[a]<=60)
		hist[5]=hist[5]+1;
		else if(valid[a]>=61 && valid[a]<=70)
		hist[6]=hist[6]+1;
		else if(valid[a]>=71 && valid[a]<=80)
		hist[7]=hist[7]+1;
		else if(valid[a]>=81 && valid[a]<=90)
		hist[8]=hist[8]+1;
		else if(valid[a]>=91 && valid[a]<=100)
		hist[9]=hist[9]+1;	
	}
	cout<<endl;
	cout<<"Range"<<"	"<<"Histogram"<<endl;
	cout<<"---------------------------------"<<endl;
	cout<<"1-10"<<"	"<<histogram(hist[0])<<endl;
	cout<<"11-20"<<"	"<<histogram(hist[1])<<endl;
	cout<<"21-30"<<"	"<<histogram(hist[2])<<endl;
	cout<<"31-40"<<"	"<<histogram(hist[3])<<endl;
	cout<<"41-50"<<"	"<<histogram(hist[4])<<endl;
	cout<<"51-60"<<"	"<<histogram(hist[5])<<endl;
	cout<<"61-70"<<"	"<<histogram(hist[6])<<endl;
	cout<<"71-80"<<"	"<<histogram(hist[7])<<endl;
	cout<<"81-90"<<"	"<<histogram(hist[8])<<endl;
	cout<<"91-100"<<"	"<<histogram(hist[9])<<endl;
	cout<<endl;
	
	cout<<"Number of students that gave valid numbers: "<<tot_val<<" students."<<endl;
	cout<<"Number of students that gave invalid numbers: "<<tot_inval<<" students."<<endl;
	cout<<"Number of students eho did nto reveal their favourite numbers: "<<no_reveal<<" students."<<endl;
	
	for(a=0; a<tot_val; a=a+1){
		valid_num=valid[a];
		choose[valid_num]=choose[valid_num]+1;
	}
	for(a=1; a<101; a=a+1){
		if(choose[a]>most && choose[a]>=2){
			most= choose[a];
		}
		if(choose[a]<least && choose[a]>=1){
			least=choose[a];
		}
	}
	for(a=1; a<101; a=a+1){
		if(choose[a]==most){
			choose_most[m]=a;
			m=m+1;
		}
		if(choose[a]==least){
			choose_least[l]=a;
			l=l+1;
		}
	}
	tot_most=m;
	tot_least=l;
	cout<<"Number(s) that was/were chosen the most by the students: "<<endl;
	for(a=0; a<tot_most; a=a+1){
		cout<<choose_most[a]<<'\t';
	}
	cout<<endl;
	cout<<"NUmber(s) that was/were chosen the least by the students: "<<endl;
	for(a=0; a<tot_least; a=a+1){
		cout<<choose_least[a]<<'\t';
	}
	input.close();
	return 0;
}
