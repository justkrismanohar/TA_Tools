#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool isperfect(int num){
    int i, factor=0;
    for(i=1; i<num;i++){
       if(num%i==0){
        factor= factor + i;
       }
    }
       if(factor==num)
        return true;

    return false;
}

bool isprime(int num){
    if (num==1)
        return false;
    for(int i=2; i<num/2; i++){
        if(num%i==0)
            return false;
    }
    return true;
}

bool isPerfectSquare(int num){
    int sqr;
    if (num==1)
        return true;

    for(int i=2; i<num/2; i++){
        sqr=i*i;
        if (sqr==num)
            return true;
    }
    return false;
}

bool isSphenic(int num){
    int i, counter, product;

    counter=0;
    product=1;

    for(i=2; i<num/2; i++){
        if(num%i==0 && isprime(i)){
			product=product * i;
			counter= counter + 1;
		}
		if (counter ==3 && product==num)
			return true;
	}
	return false;
    }

void binary(int num){
    int i,x;
    int a[7];

    for (i=0; i<7; i++){
        a[i]=0;
    }
    i=0;
    while(num!=0){
        x=num%2;
        a[i]=x;
        i++;
        num/=2;


        }
        for(i=0; i<7; i++){
            cout<<a[i];
        }
    }


int main(){
    ifstream in;

    in.open ("numbers.txt");
    if(!in.is_open()){
        cout<<"File not found"<<endl;
    }

    int num;
    int i=0,y=0,z=0,a=0, nothing=0;
    int invalid[200];
    int valid[200];
    int star[10];



    in>>num;
    cout<<"Number   Perfect?    Prime?    Perfect Square?    Sphenic?    Binary"<<endl;
    cout<<"========================================================================="<<endl;

    while(num!=-1){
        if((num>0) && (num<=100) ){


        cout<<num;
        if(isperfect(num)==true){
            cout<<"\t  Yes";
        }else{
            cout<<"\t  No";
            }
        if(isprime(num)==true){
            cout<<"\t\tYes"<<"\t";
        }else{
            cout<<"\t\tNo"<<"\t";
            }
        if(isPerfectSquare(num)==true){
            cout<<"\tYes";
        }else{
            cout<<"\tNo";
            }
        if(isSphenic(num)==true){
            cout<<"\t   Yes"<<"\t\t";
        }else{
            cout<<"\t   No"<<"\t\t";
            }

        binary(num);
        cout<<endl;
        valid[y]=num;
        y++;

        }else if(num!=0){
            invalid[i]=num;
            i++;
        }else
         nothing++;

        in>>num;

    }


    cout<<endl<<endl<<endl;
    cout<<"==========================="<<endl;
    cout<<"     Invalid Numbers"<<endl;
    for(int x=1; x<i; x++){
        cout<<invalid[x]<<"  ";
        if(x%5==0)
        cout<<endl;

    }
    for(z=0; z<10; z++){
        star[z]=0;
    }
    for(int j=0; j<y; j++){
        if((valid[j]>0) && (valid[j]<11)){
            star[0]=star[0]+1;
        }
        if((valid[j]>10) && (valid[j]<21)){
            star[1]=star[1]+1;
        }
        if((valid[j]>20) && (valid[j]<31)){
            star[2]=star[2]+1;
        }
        if((valid[j]>30) && (valid[j]<41)){
            star[3]=star[3]+1;
        }
        if((valid[j]>40) && (valid[j]<51)){
            star[4]=star[4]+1;
        }
        if((valid[j]>50) && (valid[j]<61)){
            star[5]=star[5]+1;
        }
        if((valid[j]>60) && (valid[j]<71)){
            star[6]=star[6]+1;
        }
        if((valid[j]>70) && (valid[j]<81)){
            star[7]=star[7]+1;
        }
        if((valid[j]>80) && (valid[j]<91)){
            star[8]=star[8]+1;
        }
        if((valid[j]>90) && (valid[j]<101)){
            star[9]=star[9]+1;
        }
    }
    cout<<endl<<"===========================";
    cout<<endl<<endl;
    cout<<"==========================="<<endl;
    cout<<"Range        Histogram"<<endl;
    cout<<"==========================="<<endl;
    cout<<"1-10     |    ";
    for(int q=0;q<star[0]/5; q++)
        cout<<"*";
    cout<<endl<<"11-20    |    ";
    for(int q=0;q<star[1]/5; q++)
        cout<<"*";
    cout<<endl<<"21-30    |    ";
    for(int q=0;q<star[2]/5; q++)
        cout<<"*";
    cout<<endl<<"31-40    |    ";
    for(int q=0;q<star[3]/5; q++)
        cout<<"*";
    cout<<endl<<"41-50    |    ";
    for(int q=0;q<star[4]/5; q++)
        cout<<"*";
    cout<<endl<<"51-60    |    ";
    for(int q=0;q<star[5]/5; q++)
        cout<<"*";
    cout<<endl<<"61-70    |    ";
    for(int q=0;q<star[6]/5; q++)
        cout<<"*";
    cout<<endl<<"71-80    |    ";
    for(int q=0;q<star[7]/5; q++)
        cout<<"*";
    cout<<endl<<"81-90    |    ";
    for(int q=0;q<star[8]/5; q++)
        cout<<"*";
    cout<<endl<<"91-100   |    ";
    for(int q=0;q<star[9]/5; q++)
        cout<<"*";


    cout<<endl<<endl;
    cout<<"=================================================="<<endl;
    cout<<"Amount of students that put valid numbers: "<<y<<endl;
    cout<<"Amount of students that put invalid numbers: "<<i<<endl;
    cout<<"Amount of students that did not put a number: "<<nothing<<endl;




    return 0;
}
