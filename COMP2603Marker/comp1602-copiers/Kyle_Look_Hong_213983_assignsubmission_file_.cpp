#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int arr[100]; // universally declared to be used in the histogram function

bool perfect(int b){
    int sum = 0;
    int a = 0;
    int c = 1; // to start divisor process
    while (c != b){
        a = b % c;
        if (a == 0){
            sum +=c;
        }
    }
    if (b == sum){
        return true;
    }else{
        return false;
    }
} // end of perfect

bool prime(int b){
    int x;
    for (x=2; x<=b/2; x++){
        if (b % x == 0){
            return false;
        }
    }
    return true;
} // end of prime

bool perfectsqr(int b){
    int a = 0;
    a = sqrt(b);
    if (a % 1 == 0){
        return true;
    }else{
        return false;
    }
} // end of perfectsqr

bool sphenic(int b){ // 30, 42, 66, 70, 78
    if (b == 30){
        return true;
    }else if (b == 42){
        return true;
    }else if (b == 66){
        return true;
    }else if (b == 70){
        return true;
    }else if (b == 78){
        return true;
    }else{
        return false;
    }
} // end of sphenic

void binary(int b){
    int arr2[7];
    int c = 0;
    int x = 0;
    for (x=0; x<=7; x++){
        c = c % 2;
        arr2[x] = c;
    }
    for (x=7; x>=0; x--){
        cout << arr2[x];
    }
    cout << endl;
}

void histogram(int a, int b, int c){ // c will be x from main to get size of array
    int x = 0;
    int total = 0;
    int stars = 0;
    int rem = 0; // to round up stars
    for (x=0; x<=c; x++){
        if (arr[x] >= a && arr[x] <= b){
            total += 1;
        }
    }
    stars = total/5;
    rem = total%5;
    if (rem > 0){
        stars += 1;
    }
    cout << a << "-" << b << "\t";
    for (x=0; x<=stars; x++){
        cout << "*";
    }
    cout << endl;
}

int main(){
    int i = 0;
    int invalidarr[100]; // to hold invalid values
    int x = 0; // arr counter for valid
    int z = 0; // in valid array counter
    int y = 0;
    int p = 0; // to display 5 per line
    int n = 0;
    int a = 0;
    int q, r, temp = 0; // for the most and least recurring values
    int secret = 0;
    ifstream in;

    in.open("numbers.txt");
    if (!in.is_open()){
        cout << "Error";
        return 0;
    }

    in >> i;
    while (i != -1){
        if (i <= 100 && i > 0){
            arr[x] = i;
            x++;
        }else if (i == 0){
            secret += 1;
        }else{
            invalidarr[z];
            z++;
        }
        in >> i;
    } // end of reading from file
    in.close();

    cout << "Number\tPerfect\tPrime\tPerfect Square\tSphenic\tBinary Equiv" << endl;

    for (y=0; y<=x; y++){
        if (perfect(arr[y])){
            cout << "Y\t";
        }else{
            cout << "N\t";
        }
        if (prime(arr[y])){
            cout << "Y\t";
        }else{
            cout << "N\t";
        }
        if (perfectsqr(arr[y])){
            cout << "Y\t";
        }else{
            cout << "N\t";
        }
        if (sphenic(arr[y])){
            cout << "Y\t";
        }else{
            cout << "N\t";
        }
        binary(arr[y]);
        cout << "\t" << endl;
        //cout << "hi";
    }

    cout << "Valid Numbers" << endl;
    for (n=0; n<=x; n++){
        cout << arr[n] << endl;
    }
    cout << endl << "Invalid Numbers" << endl;
    for (n=0; n<=z; n++){
        cout << invalidarr[n] << endl;
        if (p > 4){
            cout << endl;
            p = 0;
        }
    }

    cout << "Range\tHistogram" << endl;
    histogram(1, 10, x);
    histogram(11, 20, x);
    histogram(21, 30, x);
    histogram(31, 40, x);
    histogram(41, 50, x);
    histogram(51, 60, x);
    histogram(61, 70, x);
    histogram(71, 80, x);
    histogram(81, 90, x);
    histogram(91, 100, x);

    cout << "Amount of Valid entries: " << x << endl;
    cout << "Amount of Invalid entries: " << z << endl;
    cout << "Amount of students who did not reveal their number: " << secret << endl;

    for (q=1; q<=100; q++){
        temp = 0;
        for (r=0; r<=x; r++){
            if (arr[r] == q){
                temp += 1;
            }
        }
        if (temp > 1){
            cout << q << " was selected " << temp << " times. One of the most chosen numbers." << endl;
        }else if (temp <= 1 && temp > 0){
            cout << q << " was selected " << temp << " times. One of the least chosen numbers." << endl;
        }
    }
}
