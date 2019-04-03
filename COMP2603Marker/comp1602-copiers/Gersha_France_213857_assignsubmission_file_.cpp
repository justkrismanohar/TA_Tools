#include <iostream>
#include <fstream>
using namespace std;

int  perfectNumber(int n){
	int i,  a=0;

		for(i=1;i<=n/2;i++){
			if (n%i==0)
	
			a=i+a;
		}
		if(n==a)
		cout<<"y             \t";
		
		cout<<"n           \t"; 	
}

bool  isPrime(int n) {
   int i;
       for(i=2; i<=n/2; i++) {
      if(n%i==0) 
	  return false;
	  else
	  return true;
	  
  
}
}

bool perfectSquare(int a) {

int i, sq;
	
	if (a>0&&a<100){
	
  for(i=1;i<a/2;i=i+1)
  
	sq=i*i;
	
	if (sq==a)
	
	return true;
	
	else
	 
	return false;

}
}

bool isSphenic(int n){
	
	int i, count=0, product=1;
	
	if (n>0&&n<=100){
	
	for (i=2; i<=n/2; i=i+1){
		
	
	   if (n%i==0&&isPrime(i))
	  product=product*i;
	  count=count+1;


if ((count==3)&&(product==n))
return true;
else
return false;
}
}
} 

void toBinary(int n){
	int num1 ,num2;
	if (n==0)
	return  ;
	else{
		num1=n%2;
		num2=n/2;
		n=num2;
		toBinary(n);
		cout<<num1;

}	
	
}
void isInvalid(int n){
	  if(n<0||n>100){
		cout<<n<<endl;
}	
	
}





int main (){

	ifstream in;
	int invalid[200];

  	in.open("numbers.txt");

	if(!in.is_open()){
		cout<<"File not found"<<endl;
	return 0;
	}
	int num ,total=0, count=0,count1=0, count2=0, count3=0, count4=0,count5=0, count6=0, count7=0, count8=0,count9=0 ;
	int  i=0,j=0,k=0;
	int countv=0, counti=0, countn=0;
	
	
	
	cout<<"Number   Perfect?   Prime?   Perfect Square?    Shenic?     Binary Eqiv."<<endl;
	cout<<"============================================================================"<<endl;
	in>>num;
	while (num!=-1){
				in>>num; 
				
				
				for(k=0;k<200;k++)
                	invalid[k]=num;
				
				
				
				if(num>=1&&num<=10){
					count=count+1;
					
				}
				
					if(num>=11&&num<=20){
					count1=count1+1;
					
				}
				
					if(num>=21&&num<=30){
					count2=count2+1;
					
				}
				
					if(num>=31&&num<=40){
					count3=count3+1;
					
				}
				
					if(num>=41&&num<=50){
					count4=count4+1;
					
				}
				
					if(num>=51&&num<=60){
					count5=count5+1;
					
				}
				
					if(num>=61&&num<=70){
					count6=count6+1;
					
				}
				
					if(num>=71&&num<=80){
					count7=count7+1;
					
				}
					if(num>=81&&num<=90){
					count8=count8+1;
					
				}
					if(num>=91&&num<=100){
					count9=count9+1;
					
				}
				
			countv=count+count1+count2+count3+count4+count5+count6+count7+count8+count9;	
				
			 if	(num>0&&num<=100){
			 cout<<num;
			 countv=countv+1;
			 cout<<"\t";
			perfectNumber(num);
		
			if (isPrime(num))
			
			cout<<"y             "<<"\t";
			else
			cout<<"n           "<<"\t";
			
			if (perfectSquare(num))
			cout<<"y     "<<"\t";
			else
			cout<<"n     "<<"\t";
			
			if (isSphenic(num))
			cout<<"y   "<<"\t";
			else
			cout<<"n    "<<"\t";
			
			 toBinary(num);
			 cout<<endl;
			 
			 	
		}
		
		 if(num==0){
		
	            	countn=countn+1;
                	}
                	
	        if(num<0||num>100){
		
			counti=counti+1;
	          	}	
	          
	          	  
	          	  
	          	  
	          	
      }
      	




	






cout<<"Range \t      Histogram"<<endl;
cout<<"==========================="<<endl;
cout<<"1 - 10  \t :"	;
total = count/5;
for(int i=0; i<=total; i++)
	cout<<"*";
cout<<endl;

cout<<"11 - 20 \t :"	;
total = count1/5;
for(int i=0; i<=total; i++)
	cout<<"*";
cout<<endl;

cout<<"21 - 30 \t :"	;
total = count2/5;
for(int i=0; i<=total; i++)
	cout<<"*";
cout<<endl;

cout<<"31 - 40 \t :"	;
total = count3/5;
for(int i=0; i<=total; i++)
	cout<<"*";
cout<<endl;

cout<<"41 - 50 \t :"	;
total = count4/5;
for(int i=0; i<=total; i++)
	cout<<"*";
cout<<endl;

cout<<"51 - 60 \t :"	;
total = count5/5;
for(int i=0; i<=total; i++)
	cout<<"*";
cout<<endl;

cout<<"61 - 70 \t :"	;
total = count6/5;
for(int i=0; i<=total; i++)
	cout<<"*";
cout<<endl;
	
	cout<<"71 - 80 \t :"	;
total = count7/5;
for(int i=0; i<=total; i++)
	cout<<"*";
cout<<endl;

cout<<"81 - 90 \t :"	;
total = count8/5;
for(int i=0; i<=total; i++)
	cout<<"*";
cout<<endl;

cout<<"91 - 100 \t :"	;
total = count9/5;
for(int i=0; i<=total; i++)
	cout<<"*";
cout<<endl;

cout<<"valid numbers"<<endl;
cout<<countv<<endl;

cout<<"invalid numbers "<<endl;
cout<<counti<<endl;

cout<<"no numbers "<<endl;
cout<<countn<<endl;
return 0;
}

