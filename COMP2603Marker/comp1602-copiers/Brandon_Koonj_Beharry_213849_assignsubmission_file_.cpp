#include <iostream>
#include <fstream>
using namespace std;

bool perfect(int num)
{
	int i, sum;
	
	sum = 0;
	
	for (i = 1; i < num; i++)
	{
		if (num % i == 0)
		{
			sum = sum + i;
		}
		
		if (sum == num)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

//-------------------------------------------------------------

bool prime(int num)
{
	int i;
	
	for(i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}	
	
}

//-------------------------------------------------------------

bool perfectSquare(int num)
{
	int i;
	
	i = 1;
	
	while (i <= num)
	{
		if (i * i == num)
		{
			return true;
		}
		else
		{
			return false;
			
			i++;
		}	
	}
		
}

//-------------------------------------------------------------

bool sphenic (int num)
{
	int i, product, count;
	
	product = 1;
	count = 0;
	
	for (i = 2; i <= num; i++)
	{
		if ((num % i == 0) && (prime(i)))
		{
			product = product * i;
			count = count + 1;
			
		}
	}
	
	if ((count ==3) && (product == num))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//-------------------------------------------------------------

void binary (int num)
{
	int bin[8], i;
	
	for (i = 0; i < 8; i++)
	{
		bin[i] = num % 2;
		num = num / 2;
	}
	
	for (i = 7; i >= 0; i--)
	{
		cout << bin[i];
	}
}

//-------------------------------------------------------------

void histogram (int range_counter)
{
	while(range_counter >= 5)
	{
		range_counter =  range_counter - 5;
		cout << "*";
	}
}

//-------------------------------------------------------------

int main ()
{
	ifstream ifile;
	int numbers[1000], numbers_temp, i, j, n, m, invalid[1000], range[10], most[100], least[100];
	int num_count[100], num_amount[100], max_amt, max_num, min_amt, min_num;
	int zero_counter, invalid_counter, counter;
	bool b;
	
	ifile.open("numbers.txt");
	
	if (!ifile.is_open())
	{
		cout << "Error opening output file. Aborting...";
		return 0;
	}
	
	n = 1;
	i = 0;
	j = 0;
	counter = 0;
	invalid_counter = 0;
	zero_counter = 0;
	
	for (i = 0; i < 10; i++)
	{
		range[i] = 0;
	}
	
	ifile >> numbers_temp;
	
	while (numbers_temp != -1)
	{
		if ((numbers_temp >= 1) && (numbers_temp <= 100))
		{
			numbers[counter] = numbers_temp;
			
			counter = counter + 1;

			
			if ((numbers_temp >= 1) && (numbers_temp <= 10))
			{
				range[0] = range[0] + 1 ;
			}
			
			if ((numbers_temp >= 11) && (numbers_temp <= 20))
			{
				range[1] = range[1] + 1 ;
			}
			
			if ((numbers_temp >= 21) && (numbers_temp <= 30))
			{
				range[2] = range[2] + 1 ;
			}
			
			if ((numbers_temp >= 31) && (numbers_temp <= 40))
			{
				range[3] = range[3] + 1 ;
			}
			
			if ((numbers_temp >= 41) && (numbers_temp <= 50))
			{
				range[4] = range[4] + 1 ;
			}
			
			if ((numbers_temp >= 51) && (numbers_temp <= 60))
			{
				range[5] = range[5] + 1 ;
			}
			
			if ((numbers_temp >= 61) && (numbers_temp <= 70))
			{
				range[6] = range[6] + 1 ;
			}
			
			if ((numbers_temp >= 71) && (numbers_temp <= 80))
			{
				range[7] = range[7] + 1 ;
			}
			
			if ((numbers_temp >= 81) && (numbers_temp <= 90))
			{
				range[8] = range[8] + 1 ;
			}
			
			if ((numbers_temp >= 91) && (numbers_temp <= 100))
			{
				range[9] = range[9] + 1 ;
			}
		}
		
		else if (numbers_temp == 0)
		{
			zero_counter = zero_counter + 1;
		}
		
		else
		{
			invalid[j] = numbers_temp;
			
			invalid_counter = invalid_counter + 1;
			
			j++;
			
		}
		
			ifile >> numbers_temp;
		
	}

//Output values-----------------------------------------------------------------------------------------------------
	
	cout << "Number		Perfect?		Prime?		Perfect Square?		Sphenic?		   Binary Equiv" << endl;
	cout << "======		========		======		===============		========		   ============" << endl;
	
	for (i = 0; i < counter; i++)
	{
		for (j=0; j<i; j++)
		
            if (numbers[i] == numbers[j])
               {
			   break;
			   }

		if (i == j)
		{
			cout << numbers[i] << "		";
			
			if (perfect(numbers[i]))
				cout << "Y			";
			else
				cout << "N			";
//-------------------------------------------------------------
			if (prime(numbers[i]))
				cout << "Y		";
			else
				cout << "N		";
//-------------------------------------------------------------	
			if (perfectSquare(numbers[i]))
				cout << "Y			";
			else
				cout << "N			";
//-------------------------------------------------------------
			if (sphenic(numbers[i]))
				cout << "Y			";
			else
				cout << "N			";
//-------------------------------------------------------------
			binary(numbers[i]);
			
			cout << endl;
		}
	}
	
//Output invalid numbers--------------------------------------------------------------------------------------------	
	
	for (i = 0; i < invalid_counter; i++)
	{
		if (i % 5 == 0)
		{
			cout << endl;
			cout << invalid[i] << "		";
		}
		else
		{
			cout << invalid[i] << "		";
		}
	}
	
//Histogram---------------------------------------------------

	cout << endl << endl;
	cout << "Range		Histogram" << endl;
	cout << "==========================" << endl;

for (i = 0; i < 10; i++)
	{
		cout << n << "-" << n+9 << "		|";
		histogram (range[i]);
		n = n + 10;
		cout << endl;
	}
	
//output valid, invalid and not revealed counts--------------------------------------------------------------------
	
	cout << endl;
	cout << "Amount of students who specified favourite valid number = " << counter << endl;
	cout << "Amount of students who specified favourite invalid number = " << invalid_counter << endl;
	cout << "Amount of students who did not reveal their favourite number = " << zero_counter << endl;
	cout << endl;
//---------------------------------------------------------
	for	(i = 0; i < 100; i++)
	{
		num_count[i] = i + 1;
		num_amount[i] = 0;
	}
	
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < counter; j++)
		{
			if (numbers[j] == num_count[i])
			{
				num_amount[i] = num_amount[i] + 1;
			}
		}
	}
	
	
//Max & min----------------------------------------------
//Max----------------------------------------------------
	max_amt = 0;
	
	for (i = 0; i < 100; i++)
	{
		if (num_amount[i] > max_amt)
		{
			max_amt = num_amount[i];
			max_num = num_count[i];
		}
	}

	cout << "Number(s) chosen the most times" << endl;
	
	m = 0;
	
	for (i = 0; i < 100; i++)
	{
		most[i] = 0;
		least[i] = 0;
	}
		
	for (i = 0; i < 100; i++)
	{
		if (num_amount[i] == max_amt)
		{
			most[m] = num_count[i];
			
			m++;
		}
	}
	
	for (i = 0; i < 100; i++)
	{
		if (most[i] != 0)
		{
			cout << most[i] << "	";
		}
		
		if ((i % 5 == 4) && (most[i] != 0))
		{
			cout << endl;
		}

	}

	
	cout << endl << endl;

//Min-------------------------------------------------
	min_amt = 900;
	
	for (i = 0; i < 100; i++)
	{
		if ((num_amount[i] < min_amt) && (num_amount[i] > 0))
		{
			min_amt = num_amount[i];
			min_num = num_count[i];
		}
	}
	
	cout << "Number(s) chosen the least times" << endl;
	
	m = 0;
	
	for (i = 0; i < counter; i++)
	{
		
		if (num_amount[i] == min_amt)
		{
			least[m] = num_count[i];
			m++;
		}
	}
	
		for (i = 0; i < 100; i++)
		{
			if (least[i] != 0)
			{
				cout << least[i] << "	";
			}
			
			if ((i % 5 == 4) && (least[i] != 0))
			{
				cout << endl;
			}

	}
	
	
	ifile.close();

	return 0;
}


