//REBEKAH SOONACHAN 816002189 A1
#include <iostream>
#include <fstream>
using namespace std;

bool isValid (int n){
	
	if ((n>=1) && n<=100)
	    return true;
	return false;    
}
bool isPerfect(int n){
	int sum=0;
	for(int i=2; i<=n/2; i++){
	if(n%i==0)
	sum=sum+i;
}
	if(n==sum)
	return true;
	else
	return false;
}

bool isPrime(int n){
	int f=0;
	for(int i=2; i<=n/2; i++){
		if(n%i==0){
			f=1;
			break;
		}
	}
	if(f==0)
	return true;
	else
	return false;
	
}

bool isPerfectSquare(int n){
	int i, sum;
	for(i=1; i<n; i++){
		sum= i*i;
		if(sum==n)
	return true;
	}
	return false;
}

bool isSphenic(int n){
	int p,q,r,s;
	
	for(int i=2; i<=n/2; i++){
		if(isPrime(i) && n%i==0){
			p=i;
			s=n/i;
			
			for(int j=2; j<=s/2; j++){
				if(isPrime(j) && s%j==0){
					q=j;
					s=s/j;
					
					for(int k=2; k<=s; k++){
						if(isPrime(k) && s%k==0){
							r=k;
							
							if((p*q*r==n) &&(p!=q && (p!=r && q!=r))){
							return true;	
							}
						}
					}
				}
			}
		}
	}
	return false;
			
}
	
	
void convertToBinary(int n){
	int binary[8];
	int a=0;
	
	for (int b=0; b<8; b++)
	    binary[b]=0;
	while(n>0){
		binary[a]=n%2;
		n=n/2;
		a++;
	}
	a=7;
	while (a>=0){
		cout<<binary[a];
		a--;
	}
	
	cout<<endl;
		
}


void printHistogram(int a){
	if (a>=5){
	    while (a>=5){
		    cout<<"*";
		    a=a-5;
	    }
	}
}

void most (int n[], int a){
    int mostOcc=0, freq=0, mostFreq=0, i=0, temp=0, mostOccArray[1000], b=0;
	
	while (i<a){
		
		int freq=0;
		b=0;
		temp=n[i];
		
		while (b<a){
			if (temp==n[b])
				freq++;
			b++;
			
		}
		
		if (freq>mostFreq){
			mostFreq=freq;
		}
		i++;
	}
	
	i=0, b=0, freq=0;
	int c=0;
	
	while (i<a){
		freq=0;
		b=0;
		temp=n[i];
		
		while(b<a){
			if (temp==n[b])
			    freq++;
	    	b++;
	    }
		
		if (freq==mostFreq){
			
			int e=0;
			while (temp!=mostOccArray[e] && e<c)
			    e++;
				
			
			
			if (c==e){
			    mostOccArray[c]=temp;
			    c++;
			}
		}
		i++;	    
	}
	mostOccArray[c]=-1;
	
	int d=0;
	cout<<"Most Occurring: "<<endl;
	
	int f=0;
	while (mostOccArray[d]!=-1){
		cout<<mostOccArray[d]<<"   ";
		d++;
		f++;
		if (f==4){
			cout<<endl;
			f=0;
		}
	}
	cout<<endl;
	cout<<"Frequency: "<<mostFreq<<endl;
	
}


void least (int n[], int a){
    int leastOcc=0, freq=0, leastFreq=a, i=0, temp=0, leastOccArray[1000], b=0;
	
	while (i<a){
		
		int freq=0;
		b=0;
		temp=n[i];
		
		while (b<a){
			if (temp==n[b])
				freq++;
			b++;
			
		}
		
		if (freq<leastFreq){
			leastFreq=freq;
		}
		i++;
	}
	
	i=0, b=0, freq=0;
	int c=0;
	
	while (i<a){
		freq=0;
		b=0;
		temp=n[i];
		
		while(b<a){
			if (temp==n[b])
			    freq++;
	    	b++;
	    }
		
		if (freq==leastFreq){
			
			int e=0;
			while (temp!=leastOccArray[e] && e<c)
			    e++;
				
			
			
			if (c==e){
			    leastOccArray[c]=temp;
			    c++;
			}
		}
		i++;	    
	}
	leastOccArray[c]=-1;
	
	int d=0;
	cout<<"Least Occurring: "<<endl;
	
	int f=0;
	while (leastOccArray[d]!=-1){
		cout<<leastOccArray[d]<<"   ";
		d++;
		f++;
		if (f==4){
			cout<<endl;
			f=0;
		}
	}
	cout<<endl;
	cout<<"Frequency: "<<leastFreq<<endl;
	
}



int main(){
	
	int n, x=0, validNos=0, invalidNos=0, NR=0;
	int invalid[100];
	int valid[3000];
	char perfect, prime, square, sphenic;
	
	ifstream fin;
	fin.open("numbers.txt");
	
	if (!fin.is_open()){
		cout<<"Error. File not found"<<endl;
		return 0;
	}
	
	
	fin>>n;
	
	cout<<"Number"<<"\t"<<"Perfect"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary"<<endl;
	
	while(n!=-1){
		
		if (isValid(n)){
		
		    if (isPerfect(n))
		        perfect='T';
		    else
		        perfect='F';
			
			
		    if (isPrime(n))
		        prime='T';
		    else
		        prime='F';
			
			
		    if (isPerfectSquare(n))
		        square='T';
		    else
		        square='F';
			
			
		    if (isSphenic(n))
		        sphenic='T';
		    else
		        sphenic='F';			
			    
	
	        cout<<n<<"\t"<<perfect<<"\t"<<prime<<"\t"<<"    "<<square<<"\t"<<"         "<<sphenic<<"\t"<<"         ";
	        convertToBinary(n);
	        validNos++;
	        valid[validNos-1]=n;
        }
        
        else{
    	    if (n!=0){
    		    invalid[x]=n;
    		    x++;
    		    invalidNos++;
		    }
		    else
		        NR++;
        }
        fin>>n;
    	
	}
	cout<<endl;
	cout<<endl;
	
	cout<<"Invalid Numbers: "<<endl;
	for (int i=0; i<x; i++){
		cout<<invalid[i]<<"     ";
		if (i%5==4)
		    cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	
	cout<<"Range"<<"\t"<<"   Histogram"<<endl;
	
	int ones=0, tens=0, twenties=0, thirties=0, forties=0, fifties=0, sixties=0, seventies=0, eighties=0, nineties=0, q=validNos;
	while (q>0){
		if (valid[q-1]>=1 && valid[q-1]<=10)
		     ones++;
		if (valid[q-1]>=11 && valid[q-1]<=20)
		     tens++;
		if (valid[q-1]>=21 && valid[q-1]<=30)
		     twenties++;
		if (valid[q-1]>=31 && valid[q-1]<=40)
		     thirties++;	 	      
		if (valid[q-1]>=41 && valid[q-1]<=50)
		     forties++;
		if (valid[q-1]>=51 && valid[q-1]<=60)
		     fifties++;
		if (valid[q-1]>=61 && valid[q-1]<=70)
		     sixties++;	 	      
		if (valid[q-1]>=71 && valid[q-1]<=80)
		     seventies++;     
		if (valid[q-1]>=81 && valid[q-1]<=90)
		     eighties++;
		if (valid[q-1]>=91 && valid[q-1]<=100)
		     nineties++;
			 
		q--;	 	      
	}
	
	cout<<"1-10"<<"\t"<<"     ";
	printHistogram(ones);
	cout<<endl;
	
	cout<<"11-20"<<"\t"<<"     ";
	printHistogram(tens);
	cout<<endl;
	
	cout<<"21-30"<<"\t"<<"     ";
	printHistogram(twenties);
	cout<<endl;
	
	cout<<"31-40"<<"\t"<<"     ";
	printHistogram(thirties);
	cout<<endl;
	
	cout<<"41-50"<<"\t"<<"     ";
	printHistogram(forties);
	cout<<endl;
	
	cout<<"51-60"<<"\t"<<"     ";
	printHistogram(fifties);
	cout<<endl;
	
	cout<<"61-70"<<"\t"<<"     ";
	printHistogram(sixties);
	cout<<endl;
	
	cout<<"71-80"<<"\t"<<"     ";
	printHistogram(seventies);
	cout<<endl;
	
	cout<<"81-90"<<"\t"<<"     ";
	printHistogram(eighties);
	cout<<endl;
	
	cout<<"91-100"<<"\t"<<"     ";
	printHistogram(nineties);
	cout<<endl;
	
	
	cout<<endl;
	cout<<endl;
	
	
	cout<<"Number of valid entries: "<<validNos<<endl;
	cout<<"Number of invalid entries: "<<invalidNos<<endl;
	cout<<"Number of no responses: "<<NR<<endl;
	
	cout<<endl;
	cout<<endl;
	
	most(valid, validNos);
	cout<<endl;
	least (valid, validNos);
	
	
    fin.close();
    system ("pause");
	return 0;
}
