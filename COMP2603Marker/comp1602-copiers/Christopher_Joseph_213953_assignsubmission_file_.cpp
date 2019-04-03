#include <iostream> 
#include <fstream>
using namespace std;

int distinct (int valnum[], int size, int x){
	
	for(int i=0; i<size; i++){
		if(valnum[i]==x)
		return i;
	}
	return -1;
}

bool Perfect(int num) {
	int i, sum = 0;
	
  	for(i=1; i<num; i++){
  		if (num%i==0){
        	sum = sum + i;
  		}
	}
  		if(sum == num) {
 			return true;
  		}
  		else{
 		return false;
 		}
}

bool Prime (int num){
	int i; 
	for (i=2; i<=num/2; i++){
		if(num%i ==0){
			return false;
		}
	}
	if(num==1){
		return false;
	}
	return true;
}

bool PerfectSquare (int num){
	int square;
	for(int i=1; i<=num/2; i++){
		square = i*i;
		if(square==num){
			return true;
		}
	}
	if(num==1){
		return true;
	}
			return false;
		
	}
	
bool Sphenic(int num){
	int i, count,product;
	count =0;
	product =1;
	
	for(i=2; i<=num/2; i++){
		if(num%i ==0 && Prime(i)){ 
			product = product * i;
			count = count + 1;
		}
	}
		if(count==3 && product ==num)
			return true;
			return false;
}

void Binary(int num){
	int bin[8];
	int i,digit;
	for(i=0; i<8; i++){
		digit = num%2;
		bin[i] = digit;
		num = num/2;
	}
	for(i=7; i>=0; i--){
		cout <<bin[i];
	}
}


int main () {
	int num,valid=0, didnotreveal=0,inval=0, uniqueIndex = 0;
	//,histo=0, histo2=0;
	int valnum[250];
	int invalnum[250];
	int unique[250];
	char perfectnum, primenum, perfectsqnum, sphenicnum;
	int sizeD=0;
	int range[10]= {0,0,0,0,0,0,0,0,0,0};
	int countU[250];
	int nummax=-2, locnummax;
	int nummin=99999, locnummin;
	
	for(int i=0; i<250; i++){
		countU[i]=0;
	}
	
	ifstream inFile;

	inFile.open("numbers.txt");
	
	if(!inFile.is_open()){
		cout << "Error locating file" <<endl;
		return 1;
	}
	
	inFile >> num;
	
	//store valid values into an array and test for didn't reveal and store invalid numbers
	while(num!=-1){
	if(num>=1 && num <= 100){
	    valnum[valid] = num;
		valid++;
	}
	else if (num == 0){
	    didnotreveal++;
	}
	else{
		invalnum[inval]=num;
	    inval++;
	    }
		inFile >> num;
	}
	
	//test if each number is distinct and occurrence of duplicates
	for(int i=0; i<valid; i++){
		int indexFound = distinct (unique, sizeD, valnum[i]);
		if (indexFound !=-1){
			countU[indexFound]++;
		}
		else{
			unique[uniqueIndex] = valnum[i];
			countU[uniqueIndex]++;
			uniqueIndex++;
			sizeD++;
		}
	}
	
	cout <<"Number\t\t Perfect?\t Prime?\t\t Perfect Square?\t Sphenic?\t Binary Equiv" <<endl;
	cout <<"======\t\t ========\t ======\t\t ===============\t ========\t ============" <<endl;
	for(uniqueIndex=0; uniqueIndex<sizeD; uniqueIndex++){
	    if(Perfect(unique[uniqueIndex])){
	    perfectnum = 'Y';
	    }
	    else{
	    perfectnum = 'N';;
		}
		
		if(Prime(unique[uniqueIndex])){
			primenum = 'Y';
		}
		else{
			primenum = 'N';
		}
		
		if(PerfectSquare(unique[uniqueIndex])){
			perfectsqnum = 'Y';
		}
		else{
			perfectsqnum = 'N';
		}
		
		if(Sphenic(unique[uniqueIndex])){
			sphenicnum = 'Y';
		}
		else{
			sphenicnum = 'N';
		}
	cout <<unique[uniqueIndex] <<"\t\t "<<perfectnum <<"\t\t " <<primenum <<"\t\t " <<perfectsqnum <<"\t\t\t " <<sphenicnum <<"\t\t ";
	Binary(unique[uniqueIndex]);
	cout <<endl;
	}
	
	cout <<"\n\nInvalid Numbers\n";
	cout <<"---------------" <<endl;
	for(int j=1; j<=inval; j++){
		cout <<invalnum[j-1] <<" ";
		if(j%5==0){
		cout <<	endl;
		}
	}
		
	cout <<"\n\nRange\t\tHistogram" <<endl;
	cout <<"=========================" <<endl;
	
	for(int i=0; i<valid; i++){
		if(valnum[i]>=1 && valnum[i]<=10){
			range[0] +=1;
		}
		if(valnum[i]>=11 && valnum[i]<=20){
			range[1] +=1;
		}
		if(valnum[i]>=21 && valnum[i]<=30){
			range[2] +=1;
		}
		if(valnum[i]>=31 && valnum[i]<=40){
			range[3] +=1;
		}
		if(valnum[i]>=41 && valnum[i]<=50){
			range[4] +=1;
		}
		if(valnum[i]>=51 && valnum[i]<=60){
			range[5] +=1;
		}
		if(valnum[i]>=61 && valnum[i]<=70){
			range[6] +=1;
		}
		if(valnum[i]>=71 && valnum[i]<=80){
			range[7] +=1;
		}
		if(valnum[i]>=81 && valnum[i]<=90){
			range[8] +=1;
		}
		if(valnum[i]>=91 && valnum[i]<=100){
			range[9] +=1;
		}
	}
	
	cout <<"1-10\t\t|";
	for(int i=1; i<=range[0]; i++){
		if(i%5==0){
		cout <<"*";
		}
	}
	cout <<endl;
	
	cout <<"11-20\t\t|";
	for(int i=1; i<=range[1]; i++){
		if(i%5==0){		
		cout <<"*";
		}
	}
	cout <<endl;
	
	cout <<"21-30\t\t|";
	for(int i=1; i<=range[2]; i++){
		if(i%5==0){
		cout <<"*";
		}
	}
	cout <<endl;
	
	cout <<"31-40\t\t|";
	for(int i=1; i<=range[3]; i++){
		if(i%5==0){
		cout <<"*";
		}
	}
	cout <<endl;
		
	cout <<"41-50\t\t|";
	for(int i=1; i<=range[4]; i++){
		if(i%5==0){
		cout <<"*";
		}
	}
	cout <<endl;
		
	cout <<"51-60\t\t|";
	for(int i=1; i<=range[5]; i++){
		if(i%5==0){
		cout <<"*";
		}
	}
	cout <<endl;
		
	cout <<"61-70\t\t|";
	for(int i=1; i<=range[6]; i++){
		if(i%5==0){
		cout <<"*";
		}
	}
	cout <<endl;
		
	cout <<"71-80\t\t|";
	for(int i=1; i<=range[7]; i++){
		if(i%5==0){
		cout <<"*";
		}
	}
	cout <<endl;
		
	cout <<"81-90\t\t|";
	for(int i=1; i<=range[8]; i++){
		if(i%5==0){
		cout <<"*";
		}
	}
	cout <<endl;
		
	cout <<"91-100\t\t|";
	for(int i=1; i<=range[9]; i++){
		if(i%5==0){
		cout <<"*";
		}
	}
	cout <<endl;
	
	cout <<"\nThe number of students that specified valid favourite numbers: " <<valid <<endl;
	cout <<"The number of students that specified invalid favourite numbers: " <<inval <<endl;
	cout <<"The number of students that did not reveal their favourite numbers: " <<didnotreveal <<endl<<endl;
	
	cout <<"The number chosen the most by students: ";
	int j,k;
	for(j=0; j<sizeD; j++){
		if(countU[j]>nummax && countU[j]>=2){
			nummax = countU[j];
			locnummax = j;
		}
	}
	
	for(k=0; k<sizeD; k++){
		if(countU[k]==nummax){
		cout <<unique[k] <<endl;		
		}
	}
	
	cout <<"The number chosen the least by students:\n";
	for(j=0; j<sizeD; j++){
		if(countU[j]<nummin && countU[j]>=1){
			nummin = countU[j];
			locnummin = j;
		}
	}
	
	for(k=0; k<sizeD; k++){
		if(countU[k]==nummin){
		cout <<unique[k] <<endl;		
		}
 	}
	return 0;
}

