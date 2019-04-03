#include <iostream>
#include <fstream>
using namespace std;

//Functions

//finding perfect numbers
void isPerfect (int num){
	
	int x=1;
	int sum=0;
	int quotient=0;
	bool isperfect;
	string answer;
	
	for (x=1;x<num;x++){
			
	quotient=num %x;
			
	if (quotient==0){
	sum= sum+x;
	}
				
	}
	
	if (sum==num){
		isperfect=true;
		answer="Y";
	}
	
	else if (sum!=num){
		isperfect=false;
		answer="N";
	}  
	
cout<<answer;
	
}

//finding prime numbers
void isPrime (int num){
	
	int x;
	int sum=0;
	int factors=0;
	bool isprime;
	string answer;
	
	for (x=1;x<=num;x++){
		if(num %x==0){
		factors=factors+1;
		}
		
	}

	if (num %1==0 && num %num==0 && factors==2){
		isprime=true;
		answer="Y";
	}
	
	else{
		isprime=false;
		answer="N";
	}
	
	cout<<answer;
}

//finding perfect squares
void perfectSquare (int num){
	
	int x=1;
	int sum=0;
	bool perfectsquare=false;
	string answer;
	
	
	for (x=1;x<num;x++){
		if ((x*x)==num){
		perfectsquare=true;
		answer="Y";
		}
	}
	
	if (perfectsquare==false){
		answer="N";
	}
	
	cout<<answer;
}

//finding sphenic numbers
void isSphenic (int num){
	
	int x=1;
	int b=0;
	int c=0;
	int j=0;
	int sum=1;
	int numberoffactors=0;
	int factors[9999];
	int primefactors [9999];
	bool sphenic=false;
	string answer;
	
	
	//finding the all the factors of num
	for (x=1;x<=num;x++){
		if(num %x==0){
		factors[c]=x;
		c=c+1;
		}
	}
	
	//identfying factors of num that are prime numbers

	for (x=0;x<=c;x++){
		
		for (j=1;j<=factors[x];j++){
			if (factors[x] % j==0){
			numberoffactors=numberoffactors+1;
			}	
			
		}	
	
		if (numberoffactors==2 && factors[x] %factors[x]==0 && factors[x] %1==0){
			primefactors[b]=factors[x];
			b=b+1;	
			}
			
			//resetting numberoffactors variable
			numberoffactors=0;
			
			}
			
		
	 for (j=0;j<b;j++){
	 	
	 sum=primefactors[j] *sum;
	
		if (j==2 && sum==num){
			
		if (sum==num){
			sphenic=true;
			answer="Y";	
			}
		}	
	}
	
	if (sphenic==false){
		answer="N";
	}
	
	
cout<<answer; 
	
}

//finding binary equivalent
void binary (int num, int digit[]){
	
	int i;
	int b;
	int x=0;
	int bits=0;
	int originalnum;
	int remainingbits;
	
	originalnum=num;
	
	while (num > 0){
	digit[x]=num%2;
	num=num/2;
	bits=bits+1;
    }
    
    remainingbits=8-bits;
    
    if ((bits!=8 && originalnum %2!=0) || (bits!=8 && originalnum <=70) ){
        
    	while(bits<8){
    		cout<<"0";
    		bits=bits+1;
		}
    
 	while (originalnum > 0){
		
	digit[x]= originalnum % 2;
    originalnum=originalnum/2;
   
    if (originalnum>0){
    x=x+1;
    bits=bits+1;
	}
    }
    
    for (i=x; i>=0;i--){
    cout<<digit[i];
	}
	
}

else if ((bits!=8 && originalnum %2==0) || (originalnum %2 !=0 && originalnum>70)){
	while (originalnum > 0){
		
	digit[x]= originalnum % 2;
    originalnum=originalnum/2;
   
    if (originalnum>0){
    x=x+1;
    bits=bits+1;
	}
    }
    
    for (i=x; i>=0;i--){
    cout<<digit[i];
	}


	for (b=0; b<remainingbits; b++){
    cout<<"0";
    bits=bits+1;
	}
}

		
}


int main(){
	
//fstreams
ifstream inputFile;
	
int validnumbers=0;
int invalidnumbers=0;
int secretnumbers=0;
int students=0;
int key;
bool exist;
int j=0;
int w=0;
int x=0;
int h=0;
int k=0;
int p=0;
int c=0;
int b=0;
int v=0;
int i;
int y;
int z;


//arrays
int validfavnumber[9999];
int invalidfavnumber[9999];
int favnum[9999];
int pastnumber[9999];
int digit[9999];
int existArr[9999];

//categories for histogram
int one_ten=0;
int eleven_twenty=0;
int twentyone_thirty=0;
int thirtyone_forty=0;
int fortyone_fifty=0;
int fiftyone_sixty=0;
int sixtyone_seventy=0;
int seventyone_eighty=0;
int eightyone_ninety=0;
int ninetyone_hundred=0;

//most and least popular numbers
int frequency=0;
int mostpopularnumber[9999];
int leastpopularnumber[9999];



//opening file
inputFile.open("numbers.txt");

	if (inputFile.is_open()==false){
		cout<<"Error opening file. Aborting..."<<endl;
		return 0;
	}
	
//headings for table
cout<<"Number"<<"\t"<<"Perfect?"<<"   "<<"Prime?"<<"   "<<"Perfect Square?"<<"\t"<<"Sphenic"<<"\t    "<<"Binary Equiv."<<endl;
cout<<"======"<<"\t"<<"========"<<"   "<<"======"<<"   "<<"==============="<<"     "<<"========"<<"    "<<"============="<<endl;
	


//reading file content
inputFile>>favnum[j];


while (favnum[j] != -1){

if (students>0){	
inputFile>>favnum[j];
}

if (favnum[j] != -1){

//finding number of students who gave valid numbers
	if (favnum[j] >= 1 && favnum[j] <= 100){
	validnumbers= validnumbers +1;
	validfavnumber[x]= favnum[j];
	x= x+1;
}

//finding number of students who gave invalid numbers (not including those with secret numbers)
	if (favnum[j]!=0 && favnum[j]<1 || favnum[j]>100){
	invalidnumbers= invalidnumbers+1;
	invalidfavnumber[w]= favnum[j];
	w= w+1;
	} 
	
//finding number of students who kept their favourite number a secret
	if (favnum[j] == 0){
	secretnumbers= secretnumbers+1;
	}
	
	
//displaying valid numbers
if (favnum[j]>=1 && favnum[j]<=100){
cout<<favnum[j]<<"\t ";
	
     //finding perfect numbers
	 isPerfect (favnum[j]);
	 cout<<"\t   ";
	 
	 //finding prime numbers
	 isPrime (favnum[j]);
	 cout<<"\t    ";
	 
	 //finding perfect squares
	 perfectSquare (favnum[j]);
	 cout<<"\t\t\t";
	 
	 //finding sphenic numbers
	 isSphenic (favnum[j]);
	 cout<<"\t    ";
	 
	 //finding the binary equivalent (8 bits)
	 binary (favnum[j], digit);
	 cout<<"\n\n";
	 	
	}

students=students+1;
j=j+1;
}

}	


//displaying all invalid numbers, five per line

cout<<"\n\n";
cout<<"Invalid numbers: "<<endl;
	for (y=0; y<w;y++){
		if (y%5==0){
		cout<<"\n";	
		}
		
	cout<<invalidfavnumber[y]<<" ";
}



//formatting histogram
cout<<"\n\n\n";
cout<<"Range"<<"\t    "<<"Histogram"<<endl;
cout<<"=========================="<<endl;
cout<<"\n";


//calculations for histrogram
for (i=0;i<=x;i++){

//1-10
if (validfavnumber[i]>=1 && validfavnumber[i]<=10){
	one_ten= one_ten +1;
}
//11-20
else if (validfavnumber[i]>=11 && validfavnumber[i]<=20){  
	eleven_twenty= eleven_twenty +1; 
}
//21-30
else if (validfavnumber[i]>=21 && validfavnumber[i]<=30){
	twentyone_thirty= twentyone_thirty +1;
}
//31-40
else if (validfavnumber[i]>=31 && validfavnumber[i]<=40){
	thirtyone_forty= thirtyone_forty +1; 
}
//41-50
else if (validfavnumber[i]>=41 && validfavnumber[i]<=50){
	fortyone_fifty= fortyone_fifty +1; 
}
//51-60
else if (validfavnumber[i]>=51 && validfavnumber[i]<=60){
	fiftyone_sixty= fiftyone_sixty +1; 
}
//61-70
else if (validfavnumber[i]>=61 && validfavnumber[i]<=70){
	sixtyone_seventy= sixtyone_seventy +1;  
} 
//71-80
else if (validfavnumber[i]>=71 && validfavnumber[i]<=80){
	seventyone_eighty= seventyone_eighty +1;  
}
//81-90
else if (validfavnumber[i]>=81 && validfavnumber[i]<=90){
	eightyone_ninety= eightyone_ninety +1; 
}
//91-100
else if (validfavnumber[i]>=91 && validfavnumber[i]<=100){
	ninetyone_hundred= ninetyone_hundred +1;
}

}


//inputting data into histogram

cout<<" 1-10"<<"\t    ";
for (y=0; y<=one_ten;y++){
		if (y!=0 && y%5==0){
		cout<<"*";	
	}	
}

cout<<"\n";

cout<<"11-20"<<"\t    ";
for (y=0; y<=eleven_twenty;y++){
		if (y!=0 && y%5==0){
		cout<<"*";	
	}	
}

cout<<"\n";

cout<<"21-30"<<"\t    ";
for (y=0; y<=twentyone_thirty;y++){
		if (y!=0 && y%5==0){
		cout<<"*";	
	}	
}

cout<<"\n";

cout<<"31-40"<<"\t    ";
for (y=0; y<=thirtyone_forty;y++){
		if (y!=0 && y%5==0){
		cout<<"*";	
	}	
}

cout<<"\n";

cout<<"41-50"<<"\t    ";
for (y=0; y<=fortyone_fifty;y++){
		if (y!=0 && y%5==0){
		cout<<"*";	
	}	
}

cout<<"\n";

cout<<"51-60"<<"\t    ";
for (y=0; y<=fiftyone_sixty;y++){
		if (y!=0 && y%5==0){
		cout<<"*";	
	}	
}

cout<<"\n";

cout<<"61-70"<<"\t    ";
for (y=0; y<=sixtyone_seventy;y++){
		if (y!=0 && y%5==0){
		cout<<"*";	
	}	
}

cout<<"\n";

cout<<"71-80"<<"\t    ";
for (y=0; y<=seventyone_eighty;y++){
		if (y!=0 && y%5==0){
		cout<<"*";	
	}	
}

cout<<"\n";

cout<<"81-90"<<"\t    ";
for (y=0; y<=eightyone_ninety;y++){
		if (y!=0 && y%5==0){
		cout<<"*";	
	}	
}

cout<<"\n";

cout<<"91-100"<<"\t    ";
for (y=0; y<=ninetyone_hundred;y++){
		if (y!=0 && y%5==0){
		cout<<"*";	
	}	
}

cout<<"\n\n\n";


//displaying the number of students and students with valid, invalid and secret numbers
cout<<"Total number of students: "<<students<<endl;
cout<<"Number of students with valid favourite numbers: "<<validnumbers<<endl;
cout<<"Number of students with invalid favourite numbers: "<<invalidnumbers<<endl;
cout<<"Number of students who kept their favourite number a secret: "<<secretnumbers<<endl;



//finding the most and least popular numbers (using both valid and invalid numbers)
for (y=0;y<=students;y++){
	
	if (favnum[y]!=-1){
	
	//resetting the frequency variable after each loop	
	frequency=0;
		
	for (z=0;z<=students;z++){
		
		if (favnum[y]==favnum[z]){
			frequency=frequency+1;
		}
		
	}
	
	key=-1;
	
		if (frequency>=2){
		mostpopularnumber[k]=favnum[y];
		key=mostpopularnumber[k];
		k=k+1;
		}
		
		exist=true;
		
			for (i=k-2; i> -1; i--) {
				if (key!= -1 && key== mostpopularnumber[i]) {
					exist= false;
				}
			}

			if (exist== true && key!= -1){
				existArr[v]= key;
				v=v + 1;  
			} 
	
		if (frequency==1){
		leastpopularnumber[h]=favnum[y];
		h=h+1;
		}
	
	}

}


cout<<"\n\n";
cout<<"Most popular numbers: ";
	for (y=0; y<v;y++){
	cout<<existArr[y] << " ";
	}

cout<<"\n\n\n";
cout<<"Least popular numbers: ";
	for (y=0; y<=h;y++){
	cout<<leastpopularnumber[y]<<" ";
}

cout<<"\n";

	
//closing the file	
inputFile.close();



return 0;	
}

