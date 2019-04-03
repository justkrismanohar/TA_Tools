#include <iostream>
#include <fstream>
using namespace std;


//(b)(i) 
bool isPerfect(int num){
	int i, sum=0; 
	
	for(i=1; i<=num; i++){
		if (num%i==0)
			sum = sum+i;
		else 
			sum = sum; 
	}
	
	if (sum == num)
		return true;
	else 
		return false; 	
}

//(b)(ii)
bool isPrime(int num){
	int i;
	
	for(i=2; i<=num/2; i++){
		if(num%i==0)
     		return false;
		else
	    	return true;
	}
}

//(b)(iii)
bool perfectSquare(int num){
	int sq,i;
	
	for(i=1; i<=num/2; i++){
		sq=i*i;
		
		if(sq==num)
			return true;
		}
	 
	 	return false;
}

//(b)(iv)
bool isSphenic(int num){
	int i,count=0,prod=1;
	
	for(i=2; i<=num/2; i++){
		if(num%i==0 && isPrime(i)){
		   	prod=prod*i;
		   	count=count+1;
		}
	}
	   
	if(count==3 && prod==num)
	    return true;
	else
	    return false;
}



//(b)(v)   
int convert(int num){
	int rem;
	
	while(num!=0){
		rem=num%2;
		num=num/2;
	}
}

//(a)
int main(){
	int num, nofave=0, numbers[100], invalid[100], j=0, validcount=0, invalidcount=0, i=0;
	
	ifstream in;
	in.open("numbers.txt");
	
	if(!in.is_open()){
	    cout<"Error opening file.";
	    return 0;
	}
	
	in>>num;   // reads the numbers, sorts them into 2 arrays, invalid and valid numbers and counts the number of both types of numbers	
	while(num!=-1){   //have to check if a number is valid or invalid
		if (num==0)
			nofave=nofave + 1;
		else if (num<-1){
			invalidcount = invalidcount + 1;
			invalid[j] = num; 
			j = j + 1;
		}

		else{
			numbers[i]=num;
			validcount=validcount+1;
			i = i+1;
	  	}	
		in>>num; 
	}

	//display the table 
	cout<<"Number"<<"\t"<<"Perfect?"<<"   "<<"Prime?"<<"   "<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equiv."<<endl;
	cout<<"======"<<"\t"<<"========"<<"   "<<"======"<<"   "<<"==============="<<"\t"<<"========"<<"\t"<<"=============="<<endl;
      
	   for(i=0; i<validcount; i++){
           cout<<" "<<numbers[i];

			if (isPerfect(numbers[i]))
				cout<<"\t   Y  \t";
			else 
				cout<<"\t   N  \t";

			if (isPrime(numbers[i]))
				cout<<"     Y  \t";
			else 
				cout<<"     N  \t";

			if (perfectSquare(numbers[i]))
				cout<<"   Y    ";
			else 
				cout<<"   N    ";

			if (isSphenic(numbers[i]))
				cout<<"\t   Y  \t";
			else 
				cout<<"\t   N  \t";
	        
			
		//	if (convert(numbers[i]))
		    
			
			cout<<endl;
			
		} //ends for loop 
		
	cout<<endl;
	

	//(c)
	for (int k=0; k<invalidcount; k = k+5){
		cout<<" INVALID NUMBERS: ";
		cout << invalid[k] << "\t" << invalid[k+1] << "\t" << invalid[k+2] << "\t" << invalid[k+3] << "\t" << invalid[k+4] << endl;
	}	


	//(d)
	int range=0, range1=0, range2=0, range3=0, range4=0, range5=0, range6=0, range7=0, range8=0, range9=0;
	
		cout<<endl;
		cout<<endl;
		cout<<"Range             Histogram"<<endl;
		cout<<"=============================="<<endl;

	//count for the number of valid numbers in each range
	for (int k =0; k<validcount; k++){
		if (numbers[k]>= 1 && numbers[k]<=10)
			range++;
			
		else if (numbers[k]>= 11 && numbers[k]<=20)
			range1++;
			
		else if (numbers[k]>= 21 && numbers[k]<=30)
			range2++;
			
		else if (numbers[k]>= 31 && numbers[k]<=40)
			range3++;
			
		else if (numbers[k]>= 41 && numbers[k]<=50)
			range4++;
			
		else if (numbers[k]>= 51 && numbers[k]<=60)
			range5++;
			
		else if (numbers[k]>= 61 && numbers[k]<=70)
			range6++;
			
		else if (numbers[k]>= 71 && numbers[k]<=80)
			range7++;
			
		else if (numbers[k]>= 81 && numbers[k]<=90)
			range8++;
			
		else if (numbers[k]>= 91 && numbers[k]<=100)
			range9++;
	}
	
	// how much stars in each range and display

	cout<<"1-10\t |";
	
	int star = range/5;
	
		for (int j=0; j<star; j++){
		    cout<<"*";
		}
		cout<<endl;
	
	
	cout<<"11-20\t |";
	   
	int star1 = (range1)/5;
	
		for (int j=0; j<star1; j++){
		    cout<<"*";
		}
		cout<<endl;
	
	
	cout<<"21-30\t |";
	     
	int star2 = (range2)/5;
		 
		for (int j=0; j<star2; j++){
		    cout<<"*";
		}
		cout<<endl;
	
	
	cout<<"31-40\t |";
	
	int star3 = (range3)/5;
	
		for (int j=0; j<star3; j++){
		    cout<<"*";
		}
		cout<<endl;
	
	
	cout<<"41-50\t |";
	
	int star4 = (range4)/5;
	 
		for (int j=0; j<star; j++){
		    cout<<"*";
		}
		cout<<endl;
		
	
	cout<<"51-60\t |";
	     
	int star5 = (range5)/5;
		 
		for (int j=0; j<star; j++){
		    cout<<"*";
		}
		cout<<endl;
	
	
	cout<<"61-70\t |";
	
	int star6 = (range6)/5;
	
		for (int j=0; j<star; j++){
		    cout<<"*";
		}
		cout<<endl;
	
	
	cout<<"71-80\t |";
	
	int star7 = (range7)/5;
	
		for (int j=0; j<star; j++){
		    cout<<"*";
		}
		cout<<endl;
	
	
	cout<<"81-90\t |";
	
	int star8 = (range8)/5;
	
		for (int j=0; j<star; j++){
		    cout<<"*";
		}
		cout<<endl;
	
	
	cout<<"91-100\t |";
	
	int star9 = (range9)/5;
	     
		for (int j=0; j<star; j++){
			cout<<"*";
		}
		cout<<endl;
	
	//(e)(i)
    cout<<endl;
	cout<<"Amount of students with valid favourite numbers: "<<validcount<<endl;
	cout<<"Amount of students with invalid favourite numbers: "<<invalidcount<<endl;
	cout<<"Amount of students who did not reveal their favourite numbers: "<<nofave<<endl;



	//(ii) for each number search the array and check how much times it appears
	int count = 0;
	 	for (int i=0; i<100; i++){
			for(int j=0; j<100; j++){
		
				if (numbers[j]==i)
					count++;
				}
	    		
			//	if (count>=2)
	   		    //	cout<<i<<" appears "<<count<<" times"<<endl; 
	   	}
	
	//(iii)
	int count1 = 0;
		for (int i=0; i<100; i++){
			for(int j=0; j<100; j++){
	
				if (numbers[j]==i)
					count1++;
				}
	    
			//	if (count1>=1)
		        	//cout<<i<<" appears "<<count1<<" times"<<endl; 
		}
	
	in.close();
	return 0;
}
	
	

