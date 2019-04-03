#include <iostream>
#include <fstream>
using namespace std;

bool isPerfect(int x){
    int sum=0;
    int i;

    for(i=1; i<=x/2; i++){
        if(x%i==0){
            sum+=i;
        }
    }
    if(sum==x){
        return true;
    }
    else{
        return false;
    }
}

bool isPrime(int x){
    bool prime=true;
    int i;

    if(x==1){
        return false;
    }

    for(i=2; i<=x/2; i++){
        if(x%i==0){
            prime=false;
        }
    }
    if(prime==true){
        return true;
    }
    else{
        return false;
    }
}

bool isPsquare(int x){
    bool result= false;
    int i;

    if(x==1){
        return true;
    }

    for(i=1; i<=x/2; i++){
        if((i*i)==x){
            result=true;
        }
    }
    if(result==true){
        return true;
    }
    else{
        return false;
    }
}

bool isSphenic(int x){
    int i;
    int times=0;
    int product=1;
    bool result=false;

    for(i=2;i<x;i++){
        if(x%i==0&&isPrime(i)){
            product=product*i;
            times++;
            }
        }

    if(times==3&&product==x){
        return true;
    }
    else{
        return false;
    }
}

void binaryConvert(int x){
    int arr[8]={0,0,0,0,0,0,0,0};
    int remainder;
    int temp=x;
    int i;

    for(i=0;temp>0;i++){
            arr[i]=temp%2;
            temp=temp/2;
    }
    for(i=7;i>=0;i--){
        cout<<arr[i];
    }
}

int main(){
    int temp=1;
    int numbers[100];
    int hide=0;
    int valid=0;
    int invalid=0;
    int highNumber, lowNumber;
    int high=-1;
    int low=999;
    int i;
    int distinct[100];

    for(i=0;i<=99;i++){
        numbers[i]=0;
        distinct[i]=0;
    }

    ifstream inFile;
    inFile.open("numbers.txt");

    if(!inFile.is_open()){
        cout<<"'numbers.txt' cannot be opened.";
        return 0;
    }

    cout<<"Number"<<'\t'<<"Perfect?"<<'\t'<<"Prime"<<'\t'<<"Perfect Square?"<<'\t'<<'\t'<<"Sphenic?"<<'\t'<<"Binary Equiv."<<endl;
    cout<<"======"<<'\t'<<"========"<<'\t'<<"====="<<'\t'<<"==============="<<'\t'<<'\t'<<"========"<<'\t'<<"============="<<endl;

    inFile>>temp;
    while(!inFile.eof()&&temp!=-1){
        if(temp>0&&temp<101){

            valid++;
            numbers[temp-1]++;

            if(distinct[temp-1]<1){
                cout<<temp<<'\t';

                if(isPerfect(temp)){
                    cout<<"Y"<<'\t'<<'\t';
                }
                else{
                    cout<<"N"<<'\t'<<'\t';
                }

                if(isPrime(temp)){
                    cout<<"Y"<<'\t';
                }
                else{
                    cout<<"N"<<'\t';
                }

                if(isPsquare(temp)){
                    cout<<"Y"<<'\t'<<'\t'<<'\t';
                }
                else{
                    cout<<"N"<<'\t'<<'\t'<<'\t';
                }

                if(isSphenic(temp)){
                    cout<<"Y"<<'\t'<<'\t';
                }
                else{
                    cout<<"N"<<'\t'<<'\t';
                }

                binaryConvert(temp);
                cout<<endl;

                distinct[temp-1]++;
            }

        }
        else if(temp==0){
            hide++;
        }
        else if(temp<0||temp>100){
            invalid++;
        }
        inFile>>temp;
    }

    ifstream in;
    in.open("numbers.txt");

    if(!in.is_open()){
        cout<<"'numbers.txt' cannot be opened.";
        return 0;
    }
    in>>temp;
    i=0;

    cout<<endl;

    cout<<"List of invalid numbers: "<<endl;
    while(!in.eof()&&temp!=-1){
        if((temp<1||temp>100)&&temp!=0){
            cout<<temp<<'\t';
            i++;
            if(i%5==0){
                cout<<endl;
            }
        }
        in>>temp;
    }

    in.close();
    ifstream input;
    input.open("numbers.txt");

    if(!input.is_open()){
        cout<<"'numbers.txt' cannot be opened.";
        return 0;
    }

    int arr[10]={0,0,0,0,0,0,0,0,0,0};
    input>>temp;
    while(!input.eof()&&temp!=-1){
        if(temp>=1&&temp<=10){
            arr[0]++;
        }
        if(temp>=11&&temp<=20){
            arr[1]++;
        }
        if(temp>=21&&temp<=30){
            arr[2]++;
        }
        if(temp>=31&&temp<=40){
            arr[3]++;
        }
        if(temp>=41&&temp<=50){
            arr[4]++;
        }
        if(temp>=51&&temp<=60){
            arr[5]++;
        }
        if(temp>=61&&temp<=70){
            arr[6]++;
        }
        if(temp>=71&&temp<=80){
            arr[7]++;
        }
        if(temp>=81&&temp<=90){
            arr[8]++;
        }
        if(temp>=91&&temp<=100){
            arr[9]++;
        }
        input>>temp;
    }
    cout<<endl<<endl;

    int bot=1;
    int top=10;
    int x;

    cout<<"Range"<<'\t'<<"Histogram"<<endl;
    cout<<"================="<<endl;
    for(i=0;i<=9;i++){
        temp=arr[i];
        cout<<bot<<"-"<<top<<'\t'<<"[";
        for(x=0;temp>=5;x++){
            cout<<"*";
            temp-=5;
        }
        cout<<endl;
        bot=bot+10;
        top=top+10;
    }

    cout<<endl;
    cout<<"Number of valid responses: "<<valid<<endl;
    cout<<"Number of invalid responses: "<<invalid<<endl;
    cout<<"Number of hidden responses: "<<hide<<endl;

    for(i=0;i<=99;i++){
        temp=numbers[i];
        if(temp>high&&temp>=2){
            high=temp;
        }
        if(temp<low&&temp>=1){
            low=temp;
        }
    }
    cout<<endl<<"Most selected numbers: ";
    for(i=0;i<=99;i++){
        temp=numbers[i];
        if(temp==high){
            cout<<i+1<<" ";
        }
    }
    cout<<endl<<endl;

    cout<<"Least selected numbers: ";
    for(i=0;i<=99;i++){
        temp=numbers[i];
        if(temp==low){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;

    in.close();
    input.close();
    inFile.close();

    return 0;
}
