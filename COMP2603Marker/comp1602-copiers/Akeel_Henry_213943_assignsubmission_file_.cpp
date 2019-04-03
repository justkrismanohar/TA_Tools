#include <iostream>
#include <fstream>
using namespace std;

// Function To Determine If Perfect

char isPerfect (int num)
{
	int i, sum;
	bool perfect = false;

	sum = 0;

	for (i=1; i<num; i++)
	{
		if ((num%i) == 0)
		{
			sum = sum + i;
		}
	}

	if (sum == num)
	{
		perfect = true;
	}

	if (perfect == true)
		return 'Y';
	else
		return 'N';
}

// Function To Determine If Prime

char isPrime (int num)
{
	int i;
	bool prime = true;

	if (num == 1)
	{
		prime = false;
	}
	else
	{
		for (i=2; i<num; i++)
		{
			if (num%i == 0)
			{
				prime = false;
			}
		}
	}

	if (prime == true)
		return 'Y';
	else
		return 'N';
}

// Function To Determine If Perfect Square

char isPerfectSquare (int num){

	int i,sum = 1;

	while (sum < num)
	{
		sum = i * i;
		i++;
	}

	if(sum == num)
	{
		return 'Y';
	}
	else
	{
		return 'N';
	}

}

// Function To Determine If Sphenic


char isSphenic (int num)
{
	int i, count, product;

	count = 0;
	product = 1;

	for(i=2; i<=num/2; i++)
	{
		if(num % i == 0 && isPrime(i) == 'Y')
		{
			product = product * i;
			count = count + 1;
		}
	}

	if(count == 3 && product == num)
		return 'Y';
	else
		return 'N';
}

// Function To Find Binary Number

void binary (int num)
{
	int bin[8], i;

	for (i=0; i<8; i++)
	{
		bin[i] = num % 2;
		num = num / 2;
	}

	// Reverses Order

	for (i=7; i>=0; i--)
	{
		cout << bin[i];
	}
}

// Function For Histogram

void histogram (int chosenCount)
{
	while(chosenCount >= 5)
	{
		chosenCount = chosenCount - 5;
		cout << "*";
	}

}

int main ()
{
	int validNum[150], invalidNum[100], chosenCount[10], num, validCount, invalidCount, didNotRevealCount, i, histogramCount, n;
	ifstream inputFile;

	validCount = 0;
	invalidCount = 0;
	didNotRevealCount = 0;
	histogramCount = 0;
	n = 1;

	inputFile.open("numbers.txt");
	
	if (inputFile.is_open() == false)
	{
		cout << "Error Opening File" << endl;
		return 0;
	}

	inputFile >> num;

	// Setting Array To 0

	for (i=0; i<10; i++)
	{
		chosenCount[i] = 0;
	}

	// Reading In Values

	while (num != -1)
	{
		if ((num >=1) && (num <=100))
		{
			validNum[validCount] = num;
			validCount++;

			if (num >=1 && num <= 10)
			{
				chosenCount[0]++;
			}

			if (num >10 && num <= 20)
			{
				chosenCount[1]++;
			}

			if (num >20 && num <= 30)
			{
				chosenCount[2]++;
			}

			if (num >30 && num <= 40)
			{
				chosenCount[3]++;
			}

			if (num >40 && num <= 50)
			{
				chosenCount[4]++;
			}

			if (num >50 && num <= 60)
			{
				chosenCount[5]++;
			}

			if (num >60 && num <= 70)
			{
				chosenCount[6]++;
			}

			if (num >70 && num <= 80)
			{
				chosenCount[7]++;
			}

			if (num >80 && num <= 90)
			{
				chosenCount[8]++;
			}

			if (num >90 && num <= 100)
			{
				chosenCount[9]++;
			}

		}
		else
		{
			if (num == 0)
			{
				didNotRevealCount++;
			}
			else
			{
				invalidNum[invalidCount] = num;
				invalidCount++;
			}
		}

		inputFile >> num;
	}


	inputFile.close();

	// Distinct Numbers Output

	cout << "======\t\t========\t======\t\t===============\t\t========\t=============" << endl;
	cout << "Number\t\tPerfect?\tPrime?\t\tPerfect Square?\t\tSphenic?\tBinary Equiv." << endl;
	cout << "======\t\t========\t======\t\t===============\t\t========\t=============" << endl;

	int j;

	for (i=0; i<validCount; i++)
	{
		for (j=0; j<i; j++)
            if (validNum[i] == validNum[j])
               break;

		if (i == j)
		{
			cout << validNum[i] << "\t\t" << isPerfect(validNum[i]) << "\t\t" << isPrime(validNum[i]) << "\t\t" << isPerfectSquare(validNum[i]) << "\t\t\t" << isSphenic(validNum[i]) << "\t\t";
			binary(validNum[i]);
			cout << endl;
		}

	}

	cout << endl << endl;


	cout << "===============" << endl;
	cout << "Invalid Numbers" << endl;
	cout << "===============" << endl;
	cout << endl;

	for (i=0; i<invalidCount; i++)
	{
		cout << invalidNum[i] << "\t";

		if (i % 5 == 4)
		{
			cout << endl;
		}
	}

	cout << endl << endl;


	cout << "=================" << endl;
	cout << "Range\tHistogram" << endl;
	cout << "=================" << endl;

	for (i=0; i<10; i++)
	{
		cout << n << "-" << n+9 << "\t|";
		histogram (chosenCount[i]);
		n = n + 10;
		cout << endl;
	}

	cout << endl;
	cout << "Number Of Students Who Specified Valid Numbers - " << validCount << endl << endl;
	cout << "Number Of Students Who Specified Invalid Numbers - " << invalidCount << endl << endl;
	cout << "Number Of Students Who Did Not Reveal Their Favourite Number - " << didNotRevealCount << endl << endl;

	// Number/s that was/were chosen the most
	//
	//

	int most = 0, temp, mostCount[validCount], leastCount[validCount], mostValue;

	// Setting Array To 0

	for (i=0; i<validCount; i++)
    {
        mostCount[i] = 0;
        leastCount[i] = 0;
    }

    // Counting Number Of Times Each Number Appears

	for (i=0; i<validCount; i++)
    {
        temp = validNum[i];
        mostCount[temp]++;
    }

    // Finding Highest Amount A Number Appears

    for (i=0; i<validCount; i++)
    {
        if (mostCount[i] > most)
        {
            most = mostCount[i];
        }
    }

    // Outputting All Values That Appeared = Highest Amount

    cout << "Number/s That Were Chosen The Most By Students Are - ";

    for (i=0; i<validCount; i++)
    {
        if ((mostCount[i] == most) && (mostCount[i] > 1))
        {
            cout << i;
        }
    }

    cout << endl << endl;

    // Number/s that was/were chosen the least
    //
    //

    int least = 10000, temp2, leastValue;


    // Counting Number Of Times Each Number Appears

	for (i=0; i<validCount; i++)
    {
        temp2 = validNum[i];
        leastCount[temp2]++;
    }

    // Finding Lowest Amount A Number Appears

    for (i=0; i<validCount; i++)
    {
        if ((leastCount[i] < least) && (leastCount[i] >= 1))
        {
            least = leastCount[i];
        }
    }

    // Outputting All Values That Appeared = Lowest Amount

    cout << "Number/s That Were Chosen The Most By Students Are - " << endl << endl;

    int newLine = 0;

    for (i=0; i<validCount; i++)
    {
        if ((leastCount[i] == least) && (leastCount[i] >=1))
        {
            cout << i << " ";

            newLine++;

            if (newLine % 5 == 0)
            {
                cout << endl;
            }

        }
    }

	return 0;
}
