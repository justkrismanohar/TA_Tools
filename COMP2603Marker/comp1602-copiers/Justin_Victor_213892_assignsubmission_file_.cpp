//Justin Victor
//816011075
#include <iostream>
#include<fstream>
#include<cmath>
using namespace std;

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

void Psquare(int number){
	float root=sqrt(number);

	int base=floor(root);


	if((root-base)==0)
	cout <<"Y";

	else
		cout <<"N";





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







int main(){
	ifstream fin;
	ofstream fout;
	fin.open("numbers.txt");


	int number;
    int invalid[999];
    int i=0;
    int count=1;

		cout <<"Number       Perfect?         Prime?     Perfect Sqaure        Sphenic          Binary ";
		cout <<endl;
		cout <<"=========    ==========      ========    ================      =========        =========";
		cout <<endl;
	fin >>number;

	while(number!=-1){

		cout << number <<"\t";  cout <<"\t";
		perfect(number); cout <<"\t"; cout <<"\t";
		prime(number);   cout <<"\t"; cout <<"\t";
		Psquare(number);   cout <<"\t";  cout <<"\t";
		sphenic(number);  cout <<"\t"; cout <<"\t";
		bin(number);       cout <<"\t"; cout <<"\t";
		cout <<endl;
     fin >>number;

     //if((number<-1)||(number>100)){
      //      invalid[i]=number;

       //    fin>>number;
       //    i=i+1;
        //   count=count+1;
    // }




//for( i=0; i<count; i=i+1){

         // cout<<"Invalid Numbers:"<<endl;

           //}
}
















	return 0;
}
