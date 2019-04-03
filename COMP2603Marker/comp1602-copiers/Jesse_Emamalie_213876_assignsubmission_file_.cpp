//  main.cpp
//  Created by Jesse Emamalie
// 816015551

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool perf_sum(int num) {
    int sum = 0;
    for (int i=1; i < num; i++) {
        if (num % i == 0) {
            sum+=i;
        }
    }
    if (num == sum) {
        return true;
    }
    return false;
}

bool prime_num(int num) {
    int sum = 0;
    for (int i=1; i <= num; i++) {
        if (num % i == 0) {
            sum+=i;
        }
    }
    
    if ((sum-1) == num) {
        return true;
    }
    
    return false;
}

bool perfect_square(int num) {
    for (int i = 1; i <= num; i++) {
        if ((i*i) == num) {
            return true;
        }
    }
    return false;
}

bool sphenic(int num) {
    int product = 1, t_factors = 0;
    for (int i = 1; i < num; i++) {
        if (prime_num(i) && (num % i == 0)) {
            product *= i;
            t_factors++;
        }
    }
    
    if ((product == num) && (t_factors == 3)) {
        return true;
    }
    return false;
}

void binary(int num) {
    int bits[8], sum = num;
    for (int i = 0; i < 8; i++) {
        bits[i] = sum % 2;
        sum = sum / 2;
    }
    cout << "\t\tBinary: " << bits[7] << bits[6] << bits[5] << bits[4] << bits[3] << bits[2] << bits[1] << bits[0] << endl;
}

int main() {
    ifstream numbers_file;
    int num, cat[10], fav_nums, no_reveal_nums = 0, invalid_nums = 0;
    numbers_file.open("/Users/razoredge451/Desktop/assignment1s2/assignment1s2/numbers.txt");
    numbers_file >> num;
    
    cout << "Number" << "\tPerfect?" << "\tPrime?" << "\tPerfect Square?" << "\tSphenic?" << "\tBinary Equiv." << endl;
    
    cout << "======" << "\t========" << "\t======" << "\t===============" << "\t========" << "\t=============" << endl;
    
    while (num != -1) {
        if (num >= 1 && num <= 100) {
            fav_nums++;
            
            cout << num << "\t";
        
            if (perf_sum(num)) {
                cout <<"\tY\t";
            }
            else {
                cout <<"\tN\t";
            }
        
            if (prime_num(num)) {
                cout <<"\t\tY\t";
            }
            else {
                cout <<"\t\tN\t";
            }
        
            if (perfect_square(num)) {
                cout <<"\tY\t";
            }
            else {
                cout <<"\tN\t";
            }
        
            if (sphenic(num)) {
                cout <<"\t\t\tY\t";
            }
            else {
                cout <<"\t\t\tN\t";
            }
            
            if (num >= 1 && num <= 10) {
                cat[0]++;
            }
            else if (num >= 11 && num <= 20) {
                cat[1]++;
            }
            else if (num >= 21 && num <= 30) {
                cat[2]++;
            }
            else if (num >= 31 && num <= 40) {
                cat[3]++;
            }
            else if (num >= 41 && num <= 50) {
                cat[4]++;
            }
            else if (num >= 51 && num <= 60) {
                cat[5]++;
            }
            else if (num >= 61 && num <= 70) {
                cat[6]++;
            }
            else if (num >= 71 && num <= 80) {
                cat[7]++;
            }
            else if (num >= 81 && num <= 90) {
                cat[8]++;
            }
            else {
                cat[9]++;
            }
        
            binary(num);
        }
        else if (num == 0) {
            no_reveal_nums++;
        }
        else {
            invalid_nums++;
        }
            numbers_file >> num;
    }
    numbers_file.close();
    numbers_file.open("/Users/razoredge451/Desktop/assignment1s2/assignment1s2/numbers.txt");
    numbers_file >> num;
    cout << "\nInvalid Numbers" << endl;
    cout << "===============" << endl;
    
    while (num!=-1) {
        if (num < 0 || num > 100) {
            cout << num << endl;
        }
        numbers_file >> num;
    }
    numbers_file.close();
    
    cout << "\nRange\tHistogram" << endl;
    cout << "=================" << endl;
    cout << "1-10\t";
    for (int i = 0; i < floor((cat[0] / 5)); i++) {
        cout << "*";
    }
    cout << "\n11-20\t";
    for (int i = 0; i < floor((cat[1] / 5)); i++) {
        cout << "*";
    }
    cout << "\n21-30\t";
    for (int i = 0; i < floor((cat[2] / 5)); i++) {
        cout << "*";
    }
    cout << "\n31-40\t";
    for (int i = 0; i < floor((cat[3] / 5)); i++) {
        cout << "*";
    }
    cout << "\n41-50\t";
    for (int i = 0; i < floor((cat[4] / 5)); i++) {
        cout << "*";
    }
    cout << "\n51-60\t";
    for (int i = 0; i < floor((cat[5] / 5)); i++) {
        cout << "*";
    }
    cout << "\n61-70\t";
    for (int i = 0; i < floor((cat[6] / 5)); i++) {
        cout << "*";
    }
    cout << "\n71-80\t";
    for (int i = 0; i < floor((cat[7] / 5)); i++) {
        cout << "*";
    }
    cout << "\n81-90\t";
    for (int i = 0; i < floor((cat[8] / 5)); i++) {
        cout << "*";
    }
    cout << "\n91-100\t";
    for (int i = 0; i < floor((cat[9] / 5)); i++) {
        cout << "*";
    }
    
    numbers_file.open("/Users/razoredge451/Desktop/assignment1s2/assignment1s2/numbers.txt");
    numbers_file >> num;
    int total_nums[no_reveal_nums+fav_nums], count = 0, max_count = 0, max_num = 0, min_count = (no_reveal_nums + fav_nums), min_num, min_occurance = 0, num_occurance[100];
    while (num != -1) {
        if (num >= 0 && num <= 100) {
            total_nums[count] = num;
            count++;
            num_occurance[num]++;
        }
        numbers_file >> num;
    }
    
    //MOST FREQUENT #
    for (int i = 0; i < count; i++) {
        int num_count = 1;
        for (int j = i+1; j < count; j++) {
            if (total_nums[i] == total_nums[j] && (total_nums[i] != 0 && total_nums[j] != 0)) {
                num_count++;
            }
        }
        if ((num_count > max_count) && (num_count >= 2)) {
            max_count = num_count;
            max_num = total_nums[i];
        }
    }
    
    //LEAST FREQUENT #
    for (int i = 0; i < 100; i++) {
        if (num_occurance[i] != 0) {
            min_occurance = num_occurance[i];
            break;
        }
    }
    
    for (int i = 0; i < 100; i++) {
        if ((num_occurance[i] < min_occurance) && (num_occurance[i] != 0)) {
            min_occurance = num_occurance[i];
            min_num = i;
        }
    }
    cout << "# of students who chose valid #s: " << fav_nums << endl;
    cout << "# of students who chose invalid #s: " << invalid_nums << endl;
    cout << "# of students who did not choose to release a #: " << no_reveal_nums << endl;

    cout << endl << "Most frequent #: " << max_num << endl;
    cout << "Least frequent #: " << min_num << endl;

    return 0;
}
