#include<iostream>
#include<fstream>
using namespace std;
bool isPerfect (int num)
{
    int i,sum=0;
    for(i=1; i<num; i++)
    {
        if (num%i==0)
        {
            sum=sum+i;
        }
    }
    if (sum == num && num != 1)
        return true;
    else
        return false;

}

bool isPrime (int num)
{
    int i;
    for(i=2; i<= num/2; i++)
    {
        if(num%i==0)
        {
            return false;
        }
        return true;
    }
}
bool isPerfectsquare(int num)
{
    int s,i;
    for(i=0; i<=num; i++)
    {
        s=i*i;
        if (s==num)
        {
            return true;
        }
    }
    return false;
}
bool isSphenic(int num)
{
    int i,c, prod;
    c=0;
    prod=0;
    for(i=2; i<=num/2; i++)
    {
        if((num%i==0)&& isPrime(i))
        {
            prod=prod*i;
            c++;
        }
        if((c==3)&&(prod==num))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
}
int binary(int num)
{
    int arr[8]={0};
    int j,i=0;
    for(i=0;num>0;i++)
    {
        arr[i]=num%2;
        num=num/2;
    }
    cout<<"          ";
    for (j = 7; j >= 0; j--)
    {
        cout <<arr[j];
    }
    cout<<endl;
    return num;
}
int isInvalid (int invalidarr[100], int k)
{
    int i;
    cout<<"\n-------------------------------------------------------";
    cout<<"\nList of invalid numbers are: "<<endl;
    for(i=1; i<k;i++ )
    {

        cout<<invalidarr[i]<<" ";
        if(i%5==0)
            cout<<endl;

    }

}
int isHistogram(int num1,int num2,int num3,int num4,int num5,int num6,int num7,int num8,int num9,int num10)
{

}
int main()
{
    ifstream in;
    int num,k=1,notrevealed=0,a=0;
    int invalidarr [100];
    int invalidnum;
    int num1=0,num2=0,num3=0,num4=0,num5=0,num6=0,num7=0,num8=0,num9=0,num10=0;

    in.open("numbers.txt");

    if (!in.is_open())
    {
        cout << "File unable to open...";
        return 0;
    }

    cout<<"Number "<<"Perfect? "<<"Prime? "<<"Perfect Square? "<<"Sphenic? "<<"Binary Equiv."<<endl;
    cout<<"===================================================================================="<<endl;
    in>>num;
    while(num != -1)
    {
        if((num>=1)&&(num<=100))
        {
            cout<<" "<<num;
            a++;
            if (isPerfect(num))
                cout<<"\t"<<"  Y";
            else
                cout<<"\t"<<"  N";

            if (isPrime(num))
                cout<<"\t"<<"   Y";
            else
                cout<<"\t"<<"   N";

            if (isPerfectsquare(num))
                cout<<"\t"<<"    Y";
            else
                cout<<"\t"<<"    N";
            if (isSphenic(num))
                cout<<"\t     "<<"    Y";
            else
                cout<<"\t     "<<"    N";
            binary(num);

        }
        else
        {
            if(num != 0)
            {
                invalidarr[k]=num;
                k++;

            }
            else
            {
                notrevealed++;
            }

        }
        if ((num>=1) && (num<=10))
            num1++;
        if ((num>=11) && (num<=20))
            num2++;
        if ((num>=21) && (num<=30))
            num3++;
        if ((num>=31) && (num<=40))
            num4++;
        if ((num>=41) && (num<=50))
            num5++;
        if ((num>=51) && (num<=60))
            num6++;
        if ((num>=61) && (num<=70))
            num7++;
        if ((num>=71) && (num<=80))
            num8++;
        if ((num>=81) && (num<=90))
            num9++;
        if ((num>=91) && (num<=100))
            num10++;

        in>>num;

    }
    isInvalid(invalidarr,k);
    cout<<endl<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Amount of valid favourite numbers: "<<a<<endl;
    cout<<"Amount of invalid favourite numbers: "<<k-1<<endl;
    cout<<"Hidden favourite numbers: "<<notrevealed<<endl;
}
