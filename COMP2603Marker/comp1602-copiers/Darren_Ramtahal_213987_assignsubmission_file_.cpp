#include <iostream>
#include <fstream>
using namespace std;


bool perfect(int num){
	int sum = 0;
	int x;
	for(x=1;x<=num/2;x++){
		if(num%x==0)
			sum = sum + x;
	}
	if(sum == num)
		return true;
	return false;
}

bool prime(int num){
	if(num == 1)
		return false;
	int x;
	for(x=2;x<=num/2;x++){
		if(num%x == 0)
			return false;
	}
	return true;
}

bool perfectSquare(int num){
	int x;
	for(x=1;x<=num/2;x++){
		if(x*x == num)
			return true;
	}
	return false;
}

bool sphenic(int num){
	int count, x;
	int product = 1;
	count = 0;
	for(x=2;x<num/2;x++){
		if(num%x == 0 && prime(x) == true){
			product = product * x;
			count++;
		}
	}
	if(count == 3 && product == num)
		return true;
	return false;
}

void binary(int num){
	int x;
	int binaryNum[8];
	for(x=0;x<8;x++){
		binaryNum[x] = num%2;
		num = num/2;
	}
	int temp;
	for(x=0;x<4;x++){ //reverses the order of the array to display the correct binary equivalent.
		temp = binaryNum[8-x-1];
		binaryNum[8-x-1] = binaryNum[x];
		binaryNum[x] = temp;
	}
	for(x=0;x<8;x++)
		cout<<binaryNum[x];
	cout<<endl;
}

void histogram(int num){
	int starCount;
	starCount = num/5;
	for(int x = 0; x<starCount; x++)
		cout<<"*";
	cout<<endl;
}


int main(){
	ifstream in;
	in.open("numbers.txt");
	while(!in.is_open()) //checks if the file "numbers.txt" can be opened for reading.
		cout<<"File can't be opened"<<endl;
	int count = 0;
	int number, valid;
	int firstGroup = 0;
	int secondGroup = 0;
	int thirdGroup = 0; 
	int fourthGroup = 0;
	int fifthGroup = 0;
	int sixthGroup = 0; 
	int seventhGroup = 0;
	int eighthGroup = 0;
	int ninthGroup = 0;
	int tenthGroup = 0;
	valid = 0;
	in>>number;
	while(number!=-1){ //obtains the amount of students who were polled.
		count++;
		in>>number;
	}
	int numbers[count];
	int distinctNum[101];
	int choices[101];
	int x,i;
	for(x=0;x<101;x++)
		distinctNum[x] = 0;
	int noReveal = 0;
	in.close();
	in.open("numbers.txt");
	cout<<"Number \t\t Perfect \t Prime \t\t Perfect Square \t Sphenic \t Binary Equiv."<<endl;
	cout<<"====== \t\t ======= \t ===== \t\t ============== \t ======= \t ============="<<endl;
	cout<<endl;
	for(x=0;x<count;x++)
		in>>numbers[x];
	for(x=0;x<101;x++)
		choices[x] = 0;
	int y;
	for(x=0;x<count;x++){
		for(y=0;y<101;y++){
			if(y == numbers[x])
				choices[y]++;
		}
		if(numbers[x] == 0)
			noReveal++;
		if(numbers[x]>=1 && numbers[x]<=10) //counts the amount of numbers which fall in the respective categories.
			firstGroup++;
		if(numbers[x]>=11 && numbers[x]<=20)
			secondGroup++;
		if(numbers[x]>=21 && numbers[x]<=30)
			thirdGroup++;
		if(numbers[x]>=31 && numbers[x]<=40)
			fourthGroup++;
		if(numbers[x]>=41 && numbers[x]<=50)
			fifthGroup++;
		if(numbers[x]>=51 && numbers[x]<=60)
			sixthGroup++;
		if(numbers[x]>=61 && numbers[x]<=70)
			seventhGroup++;
		if(numbers[x]>=71 && numbers[x]<=80)
			eighthGroup++;
		if(numbers[x]>=81 && numbers[x]<=90)
			ninthGroup++;
		if(numbers[x]>=91 && numbers[x]<=100)
			tenthGroup++;
			
		if(numbers[x]>0 && numbers[x]<=100){
			valid++; //counts the amount of valid numbers.
			if(distinctNum[x] == 0){
				cout<<numbers[x]<<" \t \t ";
				if(perfect(numbers[x]) == true)
					cout<<"Y \t\t ";
				else
					cout<<"N \t\t ";
			
				if(prime(numbers[x]) == true)
					cout<<"Y \t\t ";
				else
					cout<<"N \t\t ";
			
				if(perfectSquare(numbers[x]) == true)
					cout<<"Y \t\t\t ";
				else
					cout<<"N \t\t\t ";
				
				if(sphenic(numbers[x]) == true)
					cout<<"Y \t\t ";
				else
					cout<<"N \t\t ";
				binary(numbers[x]);	
				distinctNum[x]++;
			}
		}
	}
	int invalidCounter = 0;
	cout<<endl;
	cout<<endl;
	cout<<"INVALID NUMBERS:"<<endl;
	for(x=0;x<count;x++){
		if(numbers[x]>100 || numbers[x]<0){
			cout<<numbers[x]<<", ";
			invalidCounter++;
			if(invalidCounter%5 == 0)
				cout<<endl;
		}
	}
	cout<<endl;
	cout<<endl;
	cout<<"RANGE \t HISTOGRAM"<<endl; //displays histogram showing the amount of numbers falling in each category.
	cout<<"===== \t ========="<<endl;
	cout<<"1-10  \t ";
	histogram(firstGroup);
	cout<<"11-20 \t ";
	histogram(secondGroup);
	cout<<"21-30 \t ";
	histogram(thirdGroup);
	cout<<"31-40 \t ";
	histogram(fourthGroup);
	cout<<"41-50 \t ";
	histogram(fifthGroup);
	cout<<"51-60 \t ";
	histogram(sixthGroup);
	cout<<"61-70 \t ";
	histogram(seventhGroup);
	cout<<"71-80 \t ";
	histogram(eighthGroup);
	cout<<"81-90 \t ";
	histogram(ninthGroup);
	cout<<"91-100 \t ";
	histogram(tenthGroup);
	
	int invalid = count - (noReveal + valid);
	cout<<endl;
	cout<<"Students who specified valid numbers: "<<valid<<endl;
	cout<<"Students who specified invalid numbers: "<<invalid<<endl;
	cout<<"Students who didn't reveal a number: "<<noReveal<<endl;
	cout<<endl;
	int highestNum = 0;
	int lowestNum = 99999;
	int mostVotes = 0;
	int leastVotes = 0;
	for(x=1;x<101;x++){
		if(choices[x]>=2 && choices[x]>highestNum)
			highestNum = choices[x];
		if(choices[x]>=1 && choices[x]<lowestNum)
			lowestNum = choices[x];
	}
	cout<<"Number chosen most by students: ";
	for(x=1;x<101;x++){
		if(choices[x] == highestNum)
			cout<<x<<", ";
	}
	cout<<endl;
	int leastCount = 0;
	cout<<"Number chosen least by students:"<<endl;
	for(x=1;x<101;x++){
		if(choices[x] == lowestNum){
			cout<<x<<", ";
			leastCount++;
			if(leastCount%5 == 0)
				cout<<endl;
		}
	}
	
	
	
}
