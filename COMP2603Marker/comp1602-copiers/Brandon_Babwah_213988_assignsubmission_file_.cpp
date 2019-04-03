#include <iostream>
#include <fstream>
using namespace std;

bool isValid (int num){
	if ((num > 0) && (num <=100)){
		return true;
	}
	else {
		return false;
	}
}

bool isPerfect (int num){

	int i;
	int sum = 0;
	
	for (i = 1; i <= (num/2); i++){
		if (num % i == 0){
			sum = sum + i;
		}
	}
	
	if (sum == num){
		return true;
	}
	else {
		return false;
	}
			
}

bool isPrime (int num){
	int i, count;
	int a = 0;
	
	for (i = 2; i <= num/2; i++){
		if ((num % i) == 0){
			for (count = 2; count <= i/2; count++){
				if ((i % count) == 0){
					a++;
				}
			}
		}		
	}
	
	if (a == 0){
		return true;
	}
	else {
		return false;
	}
}

bool isPerfectSquare (int num){
	int i = 2;
	int a,b;
	bool square = false;
	b = num;
	for (i = 2; i <= num/2; i++){
		a = b % i;
	
		if (a == 0){
			b = b / i;
			if (i == b){
				square = true;
			}
		}
	}
	
	if (square){
		return true;
	}
	else {
		return false;
	}
	
}

bool isSphenic (int num){
	int i, count;
	int a, b, c;
	int x = 0;
	bool prime;
	a = num;
	for (count = 2; count <= a/2; count++){
	
		if (a % count == 0){		
			prime = isPrime(count);
			
			if (isPrime(count)){
				x++;
				a = a / count;
			}		
		} 
	}
		
	if (x == 3){
		return true;	
	}	
	else{
		return false;
	}			
}

void Binary (int num){
	
	int i = 0;
	int bin[8];
	int a,b;
	a = num;
	while (i <= 7){
		b = a % 2;
		a = a / 2;
		
		if (b == 1){
			bin[i] = 1;
		}
		else {
			bin[i] = 0;
		}
		
		i = i + 1;	
	}
	
	for (i = 7; i >= 0; i = i - 1){
		cout << bin[i] ;
	}
}


int main (){
	ifstream numbers;
	int x[500] = {0};
	int i, count, validnum, invalidnum,unknown;
	bool valid, perfect, prime, square, sphenic;
	int num[500];
	int a,b;
    int	students = 0;
    int most, least, mostnum, leastnum;;
    most = 0;
    least = 0;
    
	a = 10;
	b = 1;
	numbers . open ("numbers.txt");
	i = 0;
	count = 1;
	validnum = 0;
	invalidnum = 0;
	unknown = 0;
	
	
	numbers >> num[i];
	students++;
	cout << "Number\t" << "Perfect\t"<< " Prime\t" << "Perfect Square\t" << "Sphenic\t" << "	Binary" << endl ;
	cout << "______________________________________________________________________"<< endl;
	while (num[i] != -1){
		valid = isValid(num[i]);
		
		if (valid){
			validnum++;
			cout << num[i] << "\t ";	
			
			perfect = isPerfect(num[i]);
			if (perfect){
				cout << "YES \t ";
			}
			else {
				cout << "NO \t ";
			}
			
			prime = isPrime(num[i]);
			if (prime){
				cout << " YES \t ";
			}
			else {
				cout << " NO \t ";
			}
			
			square = isPerfectSquare(num[i]);
			if (square){
				cout << "  YES \t ";
			}
			else {
				cout << "  NO \t ";
			}
			
			sphenic = isSphenic(num[i]);
			if(sphenic){
				cout << "\t YES \t  ";
			}
			else{
				cout << "\t NO \t  ";
			}
			cout << "\t";
			Binary(num[i]);
			
			cout << endl;
			i++;			
		}
		
		numbers >> num[i];
		students++;
	}
	
	cout << "______________________________________________________________________"<< endl;
	
	
	cout << "Invalid numbers are :" << endl;
	for (i = 1; i <= students; i++){
		if(!valid){
			invalidnum++;
			cout << num[i] << "		";
			count++;
			if (count > 5){
				cout << endl;
				count = 1;
			}
			
		}
	}
	
	cout << "______________________________________________________________________"<< endl;
	
	
	cout << "Range \t  |" << "Histogram" << endl;
	cout << "__________|___________________" << endl;
	
	cout << " 1 - 10   |";
	for (i = 1; i <= students; i++){
	
		if (num[i] >= 1 && num[i] <= 10){
			cout << "*";
		}
	}
	cout << endl;
	
	cout << " 11 - 20  |";
	for (i = 1; i <= students; i++){
	
		if (num[i] >= 11 && num[i] <= 20){
			cout << "*";
		}
	}
	cout << endl;
	
	cout << " 21 - 30  |";
	for (i = 1; i <= students; i++){
	
		if (num[i] >= 21 && num[i] <= 30){
			cout << "*";
		}
	}
	cout << endl;
	
	cout << " 31 - 40  |";
	for (i = 1; i <= students; i++){
	
		if (num[i] >= 31 && num[i] <= 40){
			cout << "*";
		}
	}
	cout << endl;
	
	cout << " 41 - 50  |";
	for (i = 1; i <= students; i++){
	
		if (num[i] >= 41 && num[i] <= 50){
			cout << "*";
		}
	}
	cout << endl;
	
	cout << " 51 - 60  |";
	for (i = 1; i <= students; i++){
	
		if (num[i] >= 51 && num[i] <= 60){
			cout << "*";
		}
	}
	cout << endl;
	
	cout << " 61 - 70  |";
	for (i = 1; i <= students; i++){
	
		if (num[i] >= 61 && num[i] <= 70){
			cout << "*";
		}
	}
	cout << endl;
	
	cout << " 71 - 80  |";
	for (i = 1; i <= students; i++){
	
		if (num[i] >= 71 && num[i] <= 80){
			cout << "*";
		}
	}
	cout << endl;
	
	cout << " 81 - 90  |";
	for (i = 1; i <= students; i++){
	
		if (num[i] >= 81 && num[i] <= 90){
			cout << "*";
		}
	}
	cout << endl;
	
	cout << " 91 - 100 |";
	for (i = 1; i <= students; i++){
	
		if (num[i] >= 91 && num[i] <= 100){
			cout << "*";
		}
	}
	cout << endl;
	
	cout << "______________________________________________________________________"<< endl;
	
	for (i = 0; i <= students; i++){
		if( num[i] == 0){
			unknown++;
		}
	}
	
	cout << "Valid Numbers - " << validnum << endl;
	cout << "Invalid Numbers - " << invalidnum << endl;
	cout << "Unknown numbers - " << unknown << endl;
	
	
	for (i = 1; i<=100; i++){
		for(count = 1;count <=100; count++){
			if(num[i]= count){
				x[i]= x[i]+1;
				
		}
	}
		if (x[i] > most ){
			mostnum = num[i];
		}
		if (x[i] > 1 && x[i]< most){
			leastnum = num[i];
		}	
}
	
	cout << "Most occurring - " << mostnum << endl;
	cout << "Least occurring - " << leastnum;
			
	numbers . close();
	return 0;
}
