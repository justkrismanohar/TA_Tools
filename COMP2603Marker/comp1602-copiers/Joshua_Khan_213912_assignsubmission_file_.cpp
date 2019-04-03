#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

char isPerfect(int num){
	int sum = 0;
	for(int i = 1; i < num; i++){
		if (num % i == 0)
			sum += i;
	}
	if (sum == num)
		return 'Y';
	return 'N';
	
}

char isPrime(int num){
	for(int i = 2; i <= num/2; i++){
  	if(num % i == 0){
	  return 'N';  
    }  
  }
  return 'Y';
}

char isPerfectSquare(int num){
	int sqr;
    for(int i=0; i < num/2; i++)
    {
        sqr = i*i;
		 if(sqr==num)
            return 'Y';
    }
    return 'N';
}

char isSphenic(int num){
	int div = 0;						//Count for number of divisors and number of prime divisors respectively for num
	if(isPrime(num) == 'N'){
		
		for(int i = 2; i <= num; i++){
			if(num % i == 0 && isPrime(i) == 'Y'){
				div++;
				num /= i;
			}

		}
		if (num == 1 && div == 3)
			return 'Y';
	}
	return 'N';
}

void binary(int num){
	int arr[8];
	for(int i = 7; i >= 0; i--){
		arr[i] = num % 2;
		num /= 2;
	}
	for(int i = 0; i < 8; i++)
		cout<<arr[i];
}


void drawStars(int num){
	for(int i = 0; i < num; i++)
		cout<<"*";
	cout<<endl;
}

bool isDistinct(int nums[], int check){
	for(int i = 0; i < check; i++){
		if(nums[i] == nums[check])
			return false;
	}
	return true;
}

int Count(int favNums[], int num, int max){
	int count = 0;
	for(int i = 0; i < max; i++){
		if(num == favNums[i])
			count++;
	}
	return count;
}



int main(){
	ifstream fileInput;
	int num;							//Temporary number holder
	int numCount = 0;
	
	fileInput.open("numbers.txt");
	if(!fileInput.is_open() ){
		cout<<"File not found. Check file path"<<endl;
		return 0;
	}
	
	fileInput>>num;
	while (num != -1){
		numCount++;
		fileInput>>num;
	}
	fileInput.close();
	
	fileInput.open("numbers.txt");
	int j;								//Array Counter variable
	int favNum[numCount]; 				//Creates an array using the exact number of students
	for(int i = 0; i < numCount; i++){
		fileInput>>favNum[i];
	}
	fileInput.close();
	
	int invalid=0, valid=0, noReveal=0; //Amount of Students who specified invalid, valid, and no numbers respectively
	
	int rangeCount[10]; 				//Counter for the different ranges of valid numbers
	
	for(int i = 0; i < 10; i++){
		rangeCount[i] = 0;				//Initialization for the ranges count
	}
	
	int highNum[10], lowNum[100];					//Holding the numbers that are most and least chosen
	int position_high = 0, position_low = 0;		//pointers for the highest and lowest number arrays
	highNum[0] = lowNum[0] = favNum[0];
	cout<<"Number\t\tPerfect \tPrime\t\tPerfect Square? \tSphenic \tBinary Equiv."<<endl;
	cout<<"======\t\t======= \t=====\t\t=============== \t======= \t============"<<endl;
	for(int i = 0; i < numCount; i++){
		
		if(favNum[i] > 0 && favNum[i] <= 100){ //Valid number condition
			valid++;	
		  	if(isDistinct(favNum, i)){		   //Distinct number check
		    
				cout<<favNum[i]<<"\t\t"<<isPerfect(favNum[i])<<"\t\t"<<isPrime(favNum[i])<<"\t\t";
				cout<<isPerfectSquare(favNum[i])<<"\t\t\t"<<isSphenic(favNum[i])<<"\t\t";
				binary(favNum[i]);
				cout<<endl;
			
			
			if(Count(favNum,favNum[i],numCount) > Count(favNum, highNum[position_high], numCount)){
				position_high=0;
				highNum[position_high]=favNum[i];
				for(int j = i+1; j < numCount; j++){
					if (Count(favNum, favNum[i], numCount) == Count(favNum, favNum[j], numCount) && isDistinct(highNum, position_high) ){
						position_high++;
						highNum[position_high] = favNum[j];
					}
				}	
			}
			
			if(Count(favNum,favNum[i],numCount) < Count(favNum, lowNum[position_low], numCount)){
				position_low=0;
				lowNum[position_low]=favNum[i];
				for(int j = i+1; j < numCount; j++){
					if (Count(favNum, favNum[i], numCount) == Count(favNum, favNum[j], numCount) && isDistinct(lowNum, position_low) ){
						if(favNum[j]>0 && favNum[j]<=100){
							position_low++;
							lowNum[position_low] = favNum[j];
						}
					}
				}	
			}
		}
			num = favNum[i] / 10;
			if(favNum[i] % 10 == 0)
				num--;
			rangeCount[num]++;
			
	}
}
	cout<<endl<<endl;
	cout<<"Invalid Numbers:"<<endl;
	for(int i = 0; i < numCount; i++){
		if(favNum[i] < -1 || favNum[i] > 100){
			invalid++;
			cout<<favNum[i]<<"\t";
			if(invalid % 5 == 0)
				cout<<endl;
		}
		
		/*
			
		*/
		if (favNum[i] == 0)
			noReveal++;
	}
	cout<<endl<<endl;
	
	int lowerLim = 1, upperLim = 10;	//Lower and upper limits for each range of numbers in the histogram
	cout<<"Range \tHistogram"<<endl;
	cout<<"======================="<<endl;
	for(int i = 0; i < 10; i++){
		cout<<lowerLim<<"-"<<upperLim<<" \t:";
		drawStars(rangeCount[i]/5);
		lowerLim += 10;
		upperLim += 10;
	}
	
	cout<<endl<<endl;
	cout<<"==========Conclusion=========="<<endl;
	cout<<"Amount of students with valid numbers: "<<valid<<endl;
	cout<<"Amount of students with invalid numbers: "<<invalid<<endl;
	cout<<"Amount of students who didn't reveal their favourite number: "<<noReveal<<endl;
	cout<<"==============================="<<endl;
	cout<<"Number(s) that the students chose the most: ";
	for(int i = 0; i < position_high; i++){
		cout<<highNum[i];
		if(i != position_high-1)
			cout<<", ";
	}
	cout<<endl;
	cout<<"Number that was chosen the least by the students: ";
	for(int i = 0; i < position_low; i++){
		cout<<lowNum[i];
		if(i != position_low-1)
			cout<<", ";
	}
	cout<<endl;
	
	
	return 0;
}
