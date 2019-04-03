//  main.cpp
//  Sem2_Assignment1
//  Created by Tasnim Ramnarine on 29/01/2019.
//  Copyright © 2019 Tasnim Ramnarine. All rights reserved.
//  Due to the uncertain nature of the the amount of invalid variables in the file, I chose to use a file to store these invalid entries to prevent creating an array that has unnecessary storage.

#include <iostream>
#include<fstream>
using namespace std;

char isperfect(int n){
    char perfect;
    int i,sum=0;
    for(i=2;i<n;i++){
        if(n%i==0)
            sum=sum+i;
    }
    if(sum==n)
        perfect='Y';
    else
        perfect='N';
    return perfect;
}

char isprime(int n){
    char prime;
    int i;
    for(i=2;i<n;i++){
        if (n%i==0){
            prime='N';
            return prime;}
    }
    prime='Y';
    return prime;
}

char issqr(int n){
    int i;
    char sqr;
    for (i=2;i<=50;i++){
        if (n==i*i){
            sqr='Y';
        return sqr;}
        else
            i++;
            }
    sqr='N';
    return sqr;
}

char issphenic(int n){
    char prime,sphenic;
    int i,count=0,prod=1;
    for(i=2;i<n;i++){
        prime=isprime(n);
        if(prime=='Y'){
            prod=prod*i;
            count=count+1;
        }
    }
    if((prod==n)&&(count==3)){
        sphenic='Y';
        return sphenic;}
    sphenic='N';
    return sphenic;
}

void Binary(int n){
    int count,bits[8],rem;
    rem=n;
    for (count=0;count<8;count++)
        bits[count]=0;
    count=7;
    while((rem!=0)&&(count>=0)){
        bits[count]=rem%2;
        rem=rem/2;
        count=count-1;
    }
    for(count=0;count<8;count++)
        cout<<bits[count];
}

int main() {
    char sphenic,perfect,prime,sqr;
    int i,a,x,num,valid=0,invalid=0,zero=0,hist[10],count[100],highest=0;
    string range[10];
    range[0]="1-10";
    range[1]="11-20";
    range[2]="21-30";
    range[3]="31-40";
    range[4]="41-50";
    range[5]="51-60";
    range[6]="61-70";
    range[7]="71-80";
    range[8]="81-90";
    range[9]="91-100";
    for (i=0;i<10;i++)
        hist[i]=0;
    for (i=0;i<100;i++)
        count[i]=0;
    ifstream in;
    ofstream out;
    in.open("/Users/rexdixon/Desktop/C++ Projects/Sem2_Assignment1/Sem2_Assignment1/numbers.txt");/*Compiler used requires full address of text files used.*/
    if(in.is_open()==false){
        cout<<"ERROR"<<endl;
        return 0;
    }
    out.open("/Users/rexdixon/Desktop/C++ Projects/Sem2_Assignment1/Sem2_Assignment1/invalid.txt");/*Compiler used requires full address of text files used.*/
    in>>num;
    cout<<"Number\tPerfect\tPrime\tPerfect Square\tSphenic\tBinary"<<endl;
    cout<<"======\t=======\t=====\t==============\t=======\t======"<<endl<<endl;
    while(num!=-1){
        if((num<=100)&&(num>=1)){
            valid=valid+1;
            i=num-1;
            if(count[i]==0){
                count[i]++;
                perfect=isperfect(num);
                sqr=issqr(num);
                prime=isprime(num);
                sphenic=issphenic(num);
                cout<<num<<"\t\t"<<perfect<<"\t\t"<<prime<<"\t\t\t"<<sqr<<"\t\t\t"<<sphenic<<"\t\t";
                Binary(num);
                cout<<endl;
            }
            else
                count[i]++;
            if((num>=1)&&(num<=10))
                hist[0]=hist[0]+1;
            if((num>=11)&&(num<=20))
                hist[1]=hist[1]+1;
            if((num>=21)&&(num<=30))
                hist[2]=hist[2]+1;
            if((num>=31)&&(num<=40))
                hist[3]=hist[3]+1;
            if((num>=41)&&(num<=50))
                hist[4]=hist[4]+1;
            if((num>=51)&&(num<=60))
                hist[5]=hist[5]+1;
            if((num>=61)&&(num<=70))
                hist[6]=hist[6]+1;
            if((num>=71)&&(num<=80))
                hist[7]=hist[7]+1;
            if((num>=81)&&(num<=90))
                hist[8]=hist[8]+1;
            if((num>=91)&&(num<=100))
                hist[9]=hist[9]+1;
            in>>num;
        }
        else{
            if(num==0){
                zero=zero+1;
                in>>num;
            }
            else{
                invalid=invalid+1;
                out<<num<<endl;
                in>>num;
            }
        }
        }
    in.close();
    out.close();
    i=0;
    cout<<endl;
    cout<<"\t\t\t\t\tInvalid Entries"<<endl;
    in.open("/Users/rexdixon/Desktop/C++ Projects/Sem2_Assignment1/Sem2_Assignment1/invalid.txt");/*Compiler used requires full address of text files used.*/
    if(in.is_open()!=true){
        cout<<"ERROR"<<endl;
        return 0;
    }
    in>>num;
    while(in.eof()==false){
        cout<<num<<"\t";
        in>>num;
        i++;
        if(i%5==0)
            cout<<endl;
    }
    in.close();
    cout<<endl<<endl;
    cout<<"Range\t\tHistograph"<<endl;
    cout<<"================================================="<<endl;
    for(i=0;i<10;i++){
        cout<<range[i]<<"\t\t";
        x=hist[i]/5;
        for(a=0;a<x;a++)
            cout<<"*";
        cout<<endl;
    }
    for(i=0;i<100;i++){
        if(count[i]>highest)
            highest=count[i];}
    cout<<endl;
    cout<<"The number of students who entered valid numbers is "<<valid<<endl<<endl;
    cout<<"The number of students who entered invalid numbers is "<<invalid<<endl<<endl;
    cout<<"The number of students who did not want to reveal their favourite numbers is "<<zero<<endl<<endl;
    cout<<"The numbers that were chosen the most by people were :"<<endl;
    for(i=0;i<100;i++){
        if(count[i]==highest)
            cout<<i+1<<"\t";
    }
    cout<<endl<<endl;
    cout<<"The numbers that were chosen the least by people were :"<<endl;
    for(i=0;i<100;i++){
        if(count[i]==1)
            cout<<i+1<<"\t";
    if((i+1)%10==0)
        cout<<endl;
    }
    return 0;
}
