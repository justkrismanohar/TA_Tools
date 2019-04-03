#include <iostream>
#include <fstream>
using namespace std;

bool validNum(int n) {
	if(n!=0 && n > 0 && n<=100)
	return true;
	else
	return false;
}

bool isPerfect(int n){
	int i;
	int sum = 0;
	for(i = 1; i <= n/2; i++) {
		if(n%i == 0) 
		sum = sum + i;
	}
	if (sum==n) 
	return true;
	return false;
}

bool perfectSquare(int n) {
	int square, i;
	for(i = 1; i<n/2; i++) {
		if(n/i == i)
		return true;
	}
	return false;
}

bool isPrime(int n) {
	int i, prime;
	for(i = 2; i<n/2; i++){
		prime = n%i;
		if(prime == 0)
		return false;
	}
	return true;
}

bool isSphenic(int n) {
	int product = 1;
	int prime = 0;
	int i;
	for(i = 2; i<n/2; i++) {
		if(n%i == 0 && (isPrime(i))) {
			product = product * i;
			prime++;
		}
	}
	if (prime == 3 && product == n)
	return true;
	return false;
}

void Binary(int n) {
	int binary1[8] = {};
	int i = 7;
	
	while (n!= 0) {
		if(n%2 == 0)
		binary1[i] = 0;
		else if (n%2 == 1)
		binary1[i] = 1;
		i--;
		n = n/2;
	}
	for(i = 0; i<=7; i++) 
	cout << binary1[i];
}
string Histogram(int n) {
	if (n/5 == 1)
	return "*";
	else if (n/5 == 2)
	return "**";
	else if(n/5 == 3)
	return "***";
	else if(n/5 == 4)
	return "****";
	else if(n/5 == 5)
	return "*****";
}
int main() {
	ifstream inputFile;
	bool perfect;
	bool perf_square;
	bool sphenic;
	bool prime;
	bool check;
	bool valid_num;
	bool distinct_num = true;
	int fav[1000] = {};
	int distinct[1000] = {};
	int valid[1000] = {};
	int invalid[1000] = {};
	int histogram1[10] ={};
	int most_chosen[1000] = {};
	int least_chosen[1000] = {};
	int dismost_chosen[1000] = {};
	int disleast_chosen[1000] = {};
	int choose[101] ={};
	int students = 0;
	int a = 0;
	int distinctNum = 0;
	int disnum=0;
	int invalidnum=0;
	int validnums=0;
	int b=0;
	int c=0;
	int d=0;
	int notshare = 0;
	int vnum = 0;
	int most = 0;
	int least = 999;
	int f;
	int num;
	int total_valid;
	int total_invalid; 
	int total_students;
	int total_distinct; 
	int total_most;
	int total_least;
	int total_chosen;
	
	inputFile.open("numbers.txt");
	if (!inputFile.is_open()) {
		cout<<"Error in opening file! Aborting...";
		return 0;
	}
	inputFile>>num;
	while (num!=-1) {
		fav[a] = num;
		a++;
		students++;
		inputFile>>num;
	}
	total_students = students;
	for(a = 0; a<total_students; a++) {
		valid_num = validNum(fav[a]);
		if(valid_num) {
			valid[validnums] = fav[a];
			validnums++;
		}
		else if (!valid_num) {
			invalid[invalidnum] = fav[a];
			invalidnum++;
		}
	}
	total_valid = validnums;
	total_invalid = invalidnum;
	
	for(a = 0; a < total_valid; a++) {
		for (b = 0; b <= total_valid; b++){
			if(valid[a] == distinct[b]) {
				distinct_num = false;
			}
		}
		if(distinct_num) {
			distinct[disnum] = valid[a];
			disnum++;
		}
		distinct_num = true;
	}
	total_distinct = disnum;
	
	cout << "Number   Perfect?   Prime?   Perfect Square?   Sphenic?   Binary Equiv." << endl;
	
	for(a = 0; a < total_distinct; a++) {
		cout << distinct[a] << "\t     ";
		
		perfect = isPerfect(distinct[a]);
		if(perfect)
		cout << "Y\t      ";
		else
		cout << "N\t      ";
		
		prime = isPrime(distinct[a]);
		if(prime)
		cout << "Y\t\t     ";
		else
		cout << "N\t\t     ";
		
		perf_square = perfectSquare(distinct[a]);
		if(perf_square)
		cout << "Y\t\t    ";
		else
		cout << "N\t\t    ";
		
		sphenic = isSphenic(distinct[a]);
		if(sphenic)
		cout << "Y\t     ";
		else
		cout << "N\t     ";
		
		Binary(distinct[a]);
		cout<<endl;
	}
	
	cout <<endl<< "Invalid Numbers" << endl<<endl;
	for(a = 0; a < total_invalid; a++) {
		if(a%5 == 0 && a != 0)
		cout << endl;
		cout << invalid[a] << " ";
	}
	cout<<endl<<endl;
	
	for (a = 0; a < total_valid; a++) {
		if(valid[a] >= 1 && valid[a] <= 10)
		histogram1[0]++;
		else if(valid[a] >= 11 && valid[a] <=20)
		histogram1[1]++;
		else if(valid[a] >= 21 && valid[a] <=30)
		histogram1[2]++;
		else if(valid[a] >= 31 && valid[a] <=40)
		histogram1[3]++;
		else if(valid[a] >= 41 && valid[a] <=50)
		histogram1[4]++;
		else if(valid[a] >= 51 && valid[a] <=60)
		histogram1[5]++;
		else if(valid[a] >= 61 && valid[a] <=70)
		histogram1[6]++;
		else if(valid[a] >= 71 && valid[a] <=80)
		histogram1[7]++;
		else if(valid[a] >= 81 && valid[a] <=90)
		histogram1[8]++;
		else if(valid[a] >= 91 && valid[a] <=100)
		histogram1[9]++;
	}
	cout << "Range			Histogram"<<endl;
	cout <<"						 "<<endl;
	cout <<"1 - 10			"<< Histogram(histogram1[0])<<endl;
	cout <<"11 - 20			"<< Histogram(histogram1[1])<<endl;
	cout <<"21 - 30			"<< Histogram(histogram1[2])<<endl;
	cout <<"31 - 40			"<< Histogram(histogram1[3])<<endl;
	cout <<"41 - 50			"<< Histogram(histogram1[4])<<endl;
	cout <<"51 - 60			"<< Histogram(histogram1[5])<<endl;
	cout <<"61 - 70			"<< Histogram(histogram1[6])<<endl;
	cout <<"71 - 80			"<< Histogram(histogram1[7])<<endl;
	cout <<"81 - 90			"<< Histogram(histogram1[8])<<endl;
	cout <<"91 - 100		"<< Histogram(histogram1[9])<<endl;
	cout << endl;
	
	for( int i= 0; i<total_invalid; i++){
		if(invalid[i]== 0)
		notshare ++;
		}
	
	cout << "Amount of students with Valid Favourite Numbers  " << total_valid << endl;
	cout << "Amount of Students with Invalid Favourite Numbers  " << total_invalid<<endl;
	cout << "Amount of Students that did not reveal their Favourite Numbers  " << notshare << endl; 
		
		
		for (a = 0; a < total_valid; a++) {
		vnum = valid[a];
		choose[vnum]++;
	}
	for (a = 1; a < 101; a++) {
		if(choose[a] > most && choose[a] >= 2) {
			most = choose [a];
		}
		if(choose[a] < least && choose[a] >= 1){
			least = choose[a];
		}
	}
	for(a = 1; a < 101; a++){
		if(choose[a] == most){
			most_chosen[c] = a;
			c++;
		}
		if(choose[a] == least) {
			least_chosen[d] = a;
			d++;
		}
	}
	total_most = c;
	total_least = d;
	
	cout << endl;
	cout << "Number(s) chosen most by students: ";
	for(a = 0; a < total_most; a++) {
		cout << most_chosen[a] << "		";
	}
	cout << endl;
	cout << "Numbers(s) chosen least by students: ";
	for(a=0; a<total_least; a++){
		cout << least_chosen[a] << "	";	
	}
		
	inputFile.close();
	return 0;
}
