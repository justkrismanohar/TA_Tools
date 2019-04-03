#include <iostream>
#include <fstream>

using namespace std;

bool isValid(int n){ //function tests the numbers for validity (1 - 100)
	if(n != 0 && n > 0 && n <= 100)
		return true;
	else
		return false;
}

bool isPerfect(int n){ //functions tests if the number is perfect
	int i;
	int sum = 0;
	for(i = 1; i <= n/2; i++){
		if(n % i == 0)
			sum = sum + i;
	}
	if(sum == n)
		return true;
	return false;
}

bool isPerfectSquare(int n){
	int square, i;
	for(i = 1; i < n; i++){
		square = i * i;
		if(square == n)
			return true;
	}
	return false;
}

bool isPrime(int n){
	int i;
	int prime;
	for(i = 2; i < n/2; i++){
		prime = n % i;
		if(prime == 0)
			return false;
	}
	return true;
}

bool isSphenic(int n){
	int product = 1;
	int primes = 0;
	int i;
	for(i = 2; i < n/2; i++){
		if(n % i == 0 && (isPrime(i))){
			product = product * i;
			primes++;
		}
	}
	if(primes == 3 && product == n)
		return true;
	return false;
}

void toBinary(int n){
	int binary[8] = {};
	int i = 7;
	
	while(n != 0){
		if(n % 2 == 0)
			binary[i] = 0;
		else if(n % 2 == 1)
			binary[i] = 1;
		i--;
		n = n / 2;
	}
	
	for(i = 0; i <= 7; i++)
		cout << binary[i];
}

void Histogram( int histogram[], int n){
	int stars = 0;
	int i = 0;
	
	stars = histogram[n] / 5;
	
	for(i = 0; i < stars; i++)
		cout << "*";
}

int main(){
	
	ifstream input; //file to input numnbers from file
	bool vldcheck; //checks to see if number is valid
	bool discheck; //checks to see if the number is distinct
	bool perfect; //checks to ensure number is perfect
	bool psquare; //checks to see if number is a perfect square
	bool sphenic; //checks to see if number is sphenic
	bool prime; //checks to see if number is a prime
	int favnum[10000] = {}; //reads and stores the numbers given by students
	int distinct[10000] = {};
	int valid[10000] = {};
	int invalid[10000] = {};
	int histo[10] = {};
	int mchosen[10000] = {};
	int lchosen[10000] = {};
	int chose[101] = {};	
	int students = 0; //number of students who gave numbers
	int x = 0;
	int dis = 0; //distinct
	int inv = 0; //invalid
	int val = 0; //valid
	int z = 0;
	int k = 0;
	int h = 0;
	int noshare = 0;
	int vnum = 0;
	int most = 0;
	int least = 9999;
	int num, tstudents, tvalids, tinvalids, tdistincts, a, tmost, tleast;
	
	input.open("numbers.txt"); //opens the file
	
	if(!input.is_open()){ //closes program if there is an error opening the file
		cout << "Error opening file. Closing program...";
		return 0;
	}
	
	input >> num;
	
	while(num != -1){
		favnum[x] = num;
		x++;
		students++;
		input >> num;
	}
	
	tstudents = students; //stores the total amount of numbers from students
	
	for(x = 0; x < tstudents; x++){
		vldcheck = isValid(favnum[x]);
		if(vldcheck){
			valid[val] = favnum[x];
			val++; //valid numbers
		}
		else if(!vldcheck){
			invalid[inv] = favnum[x];
			inv++; //invalid numbers
		}
	}
	
	
	tvalids = val; //stores the total amount of valid numbers
	tinvalids = inv; //stores the total amount of invalid numbers
	
	for(x = 0; x < tinvalids; x++){
		if(invalid[x] == 0)
			noshare++;
	}
	
	for(x = 0; x < tvalids; x++){
		for(a = 0; a <= tvalids; a++){
			if(valid[x] == distinct[a]){
				discheck = false;
			}
		}
		if(discheck){
			distinct[dis] = valid[x];
			dis++;
		}
		discheck = true;
	}
	
	tdistincts = dis; //stores the total amount of distinct numbers
	
	cout << "Number		Perfect?		Prime?		Perfect Square?		Sphenic?		Binary Equiv." << endl;
	cout << "------		--------		------		---------------		--------		-------------" << endl;

	for(x = 0; x < tdistincts; x++){
		cout << distinct[x] << "		";
		
		perfect = isPerfect(distinct[x]);
		if(perfect)
			cout << "Y" << "			";
		else
			cout << "N" << "			";
		
		prime = isPrime(distinct[x]);
		if(prime)
			cout << "Y" << "		";
		else
			cout << "N" << "		";
			
		psquare = isPerfectSquare(distinct[x]);
		if(psquare)
			cout << "Y" << "			";
		else
			cout << "N" << "			";
			
		sphenic = isSphenic(distinct[x]);
		if(sphenic)
			cout << "Y" << "			";
		else
			cout << "N" << "			";
			
		toBinary(distinct[x]);
		cout << endl; 
	}
	
	cout << endl << endl << endl;
	cout << "List of Invalid Numbers" << endl;
	cout << "-----------------------------------" << endl;
	for(x = 0; x < tinvalids; x = x + 1){
		if(x % 5 == 0 && x != 0)
			cout << endl;
		cout << invalid[x] << "	";	
	}
	
	for(x = 0; x < tvalids; x++){
		if(valid[x] >= 1 && valid[x] <= 10)
			histo[0]++;
		else if(valid[x] >= 11 && valid[x] <= 20)
			histo[1]++;
		else if(valid[x] >= 21 && valid[x] <= 30)
			histo[2]++;
		else if(valid[x] >= 31 && valid[x] <= 40)
			histo[3]++;
		else if(valid[x] >= 41 && valid[x] <= 50)
			histo[4]++;
		else if(valid[x] >= 51 && valid[x] <= 60)
			histo[5]++;
		else if(valid[x] >= 61 && valid[x] <= 70)
			histo[6]++;
		else if(valid[x] >= 71 && valid[x] <= 80)
			histo[7]++;
		else if(valid[x] >= 81 && valid[x] <= 90)
			histo[8]++;
		else if(valid[x] >= 91 && valid[x] <= 100)
			histo[9]++;
	}
	
	cout << endl << endl << endl;
	
	cout << "Range		Histogram" << endl;
	cout << "-------------------------" << endl;
	cout << "1-10		";
	Histogram(histo, 0);
	cout << endl << "11-20		";
	Histogram(histo, 1);
	cout << endl << "21-30		";
	Histogram(histo, 2);
	cout << endl << "31-40		";
	Histogram(histo, 3);
	cout << endl << "41-50		";
	Histogram(histo, 4);
	cout << endl << "51-60		";
	Histogram(histo, 5);
	cout << endl << "61-70		";
	Histogram(histo, 6);
	cout << endl << "71-80		";
	Histogram(histo, 7);
	cout << endl << "81-90		";
	Histogram(histo, 8);
	cout << endl << "91-100		";
	Histogram(histo, 9);
	cout << endl;
	
	cout << endl << endl;
	
	cout << "Amount of Students that Submitted Valid Favourite Numbers: " << tvalids << " Students" << endl;
	cout << endl;
	cout << "Amount of Students that Submitted Invalid Favourite Numbers: " << tinvalids << " Students" << endl;
	cout << endl;
	cout << "Amount of Students that did not reveal their Favourite Numbers: " << noshare << " Students" << endl;
	
	for(x = 0; x < tvalids; x++){
		vnum = valid[x];
			chose[vnum]++;
	}
	
	for(x = 1; x < 101; x++){
		if(chose[x] > most && chose[x] >= 2){
			most = chose[x];
		}
		
		if(chose[x] < least && chose[x] >= 1){
			least = chose[x];
		}
	}
	
	for(x = 1; x < 101; x++){
		if(chose[x] == most){
			mchosen[z] = x;
			z++;
		}
		if(chose[x] == least){
			lchosen[k] = x;
			k++;
		}
	}
	
	tmost = z; //total size of most chosen numbers array
	tleast = k; //total size of least chosen numbers array
	
	
	cout << endl << endl;
	
	cout << "Number/s chosen most by the students:" << endl;
	for(x = 0; x < tmost; x++){
		cout << mchosen[x] << "	";
	}
	
	cout << endl << endl;
	
	cout << "Number/s chosen least by the students: " << endl;
	for(x = 0; x < tleast; x++){
		cout << lchosen[x] << "	";
	}
	
	input.close();
	return 0;
}


