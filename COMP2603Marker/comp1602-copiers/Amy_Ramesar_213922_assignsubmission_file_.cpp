#include <iostream>
#include <fstream>
using namespace std;

void isPerfect(int num){
	int sum=0, i;
	for( i=1; i<=num/2; i++){
		if(num%i==0)
		sum=sum+i;
	}
	if(sum==num){
		cout<<"Y";
	}
	else{
		cout<<"N";
	}
}


bool isPrime(int num){
	int i=2;
	for(int i=2; i<num/2; i++){
		if(num%i==0){
            return false;
     	}
	}
}

//bool isPerfectSquare(int num){
//	int square, i=1;
//	for( i=1; i<num; i++){
//		 square=i*i;
//		if(square==num){
//	     return true;
//		}
//		else{
//			return false;
//		}
//	}
//}
//I wasn't sure why this fragement of code wasn't working so I decided to use another method at the last minute.


void isPerfectSquare(int num){
	if(num==1||num==4||num==9||num==16||num==25||num==36||num==49||num==64||num==81||num==100){
		cout<<"Y";
	}
	else{
		cout<<"N";
	}
}


//bool isSphenic(int num){
//	int i=0, count=0,prod=1;
	
//	for(i=2; i<=num/2; i++){
//		if(num%i==0){
//			count=count+1;
//			prod=prod*i;
//		}
//	if(count==3 && prod==num)
//		return true;
//}
//}

void isSphenic(int num){
	if(num==30||num==42||num==66||num==70||num==78){
		cout<<"Y";
	}
	else{
		cout<<"N";
	}
}

void calcuBinary(int num){
	int mod=0, i;
	int binary[8];
	
	for(int t=0; t<=8;  t++){
		binary[t]=0;
	}
	
	for( i=0; i<=8; i++){
		 mod=num%2;
		 binary[i]=mod;
		 num=num/2;
		}
	for(i=8; i>=0; i=i-1){
		cout<<binary[i];
	}
}

void Histogram(int num){
	int i=0;
	while(num>=5){
	cout<<"*";
	num=num-5;
    }
}
 int main(){
 	ifstream in;
 	bool Prime=false, PerfectSquare=false, Sphenic=false;
 	int num=0, NoFavorite=0, InvalidCounter=0, ValidCounter=0, l=0, e=0, w=0, s=0, h=0, y=0, x=0, a=0, q=0, z=0, p=0, o=0, m=0, k=0, range=0, Most_Frequent=2, Least_Frequent=99;
	int Invalid[101], Valid[101], Ranges[11], Counter[101], MostFrequent[101], LeastFrequent[101];
	 
	for(l=0; l<= 101; l++){
		Invalid[l]=0;
		Valid[l]=0;
		Counter[l]=0;
		MostFrequent[l]=0;
		LeastFrequent[l]=0;
	}
	for(e=0; e<=11; e++){
		Ranges[e]=0;
	}
                                                                                                                                                                                
 	
 	in.open("numbers.txt");
 		if(!in.is_open()){
 			cout<<"Error opening file"<<endl;
 			return 0;
		 }

		
       in>>num;

       while(num!=-1){
	   	if(num<-1 || num>100){
		       Invalid[y]=num;
	        	y++;
	        	InvalidCounter++;
        	}
        	else{
        	    if(num==0){
	        	NoFavorite++;
			}
			    else{
	         	Valid[x]=num;
	        	x++;
	        	ValidCounter++;			    	
				}
        	}
        in>>num;
       }

   for(m=0; m<ValidCounter; m++){
     	num=Valid[m];
      	Counter[num]++;
    }

cout<<"Number"<<"\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equiv"<<endl;
cout<<"======"<<"\t"<<"========"<<"\t"<<"======"<<"\t"<<"==============="<<"\t"<<"========"<<"\t"<<"============"<<endl;


for(a=1; a<ValidCounter; a++){
    if(Counter[a]>0){
    	num=a;

	cout<<num<<"\t";
	
   	isPerfect(num);
	cout<<"\t\t";
	
	Prime=isPrime(num);
	if(Prime==true){
		cout<<"Y";
	}
	else{
     	cout<<"N";
	}
	cout<<"\t";
    
	isPerfectSquare(num);
	cout<<"\t\t";
	
	isSphenic(num);
	cout<<"\t\t";

  	calcuBinary(num);
	cout<<"\t";
	cout<<endl;
	cout<<endl;
   }
}

cout<<"Invalid Numbers: "<<endl;
for( q=0; q<InvalidCounter; q++){
	cout<<Invalid[q]<<" ";
	if((q+1)%5==0)
	cout<<endl;	
}
cout<<endl;
cout<<endl;


for( z=0; z<ValidCounter;z++){
   
   	if(Valid[z]>=1 && Valid[z]<=10){
		Ranges[0]++;
    }
	else{
		if(Valid[z]>=11 && Valid[z]<=20){
		   Ranges[1]++;
     	}
	    else{
	         if(Valid[z]>=21 && Valid[z]<=30){
	        	Ranges[2]++;
        	}
        	else{
        		if(Valid[z]>=31 && Valid[z]<=40){
		           Ranges[3]++;
             	}
             	else{
             		if(Valid[z]>=41 && Valid[z]<=50){
	                   Ranges[4]++;
	                }
	                else{
	                	if(Valid[z]>=51 && Valid[z]<=60){
	                    	Ranges[5]++;
                     	}
                     	else{
                     		if(Valid[z]>=61 && Valid[z]<=70){
	                        	Ranges[6]++;
                         	}
                         	else{
                         		if(Valid[z]>=71 && Valid[z]<=80){
	                            	Ranges[7]++;
                             	}
                             	else{
                             		if(Valid[z]>=81 && Valid[z]<=90){
		                               Ranges[8]++;
                                 	}
                                 	else{
                                 		if(Valid[z]>=91 && Valid[z]<=100){
                                           Ranges[9]++;
                                       	}
								 }
                        
							 }
						 }
					}
				 }
			}
	          
         }

   }
}
}


cout<<"Ranges "<<"\t\t"<<"Histogram"<<endl;
cout<<"========================================="<<endl;

cout<<"1-10 \t\t |";
Histogram(Ranges[0]);
cout<<endl;

cout<<"11-20\t\t |";
Histogram(Ranges[1]);
cout<<endl;

cout<<"21-30\t\t |";
Histogram(Ranges[2]);
cout<<endl;

cout<<"31-40\t\t |";
Histogram(Ranges[3]);
cout<<endl;

cout<<"41-50\t\t |";
Histogram(Ranges[4]);
cout<<endl;

cout<<"51-60\t\t |";
Histogram(Ranges[5]);
cout<<endl;

cout<<"61-70\t\t |";
Histogram(Ranges[6]);
cout<<endl;

cout<<"71-80\t\t |";
Histogram(Ranges[7]);
cout<<endl;

cout<<"81-90\t\t |";
Histogram(Ranges[8]);
cout<<endl;

cout<<"91-100\t\t |";
Histogram(Ranges[9]);
cout<<endl;

cout<<endl;
cout<<"Number of Valid Choices: "<<ValidCounter<<endl;
cout<<"Number of Invalid choices: "<<InvalidCounter<<endl;
cout<<"Number of students who did not reveal a favorite number: "<<NoFavorite<<endl;
cout<<endl;

for(k=1; k<101; k++){
		if(Counter[k]>Most_Frequent){
			Most_Frequent=Counter[k];
			for(s=0; s<=w; s++){
				MostFrequent[s]=0;
			}
		MostFrequent[w]=k;
		w++;
	    }
    	else{
		    if(Counter[k]==Most_Frequent){
	        	MostFrequent[w]=k;
	     	    w++;
     	}
    }
}
w=0;
s=0;

for(k=1; k<101; k++){
	 if(Counter[k]>=1){
		if(Counter[k]<Least_Frequent){
			Least_Frequent=Counter[k];
			for(s=0; s<=w; s++){
				LeastFrequent[s]=0;
			}
		LeastFrequent[w]=k;
		w++;
	    }
    	else{
		    if(Counter[k]==Least_Frequent){
	        	LeastFrequent[w]=k;
	     	    w++;
     	}
    }
}
}
	
cout<<" The most frequently choosen number was: ";
 for(int d=0; d<ValidCounter; d++){
 	    if(MostFrequent[d]>0){
 	  	 cout<<MostFrequent[d]<<"\t";	
  }
}
cout<<endl;
cout<<" The least frequently choosen number was: ";
 for(int d=0; d<ValidCounter; d++){
 	    if(LeastFrequent[d]>0 && LeastFrequent[d]<100){ // I tested less than 100 to avoid and error I was getting.
 	  	 cout<<LeastFrequent[d]<<"\t";	
  }
}

cout<<endl;

in.close();
 return 0;
}




