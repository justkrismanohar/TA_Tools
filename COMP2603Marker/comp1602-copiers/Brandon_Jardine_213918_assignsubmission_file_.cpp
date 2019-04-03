//BRANDON JARDINE
//816013474
//ASSIGNMENT 1
//COMP 1602
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

char isPerfect(int n) //perfect function
{
	int sum = 0, i;
	for (i = 1; i <= n/2; i++)
	{
		if (n%i == 0)
			sum = sum + i;	
	}
	if (sum == n)
		return 'Y';
	return 'N';
}

char isPrime(int n) //prime number function
{
	int i;
	if (n == 1)
		return 'N';
	for (i = 2; i <= n/2; i++)
	{
		if (n%i == 0)
			return 'N';
	}
	return 'Y';
}

char perfectSquare(int n) //perfect square function
{
	if (n == 1)
		return 'Y';
	int i;
	for (i = 1; i <= n/2; i++)
	{
		if (i*i == n)
			return 'Y';
	}
	return 'N';	
}

char isSphenic(int n) //sphenic function
{
	int prod = 1, count = 0, i;
	char prime;
	for (i = 2; i <= n/2; i++)
	{
		prime = isPrime(i);
		if (n%i == 0 && prime == 'Y')
		{
			prod = prod * i;
			count++;
		}
	}
	if (prod == n && count == 3)
		return 'Y';
	return 'N';
}

void binaryEqui(int n) //converting decimal to binary function
{
	int binary[8], i = 0, bit; 
	for (i = 0; i <= 7; i++)
		binary[i] = 0;
	i = 0;
	while (n != 0)
	{
		bit = n % 2;
		n = n / 2;
		binary[i] = bit;
		i += 1;
	}
	for (i = 7; i >= 0; i--)
		cout<<binary[i];
	return;
}
	
int main() //start of main function (start of program)
{
	char perf, prime, perfSq, sphen; //declaring variables
	int number, i, bin, k, j;
	int range10 = 0, range20 = 0, range30 = 0, range40 = 0, range50 = 0, range60 = 0, range70 = 0, range80 = 0, range90 = 0, range100 = 0, range[1000];
	int valid[1000], invalid[1000], nofave = 0;
	int validcount = 0, invalidcount = 0;
	int newline = 1;
	int stars;
	int storage[1000];
	int freq[101], most[101], least[101], highest, lowest; //arrays of size 101 were used in order to have the range from 1 to 100 to make it easier to navigate
	ifstream in;
	
	in.open("numbers.txt"); //opening file
	if (!in.is_open())
	{
		cout<<"ERROR FINDING FILE!";
		return 0;
	}
	// creating table
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"NUMBER\t\tPERFECT\t\tPRIME\t\tPERFECT SQUARE\t\tSPHENIC\t\tBINARY EQUIVALENT"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
	
	for (i = 0; i<= 9; i++) //assigning all numbers in the range array to 0
	{
		range[i] = 0;
	}
	in>>number; //read first number from file
	
	k = 0; //assigning variable to 0
	i = 0;
	
	while (number != -1) //reads all values until the end of program
	{
		if (number >= 1 && number <= 100) //check to see if the numbers are valid
		{
			storage[i] = number; //storing valid numbers in an array
			validcount++; //increasing the count of calid numbers
			i++; //incrementing i
			if (number >= 1 && number <= 10) //checks ranges int 10s from 1 to 100 and has a counter stored in an array for it
				range[0]++;
			else if (number >= 11 && number <= 20)
				range[1]++;
			else if (number >= 21 && number <= 30)
				range[2]++;
			else if (number >= 31 && number <= 40)
				range[3]++;
			else if (number >= 41 && number <= 50)
				range[4]++;
			else if (number >= 51 && number <= 60)
				range[5]++;
			else if (number >= 61 && number <= 70)
				range[6]++;
			else if (number >= 71 && number <= 80)
				range[8]++;
			else if (number >= 91 && number <= 100)
				range[7]++;
			else if (number >= 81 && number <= 90)
				range[9]++;			
		}
		else if (number < 0 || number > 100) //counting invalid numbers
		{
			invalid[k] = number;
			invalidcount++;
			k++;
		}
		else //counting people with no favourite numbers
			nofave++;
		in>>number;
	}
	
	for (i = 0; i <= validcount-1; i++) //this for loop is for printing only one of each number in the table
	{
		for (j = 0; j < i; j++)         //the assignment specified distinct numbers, so i interpreted distinct as 1 of each valid number
		{
			if (storage[i] == storage[j]) // so if there are multiple instances of the same number, only one will appear in the table
				break;
		}
		if (i == j)
		{
			perf = isPerfect(storage[i]);
			prime = isPrime(storage[i]);
			perfSq = perfectSquare(storage[i]);
			sphen = isSphenic(storage[i]);
			cout<<storage[i]<<"\t\t   "<<perf<<"\t\t  "<<prime<<"\t\t      "<<perfSq<<"\t\t\t   "<<sphen<<"\t\t"; //printing everything
			binaryEqui(storage[i]); //printing the conversion to binary
			cout<<endl<<endl;
		}
	}
	
	cout<<endl<<endl<<endl;
	
	cout<<"INVALID NUMBERS: "<<endl; //printing all invalid numbers
	
	for (i = 0; i <= invalidcount - 1; i++)
	{
		cout<<invalid[i]<<"\t\t";
		if (newline % 5 == 0) //printing 5 on a line
			cout<<endl;
		newline++;
	}
	
	cout<<endl<<endl<<endl;
	
	cout<<"-----------------------------"<<endl; //printing the histogram
	cout<<"RANGE\t\tHISTOGRAM"<<endl;
	cout<<"-----------------------------"<<endl;
	
	k = 0;
	
	for (i = 1; i <= 100; i = i + 10)
	{
		stars = floor (range[k] / 5);
		cout<<i<<"-"<<i+9<<"\t\t"<<"|"; // 1 star = 5 numbers
		for (j = 1; j <= stars; j++)
			cout<<"*";
		k++;
		cout<<endl;
	}
	
	cout<<endl<<endl<<endl; //printing number of valid favourites, invalid and did not reveal
	cout<<"# of students who specified valid favourite numbers: "<<validcount<<endl;
	cout<<"# of students who specified invalid favourite numbers: "<<invalidcount<<endl;
	cout<<"# of students who did not reveal their favourite number: "<<nofave<<endl;
	
	for (i = 0; i <= 100; i++) //assigning everything in frequency
	{
		freq[i] = 0;
	}
	
	for (i = 0; i <= validcount-1; i++) //checking the frequency of each valid favourite number and storing it in an array
	{
		for (j = 1; j <= 100; j++)
		{
			if (storage[i] == j)
			{
				freq[j]++;
			}
		}
	}
	
	
	highest = 0; //assign highest to 0
	
	for (i = 0; i <= 99; i++) //check for the highest frequency
	{
		if (freq[i] > highest)
			highest = freq[i];
	}
	
	for (i = 0; i <= 99; i++) //assign the most and least arrays to -1
	{                         //most and least are used to store the numbers that have the highest and lowest frequencies respectively
		most[i] = -1;
		least[i] = -1;
	}
	
	k = 0; //assign k to 0
	
	for (i = 0; i <= 100; i++) //storing the numbers with the highest frequencies in the array
	{
		if (freq[i] == highest)
		{
			most[k] = i;
			k++;
		}
	}
	
	lowest = highest; //assign lowest to the highest frequency therefore the next lowest will have to be smaller
	
	for (i = 0; i <= 100; i++)  //check for the lowest frequency
	{
		if (freq[i] > 0)
		{
			if (freq[i] < lowest)
				lowest = freq[i];
		}
	}
	
	k = 0; //assign k to 0 again
	
	for (i = 0; i <= 100; i++) //storing the numbers with the lowest frequencies
	{
		if (freq[i] == lowest)
		{
			least[k] = i;
			k++;
		}
	}
	
	cout<<endl;
	
	cout<<"# chosen the most by the students was/were: "; //printing numbers chosen the most
	k = 0;
	
	while (most[k] != -1) //loop until the end of all numbers with the highest frequency
	{
		cout<<most[k]<<"\t";
		k++;
	}
	cout<<endl;
	
	cout<<"# chosen the least by the students was/were: ";
	
	k = 0;
	
	while (least[k] != -1) //loop until the end of all numbers with the lowest frequency
	{
		cout<<"\t"<<least[k];
		k++;
	}
	
	in.close(); //close file
	return 0;
} //end of program
