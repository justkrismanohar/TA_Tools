#include<iostream>
#include<string>
#include<fstream>
using namespace std;

bool isFactor(int n, int m) {
	if (m%n == 0)
		return true;
	else
		return false;
}
/*b(i)*/
bool isPerfect(int n) {
	int i;
	int total = 0;
	for (i = 1; i < n; i++) {
		if (isFactor(i, n)) {
			total = total + i;
		}

	}
	if (total == n)
		return true;
	else
		return false;
}

/*b(ii)*/
bool isPrime(int n) {
	int i;
	if (n == 1)
		return false;
	for (i = n - 1; i > 1; i++) {
		if (n%i == 0)
			return false;
		
	}
	
			return true;
}


/*b(iii)*/
bool isPSquare(int n) {
	int i;
	for (i = 1; i < n; i++) {
		if ((i*i) == n)
			return true;

	}
	return false;
}


/*b(iv)*/
bool isSphenic(int n) {
	int pqr = 1;
	int i;
	int primes = 0;
	for (i = 1; i < n; i++) {
		if (isFactor(i, n) && isPrime(i)) {
			pqr = pqr * i;
			primes = primes + 1;
		}
		if (primes == 3 && pqr == n)
			return true;
	}
	return false;
}
/*b(v)*/
void binconverter(int n) {
	int i, a[10];
	for (i = 0; n > 0; i++)
	{
		a[i] = n % 2;
		n = n / 2;
	}
	for (i = i - 1; i >= 0; i--)
	{
		cout << a[i];
	}
}
	


int main() {

	return 0;
}