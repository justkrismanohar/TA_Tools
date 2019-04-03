//Maariyah Maleehah Baksh
//816006907
#include <iostream>
#include <cmath>
 #include <fstream>
using namespace std;

void isPerfect (int n){
  	int i=1; int sum=0;
  	
  	while(i<n){
  		if(n%i==0)
  		sum=sum+i;
  		i=i+1;
	  }
	if(sum==n){
		cout<<"Y\t";
	}
	else{
		cout<<"N\t";
	}
  	  
}

bool isPrime (int m ){
 	int i; 							
 	for (i=3; i<=m/2; i=i+1){
 		if(m==2){
 			return true;
		 }
		 
		 if(m==1 || m%2==0){
		 	return false;
		 }
 		if (m%i==0){
 			return false;	
		 }
	 }
	 return true;
} 

void isSphenic (int k){
	int count=0; int prod=1; int prime;
	
	for(int i=1; i<k/2;i=i+1){
	prime=isPrime(k);
	if(prime && k%i==0){
		prod=prod*i;
		count=count+1;
	}
	
	if(prod==k && count==3){
		cout<<"Y\t";
	}
	else{
		if(prod!=k && count==3){
			count=2;
		}
		}
	}
	 cout<<"N\t";
}

void isPerfectSquare (int l){
  	int i=1; int r=1;
  	while(r<l){
  		i = i +1 ;
  		r = i*i;
  	  }
  	  if (r==l){
  	  	cout<<"Y\t";
  	  
  	  
		}
	else {
		cout<<"N\t";
		
		
	 }
}
	  
void binary (int q){
	int binNum[8];
	int i=0; int r; int j=0;
	for(i=0; i<8;i=i+1){
		binNum[i]=0;
	}
    
    while (q!=0){
    	binNum[7-j]=q%2;
    	q=q/2;
    	j=j+1;
	}
	
	for(i=1;i<8;i=i+1){
		cout<<binNum[i];
	}
}

void stars(int q){
	int num=q/5;
	for(int i=1; i<=num; i=i+1)
	{
		cout <<"*";
	}
}

int main(){
	
	int fav[999]; int i=0; int invalid=0;  int valid= 0; int zero=0; int f; int ranges[10]; int inval [99]; int l=0; int highest=0; 
	int marker=0; int marker2=0; int count=0; int a=0; int max=0; int min=9999 ; int j; int A[101];
	ifstream in; 
	
	in.open("numbers.txt");
	if(!in.is_open()){
		cout<<"File is not found."<<endl;
		return 0;
	}
	
	
	for (i =1; i < 101; i++){
		A[i] = 0;
	}
	
cout<<"Number"<<"\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equivalent"<<endl; 
 in>>f;
 
 //while loop starts
 while (!(f==-1)){
 	    
 	   
    if(f>0&& f<=100){ 
    
    A[f]++;
    
	for( count=0;count<valid; count=count+1){
	marker=1;
	
	for( a=count+1;a<valid;a=a+1)
	if(fav[count]==fav[a])
	
	marker=marker+1;
	
	if(marker>highest)
	highest=marker;
}
	for(count=0;count<valid;count=count+1){
	marker=1;
	
	for( marker2=count+1;marker2<valid;marker2=marker2+1)
	if(fav[count]==fav[marker2])
	 marker=marker+1;
	 
	 if(marker==highest){
      marker=fav[count];

}

}

	    
    	cout<<f<<"\t\t";
	  isPerfect(f); 
		if (isPrime(f)==true)   
			cout << "Y\t\t";
		else
			cout<<"N\t\t";
      isPerfectSquare(f);
    	isSphenic(f);

	    binary(f);
	    
       cout<<endl;
    
       
		fav[i]=f;
		valid = valid +1; 
		}
		
	   if(f<0 || f>100){
		inval[l]=f ;   	
	    l=l+1;
   	}
   	
	      
	   	if(f==0){
			zero=zero+1;
		}
	
	
    	    
	in>>f;
	i=i+1;
  }
  //while loop ends
  
  cout<<endl;
  
  //invalid numbers
  cout<<"Invalid numbers:"<<endl;
  for(int k=0; k<=l-4;k=k+5){
  	cout<<inval[k]<<" "<<inval[k+1]<<" "<<inval[k+2]<<" "<<inval[k+3]<<" "<<inval[k+4]<<endl;
  	cout<<" "<<endl;
  	
  }

  ranges[0]=ranges[1]=ranges[2]=ranges[3]=ranges[4]=ranges[5]=ranges[6]=ranges[7]=ranges[8]=ranges[9]=0;
for(int p=0; p<i; p=p+1){
	if(fav[p]>=1 && fav[p]<=10)
		ranges[0]=ranges[0]+1;
	else if(fav[p]>=11 && fav[p]<=20)
		ranges[1]=ranges[1]+1;
	else if(fav[p]>=21 && fav[p]<=30)
		ranges[2]=ranges[2]+1;		
	else if(fav[p]>=31 && fav[p]<=40)
		ranges[3]=ranges[3]+1;	
	else if(fav[p]>=41 && fav[p]<=50)
		ranges[4]=ranges[4]+1;
	else if(fav[p]>=51 && fav[p]<=60)
		ranges[5]=ranges[5]+1;
	else if(fav[p]>=61 && fav[p]<=70)
		ranges[6]=ranges[6]+1;
	else if(fav[p]>=71 && fav[p]<=80)
		ranges[7]=ranges[7]+1;
	else if(fav[p]>=81 && fav[p]<=90)
		ranges[8]=ranges[8]+1;
	else if(fav[p]>=91 && fav[p]<=100)
		ranges[9]=ranges[9]+1;
}


//histogram 
  cout<<"Range                 Histogram"<<endl;
cout<<"--------------------------------------"<<endl;
cout<<"--------------------------------------"<<endl;
cout<<"1-10                       "; stars(ranges[0]); cout<<endl;  
cout<<"11-20                      "; stars(ranges[1]); cout<<endl;
cout<<"21-30                      "; stars(ranges[2]); cout<<endl;
cout<<"31-40                      "; stars(ranges[3]); cout<<endl;
cout<<"41-50                      "; stars(ranges[4]); cout<<endl;
cout<<"51-60                      "; stars(ranges[5]); cout<<endl;
cout<<"61-70                      "; stars(ranges[6]); cout<<endl;
cout<<"71-80                      "; stars(ranges[7]); cout<<endl;
cout<<"81-90                      "; stars(ranges[8]); cout<<endl;
cout<<"91-100                     "; stars(ranges[9]); cout<<endl;

cout<<endl;

  cout<<endl;
  cout<<"The amount of valid nubers are:"<<valid<<endl;
  cout<<"The amount of invalid numbers are:"<<l<<endl;
  cout<<"The amount of students who didnt particiate are:"<<zero<<endl;
  
  
  int mostStudents = 0;
  
  for(i = 1; i <101; i++){
  	if(mostStudents < A[i]){
  		mostStudents = A[i];
	  }
  }
  
  int leastStudents = 10000;
  for(i = 1; i <101; i++){
  	if(A[i] != 0 && leastStudents > A[i]){
  		leastStudents = A[i];
	  }
  }
  
  
  cout <<"The number/s that was/were chosen the most by the students: ";
  for(int i = 1; i < 101; i++){
  	if(mostStudents > 1 && A[i] == mostStudents){
  		cout << i << " ";
	  }
  }
  
  cout <<endl;
  
  
  cout << "The number/s that was/were chosen the least by the students: ";
  for(int i = 1; i < 101; i++){
  	if(leastStudents > 0 && A[i] == leastStudents){
  		cout << i << " ";
	  }
  }
  cout <<endl;
  in.close();
   return 0;
}
