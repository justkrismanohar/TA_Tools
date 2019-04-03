//Chelsea Sankeralli
//816000177

//i)
bool isPerfect (int num){
	int sum=1;
	for (int i=2;i<=num/2;i++){
		if(num%i==0)
		sum=sum+i;
	}
	if (sum==num && num!=1)
	return true;
	else
	return false;
}

//ii)
bool isPrime (int num){
	int count=1;
	for (int i=2;i<=num;i++){
		if(num%i==0)
		count=count+1;
	}
	if (count>2)
	return false;
	else
	return true;
}

//iii)
bool isPerfectSquare (int num){
	int square;
	for (int i=1;i<=num;i++){
		square=i*i;
	if (square==num)
	return true;
}
	return false;
}

//iv)
bool isSphenic (int num) {

int i,j,arr[num+1],ans ;
arr[0]=0 ;
arr[1]=1 ;
ans=0 ;
for(i=0;i<=num;i++)
arr[i]=1 ;
for(i=2;i<=num;i++){
for(j=i+1;j<=num;j++)
if(j%i==0)
arr[j]=0 ;
}
}

//v)


void convertToBinary(int num){
	int remainder,remainderArray[8];
	int i=0;
	while(num>0){
		remainderArray[i]=num%2;
		num=num/2;
		i++;
}
}




#include <iostream>
#include <fstream>
using namespace std;

bool isPerfect( int num);
bool isPrime( int num);
bool isPerfectSquare( int num);
bool isSphenic( int num);
void convertToBinary( int num);

int main (){
	int num,n,invalids[100],countInvalids=0,countZero=0,countValids=0,numbers[200],k,ans4;
	ifstream input;
	input.open("numbers.txt");
	
	if(!input.is_open()){
		cout<<"Error opening file";
		return 0;	
	}
	cout<<"Number"<<"\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equiv."<<endl;
	cout<<"================================================================================================="<<endl;
	input>>num;
	while(num!=-1){
		 numbers[k]=num;
		int totalNumbers=k;

		if(numbers[k]>=1 && numbers[k]<=100){
			countValids=countValids+1;
		//
			bool ans1= isPerfect(numbers[k]);
			if(ans1==true)
			cout<<"Y";
			else
			if (ans1==false)
			cout<<"N";
		//
			bool ans2= isPrime(numbers[k]);
			if(ans2==true)
			cout<<"Y";
			else
			if (ans2==false)
			cout<<"N";
		//
			bool ans3= isPerfectSquare(numbers[k]);
			if(ans3==true)
			cout<<"Y";
			else
			if (ans3==false)
			cout<<"N";
	
		//
		bool ans4=isSphenic(numbers[k]);
		if(ans4==true)
			cout<<"Y";
			else
			if (ans4==false)
			cout<<"N";
			
		//
		convertToBinary(numbers[k]);
		
			cout<<num<<"	\t"<<ans1<<"	\t"<<ans2<<"	\t"<<ans3<<"	\t"<<ans4<<endl;
			
			}
		
			if(num>=1&&num<=10){
				
			}
			
		else
		if((numbers[k]<0) || (numbers[k]>100)){
			countInvalids=countInvalids+1;
			for (int i=0;i<n;i++){
				invalids[i]=num;
				cout<<invalids[i];
				if(i+1%5==0)
				cout<<endl;
			}
		}
		else
		if(numbers[k]==0){
			countZero=countZero+1;
		}
		k++;
		input>>num;	
}
		
	
cout<<endl;
	cout<<"Range"<<"\t"<<"Histogram"<<endl;
	cout<<"========================"<<endl;
	cout<<countValids<<"-No. of Valid numbers"<<endl;
	cout<<countInvalids<<"-No. of invalid numbers"<<endl;
	cout<<countZero<<"-No. of Zeroes"<<endl;
}
	
