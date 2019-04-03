#include <iostream>
#include<fstream>
#include<cmath>
using namespace std;

void perfect(int number){
	int sum=0;
	for(int i=1; i<=number/2;i++){

		if (number%i==0){
			sum=sum+i;
		}
}

if (sum==number)
	cout <<"Y";

else
cout << "N";

}


void prime(int number){
		int sum=0;
	for(int i=1; i<=number/2;i++){

		if (number%i==0){
			sum=sum+i;
		}
}
if (sum==1)
    cout<<"Y";
else
cout <<"N";




}

void Psquare(int number){
	float root=sqrt(number);
		int base=floor(root);


	if((root-base)==0)
	cout <<"Y";

	else
		cout <<"N";





}

void sphenic(int number){
	int count=0;
	int product=1;
	int sum=0;
 	for(int i=2; i<=number; i++){

 		if ((number%i)==0){


 			 sum=0;
 			for(int k=1; k<=i/2;k++){

		if (i%k==0)
			sum=sum+k;
		}

 			if (sum==1)	{

 			count=count+1;

 			product=product*i;

		 }

}
}

 if ((count==3) && (product==number))
 cout <<"Y";

 else
 cout <<"N";






}



void bin(int number){

	int rem=0;
	int array[8];
	int count=0;

	for(int i=0; i<8; i++)
	array[i]=0;


	while(number!=0){

	rem=number%2;
	if(rem==0)
		array[count]=0;

	else
	array[count]=1;



	number=number/2;


	count=count+1;
}


for(int i=7; i>=0; i--){
	cout <<array[i];


}


}

void printstars(int num){
	for(int i=0; i<num; i++)
	cout <<"*";


}






int main(){
	ifstream in;
	ofstream out;
	in.open("numbers.txt");
	if(!in.is_open()){
        cout<<"The file was not found. Aborting...";
        return 0;
	}


	int number;
	int invalidcount=0;
	int zerocount=0;



		cout <<"Number"<<"\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Sqaure?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equiv. ";
		cout <<endl;
		cout <<"============================================================================================================";
		cout <<endl;

	int distinct[101];
	for (int i=0; i<=100; i++){
		distinct[i]=0;
	}

		int invalid[56000];
	for (int i=0; i<=56000; i++){
		invalid[i]=0;
	}

	in >>number;
	while(number!=-1){
		if((number>=1) &&(number<=100)){



			if(distinct[number]==0){



			cout << number <<"\t";  cout <<"\t";
			perfect(number); cout <<"\t"; cout <<"\t";
			prime(number);   cout <<"\t"; cout <<"\t";
			Psquare(number);   cout <<"\t";  cout <<"\t";
			sphenic(number);  cout <<"\t"; cout <<"\t";
			bin(number);       cout <<"\t"; cout <<"\t";
			cout <<endl;


	}
	distinct[number]++;
}
	else {

		invalid[invalidcount+1]=number;
				invalidcount++;
}

if (number==0)
zerocount++;



		in >>number;






}

cout <<endl <<"Invalid Numbers  " <<endl;
int i=1;
	if((invalid[i])!=0){
while((invalid[i])!=0){

cout <<invalid[i] << "     ";
	if ((i%5)==0)
	cout <<endl;

i++;

}
}

cout <<endl;
cout <<endl;

int total=0;
cout<<"Range"<<"\t"<<"Histogram" <<endl
	<< "========================" <<endl;

	for(int i=1; i<=100; i=i+10){
		total=0;

	cout <<i << "-" <<i+9;
	cout <<"\t   ";
		for (int hold=i; hold<=i+9; hold++){


		total = total+distinct[hold];
}
	printstars(total/5);
	cout <<endl;




}


cout <<endl <<endl;
int valid=0;
for(i=1; i<=100; i++){
	valid= valid+distinct[i];
}
cout <<"Valid number count  : " <<valid <<endl;
cout <<"Invalid number count : " <<invalidcount <<endl;
cout <<"Persons who did not reveal their favorite number: " <<zerocount <<endl;


cout <<endl;

int maxvalue=0;
int max=0;
int min=99999;
int minvalue=99999;

for(int i=1; i<=100; i++){
	if((distinct[i]>1)&&(distinct[i]>maxvalue)){

	maxvalue=distinct[i];
	max=i;
}

}

cout <<"The  number most frequenly chosen is " <<max;


for(int i=1; i<=100; i++){
	if((distinct[i]==maxvalue) && (i!=max))
	cout << ", " << i;

}




cout <<endl;



for(int i=1; i<=100; i++){
	if((distinct[i]>0)&&(distinct[i]<minvalue)){

	minvalue=distinct[i];
	min=i;
}
}
cout <<"The  numbers least frequenly chosen are " <<min;


for(int i=1; i<=100; i++){
	if((distinct[i]==minvalue) && (i!=min))
	cout << ", " << i;

}










	return 0;
}
