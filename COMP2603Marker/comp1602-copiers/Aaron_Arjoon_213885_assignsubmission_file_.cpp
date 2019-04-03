#include <iostream>
#include <fstream>
using namespace std;

    bool perfect(int n){
        int i=1, add=0;
        while(i<n){
        if(n%i==0)
        add=add+i;
        i++;
    }
        if(add==n)
            return true;
        else
            return false;
    }

  bool prime(int n){
        int i;
        bool Prime=true;
        for(i=2; i<=n/2; i++){
            if(n%i==0)
            Prime=false;
        }
       if(Prime){
            return true;
       }
       else
            return false;

    }
    bool perSquare(int n){

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
        int primeS[]={0,0,0};
        while(i<=n){
            if(n%i==0){
                if(prime(i)){
                primeS[k]=i;
                k++;
                }
            }

            if(k==3){
                i=n+1;
            }
            i++;
        }
        int num=primeS[1]*primeS[0]*primeS[2];
        if(num==n)
            return true;
        else
                return false;

    }

    int binary(int n){
    for (int i = 7; i >= 0; i--) {
        int j = n >> i;
        if (j & 1)
            cout << "1";
        else
            cout << "0";
    }
}

void Histogram(int num){
for(int i=1;i<=num;i++)
    cout<<"*";
}


int main (){

    ifstream in;
    int n,count=0,invcount=0,i=0,counter=0,zero=0;
    int invalid[1000]={0};
    int valid[1000]={0};
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,z=0,j=0;
    int A,B,C,D,E,F,G,H,Z,J;

    in.open("numbers.txt");
    if(!in.is_open()){
    cout<<"Error loading file!"<<endl;
    return 0;
    }
    in>>n;

    cout<<"Number Perfect Prime PerfectSquare Sphenic Binary Representation"<<endl;
    cout<<"====== ======= ===== ============= ======= ====================="<<endl;
    while(n!=-1){
        if(n<=100&&n>=1){
    cout<<n;
    if(perfect(n))
        cout<<"        Y";
        else
            cout<<"       N";

        if(prime(n))
            cout<<"        Y";
        else
            cout<<"       N";

        if(perSquare(n))
            cout<<"        Y";
        else
            cout<<"       N";

        if(isSphenic(n))
            cout<<"           Y         ";
        else
            cout<<"           N         ";

            binary(n);
            cout<<endl;
            valid[count]=n;
            count++;
        }
        else{
            invalid[invcount]=n;
            invcount++;
        }

    in>>n;
    }
    cout<<endl;
    cout<<"INVALID NUMBERS"<<endl;
    for(i=0;i<invcount;i++){
        cout<<invalid[i]<<" ";
        if((i+1)%5==0)
            cout<<endl;
    }

    cout<<endl;
    for(i=0;i<count;i++){
        if(valid[i]>=1&&valid[i]<=10)
            a++;
            if(valid[i]>=11&&valid[i]<=20)
            b++;
            if(valid[i]>=21&&valid[i]<=30)
            c++;
            if(valid[i]>=31&&valid[i]<=40)
            d++;
            if(valid[i]>=41&&valid[i]<=50)
            e++;
            if(valid[i]>=51&&valid[i]<=60)
            f++;
            if(valid[i]>=61&&valid[i]<=70)
            g++;
            if(valid[i]>=71&&valid[i]<=80)
            h++;
            if(valid[i]>=81&&valid[i]<=90)
            z++;
            if(valid[i]>=91&&valid[i]<=100)
            j++;
    }
A=a/5;
B=b/5;
C=c/5;
D=d/5;
E=e/5;
F=f/5;
G=g/5;
H=h/5;
Z=z/5;
J=j/5;
cout<<endl;
cout<<"HISTOGRAM"<<endl;
cout<<"Range     Histogram"<<endl;
cout<<"==================="<<endl;

cout<<"1-10       ";
Histogram(A);
cout<<endl;

cout<<"11-20       ";
Histogram(B);
cout<<endl;

cout<<"21-30       ";
Histogram(C);
cout<<endl;

cout<<"31-40       ";
Histogram(D);
cout<<endl;

cout<<"41-50       ";
Histogram(E);
cout<<endl;

cout<<"51-60       ";
Histogram(F);
cout<<endl;

cout<<"61-70       ";
Histogram(G);
cout<<endl;

cout<<"71-80       ";
Histogram(H);
cout<<endl;

cout<<"81-90       ";
Histogram(Z);
cout<<endl;

cout<<"91-100       ";
Histogram(J);
cout<<endl;

for(i=0;i<invcount;i++){
    if(!invalid[i]==0)
        counter++;
    else
        zero++;
}
cout<<endl;

cout<<"The number of students with valid favorite numbers are "<<count<<endl;
cout<<"The number of students with invalid favorite numbers are "<<counter<<endl;
cout<<"The number of students who didn't reveal their favorite number are "<<zero<<endl;

return 0;
}
