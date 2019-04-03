#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

bool isPerfect(int n){
	int div, sum=0;
	for(int x=1; x<n; x++){
		div=n % x;
		if(div==0)
			sum=sum + x;
	}
	
	if(sum==n)
		return true;
		
		return false;
}

bool isPrime(int n){
	for(int x=2; x<=n; x++)
		if(n%x==0)
		return false;
		
		return true;
}

bool perfectSq(int n){
		int sq;
	
	for(int x=1;x<=n/2;x++){
		sq=x*x;
		if(sq==n)
		return true;
	}
		return false;
}

bool isSphenic(int n){
	int count=0, product=1;
			
	for(int x=2; x<=n/2; x++){
		if(n%x==0&&isPrime(x)){
			product=product*x;
			count=count+1;
		}
		if(count==3&&product==n)
		return true;
		
		return false;
		}
}

void binaryEq(int n){
	int bit[8];
    for(int x=7; x>=0;x--){
        bit[x]= n%2;
        n= n/2;
    }
    
    for(int i=0; i<8; i++)
        cout << bit[i];
}

void printStar(int n){
	while(n>=5){
		cout<<"*";
		n=n-5;
	}
	cout<<endl;
}

int main(){
	ifstream input;
	input.open("numbers.txt");
	if (input.is_open()==false){
		cout<<"File not found."<<endl;
		return 1;
	}
	
	cout<<"Number"<<'\t'<<"Perfect?"<<'\t'<<"Prime?"<<'\t'<<"Perfect Square?"<<'\t'<<"Sphenic?"<<'\t'<<"Binary Equiv."<<endl;
	cout<<"======"<<'\t'<<"========"<<'\t'<<"======"<<'\t'<<"==============="<<'\t'<<"========"<<'\t'<<"============="<<endl;
	
	int num[1000],range[10], nInvalid[1000], i=0, n, valid=0,invalid=0, nRev=0, line=0, count=0 ;
	
	
	input>>n;
	
	while(n!=-1){
		
		//Valid?
	if ((n>0)&&(n<=100)){
		num[i]=n;
		i++;
		valid++;
		
		//Histogram vote
	if((n>=1)&&(n<=10))
        range[0]++;
            
    else if((n>10)&&(n<=20))
		range[1]++;
		
    else if((n>20)&&(n<=30))
        range[2]++;
        
    else if((n>30)&&(n<=40))
        range[3]++;
        
    else if((n>40)&&(n<=50))
    	range[4]++;
    	
    else if((n>50)&&(n<=60))
        range[5]++;
        
    else if((n>60)&&(n<=70))
        range[6]++;
        
    else if((n>70)&&(n<=80))
        range[7]++;
        
    else if((n>80)&&(n<=90))
        range[8]++;
        
    else if((n>90)&&(n<=100))
        range[9]++;
    
    //Yes or No Table + Binary
    	
    cout<<n<<'\t';
    		
    if(isPerfect(n))
       	cout<<"Y"<<'\t'<<'\t';
    else
    cout<<"N"<<'\t'<<'\t';
        
     
    if(isPrime(n))
        cout<<"Y"<<'\t'<<'\t';
    else
    cout<<"N"<<'\t'<<'\t';
            
     
    if(perfectSq(n))
        cout<<"Y"<<'\t';
    else
    cout<<"N"<<'\t';
            
            
    if(isSphenic(n))
        cout <<"Y"<<'\t'<<'\t';
    else
    cout <<"N"<<'\t'<<'\t';
            
	binaryEq(n); 
    cout << endl;
	

	}
	
	//Not revealed or Invalid?
	else{if(n==0)
		nRev++;
		else{
		invalid++;
		nInvalid[count]=n;
        count++;
    }
	}
	    
		input>>n;
	}
	
	cout<<endl<<endl;
	cout<<"Invalid numbers:"<<endl;
	  
	  //List of Invalid Numbers
	for(int x=0; x<count; x++){
		
        cout<<nInvalid[x]<<'\t';
        line++;
        
        if(line==5){
        cout<<endl;
        line= 0;
        }
    }
	
	//Drawing Histogram
	cout<<endl<<endl;
	cout<<"Range    Histogram"<<endl;
	cout<<"==================="<<endl;
	cout<<"1-10     |";
						printStar(range[0]);
	cout<<"11-20    |";
						printStar(range[1]);
	cout<<"21-30    |";
						printStar(range[2]);
	cout<<"31-40    |";
						printStar(range[3]);
	cout<<"41-50    |";
						printStar(range[4]);
	cout<<"51-60    |";
						printStar(range[5]);
	cout<<"61-70    |";
						printStar(range[6]);
	cout<<"71-80    |";
						printStar(range[7]); 
	cout<<"81-90    |";
						printStar(range[8]);
	cout<<"91-100   |";
						printStar(range[9]); 
	
	//Stats No.of Valid, Invalid, not Revealed
	cout<<endl<<endl;
	cout<<"Statistics"<<endl;
	cout<<"Amount of students who specified :"<<endl;
	cout<<"Valid Favourite Numbers- "<<valid<<endl;
	cout<<"Invalid Favourite Numbers- "<<invalid<<endl<<endl;
	cout<<"Amount of students who did not reveal their favourite number:"<<nRev<<endl<<endl;
	
	// Most/Least Popular	
 int mostValue[1000], leastValue[1000],most, least;
 for(i=0; i<(valid-1); i++){
        if(num[i]>2){
            if(num[i]>most){
                most= num[i];
                mostValue[0] = i+1;
            }
        }

        if(num[i]>=1){
            if(num[i]<least){
                least = num[i];
                leastValue[0] = i+1;
            }
        }
    }

int z=0, c= 0;

    for(i=0; i<100; i++){
        if(num[i]>2){
            if((num[i]==most) && ((i+1)!=mostValue[0])){
                z++;
                mostValue[z] = i+1;
            }
        }

        if(num[i]>=1){
            if((num[i]==least) && ((i+1)!=leastValue[0])){
                c++;
                leastValue[c] = i+1;
            }
        }
    }

    cout<<endl;

    if(z==0)
        cout << "The number that was chosen the most by the students is " << mostValue[0] << endl ;
    else{
        cout << "The numbers that were chosen the most by the students are: "<<endl;
        for(i=0; i<z; i++){
            cout << mostValue[i] <<endl;
        }
    }

    cout <<endl;
    if(c==0)
    cout << "The number that was chosen the least by the students is " << leastValue[0] << endl ;
    else{
        cout << "The numbers that were chosen the least by the students are:"<<endl;
        for(i=0; i<c; i++){
            cout << leastValue[i] <<endl;
        }
    }
	
	
	
	
	
	
	input.close();
    return 0;
	}

