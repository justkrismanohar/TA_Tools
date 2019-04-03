//NAME: Jenelle Kallicharan		ID: 816117683

#include <iostream>
#include <fstream>
using namespace std;

bool isPerfect(int numbers );
bool isPrime(int numbers);
bool isPerfectSquare(int numbers);
bool isSphenic (int numbers);
void isBinary(int numbers);



int main (){
 ifstream inputFile;
 int num, k=0,count=0,count1=0,count2=0,count3=0,binary,totalNumbers,minRange=1,maxRange=10;
 int topCount=0, c, topElement,lowCount=100,lowElement,b;
 bool perfect,prime,perfectSquare,sphenic;
 int numbers[140];
 inputFile.open("numbers.txt");

 if (!inputFile.is_open()) {
 cout << "Error opening input file. Aborting ...";
}
cout<<"Number		Perfect		Prime		Perfect Square		Sphenic		Binary Equivalent"<<endl;
 inputFile >> num;

 while (num != -1) { 
 	numbers[k]=num;
	totalNumbers=k;
 	if(numbers[k]>=1 && numbers[k]<=100){
	 
 	perfect = isPerfect (numbers [k]);
 	if (perfect== true){
 		cout<<num<< "		Y"<<endl;
	 }
	 else if (perfect==false){
	 	cout<<num<<"		N"<<endl;	 
 }
 
 
 	prime=isPrime(numbers[k]);
 	
 	if(prime==true){
 		cout<<"				"<<" Y"<<endl;
	 }
	 else {
	 	cout<<"				"<<" N"<<endl;
	 }
	 
	 perfectSquare=isPerfectSquare(numbers[k]);
	 	if(perfectSquare==true){
	 	cout<<"						"<<" Y"<<endl;
	 }
	 else {
	 	cout<<"						"<<" N"<<endl;	
	 }
	
	sphenic=isSphenic(numbers[k]);
	if (sphenic==true){
		cout<<"									"<<" Y"<<endl;
	}
	
	else {
		cout<<"									"<<" N"<<endl;
	}
	
		
	isBinary(numbers[k]);
	
		count=count+1;
}


else if ((numbers[k]>100)||(numbers[k]<0)){
	 count1=count1+1;
	
}


else if (numbers[k]==0){
	count2=count2+1;
}


 	k=k+1;
	 	inputFile>>num;
}

cout<<endl<<endl;
 
 int i=1;
for(k=0;k<totalNumbers;k=k+1){
	if ((numbers[k]>=101)||(numbers[k]<=-1)){
	
	if(i==6){
		cout<<endl;
		cout<<numbers[k]<<"\t";
		i=1;
	}
	else {
		cout<<numbers[k]<<"\t";
		
	}

i=i+1;
	
}
}
cout<<endl<<endl;
cout<<"The amount of students who specified valid favourite numbers: "<<count<<endl;
cout<<"The amount of students who specified invalid favourite numbers "<<count1<<endl;
cout<<"Total amount of students who did not reveal their favourite number: "<<count2<<endl;


cout<<endl<<endl;
cout<<"Range  \t\tHistogram"<<endl;
cout<<"=========================="<<endl;


cout<<endl;

for(i=1;i<=10;i=i+1){
	cout<<minRange<<" to "<<maxRange<<"		";
for(k=0;k<totalNumbers;k=k+1){
	if((numbers[k]>=minRange)&&(numbers[k]<=maxRange)){
	int count=count+1;
	if(count==5){
		
		cout<<"*";
		count=0;
	}
	
	}		
}
minRange=minRange+10;
maxRange=maxRange+10;
cout<<endl;
}




for ( int i=0 ; i<140 ;i=i+1)
{
    c=0;
    for (int j=0 ; j<10 ; j=j+1)
    {
        if (numbers[i]==numbers[j]) 
		c=c+1;
    }
    if (c>topCount)
    {
        topCount=c;
        topElement=numbers[i];
    }
}
cout<<endl;
cout<<"The number that was chosen the most by the students: "<<topElement<<endl;



for ( int i=0 ; i<140 ;i=i+1){
    b=0;
    for (int j=0 ; j<10 ; j=j+1)
    {
        if (numbers[i]==numbers[j]) 
		c=c+1;
    }
    if (c>lowCount)
    {
        lowCount=b;
        lowElement=numbers[i];
    }

}
cout<<endl;
cout<<"The number that was chosen the least by the students "<<lowElement<<endl;

inputFile.close(); 
 return 0;

}

bool isPerfect(int numbers){
 int num,i=1,sum=0;
 	if (numbers>=1){
	 
       while(i<numbers){
       if(numbers%i==0)
       sum=sum+i;
       i++; 
}
} 
	else return false;

  if(sum==numbers){
  
        return true;
    }
  else {
        return false;
    }
}

bool isPrime(int numbers){
	int i;
  bool prime = true;

  for(i = 2; i <= numbers / 2; i=i+1)
  {
      if(numbers % i == 0)
      {
          prime = false;
      }
  }
  if (prime)
      return true;
  else
      return false;

}

bool isPerfectSquare(int numbers){
	
	 int sqr=1;
    int counter=1;
    for(int i=1; i<=numbers; i=i+1)
    {
        sqr = i*i;
		 if(sqr==numbers)
            return true;
     }
           return false;
}

bool isSphenic (int numbers){

    int i,j,arr[numbers+1],ans ;
    arr[0]=0 ;
    arr[1]=1 ;
    ans=0 ;
   
    for(i=0;i<=numbers;i=i+1)
        arr[i]=1 ;
       
    for(i=2;i<=numbers;i=i+1)
    {
        for(j=i+1;j<=numbers;j=j+1)
            if(j%i==0)
                arr[j]=0 ;
    }  
   
    for(i=2;i<=numbers;i=i+1)
    {
        if(arr[i]==1)
        {
            if(numbers%arr[i]==0)
            {
                numbers=numbers/i ;
                ans++ ;
            }
        }
        if(numbers==1)
            break ;
    }
   
    if(ans==3)
        return true ;
    return false ;
}


void isBinary (int numbers){

int arrayDigits[8] = {128, 64, 32, 16, 8, 4, 2, 1};

int arrayCheck[8];

        for(int i=0; i<8; i=i+1)

        {

            if(numbers >= arrayDigits[i]) 
            {
                arrayCheck[i] = 1;
                numbers = numbers - arrayDigits[i];
            } else {
                arrayCheck[i] = 0;
            }

        }

     cout<<"												"<<arrayCheck[0] << arrayCheck[1] << arrayCheck[2] << arrayCheck[3] << arrayCheck[4] << arrayCheck[5] << arrayCheck[6] << arrayCheck[7] << "\n" << endl;

}

 

 

	

 
