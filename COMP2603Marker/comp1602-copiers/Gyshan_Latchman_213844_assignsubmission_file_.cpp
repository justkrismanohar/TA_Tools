#include <iostream>
#include <fstream>
using namespace std;


char isPerfect (int n){
	int a, mod, sum=0;
	for (a=1;a<=n/2; a++){
		mod = n%a;
		if (mod == 0)
		sum = sum + a;
	}
	if (sum==n)
	return 'Y';
	return 'N';
}

char isSquare (int n) {
	int a, prod;
	if (n==1)
	return 'Y';
	else {
	for (a=1; a<=n/2; a++){
		prod = a*a;
		if (prod == n)
		return 'Y';
		} 
	}
	return 'N';
}

char isPrime (int n) {
	int a, mod;
	if (n==1)
	return 'N';
	else{
	for (a=2; a<=n/2; a++){
		mod = n%a;
		if (mod==0)
		return 'N';
		}
	}
	return 'Y';
}

char isSphenic (int n){
	int a, mod, prod=1, sum=0;
	char prime;
	for (a=2; a<=n/2; a++){
		prime = isPrime(a);
		mod = n%a;
		if (prime=='Y' && mod == 0){
		prod = prod*a;
		sum=sum+1;
		}
	}
	if (prod==n && sum == 3)
	return 'Y';
	else
	return 'N';
}

void binEquiv (int n) {
	int mod, div, i=n, rem[8], l=7;
	for (int k=0; k<8; k++)
	rem[k]=0;
	while (i!=0 && l>=0){
		mod = i % 2;
		rem[l]=mod;
		l=l-1;
		div = i/2;
		i = i/2;
	}
	for (int a=0; a<8; a++)
	cout << rem[a];
}

int main () {
	ifstream in;
	in.open("numbers.txt");
	if (!in.is_open()){
		cout << "Error opening file. Aborting...";
		return 0;
	}
	
	int choices[101], n;
	for (int i=0; i<101; i++)
	choices[i]=0;
	in >> n;
	while (n!=-1){
		if (n>=0 && n<=100)
		choices[n]= choices[n] + 1;
		in >> n;
	}
	cout << "Number\tPerfect? Prime?\t  Square? Sphenic?\tBinary" << endl;
	cout << "======\t======== ======= ======== ========\t==========" << endl;
	char perfect, prime, square, sphenic;
	for (int k=1; k<101; k++){
		if (choices[k]!=0) {
		perfect = isPerfect(k);
		prime = isPrime(k);
		square = isSquare(k);
		sphenic = isSphenic(k);
		cout << k << "   \t   " << perfect << "   \t   " << prime << "   \t   " << square << "   \t   " << sphenic << "\t\t";
		binEquiv(k);
		cout << endl;
		}
	}
	
	cout << endl << endl << "IVALID ENTRIES" << endl << "----------------- "<< endl << endl;
		
	in.close();
	ifstream input;
	input.open("numbers.txt");
	if (!input.is_open()){
		cout << "Error opening file. Aborting...";
		return 0;
	}
	int num, j=0, invalid=0, valid=0;
	input >> num;
	while (num!=-1) {
		if (num<0 || num>100){
			cout << num << " ";
			invalid++;
			j++; 
		if (j%5==0)
		cout << endl;
		}
		input >> num;		
	}
	
	cout << endl << endl << endl;
	cout << "RANGE         HISTOGRAM" << endl;
	cout << "==============================" << endl;
	int div, starsTotal=0;
	for (int l=1; l<101; l=l+10){
		for (int w=l; w<l+10; w++){
			starsTotal = starsTotal + choices[w];
		}
		cout << l << " - " << l+9 << "  \t|"; 
		div=starsTotal/5;
	    for (int i=1; i<=div; i++)
	    cout << "*";
		cout << endl;
		starsTotal=0; 
	}
	
	int most=-1, least=1000, total=0, numMost, numLeast;
	for (int m=1; m<101; m++){
		if(choices[m]>most && choices[m]>=2){
		most=choices[m];
		}
		if(choices[m]<least && choices[m]>=1){
		least=choices[m];
		}
		valid=valid+choices[m];
	}
	
	cout << endl << endl;
	cout << "Number valid: " << valid << endl;
	cout << "Number invalid: " << invalid << endl;
	cout << "Students that did not reveal: " << choices[0] << endl;
	cout << "Number(s) chosen the most: ";
	for (int y=1; y<101; y++){
		if (choices[y]==most)
		cout << y << " ";
	}
	cout << endl;
	cout << "Number(s) chosen the least: ";
	for (int g=1; g<101; g++){
		if (choices[g]==least)
		cout << g << " ";
	}	
	input.close();
	return 0;	 
}

