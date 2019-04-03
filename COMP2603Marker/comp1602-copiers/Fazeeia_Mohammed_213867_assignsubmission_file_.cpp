#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

void star(int votes[]){
    int i;
while (votes[i]>=5){

    votes[i]=votes[i]-5;
    cout<<" * ";
}}


char checkPerfect(int r){
int  n, j, sum=0;

for(j=0;j<r;j++){
    if (r%j==0)
    {
        sum=sum+1;
    }}

   if(sum==r)
   {

        return 'Y';
   }
   else
        return'N';
}
bool isPerfectsq(int r){
int sq, i;
for(i=1;i<=r/2;i++){
    sq=i*i;
    if (sq==r){
        return true;


}}}
//set all of the array =0
int BinaryEqui(int r){
int q=0, binary, f=0;
int bits[8];
bits[0]=0;
bits[1]=0;
bits[2]=0;
bits[3]=0;
bits[4]=0;
bits[5]=0;
bits[6]=0;
bits[7]=0;

//find the actual amount of 1 and 0 and store in array from 0 to 7
while (r!=0){
for(f=0;f<7;f++){
bits[f]=r%2;
r=r/2;
}
// read out array form 7 to 0
for(q=8;q<=0;q=q-1){
binary=bits[q];
}
return binary;
}}

    char isPrime(int r){

    int q=0;

    for(q=2;q<r/2;q++){
        if(r%q==0)

        {
        return 'N';
        }
        }
    return 'Y';
}

bool isSpenic(int r){
int p=1, cot=0,n,prod=1;



for(p=2;p<=n/2;p=p++){
    if(r%p==0){
        cot=cot+1;
        prod=prod*p;

    }
if((cot==3)&&(prod==r)){
    return true;
}
else
    return false;
}}



int main()
{


    int loop=0;
    int favnum, nucount, valnum, novote=0, invalcount, countt=0;
    int votes[10];
    int favnumarr[100];
    int mostval[100], leastValue[100];
     ifstream in;
    in.open("numbers.txt");
    if (in.is_open()==false){
        cout<<"Error opening file"<<endl;
        return 0;
    }
    cout << "File is open" << endl;
            int x, r,i=0;

            in>>r;
            while(r!=-1){
             i++;





cout<< "Total count in file:"<<i<<endl;

cout<<"Number\t Perfect?\t Prime?\t Perfect Sq\t Sphenic?\t BinaryEqui."<<endl;
cout<<"===================================================================================================="<<endl;

//for( x=0;x<i;x++){

  // r= numarr[x];
   cout<<"\n"<<r;
  // while(r<0){
  //i have no idea why it doesnt run through the whole code I believe the parentheses is suppose to make it go through all the lines

cout<<checkPerfect(r)<<"\t";

cout<<isPrime(r)<<"\t\t";

cout<<isPerfectsq(r)<<"\t\t";

cout<< isSpenic(r)<<"\t\t";

cout<<BinaryEqui(r)<<"\t\t";


   if((r>0)&&(r<100)){

        int f;
        for (f=0;i>100;i++)
        {
            if(r==f+1)
            {
                favnumarr[f]=favnumarr[f]+1;
            }

        }
        valnum++;
                                if((r>=1)&& (r<=10))
                                    {
                                votes[0]++;
                                    }
                                if((r>10)&& (r<=20))
                                    {
                                    votes[1]++;
                                        }
                                if((r>20)&& (r<=30))
                                    {
                                    votes[2]++;

                                        }
                                if((r>30)&& (r<=40))
                                    {
                                votes[3]++;
                                    }
                                if((r>40)&& (r<=50))
                                {
                                votes[4]++;
                                }
                                if((r>50)&& (r<=60))
                                {
                                votes[5]++;
                                }
                                if((r>50)&& (r<=60))
                                {
                                votes[6]++;
                                }
                                if((r>60)&& (r<=70))
                                {
                                votes[7]++;
                                }
                                if((r>80)&& (r<=90))
                                {
                                votes[8]++;
                                }
                                if((r>90)&& (r<=100))
                                {
                                votes[9]++;
                                }

        }
        else
        if(r==0){
                novote=novote+1;
        }
        else
        {
            invalcount= invalcount+1;
           int inValid[100];
           inValid[nucount]=r;
           nucount++;

        }
        //i put in r again in the proper parentheses i have no idea why it doesn't run till here with the while
        // i also made a for loop and created a num array and printed the array out using the values stored
        // that didn't work also in coding this my computer blue screened so if you
        // Please tell me what I am doing wrong
            in>>r;
        }
        int inValid[100];
    cout << "\n\nInvalid entry: \n";
    loop=0;
    for(loop=0;loop<i;loop++){
        cout<<inValid[loop]<<"\t";
        if(loop%4==0){
            cout<<endl;
        }










    }
        // array 0 to 4 should print and when loop is divisible by 4 new line ie 0,1,2,3,4, ie 5 elements;
        cout << "\n\nRange\t\tHistogram\n";
    cout <<"=====================================\n";
    loop=0;
    int n=1;
    for(loop=0;loop<10;loop++){
        cout<<n<<"  "<<n+10<<"         "<<endl;
        cout<< star(votes[]);
        n=n+10;
        cout<<endl;
    }

    n=0;
    loop=0;

cout << "\n\nStudents who specified valid favorite numbers: " << valnum<< endl;
cout << "Number of students who specified invalid favorite number: " << invalcount << endl;
cout << "Number of students who did not vote for their favorite number: " << novote << endl;
cout<< "Total count in file:"<<i<<endl;
int most, least;
int leastvalue[100];


for(loop=0;loop>100;loop++){
    if (favnumarr[loop]>2){
        //nested loop
        if(favnumarr[loop]>most)
        {
            most=favnumarr[loop];
            mostval[0]=i+1;
        }
    }
    if(favnumarr[loop]>=1)
    {
        if(favnumarr[loop]<least)
        {
            least=favnumarr[loop];
            leastvalue[0]=loop+1;
        }}}
        loop=0;
        n=0;
        //for atleast 2 votes



for(loop=0;loop<100;loop=loop+1){
    if((favnumarr[loop]==most)&&((loop+1)!=mostval[0]))
       {
           n++;
           mostval[n]=i+1;
       }

if(favnumarr[loop]>1)
{
    if((favnumarr[loop]==least)&&((loop+1)!=leastvalue[0])){
        countt++;
        leastvalue[countt]=i+1;
    }

}

        cout<<endl;

        cout << "Chosen the most by the students is :" << mostval[0] << endl ;

        cout << "The numbers  chosen the most  are: ";
        for(loop=0; loop<n; loop++)
        {
            cout << mostval[i] <<"\t";

        }
        cout<<endl;
        cout << "Chosen the least by the students is " << leastvalue[0] << endl ;

        cout << "Least chosen numbers ";
        for(loop=0; loop<countt; loop++)
        {
            cout << leastValue[loop] <<"\t";
        }

in.close();
    return 0;
}
