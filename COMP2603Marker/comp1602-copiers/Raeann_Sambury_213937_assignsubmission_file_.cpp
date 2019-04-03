#include <iostream>
#include <fstream>
using namespace std;

    bool perfect(int n){
        int i=1, sum=0;
        while(i<n){
        if(n%i==0)
        sum=sum+i;
        i++;
    }
        if(sum==n)
            return true;
        else
            return false;
    }

  bool prime(int n){
        int i;
        bool isPrime=true;
        for(i=2; i<=n/2; i++){
            if(n%i==0)
            isPrime=false;
        }
       if(isPrime){
            return true;
       }
       else
            return false;

    }
    bool pSquare(int n){

    int a=1,i=1;
    while(a<n)
	{
		i=i+1;
		a=i*i;
	}
	if(a==n)
        return true;
	else
        return false;

}

    bool isSphenic(int n){
        int k=0, i=2;
        int primeSet[]={0,0,0};
        while(i<=n){
            if(n%i==0){
                if(prime(i)){
                primeSet[k]=i;
                k=k+1;
                }
            }

            if(k==3){
                i=n+1;
            }
            i=i+1;
        }
        int num=primeSet[1]*primeSet[0]*primeSet[2];
        if(num==n)
            return true;
        else
                return false;

    }

    int Binary(int n){
    for (int i = 7; i >= 0; i=i-1) {
        int j = n >> i;
        if (j & 1)
            cout << "1";
        else
            cout << "0";
    }
}

    void histoG(int num){
    for(int i=1;i<=num;i=i+1)
    cout<<"*";
}

     void mode(int a[],int b) {
        int maxValue = 0, maxCount = 0, i, j;
         b=100;

        for (i = 0; i < b; i++) {
            int count = 0;

      for (j = 0; j < b ; j++) {
            if (a[j] == a[i])
         count++;
      }

      if (count > maxCount) {
         maxCount=count ;
         maxValue = a[i];
      }
   }
   cout<<"The number that was chosen the most is : "<<maxValue<<endl;
}


int main (){

    ifstream in;
    int n,InvalZ=0,vCount,v[100]={0,0,0},number=v[0];
    int count=0,inVcount=0,i=0,z,a[1000]={0};
    int invalid[1000]={0},valid[1000]={0};
    int counterA=0,counterB=0,counterC=0,counterD=0,counterE=0,counterF=0,counterG=0,counterH=0,counterI=0,counterJ=0;
    int MainA,MainB,MainC,MainD,MainE,MainF,MainG,MainH,MainI,MainJ;

    in.open("numbers.txt");
    if(!in.is_open()){
    cout<<"Aborting File...error"<<endl;
    return 0;
    }
    in>>n;

    cout<<"Number Perfect Prime PerfectSquare Sphenic Binary Equivalence"<<endl;
    cout<<"====== ======= ===== ============= ======= =================="<<endl;
    while(n!=-1){

     if(n>=1&&n<=100){
    cout<<n;
    if(perfect(n))
        cout<<"        Y";
        else
            cout<<"       N";

        if(prime(n))
            cout<<"        Y";
        else
            cout<<"       N";

        if(pSquare(n))
            cout<<"        Y";
        else
            cout<<"       N";

        if(isSphenic(n))
            cout<<"           Y         ";
        else
            cout<<"           N         ";

            Binary(n);
            cout<<endl;
            valid[count]=n;
            count=count+1;
        }
        else{
            invalid[inVcount]=n;
            inVcount=inVcount+1;
             if(n==0)
            InvalZ=InvalZ+1;
        }
    in>>n;
    }
        cout<<endl;
     cout<<"INVALID NUMBERS ARE:"<<endl;
    for(i=0;i<inVcount;i=i+1){
        cout<<invalid[i]<<" ";
        if((i+1)%5==0)
            cout<<endl;
    }

    for(i=0;i<count;i=i+1){
        if(valid[i]>=1&&valid[i]<=10)
            counterA=counterA+1;

            if(valid[i]>=11&&valid[i]<=20)
            counterB=counterB+1;

            if(valid[i]>=21&&valid[i]<=30)
            counterC=counterC+1;

            if(valid[i]>=31&&valid[i]<=40)
            counterD=counterD+1;

            if(valid[i]>=41&&valid[i]<=50)
            counterE=counterE+1;

            if(valid[i]>=51&&valid[i]<=60)
            counterF=counterF+1;

            if(valid[i]>=61&&valid[i]<=70)
            counterG=counterG+1;

            if(valid[i]>=71&&valid[i]<=80)
            counterH=counterH+1;

            if(valid[i]>=81&&valid[i]<=90)
            counterI=counterI+1;

            if(valid[i]>=91&&valid[i]<=100)
            counterJ=counterJ+1;
    }
    MainA=counterA/5;
    MainB=counterB/5;
    MainC=counterC/5;
    MainD=counterD/5;
    MainE=counterE/5;
    MainF=counterF/5;
    MainG=counterG/5;
    MainH=counterH/5;
    MainI=counterI/5;
    MainJ=counterJ/5;

        cout<<endl;
        cout<<endl;
    cout<<"HISTOGRAM"<<endl;
    cout<<"Range     Histogram"<<endl;
    cout<<"==================="<<endl;
    cout<<"1-10      :";
        histoG(MainA);
    cout<<endl;
    cout<<"11-20     :";
        histoG(MainB);
    cout<<endl;
    cout<<"21-30     :";
        histoG(MainC);
    cout<<endl;
    cout<<"31-40     :";
        histoG(MainD);
    cout<<endl;
    cout<<"41-50     :";
        histoG(MainE);
    cout<<endl;
    cout<<"51-50     :";
        histoG(MainF);
    cout<<endl;
    cout<<"61-70     :";
        histoG(MainG);
    cout<<endl;
    cout<<"71-80     :";
        histoG(MainH);
    cout<<endl;
    cout<<"81-90     :";
        histoG(MainI);
    cout<<endl;
    cout<<"91-100    :";
        histoG(MainJ);
    cout<<endl;

        cout<<endl;
        vCount=100-inVcount;
        a[100]=valid[count];

    cout<<"The amount of students that entered Valid numbers: "<<vCount<<endl;
    cout<<"The amount of students that entered Invalid numbers: "<<inVcount<<endl;
    cout<<"The amount of students who did not reveal there favourite number: "<<InvalZ<<endl;
    mode(a,100);

    in.close();
    return 0;
}
