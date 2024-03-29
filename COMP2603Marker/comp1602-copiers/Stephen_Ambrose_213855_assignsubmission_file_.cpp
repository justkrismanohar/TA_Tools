#include<iostream>
#include<fstream>
using namespace std;

bool perfectsqr(int n)
{
    int i,sum;
    
    for(i=1;i<n; i++)
    {
        if(n%i==0)
        sum=sum+i;
    }
    if(sum==n && n!=1)
    return true;
    else
    return false;
}

bool primenum(int n)
{
    int i;
    
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}

bool perfectsqrsquare(int n)
{
    int i;
    
    for(i=1;i<=n/2;i++)
    {
        if(i*i == n)
        return true;
    }
    return false;
}

bool issphenic(int n)
{
    int i,c=0,prod=1;
    
    for(i=2;i<=n/2;i++)
    {
        if((n%i==0) && primenum(i))
        {
            prod=prod*i;
            c++;
        }
        if((c==3) && (prod==n))
        return true;
        return false;
    }
    return 0;
}

int binaryeq(int n)
{
    int bits[8]={0};
    int i,j;
    for(i=0;n>0;i++)
    {
        bits[i]=n%2;
        n=n/2;
    }
    cout<<"        ";
    for(j=7;j>=0;j--)
    cout<<bits[j];
    return 0;
}


int main()
{
    int invalid[25];
    
    int num,unspecified=0,i=1,j,countvalid=0,num10=0,num20=0,num30=0,num40=0,num50=0,num60=0,num70=0,num80=0,num90=0,num100=0;
    int a,count,nums[9999],countNum[9999],uniqueNum[9999],uniqueIndex,max=0,min=9999;
    int totalnums=0;
    ifstream inf;
    
    inf.open("numbers.txt");
    
    if (!inf.is_open())
    {
        cout << "Error, file is not opening.";
        return 0;
    }
    
    inf>>num;
    cout<<"Number        Perfect?    Prime?        PerfectSquare?    Sphenic?      Binary Equiv."<<endl;
    cout<<"======        =========   ======        ==============    ========      ============"<<endl;
    while(num!=-1)
    {
        totalnums++;
        if(num==0)
        unspecified++;
        else
        if((num<1) || (num>100))
        {
            invalid[i]=num;
            i++;
        }
        else
        {
            nums[countvalid]=num;
            countvalid++;
            cout<<num;
            if(perfectsqr(num))
            cout<<"\t\t\t\t"<<"Y";
            else
            cout<<"\t\t\t\t"<<"N";
            if(primenum(num))
            cout<<"\t\t\t"<<"Y";
            else
            cout<<"\t\t\t"<<"N";
            if(perfectsqrsquare(num))
            cout<<"\t\t\t"<<"Y";
            else
            cout<<"\t\t\t"<<"N";
            if(issphenic(num))
            cout<<"\t\t\t\t\t"<<"Y";
            else
            cout<<"\t\t\t\t\t"<<"N";
            cout<<"\t";
            binaryeq(num);
            cout<<endl;
            
            if ((num>=1) && (num<=10))
            num10++;
            if ((num>=11) && (num<=20))
            num20++;
            if ((num>=21) && (num<=30))
            num30++;
            if ((num>=31) && (num<=40))
            num40++;
            if ((num>=41) && (num<=50))
            num50++;
            if ((num>=51) && (num<=60))
            num60++;
            if ((num>=61) && (num<=70))
            num70++;
            if ((num>=71) && (num<=80))
            num80++;
            if ((num>=81) && (num<=90))
            num90++;
            if ((num>=91) && (num<=100))
            num100++;
        }
        inf>>num;
    }
    cout<<endl<<"=========================================================================================================";
    cout<<endl<<"Invalid Numbers"<<endl;
    for(j=1;j<i;j++)
    {
        cout<<invalid[j]<<" ";
        if(j%5==0)
        cout<<endl;
    }
    cout<<endl<<"=========================================================================================================";
    int highestcount=1;
    cout<<endl<<"Range        Histogram";
    cout<<endl<<"============================"<<endl;
    cout<<"1-10         ";
    while (highestcount <= num10/5){
        cout<<"*";
        highestcount++;
    }
    cout<<endl;
    highestcount=1;
    
    cout<<"11-20        ";
    while (highestcount <= num20/5){
        cout<<"*";
        highestcount++;
    }
    cout<<endl;
    highestcount=1;
    
    cout<<"21-30        ";
    while (highestcount <= num30/5){
        cout<<"*";
        highestcount++;
    }
    cout<<endl;
    highestcount=1;
    
    cout<<"31-40        ";
    while (highestcount <= num40/5){
        cout<<"*";
        highestcount++;
    }
    cout<<endl;
    highestcount=1;
    
    cout<<"41-50        ";
    while (highestcount <= num50/5){
        cout<<"*";
        highestcount++;
    }
    cout<<endl;
    highestcount=1;
    
    cout<<"51-60        ";
    while (highestcount <= num60/5){
        cout<<"*";
        highestcount++;
    }
    cout<<endl;
    highestcount=1;
    
    cout<<"61-70        ";
    while (highestcount <= num70/5){
        cout<<"*";
        highestcount++;
    }
    cout<<endl;
    highestcount=1;
    
    cout<<"71-80        ";
    while (highestcount <= num80/5){
        cout<<"*";
        highestcount++;
    }
    cout<<endl;
    highestcount=1;
    
    cout<<"81-90        ";
    while (highestcount <= num90/5){
        cout<<"*";
        highestcount++;
    }
    cout<<endl;
    highestcount=1;
    
    cout<<"91-100       ";
    while (highestcount <= num100/5){
        cout<<"*";
        highestcount++;
    }
    cout<<endl;
    highestcount=1;
    
    cout<<endl<<"=========================================================================================================";
    cout<<endl<<"Total Valid Favourite Numbers: "<<countvalid;
    cout<<endl<<"Total Invalid Favourite Numbers: "<<i-1;
    cout<<endl<<"Total Unrevealed Favourite Numbers: "<<unspecified;
    cout<<endl<<"=========================================================================================================";
    
    
    for(a=0;a<countvalid;a++)
    {
        countNum[a]=-1;
        uniqueNum[a]=0;
    }
    
    int infalNum[9999];
    int freq[9999];
    
    for(int b=0;b<countvalid;b++){
        count=1;
        for(int c=b+1;c<countvalid;c++){
            if(nums[b]==nums[c]){
                count++;
                countNum[c]=0;
            }
        }
        if(countNum[b] !=0)
        countNum[b]=count;
    }
    for(int b=0;b<countvalid;b++){
        if(countNum[b]!=0){
            infalNum[uniqueIndex]=nums[b];
            freq[uniqueIndex]=countNum[b];
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
            cout<<infalNum[a];
            cout<<" ";
        }
    }
    cout<<endl;
    cout<<"Number/s that were chosen the least: ";
    for(a=0;a<uniqueIndex;a++){
        if(freq[a]==min){
            cout<<infalNum[a];
            cout<<" ";
        }
    }
    
    return 0;
}
