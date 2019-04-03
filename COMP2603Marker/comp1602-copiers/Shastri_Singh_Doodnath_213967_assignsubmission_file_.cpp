#include <iostream>
#include <fstream>
using namespace std;
char perf(int number){
	char perfnum;
	int i, pe;
	for(i=1; i<number; i=i+1){
		if(number%i==0){
			pe=pe+i;
		}}
		if(pe==number){
			perfnum = 'Y';
		}
		else{
			perfnum = 'N';
		}
	
	
	return perfnum;
	}

char prime(int number){
	int i;
	char isprime;
	int count=1;
	int hf = number/2;
	if(number==1){
		isprime = 'N';
		count =2;
	}
	if(number>1 && number<=100){

	for(i=2; i<=hf; i=i+1){
	
		if(number % i == 0){
		count=count+1;
		}
	}}
	if(count>1){
	isprime = 'N';
	}
	else{
	isprime = 'Y';
	}
	return isprime;
	}
char perfsq(int number){
	char persq;
	int p=1;
	int i=1;
	while(p<number){
		i=i+1;
		p=i * i;
	}
	if(p==number){
		persq = 'Y';
	}
	else{
		persq = 'N';
	}
	
	
	return persq;
}
char sphen(int number){
	char sp;
	int j;
	int i=0;
	int pro=1;
	int hf= number/2;
	for(j=2; j<=hf; j=j+1){

	if((number%j==0)  &&  (prime(j)=='Y')){
		pro = pro *j;
		i = i + 1;
	}
}
	if(i==3 && pro==number){
		sp = 'Y';
	}
	else{
		sp='N';
	}
	return sp;
	}
	
	

 void binary(int number){
 	
 	int array[8];
 	int i=0;
 	while(number>0 && number<=100){
 		for(i=0; i<8; i++){
		 
 		array[i]=number%2;
 		number = number /2;
 		
	 }}
	 
	 for(i=i-1; i>=0; i=i-1){
	 	cout<< array[i];
	}
	}


void printstar(int n){
	for(int k=1; k<=n/5; k++){
		cout<< "*";
	}
	}

int main(){
	
	ifstream input;
	int disp;
	int number;
	int valid, invalid, dna;
	valid = 0;
	invalid = 0;
	dna = 0;
	
	
	input.open("numbers.txt");
	if(!input.is_open()){
		cout<< "ERROR, ABORTING..." << endl;
		return 0;
	}
	cout<< "Number	"  << "Perfect?   "  <<"Prime?   " << "Perfect Square?   "  << "Sphenic?   " << "Binary Equiv" << endl;
	cout<< "=============================================================================="<< endl;
	
	int inv=0;
	int invarray[100];
	int val=0;
	int varray[900];
	int arrayL[101];
	for(int counter=0; counter<101; counter++){
		arrayL[counter] =0 ;
	}
	input>> number;
	
	while(number!=-1){
		
	if(number>=1 && number<=100){
		arrayL[number]=arrayL[number] +1;
		varray[val]= number;	
	char perfect= perf(number);	
	char primenum = prime(number);
	char perfectsq = perfsq(number);
	char sphenic = sphen(number);
	cout<< number << "	 " << perfect << "	      " << primenum <<"	   	" << perfectsq<<"	   	"<< sphenic << "	   "  ;
	binary(number);
	cout<< endl;
	valid = valid + 1;

	val=val+1;
	
}

	
if(number<0 || number>100){
		invarray[inv]= number;
		invalid = invalid + 1;
		inv = inv+1;
		
	}
if(number==0){
	dna = dna + 1;
}
	input >> number;
	}
	
	input.close();
	
	cout<< endl;
	cout<< "Invalid numbers entered(five per line): "<< endl;
	cout<< endl;
	
	int in;
	int num=0;
	int ran;
	int range[10];
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
	
	while(num<invalid){
	for(in=0; in<5; in=in+1){
		if(num < invalid){
			cout<< invarray[num] << "   ";
			num=num+1;
		}}
	cout<< endl; }
	

	for(ran=0; ran<valid; ran=ran+1){
			if((varray[ran]>=1 ) && (varray[ran]<=10)){
			range[0] = range[0] + 1;
			
		}
		else{
			if((varray[ran]>=11) && (varray[ran]<=20)){
				range[1] = range[1] + 1;
			}
			else{
				if((varray[ran]>=21) && (varray[ran]<=30)){
					range[2] = range[2] + 1;
					
				}
				else{
					if((varray[ran]>=31) && (varray[ran]<=40)){
						range[3] = range[3] + 1;
					}
					else{
						if((varray[ran]>=41) && (varray[ran]<=50)){
							range[4] = range[4] + 1;
						}
						else{
							if((varray[ran]>=51) && (varray[ran]<=60)){
								range[5] = range[5] + 1;
							}
							else{
								if((varray[ran]>=61) && (varray[ran]<=70)){
									range[6]= range[6] + 1;
								}
								else{
									if((varray[ran]>=71) && (varray[ran]<=80)){
										range[7] = range[7] + 1;
									}
									else{
										if((varray[ran]>=81) && (varray[ran]<=90)){
											range[8] = range[8] +1;
										}
										else{
											if((varray[ran]>=91) && (varray[ran]<=100)){
												range[9] = range[9] + 1;
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


	cout<< endl;
	cout<< "Range			" << "Histogram" << endl;
	cout<< "====================================="<< endl;
	cout<< "  1 - 10" <<"		|" ;
	printstar(range[0]);
	cout<< endl;
	cout<< " 11 - 20" <<"		|" ;
	printstar(range[1]);
	cout << endl;
	cout<< " 21 - 30" <<"		|" ;
	printstar(range[2]);
	cout << endl;
	cout<< " 31 - 40" <<"		|" ;
	printstar(range[3]) ;
	cout << endl;
	cout<< " 41 - 50" <<"		|" ;
	printstar(range[4]);
	cout << endl;
	cout<< " 51 - 60" <<"		|" ;
	printstar(range[5] );
	cout << endl;
	cout<< " 61 - 70" <<"		|" ;
	printstar(range[6]);
	cout << endl;
	cout<< " 71 - 80" <<"		|" ;
	printstar(range[7]);
	cout<< endl;
	cout<< " 81 - 90" <<"		|" ; 
	printstar(range[8]);
	cout<< endl;
	cout<< " 91 - 100" <<"		|" ;
	printstar(range[9]);
	cout<< endl;

	cout<< endl;
	cout<< endl;
	cout<< "STATISTICAL INFORMATION"<< endl;
	cout<< endl;
	
cout<< "Number of students who specified valid favourite numbers: "<< valid << endl;
cout<< "Number of students who specified invalid favourite numbers: "<< invalid << endl;
cout<< "Number of students who did not reveal their favourite numbers: " << dna << endl;
cout<< endl;



int r;
int countt;
int mostnum=0;


cout<< "Number/s chosen most by students: ";
for(r=1; r<101; r++){
	if(mostnum<arrayL[r]){
		mostnum = arrayL[r];
		countt = r;
}
	}
cout<< countt << " ";
	
	cout<< endl;
	cout<< endl;
	int check;
	int endline=0;

  cout <<"Number/s which were chosen least by students: " << endl;
   
   for (check = 1;check < 101;check=check+1){
	if (arrayL[check] == 1){
	
	cout <<check << " ";
	endline=endline+1;
	if(endline>15){
		cout<<endl;
		endline=0;
	}
}
}
    


return 0;	
}


