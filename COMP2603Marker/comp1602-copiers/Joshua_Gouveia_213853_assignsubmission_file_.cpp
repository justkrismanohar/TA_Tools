#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

char perfect(int x);
char prime(int x);
char perfectSqr(int x);
char sphenic(int x);
void binary(int x);

int main() {
	
	ifstream infile;
	int num;
	int Num[1000];

	infile.open("numbers.txt");

	if (!infile.is_open()) {
		cout << "Error. Abort." << endl;
		return 0;
	}

	for (int i = 0; i < 1000; i++) {
		infile >> Num[i];
	}

	cout << "Number" << setw(10) << "Perfect?" << setw(10) << "Prime?" << setw(10) << "Perfect Square?" << setw(10) << "Sphenic?" << setw(10) << "Binary Equiv." << endl;
	cout << "======" << setw(10) << "========" << setw(10) << "======" << setw(10) << "===============" << setw(10) << "========" << setw(10) << "=============" << endl;


	while (num != -1) {
		if ((num >= 1) && (num <= 100)) {

		}
		//cout << num << endl;

		infile >> num;
	}




	return 0;
}


char perfect(int x) {

	int sum = 0;
	for (int i = 1; i < x; i++) {
		if (x%i == 0)
			sum = sum + i;
	}
	if (sum == x) {
		return 'Y';
	}
	else {
		return 'N';
	}
}

char prime(int x) {

	bool isPrime = true;

	for (int i = 2; i <= x / 2; i++) {
		if (x%i == 0) {
			isPrime = false;
			break;
		}
	}
	if (isPrime == true) {
		return 'Y';
	}
	else {
		return 'N';
	}
}

char perfectSqr(int x) {

	int sqr = 1;
	for (int i = 1; i <= x; i++) {
		sqr = i * i;
	}
	if (sqr == x) {
		return 'Y';
	}
	else {
		return 'N';
	}
}

char sphenic(int x) {
	int n;
	int cot = 0;
	int prod = 1;

	for (int i = 2; i <= n / 2; i++) {
		if (x%i == 0) {
			cot = cot + 1;
			prod = prod * i;
		}
		if ((cot == 3) && (prod == x)) {
			return 'Y';
		}
		else {
			return 'N';
		}
	}
}

void binary(int x) {

	int binArr[8];
	int i = 0;

	while (x > 0) {
		binArr[i] = x % 2;
		x = x / 2;
		i++;
	}
	for (i = i - 1; i >= 0; i--) {
		cout << binArr[i];
	}

}