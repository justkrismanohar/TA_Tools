#include <iostream>
#include <fstream>
#include<cmath>
using namespace std;
bool Perfect(int num) {
	int i;
	int proper_div;
	int sum=0;
	if ((num>0)&&(num<101)) {
		
		for(i=1; i<=(num/2); i++) {
			
			proper_div= num%i;
			
			if(proper_div==0) {
				sum = sum + i;
			}
			if(sum==num) 
			return true;
			}
				return false;
	}

	
 }
bool Prime(int num) {
    int i;
    int prime_test;
     if ((num>0)&&(num<101)){
	
    for (i=2; i<=(num/2); i++) {
    	prime_test= num%i;
    	if(prime_test==0)
    	return false;
	}
	return true;
}
        
}
           
            
bool PerfSquare(int num) {
   int i;
   int square;
   if ((num>0)&&(num<101)){
   if(num==1)
   return true;
   for(i=2;i<=(num/2);i++){
   	square= i*i;
   	if(square==num)
   	return true;
   }
   return false;
   }
   
}

bool Sphenic(int num) {
   int i;
   int count;
   int product;
    if ((num>0)&&(num<101)){
    	product=1;
    	count=0;
    	for(i=2; i<=(num/2); i++){
    		if((num%i==0)&&(Prime(i))){
    			product=product*i;
    			count=count + 1;
			}
		}
		if((count==3)&&(product==num))
		return true;
		else
		return false;
	}
}
bool Binary(int num){
    int arr[9];
    int div;
	int i;
	int b;
	
	if ((num>0)&&(num<101)){
    for (i=0; i<8; i++){
        
            div= num%2;
            num=num/2;
            arr[i]=num;
			
			}
			
            for(b=0; b<4; b++) {
                int temp=arr[b];
                
                arr[b]=arr[7-b];
                
                arr[7-b]=temp[b];
				
				 }
            }
    }
    

int main() {
int num;
 int valid=0;
 int notreveal=0;
 int invalid=0;
 int ten=0;
 int twenty=0;
 int thirty=0;
 int forty=0;
 int fifty=0;
 int sixty=0;
 int seventy=0;
 int eighty=0;
int ninety=0;
int hundred=0;
int inv=0;
int array[inv];

ifstream inputFile;
inputFile.open("numbers.txt");
if (!inputFile.is_open()){
    cout<< "Error opening input file. aborting....";
    return 0;}


cout<< "Number" <</t<< "Perfect" <</t<< "Prime" <</t<< "Perfect Square" <</t<< "Sphenic" <</t<< "Binary Equivalent"<<endl;

cout<< "==========================================================================================================="<<endl;

inputFile>>num;
while(n!=1)
{
    if((num>=1 )&&( num<=100)){
        valid=valid+1;
        Perfect(num);
        Prime(num);
        PerfectSquare(num);
        Sphenic(num);
        Binary(num);
        
        
cout<< num <</t;
cout<< Perfect <</t;
cout<< Prime <</t;
cout<< PerfSquare <</t;
cout<< Sphenic <</t;
cout<< Binary <<endl; 
 }
  
      
      if((num>=1 )&&(num<=10)) {
          ten=ten+1;
		  }
     if((num>=11) && (num<=20)) {
          twenty=twenty+1;
		   }
 if((num>=21 )&& (num<=30)) {
          thirty=thirty+1; 
		  }
            if((num>=31 )&&(num<=40)) {
          forty=forty+1;
		   }
            if((num>=41 )&&( num<=50)) {
          fifty=fifty+1;
		  }
           if((num>=51 )&&(num<=60)) {
          sixty=sixty+1;
		  }
            if((num>=61 )&& (num<=70)) {
          seventy=seventy+1;
		  }
            if((num>=71 )&& (num<=80)) {
          eighty=eighty+1;
		  }
            if((num>=81 &&  (num<=90)) {
          ninety+ninety+1;
		  }
            if((num>=91 )&& (num<=100)) {
          hundred=hundred+1;
		  }
if(num==0) {
      notreveal=notreveal+1;
	  }
      
    invalid=invalid+1;
    array[inv]=n;
    inv=inv+1;
}

     for(inv>=0, inv<inv, inv++;) {
 cout << array[inv]
     }
     
cout<< "Range" <</t/t<< "Histogram" << endl;
cout<< "=================================" << endl;
cout<< "1-10" <</t/t<< ten<<endl;
cout<< "11-20" <</t/t<< twenty<< endl;
cout<< "21-30" <</t/t<< thirty<< endl;
cout<< "31-40" <</t/t<< forty<< endl;
cout<< "41-50" <</t/t<< fifty<< endl;
cout<< "51-60" <</t/t<< sixty<< endl;
cout<< "61-70" <</t/t<< seventy<< endl;
cout<< "71-80" <</t/t<< eighty<<endl;
cout<< "81-90" <</t/t<< ninety<<endl;
cout<< "91-100" <</t/t<< hundred<<endl;
cout<<endl;
cout<<endl;
cout<<"Amount of student that specified valid numbers: "<<valid<<endl;
cout<<"Amount of students who specified invalid numbers: "<<invalid<<endl;
cout<<"Amount of students that didnt reveal a number: " <<notreveal<<endl;
     
     return 0;
} 
