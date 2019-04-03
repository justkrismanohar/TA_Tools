#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool isPerfect(int n)
{
	int i;
	int sum = 0;

	for(i = 1; i < n; i = i + 1)
	{
		if(n % i == 0)
			sum = sum + 1;
	}
	if(sum == n)
		return true;
	return false;
}

bool isPrime(int n)
{
	int i;
	for(i = 2; i < n; i = i + 1)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

bool isPerfectSquare(int n)
{
	int square = 1;
	int count = 1;
	int i;

	for(i = i; i <= n; i = i + 1)
	{
		square = i * i;
		if(square == n)
            return true;
	}
	return false;
}

bool isShenic(int n)
{
	int product = 1;
	int count = 0;
	int i;
	for(i = 2; i <= n / 2; i = i + 1)
    {
        if((n % i == 0) && (n = isPrime(i)))
        {
            product = product * i;
            count = count + 1;
        }
    }
}

int toBinary(int n)
{
    int i = 0;
    int j;
    //array used to store the binary number to be displayed.
    int binaryNum[1000];

    while(n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i = i + 1;
    }
    for(j = i - 1; j >= 0; j = j - 1)
    {
        cout<<binaryNum[j];
    }
}

int displayHistogram(int n)
{
    int i;
    for(i = 0; i <= n / 5; i = i + 1)
    {
        cout<<"*";
    }
}

int main()
{
    int num, numElements, i = 0, count = 0;
    int validNums;
    //Variables used to store the range of numbers that fell into a specific category.
    int first = 0, second = 0, third = 0, forth = 0, fifth = 0, sixth = 0, seventh = 0, eight = 0, ninth = 0, tenth = 0;
    int invalid[1000];
	ifstream in;
	in.open("numbers.txt");

	if(!in.is_open())
    {
        cout<<"The file could not be accessed for reading. Please try again."<<endl;
        return 1;
    }

    cout<<"Number \t"<<"\t Perfect ? \t"<<"Prime ? \t"<<"Perfect Square? \t"<<"Sphenic ? \t"<<"Binary Equvilent  ? \t"<<endl;
    cout<< "=======\t"<<"\t ========= \t"<<"======= \t"<<"================\t"<<"=========\t"<<"==================\t"<<endl;

    in>>num;
    while(num != -1)
    {
        invalid[i] = num;
        i = i + 1;

        if((num > 0) && (num <= 10))
            first = first + 1;
        if((num > 10) && (num <= 20))
            second = second + 1;
        if((num > 20) && (num <= 30))
            third = third + 1;
        if((num > 30) && (num <= 40))
            forth = forth + 1;
        if((num > 40) && (num <= 50))
            fifth = fifth + 1;
        if((num > 50) && (num <= 60))
            sixth = sixth + 1;
        if((num > 60) && (num <= 70))
            seventh = seventh + 1;
        if((num > 70) && (num <= 80))
            eight = eight + 1;
        if((num > 80) && (num <= 90))
            ninth = ninth + 1;
        if((num > 90) && (num < 100))
            tenth = tenth + 1;

        if((num >= 1) && (num <= 100))
            validNums = validNums + 1;
            cout<<num<<"\t\t";

        if(num = isPerfect(num))
            cout<<"Y      \t\t";
        else
            cout<<"N     \t\t ";

        if(num = isPrime(num))
            cout<<"Y     \t\t ";
        else
            cout<<"N      \t\t";

        if(num = isPerfectSquare(num))
            cout<<"Y      \t\t";
        else
            cout<<"N      \t\t";

        if(num = isShenic(num))
            cout<<"Y      \t\t";
        else
            cout<<"Y      \t\t";

        cout<<toBinary(num);

    cout<<endl;
        count = count + 1;
        in>>num;

    }

}
