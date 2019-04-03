#include <iostream>
#include <fstream>
using namespace std;

bool isUnique (int n, int unique[], int size) {
	for (int i = 0; i < size; i++){
		if (n == unique[i])
			return false;
	}
	return true;
}

bool  isPerfect (int n) {
	int sum = 0;
	for (int i = 1; i <= n/2; i++) {
		if (n%i == 0)
			sum = sum + i;
	}
	if (sum == n) 
		return true;
	return false;
}

bool isPrime (int n) {
	if (n == 1)
		return false;
	for (int i = 2; i <= n/2; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

bool isPerfectSquare (int n) {
	int sq;
	if (n == 1) {
		return true;
	}
	for (int i = 2; i <= n/2; i++) {
		sq = i * i;
		if (n == sq) 
			return true;
	}
	return false;
}

bool isSphenic (int n) {
	int count = 0;
	int product = 1;
	for (int i = 2; i <= n/2; i++){
		if (n%i == 0 && isPrime (i)) {
			product = product * i;
			count = count + 1;
		}
	}
	if (count == 3 && product == n)
		return true;
	return false;
}

void Binary (int n) {
	int bin[9];
	int num;
	int a;
	for (int i = 0; i < 9; i++) {
		bin[i] = 0;
	}
	a = 1;
	while (n != 0) {
		if (n%2 == 1)
			bin[a] = 1;
	a = a + 1;
	n = n/2;	
	}
	for (int b = 8; b > 0; b = b - 1) {
		cout << bin[b];
	}
}

int main () {
	ifstream in;
	int num;
	int unique[101];
	int uCount = 0;
	int arr[1000];
	int count = 0;
	int valid = 0;
	int zero = 0;
	int invalid = 0;
	int range[10];
	bool ans;
	bool perfect;
	bool prime;
	bool perfectsquare;
	bool sphenic;
	int stars;
	int invNum[1000];
	int uniqueCount[101];
	int most = 0;
	int least = 999;
	
	for(int h = 0; h < 101; h++){
		unique[h]=0;
	}
	
	
	in.open("numbers.txt");
	if (!in.is_open()) {
		cout << "File was not found. Aborting...";
		return 0;
	}
	
	in >> num;
	while (num != -1) {
		arr[count] = num;
		count++;
		in >> num;
	}
	in.close();
	
	cout << "Number\t Perfect?\t Prime?\t Perfect Square?\t Sphenic?\t Binary Equiv." << endl;
	cout << "======\t ========\t ======\t ===============\t ========\t =============" << endl;
	
	for (int a = 0; a < count; a++) {
		if (arr[a] > 0 && arr[a] < 101) {
			valid = valid + 1;
			ans = isUnique (arr[a], unique, uCount);
			if (ans) {
				unique[uCount] = arr[a];
				uCount = uCount + 1;
				cout << arr[a] << "\t ";
				
				perfect = isPerfect (arr[a]);
				if (perfect)
					cout << "Y\t\t ";
				else
					cout << "N\t\t ";
					
				prime = isPrime (arr[a]);
				if (prime)
					cout << "Y\t ";
				else
					cout << "N\t ";
				
				perfectsquare = isPerfectSquare (arr[a]);
				if (perfectsquare)
					cout << "Y\t\t\t ";
				else
					cout << "N\t\t\t ";
					
				sphenic = isSphenic (arr[a]);
				if (sphenic)
					cout << "Y\t\t ";
				else
					cout << "N\t\t ";
				
				Binary (arr[a]);
				cout << endl;
			}	
		}
		else {
			if (arr[a] == 0) 
				zero = zero + 1;
			else {
				invNum [invalid] = arr[a];
				invalid = invalid + 1;
			}
		}
	}
	cout << endl << endl << endl;
	cout << "Invalid numbers: " << endl;
	for (int b = 0; b < invalid; b++){
		cout << invNum[b] << "\t";
		if ((b+1)%5 == 0)
			cout << endl;
	}
	
	cout << endl << endl << endl;
	
	for (int j = 0; j < 10; j++) {
		range[j] = 0;
	}
	
	for (int c = 0; c < count; c++) {
		if ((arr[c] >= 1) && (arr[c] <= 10))
			range[0] = range[0] + 1;
		
		if ((arr[c]  >= 11) && (arr[c]  <= 20))
			range[1] = range[1] + 1;
		
		if ((arr[c] >= 21) && (arr[c] <= 30))
			range[2] = range[2] + 1;
		
		if ((arr[c] >= 31) && (arr[c] <= 40))
			range[3] = range[3] + 1;
		
		if ((arr[c] >= 41) && (arr[c] <= 50))
			range[4] = range[4] + 1;
		
		if ((arr[c] >= 51) && (arr[c] <= 60))
			range[5] = range[5] + 1;
		
		if ((arr[c] >= 61) && (arr[c] <= 70))
			range[6] = range[6] + 1;
		
		if ((arr[c] >= 71) && (arr[c] <= 80))
			range[7] = range[7] + 1;
	
		if ((arr[c] >= 81) && (arr[c] <= 90))
			range[8] = range[8] + 1;
		
		if ((arr[c] >= 91) && (arr[c] <= 100))
			range[9] = range[9] + 1;
	}
	
	cout << "Range \t\tHistogram" << endl;
	cout << "==========================" << endl;
	int e;
	int f = 0;
	for (int d = 1; d <= 91; d = d + 10) {
		e = d + 9;
		cout << d << " - " << e << "  \t:";
		stars = range[f] / 5;
		f++;
		for (int g = 0; g < stars; g++) {
			cout << "*";
		}
		cout << endl;
	}
	
	cout << endl << endl;
	
	for (int l = 0; l < 101; l++){
		uniqueCount[l] = 0;
	}

	for (int k = 0; k < count; k++) {
		if (arr[k] > 0 && arr[k] < 101)
			uniqueCount[arr[k]]++;	
	}
	
	for (int m = 0; m < 101; m++) {
		if (uniqueCount[m] > 2 && uniqueCount[m] > most) 
			most = uniqueCount[m];
		if (uniqueCount[m] > 1 && uniqueCount[m] < least)
			least = uniqueCount[m];	
	}
	
	cout << "Number of students with valid favourite numbers: " << valid << endl;
	cout << "Number of students with invalid favourite numbers: " << invalid << endl;
	cout << "Number of students with unrevealed favourite numbers: " << zero << endl;
	cout << endl;
	cout << "The most chosen number(s): ";
	for (int n = 0; n < 101; n++) {
		if (uniqueCount[n] == most)
			cout << n << " ";
	}
	
	cout << endl;
	cout << "The least chosen number(s): ";
	for (int o =0; o <101; o++) {
		if (uniqueCount[o] == least)
			cout << o << " ";
	}
	
	cout << endl;
	return 0;	
}


