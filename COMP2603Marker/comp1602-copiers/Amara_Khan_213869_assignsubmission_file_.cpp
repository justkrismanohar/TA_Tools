#include <iostream>//AMARA KHAN
#include<fstream>

using namespace std;
struct numbers{
    int number;
    int times;
};
bool perfect(int num){
    int i;
    int div;
    int sum=0;
    for (i=1;i<num;i++){
        div=num%i;
        if(div==0)
            sum=sum+i;
    }
    if (sum==num)
        return true;
    else return false;

}
bool isPrime(int num){
  bool isPrime = true;

  for(int i=2;i<=num/2;i++){
      if(num%i==0){
          return false;
      }
  }
  return true;
}
bool perfectSquare(int n){
    int sqr=1;
    int counter=1;
    for(int i=1; i<=n; i++){
        sqr = i*i;
		 if(sqr==n)
            return true;
     }
           return false;
}
bool isSphenic(int n){
    for(int i=2;i<=200;i++){
        if(isPrime(i)==true){
            if(n%i==0){
                //int first=i;
                for(int j=2;j<=200;j++){
                    if(isPrime(j)==true){
                        if(n/i%j==0 && j!=i){
                           // int second=j
                            int close=(n/i)/j;
                            if(isPrime(close)==true && close!=i && close!=j)
                                return true;
                        }
                    }

                }
            }
        }
    }
    return false;
}
void toBinary(int n){
    int a[10], x;
    int counter=0;
    for(x=0; n>0; x++){
        a[x]=n%2;
        counter++;
        n= n/2;
    }
    for(int y=0;y<8-counter;y++)
        cout << "0";
    for(x=x-1 ;x>=0 ;x--){
            cout<<a[x];
        }
}
int main(){
    ifstream fin;
    ofstream fout;
    fin.open("num.txt");

    numbers arr[200];
    for(int i=0;i<200;i++){
        arr[i].number=i;
        arr[i].times=0;
        //cout << arr[i].number;
    }
    int invalids=0;
    int total=0;
    int notrevealed=0;
    int valid=0;
    int z=101;
    int number;
    fin >> number;
    while(number!=-1){
            total++;
        if(number>=0 && number <=100){
            arr[number].times=arr[number].times+1;
        //endif
            if(number==0)
                notrevealed++;
            if(number!=0)
                valid++;
        }
        else {
            invalids++;
            z++;
            arr[z].number=number;
            arr[z].times=1;

    }
    fin >> number;
    }
    cout << "Number Perfect?       Prime?\t  PerfectSquare?     Sphenic?\t   Binary Equivalent" << endl;
    for(int j=1;j<=100;j++){
            if(arr[j].times>0){
                cout << arr[j].number;
                if(perfect(arr[j].number)==true)
                    cout << "  \tY";
                else cout << "  \tN";
                if(isPrime(arr[j].number)==true)
                    cout << "     \t\tY";
                else cout << "     \t\tN";
                if(perfectSquare(arr[j].number)==true)
                    cout << "\t\tY";
                else cout << "\t\tN";
                if(isSphenic(arr[j].number)==true)
                    cout << "\t\tY\t\t";
                else cout << "\t\tN\t\t";
                int n=j;
                toBinary(n);

                    cout << endl;
            }
        }



    cout << endl << "Invalid inputs were :";
    int count=-1;
    for(int j=101;j<=z;j++){
            count++;
        if(count==5){
            cout << endl << "                     ";
            count=0;
            }
        cout << arr[j].number << " ";

    }
    cout << "in that order " << endl;

 cout << endl << "Range\t\tHistogram" << endl;
    cout << "==========================="<< endl;
    for(int i=1;i<=100;i+=10){
        int sum=0;
        cout << i << "-" << i+9 << "\t\t|";
        for(int x=i;x<=i+9;x++){
            sum=sum+arr[x].times;
        }
        int stars=sum/5;
        for(int k=0;k<stars;k++)
            cout << "*";
        cout << endl;
        }
        //e
        cout << "Students who chose valid numbers: "<< valid << endl;
        cout << "Students who chose invalid numbers: " << z-100 << endl;
        cout << "Students who did not reveal their favorite number: " << notrevealed << endl;
        cout << "The numbers that was chosen the most by students: " << endl;
        int count2=0;
        for(int c=1;c<=100;c++){
            if(arr[c].times>=2){
                count2++;
                cout << arr[c].number << "\t\t ";
                if(count2==5){
                    cout << endl;
                    count2=0;
                }
            }
        }
        count2=0;
        cout << endl << endl<< "The numbers that was chosen the least by students: " << endl;
        for(int c=1;c<=100;c++){
            if(arr[c].times==1){
                count2++;
                cout << arr[c].number << "\t\t ";
                if(count2==5){
                    cout << endl;
                    count2=0;
                }
            }
        }
}


