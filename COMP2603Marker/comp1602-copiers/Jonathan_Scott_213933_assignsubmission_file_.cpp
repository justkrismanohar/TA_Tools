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
    cout<<"Invalid numbers are: "<<endl;
    for(i=1; i<k;i++ )
    {

        cout<<invalidarr[i]<<" ";
        if(i%5==0)
            cout<<endl;

    }

}

int main()
{
    ifstream in;
    int num,k=1,notrevealed=0,a=0;
    int invalidarr [100];
    int invalidnum;
    int i,o;
    int histogram [10]={0,0,0,0,0,0,0,0,0,0};

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
            if (isPerfect(num)==true)
                cout<<"\t"<<"  Y";
            else
                cout<<"\t"<<"  N";

            if (isPrime(num)==true)
                cout<<"\t"<<"   Y";
            else
                cout<<"\t"<<"   N";

            if (isPerfectsquare(num)==true)
                cout<<"\t"<<"    Y";
            else
                cout<<"\t"<<"    N";
            if (isSphenic(num)==true)
                cout<<"\t"<<"    Y";
            else
                cout<<"\t"<<"    N";
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
            histogram[0]++;
        if ((num>=11) && (num<=20))
            histogram[1]++;
        if ((num>=21) && (num<=30))
            histogram[2]++;
        if ((num>=31) && (num<=40))
            histogram[3]++;
        if ((num>=41) && (num<=50))
            histogram[4]++;
        if ((num>=51) && (num<=60))
            histogram[5]++;
        if ((num>=61) && (num<=70))
            histogram[6]++;
        if ((num>=71) && (num<=80))
            histogram[7]++;
        if ((num>=81) && (num<=90))
            histogram[8]++;
        if ((num>=91) && (num<=100))
            histogram[9]++;

        in>>num;

    }
    isInvalid(invalidarr,k);
    cout<< endl<<endl<<endl;
    cout<<"\t\tRANGE\t\t\tHistogram"<<endl;
    o=1;
    for (i=0;i<10;i++){
    cout<<"\t\t"<<o<<"-"<<o+9<<endl;
    o=o+10;
}    
    while(histogram[i]>=5){
    	histogram[i]-=5;
    
    }
    cout<<endl<<endl;
    cout<<"Valid favourite numbers: "<<a<<endl;
    cout<<"Invalid favourite numbers: "<<k-1<<endl;
    cout<<"Not revealed favourite numbers: "<<notrevealed<<endl;
}
