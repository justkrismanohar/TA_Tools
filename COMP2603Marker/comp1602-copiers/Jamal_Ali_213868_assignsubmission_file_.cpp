#include <iostream>
#include <fstream>
using namespace std;

char isPerfect(int n){
	int sum;
	char Perfect;
	for(int i=1;i<n;i++){
		if(n%i==0){
			sum=sum+i;
        }
	}
	if (sum==n){
	Perfect='Y';
	return Perfect;
	}
	else{
		Perfect='N';
		return Perfect;
	}
}

void binary(int n){
    int count,bits[8],rem;
    rem=n;
    for (count=0;count<8;count++)
        bits[count]=0;
    count=7;
    while((rem!=0&&count>=0)){
        bits[count]=rem%2;
        rem=rem/2;
        count=count-1;
    }
    for(count=0;count<8;count++)
        cout<<bits[count];
}

char isPrime(int n){
	char Prime;
	for(int i=2;i<n;i++){
		if (n%i==0){
			Prime='N';
			return Prime;
		}
		else{
			Prime='Y';
			return Prime;
		}
	}
}

char isSquare(int n){
	char Square;
	for(int i=2;i<=n;i++){
		if (n==i*i){
		Square='Y';
		return Square;}
		else{
			Square='N';
			return Square;
		}
	}
}

char isSphenic(int n){
	int product,count;
	char sphenic;
	for(int i=2;i<n;i++){
		if (isPrime(n)=='Y'){
			product=product*i;
			count=count+1;
		}
	}
	if (product==n && count==3){
			sphenic='Y';
			return sphenic;
		}
		else{
			sphenic='N';
			return sphenic;
		}	
}

int main(){
	ifstream in;
	in.open("numbers.txt");
	if (!in.is_open()){
		cout<<"ERROR OPENING FILE\n";
		return 0;
	}
	int count[101],num,valid,high=0,highest=0,invalid=0,range[10],dns,z,k;
	char Perfect;
	string a[10];
    cout<<"Number\t\tPerfect\t\tPrime\t\tPerfect Square\t\tSphenic\t\tBinary\n";
    cout<<"=======================================================================================\n\n";
    in>>num;
    while (num!=-1){
    	if (num>=1 && num<=100){
    		Perfect=isPerfect(num);
    		cout<<num<<"\t\t"<<Perfect<<"\t\t"<<isPrime(num)<<"\t\t"<<isSquare(num)<<"\t\t"<<isSphenic(num)<<"\t\t";
			binary(num);
			cout<<endl;
    	valid=valid+1;
    	k=num;
    	count[k]=count[k]+1;
			if(num>=1 && num<=10){
    			range[0]=range[0]+1;
			}
			if(num>=11 && num<=20){
    			range[1]=range[1]+1;
			}
			if(num>=21 && num<=30){
    			range[2]=range[2]+1;
			}
				if(num>=31 && num<=40){
    			range[3]=range[3]+1;
			}
				if(num>=41 && num<=50){
    			range[4]=range[4]+1;
			}
				if(num>=51 && num<=60){
    			range[5]=range[5]+1;
			}
				if(num>=61 && num<=70){
    			range[6]=range[6]+1;
			}
				if(num>=71 && num<=80){
    			range[7]=range[7]+1;
			}
				if(num>=81 && num<=90){
    			range[8]=range[8]+1;
			}
				if(num>=91 && num<=100){
    			range[9]=range[9]+1;
			}
		}
    	else{invalid=invalid+1;
		}
    	
		if (num==0){
			dns=dns+1;
		}
			in>>num;
		
	}
    a[0]="1-10";
    a[1]="11-20";
    a[2]="21-30";
    a[3]="31-40";
    a[4]="41-50";
    a[5]="51-60";
    a[6]="61-70";
    a[7]="71-80";
    a[8]="81-90";
    a[9]="91-100";
    cout<<"Range\t\tHistograph\n";
    cout<<"=================================================\n";
    for(int i=0;i<=9;i++){		
    cout<<a[i]<<"      :";
    for (int i=0;i<range[i]/5;i++){
    	cout<<"*";
	}
	cout<<endl;
	}
	cout<<endl;
	cout<<"VALID           :"<<valid<<endl;
	cout<<"INVALID         :"<<invalid<<endl;
	cout<<"DID NOT SPECIFY :"<<dns<<endl;
	cout<<"HIGHEST NUMBERS :";
	for(int i=0;i<100;i++){
        if(count[i]==2)
            cout<<i<<"\t";
    }
	cout<<"LOWEST NUMBERS :";
	for(int i=0;i<100;i++){
        if(count[i]==1)
            cout<<i<<"\t";
    }
    cout<<endl;
in.close();	
return 0;	
}
