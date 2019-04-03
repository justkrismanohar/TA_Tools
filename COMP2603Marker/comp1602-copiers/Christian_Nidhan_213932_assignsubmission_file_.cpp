#include <iostream>
#include <fstream>
using namespace std;

bool isPerfect(int n){ 
    int div, sum=0;
    for (int i=1; i<=n/2; i++)
    {
        div = n%i;
        if (div==0)
            sum=sum+i;
    }
    if (sum==n)
        return true;
    else
    	return false;
}

bool checkPrime(int n){
  for(int i=2; i<= n/2; i++){
      if(n%i==0){
        return false;
      }
	  }
	return true;
}

bool perfSquare(int n){
	for (int i=1; i<=n/2; i++){
		if (i*i==n){
			return true;
		}
	}
	return false;
}

bool sphenic(int n){
	int pqr=0, product=1;
	for(int i=2; i<=n/2; i++){
		if (n%i==0&&checkPrime(i)==true){
			product=product*i;
			pqr=pqr++;
		}
	}
	if (pqr==3&&product==n){
		return true;
	}
	return false;
}

void binary(int n){ 
    int j=0, i=0;
	int bits[8]={0};
	j=n;
	for (i=0; j>0; i++){
		bits[i]=j%2;
		j=j/2;
		}
	cout<<"\t\t";
	for (i=7; i>=0; i--){
		cout<<bits[i];
	}
}

void histogram (int minrange, int maxrange, int valid [], int numvalid){
	int count = 0;
	for (int i=0; i<=numvalid; i++){
		if (valid[i]>= minrange&&valid[i]<=maxrange){
			count=count++;
			if (count%5==0){
				cout<<"*";
			}
		}
	}
	cout<<endl; 
}

int main (){
    int i=0, z=0, n=0, distinct=0, votes=0, min=9999, secret=0, validnum=0, invalidnum=0;
    int file[500];
    int valid[500];
    int invalid[500];
    int repeats[100]={0};
    ifstream in;
    
    in.open("numbers.txt");
    
    if (!in){
    	cout<<"File could not be found.";
    	return 0;
	}
	
	in>>n;
	while(n!=-1){
		file[i]=n;
		i++;
		in>>n;
	}
	for(z=0; z<=i-1; z++){
		if (file[z]==0){
			secret++;
		}
		else if(file[z]<0||file[z]>100){
			invalid[invalidnum]=file[z];
			invalidnum++;
		}
		else if(file[z]>0||file[z]<=100){
			valid[validnum]=file[z];
			validnum++;
		}
	}
	cout<<"Number\tPerfect?\tPrime?\tPerfect Square?\tSphenic?\tBinary Equiv."<<endl;
	cout<<"========================================================================================="<<endl;
	for(i=0; i<validnum; i++){
		distinct=valid[i];
		if(repeats[distinct--]==0){
			repeats[distinct--]=repeats[distinct--]++;
			cout<<distinct;
		
		
		if(isPerfect(distinct)==0){
			cout<<"\tN";
		}
		else{
			cout<<"\tY";
		}
		if(checkPrime(distinct)==0){
			cout<<"\t\tN";
		}
		else{
			cout<<"\t\tY";
		}
		if(perfSquare(distinct)==0){
			cout<<"\tN";
		}
		else{
			cout<<"\tY";
		}
		if(sphenic(distinct==0)){
			cout<<"\t\tN";
		}
		else{
			cout<<"\t\tY";
		}
		binary(distinct);
		cout<<endl;
	}
	else{
		repeats[distinct--]=repeats[distinct--]++;
	}
}
	cout<<"\nInvalid Numbers: "<<endl;
	for(z=1; z<=invalidnum; z++){
		if (z%5==0){
			cout<<invalid[z-1]<<endl;
		}
		else{
			cout<<invalid[z-1]<<" ";
		}
	}
	cout<<"\n\nRange\t\tHistogram"<<endl;
	cout<<"==================================="<<endl;
	cout <<" 1 - 10\t\t";
	histogram(1,10,valid,validnum);
	cout <<"11 - 20\t\t";
	histogram(11,20,valid,validnum);
	cout <<"21 - 30\t\t";
	histogram(21,30,valid,validnum);
	cout <<"31 - 40\t\t";
	histogram(31,40,valid,validnum);
	cout <<"41 - 50\t\t";
	histogram(41,50,valid,validnum);
	cout <<"51 - 60\t\t";
	histogram(51,60,valid,validnum);
	cout <<"61 - 70\t\t";
	histogram(61,70,valid,validnum);
	cout <<"71 - 80\t\t";
	histogram(71,80,valid,validnum);
	cout <<"81 - 90\t\t";
	histogram(81,90,valid,validnum);
	cout <<"91 - 100\t";
	histogram(91,100,valid,validnum);
	
	for(i=0; i<=100; i++){
		if (repeats[i]<min&&repeats[i]!=0){
			min=repeats[i];
		}
	}
	cout<<"\n\nStudents Who Did Not Choose: "<<secret<<endl;
	cout<<"Valid Choices: "<<validnum<<endl;
	cout<<"Invalid Choices: "<<invalidnum<<endl;
	cout<<"Most Voted Number: ";
	for(i=0; i<100; i++){
		if (repeats[i]==votes){
			cout<<i++<<" ";
		}
	}
	cout<<"\nLeast Voted Number(s): ";
	for(i=0; i<100; i++){
		if (repeats[i]==min){
			cout<<i++<<" ";
		}
	}
	in.close();
	return 0;
}
