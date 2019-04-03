#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


bool isValid(int a) {
	if ((a > 0) && (a < 101)) 
		return true;
		
	return false;
}


bool isPerfect(int favNum) {
	int i;
	int div = 0;
	
	for (i = 1; i <= (favNum/2); i++) {
		if (favNum % i == 0) 
			div = div + i;
			
	}
		
		if (favNum == div) 
			return true;
			
	return false;		
}


bool isPrime(int favNum){
	int i;
	
	for (i = 2; i <= favNum/2; i++){
		if (favNum % i == 0)
			return false;
	
	}
	
	return true;
}


bool isPerfectSquare(int favNum) {
	int i, sq;
	
	if (favNum == 1)
		return true;
		
	for (i = 2; i <= favNum/2; i++){
		sq = i * i;
		
		if (sq == favNum) 
			return true;
	}
	
	return false;
}


bool isSphenic(int favNum){
	int i, count, product;
	
	product = 1;
	count = 0;
	
	for (i = 2; i <= favNum/2; i++ ){
		if (  favNum % i  == 0 && isPrime(i) ) {
			product = product * i;
			count = count + 1;
		}
	}
	
	if (count == 3 && product == favNum)
		return true;
	else
		return false;
}


int findBit(int favNum) {
	int i, rem;
	
	rem = favNum % 2;
	
	return rem;
}


int main () {
	int valNum[1000];
	int invalNum[1000]; 
	int bitArray[8];
	int num, valid, distinct, perf, prime, perfSq, sphen, binEquiv;
	int notSpecified = 0;
	int totVal = 0;
	int totInval = 0;
	int totDist;
	int i = 0;
	int v= 0;
	int iv = 0;
	
	
	ifstream in;
	
	in.open("numbers.txt");
	
	if (!in.is_open() ) {
		cout << "File not found.";
		return 0;
	}	
	
	
	in >> num;
	
	while (num != -1){
		
		if (num == 0) 
			notSpecified++;
	
		
		valid = isValid(num);
		
		if (valid == true) { 
			valNum[v] = num;

			totVal++;
			v++;
			
		}
		else {
			if ((valid == false) && (num != 0)){
				invalNum[iv] = num;
			
				totInval++;
				iv++;
			}
		}
	
		
		in >> num;
	}
	
	//to determine all the distinct number	
	totDist = totVal;
	int distNum[totDist];
	
	for (i = 0; i < totVal; i = i + 1 ) {
		distNum[i] = valNum[i];
		
	}
	
	for (i = 0; i < totDist; i++) {
		
		distinct = 1;
		
		for (int j = i + 1; j < totDist; j++) {
			
			if (distNum[i] == distNum[j]) {
				
				for(int k = j; k < (totDist - 1); k++)
					distNum[k] = distNum[k + 1];
					 
				totDist--;
				j--;
				distinct = 0;
			}
		}
		
		if (distinct != 1) {
			for (int j = i; j < (totDist - 1); j++)
				distNum[j]  = distNum[j + 1];
				
			totDist--;
			i--;
		}
	}
	

	cout << "Number" << "		" << "Perfect?" << "	" << "Prime?" << "		" << "Perfect Square?" << "		" << "Sphenic?" << "	" << "Binary Equiv." << endl;
	cout << "======" << "		" << "========" << "	" << "======" << "		" << "===============" << "		" << "========" << "	" << "=============" << endl << endl;
	
	for (i = 0; i < totDist; i++) {
	
		cout << distNum[i];
		
		
		perf = isPerfect(distNum[i]);
		if (perf == true) 
			cout << "		" << "Y";
			
		else 
			cout << "		" << "N";
		
			
		prime = isPrime(distNum[i]);
		if (prime == true) 
			cout << "		" << "Y";
			
		else 
			cout << "		" << "N";
		
		
		perfSq = isPerfectSquare(distNum[i]);
		if (perfSq == true) 
			cout << "		" << "Y";
			
		else 
			cout << "		" << "N";
		
		
		sphen = isSphenic(distNum[i]);
		if (sphen == true) 
			cout << "			" << "Y		";
			
		else 
			cout << "			" << "N		";
			
		
		int favNum = distNum[i];
		
		for (int j = 0; j < 8; j++) {
			bitArray[j] = findBit(favNum);
			favNum = favNum/2;	
		}
		
		for (int j = 7; j >= 0; j--)
			cout << bitArray[j];
		
		cout << endl;
			
	}
 	
 	
	cout << "----------------------------------------------------------------------------------------------------------";
	cout << endl << endl;	
	
	//To display invalid numbers
	cout << "INVALID NUMBERS" << endl << endl;
	for (i = 0; i < totInval; i = i + 5) {
		int a = i + 1;
		int b = i + 2;
		int c = i + 3;
		int d = i + 4;
		
		if (i < totInval-5)
			cout << invalNum[i] << "       " << invalNum[a] << "       " << invalNum[b] << "      " << invalNum[c] << "       " << invalNum[d] << endl; 
		else
			cout << invalNum[i] << "       " << invalNum[a] << "       " << invalNum[b] << "      " << invalNum[c] << endl;
	}

	
	cout << "----------------------------------------------------------------------------------------------------------";
	cout << endl << endl;	
	
	//To determine the total amount of numbers that fall within ranges of 10 numbers (from 1 to 100)
	int rangeArr[10];
	int starNum;
	
	for (int range = 0; range < 10; range++ ) {
		rangeArr[range] = 0;
	}
	
		
	for (i = 0; i < totVal; i++) {
			
		if ( (valNum[i] > 0) && (valNum[i] < 11) ) 
			rangeArr[0]++;
			
		else {
			if ( (valNum[i] > 10) && (valNum[i] < 21) ) 
				rangeArr[1]++;
			
			else {
				if ( (valNum[i] > 20) && (valNum[i] < 31) ) 
					rangeArr[2]++;
				
				else {
					if ( (valNum[i] > 30) && (valNum[i] < 41) ) 
						rangeArr[3]++;
						
					else {
						if ( (valNum[i] > 40) && (valNum[i] < 51) ) 
							rangeArr[4]++;
							
						else{
							if ( (valNum[i] > 50) && (valNum[i] < 61) ) 
								rangeArr[5]++;
								
							else {
								if ( (valNum[i] > 60) && (valNum[i] < 71) ) 
									rangeArr[6]++;
									
								else {
									if ( (valNum[i] > 70) && (valNum[i] < 81) ) 
										rangeArr[7]++;
										
									else {
										if ( (valNum[i] > 80) && (valNum[i] < 91) ) 
											rangeArr[8]++;
											
										else {
											if ( (valNum[i] > 90) && (valNum[i] < 101) ) 
												rangeArr[9]++;
												
										}
									}
								}
							}
						}
					}
				}
			}
		}		
	}
	
	//To create histogram 	
	cout << "Range		Histogram" << endl;
	cout << "=========================" << endl;
	
	for (int range = 0; range < 10; range++) {
		
		if (range == 0)
			cout << "1-10		|";
			
		else {
			if (range == 1)
				cout << "11-20		|";
				
			else {
				if (range == 2)
					cout << "21-30		|";
				
				else {
					if (range == 3)
						cout << "31-40		|";
						
					else {
						if (range == 4)
							cout << "41-50		|";
							
						else {
							if (range == 5)
								cout << "51-60		|";
								
							else {
								if (range == 6)
									cout << "61-70		|";
									
								else {
									if (range == 7)
										cout << "71-80		|";
										
									else {
										if (range == 8)
											cout << "81-90		|";
											
										else {
											if (range == 9)
												cout << "91-100		|";
			
										}
			
									}
			
								}
			
							}
			
						}
			
					}
			
				}
			
			}
			
		}
		
		//outputs a "*" for every 5 students in each category		
		starNum = rangeArr[range]/5;
		
		for (i = floor(starNum); i > 0; i--) 
			cout << "*";
			
		cout << endl;
	}
	

	cout << "----------------------------------------------------------------------------------------------------------";
	cout << endl << endl;	
	
	cout << "Amount of students who specified valid favourite numbers = " << totVal << endl;
	cout << "Amount of students who specified invalid favourite numbers = " << totInval << endl;
	cout << "Amount of students who did not specify a favourite number = " << notSpecified << endl << endl;
	
	cout << "The numbers that were chosen the most by students are: " << endl;
	
	for (i = 0; i < totVal; i++) {
	
		for (int j = i+1; j < totVal; j++) {
			
			if (valNum[i] == valNum[j])
				cout << valNum[i] << endl; 
				
		} 
	}
	
	cout << endl;
	cout << "The numbers that were chosen the least by students are: " << endl;
	
	for (i = 0; i < totDist; i++) 
		cout << distNum[i] << endl;



	
	in.close();
}
