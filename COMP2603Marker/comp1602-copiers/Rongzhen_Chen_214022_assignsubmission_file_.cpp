#include <iostream>
#include <fstream>
using namespace std;

void isPerfect (int n){
	int i=1, sum=0;
	for(i=1;i<n;i++){
		if(n%i==0)
		sum=sum+i;
		}
	if(sum==n)
		cout<<"Y";
	else
		cout<<"N";
	}

bool isPrime(int n){
	int num;
	for(int i=2;i<=n/2;i++){
		num=n%i;
		if(num==0)
		return false;
	}
	return true;
}
	
void isPerfSqr(int n){
	int prod=1;
	bool perfectsqr;
	for(int i=1;i<=n/2;i++){
		prod=i*i;
		if(prod==n)
		perfectsqr=true;
	}
	if(perfectsqr==true)
	cout<<"Y";
	else cout<<"N";
}

void isSphenic(int n){
	int i, prod=1, count=0;
	for(i=2;i<=n/2;i++){
		
		if(n%i==0 && isPrime(i)){
			prod=prod*i;
			count=count+1;
		}
	}
		if(count==3 && prod==n)
		cout<<"Y";
		else
		cout<<"N";
	}
	
void showBinary(int n){
	int arr[8]={0}, i;
	for(i=7;i>=0;i=i-1){
		if(n>0){
			arr[i]=n%2;
			n=n/2;
	}
	}
	for(i=0;i<8;i++){
		cout<<arr[i];
	}
}
	
int main(){
	
	ifstream in;
	in.open("numbers.txt");
	if(!in.is_open()){
		cout<<"Error opening file. Aborting...";
		return 0;
	}
	
	int n, valid=0, invalid=0, noreveal=0;
	int numbers[101]={0};
	int range[10]={0};
	
	cout<<"Number  Perfect?  Prime?  Perfect Square?  Sphenic?  Binary Equivalent"<<endl;
	cout<<"======  ========  ======  ===============  ========  ================="<<endl;

	in>>n;
	while(n!=-1){
				
		if(n>=1 && n<=100){
		valid=valid+1;		
		numbers[n]++;
			
		if(n>0 && n<11)
			range[0]++;
		else if(n>10 && n<21)
			range[1]++;
		else if(n>20 && n<31)
			range[2]++;
		else if(n>30 && n<41)
			range[3]++;
		else if(n>40 && n<51)
			range[4]++;
		else if(n>50 && n<61)
			range[5]++;
		else if(n>60 && n<71)
			range[6]++;
		else if(n>70 && n<81)
			range[7]++;
		else if(n>80 && n<91)
			range[8]++;
		else if(n>90 && n<101)
			range[9]++;
	
	if(numbers[n]==1){
		cout<<n;
		cout<<"\t    ";
		isPerfect(n);
		cout<<"        ";
		isPrime(n);
		if(isPrime(n)==true)
		cout<<"Y";
		else
		cout<<"N";		
		cout<<"            ";
		isPerfSqr(n);
		cout<<"            ";
		isSphenic(n);
		cout<<"          ";
		showBinary(n);
		cout<<endl;	
	}
}
		else if(n==0){
		noreveal++;
	}
		in>>n;
}
in.close();

in.open("numbers.txt");
if(!in.is_open()){
	cout<<"Error opening file. Aborting...";
	return 0;
}

	cout<<endl<<endl<<"Invalid numbers: "<<endl<<endl;
		
		in>>n;
		
		int i=1;
		
		while(n!=-1){
			if(n<0 || n>100){
			invalid++;
			
			cout<<n<<"  ";
			if(i%5==0)
			cout<<endl;
			
			i++;
		}
		in>>n;
	}
						
	cout<<endl<<endl;
	cout<<"Range         Histogram"<<endl;
	cout<<"======================="<<endl;
	
	int j=0;
	int histo;
		for(int t=0;t<10;t++){			
		histo=range[t]/5;
			cout<<j+1<<" - "<<j+10<<"  \t|";
			for(int k=0;k<histo;k++){
				cout<<"*";
			}
			cout<<endl;
			j=j+10;
	}
	
cout<<endl<<endl;
cout<<"Number of students who specified valid favourite numbers - "<<valid<<endl;
cout<<"Number of students who specified invalid favourite numbers - "<<invalid<<endl;
cout<<"Number of students who did not reveal their favourite number - "<<noreveal<<endl<<endl;
cout<<"Number/s that was chosen the most by students  -    ";
		int u;
		int most=0;
		for(u=1;u<101;u++){
			if(numbers[u]>=2 && numbers[u]>=most)
			most=numbers[u];
		}
		for(u=1;u<101;u++){
			if(numbers[u]==most)
			cout<<u<<", ";
		}

cout<<endl<<"Number/s that was chosen the least by students -    ";
		int least=999;
		for(u=1;u<101;u++){
			if(numbers[u]>=1 && numbers[u]<least)
			least=numbers[u];
		}
		for(u=1;u<101;u++){
			if(numbers[u]==least)
			cout<<u<<", ";
		}

in.close();

return 0;
}



			
		

	
		
		
	
	
	

