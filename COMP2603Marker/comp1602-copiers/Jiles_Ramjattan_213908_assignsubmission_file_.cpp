//Jiles Tony Ramjattan
//816008647
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void historgram(int time[200]);
bool perfectnum(int num);
bool PerfectSquare(int n);
bool Sphenic(int n);
void Binary(int n);
bool Prime(int num);


int main(){
 
    ifstream in;
    in.open("numbers.txt");
    ofstream out;
    int num_arr[200];
    int time[200];

	if(!in.is_open()){
		cout<<"error opening file";
	
		return 0;

	}
    
	
	for(int i=0;i<200;i++){
        num_arr[i]=i;
        time[i]=0;
    }

    int invalidnum=0;
    int students=0;
    int hidden=0;
    int validnum=0;
    int invalid_locs=100;
    int number;

    in >> number;
    while(number!=-1){
            students++;
        if((number>=0) && (number <=100)){
            time[number]=time[number]+1;
            if(number!=0)
                validnum++;
            if(number==0)
                hidden++;
        }
        else {
            invalidnum++;
            invalid_locs++;
            num_arr[invalid_locs]=number;
            time[invalid_locs]=1;

    }
    in >> number;
    }
    in.close();
    cout << "Number Perfect?       Prime?\t  PerfectSquare?     Sphenic?\t        Binary" << endl;
    for(int j=1;j<=100;j++){
            if(time[j]>0){
                cout <<num_arr[j];
                if(perfectnum(num_arr[j])==true)
                    cout << "  \tY";
                else cout << "  \tN";
                if(Prime(num_arr[j])==true)
                    cout << "     \t\tY";
                else cout << "     \t\tN";
                if(PerfectSquare(num_arr[j])==true)
                    cout << "\t\tY";
                else cout << "\t\tN";
                if(Sphenic(num_arr[j])==true)
                    cout << "\t\tY\t\t";
                else cout << "\t\tN\t\t";
                int number=j;
                Binary(number);
            }
        }



    cout << endl << "Invalid inputs:"<< endl;
    int breaker=-1;
    for(int j=101;j<=invalid_locs;j++){
            breaker++;
        if(breaker==5){
            cout << endl;
            breaker=0;
            }
        cout << num_arr[j] << " ";

    }
    historgram(time);
    cout << "Students who chose valid numbers: "<< validnum << endl<<endl;
    cout << "Students who chose invalid numbers: " << invalidnum << endl<<endl;
    cout << "Students who did not reveal their favorite number: " << hidden <<endl<< endl;
    cout << "The numbers chosen the most by students: " << endl<<endl;
    for(int n=1;n<=100;n++){
        if(time[n]>=2){
            cout << num_arr[n] << " ";
        }
    }
    cout << endl << endl<< "Numbers chosen the least by students: " << endl<< endl;
    for(int y=1;y<=100;y++){
        if(time[y]==1){
            cout << num_arr[y] << " ";
        }
    }
}

bool Sphenic(int number){
    for(int i=2;i<=200;i++){
        if(Prime(i)==true){
            if(number%i==0){
                for(int z=2;z<=200;z++){
                    if(Prime(z)==true){
                        if(number/i%z==0 && z!=i){
                            int close=(number/i)/z;
                            if(Prime(close)==true)
                                return true;
                        }
                    }

                }
            }
        }
    }
    return false;
}

bool perfectnum(int num){
    int div;
    int sum=0;
    for (int i=1;i<num;i++){
        div=num%i;
        if(div==0)
            sum=sum+i;
    }
    if (sum==num)
        return true;
    return false;
}

bool Prime(int number){
  bool Prime = true;

  for(int i=2;i<=number/2;i++){
      if(number%i==0){
          return false;
      }
  }
  return true;
}

void Binary(int number){
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

bool PerfectSquare(int number){
    int square=1;
    int counter=1;
    for(int i=1; i<=number; i++){
        square = i*i;
		 if(square==number)
            return true;
     }
           return false;
}

void historgram(int time[200]){
    cout << endl << "Range\t\tHistogram" << endl;
    cout << "==========================="<< endl;
    for(int i=1;i<=100;i=i+10){
        int sum=0;
        cout << i << "-" << i+9 << "\t\t|";
        for(int y=i;y<=i+9;y++){
            sum=sum+time[y];
        }
        int stars=sum/5;
        for(int x=0;x<stars;x++)
            cout << "*";
        cout << endl;
        }
}
