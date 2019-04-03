#include <iostream>
#include <fstream>
using namespace std;
bool perfect(int n){
    int sum, b, a;
    for (a=n-1; a>1; a=a-1) {
        b=n%a;
        if (b==0) {
            sum=sum+a;} }
            if (sum==n) { 
                return true;}
                return false;}
                
bool prime(int n) {
    int a;
    for (a=n-1; a>1; a=a-1) {
        int b= n%a; }
        if (b==0) {
            return false;}
            return true;}
            
bool perfectSquare(int n) {
    int a; float b;
    a=sqrt(n);
    b= ceil a;
    if ( b*b==a) {
        return true;}
        
        return false;}

bool sphenic(int n) {
    if (n==30 || n== 42 || n==66 || n== 70|| n==78){
        return true;}
        return false;}
    
bool binary(int n){
    int array[8];
    int div, i, j;
    for (i=0, i<8, i++;){
        while(n!=0){
            div= n%2;
            n=n/2;
            array[i]=div;}}
            for(j=0, j<4, j++;){
                int temp=array[j];
                array[j]=array[7-j];
                array[7-j]=temp[j]; }
            }
        
    

int main()
{
int n, valid=0, notreveal=o, invalid=0, ten=0, twenty=0, thirty=0, forty=0, fifty=0, sixty=0, seventy=0, eighty=
0, ninety=0, hundred=o, inv=0;
int array[inv];

ifstream inputfile;
inputfile.open("numbers.txt");
if (!inputfile.is_open()){
    cout<< "Error opening input file. aborting....";
    return 0;}

inputfile>>n;
cout<< "Number" <</t<< "Perfect" <</t<< "Prime" <</t<< "Perfect Square" <</t<< "Sphenic" <</t<< "Binary Equivalent"<<endl;
cout<< "==========================================================================================================="<<endl;
while(n!=1){
    if(n>=1 && n<=100){
        valid=valid+1;
        perfect();
        prime();
        perfectSquare();
        sphenic();
        binary();
cout<< n <</t<< perfect <</t<< prime <</t<< perfectSquare <</t<< sphenic <</t<< binary <<endl;  }
  
      
      if(n>=1 &&n<=10){
          ten=ten+1;}
     if(n>=11 && n<=20){
          twenty=twenty+1; }
 if(n>=21 && n<=30) {
          thirty=thirty+1; }
            if(n>=31 &&n<=40) {
          forty=forty+1; }
            if(n>=41 && n<=50) {
          fifty=fifty+1;}
           if(n>=51 &&      n<=60) {
          sixty=sixty+1;}
            if(n>=61 &&      n<=70) {
          seventy=seventy+1;}
            if(n>=71 &&      n<=80) {
          eighty=eighty+1;}
            if(n>=81 &&      n<=90) {
          ninety+ninety+1;}
            if(n>=91 &&      n<=100) {
          hundred=hundred+1:}
if(n==0){
      notreveal=notreveal+1;}
      
    invalid=invalid+1;
    array[inv]=n;
    inv=inv+1;
}

     for(inv>=0, inv<inv, inv++;) {
 cout << array[inv]
     }
     
cout<< "Range" <</t/t<< "Histogram" << endl;
cout<< "=================================" << endl;
cout<< "1-10" <</t/t<< ten<<endl;
cout<< "11-20" <</t/t<< twenty<< endl;
cout<< "21-30" <</t/t<< thirty<< endl;
cout<< "31-40" <</t/t<< forty<< endl;
cout<< "41-50" <</t/t<< fifty<< endl;
cout<< "51-60" <</t/t<< sixty<< endl;
cout<< "61-70" <</t/t<< seventy<< endl;
cout<< "71-80" <</t/t<< eighty<<endl;
cout<< "81-90" <</t/t<< ninety<<endl;
cout<< "91-100" <</t/t<< hundred<<endl;
cout<<endl;
cout<<endl;
cout<<"Amount of student that specified valid numbers: "<<valid<<endl;
cout<<"Amount of students who specified invalid numbers: "<<invalid<<endl;
cout<<"Amount of students that didnt reveal a number: " <<notreveal<<endl;
     
     return 0;
}
