#include <bits/stdc++.h>
using namespace std;

bool isPerfect (int n){
	int p, sum = 0;
	
	for (int i = 1; i < n; i= i + 1){
		p = n % i;
		if (p == 0){ 
		sum = sum + i;
	}
		if (sum == n){	
			return true;
		}	
	}
	return false;	
}

bool isPerfectSquare (int n){
    int sq = 1;
    
    for (int i= 1; i <= n; i= i + 1){
    	sq = i*i;
    	if (sq == n)
    	return true;
	}
	return false;
	}
	
bool isPrime (int n){
    for (int i = 2; i <= n/2; i = i + 1){
    	if (n % i == 0)
    	return false;
	}
	return true;
	}
	
bool isSphenic (int n){
	int i, count = 0, product = 1, half;
	half = n / 2;
	
	for (i = 2; i <= half; i = i + 1){
		if (n % i == 0 && isPrime(i) == true){
			product = product * i;
			count = count + 1;
		}
	}
	if (count == 3 && product == n){
		return true;
	} 
	else {
		return false;
	}

}
	
int binary (int n){
	int remainder, binaryNum = 0, i = 1;
	
	while (n != 0){
		remainder = n % 2;
		n = n / 2;
		binaryNum = binaryNum + remainder * i;
		i = i * 10;
	}
	return binaryNum;
}

int mostF (int validNum[], int num_valid){ 
    sort(validNum, validNum + num_valid); 
    
    int max_counter = 1, r = validNum[0], current_counter = 1; 
    for (int i = 1; i < num_valid; i++) { 
        if (validNum[i] == validNum[i - 1]) 
            current_counter++; 
        else { 
            if (current_counter > max_counter) { 
                max_counter = current_counter; 
                r = validNum[i - 1]; 
            } 
            current_counter = 1; 
        } 
    } 
    if (current_counter > max_counter) 
    { 
        max_counter = current_counter; 
        r = validNum[num_valid - 1]; 
    } 
    return r; 
}

int leastF(int validNum[], int num_valid){ 
    sort(validNum, validNum + num_valid); 
  
    int min_counter = num_valid+1, r = -1, current_counter = 1; 
    for (int i = 1; i < num_valid; i++) { 
        if (validNum[i] == validNum[i - 1]) 
            current_counter++; 
        else { 
            if (current_counter < min_counter) { 
                min_counter = current_counter; 
                r = validNum[i - 1]; 
            } 
            current_counter = 1; 
        } 
    } 
    if (current_counter < min_counter) 
    { 
        min_counter = current_counter; 
        r= validNum[num_valid - 1]; 
    } 
    return r; 
} 

	
int main (){
		
	int i, n, j = 0, num_valid = 0, num_invalid = 0, std_valid = 0, std_invalid = 0, std_ns = 0, not_specified, is_Binary, most_freq, least_freq;
	bool is_Perfect, is_PerfectSquare, is_Prime, is_Sphenic;  

	ifstream input;	 	
	input.open("numbers.txt");
	
	if (!input.is_open()) {
		cout << "Error opening input file." << endl;
		return 0;
	}
	
	input >> n; 

	while (n != -1){
		
		if ((n > 0) && (n <= 100)){
			num_valid = num_valid + 1;
						 
		}
		else{ if ((n < 0) || (n > 100)){	
		num_invalid = num_invalid + 1; 
		}
	}
    	if (n == 0){
		not_specified = not_specified + 1;
		}				
		input >> n;
	}

    input.close();

	int validNum[num_valid];
	int invalidNum[num_invalid];
	int s = 5;
	int one_to_ten = 0, eleven_to_twenty = 0, twentyone_to_thirty = 0, thirtyone_to_fourty = 0, fourtyone_to_fifty = 0, fiftyone_to_sixty = 0, sixtyone_to_seventy = 0, seventyone_to_eighty = 0, eightyone_to_ninety = 0, ninetyone_to_onehundred = 0;
 	
	input.open("numbers.txt");
	
	if (!input.is_open()) {
		cout << "Error opening input file." << endl;
		return 0;
	}
	
	input >> n;
	
	while (n != -1){
		
		if ((n > 0) && (n <= 100)){
		validNum[std_valid] = n;
		std_valid = std_valid + 1;		 
	}
		else{ if ((n < 0) || (n > 100)){		
		invalidNum[std_invalid] = n;
		std_invalid = std_invalid + 1;	
		}	
	}		
		input >> n;
	}
	
	cout << "Number" << "\t\t" << "Perfect?" << "\t\t" << "Prime?" << "\t\t" << "Perfect Square?" << "\t\t" << "Sphenic?" << "\t\t" << "Binary Equiv." << endl;
	cout << "======" << "\t\t" << "========" << "\t\t" << "======" << "\t\t" << "===============" << "\t\t" << "========" << "\t\t" << "=============" << endl; 	
	
	for (i=0; i<num_valid; i=i+1){
		
		cout << validNum[i];
		
		n = validNum[i];
		is_Perfect = isPerfect (n);
		
		if (is_Perfect == true){
			cout << "\t\t" << "Y";
		}
		else {
			cout << "\t\t" << "N";
		}
		
		is_Prime = isPrime (n);
		
		if (is_Prime == true){
			cout << "\t\t" << "\t" << "Y";
		}
		else {
			cout << "\t\t" << "\t" <<"N";
		}		
		
		is_PerfectSquare = isPerfectSquare (n);
		
		if (is_PerfectSquare == true){
			cout << "\t\t" << "Y";
		}
		else {
			cout << "\t\t" << "N";
		}
		
		is_Sphenic = isSphenic (n);
		
		if (is_Sphenic == true){
			cout << "\t\t" << "\t" << "Y";
		}
		else {
			cout << "\t\t" << "\t" << "N";
		}
		
		is_Binary = binary (n);
		
		cout << "\t\t" << "\t" << is_Binary;		
        cout << endl;
	}

    cout << endl;
    cout << "Invalid Numbers:";
    cout << endl; 
    
    for (i = 0; i < num_invalid; i = i + 1){
    	cout << invalidNum[i] << "\t";
    	j = j + 1;  	
    	if (j % 5 == 0){
    		cout << endl;
		}
	}
	
	cout << endl;
	cout << endl;
	
    input.close();

	input.open("numbers.txt");
	
	if (!input.is_open()) {
		cout << "Error opening input file." << endl;
		return 0;
	}
	
	input >> n;
	
	while (n != -1){
		if ((n >= 1) && (n <= 10)){
			one_to_ten += 1; 
		}
		if ((n >= 11) && (n <= 20)){ 
			eleven_to_twenty += 1; 
		}
		if ((n >= 21) && (n <= 30)){
			twentyone_to_thirty += 1; 
		}
		if ((n >= 31) && (n <= 40)){
			thirtyone_to_fourty += 1; 
		}
		if ((n >= 41) && (n <= 50)){
			fourtyone_to_fifty += 1; 
		}
		if ((n >= 51) && (n <= 60)){
			fiftyone_to_sixty += 1; 
		}
		if ((n >= 61) && (n <= 70)){
			sixtyone_to_seventy += 1; 
		}
		if ((n >= 71) && (n <= 80)){
			seventyone_to_eighty += 1; 
		}
		if ((n >= 81) && (n <= 90)){
			eightyone_to_ninety += 1; 
		}
		if ((n >= 91) && (n <= 100)){
			ninetyone_to_onehundred += 1; 
		}	
		input >> n;
	}
	
	cout << "Range" << "\t\t" << "Histogram" << endl;
	cout << "==============================" << endl;
	cout << "1-10" << "\t\t";
	for (s = 5; one_to_ten >= s; s = s + 0){
		one_to_ten = one_to_ten - 5;
		cout << "*";
	} 
	cout << endl;
    cout << "11-20" << "\t\t";
    for (s = 5; eleven_to_twenty >= s; s = s + 0){
		eleven_to_twenty = eleven_to_twenty - 5;
		cout << "*";
	} 
    cout << endl;
	cout << "21-30" << "\t\t";
    for (s = 5; twentyone_to_thirty >= s; s = s + 0){
		twentyone_to_thirty = twentyone_to_thirty - 5;
		cout << "*";
	}
	cout << endl;
	cout << "31-40" << "\t\t";
    for (s = 5; thirtyone_to_fourty >= s; s = s + 0){
		thirtyone_to_fourty = thirtyone_to_fourty - 5;
		cout << "*";
	}
	cout << endl;
	cout << "41-50" << "\t\t";
    for (s = 5; fourtyone_to_fifty >= s; s = s + 0){
		fourtyone_to_fifty = fourtyone_to_fifty - 5;
		cout << "*";
	}
	cout << endl;
	cout << "51-60" << "\t\t";
    for (s = 5; fiftyone_to_sixty >= s; s = s + 0){
		fiftyone_to_sixty = fiftyone_to_sixty - 5;
		cout << "*";
	}
	cout << endl;
	cout << "61-70" << "\t\t";
    for (s = 5; sixtyone_to_seventy >= s; s = s + 0){
		sixtyone_to_seventy = sixtyone_to_seventy - 5;
		cout << "*";
	}
	cout << endl;
	cout << "71-80" << "\t\t";
    for (s = 5; seventyone_to_eighty >= s; s = s + 0){
		seventyone_to_eighty = seventyone_to_eighty - 5;
		cout << "*";
	}
	cout << endl;
    cout << "81-90" << "\t\t";
    for (s = 5; eightyone_to_ninety >= s; s = s + 0){
		eightyone_to_ninety = eightyone_to_ninety - 5;
		cout << "*";
	}
    cout << endl;
	cout << "91-100" << "\t\t";
    for (s = 5; ninetyone_to_onehundred >= s; s = s + 0){
		ninetyone_to_onehundred = ninetyone_to_onehundred - 5;
		cout << "*";
	}
	cout << endl;
	cout << endl;
	
	cout << "Amount of students who specified valid favorite numbers: " << num_valid << endl;
	cout << "Amount of students who specified invalid favorite numbers: " << num_invalid << endl;
	cout << "Amount of students who did not specify a favorite number: " << not_specified << endl;
	most_freq = mostF(validNum, num_valid);
	least_freq = leastF(validNum, num_valid);
	cout << "Most chosen number: " << most_freq << endl;
	cout << "Least chosen number: " << least_freq << endl;   

	input.close();
	return 0;
}
