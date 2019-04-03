#include <iostream>
#include <bits/stdc++.h> 
#include <fstream>
#include <cmath>
using namespace std;

const int MAX = 100;

bool isPrime (int n) {
	int i;
	for (i = 2; i < n; i++){
		if (n % i == 0){
			return false;
		}	
	}
	if (n == 1){
		return false;
	}
	else {
		return true;
	}
}

bool isPerfect (int n){
	int i, div, sum=0;
    for (i=1; i < n; i++){
        div = n % i;
        if (div == 0)
            sum = sum + i;
    }
    if (sum == n){
        return true;
	}
	else{
        return false;
	}
}


bool isPerfect_Square (int n){
  for (int i = 1; i <= n; i++){
  	if (i*i == n){
  		return true;
  	}
	else if (i * i > n) {
		return false;
	} 	
  }
}

bool isSphenic (int n){
	int i, a, b, c;
	for (i = 1; i <= n; i++){
		if (isPrime(i)){
			if ((i != a) || (i != b) || (i != c)){
				a = i;
			}
		}
	}

	
}

void inBinary (int n){
	ofstream output;
	int i = 0, store[7], j;
	while (i <= 8){
		store [ i ] = n % 2;
		i++;
		n = n/2;
	}
	output.open("output.txt");
	if (!output.is_open()) {

		cout << "Error opening output file. Aborting ...";
	}
	
	output << store[7] << store[6] << store[5] << store[4] << store[3] << store[2] << store[1] << store[0] << endl;	
} 

int Popular (int arr[], int n){
    sort(arr, arr + n); 
  
    // find the max frequency using linear traversal 
    int max_count = 1, pop = arr[0], curr_count = 1; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] == arr[i - 1]) {
        
            curr_count++; 
    	}
		else { 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                pop = arr[i - 1]; 
            } 
            curr_count = 1; 
        } 
    } 
  
    // If last element is most frequent 
    if (curr_count > max_count) 
    { 
        max_count = curr_count; 
        pop = arr[n - 1]; 
    } 
  return pop;
}  

int Unpopular (int arr[], int n){
	 // Sort the array 
	sort(arr, arr + n); 
  
    // find the min frequency using linear traversal 
    int min_count = n+1, unpop = -1, curr_count = 1; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] == arr[i - 1]) {
            curr_count++; 
    	}
        else { 
        	for (int j = 0; j <= n; j++){
            	if (curr_count < min_count) { 
                	min_count = curr_count; 
                	unpop = arr[i - 1]; 
                	break;
            	}
        	}
			curr_count = 1; 
        } 
	  
    } 
   
    // If last element is least frequent 
    if (curr_count < min_count) 
    { 
        min_count = curr_count; 
        unpop = arr[n - 1]; 
    } 
    return unpop;
}


int main ()

{

	ifstream input;

	ofstream output;
	
	int valid_num = 0, invalid_num = 0, blank_num = 0, num_students = 0;
	
	int fav_num; //data entries
	
	int post_0, post_10, post_20, post_30, post_40, post_50, post_60, post_70, post_80, post_90;
	
	bool Prime, Perfect, Perfect_Square, Sphenic;
	
	int Binary;
	
	input.open("numbers.txt");

	output.open("output.txt");

	if (!input.is_open()) {

		cout << "Error opening input file. Aborting ...";

		return 0;

	}

	if (!output.is_open()) {

		cout << "Error opening output file. Aborting ...";

		return 0;

	}
	
	output << "Number" << setw(15) << "Perfect?" << setw(15) << "Prime?" << setw(15) << "Perfect Square?" << setw(20) << "Sphenic?" << setw(15) << "Binary Equiv." << endl;
	output << "==============================================================================================================================" << endl;
	output << "" << endl;
	input >> fav_num;
    
	while (fav_num != -1) {
		if ((fav_num > 1) || (fav_num < 100)) { 
			valid_num++;
		}
		else if ((fav_num > 100 ) || (fav_num < -1)){
			invalid_num++;
			input >> fav_num;
			num_students++;
			continue;
		}
		else if (fav_num = 0){
			blank_num++;
			input >> fav_num;
			num_students++;
			continue;
		}
	}
	
    input.close();
	
	
	int invalid_set [invalid_num], chosen_set [valid_num];
		
	for (int g = 0; g <= num_students; g++){
		if ((fav_num > 100 ) || (fav_num < -1)){
			invalid_num++;
			input >> fav_num;
			invalid_set [g] = fav_num;
		}
		g++;
	}
	for (int y = 0; y < num_students; y++){
		if ((fav_num < 100 ) || (fav_num > 1)){
			valid_num++;
			input >> fav_num;
			chosen_set [y] = fav_num;
		}
		y++;
	}
	
	for (int l = 0; l < valid_num; l++){
		output << fav_num << setw(15);
		Prime = isPrime(fav_num);
		Perfect = isPerfect(fav_num);
		Perfect_Square = isPerfect_Square(fav_num);
		Sphenic = isSphenic(fav_num);
		if (Perfect) {
			output << "Y" << setw(15);
    	}		
    	else {
    		output << "N" << setw(15);
    	}
		if (Prime) {
			output << "Y" << setw(15);
		}
		else {
    		output << "N" << setw(15);
    	}
  		if (Perfect_Square) {
    		output << "Y" << setw(20);
		}
		else {
    		output << "N" << setw(15);
    	}
    	
		if (Sphenic) {
    		output << "Y" << setw(15);
		}
    	else {
    		output << "N" << setw(15);
    	}
    	
		inBinary(fav_num);
		num_students++;
	}	 
	for (int k = 0; k < invalid_num; k++){
		output << invalid_set[k] << " ";
		if ((k + 1) % 5){
			endl;
		}
	}
	
	output << "Range" << setw(30) << "Histogram" << endl;
	output << "========================================================================" << endl;
	output << "" << endl;
	
	for (int z = 0; z < valid_num; z++){
		output << "1 - 10" << setw(30) << ":";
		
	if ((chosen_set[z] >= 1) || (chosen_set[z] <= 100)) { 
		
	}
	else{
		
	}
	}
	
	numbers[num_students] = fav_num;
	output << "" << endl;	
	output << "" << endl;
	output << "Number of Students Specifying Valid Numbers = " << valid_num << endl;
	output << "Number of Students Specifying Invalid Numbers = " << invalid_num << endl;
	output << "Number of Students that didn't answer = " << blank_num << endl;
	output << "The most common number/s chosen was/were " << Popular(chosen_set[], num_students) << endl;
	output << "The least common number/s chosen was/were " << Unpopular(chosen_set[], num_students) << endl;
    output.close();
    return 0;
}
