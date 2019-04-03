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
    ifstream fin;
    int num,k=1,notrevealed=0,j=0;
    int invalidarr [100];
    int hCount;
    int num1=0,num2=0,num3=0,num4=0,num5=0,num6=0,num7=0,num8=0,num9=0,num10=0;
    int a,countN[9999],Unum[9999],count,nums[9999],uniqueIndex,max=0,min=9999;
//int a,numCount=0,count,nums[9999],countNum[9999],uniqueNum[9999],uniqueIndex,max=0,min=9999;
    fin.open("numbers.txt");

    if (!fin.is_open())
    {
        cout << "File unable to open...";
        return 0;
    }

    cout<<"Number "<<"Perfect? "<<"Prime? "<<"Perfect Square? "<<"Sphenic? "<<"Binary Equiv."<<endl;
    cout<<"===================================================================================="<<endl;
    fin>>num;
    while(num != -1)
    {
        if((num>=1)&&(num<=100))
        {
        	nums[j]=num;
            cout<<" "<<num;
            j++;
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
                cout<<"\t"<<"       Y";
            else
                cout<<"\t"<<"       N";
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

        fin>>num;

    }
    cout<<endl<<endl;
    isInvalid(invalidarr,k);
    cout<<endl<<endl;
     hCount=1;
    cout<<endl<<"Range  Histogram";
	cout<<endl<<"===================="<<endl;
	cout<<"1-10	";
	while (hCount <= num1/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;

	cout<<"11-20	";
	while (hCount <= num2/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;

	cout<<"21-30	";
	while (hCount <= num3/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;

	cout<<"31-40	";
	while (hCount <= num4/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;

	cout<<"41-50	";
	while (hCount <= num5/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;

	cout<<"51-60	";
	while (hCount <= num6/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;

    cout<<"61-70	";
    while (hCount <= num7/5)
    {
        cout<<"*";
        hCount++;
    }
	cout<<endl;
	hCount=1;

	cout<<"71-80	";
	while (hCount <= num8/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;

	cout<<"81-90	";
	while (hCount <= num9/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;

	cout<<"91-100	";
	while (hCount <= num10/5){
		cout<<"*";
		hCount++;
	}
	cout<<endl;
	hCount=1;
    cout<<endl<<endl;
    cout<<"Valid favourite numbers: "<<j<<endl;
    cout<<"Invalid favourite numbers: "<<k-1<<endl;
    cout<<"Not revealed favourite numbers: "<<notrevealed<<endl;

   for(a=0;a<j;a++)
	{
		countN[a]=-1;
		Unum[a]=0;
	}

	int finalNum[9999];
	int freq[9999];

	for(int b=0;b<j;b++){
		count=1;
		for(int c=b+1;c<j;c++){
			if(nums[b]==nums[c]){
				count++;
				countN[c]=0;
			}
		}
		if(countN[b] !=0)
			countN[b]=count;
	}

	for(int b=0;b<a;b++){
		if(countN[b]!=0){
			finalNum[uniqueIndex]=nums[b];
			freq[uniqueIndex]=countN[b];
			uniqueIndex++;
		}
	}

	for(a=0;a<uniqueIndex;a++){
		if(freq[a]>max)
			max= freq[a];
		if(freq[a]<min)
			min=freq[a];
	}

	cout<<endl<<"Number/s that were chosen the most: ";
	for(a=0;a<uniqueIndex;a++){
		if(freq[a]==max){
			cout<<finalNum[a];
			cout<<" ";
		}
	}
	cout<<endl;
	cout<<"Number/s that were chosen the least: "<<endl;
	for(a=0;a<uniqueIndex;a++){
		if(freq[a]==min){
			cout<<finalNum[a];
			cout<<" ";
		}
	}

	return 0;
}

