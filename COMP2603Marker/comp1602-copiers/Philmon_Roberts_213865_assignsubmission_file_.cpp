#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;


bool isPerfect(int);
bool isPrime(int);
bool isPerfectSquare(int);
bool isSphenic(int);
void BinaryEquiv(int);

int main(){
	
	ifstream fin ("numbers.txt");
	if(!fin.is_open()){
		cout << "No File was found.";
		return 0;
	}
	
	int val=0, arr[101]={}, Inval[1000]={}, ran[10]={}, numInval=0, numVal=0;
	int numMostFav=-1, numLeastFav=99999;
	int i=0, j=0;
	
	fin >> val;
	while(val!=-1){
		if(val==0){
			arr[val]++;
		} 
		else if(val>=1 && val<=100){
			arr[val]++;
			numVal++;
		} else {
			// for part c
			Inval[numInval]=val;
			numInval++;
		}
	
		// for part d
		for(j=0;j<10;j++){
			if((val>=(10*j)+1) && (val<=10*(j+1))){
				ran[j]+=1;
				break;
			}
		}
	
		
		
		fin>>val;
	}
	
	fin.close();
	
	cout << "Number\tPerfect?\tPrime?\t\tPerfect Square?\t\tSphenic?\tBinary Equiv."<<endl;
	cout<<"======\t========\t======\t\t===============\t\t========\t============="<<endl<<endl;
	
	for (i=1;i<=100;i++){
		if(arr[i]>0){
			cout << i <<"\t";			
			if(isPerfect(i)){
				cout << "Y\t\t";
			} else {
				cout<<"N\t\t";
			}
			if(isPrime(i)){
				cout << "Y\t\t";
			} else {
				cout << "N\t\t";
			}
			if(isPerfectSquare(i)){
				cout<<"Y\t\t\t";
			}else {
				cout <<"N\t\t\t";
			}
			if(isSphenic(i)){
				cout << "Y\t\t";
			} else {
				cout << "N\t\t";
			}
			BinaryEquiv(i);
			cout <<endl;
		
		}

		
	}
	
	cout << endl<<endl;
	
	cout<< "Invalid Numbers"<<endl;
	cout<<"================="<<endl;
	for(i=0;i<numInval;i++){
		
		cout<<Inval[i];
		if((i+1)%5==0)
			cout<<endl;
		else
			cout<<"\t";
		
	}
	
	cout<<endl<<endl;
	cout<<"Range\t\t\tHistogram"<<endl;
	cout<<"==================================="<<endl;
	for(i=0;i<10;i++){
		cout<<(10*i)+1<<"-"<<10*(i+1)<<"\t\t\t|";
		for(j=0;j<ran[i]/5;j++){
			cout<<"*";
		}
		
		cout<<endl;
	}
	
	cout << endl<<endl;
	
	cout << "Number of students who specified valid favorite numbers: "<< numVal<<endl;
	cout << "Number of student who specified invalid favorite numbers: "<<numInval<<endl;
	cout << "Number of students who did not reveal their favorite number: "<<arr[0]<<endl;
	
	for (i=1;i<=100;i++){
		// using this for loop for a portion of part e
		if(arr[i]>0){
			if(arr[i]>numMostFav){
				numMostFav=arr[i];
			}
		
			if(arr[i]<numLeastFav){
				numLeastFav=arr[i];
			}
			
		}
	
	}
	

	if (numMostFav>=2){
		cout << "The number(s) chosen the most by students , if at least two students chose that number: "; 
		for (i=1;i<=100;i++)
			if(arr[i]==numMostFav)
				cout <<i<< "  ";

	}
	cout << endl;
	

	if(numLeastFav>=1){
			cout << "The number(s) chosen the least by students, if at least one student chose that number: ";
			for(i=1;i<=100;i++)
				if(arr[i]==numLeastFav)
					cout<<i<<"  ";		
		
	}
	
	return 0;
}


bool isPerfect(int x){
	int sum=0;
	for (int i=1;i<=x/2;i++){
		if(x%i==0)
			sum+=i;
		
	}
	if(sum==x)
		return true;
	return false;
}

bool isPrime(int x){
	
	if(x==0||x==1)
		return false;
	
	for(int i=2;i<=x/2;i++){
		if(x%i==0){
			return false;
		}
	}
	
	
	return true;
}

bool isPerfectSquare(int x){
	
	for(int i=0;i<=sqrt(x);i++){
		if (i*i==x)
			return true;
	}
	
	return false;
}

bool isSphenic(int x){
	int count=0, prod=1;
	for(int i=2;i<=x/2;i++){ 
		if(isPrime(i)&&(x%i==0)){
			count++;
			prod*=i;
		}
	}
	if((count==3) && (prod==x) )
		return true;
	return false;
	
}

void BinaryEquiv(int x){
	int bin[8]={};
	
	int i=7;
	while(x!=0){
		bin[i]=x%2;
		x/=2;
		i--;
	}
	
	for (i=0;i<8;i++){
		cout << bin[i];
	}
}
