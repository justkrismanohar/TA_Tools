#include <iostream>
#include <fstream>

using namespace std;

bool isPerfect (int n){
	int count,num=0;
	for(count = 1; count <= n/2; count ++){
		if(n % count == 0)
			num = num + count; 		
	}
	if(n == num)
		return true;
 	return false;
}

bool isPrime(int n){
	int count;
	for(count = 2; count <= n/2; count ++)
		if(n % count == 0)
			return false;
	return true;
}

bool perfectSquare(int n){
	int count,num;
	for(count = 1; count <= n; count ++){
		num = count * count;
		if(n = num)
			return true;
	}
	return false;	
}

bool isSphenic(int n){
	int count,numPrimeDivisors = 0,y;
	for(count = 1; count <=n; count ++)
	    if (isPrime(count) && (n%count == 0)){
	    	numPrimeDivisors = numPrimeDivisors+1;
			y=n/count;
			if(y % count==0)
				return false;
		}
	if (numPrimeDivisors == 3)
		return true;
	return false;
}

void binaryNumber(int num){
	int count,r,i[8];
	for(count=0;count<8;count++){
		r=num%2;
		i[7-count]=r;
		num=num/2;
	}
	for(count=0;count<8;count++)
		cout<<i[count];
}


int main () {
	ifstream inputFile;
	inputFile.open("numbers.txt");
	if(!inputFile.is_open()){
		cout<<"Error opening the file";
		return 0;
    }
    
    int count;
    int category;
    int counts[10];
	for(category = 0; category < 10; category++)
		counts[category] = 0;
	
	int d[101];
	for(count = 0; count <=100; count++)
		d[count] = 0;
		
	int zerocount=0;
	int a[100], i = 0, num, invalidNumbers[100],invalid=0,valid = 0;
	bool b;
	cout<<"Number   Perfect?   Prime?   Perfect Square?   Sphenic?   Binary Equiv."<<endl;
	cout<<"=====    ========   ======   ===============   ========   ============"<<endl;
	inputFile >> num;
	while(num != -1){
		if(num >= 1 && num <= 100){
			valid++;
			category = (num - 1)/10;
			counts[category] = counts[category] + 1;		
			
		    d[num] = d[num] + 1;
			
			b = false;
			for (count = 0; count < i; count++) {
				if (a[count] == num) {
					b = true;
				}
			}
			if (b==false){
				a[i]=num;
				i++;cout<<num;
				if(isPerfect(num))
					cout<<"           Y";
				else 			
					cout<<"           N";	
				
				if(isPrime(num))
					cout<<"         Y";
				else 			
					cout<<"         N";
	
				if(perfectSquare(num))
					cout<<"            Y";
				else 			
					cout<<"            N";
				
				if(isSphenic(num))
					cout<<"              Y        ";
				else 			
					cout<<"              N        ";		
			
				(binaryNumber(num));
				cout<<endl;
				
				
			}
		}
		else if(num == 0)
			zerocount = zerocount + 1;
			
		else{
			invalidNumbers[invalid] = num;
			invalid = invalid + 1;
		}
			
			
					
		inputFile >> num;
	}
	cout<<endl;
	cout<<"LIST OF ALL INVALID NUMBERS";	
	for(count=0;count<invalid;count++){
	    if(count % 5 == 0)
			cout<<endl;
		cout<<invalidNumbers[count]<<" ";
	}
    cout<<endl;
    cout<<endl;
    
	cout<<"Range     Histogram"<<endl;
	cout<<"====================================="<<endl;
	for(category = 0; category < 10; category++){
		int lower = 10 * category + 1;
		int upper = 10 * category + 10; 
		cout<<lower<<" - "<<upper<<"   |";
		int numStars = counts[category] / 5; 
		for(count = 0; count <= numStars; count++)
			cout<<"*";
		cout<<endl;
	}
	
	cout<<"The amount of students who specified valid favourite numbers is "<<valid<<" students"<<endl;
	cout<<"The number of students who specified invalid favourite numbers is "<<invalid<<endl;
	cout<<"The number of students who did not reveal their favourite number is "<<zerocount<<endl;
	cout<<"The number/s that was/were chosen most by the students if at least two students chose that number is/are ";
	
	int maxcount=0;
	for(count = 1; count <=100; count++){
		if(d[count] > maxcount)
			maxcount = d[count];
	}
	if(maxcount >= 2){
		for(count = 1; count <= 100; count ++)
			if(d[count] == maxcount)
				cout<<count<<"  ";
	}
	
	cout<<"The number/s that was/were chosen the least by the least by the students if at least one student chose that number is/are ";
	int mincount=1000;
	for(count = 1; count <=100; count ++)
		if((d[count] < mincount) && (d[count] >=1))
			mincount = d[count];
		
	for(count = 1; count <=100; count ++)
		if(d[count]== mincount)
			cout<<count<<"   ";
	
	inputFile.close();
	return 0;
}








