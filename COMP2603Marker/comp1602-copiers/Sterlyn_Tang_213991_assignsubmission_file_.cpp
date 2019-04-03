#include <iostream>
#include <fstream>
using namespace std;

void perfect(int num){
	
	int count=1;
	int divisor;
	int sum=0;
	
	while(count<num){
		
		divisor=num%count;
		
		if(divisor==0){
			sum=sum+count;
		}
		count=count+1;
	}
	
	
	if (sum==num){
		cout<<"Y";
	}
	else {
		if(sum!=num)
			cout<<"N";
		}
	}



bool prime (int num){
	
	int count,i=0;
	int remainder;
	
	if(num==1){
		return false;
	}
	else{
	
	for(count=2;count<=(num*1.0)/2;count=count+1){
		
		remainder = num%count;
	
	if(remainder==0){
		return false;
	}
}
}
	return true;
	
 }

void perfectSquare (int num){
	int count,i=0;
	
	for(count=1;count<=(num*1.0)/2;count=count+1){
		if(count*count==num){
			i=i+1;
	}	
	}
	
	if(i>0){
		cout<<"Y";
	}
	else
  		cout<<"N";
	
}

	bool sphenic (int num){
	int count;
	int noTimes=0;
	int product=1;
	int remainder,i=0,counter=0;
	
	for(count=2;count<=(num*1.0)/2;count=count+1){
	
		remainder = num%count;
	
		if(remainder==0 && prime(count)){
			product=product*count;
			noTimes=noTimes+1;
	
}
}
	if(noTimes==3 && product==num)
		return true;
	
	else
		
		return false;
}

	
	void binary(int num){
		int binaryDigit[10000];
		int count=0,counter;
		int p;
		
		
	for(counter=0;counter<8;counter=counter+1){
		binaryDigit[counter]=0;
	}
	
 	while(num>0){
 		binaryDigit[count] = num%2;
 		num = num/2;
 		count=count+1;
	 }
	
	for (p=7;p>=0;p=p-1){
		cout<< binaryDigit[p];
	}
	
		for(counter=0;counter<7;counter=counter+1){
		binaryDigit[counter]=0;
	}
	
}
		
	void histogram(int range[]){
		
	int count;
	int ran=1;
	int numberOfStars;
	int k;
	
		 for (count=1;count<=10;count=count+1){
		 	
		 cout <<ran<< " - " <<ran+9<< "      "<<"| ";
		 numberOfStars=range[count]/5;
	
		 for (k=1;k<=numberOfStars;k=k+1){
    		
    		cout << "*";
    	
		 
    	}
    	ran=ran+10;
    	cout<<endl;
    }
}
		 	
	
	int main (){
		ifstream input;
		int num, noFavourite=0, noInvalid=0;
		int invalidNos[10000];
		int i=0,valid=0;
		int counter=0;
		int count,invalid,p,k,ran=1,b=0;
		int range[10];	
		int mode[1000];
		int least[1000];
		int highest=0,lowest=99999;
		int marker,I=0;
		int a,marker2;
		int skipline=0,endline=0;
		
		for(count=0;count<1000;count=count+1){
			least[count]=0;
		}
		
		
		input.open("numbers.txt");
		if(!input.is_open()){
			cout<<"Error in opening file. Aborting..."<<endl;
			return 0;
		}
		
	
	
	cout<<"Number        Perfect?        Prime?        Perfect Square?       Sphenic?      Binary Equiv. "<<endl;    //8 spaces
	cout<<"======        ========        ======        ===============       ========      ============="<<endl;
	
	input>>num;
	while(num!=-1){
	
    
	if(num>=1 && num<=100){
		valid=valid+1;
		
		mode[I]=num;		//used to store the valid numbers to be used in finding mode
		I=I+1;
		
		least[num]=least[num]+1;        
		
		cout<<num<<"\t""\t";
		perfect(num);
		cout<<"\t""\t";
		prime(num);
		
		if(prime(num)){
		cout<<"Y";
		}
		else 
		{	
		if(!prime(num))
	
		cout<<"N";
		}
		
		cout<<"\t""\t";
		perfectSquare(num);
		cout<<"\t""\t     ";
		sphenic(num);
		
			if(sphenic(num)==true){
		cout<<"Y";
		}
		else
		cout<<"N";
		cout<<"\t""\t";
		
		binary(num);
		cout<<endl;         
		
	
		
	if(num>=1 && num<=10){
		range[1]=range[1]+1;
	}
	
	if(num>=11 && num<=20){
		range[2]=range[2]+1;
	}
	
	if(num>=21 && num<=30){
		range[3]=range[3]+1;
	}
	
	if(num>=31 && num<=40){
		range[4]=range[4] +1;
	}
	if(num>=41 && num<=50){
		range[5]=range[5] +1;
	}
	
	if(num>=51 && num<=60){
		range[6]=range[6] +1;
	}
	
	if(num>=61 && num<=70){
		range[7]=range[7] +1;
	}
	
	if(num>=71 && num<=80){
		range[8]=range[8] +1;
	}
	
	if(num>=81 && num<=90){
		range[9]=range[9] +1;
	}
	
	if(num>=91 && num<=100){
		range[10]=range[10] +1;
	}
	}
	
	if(num==0){
		noFavourite= noFavourite +1;
	}
	
	if( (num<0 )|| (num>100)){
		noInvalid = noInvalid + 1;
		invalidNos[i]=num;
		i=i+1;
	}
	
	input>>num;
}
	cout<<endl;
	cout<<"================================================================================================"<<endl;
	cout<<"Invalid Numbers :- "<<endl;
	
	for(count=0;count<i;count=count+1){
		invalid = invalidNos[count];
		cout << invalid;
		cout<<" ";
		
		counter=counter+1;
		
		if(counter==5){
		cout<<endl;
		counter=0;	
	}

}
	cout<<endl;
	cout<<"================================================================================================"<<endl;
	cout<<endl;
	
	cout<<"Range                Histogram"<<endl;
	cout<<"==============================="<<endl;
	histogram(range);
	
	
	cout<<endl;
	cout<<endl;
	cout<<"=========================================================="<<endl;
	cout<<"                 Summary Statistics"<<endl;
	cout<<"=========================================================="<<endl;
	cout<<"The number of students who specified their favourite numbers : "<<valid<<endl;
	cout<<"The number of invalid numbers specified : "<<noInvalid<<endl;
	cout<<"The number of students who did not specify their favourite number : "<<noFavourite<<endl;
	cout<<endl;
	
	cout <<"The most favourite number/s specified was/were : "<<endl;
	for (count=0;count<valid;count=count+1){
	 marker=1;
	 
	for ( a=count+1;a<valid;a=a+1)
    if (mode[count]==mode[a])
	
	marker=marker+1;
	
	if (marker>highest)
	highest=marker;	
	}

	for (count=0;count<valid;count=count+1){
	 marker=1;

   	for (marker2=count+1;marker2<valid;marker2=marker2+1)
       if (mode[count]==mode[marker2])
           marker=marker+1;

   if (marker==highest){
   
       cout<<mode[count]<<" ";
       
       endline=endline+1;
       
       if(endline==10){
       
	   	cout<<endl;
       
	   	endline=0;
	   }
	}
}
	cout<<endl<<endl;
	cout<<"The least favourite number/s choosen was/were : "<<endl;

for(count=1;count<1000;count=count+1){
	if(least[count]==1){
		cout<<count<<" ";
		
       skipline=skipline+1;
       if(skipline==10){
       	cout<<endl;
       	skipline=0;
	}
}

       
	
	
}

	input.close();
	return 0;

}

	


		
