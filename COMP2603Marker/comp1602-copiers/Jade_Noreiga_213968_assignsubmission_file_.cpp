//Jade Noreiga
//816017390
//COMP 1602 - Assignment #1

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
//Perfect Function
bool isPerfect(int x){
  int div;
  int sum=0;
  for( int i=1; i<= x/2; i++){
    div = x % i;
    if(div==0)
    sum=sum+i;
  }
  if (sum==x){
    return true;
  }
  return false;
}
//Prime Function
bool isprime(int x){
  int mod;
  for(int i=2; i<=x/2; i++){
    mod= x % i;
    if ( mod==0)
    return false;
  }
}
//Perfect Square Function
bool isperfectsquare (int x){
  int mult;
        if (x==1)
        // 1 is the first perfect square and isn't included in the for loop below
          return true;
  for(int i=1; i<=x/2; i++){
    mult= i * i;
    if(mult==x)
    return true;
  }
  return false;
}
//Sphenic Function
bool isSphenic(int x){
 int div1;
 int numprimes=0;
 int j = 2;
   while(x>0 && j<=x){
     if (isprime(j)){
     div1= x%j;
        if (div1==0){
         x=x/j;
         numprimes++;
        }
     }
     j++;
  }
  
     if (numprimes == 3)
     return true;
  else
     return false;
}
//Binary Function
void binary(int x){
  int mod[8];
  int temp;
  for(int i=0; i<8; i++){
  mod[i]=0;
  }
   int j=0;
   while(x!=0){
   mod[7-j]= x%2;
   x=x/2;
   j++;
   } 
for(int i=0; i<8; i++){
cout<<mod[i];
}
cout<<endl;
}

//Histogram Function
void hist(int p){
  for(int i=0; i<p; i++)
  cout<<"*";
  cout<<endl; // not included in for loop
}
 
//816017390 

int main(){
  int x,k,num;
  int numstud=0;
  int stud[999999];
  char perfect, prime, perfsqu, sphen;
  int validfav=0;
  int invalidfav=0;
  int invalid[999999];
  int t=0;
  int nofav=0;
  int R1, R2, R3, R4, R5, R6, R7, R8, R9, R10;

 
for(int i=0; i<999999; i++)
  invalid[i]=0;

ifstream fin;
fin.open("numbers.txt");
if(fin.is_open()){
    fin>>num;
  while(num!=-1){
       stud[numstud]=num;
       numstud++;
    fin>>num;
  }


  cout<<"Number \t Perfect? \t Prime? \t Perfect Square? \t Sphenic? \t Binary Equiv."<<endl;
  cout<<"====== \t ======== \t ====== \t ============== \t ======= \t ============"<<endl;
  for(int i=0; i<numstud ; i++){
    x=stud[i];
    if (x==0){
    nofav++;
      }
    if(x>=1 && x<=100){
      validfav++;
      if (isPerfect(x)==true)
        perfect='Y';
      else 
        perfect='N';

      if (isprime(x)==true)
        prime='Y';
      else 
         prime='N';

      if (isperfectsquare(x)==true)
        perfsqu='Y';
      else 
        perfsqu='N';

      if (isSphenic(x)==true)
        sphen='Y';
      else 
        sphen='N';

      
    cout<<x<<"\t\t\t"<<perfect<<"\t\t\t"<<prime<<"\t\t\t"<<perfsqu<<"\t\t\t\t\t"<<sphen<<"\t\t\t";
    binary(x);
    // the function binary consists of an endl...
    }
    else{
      invalid[t]=stud[i];
    t++;
    

  }
  }
  cout<<" "<<endl;
   cout<<"Invalid Numbers:"<<endl;
  int d=1;
    for(k=0; k<t;k=k+1){
    cout<<invalid[k]<<"\t";
    if(d%5==0)
    cout<<" "<< endl;
    d++;
    }

   

    invalidfav= t ;
    // since when t leaves the for loop it is already 1 more than what is actually present because t is initiated as 0.
   //note it '0' was taken as an invalid number since it was not included in the range in part b
    
  int histogram[10];
  for( int i= 0; i<10; i++)
   histogram[i]=0;
   
   for (int j=0; j<numstud; j++){

   if(stud[j]>=1 && stud[j]<=10)
   histogram[0]= histogram[0]+1;

   if(stud[j]>=11 && stud[j]<=20)
   histogram[1]= histogram[1]+1;

   if(stud[j]>=21 && stud[j]<=30)
   histogram[2]= histogram[2]+1;

   if(stud[j]>=31 && stud[j]<=40)
   histogram[3]= histogram[3]+1;

   if(stud[j]>=41 && stud[j]<=50)
   histogram[4]= histogram[4]+1;

   if(stud[j]>=51 && stud[j]<=60)
   histogram[5]= histogram[5]+1;

   if(stud[j]>=61 && stud[j]<=70)
   histogram[6]= histogram[6]+1;

   if(stud[j]>=71 && stud[j]<=80)
   histogram[7]= histogram[7]+1;

   if(stud[j]>=81 && stud[j]<=90)
   histogram[8]= histogram[8]+1;

   if(stud[j]>=91 && stud[j]<=100)
   histogram[9]= histogram[9]+1;
   }

   R1= histogram[0]/5;
   R2= histogram[1]/5;
   R3= histogram[2]/5;
   R4= histogram[3]/5;
   R5= histogram[4]/5;
   R6= histogram[5]/5;
   R7= histogram[6]/5;
   R8= histogram[7]/5;
   R9= histogram[8]/5;
   R10= histogram[9]/5;

   cout<<" "<< endl;

   cout<<"\nRange \t  Histogram"<<endl;
   cout<<"=================================="<<endl;
   cout<<"1-10 \t |"; 
   hist(R1); // the hist function includes the endline.
   cout<<"11-20 \t |";
   hist(R2);
   cout<<"21-30 \t |";
   hist(R3);
   cout<<"31-40 \t |";
   hist(R4);
   cout<<"41-50 \t |";
   hist(R5);
   cout<<"51-60 \t |";
   hist(R6);
   cout<<"61-70 \t |";
   hist(R7);
   cout<<"71-80 \t |";
   hist(R8);
   cout<<"81-90 \t |";
   hist(R9);
   cout<<"91-100 \t |";
   hist(R10);

cout<<" "<<endl;

   cout<<validfav<<" specified a VALID favourite number."<<endl;
   cout<<invalidfav<<" specified an INVALID favourite number."<<endl;
   cout<<nofav<<" specified NO favourite number."<<endl;

//e ii & iii
cout<<" "<<endl;
cout<<"The number/s that was/were chosen the most by students, in the valid range, is/are: ";
int A[100];
int count[100];
int highest= 0;
int lowest=99999;

for(int i= 0; i<100; i++)
A[i]=i+1;

for(int i= 0; i<100; i++)
count[i]=0;

for(int i= 0; i<100; i++){
for(int j= 0; j<validfav; j++){
  if (A[i]==stud[j])
  count[i]++;
   }
}
for(int i= 0; i<100; i++){
  if(count[i]> highest)
  highest=count[i];

}
if (highest>=2){
for(int i= 0; i<100; i++){
  if(count[i]==highest)
  cout<<A[i]<<" ";
}
}
else 
cout<<"No number is repeated twice or more times";
cout<<endl;

cout<<"The number/s that was/were chosen the least by students, in the valid range, is/are: ";

for(int i= 0; i<100; i++){
  if(count[i]< lowest && count[i]!=0)
  lowest=count[i];

}

if (lowest>=1){
for(int i= 0; i<100; i++){
  if(count[i]== lowest)
  cout<<A[i]<<" ";
}
}
cout<<endl;
   }
else {
cout<<"File not found"<<endl;
return 0;
}

  return 0;
}
