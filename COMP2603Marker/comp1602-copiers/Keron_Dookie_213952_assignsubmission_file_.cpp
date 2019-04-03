#include <iostream>
#include <fstream>


using namespace std;


int perfect(int numbers) {    

int i=1,sum=0;
    
       while(i< numbers){
       if(numbers%i==0)
       sum=sum+i;
       i++; 
}
if(sum==numbers) 
	cout <<"          Y";
	
else
	cout <<"          N";


	}

	

             
int prime(int numbers) {
	int i, check = 0;
	for (i=2;i<=numbers/2;i = i+1){
		if (numbers%i == 0) {
			check = 1;
			
		}
	}
	
if (check==0) 
	cout <<"             Y";
else
	cout <<"             N";
	
}




int perfectsquare(int numbers) {
	
    int r=1,q=1;
	while(r<numbers)
	{
		q++;
		r=q*q;
	}
if(r==numbers) 
	cout<<"           Y";
else
	cout<<"           N";

}



bool isprime (int numbers) {
	int i;
	int prime1;
	for (i=2;i<=numbers/2;i++) {
		prime1= numbers%i;
		if (prime1 == 0)
		return false;
	}
	return true;
}



int sphenic(int numbers){
	
int i, count, product;
count = 0;
product = 1;



for (i=2; i<=numbers/2; i=i+1) {
	if (numbers%i == 0 && isprime(i) ) {
		product = product * i;
		count = count + 1;
 }
	
}
if (count == 3 && product == numbers)
    cout <<"                    Y";
else
    cout <<"                    N";

}





int binary(int numbers) {
	
	int a[8],  i;    
 
for(i=0; i<8; i++)    
{    
a[i]=numbers%2;    
numbers= numbers/2;  
}    
cout << "                                                                                                                                     ";    for(i=i-1 ;i>=0 ;i--)    
																					{	cout<< a[i] ;    
																						}    

}  




int main () {
	
	ifstream inputFile;
	int bucket[200] = {0};
	int numbers;
	int i;
	int x;
	int y;
	int z;
	int s;
	int b;
	int g;
	int counter1, counter2, counter3, counter4, counter5, counter6, counter7, counter8, counter9, counter10, counter11;
	int count1=0, count2=0, count3=0, count4=0, count5=0, count6=0, count7=0, count8=0, count9=0, count10=0, count11=0;
	int count;
	int validnum, notreveal, mostchosen, leastchosen;
	int validnum1 = 0, notreveal1=0, mostchosen1=0, leastchosen1=0;
	int v=0;
	int arrayv[200];
	
	
	
	inputFile.open("numbers.txt");
	
    if (!inputFile.is_open()) {
     cout << "Error opening input file. Aborting ...";
    return 0;
    }
	 
	inputFile >> numbers;
	
		
		cout << "Number      Perfect?      Prime?      Perfect Square?      Sphenic?      Binary Equiv."<<endl;
	    cout << "======      ========      ======      ===============      ========      ============="<<endl;
		
	while (numbers !=-1 ) {
		
	inputFile >> numbers; 
	
		
		if (numbers >= 1 && numbers <= 100) { 
		validnum = validnum1 ++;
		
		cout << numbers; x = perfect(numbers);  y = prime(numbers); z = perfectsquare(numbers); s = sphenic(numbers); b = binary (numbers);
		
		cout << endl;
		
		if (numbers>= 1 && numbers <= 10){
			counter1 = count1++;
		}
		
		bucket[numbers] = bucket[numbers] +1;
		
		
		
		if (numbers>= 11 && numbers <= 20) {
			counter2 = count2 ++;
		}
		
		if (numbers>= 21 && numbers <= 30) {
			counter3 = count3 ++;
		}
		
		if (numbers>= 31 && numbers <= 40) {
			counter4 = count4 ++;
		}
	
	    if (numbers>= 41 && numbers <= 50) {
			counter5 = count5 ++;
		}
	
	    if (numbers>= 51 && numbers <= 60) {
			counter6 = count6 ++;
		}
		
		if (numbers>= 61 && numbers <= 70) {
			counter7 = count7 ++;
		}
		
		if (numbers>= 71 && numbers <= 80) {
			counter8 = count8 ++;
		}
		
		if (numbers>= 81 && numbers <= 90) {
			counter9 = count9 ++;
		}
		
		if (numbers>= 91 && numbers <= 100) {
			counter10 = count10 ++;
		}
		
		
		
	    
	    
	          }
	          else{


 			if (numbers == 0) {
				notreveal = notreveal1++;
			  }
		  
		  		arrayv[v]= numbers;
		  		if (arrayv[v] !=-1 && arrayv[v] !=0)
				v = v+1;
			
			
	          }
         
	}
cout << endl;
cout << "The list of invalid numbers " << endl;
 for (int i = 0; i <v ; i++){
 	cout << arrayv[i] << " ";
	 if ( i>0&& i%4== 0) {
 		cout << endl;
 	}

}
cout << endl;


 cout << endl;
 int max =0;
 int save;
 for (int i = 0; i<100;i++) {
 	if(max < bucket[i]){
 		max = bucket[i];
 		save = i;
 	}
 
}
 

cout << endl;
 int min =1000;
 int saved;
 for (int i = 1; i<100;i++) {
 	if(min > bucket[i] && bucket[i]>=1){
 		min = bucket[i];
 		saved = i;
 	} 
}






	cout << endl;
	
	cout << "Range          Histogram " <<endl;
	cout << "=========================" <<endl;

	cout<<"1-10           |";               for (count = 5; count <= counter1; count = count + 5) {
                                           cout << "*";
                                             }
	cout<<endl;

	cout<<"11-20          |";               for (count = 5; count <= counter2; count = count + 5) {
                                           cout << "*";
                                             }
                                             
 	cout<<endl;

	cout<<"21-30          |";               for (count = 5; count <= counter3; count = count + 5) {
                                           cout << "*";
                                             }                                            
                                             
 	cout<<endl;

	cout<<"31-40          |";               for (count = 5; count <= counter4; count = count + 5) {
                                           cout << "*";
                                             }  
											 
	cout<<endl;

	cout<<"41-50          |";               for (count = 5; count <= counter5; count = count + 5) {
                                           cout << "*";
                                             }                                          
                                             
    cout<<endl;

	cout<<"51-60          |";               for (count = 5; count <= counter6; count = count + 5) {
                                           cout << "*";
                                             }                                     
	
	cout<<endl;

	cout<<"61-70          |";               for (count = 5; count <= counter7; count = count + 5) {
                                           cout << "*";
                                             }										 
											 
	cout<<endl;

	cout<<"71-80          |";               for (count = 5; count <= counter8; count = count + 5) {
                                           cout << "*";
                                             }		
											 
	cout<<endl;

	cout<<"81-90          |";               for (count = 5; count <= counter9; count = count + 5) {
                                           cout << "*";
                                             }								 
											 
	cout<<endl;

	cout<<"91-100         |";               for (count = 5; count <= counter10; count = count + 5) {
                                           cout << "*";
                                             }									 
									
   	cout <<endl; 
											 
										 								   
	
	cout << endl;
	cout << endl;
	cout << "STATISTICS" <<endl;
	cout <<"===========" <<endl;
	cout << "The amount of students who specified valid favourite numbers are:  " << validnum1 <<endl;
	cout << "The amount of students who specified invalid favourite numbers are: " << v <<endl;
	cout << "The amount of students who did not reveal their favourite number are: " << notreveal1 <<endl; 
	
	cout << "The number/s that was/were chosen the most by the students is/are: " << save << " ";  
	for (int i = 1; i<100;i++) {
	if(bucket[i]==max && i !=save){
	cout << i << ", max ";
		}
		}
cout << endl;	
	
	
	
	  
	cout << "The number/s that was/were chosen the least by the students is/are: " << saved; 
	for (int i = 1; i<100;i++) {
    if(bucket[i]==min && i !=saved) {
	cout <<", " << i;
}
}

	
	inputFile.close();
	

	return 0;
}
