#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool is_perfect(int num) {
	int sum = 1;
	int max_factor = floor(sqrt(num));
	for (int i = 2; i <= max_factor; i++) {
		if (num % i == 0) {
			int other_factor = num / i;
			sum += i;
			
			if (i != other_factor) {
				sum += other_factor;
			}
		}
	}
	return (num == sum) && (num != 1);
}

bool is_prime(int num) {
	int max_factor = floor(sqrt(num));
	for (int i = 2; i <= max_factor; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return num > 1;
}

bool is_square(int num) {
	int square_root = round(sqrt(num));
	return square_root * square_root == num;
}

bool is_sphenic(int num) {
	int max_p = floor(cbrt(num));
	for (int p = 2; p <= max_p; p++) {
		if (num % p == 0) {
			int quotient = num / p;
			if (quotient % p == 0) {
				return false; // duplicate divisor
			}
			int max_q = floor(sqrt(quotient));
			for (int q = p + 1; q <= max_q; q++) {
				if (quotient % q == 0) {
					int r = quotient / q;
					return is_prime(r) && (r != q);
					// It is not necessary to check if p and q are prime
				}
			}
			return false;
		}
	}
	return false;
}

void print_binary(int num) {
	int bits[8];
	for (int i = 0; i < 8; i++) {
		bits[i] = num % 2;
		num /= 2;
	}
	for (int i = 7; i >= 0; i--) {
		cout << bits[i];
	}
}

char yes_or_no(bool b) {
	if (b) {
		return 'Y';
	}
	else {
		return 'N';
	}
}

int main() {
	ifstream fin;
	fin.open("numbers.txt");
	if (!fin.is_open()) {
		cout << "Error opening file: numbers.txt" << endl;
		return 0;
	}
	
	int range_counts[10];
	for (int i = 0; i < 10; i++) {
		range_counts[i] = 0;
	}
	
	int counts[100];
	for (int i = 0; i < 100; i++) {
		counts[i] = 0;
	}
	
	cout << "Number \t Perfect? \t Prime? \t Square? \t Sphenic? \t Binary" << endl;
	cout << "====== \t ======== \t ====== \t ======= \t ======== \t ======" << endl;
	
	int valid_count = 0;
	int invalid_count = 0;
	int unrevealed_count = 0;
	
	int num;
	fin >> num;
	while (num != -1) {
		if (num == 0) {
			unrevealed_count++;
		}
		else if (num > 0 && num <= 100) {
			valid_count++;
			int range_index = (num - 1) / 10;
			range_counts[range_index]++;
			counts[num-1]++;
			
			if (counts[num-1] == 1) { // distinct number
				cout << num << "\t ";
				cout << yes_or_no(is_perfect(num)) << "\t\t ";
				cout << yes_or_no(is_prime(num)) << "\t\t ";
				cout << yes_or_no(is_square(num)) << "\t\t ";
				cout << yes_or_no(is_sphenic(num)) << "\t\t ";
				print_binary(num);
				cout << endl;
			}
		}
		fin >> num;
	}
	cout << endl;
	
	fin.close();
	fin.open("numbers.txt");
	if (!fin.is_open()) {
		cout << "Error opening file: numbers.txt" << endl;
		return 0;
	}
	
	cout << "Invalid Numbers" << endl;
	fin >> num;
	while (num != -1) {
		if (num < 0 || num > 100) {
			invalid_count++;
			cout << num << ' ';
			if (invalid_count % 5 == 0) {
				cout << endl;
			}
		}
		fin >> num;
	}
	fin.close();
	
	cout << endl << endl;
	cout << "Range \t Histogram" << endl;
	for (int i = 0; i < 10; i++) {
		cout << (10 * i + 1) << '-' << (10 * i + 10) << "\t|";
		int num_stars = range_counts[i] / 5;
		for (int j = 0; j < num_stars; j++) {
			cout << '*';
		}
		cout << endl;
	}
	cout << endl;
	
	cout << "Number of valid numbers: " << valid_count << endl;
	cout << "Number of invalid numbers: " << invalid_count << endl;
	cout << "Number of unrevealed numbers: " << unrevealed_count << endl;
	
	int max = 0;
	int min = valid_count;
	for (int i = 0; i < 100; i++) {
		if (counts[i] > max) {
			max = counts[i];
		}
		if (counts[i] < min && counts[i] >= 1) {
			min = counts[i];
		}
	}
	
	cout << endl;
	cout << "Number(s) chosen the most: " << endl;
	if (max >= 2) {
		for (int i = 0; i < 100; i++) {
			if (counts[i] == max) {
				num = i + 1;
				cout << num << endl;
			}
		}
	}
	else {
		cout << "No number was selected more than once" << endl;
	}
	cout << endl;
	
	cout << "Number(s) chosen the least: " << endl;
	for (int i = 0; i < 100; i++) {
		if (counts[i] == min) {
			num = i + 1;
			cout << num << endl;
		}
	}
	cout << endl;
	
	cin.get(); // Press enter to exit
	return 0;
}