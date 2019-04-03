#include<iostream>
#include<fstream>
using namespace std;

void isPerfect(int n){
	int i;
	int sum = 0;
	for(i=1;i<=n/2;i=i+1){
		if(n%i==0){
			sum=sum+i;
		}
	}
	if(sum==n){
		cout<<"Y";
	}
	else{
		cout<<"N";
	}
}

bool Prime(int n){
  int i;
  bool ans;
	for(i=2;i<=n/2;i=i+1){
		if(n%i==0)
		return false;

	}
		return true;
	
} 

void isPrime(int n){
	int i;
	bool ans = true;
	for(i=2;i<=n/2;i=i+1){
		if(n%i==0){
			ans=false;
			if(ans==false){
				cout<<"N";
				break;
			}
		}
	}
	if(ans==true){
		cout<<"Y";
	}
}

void isPerfectSquare(int n){
   int sq;
	int i;
	if(n==1)
	cout<<"Y";
	for(i=2;i<=n/2;i=i+1){
		sq=i*i;
		if(sq==n){
			cout<<"Y";
			break;
		}
	}
	if((sq !=n)&&(n!=1)){
			cout<<"N";
	} 	
}

void isSphenic(int n){
	int i, count, product;
	bool ans = true;
	count = 0;
	product = 1;
	for(i=2;i<=n/2;i=i+1){
		if((n%i==0) && (Prime(i))){
			product = product*1;
			count=count+1;
		}
	}
	if((count==3)&&(product==n)){
		cout<<"Y";
  }
    else{
    	cout<<"N";
    }
}

void binary(int n){
	int quo;
	int rem;
	int bits[8];
	int i;
	int j=0;
	for( i=0; i<8; i=i+1){
		bits[i]=0;
	}
	quo=n;
	while(quo!=0){
		rem=quo%2;
		quo=quo/2;
		bits[j]=rem;
		j=j+1;
	}
	for(i=i-1;i>=0;i=i-1){
		cout<<bits[i];
	}
	
}

void printStars( int n){
	int s;
	int i;
	s=n/5;
	if(s!=0){
		for(i=1;i<=s;i=i+1){
			cout<<"*";
		}
	}
}

int main(){
	ifstream in;
	int num;
	int count=0;
	int i;
	int j;
	int h = 0;
	int n=0;
	int v=0;
	int inv=0;
	int nc=0;
	bool ans;
	int fnum[1000];
	int valid[101];
	int invalid[1000];
	int nuetral[100];
	int hist[11];
	in.open("numbers.txt");//attaches streams to the relevant file using open.
	if(!in.is_open()){//Error check. if input file is not open, do.
		cout<<"Error opening file..."<<endl;
		return 0;
	}
	in>>num;
	while(num!=-1){
		fnum[count]=num;
	/*	cout<<fnum[count]<<endl;*/
		count=count+1;
		in>>num;
	}
	for(int c=0;c<101;c=c+1){
		valid[c]=0;
	}
	for(h=0;h<11;h=h+1){
	    hist[h]=0;
    }
    
	for(i=0;i<count;i=i+1){
		if (fnum[i]>=1&&fnum[i]<=100){
			valid[v]=fnum[i];
			v=v+1;
			if(fnum[i]>=1 && fnum[i]<=10){
				hist[1]=hist[1]+1;
			}
			if(fnum[i]>=11 && fnum[i]<=20){
				hist[2]=hist[2]+1;
			}
			if(fnum[i]>=21 && fnum[i]<=30){
				hist[3]=hist[3]+1;
			}
			if(fnum[i]>=31 && fnum[i]<=40){
				hist[4]=hist[4]+1;
			}
			if(fnum[i]>=41 && fnum[i]<=50){
				hist[5]=hist[5]+1;
			}
			if(fnum[i]>=51 && fnum[i]<=60){
				hist[6]=hist[6]+1;
			}
			if(fnum[i]>=61 && fnum[i]<=70){
				hist[7]=hist[7]+1;
			}
			if(fnum[i]>=71 && fnum[i]<=80){
				hist[8]=hist[8]+1;
			}
			if(fnum[i]>=81 && fnum[i]<=90){
				hist[9]=hist[9]+1;
			}
			if(fnum[i]>=91 && fnum[i]<=100){
				hist[10]=hist[10]+1;
			}
			
		}
		if(fnum[i]<0|| fnum[i]>100){
			invalid[inv]=fnum[i];
			inv=inv+1;
		}
		
		if(fnum[i]==0){
			fnum[i]=nuetral[nc];
			nc=nc+1;
		}
}

cout<<"Number"<<"	"<<"Perfect?"<<"	"<<"Prime?"<<"	"<<"Perfect Square?"<<"	"<<"Sphenic?"<<"	"<<"Binary Equivalent"<<endl;

    for(n=0;n<v;n=n+1){
	cout<<valid[n]<<"	";
	isPerfect(valid[n]);
	cout<<"	 	";
	isPrime(valid[n]);
	cout<<"		";
	isPerfectSquare(valid[n]);
	cout<<" 	";
	isSphenic(valid[n]);
	cout<<"		";
	binary(valid[n]);
	cout<<endl;
   }
   cout<<endl;

cout<<"Invalid Numbers:"<<endl;
for(int a=0;a<inv;a=a+1){
	cout<<invalid[a]<<"	";
	if((a+1)%5==0)
	cout<<endl;
}
cout<<endl;
cout<<endl;
cout<<"Range"<<"	 "<<"Histogram"<<endl;
cout<<"========================================"<<endl;
cout<<"1-10"<<"	"<<"|";
printStars(hist[1]);
cout<<endl;
cout<<"11-20"<<"	"<<"|";
printStars(hist[2]);
cout<<endl;
cout<<"21-30"<<"	"<<"|";
printStars(hist[3]);
cout<<endl;
cout<<"31-40"<<"	"<<"|";
printStars(hist[4]);
cout<<endl;
cout<<"41-50"<<"	"<<"|";
printStars(hist[5]);
cout<<endl;
cout<<"51-60"<<"	"<<"|";
printStars(hist[6]);
cout<<endl;
cout<<"61-70"<<"	"<<"|";
printStars(hist[7]);
cout<<endl;
cout<<"71-80"<<"	"<<"|";
printStars(hist[8]);
cout<<endl;
cout<<"81-90"<<"	"<<"|";
printStars(hist[9]);
cout<<endl;
cout<<"91-100"<<"	"<<"|";
printStars(hist[10]);
cout<<endl;
cout<<endl;

cout<<"Amount of students who specified valid favourite numbers: "<<v<<" students"<<endl;
cout<<"Amount of students who specified invalid favourite numbers: "<<inv<<" students"<<endl;
cout<<"Amount of students who did not reveal their favourite number:"<<nc<<" students"<<endl;
}
