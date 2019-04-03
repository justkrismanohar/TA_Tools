#include<iostream>
#include<fstream>
using namespace std;
int main(){
	arr[10]
	int num;
	int valid;
	int invalid;
	int noreveal;
	int mostnum;
	mostnum=0;
	int leastnum;
	leastnum=100;
	noreveal=0;
	valid=0;
	invalid=0;
	char perfect;
	ifstream inputFile;
	inputFile.open("numbers.txt");
	if(!inputFile.is_open()){
		cout<<"Error opening onput file.Aborting....";
		return 0;
	}
	
	inputFile>>num;
	
	while(!inputFile.eof()){
		if(!num==-1){
			valid=valid+1;
		cout<<"Number"<<"  "<<"Perfect?"<<"   "<<"Prime?"<<"   "<<"Perfect Square?"<<"   "<<"Sphenic?"<<"    "<<"Binary equiv."<<endl;
		cout<<"======"<<"  "<<"========"<<"   "<<"======"<<"   "<<"==============="<<"   "<<"========"<<"    "<<"============="<<endl;
		cout<<num<<"     "<<perfect(num)<<"     "<<prime(num)<<"   "<<perfectsquare(num)<<"   "<<sphenic(num)<<"   "<<binaryequiv<<endl;
		if (num=>0&&num<10){
			arr[0]=arr[0]+1;
			cout<<"*"<<endl;
		}
		else if(num=>10&&num<=20){
				arr[1]=arr[1]+1;
				cout<<"*"<<endl;
		}else if(num>20&&num<=30){
			arr[2]=arr[2]+1;
			cout<<"*"<<endl;
		}
		else if(num>30&&num<=40){
			arr[3]=arr[3]+1;
			cout<<"*"<<endl;
		}
		else if(num>40&&num<=50){
			arr[4]=arr[4]+1;
			cout<<"*"<<endl;
   }
		else if(num>50&&num<=60)[
		arr[5]=arr[5]+1;
		cout<<"*"<<endl;
		}
		else if(num>60&&num<=70){
			arr[6]=arr[6]+1;
			cout<<"*"<<endl;
		}
		else if(num>70&&num<=80){
			arr[7]=arr[7]+1;
			cout<<"*"<<endl;
		}
		else if(num>80&&num<=90){
			arr[8]=arr[8]+1;
			cout<<"*"<<endl;	
		}
		else if(num>90&&num<=100){
			arr[9]=arr[9]+1;
			cout<<"*"<<endl;
		}
		
		cout<<"Range"<<"     "<<"Histogram"<<endl;
		cout<<"==========================="<<endl;
		cout<<"1-10"<<"      "<<arr[0]<<endl;
		cout<<"11-20"<<"     "<<arr[1]<<endl;
		cout<<"21-30"<<"     "<<arr[2]<<endl;
		cout<<"31-40"<<"     "<<arr[3]<<endl;
		cout<<"41-50"<<"     "<<arr[4]<<endl;
		cout<<"51-60"<<"     "<<arr[5]<<endl;
		cout<<"61-70"<<"     "<<arr[6]<<endl;
		cout<<"71-80"<<"     "<<arr[7]<<endl;
		cout<<"81-90"<<"     "<<arr[8]<<endl;
		cout<<"91-100"<<"    "<<arr[9]<<endl;
	
		cout<<"The amount of students with valid numbers:"<<valid<<endl;
		if(num==0){
			noreveal=noreveal+1;
			cout<<"The amount of students who did not reveal their favourite numbers are:"<<noreveal<<endl;
		}else
		cout<<num;
		invalid=invalid+1;
		cout<<"The amount of students with invalid numbers:"<<invalid<<endl;
		cout<<endl;
		
		if (num>hignum){
			highnum=num;
			inputFile>>num;
			
		}else
		 return 0;
		 
		 if(num<leastnum){
		 	leastnum=num;
		 	inputFile>>num;
		 }else
		 return 0;
		 cout<<"The numbers that was chosen the most:"<<highnum<<endl;
		 cout<<"The numbers that was chosen the least:"<<leastnum<<endl;
		 
		 inputFile.close()
}
char perfect(int num){
	int i;
	int sumdiv;
	i=0;
	sumdiv=0;
	while(i<num){
		if(num%i==0){
			sumdiv=sumdiv+1;
			i=i+1;
			cout<<"Y"<<endl;	
		}else
		    cout<<"N"<<endl;
	}
}
char prime(int num){
	int i;
	i=2;
	for(i=2;i<=num;i=i+1){
		if(num%i==0){
			cout<<"Y"<<endl;
		}else
		    cout<<"N"<<endl;
	}
}
char perfectsquare(int num){
int sqr;
char Y;
char N;
sqr=1;
int i;
i=1;
while(sqr<num){
	i=i+1;
	sqr=i*i;		
}
if(sqr==num)
    cout<<"Y"<<endl;
else
    cout<<"N"<<endl;	
}
char sphenic(int num){
	int prod;
	char Y;
	char N;
	int p;
	int q;
	int r;
	p= prime(num);
	q=prime(num);
	r=prime(num);
	prod=p*q*r;
	if(prod==num){
		cout<<"Y"<<endl;
	}else
	    cout<<"N"<<endl;
}
int binaryequiv(int num){
	int arr[10];
	int i;
	for(i=0;num>0;i=i+1){
		arr[i]=num%2;
		num=num/2;	
	}
	for(i=i-1;i>=0;i=i-1){
	}
	cout<<arr[i]<<endl;
}	
