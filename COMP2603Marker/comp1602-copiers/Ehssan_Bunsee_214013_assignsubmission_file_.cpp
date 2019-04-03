#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string perfect(int x){
  int a=1,sum=0;
  while(a<x){
    if(x%a==0){
      sum +=a;
    }
    a++;
  }
  if(sum==x){
    return "Y";
  }else{
    return "N";
  }
}

string prime (int p){
  int h=2;
  if(p==2){
    return"Y";
  }
  while(h<p){
    if(p%h==0){
      return "N";
    }
    else{
      h++;
     // cout<<"Y\n";
    }
  }
  return "Y";
}
  
  string perfectsquare(int ps){
    int i=0;
    for(i=1;i<=ps;i++){
      if(ps/i == i){
        return "Y";
      }
    }
    return "N";
  }

  string sphenic(int s){
    int a=0, pnumbers[100], b=0;
    for(a=2; a<=s; a++){
        string isprime= prime(a);
        if(isprime=="Y"){
            pnumbers [b] = a ;
            b++;
        }
    }
    
    for(int i=0; i<b; i++){
        for(int j = i + 1; j < b; j++) {
            for(int k = j + 1; k < b; k++) {
                if(pnumbers[i] * pnumbers[j] * pnumbers[k] == s ){
                    return "Y";
                }
              // multiply and compare to s
              //if equal then sphenic, else not  
              //cout<<pnumbers[i]<<"\t"<<pnumbers[j]<<"\t"<<pnumbers[k]<<endl;
            }
        }
    //for(int j=)
    }
    return "N";
  }
  int binary (int d){
      int i=0, a[10];
      for(i=0; d>0; i++){
        a[i]=d%2;    
        d= d/2;
      }    
for(int n=i-1 ; n>=0 ; n--)    
{    
cout<<a[n];    
}  
return 0;  
}

string star(int m){
    int k=0;
    for(k=0; k<m/5; k++){
        cout<<"*";
    }
return "";
}


int main(){

  int num=0, valid=0, invalid=0, h=0, invalidarray[100], ct1=0, ct2=0, ct3=0, ct4=0, ct5=0, ct6=0, ct7=0, ct8=0, ct9=0, ct10=0, zero=0;
  int validarray[100];
  ifstream fin;
  ofstream fout;
  fin.open("numbers.txt");
  cout<<"Number\t\t"<<"Perfect\t\t"<<"Prime\t\t"<<"Sphenic\t\t"<<"Binary Equivalent\n";
    fin>>num;
    while(num!=-1){
        if(num>= 1 && num<= 100){
            cout<<num<<"\t\t"<<perfect(num)<<"\t\t"<<prime(num)<<"\t\t"<<sphenic(num)<<"\t\t";
            binary(num);
            cout<<endl;
            validarray[100]=validarray[valid];
            validarray[valid++]=num;
            if(num>=1 && num<=10){
                ct1++;
            }
            if(num>=11 && num<=20){
                ct2++;
            }
            if(num>=21 && num<=30){
                ct3++;
            }
            if(num>=31 && num<=40){
                ct4++;
            }
            if(num>=41 && num<=50){
                ct5++;
            }
            if(num>=51 && num<=60){
                ct6++;
            }
            if(num>=61 && num<=70){
                ct7++;
            }
            if(num>=71 && num<=80){
                ct8++;
            }
            if(num>=81 && num<=90){
                ct9++;
            }
            if(num>=91 && num<=100){
                ct10++;
            }

        } else if(num < 0 || num > 100){
            invalidarray[100] = invalidarray[invalid];
            invalidarray[invalid++] = num;
        } else {
                zero++;
        }
        fin>>num; 
    }

    for(h=0; h<invalid; h++){
        cout<<invalidarray[h]<<"  ";
        if (h % 5 == 4) {
            cout<<endl;
        }
    }

    cout<<"\n\nRange\t\t"<<"Histogram\n";
    for( int g=0; g<=25; g++){
        cout<<"=";
    }
    cout<<endl;
    cout<<"1-10\t\t|"<<star(ct1)<<endl;
    cout<<"11-20\t\t|"<<star(ct2)<<endl;
    cout<<"21-30\t\t|"<<star(ct3)<<endl;
    cout<<"31-40\t\t|"<<star(ct4)<<endl;
    cout<<"41-50\t\t|"<<star(ct5)<<endl;
    cout<<"51-60\t\t|"<<star(ct6)<<endl;
    cout<<"61-70\t\t|"<<star(ct7)<<endl;
    cout<<"71-80\t\t|"<<star(ct8)<<endl;
    cout<<"81-90\t\t|"<<star(ct9)<<endl;
    cout<<"91-100\t\t|"<<star(ct10)<<endl<<endl;

    cout<<"The amount of students who chose valid favourite numbers: "<<valid<<endl;
    cout<<"The amount of students who chose invalid favourite numbers: "<<invalid<<endl;
    cout<<"The amount of students who did not reveal their favourite numbers: "<<zero<<endl;

    int q[100], max = 0, maxarray[100], min = 100, minarray[100];

    for (int v = 0; v < 100; v++) {
        q[v] = 0;
    }

    for (int p = 0; p < valid; p++) {
        q[validarray[p]-1]++;
    }

    for (int y = 0; y < 100; y++) {
        if (q[y] > max) {
            max = q[y];
        }

        if (q[y] < min) {
            min = q[y];
            if (min == 0) {
                min = 1;
            }
        }
    }

    for (int a = 0; a < 100; a++) {
            maxarray[a] = 0;
            minarray[a] = 0;
        }


int f = 0, l = 0;

    for (int w = 0; w < 100; w++){
        if (q[w] == max) {
            maxarray[f] = w+1;
            f++;
        }

        if (q[w] == min) {
            minarray[l] = w+1;
            l++;
        }
    }

    cout<<"The most liked numbers are: ";

    for (int g = 0; g < f; g++) {
        cout<<maxarray[g]<<" ";
    }

    cout<<endl;

    cout<<"The least liked numbers are: ";

    for (int u = 0; u < l; u++) {
        cout<<minarray[u]<<" ";
    }

    cout<<endl; 
    return 0;
  
}
