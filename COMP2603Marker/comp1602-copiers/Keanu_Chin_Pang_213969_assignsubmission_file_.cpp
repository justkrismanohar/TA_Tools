#include <iostream>
#include <fstream>
using namespace std;  

bool isperfect(int a){
    int i;
	int k=0;
    for(i=2;i<a;i++){
        if(a%i==0)
            k=k+i;
    }
    if(k==a)
        return true;
    return false;
}
bool isPrime(int b){
    int i;
    for(i=2;i<b;i++){
        if (b%i==0)
            return false;
    }
    return true;
}
bool  perfectSquare(int c){
    int i;
    for (i=2;i<=50;i++){
        if (c==i*i)
            return true;
            }
    return false;
}
bool Sphenic(int d){
    bool prime;
    int i,count=0,prod=1;
    for(i=2;i<d;i++){
        prime=isPrime(d);
        if(prime==true){
            prod=prod*i;
            count=count+1;
        }
    }
    if((prod==d)&&(count==3))
        return true;
    return false;
}
void Binary(int e){
    int count,bits[8],rem;
    rem=e;
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
    bool sphenic,perfect,prime,square;
    int i,y,x,numbers,valid=0,invalid=0,zero=0;
	int histo[10],count[100];
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
        histo[i]=0;
    for (i=0;i<100;i++)
        count[i]=0;
    ifstream in;
    ofstream out;
    in.open("numbers.txt");
    if(in.is_open()==false){
        cout<<"Error opening input file. Aborting ..."<<endl;
        return 0;
    }
    out.open("invalid.txt");
    in>>numbers;
    cout<<"NUMBER     Perfect?\t\tPrime\t\tPerfect Square\t\t     Sphenic?\t\tBinary Equiv"<<endl;
    cout<<"======\t   ========\t\t=======\t\t==============\t\t    =========\t\t================="<<endl<<endl;
    while(numbers!=-1){
        if((numbers<=100)&&(numbers>=1)){
            valid=valid+1;
            perfect=isperfect(numbers);
            square=perfectSquare(numbers);
            prime=isPrime(numbers);
            sphenic= Sphenic(numbers);
            cout<<numbers<<"\t\t"<<perfect<<"\t\t"<<prime<<"\t\t\t"<<square<<"\t\t\t"<<sphenic<<"\t\t";
            Binary(numbers);
            cout<<endl;
             if((numbers>=1)&&(numbers<=10))
                histo[0]=histo[0]+1;
            if((numbers>=11)&&(numbers<=20))
                histo[1]=histo[1]+1;
            if((numbers>=21)&&(numbers<=30))
                histo[2]=histo[2]+1;
            if((numbers>=31)&&(numbers<=40))
                histo[3]=histo[3]+1;
            if((numbers>=41)&&(numbers<=50))
                histo[4]=histo[4]+1;
            if((numbers>=51)&&(numbers<=60))
                histo[5]=histo[5]+1;
            if((numbers>=61)&&(numbers<=70))
                histo[6]=histo[6]+1;
            if((numbers>=71)&&(numbers<=80))
                histo[7]=histo[7]+1;
            if((numbers>=81)&&(numbers<=90))
                histo[8]=histo[8]+1;
            if((numbers>=91)&&(numbers<=100))
                histo[9]=histo[9]+1;
            for(i=0;i<100;i++){
                if (numbers==i+1)
                    count[i]=count[i]+1;
            }
            
            in>>numbers;
        }
        else{
            if(numbers==0){
                zero=zero+1;
                in>>numbers;
            }
            else{
                invalid=invalid+1;
                out<<numbers<<endl;
                in>>numbers;
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
        cout<<"Error opening input file. Aborting ..."<<endl;
        return 0;
    }
    in>>numbers;
    while(in.eof()==false){
        cout<<numbers<<"\t";
        in>>numbers;
        i++;
        if(i%5==0)
            cout<<endl;
    }
    cout<<endl<<endl;
    cout<<"Range\t\tHistograph"<<endl;
    cout<<"================================================="<<endl;
    for(i=0;i<10;i++){
        cout<<range[i]<<"\t\t";
        x=histo[i]/5;
        for(y=0;y<x;y++)
            cout<<"*";
        cout<<endl;
    }
    cout<<endl;
    cout<<"The amount of students who specified valid favourite numbers: "<<valid<<endl;
    cout<<"The amount of students who specified invalid favourite numbers "<<invalid<<endl;
    cout<<"The number of students who did not want to reveal their favourite numbers is "<<zero<<endl;
    cout<<"The numbers  chosen the most by students were :"<<endl;
    for(i=0;i<100;i++){
        if(count[i]>=2)
            cout<<i+1<<"\t";
    }
    cout<<endl<<endl;
    cout<<"The numbers that were chosen the least by the students were :"<<endl;
    for(i=0;i<100;i++){
        if(count[i]==1)
            cout<<i+1<<"\t";
    }
    
    
    
    
    
    
    return 0;
}


	
