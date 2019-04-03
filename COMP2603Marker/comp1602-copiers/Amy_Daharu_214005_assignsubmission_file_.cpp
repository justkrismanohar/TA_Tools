#include<iostream>
#include<fstream>
using namespace std;

bool isPerfect(int num){
    int i,sum;
	sum=0;
    for (i=2; i<num; i++) {
        if (num%i==0)
            sum=sum+i;
    }
    if (sum==num)
     return true;
     return false;
 }
 
 
bool isPrime(int num){
    int i;
    for(i=2; i<num; i++) {
        if (num%i==0)
            return false;
    }
    return true;
}

bool isPerfectsquare(int num){
    int i;
    for (i=2; i<=50; i++) {
        if (num==i*i)
            return true;
            }
    return false;
}


bool isSphenic(int num){
    bool prime;
    int i,count,prod;
	count=0;
	prod=1;
    for(i=2; i<num; i++) {
        prime=isPrime(num);
        if(prime==true) {
            prod= prod*i;
            count= count+1;
        }
    }
    if((prod==num) && (count==3))
        return true;
    return false;
}

void Binary(int num){
    int count, bits[8], rem;
    rem=num;
    for (count=0; count<8; count++)
        bits[count]=0;
    count=7;
    while((rem!=0) && (count>=0)){
        bits[count]= rem%2;
        rem= rem/2;
        count= count-1;
    }
    for(count=0; count<8; count++)
        cout<< bits[count];
}


int main() {
    bool sphenic, perfectsquare, prime, perfect;
    int num, i, x, a,valid=0,invalid=0,zero=0,count[100],hist[10];
    string range[10];
    range[0]= "1-10";
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
    in.open("numbers.txt");
    if(in.is_open()==false){
        cout<<"ERROR"<<endl;
        return 0;
    }
    out.open("invalid.txt");
    in>>num;
	cout<<"Number\tPerfect\tPrime\tPerfect Square\tSphenic\tBinary"<<endl;
    cout<<"======\t=======\t=====\t==============\t=======\t======"<<endl<<endl;
    
    
 while(num!=-1){
        if((num<=100) && (num>=1)){
            valid= valid+1;
            perfect= isPerfect(num);
            perfectsquare= isPerfectsquare(num);
            prime= isPrime(num);
            sphenic= isSphenic(num);
            cout<<num<<"\t\t"<<perfect<<"\t\t"<<prime<<"\t\t\t"<<perfectsquare<<"\t\t\t"<<sphenic<<"\t\t";
            Binary(num);
            cout<<endl;
            if((num>=1) && (num<=10))
                hist[0]=hist[0]+1;
            if((num>=11) && (num<=20))
                hist[1]=hist[1]+1;
            if((num>=21) && (num<=30))
                hist[2]=hist[2]+1;
            if((num>=31) && (num<=40))
                hist[3]=hist[3]+1;
            if((num>=41) && (num<=50))
                hist[4]=hist[4]+1;
            if((num>=51 )&& (num<=60))
                hist[5]=hist[5]+1;
            if((num>=61) && (num<=70))
                hist[6]=hist[6]+1;
            if((num>=71) && (num<=80))
                hist[7]=hist[7]+1;
            if((num>=81) && (num<=90))
                hist[8]=hist[8]+1;
            if((num>=91) && (num<=100))
                hist[9]=hist[9]+1;
            for(i=0; i<100; i++) {
                if (num==i+1)
                    count[i]=count[i]+1;
            }
            
            in>>num;
        }
        else{
            if(num==0){
                zero= zero+1;
                in>>num;
            }
            else{
                invalid= invalid+1;
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
    in.open("invalid.txt");
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
   
    cout<<endl;
    cout<<"Range\t\tHistograph"<<endl;
    cout<<"================================================="<<endl;
    for(i=0;i<10;i++){
        cout<<range[i]<<"\t\t";
        x=hist[i]/5;
        for(a=0 ;a<x; a++)
            cout<<"*";
        cout<<endl;
    }
    
	cout<<endl;
    cout<<"The number of students who specified valid numbers are: "<<valid<<endl;
    cout<<"The number of students who specified invalid numbers are: "<<invalid<<endl;
    cout<<"The number of students who did not reveal their favourite numbers are: "<<zero<<endl;
    cout<<"The numbers that were chosen by the most amount students are :"<<endl;
   
    for(i=0; i<100; i++){
        if(count[i]>=2)
            cout<<i+1<<"\t";
    }
    cout<<endl;
    cout<<"The numbers that were chosen by the least amount of students are :"<<endl;
    for(i=0; i<100; i++){
        if(count[i]==1)
            cout<<i+1<<"\t";
    }

  
    return 0;
}
        























