#include <iostream>
#include <fstream>
using namespace std;

char perfect(int number);
char prime(int number);
char perfect_square(int number);
int binary(int number);


int main(){
	int numbers;
	ifstream input;
	int num,bN;
	char pN,pS,prN;
	int invalid=0;
	input.open("numbers.txt");
	input >> numbers;

cout<<"Number"<<"\t"<<"Perfect?"<<"\t"<<"Prime"<<"\t"<<"Perfect Square"<<"\t"<<"Binary Equiv."<<endl;
cout<<"======"<<"\t"<<"========"<<"\t"<<"====="<<"\t"<<"==============="<<"\t"<<"============="<<endl;
	
	while (numbers != -1) {
         input >> numbers;
     if(numbers > -1 && numbers <= 100){
     pN=perfect(numbers);
     pS=perfect_square(numbers);
     prN=prime(numbers); 
     bN=binary(numbers);
     
 }
     
 else{
 	invalid++;
 }
  
     cout<<numbers<<"\t"<<pN<<"\t"<<pS<<"\t"<<prN<<"\t"<<bN<<endl;
}
 
 }
 
 
    


 char perfect(int number){
 	int s;
 	 for(int i=1;i<number;i++){
		if(number%i==0){
			s=s+i;
		}
	}
 
	if(s==number){
		return 'Y';
	}	
	else{
		return 'N';
 	
 }
	
}

char prime(int number){
	int i;
	bool isPrime = true;
	
	for(i=2; i<=number/2; i++){
		if(number%i==0)
		isPrime == false;
		

	}
	if(isPrime==true)
	return 'Y';
	else
	  return 'N';

}

char perfect_square(int number){
    int sqr=1;
    int counter=1;
    for(int i=1; sqr>=number; i++)
    {
        sqr = i*i;
        counter++;
    }
    if(sqr==number)
    {
        return 'Y';
    }
    else
    {
        return 'N';
    }
}

int binary(int number){
	int a[10], n, i;    
  
for(i=0; number>0; i++){    
a[i]=number%2;    
number= number/2;  
}       
for(i=i-1 ;i>=0 ;i--)    {    
return a[i];    
  }
}
