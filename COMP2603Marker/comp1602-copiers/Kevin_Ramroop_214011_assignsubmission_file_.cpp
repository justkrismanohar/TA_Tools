#include<iostream>
#include<fstream>
# include <stdio.h>
# include <math.h>
using namespace std;

bool perfect(int n){
	int sum =0;
		for(int i=2; i*i<=n; i++){
			if(n%i==0){
				if(i*i!=n)
					sum = sum + i + n/i;
				else
					sum = sum + i;
			}
		}
		if(sum == n && n != 1)
			return true;
		else
			return false;
}

bool isPrime(int num){
	bool prime= true;
	for(int i= 2; i <= num / 2; i++){
		if(num % i == 0){
			prime = false;
			break;
		}
	}
	return prime;
}

int perfctSqr(int n){
    int square=1;
    int count=1;
    for(int i=1; i<=n; i++){
        square = i*i;
		 if(square==n)
            return 1;
     }
           return 2;
}

int binaryEquivalent(int n){
	int remainder[1000];
	int i = 0;
	while (n > 0){
		remainder[i] = n % 2;
		n = n/ 2;
		i++;
	}
	for (int a = i- 1; a>=0; a--)
		cout<<remainder[a];
}

// sphenic numbers within 1-100 are (30,42,66,70,78)
int primeFactors(int n)
{
	
    int counter=0;
    int x=0;
    ofstream outfile;
    remove( "output.txt" ) ;
    outfile.open("output.txt");


    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
       // printf("%d ", 2);
        n = n/2;
        outfile<<2<<endl;
 counter++;
    }

    // n must be odd at this point.  So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            //printf("%d ", i);
            n = n/i;
       outfile<<i<<endl;
 counter++;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
    {
        // printf ("%d ", n);
            outfile<<n<<endl;
        counter++;
    }

   outfile.close();

       return counter;


}


int makeDistinctArray(int arrayBefore[],int n)
{
    int isDistinct =-99;
       // Pick all elements one by one
    for (int i=0; i<n; i++)
    {
        // Check if the picked element is already printed
        int j;
        for (j=0; j<i; j++)
           if (arrayBefore[i] == arrayBefore[j])
           {
            isDistinct=0;

           }


        // If not printed earlier, then print it
        if (i == j)
        {
            //cout << arrayBefore[i] << " ";
            isDistinct=1;
        }

    }
    cout<<"ONE FOR DISTINCT , 0 FOR NOT DISTINCT : "<<isDistinct<<endl;
    return isDistinct;

}


int main(){
	int counter;
	int n;
	int i = 0;
	char q,w,e,t;
	int r=0;
	int all[1000];
	int num;
	bool prime;
	int result;
	
	ifstream in;
	in.open("numbers.txt");
	if(!in.is_open()){
		cout<<"file couldn't open";
		return 1;
	}
	in>>num;
	while(num!= -1){
		all[i]=num;
		i++;
		in>>num;
	}
	// getting problem assigning file values into array.. not showing up. But when values are entered via cin, it works.
	
	/*while(!in.eof() && i<1000){
		in>>num;
		all[i]=num;
		i++;
	}*/
	
	//while(in>>num)
	//all[i++]=num;
	/*in>>num;
	while(num != -1){
		all[i++]=num;
			
	}*/
	in.close();
	
	cout<<"Number"<<"\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equiv."<<endl;
	cout<<"======"<<"\t"<<"========"<<"\t"<<"======"<<"\t"<<"==============="<<"\t"<<"========"<<"\t"<<"============="<<endl;
	while (all[i]<100 && all[i]>0){
		bool prime;
		prime = isPrime(i);
		if(prime == true){
		
		 q = 'Y';
	}
		else{
			q ='N';
		}
	
	result = perfctSqr(i);
		if(result==1){
			w = 'Y';
		}
		else{
			w = 'N';
		}
	if(perfect(i)){
	
		e = 'Y';
		}
		else{
			e = 'N';
		}
		r=binaryEquivalent(i);
		
		//find prime factors of a number
		counter=primeFactors(i);
		//if counter is more than 3 then it is not sphenic
		if(counter>3){
			t='N';
		}
		else{
			ifstream readFile;
			readFile.open("output.txt");
			int z;
			int primeCounter=0;
			int primeArray[counter];
			
			primeArray[0]=1;primeArray[1]=2;primeArray[2]=3;
			
			//after populating the primeArray from output.txt call the makedistinctArray
			
			 int isDistinct=makeDistinctArray(primeArray,counter);
			if(isDistinct==1){
				t='Y';
				
			}
			else{
				t='N';
			}
			
			
		}
		
	
	
	
	cout<<i<<"\t"<<e<<"\t"<<q<<"\t"<<w<<"\t"<<t<<"\t"<<r<<endl;
	
	}
	while (all[i]<=0 && all[i]>100){
		cout<<i;
	}
	
	return 0;
	
}

//did not get to do histogram as am having trouble with the value inputs; file not giving proper readings but programme compiles
	



