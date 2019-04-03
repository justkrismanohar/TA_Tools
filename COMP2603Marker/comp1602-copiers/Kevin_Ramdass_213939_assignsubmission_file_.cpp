#include <iostream>
#include<fstream>
using namespace std;

void historgram(int timesarr[200]);
bool isPerfect(int num);
bool isPrime(int num);
bool ispSquare(int n);
bool isSphenic(int n);
void binary(int n);
int main(){
    ifstream in;
    ofstream out;
    in.open("numbers.txt");
    int numbersarr[200];
    int timesarr[200];
    int invalids=0;
    int students=0;
    int hidden=0;
    int valid=0;
    int invalidlocs=100;
    int number;
    for(int i=0;i<200;i++){
        numbersarr[i]=i;
        timesarr[i]=0;
    }
    in >> number;
    while(number!=-1){
            students++;
        if(number>=0 && number <=100){
            timesarr[number]=timesarr[number]+1;
            if(number!=0)
                valid++;
            if(number==0)
                hidden++;
        }
        else {
            invalids++;
            invalidlocs++;
            numbersarr[invalidlocs]=number;
            timesarr[invalidlocs]=1;

    }
    in >> number;
    }
    in.close();
    cout << "Number Perfect?       Prime?\t  PerfectSquare?     Sphenic?\t        Binary Equiv." << endl;
    cout << "====== ========       ======      ==============     ========           ============="<<endl;
	for(int j=1;j<=100;j++){
            if(timesarr[j]>0){
                cout <<numbersarr[j];
                if(isPerfect(numbersarr[j]))
                    cout << "  \tY";
                else cout << "  \tN";
                if(isPrime(numbersarr[j]))
                    cout << "     \t\tY";
                else cout << "     \t\tN";
                if(ispSquare(numbersarr[j]))
                    cout << "\t\tY";
                else cout << "\t\tN";
                if(isSphenic(numbersarr[j]))
                    cout << "\t\tY\t\t";
                else cout << "\t\tN\t\t";
                int number=j;
                binary(number);
                
            }

        }
    cout << endl << "Invalid inputs:"<< endl;
    int breaker=-1;
    for(int j=101;j<=invalidlocs;j++){
            breaker++;
        if(breaker==5){
            cout << endl;
            breaker=0;
            }
        cout << numbersarr[j] << " ";
    }
    cout << endl << "=========================="<< endl;
    historgram(timesarr);
    cout << "=========================="<< endl;
    cout << valid << " students chose valid numbers"<< endl;
    cout << invalids<< " students chose invalid numbers " << endl;
    cout << hidden << " students did not reveal their favorite number"<< endl;
    cout << "The numbers chosen the most by students: " << endl;
    for(int n=1;n<=100;n++){
        if(timesarr[n]>=2){
            cout << numbersarr[n] << " ";
        }
    }
    cout << endl << endl<< "Numbers chosen the least by students: " << endl;
    for(int y=1;y<=100;y++){
        if(timesarr[y]==1){
            cout << numbersarr[y] << " ";
        }
    }
}
bool isPerfect(int number){
    int div,sum=0;
    for (int i=1;i<number;i++){
        div=number%i;
        if(div==0)
            sum=sum+i;
    }
    if (sum==number)
        return true;
    return false;

}
bool isPrime(int number){
  bool isPrime = true;
  for(int i=2;i<=number/2;i++){
      if(number%i==0){
          return false;
      }
  }
  return true;
}
bool ispSquare(int number){
    int square=1;
    int counter=1;
    for(int i=1; i<=number; i++){
        square = i*i;
		 if(square==number)
            return true;
     }
           return false;
}
bool isSphenic(int number){
    for(int i=2;i<=200;i++){
        if(isPrime(i)==true){
            if(number%i==0){
                for(int z=2;z<=200;z++){
                    if(isPrime(z)==true){
                        if(number/i%z==0 && z!=i){
                            int close=(number/i)/z;
                            if(isPrime(close)==true)
                                return true;
                        }
                    }

                }
            }
        }
    }
    return false;
}
void binary(int number){
    int bin[10];
    int nonzeros=0;
    for(int i=0; number>0; i++){
        bin[i]=number%2;
        nonzeros++;
        number= number/2;
    }
    for(int j=0;j<8-nonzeros;j++)
        cout << "0";
    for(int i=nonzeros-1 ;i>=0 ;i--){
            cout<<bin[i];
        }
        cout << endl;
}
void historgram(int timesarr[200]){
    cout << endl << "Range\t\tHistogram" << endl;
    cout << "==========================="<< endl;
    for(int i=1;i<=100;i=i+10){
        int sum=0;
        cout << i << "-" << i+9 << "\t\t|";
        for(int y=i;y<=i+9;y++){
            sum=sum+timesarr[y];
        }
        int stars=sum/5;
        for(int x=0;x<stars;x++)
            cout << "*";
        cout << endl;
        }
}
