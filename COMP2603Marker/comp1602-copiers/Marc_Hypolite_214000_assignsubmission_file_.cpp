#include<iostream>
#include<fstream>
using namespace std;


int occurleast(int array_used[], int n) 
{ 
    
  
    int max = 1111111111, result = array_used[0], count = 1; 
    for (int i = 1; i < n; i++) { 
        if (array_used[i] == array_used[i - 1]) 
            count++; 
        else { 
            if (count <max) { 
                max = count; 
                result = array_used[i - 1]; 
            } 
            count = 1; 
        } 
    } 
   
    if (count < max) 
    { 
        max = count; 
        result = array_used[n - 1]; 
    } 
  
    return result; 
} 
int occurmost(int array_used[], int n) 
{ 
    
  
    int max = 1, result = array_used[0], count = 1; 
    for (int i = 1; i < n; i++) { 
        if (array_used[i] == array_used[i - 1]) 
            count++; 
        else { 
            if (count > max) { 
                max = count; 
                result = array_used[i - 1]; 
            } 
            count = 1; 
        } 
    } 
   
    if (count > max) 
    { 
        max = count; 
        result = array_used[n - 1]; 
    } 
  
    return result; 
} 
  
void printstar(int n){
	int i;
	for(i=1;i<=n;i++){
		cout<<"*";
	} }
	//to determine the binary of a number
	int finbinary(int num1) {
  int i =0;
	    int bin[10]= {};
	    
for(i=0; num1>0; i++)    
{    
bin[i] = num1%2;    
num1  = num1/2;  
}    

for(i=i-1 ;i>=0 ;i--)    
{    
return bin[i]; 
   
}    
}
	
	

//to determine if a number is sphenic
string ifsphenic(int num){
	int factors[3]= {};
    int tnum = 0;
    int b = 0; 
    int onum = num;
	for(int i =2; i<= num/i; i++){
num = num/i;
factors[b]	= i;
b++; 	
}
if (num> 1){
factors[2] = num;
}
tnum = factors[0]* factors[1] * factors[2] ;
if (tnum == onum ){
	
	return "Y";
}
else{

 return "N";}
}
//to determine if a number is a perfect square
string perfectsquare(int num) {
		int square = 1;
		int i = 1;
		while(square <num)
    {
        square = i * i;
        i++;
    }
    if(square==num)
    {
        return "Y";    
	    
    }
    else
    {
    	  return "N"; 
        
    }
}
//to find prime number
string primenum(int n){ 
		int  i;
  bool isPrime = true;

  for(i = 2; i <= n / 2; ++i)
  {
      if(n % i == 0)
      {
          isPrime = false;
          break;
      }
  }
  if (isPrime)
        return "Y";
  else
       return "N";

	}


//determine if number is perfect
string perfectnum(int num){
int a = 1,divide = 0, sum = 0;	
		  for( a= 1;a < num;a++)
    {
        divide = num % a;
        if (divide == 0)
            sum = sum + a;
    }
    if (sum == num){
         return "Y";
       }
    else{
	 return "N"; 	
       }
		}


int main(){
	int least = 0;
	int most = 0 ;
	int valid = 0 ;
	int invalid = 0;
	int noreveal = 0 ;
	int stars = 0;
	int A_stars[10] = {};
	int k = 0;
	int square = 1;
	bool primenum1;
	int occur[100] = {};
	int numbers[124] = {};
	int c = 0;
	int i = 0;
	int q = 0;
	int j =0;
	int a = 1;
	int num = 0;
	int e = 0;
    int b = 0;	
	string Perfect[124] = {}; //123
	string Primet[124] = {};
	string Psquare[124] = {};
	string Sphenic[124] = {};
	int  binary[124] = {};
	ifstream fin;
	fin.open("numbers.txt");
	if(!fin.is_open()){cout<<"error";
	return 0;
	} else{ 
	fin>>c;
	    while(c != -1){ //numbers into array
	    numbers[i] = c;
		fin>>c;
		cout<<endl<<endl;
		i++;}	
	
	//to find prime number
	  for(k =0;k<124;k++){
	Primet[k] = primenum(numbers[k]);
	}
	//to determine if the numbers are perfect
    	for(e =0;e<124;e++){
	Perfect[e] = perfectnum(numbers[e]);
	}
	
	//determine if the number is a perfect square 
    e= 0;
    	for(e =0;e<124;e++){
     Psquare[e] = perfectsquare(numbers[e]);
	 }
     
	// determine if number is Sphenic
num = 0;
e= 0;
	for(e =0;e<124;e++){
		
		Sphenic[e] = ifsphenic(numbers[e]);
		}
	//convert the number to binary
e = 0;
num = 0;
i = 0;
    	for(e =0;e<124;e++){
	    binary[e] = finbinary(numbers[e]);
	    
    } 
    
    
    
//displaying the table
		
cout<<"Number\tPerfect\tPrime\tPerfect Square?\tSphenic?\tBinary Equiv."<<endl;
cout<<"================================================================"<<endl;	
e =	0; 
	for(e =0;e<124;e++){
cout<<numbers[e]<<"\t"<<Perfect[e]<<"\t"<<Primet[e]<<"\t"<<Sphenic[e]<<"\t"<<binary[e]<<endl;


}

//invalid numbers
cout<<endl;
cout<<"________________________________________________________________"<<endl;
cout<<"The invalid numbers are listed below; "<<endl;
 e= 0;
 for (e=0;e <124;e++){
 	     if (numbers[e] >100 || numbers[e] <0){
 	     	cout<<numbers[e]<<" ";
 	     	if(e%4==0){
 	     		cout<<endl;
			  }
		  }
}
//histogram
int occur[10]= {};
	 e= 0;
 for (e=0;e<124;e++){
if (numbers[e]>0 && numbers[e] <11){
	occur[0]++;
}

if (numbers[e]>10 && numbers[e] <21){
	occur[1]++;
}


if (numbers[e]>20 && numbers[e] <31){
	occur[2]++;
}

if (numbers[e]>30&& numbers[e] <41){
	occur[3]++;
}

if (numbers[e]>40&& numbers[e] <51){
	occur[4]++;
}

if (numbers[e]>50&& numbers[e] <61){
	occur[5]++;
}

if (numbers[e]>60&& numbers[e] <71){
	occur[6]++;
}


if (numbers[e]>70&& numbers[e] <81){
	occur[7]++;
}


if (numbers[e]>80&& numbers[e] <91){
	occur[8]++;
}

if (numbers[e]>90&& numbers[e] <101){
	occur[9]++;
}
}
cout<<endl;
cout<<"------------------------------------------------------------------"<<endl;
 cout<<endl<<endl;
  cout<<"Range\tHistogram"<<endl;
	 cout<<"================"<<endl;
	 k=0;
	 for(k=0;k<10;k++){
	 	  stars = occur[k];
	 	  A_stars[k] = stars/5;}
	 	  
//values intialized to be used in the loop to print the histogram
k= 0;
int z =1;
int v = 10;

//loop to print histogram
for(k=0;k<10;k++){
 	
cout<<z<<" - "<<v<<"\t|";
printstar(A_stars[k]);
cout<<endl;
z += 10;
v+=10;}


	e=0;
	
	for(e=0;e<124;e++){
		if(numbers[e] >0 && numbers[e]<100){
			valid++;
		}
		  if (numbers[e] >100 || numbers[e] <0){
	     invalid++;	
	}
	if (numbers[e]== 0){
		noreveal++;
	}
	
	}
	
	most = occurmost(numbers,124);
    least = occurleast(numbers,124);
	cout<<endl<<endl;
	
	cout<<"the amount of students who specified valid numbers is: "<<valid<<endl;
	cout<<"the amount of students who specified invalid favourite numbers is: "<<invalid<<endl;
	cout<<"the amount of students who did not reveal their favourite number is: "<<noreveal<<endl;
    cout<<"The number that were chosen the most by the students: "<<most<<endl;
	cout<<"The number that was/were chosen the least by the students:  "<<least<<endl;	
	
	
	
	
	
	
	
	
	





     return 0; } }
