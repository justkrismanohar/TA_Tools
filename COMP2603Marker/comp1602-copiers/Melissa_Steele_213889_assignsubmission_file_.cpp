#include <iostream>
#include <fstream>
using namespace std;

void Perfect(int favNum){
	int i=1, m, sum=0;
	while(i<favNum){
		m=favNum%i;
		if (m==0){
			sum=sum+i;
			favNum=favNum/i;
		}
		i=i+1;
	}
	if (favNum!=sum){
	cout<<"N";
	}
	else{
	cout<<"Y";
	}
}

bool Prime(int favNum){
	int i=2, j=0;
	while(i<favNum){
		if (favNum%i==0){
		j=1;
		i=i+1;
		}
		else{
		i=i+1;
		}
	}
	if (j==0){	
	return true;
	}
	else{
	return false;
	}

}

void pSquare(int favNum){
	int i=1, sq, j=0;
	for(i=1;
	 i<11; i=i+1){
		sq=i*i;
		if (sq==favNum){
			j=1;
		}
	}
	if(j==1)
	cout<<"Y";
	else
	cout<<"N";	
}


void sphenic(int favNum){
	int b=2, f=0;
	while ((favNum!=1)&& (favNum>=b)){
		if (Prime(b)==true){
			if (favNum%b==0){
				favNum=favNum/b;
				b=b+1;
				f=f+1;
			}
			else
			b=b+1;
		}
		else 
		b=b+1;
	}
	if(f==3){
	cout<<"Y";
	}
	else {
	cout<<"N";
	}
}



void binary(int favNum){
	int bit[8];
	int i=7, quotient, rem, k;
	quotient=favNum;
	while (i>=0){
		bit[i] = quotient%2;
		quotient= quotient/2;
		i=i-1;
	}
	for(k=0; k<8; k=k+1){
		cout<<bit[k];
	}
	cout<<endl;	
}

int main(){
	ifstream inputFile;
	inputFile.open("numbers.txt");
	if(!inputFile.is_open()){
		cout<<"File not found. Aborting..."<<endl;
		return 0;
	}
	
	
	int favNum, numValid=0, numInvalid=0, noNum=0, hist[10], k, i=0, invalid[99];

	
	cout<<"Number"<<"\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equiv."<<endl;
	cout<<"------"<<"\t"<<"--------"<<"\t"<<"------"<<"\t"<<"---------------"<<"\t"<<"--------"<<"\t"<<"-------------"<<endl;
	inputFile>>favNum;
	while(favNum!=-1){
		if ((favNum>0)&&(favNum<101)){
			cout<<favNum<<"\t";
			numValid=numValid+1;
			Perfect(favNum);
			cout<<"\t\t";
			
			if ((Prime(favNum))==true)
			cout<<"Y";
			else 
			cout<<"N";
			
			cout<<"\t";
			pSquare(favNum);
			cout<<"\t\t";
			sphenic(favNum);
			cout<<"\t\t";
			binary(favNum);
			cout<<endl;
		}
		
		if ((favNum<0)||(favNum>100)){
			numInvalid=numInvalid+1;
			invalid[i]=favNum;
			i=i+1;
		}
		if (favNum==0){
			noNum=noNum+1;
		}
		inputFile>>favNum;
	}
	inputFile.close();
	inputFile.open("numbers.txt");
	
	cout<<"Invalid"<<endl;
	i=0;
	while(invalid[i] != 0){
		cout<<invalid[i]<<" \t";
		i=i+1;
		if(i%5==0&&i!=0)
			cout<<endl; 
	}
	inputFile.close();
	inputFile.open("numbers.txt");
	i=0;
	inputFile>>favNum;
	while(favNum!=-1){
		
		if ((favNum>0)&&(favNum<101)){
			
			for (i=0;i<=9;i=i+1){
				if (favNum<=((i+1)*10)){
					hist[i]=hist[i]+1;
				}
			}
		}
		inputFile>>favNum;
	}
	cout<<endl<<endl;
	inputFile.close();
	int numStar;
	cout<<"Range"<<"\t"<<"Histogram"<<endl;
	cout<<"================================="<<endl;
	for(i=1;i<=10;i=i+1){
		cout<<((i*10)-9)<<"-"<<(i*10)<<"\t";
		numStar=hist[i-1]/5;
		for(k=1; k<=numStar; k=k+1)
		cout<<"*";
		cout<<endl;
		
	}
	
	cout<<numValid<<" students specified valid favourite numbers.  "<<numInvalid<<" students specified invalid favourite numbers.  "<<noNum<<" did not reveal their favourite numbers."<<endl;
	
	inputFile.close();
	return 0;
}


	
