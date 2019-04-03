#include <iostream>
#include <fstream>
using namespace std;

bool perfect(int num){					//part b, part i
	
	int i, div, sum;
	sum = 0;
	
	for (i=1; i < num; i++){
        div = num % i;
        if (div == 0)
            sum = sum + i;
    }
    
    if (sum == num)
        return true;
    else
        return false;	
}


bool prime(int num) {					//part b, part ii

	int i;
	bool isPrime=true;
	
	if(num==1){
		isPrime = false;
	}
	
	for(i = 2; i <= num / 2; ++i){
      
	  if(num % i == 0){
          isPrime = false;
      }
      
  	}
  	
    if (isPrime == false)
    	return false;
    else
        return true;

}

bool perfectSquare(int num){				//part b, part iii
    
	int sq;

    for(int i=1; i<=num; i++){
        
		sq = i*i;
		
		if(sq==num) 
        	return true;

	}

	return false;
}

bool sphenic(int num) {						//part b, part iv

	int c=0, prod=1, i;
	
	for(i=2; i<=num/2; i++){
		if(num%i==0 && prime(i)){
			prod=prod*i;
			c=c+1;
		}
		if(c==3 && prod==num){
		return true;
		}
	}
	
	return false;
}

void dec2bin(int num) { 						//part b, part v

    int binnum[8] = {}; 
	int i = 7; 
 
    while(num!=0){
    	if (num%2 == 0)
		binnum[i] = 0; 
    	else if (num%2 == 1)
		binnum[i]  = 1;
		i--;
		num = num/2;
	}
  
    for (i=0; i<=7; i++) {
        cout<<binnum[i]; 
	}
	
} 


int main (){
	
	ifstream inputFile;
	int num,i;
	int invalid[20] = {0};
	i = 0;
	int count_invalid=0;
	int z;
	int count_no_reveal=0;
	int no_reveal[20] = {0};
	int x=0;
	int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, k=0, p=0;
	int valid=0;
	int v=0;
	int valid_number = 0;
	int val[1000] = {};
	int mosCHO[101] = {};
	int leasCHO[101] = {};
	int w = 0;
	int y = 0;
	int r = 0;
	int mostSUM;
	int leastSUM;
	
	
	int counter[101] = {0};
	int most_times=0, least_times=9999, most_common=0, least_common=0;


	
	inputFile.open("numbers.txt");		//part a: opening the file
	
	if(!inputFile.is_open()) {
		cout<<"Error opening input file. Aborting...";
		return 0;
	}
	
	inputFile>>num;						//part a: reading numbers specified by the students
	
	cout<<"Number"<<"	"<<"Perfect?"<<"	"<<"Prime?"<<"	"<<"Perfect Square?"<<"	"<<"Sphenic?"<<"	"<<"Binary Equiv."<<endl;
	cout<<"======"<<"	"<<"========"<<"	"<<"======"<<"	"<<"==============="<<"	"<<"========"<<"	"<<"============="<<endl;

	while (num!=-1) {
		
		if(num>=1 && num<=100) {			//part b: check for valid numbers
		
		if (num>=1 && num<=10){
			a = a+1;
		}
		
		if (num>=11 && num<=20){
			b = b+1;
		}
		
		if (num>=21 && num<=30){
			c = c+1;
		}
		
		if (num>=31 && num<=40){
			d = d+1;
		}
		
		if (num>=41 && num<=50){
			e = e+1;
		}
		
		if (num>=51 && num<=60){
			f = f+1;
		}
		
		if (num>=61 && num<=70){
			g = g+1;
		}
		
		if (num>=71 && num<=80){
			h = h+1;
		}
		
		if (num>=81 && num<=90){
			k = k+1;
		}
		
		if (num>=91 && num<=100){
			p = p+1;
		}
		
		cout<<num<<"	";				//part b: display number
			
		if(perfect(num)==true){			//part b: display if perfect
			cout<<"Y"<<"		";
		}
		else {
			cout<<"N"<<"		";
		}
			
		if(prime(num)==true){			//part b: display if prime
			cout<<"Y"<<"	";
		}
		else {
			cout<<"N"<<"	";
		}
			
		if(perfectSquare(num)==true){			//part b: display if perfect square
			cout<<"Y"<<"		";
		}
		else {
			cout<<"N"<<"		";
		}
				
		if(sphenic(num)==true){				//part b: display if sphenic
			cout<<"Y"<<"		";
		}
		else {
			cout<<"N"<<"		";
		}	
			
		dec2bin(num);							//part b: display binary	
		
		valid=valid+1;
		
		val[i]=num;
		
		cout<<endl;
		
		i++;
		}
		
		else {												
			
			if (num==0){
				
			count_no_reveal = count_no_reveal + 1;
			
			no_reveal[x]=num;
			
			x=x+1;
			}
			
			else {											//part c	
			
			if (num<1 || num>100) {
			
			count_invalid=count_invalid + 1;
			
			invalid[v]=num;
			
			v=v+1;
			}
			}
		}
			
	inputFile>>num;	

		
	}
	
	cout<<endl;
	cout<<endl;
	cout<<"All invalid numbers are: "<<endl;
	

	
		for (i=0; i<count_invalid;i=i+1){								
			
			cout<<invalid[i]<<" ";
		
			if ((i+1) % 5 == 0){
				cout<<endl;
			}
		
		}
	
	
	cout<<endl;
	cout<<endl;
	cout<<"Range"<<"		  "<<"Histogram"<<endl;
	cout<<"==========================="<<endl;
	
	int a_star_count = a/5;
	int b_star_count = b/5;
	int c_star_count = c/5;
	int d_star_count = d/5;
	int e_star_count = e/5;
	int f_star_count = f/5;
	int g_star_count = g/5;
	int h_star_count = h/5;
	int k_star_count = k/5;
	int p_star_count = p/5;
	
	cout<<"1-10"<<"		  |";
	for (i=1; i<=a_star_count; i++){
		cout<<"*";
	}
	
	cout<<endl;
	
	cout<<"11-20"<<"		  |";
	for (i=1; i<=b_star_count; i++){
		cout<<"*";
	}
	
	cout<<endl;
	
	cout<<"21-30"<<"		  |";
	for (i=1; i<=c_star_count; i++){
		cout<<"*";
	}

	cout<<endl;
	
	cout<<"31-40"<<"		  |";
	for (i=1; i<=d_star_count; i++){
		cout<<"*";
	}
	
	cout<<endl;
	
	cout<<"41-50"<<"		  |";
	for (i=1; i<=e_star_count; i++){
		cout<<"*";
	}	
	
	cout<<endl;
	
	cout<<"51-60"<<"		  |";
	for (i=1; i<=f_star_count; i++){
		cout<<"*";
	}
	
	cout<<endl;
	
	cout<<"61-70"<<"		  |";
	for (i=1; i<=g_star_count; i++){
		cout<<"*";
	}
	
	cout<<endl;
	
	cout<<"71-80"<<"		  |";
	for (i=1; i<=h_star_count; i++){
		cout<<"*";
	}

	cout<<endl;
	
	cout<<"81-90"<<"		  |";
	for (i=1; i<=k_star_count; i++){
		cout<<"*";
	}
	
	cout<<endl;
	
	cout<<"91-100"<<"		  |";
	for (i=1; i<=p_star_count; i++){
		cout<<"*";
	}
	
	cout<<endl;
	cout<<endl;
	
	cout<<"The amount of students who specified valid favourite numbers: "<<valid<<" students."<<endl;
	cout<<"The amount of students who specified invalid favourite numbers: "<<count_invalid<<" students."<<endl;
	cout<<"The amount of students who did not reveal their favourite number: "<<count_no_reveal<<" students."<<endl;
	
	for (w=0; w<valid; w++){
		valid_number=val[w];
		counter[valid_number]++;
	}
	
	for (int w=1; w<=100; w++) {
	
		if(counter[w] > most_times && counter[w] > 1) {
			most_times = counter[w];
			//most_common = w;
		}
		
		else {
			if (counter[w] < least_times && counter[w] > 0){
				least_times = counter[w];
				//least_common = w;
			}
		}
	
	}
	
	for (w=1; w<=100; w++){
		if(counter[w]==most_times){
			mosCHO[y] = w;
			y++;
		}
		if(counter[w]==least_times){
			leasCHO[r]=w;
			r++;
		}
	}
	
	mostSUM=y;
	leastSUM=r;
	
	cout<<endl;
	cout<<"The number/s that was/were chosen the most by the students is/are: "<<endl;
		for (w=0; w<mostSUM; w++){
			cout<<mosCHO[w]<<" ";
		}
	
	cout<<endl;
	cout<<endl;
	cout<<"The number/s that was/were chosen the least by the students is/are: "<<endl;
		for (w=0;w<leastSUM; w++){
			cout<<leasCHO[w]<<" ";
		}
	
	
	inputFile.close();
	return 0;
}
