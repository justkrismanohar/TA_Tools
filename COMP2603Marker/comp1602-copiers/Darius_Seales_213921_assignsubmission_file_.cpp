#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

char perfect(int number){

	int sum=0;
	int i;
	for(i=1; i< number;i++){
		if(number% i== 0)
			sum+=i;
	}
	if(sum == number)
		return 'Y';

	return 'N';		
}

char prime(int number){
	
    int  y;
	int count = 0;
	
    for(y=2; y <= number/2; y++){
			
		if (number % y == 0)
           	return 'N';
    }
	return 'Y';
	
}

char per_square(int number){
 
  int perfect_square = 0;
  int i;
  for(i=1;i<=number;i++){
  	
  	if(i*i==number){
  		perfect_square=1;
  		return 'Y';
	  }
	  
	if(i*i>number)
		return 'N';
  }  	
}

char sphenic(int number){
	int count=0;
	int i;
	if(prime(number)=='N'){

		for(i=2;i<=number;i++){
	
			if(number%i==0 && prime(i)=='Y'){
			count++;
			number/=i;
			}
		}
		if(number==1&&count==3)
		return 'Y';
	}
	return 'N';
	
}

void binary(int number){

	int bin[8];
	int i;

	for(i=7;i>=0;i--){
		bin[i]= number%2;
		number= number/2;
	}
	for(i=0;i<8;i++)
		cout<<bin[i];
}

void hist(int num){
	int i;
	for(i=0;i<num;i++)
		cout<<"*";
}

bool distinct(int number[], int x){
	int i;
	for(i=0;i<x;i++){
		if(number[i]==number[x])
			return false;
	}
	return true;
	
}

int check (int number[], int num , int x){
	int count = 0;
	int i;
	for(i=0;i<x;i++){
		if(num==number[i])
			count++;
	}	
	return count;
}

int main(){

	ifstream fileInput;
	int number[1000];
	int x =0, y=0;
	int favourite[1000];
	int inv_num[1000];
	int range[10];
	int num;
	int not_reveal ,valid = 0;
	int invalid = 0; 
	int count =0;
	int temp;
	
	fileInput.open("numbers.txt");
	fileInput >> number[x];

	int high_number[10], low_number[100];                 
    int high = 0, low = 0;        
    high_number[0] = low_number[0] = number[x];

	
	if(!fileInput.is_open()){
		cout<<"File Not Found";
		return 0;
	}
	
	for(x=0;x<10;x++)
		range[x]=0;
	
	x=0;
	
	
	
	cout <<"Number\t"<<"Perfect?\t"<<"Prime? \t"<<"Perfect Square?\t"<<"Sphenic?\t"<<"Binary Equiv."<<endl;
	cout <<"======\t"<<"========\t"<<"====== \t"<<"===============\t"<<"========\t"<<"============="<<endl;
	
	while(number[x] != -1){
		num = number[x];
		
		if(number[x]>=1&&number[x]<=100){
		
			valid++;
				
			temp = num/10;
			if(num%10==0)
				temp--;
			range[temp]++;
			
			if (distinct(number, x) == true){
				
				cout<<number[x]<<"\t"<< perfect(num)<<"\t\t"<< prime(num) << " \t" << per_square(num)<< "\t\t" << sphenic(num)<< "\t\t";
				binary(num);
				cout<<endl;
				
				if(check(number,num,x) > check(number,number[high], x)){
                   high_number[high]=number[x];
                    for(y = x+1; y < x; y++){
                   		 if (check(number,number[y] ,x) == check(number,num, x) && distinct(high_number,high) ){
                    	    high++;
                        	high_number[high] = number[y];
                    	}
                	}
            	}
            	
                if(check(number,num,x) < check(number,number[low], x)){
                   low_number[low]=number[x];
                    for(y = x+1; y < x; y++){
                   		if (check(number,number[y] ,x) == check(number,num, x) && distinct(low_number,low) ){
                   	   	 	if(number[y]>=1&&number[y]<=100){		
								low++;
                        		low_number[low] = number[y];
                        	}
                    	}
                	
            		}    
                }
			}
		}
		
		else if( number[x]<-1 || number[x]>100) {
			inv_num[invalid]=number[x];
			invalid++;
		}

		else{
			not_reveal++;
		}
	
		x++;
		fileInput >> number[x];
	}
	cout<<endl<<endl;

	cout<<"invalid numbers"<<endl;
	cout<< "Number of invalid: \t"<<invalid<<endl;
	for(y=0;y<invalid;y=y+5){
		cout<<inv_num[y]<<"\t\t"<<inv_num[y+1]<<"\t\t"<<inv_num[y+2]<<"\t\t"<<inv_num[y+3]<<"\t\t"<<inv_num[y+4]<<endl;
	}
	cout<<endl<<endl;
	cout<<"high ";
	for(y = 0; y < high; y++){
        cout<<high_number[y];
        if(y != high-1)
            cout<<", ";
    }
	cout<<endl;
	cout<<"low ";
	for(y = 0; y < low; y++){
        cout<<low_number[y];
        if(y != low-1)
            cout<<", ";
    }
	
	cout<<endl<<endl;
	
	cout<<"Valid Numbers: \t"<<valid<<endl;
	
	cout<<endl<<endl;
	
	cout<<"Number of unspecified: \t"<< not_reveal<<endl;
	
	cout<<endl<<endl;
	
	
	
	
	cout<<endl<<endl;
	
	int min = 1, max=10;
	cout<<"Range \tHistogram"<<endl;
    cout<<"======================="<<endl;
    for(y=0;y<10;y++){
    	cout<<min<<"-"<<max<<" \t:";
    	hist(range[y]/5);
    	cout<<endl;
    	min+=10;
    	max+=10;
    	
	}
 }


