#include <iostream>
#include <fstream>
using namespace std;

//FUNCTIONS
char isPerfect(int num)
{
	if (num == 1)
		return 'N';
	int sum = 1, x;
	for (x = 2; x <= (num / 2); x++)
	{
		if (num % x == 0)
			sum = sum + x;
	}
	if (sum == num)
		return 'Y';
	return 'N';
}

char isPrime(int num)
{
	int x;
	if (num == 1)
		return 'N';
	for (x = 2; x <= (num / 2); x++)
		if (num % x == 0)
			return 'N';
	return 'Y';
}

char isSquare(int num)
{
	int x;
	for (x = 1; x <= num / 2; x++)
		if (num % x == 0 && x * x == num)
			return 'Y';
	return 'N';
}

char isSphenic(int num)
{
	int x, y, z;
	if (isPrime(num)=='N' && (num >= 30))
		for (x = 2; x <= ((num / 2) - 2); x++)
			if (isPrime(x) == 'Y')
				for (y = x + 1; y <= ((num / 2) - 1); y++)
					if (isPrime(y) == 'Y')
						for (z = y + 1; z <= (num / 2); z++)
							if (isPrime(z) == 'Y' && ((x * y * z) == num))
								return 'Y';
	return 'N';
}

void binary(int num)
{
	int pos = 0, bit[8] = {0, 0, 0, 0, 0, 0, 0, 0}, x;
	while (num != 0 && pos < 8)
	{
		bit[pos] = num % 2;
		num = num / 2;
		pos++;
	}

	for (x = 7; x >= 0; x--)
	{
		cout << bit[x];
	}
}

int main(){
	int count = 0, x, y;
	bool check=0;
	ifstream input;
	
	//count the number of records in file
	input.open("numbers.txt");
	input >> x;
	while (x!=-1){
		count++;
		input >> x;
	}
	input.close();
	
	int num[count], numdist[count], distcount=0;
	count=0;
	
	//store in arrays all the numbers and all the valid numbers
	input.open("numbers.txt");
	input >> x;
	while (x != -1){
		//all numbers
		num[count]=x;
		count++;
		
		//distinct numbers
		if (distcount != 0)
			for (y=0; y<distcount && check == 0; y++){
				if (x == numdist[y])
				check = 1;
			}
		if (check==0){
			numdist[distcount]=x;
			distcount++;
		} else {
			check = 0;
		}
		
		input >> x;
	}
	
	//count how many valid, invalid and unspecified 
	//find out how many numbers are in each category
	int val=0, inval=0, unspec=0, cat[10]={0,0,0,0,0,0,0,0,0,0};
	for (x=0; x< count; x++){
		if (num[x]==0)
			unspec++;
		else if(num[x]<0 || num[x]>100)
			inval++;
		else {
			val++;
			cat[(num[x]-1)/10]++;
		}
	}
	
	//find the numbers that occur the most and the least
	bool highcheck=0;
	int low[count], high[count], lowcount, highcount, lowamt=101, highamt=-1,amt=0;
	for(x=0;x<distcount;x++){
		if (numdist[x] > 0 && numdist[x]<=100){
			//count how much time each number occur
			for(y=0;y<count;y++){
				if(numdist[x] == num[y])
					amt++;
			}
			
			//if it occurs more than the highest occuring number replace it
			if(highcheck==0 && amt >1)
				highcheck=1;
			if(highcheck==1){
				if (amt>highamt){
					highamt=amt;
					high[0]=numdist[x];
					highcount = 1;
					
				//if it occurs the same amount of time as the highest occuring, add it to the highest array
				} else if (amt == highamt){
					high[highcount]= numdist[x];
					highcount++;
				}
			}
			
			//repeat for the lowest array
			if(amt<lowamt){
				lowamt=amt;
				low[0]=numdist[x];
				lowcount = 1;
			} else if (amt = lowamt){
				low[lowcount]=numdist[x];
				lowcount++;
			}
			
			amt=0;
		}
	}
	
	
	//OUTPUT
	cout << "======================\n";
	cout << "DISTINCT NUMBERS TABLE\n";
	cout << "======================\n";
	cout << "________________________________________________\n";
	
	cout << "Number	Perfect	Prime	Square	Sphenic	Binary" << endl;
	cout << "======	=======	=====	======	=======	========\n";
	for (x=0;x<distcount;x++){
		if (numdist[x]>0 && numdist[x] <= 100){
			cout << numdist[x] << "	" << isPerfect(numdist[x]) << "	" << isPrime(numdist[x]) 
			<< "	" << isSquare(numdist[x]) << "	" << isSphenic(numdist[x]) << "	";
			binary(numdist[x]);
			cout << endl;
		}
	}
	
	cout << "________________________________________________\n\n";	
	cout << "======================\n";
	cout << "INVALID NUMBERS\n";
	cout << "======================\n";
	cout << "___________________\n";
	
	y=0;
	for (x=0; x<distcount; x++) {
		if(numdist[x]<0 || numdist[x]>100){
			y++;
			cout<<numdist[x]<<"	";
			if (y%5 == 0)
				cout << endl;
		}
	}
	
	
	cout << "\n___________________\n\n";	
	cout << "======================\n";
	cout << "CATEGORY HISTOGRAM\n";
	cout << "======================\n";
	cout << "_________________\n";
	cout << "Range	Histogram\n";
	cout << "=====	=========\n";
	for (x=1; x<=10; x++){
		cout << (x*10)-9 << "-" << x*10 << "	" << "| ";
		for (y=1; y <= cat[x-1]/5; y++){
			cout << "*";
		}
		cout << endl;
	}
	cout << "_________________\n\n";
	
	cout << "======================\n";
	cout << "STATISTICAL INFO\n";
	cout << "======================\n";
	cout << "______________________________\n";
	cout << "Valid Favorite Numbers: " << val <<endl;
	cout << "Invalid Favorite Numbers: " << inval <<endl;
	cout << "Unrevealed Favorite Numbers: " << unspec <<endl;
	cout << "______________________________\n";
	if (highcheck == 0)
		cout << "There is no MOST choosen number. No number was chosen twice";
	else{
		cout << "The MOST chosen number(s), chosen " << highamt << " time(s) were/was: \n";
		for (x=0; x<highcount; x++){
			cout << high[x] << " ";
			if ((x+1)%5==0) cout << endl;
		}
	}
	
	cout << "\nThe LEAST chosen number(s), chosen " << lowamt << " time(s) were/was: \n";
		for (x=0; x<lowcount; x++){
			cout << low[x] << "	";
			if ((x+1)%5==0) cout << endl;
		}
	
}
