#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


bool perfect(int num);
bool prime(int num);
bool perfectSquare(int num);
bool sphenic(int num);
void binaryNumber(int num);
void stars(int category);
int rem[8];

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

bool perfectSquare(int num)
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
for(i=2; i<num; i=i+1)
    {
        if(num%i==0)
        {
            primeCheck=true;

            if(i==2)
            {
                primeNumbers[count]=2;
                count=count+1;

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
                    count=count+1;
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
        rem[i] = num%2;
        num = num/2;
        i--;
    }
    while(num==0 && i!=0)
    {
        rem[i]=0;
        i--;
    }
}

void stars(int category)
{
    while(category>=5)
    {
        category -=5;
        cout << "*";
    }
}




int main()
{

int choiceNum,  favNum[100], valid = 0, invalid[100], notrevealed = 0, invalidCount = 0,most = 0, least = 101, mostValue[100], leastValue[100];
int binarynumber[8], category[10]= {0,0,0,0,0,0,0,0,0,0};
int i=0,count=0,n=0,line=0,leastline=0;


for(i=0; i<100; i=i+1)
    {
        favNum[i]= 0;
    }

    ifstream in;
    in.open("numbers.txt");

    if(!(in.is_open()))
    {
        cout << "File not found.\n";
        return 0;
    }

    cout << "Number\t\tPerfect?\t\tPrime?\t\tPerfect Square?\t\tSphenic?\t\tBinary Equivalent\n";
    cout << "==========================================================================================\n";
    in >> choiceNum;

    while(choiceNum!=-1)
    {
	

        if((choiceNum>0) && (choiceNum<=100))
        {
            for(i=0; i<100; i=i+1)
            {

                if(choiceNum == (i+1))
                {
                    favNum[i]++;
                    break;
                }

            }
            for(i=0; i<100; i=i+1)
            {
                if((choiceNum == i+1) && (favNum[i]==1))
                {

                    binaryNumber(choiceNum);

                    cout << choiceNum << "\t\t";
                    if(perfect(choiceNum))
                    {
                        cout << "Y\t\t\t";
                    }
                    else
                    {
                        cout << "N\t\t\t";
                    }
                    if(prime(choiceNum))
                    {
                        cout << "Y\t\t";
                    }
                    else
                    {
                        cout << "N\t\t";
                    }
                    if(perfectSquare(choiceNum))
                    {
                        cout << "Y\t\t\t";
                    }
                    else
                    {
                        cout << "N\t\t\t";
                    }
                    if(sphenic(choiceNum))
                    {
                        cout << "Y\t\t\t";
                    }
                    else
                    {
                        cout << "N\t\t\t";
                    }

                    for(i=0; i<8; i=i+1)
                    {
                        cout << rem[i];
                    }
                    cout << endl;

                    break;

                }

            }

            valid=valid+1;
            if(choiceNum>=1 && choiceNum<=10)
            {
                category[0]++;
            }
            else if((choiceNum>10) && (choiceNum<=20))
            {
                category[1]++;
            }
            else if((choiceNum>20) && (choiceNum<=30))
            {
                category[2]++;
            }
            else if((choiceNum>30) && (choiceNum<=40))
            {
                category[3]++;
            }
            else if((choiceNum>40) && (choiceNum<=50))
            {
                category[4]++;
            }
            else if((choiceNum>50) && (choiceNum<=60))
            {
                category[5]++;
            }
            else if((choiceNum>60) && (choiceNum<=70))
            {
                category[6]++;
            }
            else if((choiceNum>70) && (choiceNum<=80))
            {
                category[7]++;
            }
            else if((choiceNum>80) && (choiceNum<=90))
            {
                category[8]++;
            }
            else if((choiceNum>90) && (choiceNum<=100))
            {
                category[9]++;
            }


        }
        else if(choiceNum ==0)
        {
            notrevealed=notrevealed+1;
        }
        else
        {
            invalidCount=invalidCount+1;
            invalid[count] = choiceNum;
            count=count+1;
        }

        in >> choiceNum;
    
}

    cout << "\n\nInvalid: \n";

    for(i=0; i<count; i=i+1)
    {
        cout << invalid[i] << "\t\t";
        line=line+1;
        if(line==5)
        {
            cout << endl;
            line = 0;
        }
    }


    cout << "\n\nRange\t\tHistogram\n";
    cout <<"=====================================\n";
    n=1;
    for(i=0; i<10; i=i+1)
    {
        cout << n << "-" << n+9 << "\t\t" ;
        stars(category[i]);
        n+=10;
        cout << endl;
    }
    n=0;


    cout << "Students who specified valid favourite numbers: " << valid << endl;
    cout << "Number of students who specified invalid favourite number: " << invalidCount << endl;
    cout << "Number of students who did not reveal their favourite number: " << notrevealed << endl;

    for(i=0; i<100; i=1+1)
    {
        if(favNum[i]>=2)
        {
            if(favNum[i]>most)
            {
                most = favNum[i];
                mostValue[0] = i+1;

            }
        }

        if(favNum[i]>=1)
        {
            if(favNum[i]<least)
            {
                least = favNum[i];
                leastValue[0] = i+1;
            }
        }
    }

    n= 0;
    count = 0;

    for(i=0; i<100; i=i+1)
    {
        if(favNum[i]>2)
        {
            if((favNum[i]==most) && ((i+1)!=mostValue[0]))
            {
                n=n+1;
                mostValue[n] = i+1;

            }
        }

            if((favNum[i]==least) && ((i+1)!=leastValue[0]))
            {
                count=count+1;
                leastValue[count] = i+1;

            }
    }

    cout <<endl;

    if(n==0)
    {
        cout << "The number chosen the most by the students: " << mostValue[0] << endl ;
    }
    else
    {
        cout << "The numbers chosen the most by the students are: \n";
        for(i=0; i<n; i=i+1)
        {
            cout << mostValue[i] <<endl;
        }
    }

    cout <<endl;
    if(count==0)
    {
        cout << "The number chosen the least by the students: " << leastValue[0] << endl ;
    }
    else
    {
        cout << "The numbers chosen the least by the students are: \n";
        for(i=0; i<count; i=i+1)
        {
            cout << leastValue[i] << " ";
            leastline=leastline+1;
            if(leastline==5)
            {
                cout <<endl;
                leastline=0;
            }
        }
    }






    in.close();

    system("pause");

    return 0;

}

