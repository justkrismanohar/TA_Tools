//
//  811001486.cpp
//  Assignment 1 - Answer
//
//  Created by Orrin Joseph on 27/01/2019.
//  Copyright © 2019 Orrin Joseph. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

string isPerfect (int num) {
    int divisors [50];
    int a = 1, count = 0, sum = 0, b = 0;
    
    for (a = 1; a <= num/2; a++) {
        if (num % a == 0) {
            divisors [count] = a;
            count++;
        }
    }
    for (b = 0; b < count; b++) {
        sum = sum + divisors [b];
    }
    
    if (sum == num)
        return "Y";
    else return "N";
}

string isPrime (int num) {
    int a = 2;
    
    if (num == 1)
        return "N";
    else {
    for (a = 2; a <= num/2; a++) {
        if (num % a == 0)
            return "N";
    }
    
    return "Y";
    }
}

string isSquare (int num) {
    int a = 1;
    
    if (num == 1)
        return "Y";
    else {
    for (a = 1; a <= num/2; a++) {
        if ((num % a == 0) && (a * a == num))
            return "Y";
    }
    return "N";
    }
}

string isSphenic (int num) {
    int primedivisors [50];
    int a = 2, b = 0, prod = 1, count = 0, count3 = 0;
    string prime;
    
    for (a = 2; a <= num/2; a++) {
        prime = isPrime(a);
        
        if (prime == "Y" && num % a == 0) {
            primedivisors [count] = a;
            count++;
        }
    }
    
    for (a = 0; a < count; a++) {
        for (b = 0; b < a; b++)
            if (primedivisors [a] == primedivisors [b])
                break;
        if (a == b) {
        prod = prod * primedivisors [a];
            count3++;
        }
        if (count3 == 3 && prod == num)
            return "Y";
        if (count3 > 3)
            break;
    }
    return "N";
}

void Equiv (int num) {
    int binary [8], digit = 0, count = 0, a = 7;
    
    for (count = 0; count < 8; count++) {
        binary [count] = 0;
    }
    
    while (num != 0) {
        digit = num % 2;
        binary [a] = digit;
        a--;
        num = num / 2;
    }
    
    for (a = 0; a < count; a++) {
        cout << binary [a];
    }
}

void drawStars (int num) {
    int i = 1;
    
    for (i = 1; i <= num; i++)
        cout << "*";
}


int main() {
    
    ifstream in;
    
    in.open("numbers.txt");
    
    if (!in.is_open()) {
        cout << "Error opening file!";
        return 0;
    }
    
    int valid [500];
    int invalid [500];
    int distinct [100];
    int frequency [10];
    int num, i = 0, j = 0, k = 0;
    int count_valid = 0, count_invalid = 0, count_hidden = 0;
    
    in >> num;
    while (num != -1) {
        if (num >= 1 && num <= 100) {
            valid [count_valid] = num;
            count_valid++;
        }
        if (num < 0 || num > 100) {
            invalid [count_invalid] = num;
            count_invalid++;
        }
        if (num == 0) {
            count_hidden++;
        }
        
        in >> num;
    }
    
    
    for (i = 0; i < count_valid; i++) {
        for (j = 0; j < i; j++)
            if (valid [i] == valid [j])
                break;
            if (i == j) {
            distinct [k] = valid [i];
            k++;
            }
    }
    
    string perfect, prime, square, sphenic;
    
    cout << "Number" << "\t\t" << "Perfect?" << "\t" << "Prime?" << "\t\t" << "Perfect Square?" << "\t\t" << "Sphenic?" << "\t\t" << "Binary Equivalent" << endl;
    cout << "======" << "\t\t" << "========" << "\t" << "======" << "\t\t" << "===============" << "\t\t" << "========" << "\t\t" << "=================";
    
    cout << endl << endl;
    
    for (i = 0; i < k; i++) {
        perfect = isPerfect(distinct [i]);
        prime = isPrime(distinct [i]);
        square = isSquare(distinct [i]);
        sphenic = isSphenic(distinct [i]);
        cout << distinct [i] << "\t\t\t\t" << perfect << "\t\t\t" << prime << "\t\t\t\t" << square << "\t\t\t\t" << sphenic << "\t\t\t\t";
        Equiv(distinct[i]);
        cout << endl;
    }
    
    cout << endl << endl;
    
    cout << "Invalid Numbers used as favourite:" << endl;
    for (i = 0; i < count_invalid; i++) {
        cout << invalid [i] << " ";
        
        if ((i + 1) % 5 == 0)
            cout << endl;
    }
    
    cout << endl << endl << endl;
    
    for (i = 0; i < 10; i++) {
        frequency [i] = 0;
    }
    
    for (i = 0; i < count_valid; i++) {
        if (valid [i] >= 1 && valid [i] <= 10)
            frequency [0]++;
        if (valid [i] >= 11 && valid [i] <= 20)
            frequency [1]++;
        if (valid [i] >= 21 && valid [i] <= 30)
            frequency [2]++;
        if (valid [i] >= 31 && valid [i] <= 40)
            frequency [3]++;
        if (valid [i] >= 41 && valid [i] <= 50)
            frequency [4]++;
        if (valid [i] >= 51 && valid [i] <= 60)
            frequency [5]++;
        if (valid [i] >= 61 && valid [i] <= 70)
            frequency [6]++;
        if (valid [i] >= 71 && valid [i] <= 80)
            frequency [7]++;
        if (valid [i] >= 81 && valid [i] <= 90)
            frequency [8]++;
        if (valid [i] >= 91 && valid [i] <= 100)
            frequency [9]++;
    }
    
    int range1 = 1, range2 = 10, numstars = 0;
    
    cout << "Range" << "\t\t\t" << "Histogram" << endl;
    cout << "=====" << "\t\t\t" << "=========" << endl << endl;
    for (i = 0; i < 10; i++) {
        numstars = frequency [i] / 5;
        cout << range1 << "-" << range2 << "\t\t\t";
        drawStars(numstars);
        cout << endl;
        
        range1+=10;
        range2+=10;
    }
    
    cout << endl << endl;
    cout << "Other statistical information:" << endl;
    cout << "1. Number of students who specified valid favourite numbers: " << count_valid << endl;
    cout << "2. Number of students who specified invalid favourite numbers: " << count_invalid << endl;
    cout << "3. Number of students who hid their favourite number: " << count_hidden << endl;
    
    int mostchosen_valid = -1, leastchosen_valid = 1000, mostchosen_invalid = -1, leastchosen_invalid = 1000;
    
    for (i = 0; i < count_valid; i++) {
        int appearance = 1;
        for (j = i + 1; j < count_valid; j++) {
            if (valid [i] == valid [j])
                appearance++;
        }
        if (appearance > mostchosen_valid)
            mostchosen_valid = appearance;
        if (appearance < leastchosen_valid)
            leastchosen_valid = appearance;
    }
    
    for (i= 0; i < count_valid; i++) {
        int appearance = 1;
        for (j = i + 1; j < count_valid; j++) {
            if (valid [i] == valid [j])
                appearance++;
        }
        if (appearance == mostchosen_valid)
            mostchosen_valid = valid [i];
        if (appearance == leastchosen_valid)
            leastchosen_valid = valid [i];
    }
    
    for (i = 0; i < count_invalid; i++) {
        int appearance = 1;
        for (j = i + 1; j < count_invalid; j++) {
            if (invalid [i] == invalid [j])
                appearance++;
        }
        if (appearance > mostchosen_invalid)
            mostchosen_invalid = appearance;
        if (appearance < leastchosen_invalid)
            leastchosen_invalid = appearance;
    }
    
    for (i= 0; i < count_invalid; i++) {
        int appearance = 1;
        for (j = i + 1; j < count_invalid; j++) {
            if (invalid [i] == invalid [j])
                appearance++;
        }
        if (appearance == mostchosen_invalid)
            mostchosen_invalid = invalid [i];
        if (appearance == leastchosen_invalid)
            leastchosen_invalid = invalid [i];
    }
    
    cout << "4. Number most chosen by students that was valid: " << mostchosen_valid << endl;
    cout << "5. Number least chosen by students that was valid: " << leastchosen_valid << endl;
    cout << "6. Number most chosen by students that was invalid: " << mostchosen_invalid << endl;
    cout << "7. Number least chosen by students that was invalid: " << leastchosen_invalid << endl;
    cout << endl;
    
    in.close();
    
    return 0;
}
