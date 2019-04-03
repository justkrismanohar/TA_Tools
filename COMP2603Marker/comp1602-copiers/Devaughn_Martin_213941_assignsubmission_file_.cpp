#include <iostream>
#include <fstream>
using namespace std;


void isPerfect (int a){
int  sum = 0;

for( int i = 1; i <=a/2; i ++){
	
	if (a % i == 0 ) {
	
		sum = sum + i;	

}
}
	
	if(sum == a && a != 1 ) {
	
		cout << " Y";

	}
	else{
	
		cout<< " N"; 

}
}

void isPrime (int a){
int  factors = 0;

for( int i = 2; i <=a/2; i ++){
	
	if (a % i == 0 ) {
	
		factors = 1;
		break;	

}
}
	
	if(factors == 0 && a != 1 && a !=2 )  {
	
		cout << " Y";

	}
	else{
	
		cout<< " N"; 

}
}

bool printPrime (int a){
int  factors = 0;

for( int i = 2; i <=a/2; i ++){
	
	if (a % i == 0 ) {
	
		factors = 1;
		break;	

}
}
	
	if(factors == 0 && a != 1 )  {
	
		return true;

	}
	else{
	
		return false; 

}
}

int binary(int n){
	int  bits[8]= {0};
	int i,j;
	for (i= 0; j>0; i++ ){
		bits[i]= n%2;
		n=n/2;
	}
	cout<< "         ";
	for(j=7; j>=0; j--)
	cout<<bits[j];
	return 0;
}



void isPerfectSqr (int a){
int factors = 0;
float i= 0.0;
for( i = 1; i <=a ; i ++){

	
	if ((a / i) == i ) {
	
	factors = factors + 1;
break;
}

}
	if(factors == 1){
	
		cout << " Y";

	}
	else{
	
		cout<< " N"; 

}

}

void isSphenic (int a){
	int count = 0; int product = 1;
	for (int i = 2; i <= a/2 ; i++ ){
		
		
		if ((a%i == 0 ) && (printPrime(i) == true ) && (count <= 3)){
	
	
			product = product * i;
			count = count + 1;
			
		}
		
	} 
	if ((count == 3) && (product == a)) {
	cout << "Y";
	}
	else{
		cout<< "N";
	}
	
}

string Histogram(int x){
	int remainder=0;
	int i=0;
	


	if(x>=5){
		
	if (x%5 != 0 ){		
	remainder = x%5;
	x = x-remainder;
	x = x/5;
		
	
	}
	
	if(x%5==0){
	x = x/5;
	
	}
}
 

	
	

	
	
	for(i=0; i<x; i++){
		cout << "*";
	}

return " ";
}

int main(){

ifstream in;

int valcaount = 0;
int numbers[150] ;
int notrev = 0;
int valnumbers[150];
int invalnumbers[50];
int a = 0;
int count= 0;
int valid = 0;
int invalid = 0;
int valcount =0;
int countNum[150] ;
int uniqueNum[9999],uniqueIndex = 0,max=0,min=9999;
in.open ("numbers.txt");

if (!in.is_open()){
	cout<<"Error in opening file.";
	return 0;
	
	}

cout<<"Number\t\t Perfect?\t\t Prime?\t\t Perfect Square\t\tSphenic\t\t Binary Equiv."<<endl;
cout<<"======\t\t ========\t\t ======\t\t ==============\t\t=======\t\t ============="<<endl;

in >> a;
while ( a != -1  ){

	numbers[count] = a;
	count ++;
	if (a==0){
		notrev ++;
	}
	if (a > 0 && a <= 100 ){
	
	
	valnumbers[valid] = a;
	cout << a <<"\t\t";
	isPerfect(a);
	cout <<"\t\t\t";
	isPrime(a);
	cout <<"\t\t";
	isPerfectSqr(a);
	cout <<"\t\t\t";
	isSphenic(a);
	cout <<"\t";
	binary(a);
	cout <<endl;
	valcount ++;
	valid ++;
	
}
if  ( a < 0 || a > 100) {
	invalnumbers[invalid] = a;
	invalid ++;	
}
	in >> a;
} 
	
cout<<endl;
cout << "Invalid numbers:"<<endl;

for (int i = 0; i <invalid ; i++){


cout<<invalnumbers[i]<<"\t";
 if( (i+1) % 5 == 0){
	cout<<endl;
}
}


cout<< endl<< endl<< endl<< endl<< endl;
cout<<"Range\t\tHistogram"<<endl;
cout<<"=========================="<<endl;


int onecount =0;
int twocount =0;
int threecount =0;
int fourcount =0;
int fivecount =0;
int sixcount =0;
int sevencount =0;
int eightcount =0;
int ninecount =0;
int tencount =0;
int i=0;
for (i=0; i<valcount; i++){
	if((valnumbers[i]>0)&&(valnumbers[i]<=10)){
		onecount = onecount+1;		
	}
	if((valnumbers[i]>10)&&(valnumbers[i]<=20)){
		twocount = twocount+1;		
	}
	if((valnumbers[i]>20)&&(valnumbers[i]<=30)){
		threecount = threecount+1;		
	}
	if((valnumbers[i]>30)&&(valnumbers[i]<=40)){
		fourcount = fourcount+1;		
	}
	if((valnumbers[i]>40)&&(valnumbers[i]<=50)){
		fivecount = fivecount+1;		
	}
	if((valnumbers[i]>50)&&(valnumbers[i]<=60)){
		sixcount = sixcount+1;		
	}
	if((valnumbers[i]>60)&&(valnumbers[i]<=70)){
		sevencount = sevencount+1;		
	}	
	if((valnumbers[i]>70)&&(valnumbers[i]<=80)){
		eightcount = eightcount+1;		
	} 
	if((valnumbers[i]>80)&&(valnumbers[i]<=90)){
		ninecount = ninecount+1;		
	}
	if((valnumbers[i]>90)&&(valnumbers[i]<=100)){
		tencount = tencount+1;		
	}
	
}
int x = onecount;
cout << "1 to 10\t\t :" ;
Histogram(x);

x = twocount;
cout << "\n11 to 20\t :" ;
Histogram(x);

x = threecount;
cout << "\n21 to 30\t :" ;
Histogram(x);

x = fourcount;
cout << "\n31 to 40\t :" ;
Histogram(x);

x = fivecount;
cout << "\n41 to 50\t :" ;
Histogram(x);

x = sixcount;
cout << "\n51 to 60\t :" ;
Histogram(x);

x = sevencount;
cout << "\n61 to 70\t :" ;
Histogram(x);	

x = eightcount;
cout << "\n71 to 80\t :" ;
Histogram(x);

x = ninecount;
cout << "\n81 to 90\t :" ;
Histogram(x);

x = tencount;
cout << "\n91 to 100\t :" ;
Histogram(x);


cout <<endl<<endl;
cout<< "The amount of students who specified valid favourite numbers:"<<valid<<endl;
cout<< "The amount of students who specified invalid favourite numbers:"<<invalid<<endl;
cout<< "The amount of students who did not reveal there favourite numbers:"<<notrev<<endl;



	for(a=0;a<valid;a++)
	{
		countNum[a]=-1;
		uniqueNum[a]=0;
	}
			
	int finalNum[9999];
	int freq[9999];
	
	for(int b=0;b<valid;b++){
		count=1;
		for(int c=b+1;c<valid;c++){
			if(valnumbers[b]==valnumbers[c]){
				count++;
				countNum[c]=0;
			}
		}
		if(countNum[b] !=0)
			countNum[b]=count;
	}
	
	for(int b=0;b<valid;b++){
		if(countNum[b]!=0){
			finalNum[uniqueIndex]=valnumbers[b];
			freq[uniqueIndex]=countNum[b];
			uniqueIndex++;
		}
	}

	for(a=0;a<uniqueIndex;a++){
		if(freq[a]>max)
			max= freq[a];
		if(freq[a]<min)			
			min=freq[a];
	}
	
	cout<<endl<<"Number/s that were chosen the most by the students: ";
	for(a=0;a<uniqueIndex;a++){
		if(freq[a]==max){
			cout<<finalNum[a];
			cout<<" ";
		}
	}
	cout<<endl;
	cout<<"Number/s that were chosen the least by the students: ";
	for(a=0;a<uniqueIndex;a++){
		if(freq[a]==min){
			cout<<finalNum[a];
			cout<<" ";
		}
	}
	
	


in.close();

return 0;
}
