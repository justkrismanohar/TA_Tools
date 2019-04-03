#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


void histo(int low, int high,int arr[]){
    float count=0;
    for(int i=low; i <= high; i++){
        count=count+arr[i-1];

    }
    count=count/5;
    while(count>1){
        cout<<"*";
        count=count-1;
    }
    cout<<endl;
}

bool perfectSquare(int n){
    bool flag = false;

    for (int i = 1; i <=n/2; i++){ 
        if(n%i == i)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool isPrime(int n)
{
  bool flag = false;
  
  for(int i = 2; i <= n/2; i++){
      if(n%i == 0)
      {
          flag = true;
          break;
      }
  }
  return flag;
}

bool isPerfect(int n){ 
    bool flag = false;
    int product=1;
    for(int i = 1; i<n; i++){       
        if(n%i){
            product=product*i;
        }
    }
    if(product==n)
    flag = true;
    return flag;
}

bool sphenic(int n){
    bool flag = false;
    int temp = n;
    for (int i = 2; i<=n/2; i++){
        if(n%i == 0 && isPrime(i)==true){ 
            n=n/i;
            for (int j = i+1; j<=n;j++){
                if(n%j == 0 && isPrime(j) == true){
                    n=n/j;
                    for(int k = j+1; k<=n;k++){
                        if(n%k == 0 && isPrime(k) == true){
                            flag = true;
                            return flag;
                        }
                    }
                }
            }
        }
    n= temp;
    }
    return flag;
}

void binary(int n){
    int a[10], i;
    for(i=0; n>0; i++)    
{    
a[i]=n%2;    
n= n/2;  
}    
for(i=i-1 ;i>=0 ;i--)    
{    
cout<<a[i];    
}    

}

int main()
{
ifstream in;
int n, invalidCount=0,validCount=0, noNum=0;
int arr[100]={0};
int invalidArr[100]={0};


in.open("numbers.txt");

if (!in.is_open()){       //checking if file open

    cout<<"Error in opening file";
    return 0;
 } 



cout<<"Number\tPerfect? Prime?\tPerfect square?\tSphenic\tBinary Equiv."<<endl;
cout<<"======================================================================="<<endl;
in>>n;
while(n!=-1){
    if(n==0){
        noNum++;
    }
    else
    if(n>0 && n<=100){
        arr[n]++;
        cout<<n<<"\t";
        if(isPerfect(n)){
            cout<<"Y\t";
        }
        else
        cout<<"N\t";
        if(isPrime(n))
        cout<<"Y\t";
        else
        cout<<"N\t";
        if(perfectSquare(n))
        cout<<"Y\t\t";
        else
        cout<<"N\t\t";
        if(sphenic(n))
        cout<<"Y\t";
        else
        cout<<"N\t";
        binary(n);
        cout<<endl;
        validCount++;
    }
    else{
        invalidArr[invalidCount]=n;
        invalidCount++;
    }
in>>n;

}
cout<<endl;
cout<<"Invalid Numbers:"<<endl;             //invalid print
for(int i = 1; i <= invalidCount; i++){
    cout<<invalidArr[i-1]<<" ";
    if(i%5 == 0)
    cout<<endl;
}
cout<<endl<<endl;

cout<<"Range\tHistogram"<<endl;
cout<<"============================"<<endl;
cout<<"1-10\t|";
histo(1, 10, arr);

cout<<"11-20\t|";
histo(11, 20, arr);

cout<<"21-30\t|";
histo(21,30,arr);

cout<<"31-40\t|";
histo(31,40,arr);

cout<<"41-50\t|";
histo(41,50,arr);

cout<<"51-60\t|";
histo(51,60,arr);

cout<<"61-70\t|";
histo(61,70,arr);

cout<<"71-80\t|";
histo(71,80,arr);

cout<<"81-90\t|";
histo(81,90,arr);

cout<<"91-100\t|";
histo(91,100,arr);
cout<<endl;
                        //end of histogram

cout<<"Amount of students that specifed \na valid favourite number: "
<<validCount<<endl;
cout<<"Amount of students that specified \nan invalid favourite number: "
<<invalidCount<<endl;
cout<<"Amount of students that did not \nreveal their favourite number: "
<<noNum<<endl<<endl;
int high=0;
int low=999999999;
for(int i = 0; i < 100; i++){
 if(arr[i]>1 && arr[i]>high){
     high=arr[i];
 }
 if(arr[i]>0 && arr[i]<low){
     low=arr[i];
 }
}

cout<<"number/s chosen by the most students: ";
for(int i = 0; i < 100; i++){
    if(arr[i]==high){
        cout<<i<<" ";
    }
}
cout<<endl;

cout<<"Number/s chosen by the least students: ";
for( int i = 0; i < 100; i++){
    if(arr[i]==low){
        cout<<i<<" ";
    }
}




return 0;
}

