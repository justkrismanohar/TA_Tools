#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int readFile(int numbers[]){
    int a,amt=0;

    ifstream inputFile;
    inputFile.open("numbers.txt");

    if(!inputFile.is_open()){
        cout<<"Error opening numbers.txt";
        return -1;
    }

    inputFile>>a;

    while(a != -1){
        numbers[amt]= a;
        amt = amt + 1;
        inputFile>>a;
    }
    inputFile.close();

return amt;
}

bool isPerfect(int n){
    int sum=0, i=1;
    while(i<n){
        if(n%i==0)
            sum=sum+i;
            i=i+1;
    }
    if(sum==n)
        return true;
    return false;
}

bool isPrime(int n){

    for(int i=2;i<=n/2;i=i+1){
        if(n%i == 0)
            return true;
    }
    return false;
}

bool isPerfectSquare(int n){

    for(int i=2;i<=n;i=i+1){
        if(n == i * i)
            return true;
    }
    return false;
}

bool isSphenic(int n){
    int i,coun,product;
    coun=0;
    product=1;
    for(i=2;i<=sqrt(n);i=i+1){
        if(n%i==0 && isPrime(i)){
            product = product * i;
            coun = coun + 1;
        }
    }

    if(product==n && coun==3)
        return true;
    return false;

}

void binaryNumber(int n){
    int rem[10],i;

    for(i=0;n>0;i=i+1){
        rem[i]=n%2;
        n=n/2;
    }

    for(i=i-1;i>=0;i=i-1){
            cout<<rem[i];
    }

}

void printStars(int n){
    while(n>=5){
        cout<<"*";
        n=n-5;
    }
}

int main(){
    int numbers[1000];
    int numNumbers;
    numNumbers = readFile(numbers);
    int i;
    int numPerLine = 5, lineCount=0;
    int range1=0,range2=0,range3=0,range4=0,range5=0,range6=0,range7=0,range8=0,range9=0,range10=0;
    int countValid=0,countInvalid=0,countNoReveal=0;

    cout<<"Number"<<"   "<<"Perfect?"<<"    "<<"Prime?"<<"    "<<"Perfect Square"<<"      "<<"Sphenic"<<"     "<<"Binary Equic."<<endl;
    cout<<"======"<<"   "<<"========"<<"    "<<"======"<<"    "<<"=============="<<"      "<<"======="<<"     "<<"============="<<endl<<endl;;


    for(i=0;i<numNumbers;i=i+1){
        if(numbers[i] >0 && numbers[i] <=100){
                countValid = countValid + 1;
            cout<<" "<<numbers[i]<<"          ";

            if(isPerfect(numbers[i]))
                cout<<"Y"<<"        ";
            else
                cout<<"N"<<"        ";

            if(!isPrime(numbers[i]))
                cout<<"Y"<<"            ";
            else
                cout<<"N"<<"            ";

            if(isPerfectSquare(numbers[i]))
                cout<<"Y"<<"                ";
            else
                cout<<"N"<<"                  ";

            if(isSphenic(numbers[i]))
                cout<<"Y"<<"            ";
            else
                cout<<"N"<<"            ";

            binaryNumber(numbers[i]);
            cout<<endl<<endl;

        }


    }
    cout<<endl<<endl;
    cout<<"Invalid numbers, 5 per line"<<endl<<endl;;

        for(i=0;i<numNumbers;i=i+1){
        if(numbers[i] <0 || numbers[i] >100){
                countInvalid = countInvalid + 1;
            cout<<numbers[i]<<" ";
            lineCount = lineCount + 1;
            if(lineCount == numPerLine)
                cout<<endl;
        }

    }

    for(i=0;i<numNumbers;i=i+1){
        if(numbers[i] == 0){
            countNoReveal = countNoReveal + 1;
        }
    }

    for(i=0;i<numNumbers;i=i+1){
        if(numbers[i]>0 && numbers[i]<=10)
            range1= range1 + 1;
        else if(numbers[i]>10 && numbers[i]<=20)
            range2= range2 + 1;
        else if(numbers[i]>20 && numbers[i]<=30)
            range3=range3 + 1;
        else if(numbers[i]>30 && numbers[i]<=40)
            range4=range4 + 1;
        else if(numbers[i]>40 && numbers[i]<=50)
            range5=range5 + 1;
        else if(numbers[i]>50 && numbers[i]<=60)
            range6=range6 + 1;
        else if(numbers[i]>60 && numbers[i]<=70)
            range7=range7 + 1;
        else if(numbers[i]>70 && numbers[i]<=80)
            range8=range8 + 1;
        else if(numbers[i]>80 && numbers[i]<=90)
            range9=range9 + 1;
        else if(numbers[i]>90 && numbers[i]<=100)
            range10=range10 + 1;
    }

    cout<<endl<<endl<<endl;
    cout<<"Range"<<"        "<<"Histogram"<<endl;
    cout<<"=============================="<<endl;
    cout<<"1 - 10"<<"        "<<": ";
    printStars(range1);
    cout<<endl;
    cout<<"11 - 20"<<"       "<<": ";
    printStars(range2);
    cout<<endl;
    cout<<"21 - 30"<<"       "<<": ";
    printStars(range3);
    cout<<endl;
    cout<<"31 - 40"<<"       "<<": ";
    printStars(range4);
    cout<<endl;
    cout<<"41 - 50"<<"       "<<": ";
    printStars(range5);
    cout<<endl;
    cout<<"51 - 60"<<"       "<<": ";
    printStars(range6);
    cout<<endl;
    cout<<"61 - 70"<<"       "<<": ";
    printStars(range7);
    cout<<endl;
    cout<<"71 - 80"<<"       "<<": ";
    printStars(range8);
    cout<<endl;
    cout<<"81 - 90"<<"       "<<": ";
    printStars(range9);
    cout<<endl;
    cout<<"91 - 100"<<"      "<<": ";
    printStars(range10);
    cout<<endl;
    cout<<endl;

    cout<<"Number of students with valid fav nums: "<<countValid<<endl<<endl;;
    cout<<"Number of students with invalid fav nums: "<<countInvalid<<endl<<endl;
    cout<<"Number of students who did not reveal fav nums: "<<countNoReveal<<endl<<endl;


    }






