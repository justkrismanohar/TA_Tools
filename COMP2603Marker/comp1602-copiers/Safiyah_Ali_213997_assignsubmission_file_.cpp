#include <fstream>
#include <iostream>
using namespace std;
char isPerfect (int x) {
	int i, d;
	d = 1;
	for (i = 2; i <= x/2; i = i + 1) {
		if (x%i == 0)
			d = d + i;
	}
	if (d == x)
		return 'Y';
	return 'N';
}
char isPrime (int x) {
	int i;
	if (x == 1)
		return 'N';
	for (i = 2; i <= x/2; i = i +1) {
		if (x%i == 0)
			return 'N';
	}
	return 'Y';
}
char isPerfectSquare (int x) {
	int i;
	for (i = 1; i <= x/2; i = i + 1) {
		if (i*i == x)
			return 'Y';
	}
	return 'N';
}
char isSphenic (int x) {
	int i, j, quo, prod;
	char prime;
	prod = 1;
	j = 0;
	if (x < 30)
		return 'N';
	else {
		for (i = 2; i <= x/2; i = i + 1) {
			quo = x/i;
			prime = isPrime(i);
			if (x%i == 0 && prime == 'Y') {
				prod = prod*i;
				j = j + 1;
			}
		}
		if (prod == x && j == 3)
			return 'Y';
		return 'N';
	}
}
void binaryConverter (int x) {
	int i, r;
	int binary[8];
	for (i = 0; i < 8; i = i + 1)
		binary[i] = 0;
	i = 7;
	r = x%2;
	while (x != 0 || i < 0) {
		binary[i] = r;
		x = x/2;
		i = i - 1;
		r = x%2;
	}
	for (i = 0; i < 8; i = i + 1)
		cout << binary[i];
	cout << endl;
}
int main () {
	ifstream fin;
	int i, j, n, least, most;
	int valid[1000], invalid[1000], count [101], range[10], mostChosen[101], leastChosen[101];
	char perfect, prime, perfSqr, sphenic;
	fin.open("numbers.txt");
	if (!fin.is_open()) {
		cout << "Error! File not found." << endl;
		return 0;
	}
	for (i = 0; i < 101; i = i + 1)
		count[i] = 0;
	i = j = 0;
	fin >> n;
	while (n != -1) {
		if (n <= 100 && n >= 1) {
			valid[i] = n;
			i = i + 1;
			count[n] = count[n] + 1;
		}
		else {
			if (n == 0)
				count[n] = count[n] + 1;
			else {
				invalid[j] = n;
				j = j + 1;
			}
		}	
		fin >> n;
	}
	fin.close();
	cout << "Number  Perfect?  Prime?  Perfect Square?  Sphenic?  Binary Equiv." << endl;
	cout << "======  ========  ======  ===============  ========  =============" << endl;
	for (n = 0; n < i; n = n + 1) {
		cout << valid[n] << "\t";
		perfect = isPerfect(valid[n]);
		cout << perfect << "\t  ";
		prime = isPrime(valid[n]);
		cout << prime << "\t  ";
		perfSqr = isPerfectSquare(valid[n]);
		cout << perfSqr << "\t\t   ";
		sphenic = isSphenic(valid[n]);
		cout << sphenic << "\t     ";
		binaryConverter(valid[n]);
	}
	cout << "\n";
	cout << "Invalid Numbers are: " << endl;
	for (n = 0; n < j; n = n + 1) {
		cout << invalid[n] << " ";
		if ((n+1)%5 == 0)
			cout << endl;
	}
	cout << "\n\n";
	for (n = 100; n > 0; n = n - 1) {
		if (n > 90)
			range[9] = range[9] + count[n];
		else {
			if (n > 80)
				range[8] = range[8] + count[n];
			else {
				if (n > 70)
					range[7] = range[7] + count[n];
				else {
					if (n > 60)
						range[6] = range[6] + count[n];
					else {
						if (n > 50)
							range[5] = range [5] + count[n];
						else {
							if (n > 40)
								range[4] = range[4] + count[n];
							else {
								if (n > 30)
									range[3] = range[3] + count[n];
								else {
									if (n > 20)
										range[2] = range[2] + count[n];
									else {
										if (n > 10) 
											range[1] = range[1] + count[n];
										else
											range[0] = range[0] + count[n];
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "Range \t Histogram" << endl;
	cout << "==================" << endl;
	cout <<"1 - 10 \t ";
	while (range[0] >= 5) {
		range[0] = range[0] - 5;
		cout << "*";
	}
	cout << endl << "11 - 20  ";
	while (range[1] >= 5) {
		range[1] = range[1] - 5;
		cout << "*";
	}
	cout << endl << "21 - 30  ";
	while (range[2] >= 5) {
		range[2] = range[2] - 5;
		cout << "*";
	}
	cout << endl << "31 - 40  ";
	while (range[3] >= 5) {
		range[3] = range[3] - 5;
		cout << "*";
	}
	cout << endl << "41 - 50  ";
	while (range[4] >= 5) {
		range[4] = range[4] - 5;
		cout << "*";
	}
	cout << endl << "51 - 60  ";
	while (range[5] >= 5) {
		range[5] = range[5] - 5;
		cout << "*";
	}
	cout << endl << "61 - 70  ";
	while (range[6] >= 5) {
		range[6] = range[6] - 5;
		cout << "*";
	}
	cout << endl << "71 - 80  ";
	while (range[7] >= 5) {
		range[7] = range[7] - 5;
		cout << "*";
	}
	cout << endl << "81 - 90  ";
	while (range[8] >= 5) {
		range[8] = range[8] - 5;
		cout << "*";
	}
	cout << endl << "91 - 100 ";
	while (range[9] >= 5) {
		range[9] = range[9] - 5;
		cout << "*";
	}
	cout << "\n\n";
	cout << "Amount of students with valid numbers: " << i << "." << endl;
	cout << "Amount of students with invalid numbers: " << j << "." << endl;
	cout << "Amount of students concealing their favourite number: " << count[0] << "." << endl;
	for (n = 0; n < 101; n = n + 1) {
		mostChosen[n] = 0;
		leastChosen[n] = 101;
	}
	i = 2;
	least = most = 1;
	for (n = 1; n < 101; n = n + 1) {
		if (count[n] == 1) {
			leastChosen[least] = n;
			least = least + 1;
		}
		else {
			if (count[n] > 1 && count[n] > i) {
				j = mostChosen[0];
				mostChosen[0] = n;
				i = count[n];
				mostChosen[most] = j;
				most = most + 1;
			}
			else {
				mostChosen[most] = n;
				most = most + 1;
			}
		}
	}
	cout << "The most chosen favourite number is " << mostChosen[0] << ". \n";
	cout << "Numbers chosen at least twice are: \n";
	for (n = 1; n < most; n = n + 1) {
		cout << mostChosen[n] << "   ";
		if (n%5 == 0)
			cout << endl; 
	}
	cout << endl << "The least chosen number[s] is[are]: \n";
	for (n = 1; n < least; n = n + 1) {
		cout << leastChosen[n] << "  ";
		if (n%5 == 0)
			cout << endl; 
	}
	return 0;
}
