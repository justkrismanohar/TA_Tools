#include <iostream>
#include <fstream>
 using namespace std;
  bool isPerfect(int num){
  	int b=1;
  	int sum=0;
  	 while(b<num){
  	 	if(num%b==0){
        sum=sum+b;
       b=b+1; 
	   }
	   else { b=b+1;}}
   if(sum==num){return true; }
   else{ return false;}
}

bool isPrime(int num) {
	int c=0;
	for(int i=1; i<=num; i++){
		if (num % i == 0){
           c=c+1;
        }
    }
    if (c == 2){
       return true;}
    else
    return false;  
}

bool PtSq(int num){
	int i,pt;
int sq=0;
	for( i=1; i<=num; i=i+1){ 
	pt=i*i; 
	if(pt==num) {sq=sq+1;} } 

		if (sq==1){ return true;}
		
		else return false;
	
}

bool isSphenic(int n){
	int i, count=0,product=1;
	bool ans=true;
	for(i=2; i<=n/2; i++){
		if(n%i==0 && isPrime(i)==true){
			product=product*i;
			count=count+1;
		}}
		if(count==3 && product==n){
			return true;}
			else
			return false;
		
	}

void isbinary(int num){

int binarr[7];
          	int v=0,p=0,binar,w=0;
          	      w=num;
	                while (v<7){
		                binar=w%2;
		                binarr[v]=binar;
	                 	w=w/2;
	                 	v=v+1;
	                  	}
	while(v>=0){
		     cout<<binarr[v];
			 v=v-1;
			 
}}


 
 int main(){
 	int x=0,nums[200];
 	int num=0, Perf,Pri,PfSqt,Val=0,Sphe,Binar,y=1,noVal=0,inVal[10],UnRa=0,j=0,k=0,l=0,m=0,n=0,o=0,b=0,z=0,q=0,r=0;
 	bool ansPer,ansPri,ansPfSq,ansSphe;
 	ifstream in,into;
 	
 	cout<<"Number  Perfect   Prime   Perfect Square    Sphenic   Binary Equiv."<<endl;
 	cout<<"======  =======   =====   ==============    =======   ============="<<endl;
 	in.open("numbers.txt");
 	in>>num;
 	while(num != -1){
 		if (num<0 || num>100){ inVal[y]=num;
			 y=y+1; noVal=noVal+1;}
	    if(num==0){UnRa=UnRa+1;}
 		if(num>=1 && num<=100){ 
 		    Val=Val+1;
 			nums[x] =num;
 			cout<<nums[x]<<"        ";
 			ansPer=isPerfect(num);
 			if(ansPer == true){cout<<"Y         ";}
 			else{cout<<"N         ";}
			 
			 ansPri =isPrime(num);
 			if(ansPri == true){cout<<"Y         ";}
 			else{cout<<"N         ";}
			 
			 ansPfSq = PtSq(num);
 			if(ansPfSq == true){cout<<"Y                ";}
 			else{cout<<"N                ";}
			 
			 bool ansSphe = isSphenic(num);
 			if (ansSphe == true){cout<<"Y          ";}
 			else {cout<<"N         ";} 
			 
			 isbinary(num);
			 
		     cout<<endl;
		     if(num>=1 && num<=10){j=j+1;} 
			            if(num>=11 && num<=20){k=k+1;}
			            if(num>=21 && num<=30){l=l+1;}
			            if(num>=31 && num<=40){m=m+1;}
			            if(num>=41 && num<=50){n=n+1;}
			            if(num>=51 && num<=60){o=o+1;}
			            if(num>=61 && num<=70){b=b+1;}
			            if(num>=71 && num<=80){z=z+1;}
			            if(num>=81 && num<=90){r=r+1;}
			            if(num>=91 && num<=100){q=q+1;}
			            
	
			 
			 cout<<endl;

			 }
			 
			      
			
			 x=x+1;
			 in>>num;
			 }
			 
			 cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
			 cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
			 cout<<"The invalid numbers are: "; 
			 for(y=9;y>0;y=y-1){ cout<<inVal[y]<<"  ";
			 
			 	if(y%5==0){cout<<endl;}}cout<<endl;
		     cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
		     cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
			 
			 
				 
			 	  
				 cout<<endl<<endl;
	
			cout<<"  Range            Histogram "<<endl;
			cout<<" ============================"<<endl;
			
			 cout<<"  1-10             :";
			               if(j>=5 && j<10){cout<<"*";}
			               if(j>=10 && j<15){cout<<"**";}
						   if(j>=15 && j<20){cout<<"***";}
						   if(j>=20 && j<25){cout<<"****";}
						   if(j>=25 && j<30){cout<<"*****";}
						   
				cout<<endl;	
				
			 cout<<"  11-20            :";	   
			               if( k>=5 && k<10){cout<<"*";}
			               if( k>=10 && k<15){cout<<"**";}
						   if( k>=15 && k<20){cout<<"***";}
						   if( k>=20 && k<25){cout<<"****";}
						   if( k>=25 && k<30){cout<<"*****";}
						cout<<endl;
						
			 cout<<"  21-30            :";
						    if( l>=5 && l<10){cout<<"*";}
			               if( l>=10 && l<15){cout<<"**";}
						   if( l>=15 && l<20){cout<<"***";}
						   if( l>=20 && l<25){cout<<"****";}
						   if( l>=25 && l<30){cout<<"*****";}
						cout<<endl;
						
			  cout<<"  31-40            :";
						    if( m>=5 && m<10){cout<<"*";}
			               if( m>=10 && m<15){cout<<"**";}
						   if( m>=15 && m<20){cout<<"***";}
						   if( m>=20 && m<25){cout<<"****";}
						   if( m>=25 && m<30){cout<<"*****";}
						cout<<endl;
						
			  cout<<"  41-50            :";
						   
						    if( n>=5 && n<10){cout<<"*";}
			               if( n>=10 && n<15){cout<<"**";}
						   if( n>=15 && n<20){cout<<"***";}
						   if( n>=20 && n<25){cout<<"****";}
						   if(n>=25 && n<30){cout<<"*****";}
						cout<<endl;
						
			  cout<<"  51-60            :";	
						   
						    if( o>=5 && o<10){cout<<"*";}
			               if( o>=10 && o<15){cout<<"**";}
						   if( o>=15 && o<20){cout<<"***";}
						   if( o>=20 && o<25){cout<<"****";}
						   if(o>=25 && o<30){cout<<"*****";}
						cout<<endl;
						
			  cout<<"  61-70            :";
						   
						    if( b>=5 && b<10){cout<<"*";}
			               if( b>=10 && b<15){cout<<"**";}
						   if( b>=15 && b<20){cout<<"***";}
						   if( b>=20 && b<25){cout<<"****";}
						   if(b>=25 && b<30){cout<<"*****";}
						cout<<endl;
						
			cout<<"  71-80            :";
				   
						    if( z>=5 && z<10){cout<<"*";}
			               if( z>=10 && z<15){cout<<"**";}
						   if( z>=15 && z<20){cout<<"***";}
						   if( z>=20 && z<25){cout<<"****";}
						   if(z>=25 && z<30){cout<<"*****";}
						   cout<<endl;
						   
			cout<<"  81-90            :";
						   
						    if( r>=5 && r<10){cout<<"*";}
			               if( r>=10 && r<15){cout<<"**";}
						   if( r>=15 && r<20){cout<<"***";}
						   if( r>=20 && r<25){cout<<"****";}
						   if(r>=25 && r<30){cout<<"*****";}
						cout<<endl;
						
			 cout<<"  91-100           :"; 
						    if( q>=5 && q<10){cout<<"*";}
			               if( q>=10 && q<15){cout<<"**";}
						   if( q>=15 && q<20){cout<<"***";}
						   if( q>=20 && q<25){cout<<"****";}
						   if(q>=25 && q<30){cout<<"*****";}
						 cout<<endl;
						 
			cout<<endl<<"The Number of Valid student favourites : "<<Val<<endl;
			cout<<"The Number of inValid student favourites : "<<noVal<<endl;
			cout<<"The Number of student favourites that is unrevealed : "<<UnRa<<endl<<endl;
			
	
			cout<<"The number that was chosen the most : "<<endl;
			cout<<"The number that was chosen the least : "<<endl;
			
			 	
			 
            in.close();
			 }
			 
			 
	 
 
