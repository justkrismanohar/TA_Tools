#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// FUNCTIONS :


void PrintStar(float amt_of_stars){
	int k;
	for(k=0; k<amt_of_stars; k++){
		cout<<"*";
	}
	
	
}



bool isPerfect(int number){
	int i, sum=0, divisor;
	for(i=1; i<=number; i++){
		divisor = number%i;
		if(divisor == 0)
		sum = sum + i;
	}
	
	if(sum==number)
	return true;
	else
	return false;
	
	
}



bool isValid(int number){
	if((number==0) || (number>=1) && (number <= 100))
	return true;
	else
	return false;
}





bool isPrime(int number){
	int x, prime;
	for(x=2;x<=number*0.5;x++){
		prime = number%x;
		if(prime==0)
		return false;
		else
		return true;
	
	}
}
	
	
	
	
	
bool isPerfectSquare(int number){
	int x, sqr;
	for(x=0;x<=number*0.5;x++){
		sqr=x*x;
		if(sqr==number)
		return true;
		else
		return false;
	}
}



bool isSphenic(int number){
	int x, prod, count;
	for(x=2;x<=number*0.5;x++){
		if((number%x==0)&&(isPrime(x))){
			prod= prod*x;
			count=count + 1;
		}
		if((prod==number)&&(count==3))
		return true;
		else
		return false;
	}
}




int toBinary(int number){
	int binary=0, rem, x=1;
	while(number!=0){
		rem = number%2;
		number = number/2;
		binary = binary + (rem*x);
		x=x*10;
	}
	
	return binary;
}
	


// MAIN PROGRAM :



int main(){
	int Valid[9999];
	int Invalid[9999];
	float Star_One, Star_two, Star_three, Star_four, Star_five,Star_six, Star_seven, Star_eight, Star_nine, Star_ten;
	int Range1=0, Range2=0, Range3=0, Range4=0, Range5=0, Range6=0, Range7=0, Range8=0, Range9=0, Range10=0;
	int z=0;
	int Valid_Numbers[999];
	int Invalid_Numbers[999];
	int NUMBER;
	int Most_chosen;
	int Amount_of_Numbers;
	int v, s;
	int Num=0;
	ifstream input;
	ifstream INPUT;
	int Random;
	int Zero_count = 0;
	int valid_count = 0;
	int Invalid_count = 0;
	int num, NUM;
	int a, f;
	int valid, invalid;
	char is_it_perfect;
	char is_it_perfect_sqr;
	char is_it_sphenic;
	char is_it_prime;
	int BinaryNumber;
	int i = 0;
	int Count=1;
	int Array_count[123];
	int Normal_count;
	int MOST, LEAST;
	int m, n, j, h, u;
	int Least_chosen;
	
	
	input.open("numbers.txt");
	if(!input.is_open()){
		cout<<"Error in opening file! Terminating. 1)"<<endl;
		return 0;
	}
	
	
	
	f=0;
	input>>Valid[f];
	
	
	cout<<"Number \t "<<"   Perfect? \t "<<"   Prime? \t "<<"Perfect Square? \t "<<"Sphenic? \t "<<"Binary Equivalent"<<endl;
	cout<<"====== \t "<<"   ======== \t "<<"   ====== \t "<<"=============== \t "<<"======= \t "<<"================"<<endl;
	
	
	while(!input.eof()){
	if(Valid[f]==0)
	Zero_count++;
	
	
	if(isValid(Valid[f])){
	valid_count = valid_count + 1;
	
	
	
	if(isPerfect(Valid[f]))
	is_it_perfect='Y';
	else
	is_it_perfect='N';

    
	
	
	
	if(isPrime(Valid[f]))
	is_it_prime='Y';
	else
	is_it_prime='N';
	
	

	if(isPerfectSquare(Valid[f]))
	is_it_perfect_sqr='Y';
	else
	is_it_perfect_sqr='N';

	
	
	
	
	if(isSphenic(Valid[f]))
	is_it_sphenic='Y';
	else
	is_it_sphenic='N';

	
	BinaryNumber = toBinary(Valid[f]);
	cout<<Valid[f]<<"         \t "<<is_it_perfect<<"         \t "<<is_it_prime<<"        \t "<<is_it_perfect_sqr<<"        \t "<<is_it_sphenic<<"       \t "<<BinaryNumber<<endl;
}
else{
	input>>Invalid[f];
}

	
	
	


    
	input>>Valid[f];
	
	

}


cout<<" "<<endl;
cout<<" "<<endl;
cout<<" "<<endl;

input.close();

input.open("numbers.txt");
if(!input.is_open())
cout<<"Error in opening file! Terminating 2)"<<endl;

 
input>>NUM;
Invalid_count = 0;

cout<<" INVALID NUMBERS WERE FOUND TO BE : "<<endl;
cout<<" ==================================="<<endl;

while(NUM != -1){
	
	if(!isValid(NUM)==true){
	Invalid_count= Invalid_count + 1;
	cout<<NUM<<" | ";
	if((9%Invalid_count)==4){
	cout<<"  "<<endl;
}
}
	
	input>>NUM;
}

input.close();

cout<<" "<<endl;
cout<<" "<<endl;
cout<<" "<<endl;
cout<<" "<<endl;

input.open("numbers.txt");
if(!input.is_open()){

cout<<" Error in opening file! Terminating.  3)"<<endl;
return 0; 
}




input>>Num;
while(!input.eof()){
	if(isValid(Num)){
	Valid_Numbers[i]=Num;
	input>>Num;
}
else{
	Invalid_Numbers[i]=Num;
	input>>Num;
}
	i++;
}


// This keeps track of the amount of numbers that are stored within the array so that the size of the array will now be known.
Amount_of_Numbers = i;

cout<<" The amount of numbers within the the file      numbers.txt = "<<i<<endl;
cout<<" "<<endl;
cout<<" "<<endl;

// Now that we know the size of the array, we can now use a for loop to find the amount of times a number within a specific range was chosen.


for(z=0; z<= 123; z++){
	if(Valid_Numbers[z]>= 1 && Valid_Numbers[z]!=0  &&  Valid_Numbers[z]<=10)
	Range1 = Range1 + 1;
	else
	if(Valid_Numbers[z]>= 11 && Valid_Numbers[z]!=0 &&  Valid_Numbers[z]<=20)
	Range2 = Range2 + 1;
	else
	if(Valid_Numbers[z]>= 21 && Valid_Numbers[z]!=0  &&  Valid_Numbers[z]<=30)
	Range3 = Range3 + 1;
	else
	if(Valid_Numbers[z]>= 31 && Valid_Numbers[z]!=0  &&  Valid_Numbers[z]<=40)
	Range4 = Range4 + 1;
	else
	if(Valid_Numbers[z]>= 41 && Valid_Numbers[z]!=0  &&  Valid_Numbers[z]<=50)
	Range5 = Range5 + 1;
	else
	if(Valid_Numbers[z]>= 51 && Valid_Numbers[z]!=0 &&  Valid_Numbers[z]<=60)
	Range6 = Range6 + 1;
	else
	if(Valid_Numbers[z]>= 61 && Valid_Numbers[z]!=0  &&  Valid_Numbers[z]<=70)
	Range7 = Range7 + 1;
	else
	if(Valid_Numbers[z]>= 71 && Valid_Numbers[z]!=0 &&  Valid_Numbers[z]<=80)
	Range8 = Range8 + 1;
	else
	if(Valid_Numbers[z]>= 81 && Valid_Numbers[z]!=0  &&  Valid_Numbers[z]<=90)
	Range9 = Range9 + 1;
	else
	if(Valid_Numbers[z]>= 91 && Valid_Numbers[z]!=0 &&  Valid_Numbers[z]<=100)
	Range10 = Range10 + 1;
	
} 


Star_One = floor(Range1 / 5);
Star_two = floor(Range2 / 5);
Star_three = floor(Range3 / 5);
Star_four = floor(Range4 / 5);
Star_five = floor(Range5 / 5);
Star_six = floor(Range6 / 5);
Star_seven = floor(Range7 / 5);
Star_eight = floor(Range8 / 5);
Star_nine = floor(Range9 / 5);
Star_ten = floor(Range10 / 5);







cout<<" Range  \t Histogram "<<endl;
cout<<" =====  \t ========= "<<endl;
cout<<" 1-10   \t ";
PrintStar(Star_One);
cout<<" "<<endl;
cout<<" 11-20  \t ";
PrintStar(Star_two);
cout<<" "<<endl;
cout<<" 21-30  \t ";
PrintStar(Star_three);
cout<<" "<<endl;
cout<<" 31-40  \t ";
PrintStar(Star_four);
cout<<" "<<endl;
cout<<" 41-50  \t ";
PrintStar(Star_five);
cout<<" "<<endl;
cout<<" 51-60  \t ";
PrintStar(Star_six);
cout<<" "<<endl;
cout<<" 61-70  \t ";
PrintStar(Star_seven);
cout<<" "<<endl;
cout<<" 71-80  \t ";
PrintStar(Star_eight);
cout<<" "<<endl;
cout<<" 81-90  \t ";
PrintStar(Star_nine);
cout<<" "<<endl;
cout<<" 91-100  \t ";
PrintStar(Star_ten);
cout<<" "<<endl;

cout<<" "<<endl;
cout<<" "<<endl;
cout<<" "<<endl;


input.close();

input.open("numbers.txt");

if(!input.is_open()){
	cout<<"Error in opening file! Terminating 4)"<<endl;
	return 0;
}

m = 0;

for(j=0; j<=123; j++){
	Array_count[j]=0;
}




input>>NUMBER;

while(!input.eof()){
	
	
	
	for(Normal_count=0; Normal_count<=123; Normal_count++){
		if((Valid_Numbers[Normal_count]==NUMBER) && (Valid_Numbers[Normal_count]!=0)){
		Array_count[m]= Array_count[m] + 1;
		
	}
}
	m++;
	input>>NUMBER;
	
	
}


// Display the number of Valid, Invalid and Zero counts.

cout<<" The total number of students who specified valid favorite numbers was found to be  :    | "<<valid_count<<"   Students."<<endl;
cout<<" The total number of students who specified invalid favorite numbers was found to be :   | "<<Invalid_count<<"   Students."<<endl;
cout<<" The total number of students who did not reveal their favorite number was found to be : | "<<Zero_count<<"   Students."<<endl;
cout<<" "<<endl;
cout<<" "<<endl;
	
	
	

	
	
	MOST = 0;
	LEAST = 9999;
	
	
	for(n=0; n<=123; n++){
		if(Array_count[n]>=MOST){
			MOST = Array_count[n];
			Most_chosen = n;
			
		}
		
	}
	
	
	
	for(h=0; h<=123; h++){
		if(Array_count[h]<=LEAST && Array_count[h]>0){
			LEAST = Array_count[h];
			Least_chosen = h;
		}
	}
	

	

cout<<" The most chosen number/s is/are : "<<endl;
cout<<" ================================"<<endl;
cout<<" "<<Valid_Numbers[Most_chosen]<<endl;
cout<<"  "<<endl;





cout<<" The Least chosen number/s is/are : "<<endl;
cout<<" ==================================="<<endl;
cout<<" "<<Valid_Numbers[Least_chosen]<<endl;
cout<<"  "<<endl;




	
	

	
	
	
	
	
	









return 0;
}
