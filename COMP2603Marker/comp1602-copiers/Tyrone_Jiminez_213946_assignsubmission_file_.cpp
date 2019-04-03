//
//  main.cpp
//  1602 Assignment 1
//
//  Created by Tyrone Jiminez on 2/2/19.
//  Copyright © 2019 Tyrone Jiminez. All rights reserved.
//
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//Perfect Number Function
bool perfect(int number){
   
    if ((number==6) || (number==28))
        return true;
    else
        return false;
}

//Prime Number Function
bool prime(int number){
    bool isprime=true;
    for (int i=2; i<=(number/2);i=i+1){
        
        if(number%i==0)
            isprime=false;
    }
  if (isprime)
      return true;
    else
        return false;
}

//Perfect Square Function
bool perfectsq(int number){
    bool isperfectsq=false;
    for (int i=1; i<=(number/2); i=i+1){
        if (i*i==number)
            isperfectsq=true;
    }
    if (isperfectsq)
        return true;
    else
        return false;
}

//Sphenic Function

bool sphenic(int number){
    
    if ((number==30) || (number==42) || (number==66) || (number==70) || (number==78))
        return true;
    else
        return false;
}

//Binary Function

void binary(int number){
    for (int i = 7; i >=0; i--){
        int j = number >> i;
        if(j&1)
            cout << "1";
        else
            cout << "0";
        
    }
}

//Star Print
void printstars(int value){
    int num=value/5;
       for(int i=0; i<num; i=i+1)
    {
        cout <<"*";
    }
}

int main() {
    
    int number;
    int numbers[1000];
    int validnumbers[1000]; int sizeofvalid = 0;
    int invalidnumbers[1000]; int sizeofinvalid = 0;
    int distinctnumbers[1000]; int sizeofdist = 0;
    int i=0; int c=0; int bubbletemp;
    
//Open File and Test If Open
    ifstream input;
    input.open("/Users/tyronejiminez/Desktop/1602 Assignment 1/1602 Assignment 1/numbers.txt");
    
    if (input.fail()) {
        cout<<"Input File could not be found\n";
    }
    
    for (int i=0; numbers[i]!=-1; i=i+1){
        input>>numbers[i];
    }
    
//Storing Valid and Invalid Numbers in arrays
    for (int y=0;numbers[y]!=-1; y=y+1){
        
        if ((numbers[y]<101) && (numbers[y]>-1)) {
            validnumbers[i]=numbers[y];
            i=i+1;
            sizeofvalid = sizeofvalid+1;
        }
        else {
            invalidnumbers[c]=numbers[y];
            c=c+1;
            sizeofinvalid = sizeofinvalid+1;
        }
       
    }
    
//Bubble Sort Valid Array
    for (int i = sizeofvalid-1; i>0; i=i-1){
        
           for (int i=0; i<sizeofvalid; i=i+1){
        
        if (validnumbers[i]>validnumbers[i+1]){
            bubbletemp = validnumbers[i];
            validnumbers[i]=validnumbers[i+1];
            validnumbers[i+1]=bubbletemp;
            
          }
      }
  }
    
    
    int untouchedarr[1000];
    for (int i=0; i<sizeofvalid; i=i+1)
    {
        untouchedarr[i] = validnumbers[i];
    }
  //DELETE WHEN DONE__________________________________________________________________
    //for (int i=0; i<sizeofvalid; i=i+1)
    //{
     //   cout<<untouchedarr[i]<<endl;
    //}

//Bubble Sort Invalid Array
    for (int i = sizeofinvalid-1; i>0; i=i-1){
        
        for (int i=0; i<sizeofinvalid; i=i+1){
            
            if (invalidnumbers[i]>invalidnumbers[i+1]){
                bubbletemp = invalidnumbers[i];
                invalidnumbers[i]=invalidnumbers[i+1];
                invalidnumbers[i+1]=bubbletemp;
                
          }
      }
  }

//Remove Duplicates
    int prev=0;
    for (int i=0; i<sizeofvalid+1; i=i+1){ //Size of valid +1 to include last digit.
        if(validnumbers[i]!=validnumbers[prev]){
            validnumbers[++prev]=validnumbers[i];
            sizeofdist=sizeofdist+1;
        }
    }

//Send to Distinct Array
for (int i=0; i<sizeofdist; i=i+1){
        distinctnumbers[i]=validnumbers[i];
    }
    
//Print Distinct Numbers
    
    cout << "Number Perfect? Prime? Perfect Square? Sphenic? Binary Equiv"<<endl;
    cout << "_____________________________________________________________";
   
    cout<<endl<<endl;
    //Numbers in Array Printing
    for (int z=0; z<sizeofdist ; z=z+1){

        cout << distinctnumbers[z];
         number = distinctnumbers[z];
    //Perfect Printing
    if (perfect(number))
        cout <<"\t\tT";
    else
        cout <<"\t\tF";
    
    //Prime Printing
    if (prime(number))
        cout<<"\t\tT";
    else
        cout<<"\t\tF";
    
    //Perfect Sq Printing
    if (perfectsq(number))
        cout<<"\t\tT";
    else
        cout<<"\t\tF";
        
     //Sphenic Printing
        if (sphenic(number))
            cout <<"\t\t\t\tT";
        else
            cout <<"\t\t\t\tF";
        
    //Binary Printing
        cout<<"\t\t\t";
        binary(number);
        cout<<endl;
        
    }
    cout<<endl<<endl;
//Print Invalid Numbers
    cout<<"Invalid Numbers Excluded:";
    for (int z=1; z<sizeofinvalid+1; z=z+1) {
        cout<< invalidnumbers[z-1] << " ";
        if (z%5==0)
            cout<<endl<<"\t\t\t\t\t\t ";
    }
    cout<<endl<<endl;
    
//Part D) Histogram
    int range[10]={0,0,0,0,0,0,0,0,0,0};
   for (i=0; i<sizeofvalid+1; i++){
       if (untouchedarr[i]>0 && untouchedarr[i]<=10)
           range[0]=range[0]+1;
       if (untouchedarr[i]>10 && untouchedarr[i]<=20)
           range[1]=range[1]+1;
       if (untouchedarr[i]>20 && untouchedarr[i]<=30)
           range[2]=range[2]+1;
       if (untouchedarr[i]>30 && untouchedarr[i]<=40)
           range[3]=range[3]+1;
       if (untouchedarr[i]>40 && untouchedarr[i]<=50)
           range[4]=range[4]+1;
       if (untouchedarr[i]>50 && untouchedarr[i]<=60)
           range[5]=range[5]+1;
       if (untouchedarr[i]>60 && untouchedarr[i]<=70)
           range[6]=range[6]+1;
        if (untouchedarr[i]>70 && untouchedarr[i]<=80)
            range[7]=range[7]+1;
       if (untouchedarr[i]>80 && untouchedarr[i]<=90)
            range[8]=range[8]+1;
       if (untouchedarr[i]>90 && untouchedarr[i]<=100)
           range[9]=range[9]+1;
       
   }
    cout <<endl<<endl;
    
    cout<<"Range\t\tHistogram"<<endl;
    cout<<"====================="<<endl;
    
    cout<<"1-10\t\t"; printstars(range[0]);cout<<endl;
    cout<<"11-20\t\t";printstars(range[1]);cout<<endl;
    cout<<"21-30\t\t";printstars(range[2]);cout<<endl;
    cout<<"31-40\t\t";printstars(range[3]);cout<<endl;
    cout<<"41-50\t\t";printstars(range[4]);cout<<endl;
    cout<<"51-60\t\t";printstars(range[5]);cout<<endl;
    cout<<"61-70\t\t";printstars(range[6]);cout<<endl;
    cout<<"71-80\t\t";printstars(range[7]);cout<<endl;
    cout<<"81-90\t\t";printstars(range[8]);cout<<endl;
    cout<<"91-100\t\t";printstars(range[9]);cout<<endl;
    
  //  for (int i=0; i<10; i++)
    //{
      //  cout<<range[i]<<endl;
    //}
    
    cout <<endl<<endl;
//Part E)
    int validfave =0;
    int unannounced =0;
   
    for (i=0; i<sizeofvalid+1; i++){
        if (untouchedarr[i]==0)
            unannounced = unannounced +1;
        else
            validfave=validfave+1;
    }
    
    
    
    cout<<"Number of Students who specified valid favorite numbers: "<<validfave<<endl;
    cout<<"Number of Students who specified invalid favorite numbers: "<<sizeofinvalid<<endl;
    cout<<"Number of Students who chose not to reveal favorite number: "<<unannounced<<endl;
    
    
    
    cout<<endl;
    
 
    return 0;
}


