#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

bool isPerfect (int n){
	
	int i, div, num =0;
	
	for(i=1;i<n;i++){
		div = n%i;
		if(div==0){
			num = i + num;
		}
	}

		if(num==n)
		return true;
	
	return false;
}

bool isPrime (int m){
	int i;
	for (i=2;i<=(m/2);i++){
		if(m%i==0)
		return false;
	}
	return true;
}

bool isPerfectSquare(int p){
	
	int i, num;
	
	for (i=1; i<=(p/2); i++){
	num = i*i;	
	if (num==p)
	return true;
}
	
	
	return false;
}

bool isSphenic(int q){
	
	int i, j=0, num= 1;
	
	for (i=2; i<=(q/2); i++){
		if( (q%i==0) && isPrime(i) ){
			num= num * i;
			j++;
		}
	} 
	
	if ((j==3) && num==q){
		return true;
	}
	return false;
}

void BinaryCon(int r){		//binary conversion function

	int a[10], i, j=0;       
   
	for(i=0; r>0; i++){
		a[i]=r%2;    
		r= r/2;
		j++;  
		}
	
	j= 8 - j;
	while(j>0){
		cout<<"0";
		j--;
	}	
	
	for(i=i-1 ;i>=0 ;i--){
	cout<<a[i];    
		}
	
}



int main(){
	
	int fave, i = 0, number= 0;
	int a=1, b=10, c= 0; 
	int valid= 0, invalid= 0, noAnswer= 0;
	int range[10]={}, array[100]={}, count[100]={};
	bool distinct, perfect, prime, square, sphenic;
	ifstream input;
	ofstream output;
	
		//opening file stream for valid numbers
	input.open("numbers.txt");
	if (!input.is_open()) {
		cout << "Error opening input file. Aborting ...";
		return 1;
	}
	
	cout<<"Number"<<"\t\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equiv."<<endl;
	cout<<"======"<<"\t\t"<<"========"<<"\t"<<"======"<<"\t"<<"==============="<<"\t"<<"========"<<"\t"<<"============="<<endl;
	cout<<endl;
	
	
	
	for(i=0;i<100;i++){
		array[i]=(i+1);
	}
	

	input>>fave;
	while ( fave!=-1 ){

		
	a = 1;
	b= 10;
	for(i=0; i<10; i++){
		if(fave<=b && fave>=a){
			range[i] = range[i] + 1;
		}
		a= a+10;
		b= b+10;
		}

	if(fave==0){
			noAnswer++;
		}
				
		else if(fave>0 && fave<100){
		valid++;	
		
		if(count[(fave-1)]==0){
		
		cout<<fave<<"\t\t";
				
		perfect = isPerfect(fave);
		if (perfect == true){
			cout<<"Y";
		}
		else{
			cout<<"N";
		}
		cout<<"\t\t";
		
		prime = isPrime (fave);
		if (prime == true){
		cout<<"Y"<<"\t";
		}
		else{
			cout<<"N"<<"\t";
		}
		
		square = isPerfectSquare (fave);
		if (square==true){
			cout<<"Y";
		}
		else{
			cout<<"N";
		}
		cout<<"\t\t";
		
		sphenic= isSphenic(fave);
			if (sphenic==true){
				cout<<"Y";}
			else{
			cout<<"N";
		}
		cout<<"\t\t";		
	
		BinaryCon (fave);
		cout<<endl;
		
	}
	
	}
	else{
		invalid++;
	}
	
	for(number=0;number<100;number++){
	if(fave==array[number])
		count[number]++;
	}
		
	input>>fave;	
	  
	}  /*end of while loop */
	
	input.close();
		
	if(invalid>0){
	//opening file stream for invalid numbers
	input.open("numbers.txt");
	if (!input.is_open()) {
		cout << "Error opening input file. Aborting ...";
		return 2;
	}
	
	cout<<endl<<"Invalid numbers :"<<endl;
	input>>fave;
	while ( fave!=-1 ){
		if(fave<0 || fave>100){
			
			if(i%5==0){
				cout<<endl;
			}
			cout<<fave<<"\t";
		
		i++;
		}	
	input>>fave;	
	}
	}

	//Histogram	
	cout<<endl<<endl<<"Range"<<"\t"<<"Histogram"<<endl;
	cout<<"==================================="<<endl;
	
	a = 1;
	b = 10;
	for(i=0; i<10; i++){

		cout<<a<<"-"<<b<<"\t :";
		c=(range[i]/5);
		for(int j=0; j<c; j++){
		cout<<"*";
		}
		cout<<endl;
		a= a+10;
		b= b+10; 
	}
	
	cout<<endl<<endl;
	cout<<"Number of students who chose valid numbers : "<<valid<<endl;
	cout<<"Number of students who chose invalid numbers : "<<invalid<<endl;
	cout<<"Number of students who didn't choose a number : "<<noAnswer<<endl;
	
	
	int highest=-1;
	for(i=0;i<100;i++){
		if(count[i]>highest){
			highest = count[i];
		}
	
	}

	if(highest>1){
		cout<<"The numbers chosen the most were : "<<endl;
	
	for(i=0;i<100;i++){
        if(count[i]==highest)
            cout<<i+1<<"\t";
			}
	}
	else{
		cout<<"No number was chosen more than once"<<endl;
	}
	
	int lowest=200;
	for(i=0;i<100;i++){
		if(count[i]<lowest && count[i]>0 ){
			lowest = count[i];
		}
	}

cout<<endl;
	if(lowest>0){
		cout<<"The numbers chosen the least were : "<<endl;
	for(i=0;i<100;i++){
        if(count[i]==lowest)
            cout<<i+1<<"\t";
			}
	
	}
	else{
		cout<<"No number was chosen"<<endl;
	}
	
	
	return 0;
}
