#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


bool isPerfect (int arr[], int y){
	 int x=1; int sum;
		if (arr [y] % x==0){
			sum=sum+x;
			x=x+1;
		}
	
	if (sum == arr [y]){
		return true ;
	}
	else {
		return false;
	}
}

bool isPrime (int arr[], int y){     // TO FIX
	int i; int prime=0;
	for(i=2; i<=arr[y]/2; i++) {
      if(arr[y]%i==0) {
         prime=1;
      }
   }
   if (prime==0)
      return true;
   else
      return false;
		
	}


bool isperfectSquare (int arr[], int y){
	while (arr [y] != -1){
		if (sqrt (arr[y]==0)){
			return true;
		}
		else {
			return false;
		}
	}
}

bool isSpheric (int arr [], int y){
	int x=2; int prod=1; 
		if (arr [y] % x == 0){
			if (isPrime (arr, y)==true){
				prod = prod * x;
			}
			if (prod == arr [y]){
				return true;
			}
			else {
				return false;
			}
		}
	}

int binaryEquiv(int arr[], int y){
int n=0; 
int div=arr[y];
	while (div!=0){
		n=(n*10)+(div%2);
		div=floor(div/2);
		
	}
	return n;
}

int histogram(int y){
	
	 int x=0;
	for (int i=0; i<=y; i++){
		x=x+1;
		if (x%5==0){
			cout<< "*";
		}
	}
	
	
}


int main (){
	int i=0;  
	int sum=0, sum1=0, sum2=0, sum3=0, sum4=0, sum5=0, sum6=0, sum7=0, sum8=0, sum9=0, histo1, histo2, histo3, histo4, histo5, histo6, histo7, histo8, histo9, valid=0, invalid=0,noReveal=0;
	int popular[100]={0};
	int z,y=0,s;
	int max=1;
	ifstream in;
	in.open ("numbers.txt");
	int arr [1000] ={0};
	int size=0;
	int min= 100;
	cout<< "Number\tPerfect?\tPrime?\tPerfect Square?\tSphenic?\tBinary Equiv "<<endl;
	cout<< "=======\t=======\t       ======\t===============\t=========\t==========="<<endl;
	
	in>>arr [y];
	while (arr [y]!=-1){
		if (arr[y]<=0 || arr[y] >100){
			y=y+1;
		}
		
		if(arr[y]==0){
			noReveal=noReveal+1;
		}
		
		
		if (arr[y]<min){
			min=arr[y];
		
	}	
		
	
		if (arr[y]>max){
			max=arr[y];
		
	}
		
		cout<< arr [y] << "\t     ";
		
		if (isPerfect(arr,y)==true){         //FIND PERFECT NUMBER
			    cout << "Y         ";
		}
		else if (isPerfect(arr,y)==false){
				cout <<"N           ";
			}
		
		if (isPrime(arr,y)==true){            // FIND PRIME NUMBER
			     cout<<"Y           ";
		}
		else if (isPrime(arr,y)==false){
			     cout<< "N          ";
		}
		
		if (isperfectSquare(arr,y)==true){    // FIND PERFECT SQUARE
			     cout<<"Y           ";
		}
		
		else if (isperfectSquare(arr,y)==false){
		     	cout<<"N            ";
		}
		
		if (isSpheric(arr,y)==true){         // FIND IF SPHERIC
			     cout<<"Y           ";
		}
		else if (isSpheric(arr,y)==false){
		     	cout<<"N            ";
		}
		
		cout<<binaryEquiv(arr,y);
		cout<<endl;
		size=size++;
		y ++;
		in >>arr [y] ;
		
		
		}
		cout<<endl;
	cout<<"Invalid numbers: "<<endl;
	for (i=0; i<y; i++){                 // INVALID NUMBERS
		if ((arr [i] <=-1 )|| (arr [i] > 100)){
			
			cout<< arr[i] << "  ";
			invalid = invalid + 1;
			if (invalid % 5 ==0){
				cout<<endl;
			}
		}
	}
	cout<<endl;
	cout<<endl;
	cout<< "Range \t Histogram"<<endl;
	cout<< "==================="<<endl;
	
	for (i=0; i<y; i++){
		if(arr[i]>=1 && arr[i]<=10){
			sum=sum+1;
		}
		if(arr[i]>=11 && arr[i]<=20){
			sum1=sum1+1;
		}
		if(arr[i]>=21 && arr[i]<=30){
			sum2=sum2+1;
		}
		if(arr[i]>=31 && arr[i]<=40){
			sum3=sum3+1;
		}
		if(arr[i]>=41 && arr[i]<=50){
			sum4=sum4+1;
		}
		if(arr[i]>=51 && arr[i]<=60){
			sum5=sum5+1;
		}
		if(arr[i]>=61 && arr[i]<=70){
			sum6=sum6+1;
		}
	     if(arr[i]>=71 && arr[i]<=80){
			sum7=sum7+1;
		}
		if(arr[i]>=81 && arr[i]<=90){
			sum8=sum8+1;
		}
		if(arr[i]>=90 && arr[i]<=100){
			sum9=sum9+1;
		}
	}
	
	
	cout<<"1-10 \t";
	histogram(sum);
	cout<<endl;
	
	
	cout<<"11-20 \t";
	histogram(sum1);
	cout<<endl;
	
	
	cout<<"21-30 \t";
	histogram(sum2);
	cout<<endl;
	
	
	cout<<"31-40 \t";
	histogram(sum3);
	cout<<endl;
	
	
	cout<<"41-50 \t";
	histogram(sum4);
	cout<<endl;
	
	
	cout<<"51-60 \t";
	histogram(sum5);
	cout<<endl;
	
	
	cout<<"61-70 \t";
	histogram(sum6);
	cout<<endl;
	
	
	cout<<"71-80 \t";
	histogram(sum7);
	cout<<endl;
	
	
	cout<<"81-90 \t";
	histogram(sum8);
	cout<<endl;
	
	
	cout<<"91-100 \t";
	histogram(sum9);
	cout<<endl;
	
	cout<<endl;
	cout<<endl;
	valid = y - invalid;
	cout<<"Amt of students with a valid favourite number: "<<valid<<endl;
	cout<<"Amt of students with invalid favourite numbers: "<<invalid<<endl;
	
	
	cout<<"Amt of students who did not reveal: "<<noReveal<<endl;
	
	
	
	cout<<"Most popular number: "<<max;
	cout<<endl;
	
	cout<<"Least popular number: "<<min;
	
	return 0;
}
