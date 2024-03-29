#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void binaryNumber(int num);
bool sphenic(int num);
bool perfect_square(int num);
bool prime(int num);
bool perfect(int num);
void print_stars(int category_count);

int bit[8];

bool perfect(int num)
{
    int sum = 0, i =0 ;

    for(i=1; i<num; i++)
    {
        if(num%i==0)
        {
            sum+=i;
        }
    }

    if(sum==num)
    {
        return true;
    }

    return false;

}

bool prime(int num)
{
    int i;

    for(i=2; i<num; i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }

    return true;
}

bool perfect_square(int num)
{
    int i;

    for(i=1; i<num; i++)
    {
        if(i*i==num)
        {
            return true;
        }
    }

    return false;
}

bool sphenic(int num)
{
    int i, primeNumbers[3], n, count=0;
    bool primeCheck;
    for(i=2; i<num; i++)
    {
        if(num%i==0)
        {
            primeCheck=true;

            if(i==2)
            {
                primeNumbers[count]=2;
                count++;

            }
            else
            {
                for(n=2; n<i; n++)
                {
                    if(i%n==0)
                    {
                        primeCheck = false;
                        break;
                    }
                }


                if(primeCheck==true)
                {
                    primeNumbers[count] = i;
                    count++;
                }
            }
        }
    }

    if((primeNumbers[0])*(primeNumbers[1])*(primeNumbers[2])==num)
    {
        return true;
    }

    return false;
}


void binaryNumber(int num)
{
    int i=7;


    while(num!=0)
    {
        bit[i] = num%2;
        num = num/2;
        i--;
    }
    while(num==0 && i!=0)
    {
        bit[i]=0;
        i--;
    }
}

void print_stars(int category_count)
{
    while(category_count>=5)
    {
        category_count -=5;
        cout << "*";
    }
}

int main()
{

    int choice, i=0, favNumber[100], validNum = 0, invalidNum[100], noreveal = 0, invalidNumCount = 0,most = 0, least, mostValue[10], leastValue[10];
    int bin_num[8], n=0, count =0, line=0, category[10]= {0,0,0,0,0,0,0,0,0,0};

    ifstream numbers;
    numbers.open("numbers.txt");

    if(!(numbers.is_open()))
    {
        cout << "File not found.\n";
        return 0;
    }

    cout << "Number\t\tPerfect?\t\tPrime?\t\tPerfect Square?\t\tSphenic?\t\tBinary Equivalent\n";
    cout << "=======================================================================================================================\n";
    numbers >> choice;

    while(choice!=-1)
    {

        if((choice>0) && (choice<=100))
        {
            for(i=0; i<100; i++)
            {
                if(choice == i+1)
                {
                    favNumber[i]++;
                    break;
                }
            }
            validNum++;
            if(choice>=1 && choice<=10)
            {
                category[0]++;
            }
            else if((choice>10) && (choice<=20))
            {
                category[1]++;
            }
            else if((choice>20) && (choice<=30))
            {
                category[2]++;
            }
            else if((choice>30) && (choice<=40))
            {
                category[3]++;
            }
            else if((choice>40) && (choice<=50))
            {
                category[4]++;
            }
            else if((choice>50) && (choice<=60))
            {
                category[5]++;
            }
            else if((choice>60) && (choice<=70))
            {
                category[6]++;
            }
            else if((choice>70) && (choice<=80))
            {
                category[7]++;
            }
            else if((choice>80) && (choice<=90))
            {
                category[8]++;
            }
            else if((choice>90) && (choice<=100))
            {
                category[9]++;
            }
            binaryNumber(choice);

            cout << choice << "\t\t";
            if(perfect(choice))
            {
                cout << "Y\t\t\t";
            }
            else
            {
                cout << "N\t\t\t";
            }
            if(prime(choice))
            {
                cout << "Y\t\t";
            }
            else
            {
                cout << "N\t\t";
            }
            if(perfect_square(choice))
            {
                cout << "Y\t\t\t";
            }
            else
            {
                cout << "N\t\t\t";
            }
            if(sphenic(choice))
            {
                cout << "Y\t\t\t";
            }
            else
            {
                cout << "N\t\t\t";
            }

            for(i=0; i<8; i++)
            {
                cout << bit[i];
            }
            cout << endl;


        }
        else if(choice ==0)
        {
            noreveal++;
        }
        else
        {
            invalidNumCount++;
            invalidNum[count] = choice;
            count++;
        }

        numbers >> choice;
    }

    cout << "\n\nInvalid entry: \n";

    for(i=0; i<count; i++)
    {
        cout << invalidNum[i] << "\t\t";
        line ++;
        if(line==5)
        {
            cout << endl;
            line = 0;
        }
    }


    cout << "\n\nRange\t\tHistogram\n";
    cout <<"=====================================\n";
    n=1;
    for(i=0; i<10; i++)
    {
        cout << n << "-" << n+9 << "\t\t" ;
        print_stars(category[i]);
        n+=10;
        cout << endl;
    }
    n=0;


    cout << "\n\nAmount of the students who specified valid favourite numbers: " << validNum << endl;
    cout << "Amount of students who specified invalid favourite number: " << invalidNumCount << endl;
    cout << "Number of students who did not reveal their favourite number: " << noreveal << endl;

    for(i=0; i<100; i++)
    {
        if(favNumber[i]>2)
        {
            if(favNumber[i]>most)
            {
                most = favNumber[i];
                mostValue[0] = i+1;

            }
        }

        if(favNumber[i]>=1)
        {
            if(favNumber[i]<least)
            {
                least = favNumber[i];
                leastValue[0] = i+1;
            }
        }
    }

    n= 0;
    count = 0;

    for(i=0; i<100; i++)
    {
        if(favNumber[i]>2)
        {
            if((favNumber[i]==most) && ((i+1)!=mostValue[0]))
            {
                n++;
                mostValue[n] = i+1;

            }
        }

        if(favNumber[i]>=1)
        {
            if((favNumber[i]==least) && ((i+1)!=leastValue[0]))
            {
                count++;
                leastValue[count] = i+1;

            }
        }
    }

    cout <<endl;

    if(n==0)
    {
        cout << "The number that was chosen the most by the students is " << mostValue[0] << endl ;
    }
    else
    {
        cout << "The numbers that were chosen the most by the students are: \n";
        for(i=0; i<n; i++)
        {
            cout << mostValue[i] <<endl;
        }
    }

    cout <<endl;
    if(count==0)
    {
        cout << "The number that was chosen the least by the students is " << leastValue[0] << endl ;
    }
    else
    {
        cout << "The numbers that were chosen the least by the students are: \n";
        for(i=0; i<count; i++)
        {
            cout << leastValue[i] <<endl;
        }
    }






    numbers.close();

    system("pause");

    return 0;
}



