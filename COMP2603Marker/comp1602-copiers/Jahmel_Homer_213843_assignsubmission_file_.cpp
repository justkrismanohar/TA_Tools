#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

char isPerfect(int n){

int sum=1;

    for (int i=2; i<=n/2; i++){

    if (n%i==0){
        sum=sum+i;
    }
}
    if (sum==n){

    return 'Y';
  }
    return 'N';
}

char isPrime(int n){

for(int i=2; i<=sqrt(n); i++){

    if(n%i==0)

        return 'N';
    }
        return 'Y';
 }

char perfectSquare(int n){

int square;

for (int i=1; i<=n/2; i++){

        if(n%i==0)

        square=(i*i);

}
    if (square==n){

        return 'Y';
    }
        return 'N';
}

char isSphenic(int n){

int product=1;
int count=0;

for (int i=2; i<=n/2; i++){

        if (n%i==0 && isPrime(i)=='Y'){

            product=(product*i);
            count=count+1;
        }
}
    if (count==3 && product==n){

        return 'Y';
    }
        return 'N';
}

void binaryEqiv(int n){

int binary[8];
    int i=0;


 for(i=0; i<8; i++){
    binary[i]=0;
  }

 for(i=0; i<8; i++){
        binary[i]=n%2;
        n=n/2;
 }
  for (i=7; i>=0; i--){

    cout<<binary[i];
  }
}

 void printStars(int n){

 for(int i=1; i<=n; i++){

    cout<<"*";
 }
}

int main(){

  ifstream in;

  in.open("numbers.txt");
  if(!in.is_open()){
    cout<<"Error File Not Found!";
    return 0;
  }

  int Students[1000];
  int Invalid[1000];
  int Valid[1000];
  int Distinct[1000];
  int noValue[1000];
  int Range[10];
  int num;
  int i=0;
  int k=0;
  int l=0;
  int j=0;
  int numStudents=0;
  int invalidNum=0;
  int validNum=0;
  int noFav=0;
  int disNum, binary, stars;

  char perfect;
  char prime;
  char pSquare;
  char sphenic;

 	in>>num;

	while (num!=-1){

		Students[i]=num;

		in>>num;
		i++;
}
    numStudents=i;

for (i=0; i<numStudents; i++){

	if (Students[i]>=1 && Students[i]<=100){

		Valid[validNum]=Students[i];
		validNum++;
	}
	if (Students[i]<0 || Students[i]>100){

		Invalid[invalidNum]=Students[i];
		invalidNum++;
	}
	if (Students[i]==0){

		noValue[noFav]=Students[i];
		noFav++;
	}
}

 for (int i=0; i<validNum; i++) {

        for (j=0; j<i; j++)
           if (Valid[i]==Valid[j])
               break;

        if (i==j){
         Distinct[l]=Valid[i];
          l++;
        }
}
disNum=l;

cout<<"Number\t\tPerfect?\t\tPrime?\t\tPerfect Square?\t\tSphenic?\t\tBinary Equiv."<<endl;
cout<<"=====\t\t=======\t\t\t=====\t\t==============\t\t=======\t\t\t============"<<endl;

for (i=0; i<disNum; i++){


        perfect=isPerfect(Distinct[i]);
        prime=isPrime(Distinct[i]);
        pSquare=perfectSquare(Distinct[i]);
        sphenic=isSphenic(Distinct[i]);

    cout<<Distinct[i]<<"\t\t  "<<perfect<<"\t\t\t  "<<prime<<"\t\t\t"<<pSquare<<"\t\t  "<<sphenic<<"\t\t\t";binaryEqiv(Distinct[i]);
    cout<<endl;
}

cout<<endl;
cout<<"Invalid Numbers"<<endl;
cout<<"==============="<<endl;

for(i=0; i<invalidNum; i++){

    cout<<Invalid[i]<<" , ";

    if((i+1)%5==0){
        cout<<endl;
    }
}
cout<<endl;
cout<<endl;

cout<<"Range \t Histogram"<<endl;
cout<<"====================="<<endl;

for(i=0; i<validNum; i++){

    if (Valid[i]>=1 && Valid[i]<=10){
        Range[0]=Range[0]+1;
    }
    if (Valid[i]>=11 && Valid[i]<=20){
        Range[1]=Range[1]+1;
    }
    if (Valid[i]>=21 && Valid[i]<=30){
        Range[2]=Range[2]+1;
    }
    if (Valid[i]>=31 && Valid[i]<=40){
        Range[3]=Range[3]+1;
    }
    if (Valid[i]>=41 && Valid[i]<=50){
        Range[4]=Range[4]+1;
    }
    if (Valid[i]>=51 && Valid[i]<=60){
        Range[5]=Range[5]+1;
    }
    if (Valid[i]>=61 && Valid[i]<=70){
        Range[6]=Range[6]+1;
    }
    if (Valid[i]>=71 && Valid[i]<=80){
        Range[7]=Range[7]+1;
    }
    if (Valid[i]>=81 && Valid[i]<=90){
        Range[8]=Range[8]+1;
    }
    if (Valid[i]>=91 && Valid[i]<=100){
        Range[9]=Range[9]+1;
    }
}
cout<<"1-10 \t|";stars=(Range[0]/5);printStars(stars);
cout<<endl;
cout<<"11-20 \t|";stars=(Range[1]/5);printStars(stars);
cout<<endl;
cout<<"21-30 \t|";stars=(Range[2]/5);printStars(stars);
cout<<endl;
cout<<"31-40 \t|";stars=(Range[3]/5);printStars(stars);
cout<<endl;
cout<<"41-50 \t|";stars=(Range[4]/5);printStars(stars);
cout<<endl;
cout<<"51-60 \t|";stars=(Range[5]/5);printStars(stars);
cout<<endl;
cout<<"61-70 \t|";stars=(Range[6]/5);printStars(stars);
cout<<endl;
cout<<"71-80 \t|";stars=(Range[7]/5);printStars(stars);
cout<<endl;
cout<<"81-90 \t|";stars=(Range[8]/5);printStars(stars);
cout<<endl;
cout<<"91-100 \t|";stars=(Range[9]/5);printStars(stars);
cout<<endl;


int numCount[validNum];
int count;
int maxCount=-1;
int minCount=999;
int maxNum;
int minNum;

for(i=0; i<validNum; i++){

    numCount[i]=-1;
    count=0;

    for(j=i+1; j<validNum; j++){
        if(Valid[i]==Valid[j]){
            count++;
            numCount[j]=0;
     }
    }
    if(numCount[i]!=0){
       numCount[i]=count;
    }

    if(numCount[i]>maxCount){
        maxCount=numCount[i];
        maxNum=Valid[i];
    }

    if(numCount[i]<minCount){
        minCount=numCount[i];
        minNum=Valid[i];
    }
}



cout<<endl;
cout<<endl;
cout<<"===============Statistical Information==============="<<endl;
cout<<endl;
cout<<"Amount of students who specified :-"<<endl;
cout<<"Valid Favourite Numbers: "<<validNum<<" Students"<<endl;
cout<<"Invalid Favourite Numbers: "<<invalidNum<<" Students"<<endl;
cout<<"Did not reveal favourite Numbers: "<<noFav<<" Students"<<endl;
cout<<"Most chosen favourite valid number: "<<maxNum<<endl;
cout<<"Least chosen valid number: "<<minNum<<endl;
cout<<endl;
cout<<"======================================================"<<endl;

    in.close();
    return 0;
}
