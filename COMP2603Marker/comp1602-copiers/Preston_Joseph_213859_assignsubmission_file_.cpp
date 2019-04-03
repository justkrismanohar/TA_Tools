//Assignment 1-COMP1602
//Student Name: Preston Joseph
//ID#:97705604
#include <iostream>
#include <fstream>
using namespace std;

//function prototype
bool isPerfect (int n);
bool isPrime (int n);
bool isPerfectSquare (int n);
bool isSphenic (int n);
void makeBinary (int num);
void starPrint (int num);

int main(){
//decalre all variables for main function
          int num;
          int num2;
          ifstream inFile;
          ifstream inFile2;
          bool testPerfect=false;
          bool testPerfectSquare=false;
          bool testPrime=false;
          bool testSphenic=false;
          int most=-2;
          int least=1000;
          int invalidCount=0;
          int invalidTally=0;
          int starTally=0;
          int count=0;
          int counter=0;
          int histogramCounter;
          int validTally=0;
          int arrayData[101];
//initialize values in array as zero
for (count=0;count<=101;count++)
arrayData[count]=0;
//open numbers.txt file
inFile.open("numbers.txt");
if (inFile.is_open() == false) {
cout << "Error opening input file. Aborting ...";
system("pause");
return 0;
}
//(a)
//read valid numbers from file and store tally in an array
inFile >> num;
while (num != -1||inFile.eof() == false) {
                                         for(count=0;count<=100;count++){
                                                                         if(num==count)
                                                                         arrayData[count]= arrayData[count]+1;
                                                                         }
                                         inFile >> num;
}
//(b)
//output table
cout<<"Number\t"<<"Perfect?\t"<<"Prime?\t"<<"Perfect Square?\t"<<"Sphenic?\t"<<"Binary Equiv."<<endl;
cout<<"======\t"<<"========\t"<<"======\t"<<"===============\t"<<"========\t"<<"============="<<endl;
for(count=1;count<=100;count++){
                                if(arrayData[count]!=0){
                                                        cout<<count<<"\t";
                                                        testPerfect=isPerfect(count);
                                                        if (testPerfect==true)
                                                        cout<<"Y\t\t";
                                                        else
                                                        cout<<"N\t\t";
                                                        testPrime=isPrime(count);
                                                        if (testPrime==true)
                                                        cout<<"Y\t";
                                                        else
                                                        cout<<"N\t";
                                                        testPerfectSquare=isPerfectSquare(count);
                                                        if (testPerfectSquare==true)
                                                        cout<<"Y\t\t";
                                                        else
                                                        cout<<"N\t\t";
                                                        testSphenic=isSphenic(count);
                                                        if (testSphenic==true)
                                                        cout<<"Y\t\t";
                                                        else
                                                        cout<<"N\t\t";
                                                        makeBinary(count);
                                                        cout<<endl;
                                                        if(count>0){
                                                        validTally=validTally+arrayData[count];
                                                        if(arrayData[count]>most)
                                                        most=arrayData[count];
                                                        if(arrayData[count]<least&&arrayData[count]>0)
                                                        least=arrayData[count];
                                                                    }
                                                        }
                                 }
cout<<endl;                                
//(c)
//read file again to output invalid numbers five in a row
inFile2.open("numbers.txt");
if (inFile2.is_open() == false) {
                                cout << "Error opening input file. Aborting ...";
system("pause");
return 0;
}
inFile2 >> num2;
cout<<"Invalid Numbers are as follows: "<<endl;
while (num2!= -1||inFile2.eof() == false) {
                                          if(num2<0||num2>100){
                                          invalidTally=invalidTally+1;
                                          cout<<num2<<"\t";
                                          if(invalidTally%5==0)
                                          cout<<endl;
                                          }
inFile2 >> num2;
}
cout<<endl;
cout<<endl;
cout<<endl;
//(d)
cout <<"Range\tHistogram"<<endl;
cout <<"================="<<endl;
for(histogramCounter=1;histogramCounter<=100;histogramCounter=histogramCounter+10){
                                                                                   cout<<histogramCounter<<"-"<<histogramCounter+9<<"\t|";                  
                                                                                   for(int count=histogramCounter;count<=histogramCounter+9;count++)
                                                                                   starTally=arrayData[count]+starTally;
                                                                                   starPrint(starTally/5);
                                                                                   starTally=0;
                                                                                   cout<<endl;
                                                                                   }
cout<<endl;                                                                                   
//(e)(i)
cout<<"Number of students who specified valid favourite numbers: "<<validTally<<endl;
cout<<endl;
cout<<"Number of students who specified invalid favourite numbers: "<<invalidTally<<endl;
cout<<endl;
cout<<"Number of students who did not reveal their favourite number: "<<arrayData[0]<<endl;
cout<<endl;
cout<<endl;
//(e)(ii)
cout<<"Numbers chosen with the greatest frequency: ";
for(count=0;count<=100;count++){
                                if(arrayData[count]== most)
                                cout<<count<<"\t";
                                }
cout<<endl;
cout<<endl;
//(e)(iii)
cout<<"Numbers chosen with the lowest frequency of at least one: "<<endl;
for(count=0;count<=100;count++){
                                if(arrayData[count]== least)
                                cout<<count<<"\t";
                                } 
cout<<endl;                                                                 
inFile.close();
inFile2.close();
system("pause");
return 0;
}
//end of main function
//
//Functions
//is integer x perfect?---(b)(i)
bool isPerfect (int n){
     int i=1;
     int sum=0;
     while(i<n){
                if(n%i==0)
                sum=sum+i;
                i=i+1;
                }
     if(sum==n)
     return true;
     }
//is integer x prime?---(b)(ii)
bool isPrime (int n){
     int i=2;
     if (n<=1){
               return false;
               }
     else{
          while (i<n){
                      if(n%i==0){
                                 return false;
                                 }
         else {
               i=i+1;   
               }
         }
return true;       
}
}
//is integer x a perfect square?---(b)(iii)
bool isPerfectSquare (int n){
     int i=1;
     while(i<=n){
                 if(n==i*i){
                            return true;
                            }
                 else{
                      i=i+1;   
                      }
                 }
         return false;
}
//is integer x sphenic?---(b)(iv)
bool isSphenic (int n){
     bool primeTest=false;
     int count=0;
     int i=1;
     int check=1;
     int temp=n;
     while (i<=temp){
                     if(temp%i==0){
                                   primeTest=isPrime (i);
                                   if (primeTest==true){
                                                        count=count+1;
                                                        temp=temp/i;
                                                        check=check*i;
                                                        }
                                   }
                     i=i+1;
                     }
     if (count==3&&primeTest==true&&check==n)
     return true;
     else
     return false;
}
//make a number binary---(b)(v)
void makeBinary (int num){
     int arr[8]={0,0,0,0,0,0,0,0};
     int i=0;
     int div;
     int temp;
     div=num;
     while(div>0||i<8){
                       arr[i]=div%2;
                       div=div/2;
                       i=i+1;
                       }
     for (i=0;i<=4;i++){
                        temp=arr[i];
                        arr[i]=arr[7-i];
                        arr[7-i]=temp;
                        }
     for(i=0;i<=7;i++)
     cout<<arr[i];
} 
//print stars for Histogram   
 void starPrint (int num){
     int i;
     for(i=1;i<=num;i++)
     cout<<"*";
     cout<<endl;
}        
                   
