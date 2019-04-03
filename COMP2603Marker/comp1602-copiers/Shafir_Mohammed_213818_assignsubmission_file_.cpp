// Name: Shafir Mohammed
// ID#: 813000698
// Assignment: 1

#include <iostream>
#include <fstream>
using namespace std;

bool perfect(int);
bool prime(int);
bool psquare(int);
bool sphenic(int n);
void bin(int);

int main (){
	ifstream in;
	
	int invalidarr[300]; // array to store invalid numbers
	int validarr[300]; // array to store valid numbers
	int mostchoosen[300]; // array to store numbers most choosen 
	int leastchoosen[300]; // array to store numbers least choosen
	
	int fav, validcount=0, invalidcount=0, nreveal=0, i=0, j=0, k=0, m=0;
	int p=0, x=0, tstore=0, count1=0, count=0, printc1=0, printc2=0, prev1=0, prev2=0;
	int s=0, h=0, tstore2=0, count2=0;
	int r1=0, r2=0, r3=0, r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0; // declaration for each range of histogram
	
	char isperf, isprime,issquare,issphenic; // char temp storage declaration for table
	
	in.open("numbers.txt");
	
	if(!in.is_open()){ // file open test
		cout << "Error opening file..." << endl;
		return 0;
	}
	cout << "Number\t\tperfect\t\tprime\t\tPerfect Square\t\tSphenic\t\tBinary Equiv."<< endl;
	cout << "======\t\t=======\t\t=====\t\t==============\t\t=======\t\t============="<< endl;
	
	in >> fav;
	while(fav != -1){ // while to read through file
		
		if (fav >=0 && fav <=100){

			validarr[k] = fav; // store valid number into an array for later use 
			
			if(fav == 0){ // to find number of student who didn't reveal their fav number
				nreveal++;
			} // end if
			
			if (perfect(fav)) // if to find if number is perfect using the function
			isperf = 'Y';
			else 
			isperf = 'N';
		
			if (prime(fav)) // if to find if number is perfect using the function
			isprime = 'Y';
			else 
			isprime = 'N';
			
			if (psquare(fav)) // if to find if number is perfect square using the function
			issquare = 'Y';
			else 
			issquare = 'N';
			
			if (sphenic(fav)) // if to find if number is sphenic using the function
			issphenic = 'Y';
			else 
			issphenic = 'N';
			
			validcount++; // counter for number of valid values
			k++; // array counter
			
			
			cout << fav <<"\t\t"<< isperf << "\t\t" << issquare << "\t\t" << issquare << "\t\t\t" << issphenic << "\t\t";
			bin(fav);
			cout << endl;	
		}
		else{
			invalidarr[i] = fav; // store all invalid numbers into an array for later use
			i++; // count for array
			invalidcount++; // count to find number of invalid numbers 
		}
		
		in >> fav; // read val from file 
	}
	
	cout << endl;
	
	cout << "Invalid Numbers: " << endl;
	
	for(j=i-1 ; j>-1 ; j=j-5){ // display invalid numbers 5 per line
		cout << invalidarr[j]<< " " << invalidarr[j-1] << " " << invalidarr[j-2] << " " << invalidarr[j-3] << " " << invalidarr[j-4] << endl;
	} // end for
	
	for(m=0 ; m<k ; m++){ // counts for each range of numbers 
		
		if(validarr[m] >= 0 && validarr[m] <=10){ // if to count number of vals between 0 - 10
			r1++;
		} // end if 
		
		if(validarr[m] >=11 && validarr[m] <=20){ // if to count number of vals between 11 - 20
			r2++;
		} // end if 
		
		if(validarr[m] >= 21 && validarr[m] <=30){ // if to count number of vals between 21 - 30
			r3++;
		} // emd if 
		
		if(validarr[m] >= 31 && validarr[m] <=40){ // if to count number of vals between 31 - 40
			r4++;
		} // end if 
		
		if(validarr[m] >= 41 && validarr[m] <=50){ // if to count number of vals between 41 - 50
			r5++;
		} // end if 
		
		if(validarr[m] >= 51 && validarr[m] <=60){ // if to count number of vals between 51 - 60
			r6++;
		} // end if 
		
		if(validarr[m] >= 61 && validarr[m] <=70){ // if to count number of vals between 61 - 70
			r7++;
		} // end if 
		
		if(validarr[m] >= 71 && validarr[m] <=80){ // if to count number of vals between 71 - 80
			r8++;
		} // end if 
		
		if(validarr[m] >= 81 && validarr[m] <=90){ // if to count number of vals between 81 - 90
			r9++;
		} // end if 
		
		if(validarr[m] >= 91 && validarr[m] <=100){ // if to count number of vals between 91 - 100
			r10++;
		} // end if 
	} // end for 
	
	int mostcounter=0;
	for(p=0 ; p<k ; p++){ // to find numbers choosen the most
		if(validarr[p] > 0) // to remove "0" from the test
			tstore = validarr[p];
	
		for(x=0 ; x<k ; x++){
			if(validarr[x] > 0 && validarr[x] == tstore){
				count1++;
			} // end if 
			
			if(count1 > 2){
				mostchoosen[mostcounter] = count1;
				mostcounter++;
			} // end if 
		}// end for 	
	}// end for 
	
	
	int leastcounter = 0;
	for(s=0 ; s<k ; s++){ // to find numbers choosen the least 
		if(validarr[s] > 0) // to remove "0" from the test 
			tstore2 = validarr[s];
		
		for(h=0 ; h<k ; h++){
			if(validarr[h > 0 && validarr[h] == tstore2]){
				count2++;
			} // end if 
				
			if(count2 == 1){
				leastchoosen[leastcounter] = count2;
				leastcounter++;
			} // end if 
		} // end for 
	} // end for 
	
	
	cout << endl;
	cout << "Range\t\t\tHistogram"<< endl;
	cout << "=====\t\t\t========="<< endl;
	
	// to print histogram
	cout << "1-10\t\t\t";
	for(i=1 ; i <=r1 ; i=i+5){
		cout << "*";
	}
	
	cout << endl;
	
	cout << "11-20\t\t\t";
	for(i=1 ; i <=r2 ; i=i+5){
		cout << "*";
	}
	
	cout << endl;
	
	cout << "21-30\t\t\t";
	for(i=1 ; i <=r3 ; i=i+5){
		cout << "*";
	}
	
	cout << endl;
	
	cout << "31-40\t\t\t";
	for(i=1 ; i <=r4 ; i=i+5){
		cout << "*";
	}
	
	cout << endl;
	
	cout << "41-50\t\t\t";
	for(i=1 ; i <=r5 ; i=i+5){
		cout << "*";
	}
	
	cout << endl;
	
	cout << "51-60\t\t\t";
	for(i=1 ; i <=r6 ; i=i+5){
		cout << "*";
	}
	
	cout << endl;
	
	cout << "61-70\t\t\t";
	for(i=1 ; i <=r7 ; i=i+5){
		cout << "*";
	}
	
	cout << endl;
	
	cout << "71-80\t\t\t";
	for(i=1 ; i <=r8 ; i=i+5){
		cout << "*";
	}
	
	cout << endl;
	
	cout << "81-90\t\t\t";
	for(i=1 ; i <=r9 ; i=i+5){
		cout << "*";
	}
	
	cout << endl;
	
	cout << "91-100\t\t\t";
	for(i=1 ; i <=r10 ; i=i+5){
		cout << "*";
	}
	
	// end histogram
	
	cout << endl;
	
	cout << "Number of Students who specified valid numbers: " << validcount << endl;
	cout << "Number of Students who specified invalid numbers: " << invalidcount << endl;
	cout << "Number of Students who didn't reveal their favourite number: " << nreveal << endl;
	
	cout << endl;
	
	cout << "Numbers choosen most by students: "; 
	for(printc1 = 0 ; printc1 < mostcounter ; printc1++){ // remove duplicates 
		if(mostchoosen[printc1] != prev1){
			cout << mostchoosen[printc1] << " ";
		}
		prev1 = mostchoosen[printc1];
	}// end for 
	
	cout << endl << endl;
	
	cout << "Numbers choosen least by students: ";
	for(printc2 = 0 ; printc2 < leastcounter ; printc2++){ // remove duplicates 
		if(leastchoosen[printc2] != prev2){
			cout << leastchoosen[printc2] << " ";
		}
		prev2 = leastchoosen[printc2];
	} // end for 
	
	cout << endl;
	
	in.close();
	
	return 0;
} // end main


// functions
bool perfect(int n){ // function to determine if number is perfect
	int i, sum=0;
	
	for(i=1 ; i<n ; i++){
		if(n % i == 0){
			sum = sum + i;
		} // end if
	} // end for
	
	if(sum == n)
		return true;
	else 
		return false;
}// end perfect

bool prime(int n){ // function to determine if number is prime
	int i;
	bool test = true;
	
	for(i=2 ; i < n ; i++){
		if(n % i == 0){
			test = false;
			break;
		} // end if
	} // end for
	
	if(test)
		return true;
	else 
		return false;
}// end prime

bool psquare(int n){ // function to determine if number is perfect square
	int i;
	bool test = false;
	
	for(i=1 ; i<= n/2 ; i++){
		if(i*i == n){
			test = true;
		} // end if  
	} // end for 
	
	if(test)
		return true;
	else 
		return false;
} // end psquare

void bin(int n){ // function to convert to binary
	int i, j=0, k;
	int store [10];
	
	for(i=0 ; i<10 ; i++){ // clears array each time
		store[i] = 0;
	} // end for
	
	while(n != 0){
		store[j] = n % 2;
		n = n / 2;
		j++;
	}
	
	for(k=j-1 ; k>-1 ; k--){
		cout << store[k];
	}
} // end bin

bool sphenic(int n){ // function to determine if number is sphenic
	int i, product=1, m=0;
	
	for(i=2 ; i <= n/2 ; i++){
		if(n%i == 0 && prime(i)){
			product = product * i;
			m++;
		} // end if 
	} // end for 
	
	if(m==3 && product == n)
		return true;
	else 
		return false;
} // end sphenic 

// end of functions 
