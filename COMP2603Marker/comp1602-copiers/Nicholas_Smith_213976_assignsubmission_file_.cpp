#include <iostream>
#include <fstream>
using namespace std;
char isPrime(int n){
	int i, prime;
	if(n == 1){
		return 'N';
	}
	for (i=2; i<= n/2; i++){

		if(n%i == 0){
			return 'N';
		}
		
	}
    return 'Y';
}
char isPerfectSqr(int n){
	int sqr = 1;
	int counter =1;
	for (int i=1;i<=n;i++){
		sqr =i*i;
		if(sqr==n){
			return 'Y';
		}else{
			return 'N';
		}
	}
	
}
char perfectNum(int n){
	int div, sum=0, i;
	for(i=0;i<n;i++){
		div = n%1;
		if(div == 0){
			sum=sum+i;
		}
		
	}
	if(sum == n){
			return 'Y';
			
		}else{
			return 'N';
		}
}

char isSphenic(int n){
	int i, count, product;
	count = 0;
	product = 1;
	for(i=2; i<=n/2;i++){
		if(n%i==0 && isPrime(i)){
			product=product*i;
			count++;
		}
	}
	
	if(count==3 && product == n){
		return 'Y';
	}else{
		return 'N';
	}
	
}
int convert(int n){
    int i = 8, q; 
    int binaryNum[i]; 
    
    for(q = 0; q<i; q++){
    	binaryNum[q] = 0;
	}
	int w = 0;
    while (n > 0) { 
  
        binaryNum[w] = n % 2; 
        
        n = n / 2; 
        if(n==0){
        	w = n;
		}
        w++; 
    } 
  
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j];
}

int main (){
	ifstream in;
	ofstream out;
	ofstream output;
	in.open("numbers.txt");
	
	int numbers, num[366], z=0, invalid, y, range[10] = {0,0,0,0,0,0,0,0,0,0}, secret[20], t=0, l, k, begin=1, end=10, a=0, p, valid[130], sec, vali, max = 0, flag = 0, count[1000], v=0, number;
	int result, counter = 0, maxVal= 0, maxNum, c=0;
	char primeVar, psVar, pnVar, sphenicV;
	if(!in.is_open()){
		cout<<"Error opening file Numbers!!"<<endl;
		return 0;
	}
		
	cout<<"Number"<<"\t"<<"Prime?"<<" \t"<<"PerfectSquare?"<<"\t"<<"PerfectNum?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equivalent"<<endl;
	cout<<"======"<<"\t"<<"======"<<"\t"<<"============="<<"\t"<<"==========="<<"\t"<<"========="<<"\t"<<"=================="<<endl;
	in>>numbers;
	while (numbers != -1){
		count[v]=numbers;
		v=v+1;
		if((numbers >= 1) && (numbers <=100)){
			valid[a] = numbers;
			a=a+1;
			
	       primeVar = isPrime(numbers);
	       psVar = isPerfectSqr(numbers);
	       pnVar = perfectNum(numbers);
	       sphenicV = isSphenic(numbers);
		   cout<<numbers;
		   cout<<"\t"<<primeVar<<"\t" ;
		   cout<<psVar<<" \t \t";
		   cout<<pnVar<<" \t \t";
		   cout<<sphenicV<<" \t \t";
		   convert(numbers);
	       cout<<endl; 
	    }else if((numbers < 0) || (numbers > 100)){
	    		num[z]=numbers;
	    		z=z+1;
			} else if(numbers == 0){
			secret[t]=numbers;
			t=t+1;
		}
		
		in>>numbers;
	}
	sec = t;
	vali = a;
	invalid = z;
	cout<<endl;
	
	
	
	for(l = 0;l < vali;l++){
		if((valid[l] >= 1)&&(valid[l] <= 10)){
				range[0]=range[0]+1;
			}else if ((valid[l] >=11)&&(valid[l] <= 20)){
				range[1]=range[1]+1;
			}else if ((valid[l] >=21)&&(valid[l] <= 30)){
				range[2]=range[2]+1;
			}else if ((valid[l] >=31)&&(valid[l] <= 40)){
				range[3]=range[3]+1; 
			}else if ((valid[l] >=41)&&(valid[l] <= 50)){
				range[4]=range[4]+1;
			}else if ((valid[l] >=51)&&(valid[l] <= 60)){
				range[5]=range[5]+1;
			}else if ((valid[l] >=61)&&(valid[l] <= 70)){
				range[6]=range[6]+1;
			}else if ((valid[l] >=71)&&(valid[l] <= 80)){
				range[7]=range[7]+1;
			}else if ((valid[l] >=81)&&(valid[l] <= 90)){
				range[8]=range[8]+1;
			}else if ((valid[l] >=91)&&(valid[l] <= 100)){
				range[9]=range[9]+1;
			}
	}
	
	
	for(int y = 0;y<z;y++){
		if( y%5 ==0 ){
			cout<<endl;
		}
		
			cout<<num[y]<<" "<<", ";			
	}
	
	cout<<endl;
	cout<<"Histogram"<<endl;
	cout<<"================================="<<endl;
	for(k=0;k < 10; k=k+1){
		cout<<begin<<" to "<< end;
		cout<<"\t\t\t";
		int n=range[k];
		while(n >= 5){
			cout<<"*";
			n=n-5;
		}
		cout<<endl;
		
		begin = begin+10;
		end = end+10;
	}
	int minValues[100];
	for(int f = 0; f < a;f++){
			for(int h = 0; h < a; h++){
				
				if(valid[f] == valid[h]){
					
				max= max+1;	
				}
				
				
			}
		if(max> maxVal){
				maxVal = max;
				maxNum = valid[f];
			}
			
		if(max == 1){
			minValues[c] = valid[f]; 
			c=c+1;
		}	
		max = 0;
		
		
	}
	for (int d = 0; d < c; d++){
		cout<<minValues[d]<<" ";
	}
	cout<<endl;
	cout<<"Showed the most"<<" "<<maxNum<<endl;	
	
	cout<<"Amount of students specified valid numbers: "<<vali<<endl;
	cout<<"Amount of students didn't specify numbers: "<<sec<<endl;
	cout<<"Amount of students specified invalid numbers: "<<invalid<<endl;
	//cout<<"The number picked the most is: "<<maxNum<<endl;

	
	cout<<"Program Executed succesfully!"<<endl;
	return 0;
}
