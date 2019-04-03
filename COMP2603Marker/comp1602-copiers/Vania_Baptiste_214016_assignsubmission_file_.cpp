#include<iostream>
#include<fstream>
using namespace std;

void isPerfect(int favnum){
	int j=0;
	for(int i=1;i<favnum;i++){
		if(favnum%i==0){
			j=j+1;
		}
	}
		if(j==favnum){
		cout<"Y";
		}
		else{
		cout<<"N";
		}

}

bool isPrime(int favnum){
	for(int i=2;i<favnum/2;i++){
		if(favnum%i==0){
			return true;
		}
		else{
			return false;
		}
		}
	}
bool isPerfectSqr(int favnum){
	for(int i=2;i<favnum/2;i++){
		if(i*i==favnum){
			return true;
		}
		else{
			return false;
		}
	}
}
void isBinary(int favnum){
	int i;
	int mod=0;
	int binary [8];

	for(int l=0;l<=8;l++){
		binary[l]=0;
	}
	for(i=0;i<=8;i++){
		mod=favnum%2;
		binary[i]=mod;
		favnum=favnum/2;
	}
	for(i=8;i>0;i=i-1){
		cout<<binary[i];
	}
}
void isSphenic(int favnum){
	int product=0;
	int count=0;
		for (int i=2;i<favnum/2;i++)
	if(favnum%i==0&&isPrime(favnum)){
		product=product*i;
		count=count+1;
		cout<<"Y";
		}
			else{
				cout<<"N";
			}
	}

void Histogram(int favnum){
	int i=0;
	while(favnum>=5){
	cout<<"*";
	favnum=favnum-5;
    }
	
}



int main (){

	ifstream inputFile;
	
	bool Prime=false;
	bool PerfectSqr=false;
	
	
	int favnum;
	int valid[101];
	int invalid [101];
	int ranges [11];
	int mostfreq[101];
	int i=0;
	int m;
	int n;
	int v;
	int k;
	int l;
	int d;
	int y;
	int o=0;
	int validtotal=0;
	int invalidtotal=0;
	int noreveal=0;

	for(int m=0; m<101;m++){
			valid[m]=0;
			invalid[m]=0;
			mostfreq[m]=0;
		}
		for( int l=0;l<=11;l++){
			ranges[l]=0;
		}

	inputFile.open("numbers.txt");
	if(!inputFile.is_open()){
		cout<<"error opening file.....................ABORTING!!!";
		return 0;
	}


	inputFile>>favnum;
	while(favnum!=-1){
		
		if(favnum>=1 && favnum<=100){
			valid[i]=favnum;
			i++;
			validtotal=validtotal+1;
			inputFile>>favnum;
				
		}
		else{
			invalid[o]=favnum;
			invalidtotal=invalidtotal+1;
			
			if(favnum==0){
				invalid[o]=0;
				o--;
				noreveal=noreveal+1;
				invalidtotal=invalidtotal-1;
			}
			o++;
			inputFile>>favnum;
			
		}
		}
		
	cout<<"Number"<<"\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic"<<"\t"<<"Binary Equivalent"<<endl;
	cout<<"======="<<"\t"<<"========"<<"\t"<<"======="<<"\t"<<"============="<<"\t"<<"========="<<"\t"<<"================="<<endl;

	for(v=0;v<=validtotal;v++){
		favnum=valid[v];
		cout<<favnum<<"\t";
		
		isPerfect(favnum);
		cout<<"\t\t";
		
	
		Prime=isPrime(favnum);
		if(Prime==true){
			cout<<"Y";
		}
		else{
			cout<<"N";
		}
		cout<<"\t";
		
		PerfectSqr=isPerfectSqr(favnum);
		if(PerfectSqr==true){
			cout<<"Y";
		}
		else{
			cout<<"N";
		}
		cout<<"\t\t";
			
		
		isBinary(favnum);
		cout<<endl;
	}


	for( int f=0; f<invalidtotal; f++){
	cout<<invalid[f]<<" ";
	if((f+1)%5==0)
	cout<<endl;
		

}
	

for(k=0;k<validtotal; k++){
	if(valid[k]>=1&&valid[k]<=10){
		ranges[0]++;
	}
	else{
	if(valid[k]>=11&&valid[k]<=20){
		ranges[1]++;
	}
	else{
		if(valid[k]>=21&&valid[k]<=30){
			ranges[2]++;
		}
		else{
			if(valid[k]>=31&&valid[k]<=40){
			ranges[3]++;
		}
		else{
			if(valid[k]>=41&&valid[k]<=50){
				ranges[4]++;
			}
			else{
				if(valid[k]>=51&&valid[k]<=60){
					ranges[5]++;
				}
				else{
					if(valid[k]>=61&&valid[k]<=70){
						ranges [6]++;
					}
					else{
						if(valid[k]>=71&&valid[k]<=80){
							ranges[7]++;
						}
						else{
							if(valid[k]>=81&&valid[k]<=90){
								ranges[8]++;
							}
							else{
								if(valid[k]>=91&&valid[k]<=100){
									ranges[9]++;
								}
							}
						}
					}
				}
			}
		}
	}
	}	
	}
}
cout<<endl;


cout<<"Ranges"<<"\t"<<"Histogram"<<endl;
cout<<"============================"<<endl;

cout<<"1-10 \t";
Histogram(ranges[0]);
cout<<endl;

cout<<"11-20 \t";
Histogram(ranges[1]);
cout<<endl;

cout<<"21-30 \t";
Histogram(ranges[2]);
cout<<endl;

cout<<"31-40 \t";
Histogram(ranges[3]);
cout<<endl;

cout<<"41-50 \t";
Histogram(ranges[4]);
cout<<endl;

cout<<"51-60 \t";
Histogram(ranges[5]);
cout<<endl;

cout<<"61-70 \t";
Histogram(ranges[6]);
cout<<endl;

cout<<"71-80 \t";
Histogram(ranges[7]);
cout<<endl;

cout<<"81-90 \t";
Histogram(ranges[8]);
cout<<endl;

cout<<"91-100 \t";
Histogram(ranges[9]);
cout<<endl;

	


cout<<endl;
cout<<endl;


cout<<"Students with valid numbers "<<"  "<<validtotal<<endl;
cout<<"Students invalid total are"<<"   "<<invalidtotal<<endl;
cout<<" students who did not reveal"<<"  "<<noreveal<<endl;

cout<<" The most frequently chosen number : ";
 for(int y=0; d<validtotal; d++){
 	    if(mostfreq[d]>0){
 	  	 cout<<mostfreq[d];	
  }
}	
}
	



