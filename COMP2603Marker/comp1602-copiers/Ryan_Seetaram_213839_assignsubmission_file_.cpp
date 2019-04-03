#include <iostream>
#include<fstream>
#include<cmath>

using namespace std;

void perfect(int num){
	int sum=0;

	for(int i=1; i<=num/2;i++){

	  if (num%i==0){
			sum=sum+i;
		}
}

if (sum==num)
	cout <<"Y";

else
cout << "N";

}






void perfectSquare(int num){
	float root=sqrt(num);

	int base=floor(root);


	if((root-base)==0)
	cout <<"Y";

	else
		cout <<"N";

}

void prime(int num){
		int sum=0;
	for(int i=1; i<=num/2;i++){

		if (num%i==0){
			sum=sum+i;
		}
}
if (sum==1)
	cout<<"Y";
else
cout <<"N";



}
void binary(int num){

	int rem=0;
	int array[8];
	int count=0;

	for(int i=0; i<8; i++)

	array[i]=0;

	while(num!=0){

	rem=num%2;

	if(rem==0)
		array[count]=0;

	else
	array[count]=1;


    num=num/2;
    count++;
}
for(int i=7; i>=0; i--){
	cout <<array[i];

}
}

void sphenic(int num){
	int count=0;
	int prod=1;
	int sum=0;

 	for(int i=2; i<=num; i++){

 		if ((num%i)==0){


        sum=0;

       for(int k=1; k<=i/2;k++){
          if (i%k==0)
			sum=sum+k;
		}

 			if (sum==1)	{

 			count++;

 			prod=prod*i;

		 }

}
}

if ((count==3) && (prod==num))
 cout <<"Y";

 else
 cout <<"N";

}







int main(){

	int num;

	ifstream in;
	ofstream out;


	in.open("numbers1.txt");

	cout <<"Number       Perfect?         Prime?      Perfect Sqaure?      Sphenic?          Binary " << endl;
    cout <<"======================================================================================================" << endl;


	in >>num;

	 while(num!=-1){

		cout << num <<"\t""\t";

		perfect(num);
		cout <<"\t""\t";

		prime(num);
		cout <<"\t""\t";

		perfectSquare(num);
		cout <<"\t""\t";

		sphenic(num);
		cout <<"\t""\t";

		binary(num);
		cout <<"\t""\t";

		cout <<endl;


    in >>num;

}

if (num <= -1)
    count++;
  (count=count %5)
  cout << "Invalid " << count << endl;

}
 if (num <=1 || num <= 10)
    count++;
 if (count == 5 )
    cout << "*";
 if (num <= 11 || num <= 20)
    count++;
  if(count == 5)
    cout << "*";
  if (num<=21 || num <= 30)
    count++;
  if(count==5)
    cout<< "*";
  if (num <=31 || num <=40)
    count++;
  if (num==5)
    cout << "*";
  if (num<=41 || num<=50)
    count++;
  if (num==5)
    cout<<"*";
  if (num <=51 || num <= 60)
    count++;
  if (num==5)
    cout<<"*";
  if (num <=61 || num <= 70)
    count++;
  if (num==5)
    cout<<"*";
  if( num<=71 || num <=80)
  count++;
  if (num==5)
    cout << "*";
  if (num<=81 || num <=90)
    count++;
  if (num==5)
    cout << "*";
  if (num<=91 || num <= 100)
    count++;
  if (num==5)
    cout<<"*";

  return 0;
}

