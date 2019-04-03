//Kyle Sukhdeo
//816014143

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool isPerfect(int n1){
	int sum = 0, di = 0;
	for(int i = 1; i < n1; i++){
		di = n1 % i;
		if(di == 0)
			sum = sum + i;		
	}
	if(sum == n1)
		return true;
	else
		return false;
}

bool isPrime(int n2){
	for(int j = 2; j = n2 / 2; j++)
		if(n2 % j == 0)
			return false;
		else
			return true;
}

bool isPerSqu(int n2){
	if (n2 < 0)
        return false;
    int root(round(sqrt(n2)));
    return n2 == root * root;
}

bool isSphenic(int n2){
	int count = 0, prod = 1;
	for(int i = 1; i < n2; i++){
		if(n2%i == 0){
			if(isPrime(i/2)){		
				count++;
				prod=prod*i/2;
			}
		}
	}
	
	if(count == 3 && prod == n2){
		return true;
	}
	return false;
}


void bin(int n2){
	int bi;
	if(n2 == 0||n2 == 1){
		cout<< n2;
	}
    while (n2 > 1)
    {
        bi = n2 % 2;
        cout << bi;
        n2 /= 2;
    }
    
}

int dis(int n2){
	int c[100];
	for(int k = 0; k < 101; k++){
		c[k] = 0;
	}
}


int main(){
	ifstream in;
	ofstream out;
	int n, count = 0;
	in.open("numbers.txt");
	in>>n;
	int a[100];
	
	cout<<"Number \t     Perfect? \t      Prime? \t Perfect Square?    Sphenic? \t      Binary Equiv."<<endl;
	cout<<"====== \t     ======== \t      ====== \t ===============    ======== \t      ============="<<endl;
	
	for(int o = 0; o < 101; o++){
		a[o] = 0;
	}
	
	while(n!=-1){
		count++;
		if(n < 101 && n > 0)
		if(a[n] == 0){
		a[n]++;
		 
		cout<<n<<"\t  \t";
		
		if(isPerfect(n)){
			cout<<"Y";
		}else cout<<"N";
		cout<<"\t  \t";
		
		if(isPrime(n)){
			cout<<"Y";
		}else cout<<"N";
		cout<<"\t  \t";
		
		if(isPerSqu(n)){
			cout<<"Y";
		}else cout<<"N";
		
		cout<<"\t  \t";
		
		if(isSphenic(n)){
			cout<<"Y";
		}else cout<<"N";
		cout<<"\t  \t";
		
		bin(n);
		cout<<"\n";
		}
		in>>n;
	}
	cout<<endl;
	cout<<"Invalid Numbers:"<<endl;
	
	in.close();
	in.open("numbers.txt");
	in>>n;
	cout<<n<<" ";
	int c = 0;
	int invalid = 0, valid = count, unlisted = 0;
	while(n != -1){
		if(n == 0){
			unlisted++;
		}
		if((n < 1 || n >= 101) && n != 0){
			cout<<n<<" ";
			c++;	
			invalid++;
	}
		
		in>>n;
		if(c == 4){
			cout<<"\n";
			c = -1;
		}
	}
	cout<<endl;
	
	valid = valid - invalid;
	int sum = 0;
		cout<<"\nRange"<<"\t      Histogram";
		cout<<"\n===========================";
		for(int j = 1; j < 101; j += 10){
		cout <<endl<<j<<"-"<<j+9<<"\t \t";
		for(int k = j-1; k < 10; k++){
			sum=a[k] + sum;
		}
		cout <<sum;
		if(sum == 0){
			cout<<" ";
		}else		
		if(sum > 0){
			cout<<"*";
			sum = sum -5;
		}
		
		else{		
			for(int p = 0; p < sum / 5; p++){
				cout<<"*";
			}
			
		}
		}
		
	cout<<"\n";
	
	cout<<endl;
	cout<<"Valid Favourite Numbers: "<<valid<<"\n";
	cout<<"Invalid Numbers: "<<invalid<<"\n";
	cout<<"Did not give a Number: "<<unlisted;
	
	int popular[101];
	for(int i = 0; i < 101; i++){
		popular[i] = 0;
	}
	for(int i = 0; i < count; i++){
		popular[a[i]]++;
	}
	int highfreqloc, highfreq = -1, lowfreqloc, lowfreq = 1000;
	for(int i = 0; i < valid; i++){
		if(popular[i] > highfreq && popular[i] > 1){
			highfreq = popular[i];
			highfreqloc = i;
		}
		if(popular[i] < lowfreq && popular[i] > 0){
			lowfreq = popular[i];
			lowfreqloc = i;
		}
	}
	cout <<"\nMost Frequent Number: " <<a[highfreqloc]<<"\nFrequency: " <<highfreq <<endl;
	cout <<"\nLeast Frequent Number: " <<a[lowfreqloc]<<"\nFrequency: " <<lowfreq;
}

