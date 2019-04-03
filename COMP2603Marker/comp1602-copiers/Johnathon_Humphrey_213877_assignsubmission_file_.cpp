#include <iostream>
#include <fstream>
using namespace std;

bool isPerfect(int n){
	int j, sum=0;
	for(j=1; j<n; j++){
		if(n % j == 0){
			sum = j + sum;
		}
		if (sum == n){
			return true;
		}
		
	}
	if (sum!=n){
		return false;
	}
	
}

bool isPrime(int n){
	int count=0, j;
	for(j=1; j<n; j++){
		if(n%j==0){
			count++;
		}	
	}
	if(count>1){
		return false;
	}else{
		return true;
	}	
}

bool Perfsqr(int n){
	int j, sqr; 
	for(j=1; j<n; j++){
		sqr = j*j;
		if(sqr == n){
		return true;
		}
	}
	if(sqr != n){
		return false;
	}	
}

bool isSphenic(int n){
	int j, count=0, prod=1, inv=0;
	for(j=2; j<n/2; j++){
		if((n % j == 0) && isPrime(j)){
			prod=prod*j;
			count++;
		}
		if(count==3) break;			
	}
		if((count==3) && (prod==n)){
			return true;
		}else{
			return false;	
		}		
}

int Binary(int n){
	int i=0,r;
	int binum[8]={0};
	while(n > 0){
		r= n % 2;
		n = n / 2;
		binum[i]=r;
		i++;
	}
	for (int j=7;j>=0;j--){
		cout<<binum[j];
	}
}


int main(){
	ifstream in;
	in.open("numbers.txt");
	int n, i=0, x, j, valid=0, invalid=0, nofav=0, arr[1000], inv[100];
	int b, temp, tempcount=0, count=0, frequent, lfrequent;
	
	if(!in.is_open()){
		cout << "Error opening file.";
		return 0;
	}
	
	cout <<"Number"<<"		"<<"Perfect?"<<"		"<<"Prime?"<<"		"<<"Perfect Square?"<<"		"<<"Sphenic?"<<"		"<<"Binary Equiv."<<endl;
	cout<<"======"<<"		"<<"========"<<"		"<<"======"<<"		"<<"==============="<<"		"<<"========"<<"		"<<"============="<<endl; 

	in >> n;	
	while (n!= -1){

		arr[i] = n;
		in >> n;
		i++;
			
			cout<< n <<"		"; 
			
			if(isPerfect(n)){
				cout<<"Y";
			}else{
				cout<<"N";
			} 
			
			cout <<"			";
			
			if(isPrime(n)){
				cout<<"Y";
			}else{
				cout<<"N";
			}
			
			cout <<"		";
			
				if(Perfsqr(n)){
				cout<<"Y";
			}else{
				cout<<"N";
			}
			
			cout <<"			";
			
			if(isSphenic(n)){
				cout<<"Y";
			}else{
				cout<<"N";
			}
			
			cout <<"			";
			
			b=Binary(n);
			cout<<endl;
		
				if(n>=1 && n<=10){
					arr[0]=n;
				}else
				if(n>=11 && n<=20){
					arr[1]=n;
				}
				if(n>=21 && n<=30){
					arr[2]=n;
				}
				if(n>=31 && n<=40){
					arr[3]=n;
				}
					if(n>=41 && n<=50){
					arr[4]=n;
				}
				if(n>=51 && n<=60){
					arr[5]=n;
				}
				if(n>=61 && n<=70){
					arr[6]=n;
				}
				if(n>=71 && n<=80){
					arr[7]=n;
				}
				if(n>=81 && n<=90){
					arr[8]=n;
				}
				if(n>=91 && n<=100){
					arr[9]=n;
				}
				
				if(n>=1 && n<=100){
					valid++;
				}
				if(n<1 || n>100){
					invalid++;
				}
				if(n==0){
					nofav++;
				}
				for(int l=0; l<i; l++){
					temp=arr[l];
					for(int m=0; m<i; m++){
						if(arr[m] == temp){
							tempcount++;
						}
						if(tempcount>count){
							frequent = temp;
							
						}
					}
				}
				for(int l=0; l<i; l++){
					temp=arr[l];
					for(int m=0; m<i; m++){
						if(arr[m] == temp){
							tempcount++;
						}
						if(tempcount>count){
							lfrequent = temp;
							
						}
					}
				}
				
	}
	
	cout<<endl;		
	cout<<"Invalid Numbers: ";
	cout<<endl;
	invalid = 0;
	for(int k=0;k<i;k++){
		n=arr[k];
		if(n<0 || n>100){
			invalid++;
			cout<<n<<" ";
			
			if(invalid%5==0){
				cout<<endl;
			}
		}
	}
	
	
		
	
	
	cout<<endl;
	cout<<endl;
	cout <<"Range"<<"		"<<"Histogram"<<endl;
	cout<<"========================="<<endl;
	
	
	cout<<"1-10"<<"		"<<"|";for(int i=0; i<=arr[0]/5;i++)cout<<"*";
	cout<<endl;
	
	cout<<"11-20"<<"		"<<"|";for(int i=1; i<=arr[1]/5;i++)cout<<"*";
	cout<<endl;
	
	cout<<"21-30"<<"		"<<"|";for(int i=3; i<=arr[2]/5;i++)cout<<"*";
	cout<<endl;
	
	cout<<"31-40"<<"		"<<"|";for(int i=6; i<=arr[3]/5;i++)cout<<"*";
	cout<<endl;
	
	cout<<"41-50"<<"		"<<"|";for(int i=8; i<=arr[4]/5;i++)cout<<"*";
	cout<<endl;
	
	cout<<"51-60"<<"		"<<"|";for(int i=11; i<=arr[5]/5;i++)cout<<"*";
	cout<<endl;
	
	cout<<"61-70"<<"		"<<"|";for(int i=11; i<=arr[6]/5;i++)cout<<"*";
	cout<<endl;
	
	cout<<"71-80"<<"		"<<"|";for(int i=14; i<=arr[7]/5;i++)cout<<"*";
	cout<<endl;
	
	cout<<"81-90"<<"		"<<"|";for(int i=17; i<=arr[8]/5;i++)cout<<"*";
	cout<<endl;
	
	cout<<"91-100"<<"		"<<"|";for(int i=18; i<=arr[9]/5;i++)cout<<"*";
	cout<<endl;
	
	cout<<endl;
	cout<<"The number of students who specified their favourite valid number: "<< valid <<endl;
	
	cout<<"The number of students who specified their favourite invalid number: "<< invalid <<endl;
	
	cout<<"The number of students who did not reveal their favourite number: "<< nofav <<endl;
	
	cout <<"The number/s that was chosen the most by students: "<< frequent <<" "<<endl;
	
	cout <<"The number/s that was chosen least by students: "<< lfrequent <<" "<<endl;
	
	
	
}

	
	

		
		

