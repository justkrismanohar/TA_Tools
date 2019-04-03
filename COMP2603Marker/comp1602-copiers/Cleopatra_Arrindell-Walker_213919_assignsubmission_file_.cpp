#include <iostream>
#include <fstream>

//813001054 Cleopatra Arrindell-Walker

using namespace std;

//part (i)
bool isPerfect(int num){
    int sum=0, div;

    for(int i=1; i<num; i++){
            div=num%i;
        if(div%i==0){
            sum +=i;
}
}
    if(sum==num)
        return true;
    return false;
}
//part (ii)

bool isPrime(int num){
    for(int i=2; i<num/2; i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

//part (iii)
bool isPerfectSquare(int num){
    int i=1;
    while(num>0){
        num -=i;
        i +=2;
    }
    return num==0;
}

//part (iv)

bool isSphenic(int num){

    int table[num+1],ans=0;

    table[0]=0;
    table[1]=1;

    for(int i=0; i<=num;i++)
        table[i]=1;
    for(int i=2; i<=num; i++){
       for(int j=i+1; i<=num; i++)
            if(j%i==0)
                table[j]=0;
        }
       for(int i=2; i<=num; i++){
            if(table[i]==1){
                if(num%table[i]==0){
                    num /=i;
                   ans++;
                }
            }
            if(num==1)
                break;
        }
        if(ans==3)
            return true;
        return false;
    }


//part (v)
void deciToBin(int num){

    int remainder[101]={},i=0;

    while(num>0){
        remainder[i]=num%2;
        num /=2;
       i++;
    }
    int bits =8;
    if(i>8)
        bits=(8*(i+7)/8);
    for(int j=bits-1; j>=0;j--){
        cout<<remainder[j];
    }
}


void printStars(int numStars){
    for(int i=1; i<=numStars; i++)
        cout<<"*";
    cout<<endl;
}


int getMost(int table[], int maxSize){
int cMost=table[0], mCount=0,mElement=0;
    for(int i=0; i<maxSize;i++){
    for(int j=i; j<maxSize; j++){
        if(table[i] ==table[j])
            cMost=1;
            cMost++;
    }

     if(cMost >mCount){
        mCount=cMost;
           mElement=table[i];
          }
    }
    return mElement;
}

int getLeast(int table[], int maxSize){
int cLeast=maxSize, lCount=0,lElement=0;
    for(int i=0; i<maxSize;i++){
    for(int j=i; j<maxSize; j++){
        if(table[i] ==table[j])
            cLeast=1;
            cLeast++;
    }

     if(cLeast <lCount){
        lCount=cLeast;
        lElement=table[i];

          }
    }
    return lElement;
}


void printInvalid(int num){

   for(int i=0;i<num; i++){
     if(i<1 || i>100){
    cout<<i<<"\t";
    }
    }
}

int main()
{

    ifstream fin;
    fin.open("numbers.txt");
    if(!fin.is_open()){
        cout<<"File cannot open. Aborting..."<<endl;
        return 0;
    }

    int maxSize =101, table[maxSize],num=0, i=0,numStudents=0;
    int inValidFavNums=0,validFavNums=0,noReveal=0;
    int r1=0,r2=0,r3=0,r4=0,r5=0,r6=0,r7=0,r8=0,r9=0,r10=0,most=0,least=0;


     cout<<endl<<endl;
     cout<<"Number\tPerfect?\tPrime?\tPerfect Square?\tSphenic?\tBinary Equiv."<<endl;
     cout<<"======\t=======\t\t=====\t=============\t=======\t\t==========="<<endl;




    for(int i=0; i<maxSize; i++)
       table[i]=0;

      fin>>num;
    while(num!=-1 ){

    table[i]=num;
     numStudents++;


  while(num!=-1 && num>1 && num<100){


    if(isPerfect(num))

    cout<<num<<"\t"<<" Y";
   else
        cout<<num<<"\t"<<" N";

        if(isPrime(num))
            cout<<" \t\t"<<" Y";
   else
        cout<<" \t\t"<<" N";

        if(isPerfectSquare(num))
            cout<<"\t \t"<<"Y";
   else
        cout<<" \t\t"<<"N";

        if(isSphenic(num))
             cout<<"\t"<<"Y\t\t";
   else
        cout<<"\t"<<"N\t\t";


       deciToBin(num);
       cout<<endl;

        if(num==0)
        noReveal++;

       else if(num<1 || num>100)
          inValidFavNums++;

       else
        validFavNums++;



        if(num>=1&&num<=10)
            r1++;
         if(num>=11&&num<=20)
            r2++;
        if(num>=21&&num<=30)
            r3++;
        if(num>=31&&num<=40)
            r4++;
        if(num>=41&&num<=50)
            r5++;
        if(num>=51&&num<=60)
            r6++;
        if(num>=61&&num<=70)
            r7++;
        if(num>=71&&num<=80)
            r8++;
        if(num>=81&&num<=90)
            r9++;
        if(num>=91&&num<=100)
            r10++;


      most=getMost(table,num);
      least=getLeast(table,numStudents);

        fin>>num;
    }

    if(num==0)
        noReveal++;

    else if(num<1 || num>100)
       inValidFavNums++;

       else
        validFavNums++;




  fin>>num;

}

  cout<<endl;


  cout<<"Range\t\t\t\tHistogram"<<endl;
  cout<<"=========================================="<<endl;
  cout<<" 1-10\t\t\t\t";
  printStars(r1/5);
  cout<<"11-20\t\t\t\t";
  printStars(r2/5);
  cout<<"21-30\t\t\t\t";
  printStars(r3/5);
  cout<<"31-40\t\t\t\t";
  printStars(r4/5);
  cout<<"41-50\t\t\t\t";
  printStars(r5/5);
  cout<<"51-60\t\t\t\t";
  printStars(r6/5);
  cout<<"61-70\t\t\t\t";
  printStars(r7/5);
  cout<<"71-80\t\t\t\t";
  printStars(r8/5);
  cout<<"81-90\t\t\t\t";
  printStars(r9/5);
  cout<<"91-100\t\t\t\t";
  printStars(r10/5);


   cout<<endl;

   cout<<"Amount of students who specified invalid favourite numbers: "<<inValidFavNums<<endl;
   cout<<"Amount of students who specified valid favourite numbers: "<<validFavNums<<endl;
   cout<<"Amount of students who did not reveal their favourite number: "<<noReveal<<endl;
   cout<<"Number chosen the most: "<<most<<endl;
   cout<<"Number chosen the least: "<<least<<endl;

   cout<<"Invalid numbers: "<<endl;
   printInvalid(num);



    return 0;
}
