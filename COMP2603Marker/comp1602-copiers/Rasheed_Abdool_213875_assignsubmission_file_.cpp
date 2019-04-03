# include<iostream>
# include<fstream>
using namespace std;

int table(int array[],int p);

void readOutNumbers()
{	
	int a;
	int i=1;
	int sampleSize = 0;
	ifstream inputnumbers;
	inputnumbers.open("numbers.txt");	
	inputnumbers>> a;
	cout<<"This is a read out of the numbers in the numbers.txt file.\n "<<endl;	
	while (a!=-1){
	cout<<a<<"\t";
	inputnumbers>>a ;
	i++;
			
	}
	
	inputnumbers.close();
	
	cout<<"\n\n"<<endl;
	
}



int validNumbers(){
	
	int a;
	int validFavNum = 0;
	ifstream inputnumbers;
	inputnumbers.open("numbers.txt");
	inputnumbers>>a;
	while(!inputnumbers.eof()){
		if((a>0)&&(a<101)){
			validFavNum = validFavNum + 1;
		}
		inputnumbers>>a;
	}
	inputnumbers.close();
	
	return validFavNum ;
}



int invalidNumbers(int b ){
	
	int a;
	int invalidFavNum = 0;
	ifstream inputnumbers;
	inputnumbers.open("numbers.txt");
	if(b==1)	cout<<"These are the invalid numbers :-"<<endl;
	inputnumbers>>a;
	while(a!=-1){
		if((a<0)||(a>100)){
			invalidFavNum = invalidFavNum + 1;
		if(b==1)	cout<<a<<" \t ";
			if((invalidFavNum%5==0)&&(b==1)) cout<<endl;
		}
		inputnumbers>>a;
	}
	inputnumbers.close();
	if(b==1) cout<<"\n\n"<<endl;
	return invalidFavNum ;
}
 
 
 
 int favNumNotReveal(){
	
	int a;
	int notReveal = 0;
	ifstream inputnumbers;
	inputnumbers.open("numbers.txt");
	inputnumbers>>a;
	while(a!=-1){
		if(a==0){
			notReveal = notReveal + 1;
		}
		inputnumbers>>a;
	}
	inputnumbers.close();
	
	return notReveal ;
}
  
  
 
void mostChosenNum(){
 	 
	
	int a;
	int arraySize = 0;
	

	int array[200];
	ifstream inputfile;
	inputfile.open("numbers.txt");
	inputfile>>a;
	while(a!=-1){
	inputfile>>a;
	if((a>0)&&(a<101)){
	array[arraySize]=a;
	arraySize++;
	}
	 
	}
	
	inputfile.close();
	
	int n=arraySize;
	  	 	 
	int count =0;
	cout<<endl;
	cout<<"These are the numbers that was chosen the most\n "<<endl;
	for(int i=1;i<101;i++){
		count =0;
		for(int j=0;j<n;j++){
			
			if(i == array[j])
			count =count + 1;
								
		}
		if(count>=2) 
		cout<<"The number "<<i<<"\twas chosen "<<count<<" times."<<endl;
		
	}
	cout<<endl;
	}
 	
 


void leastChosenNum (){
			
			int a;
			int arraySize = 0;
			
		
			int array[200];
			ifstream inputfile;
			inputfile.open("numbers.txt");
			inputfile>>a;
			while(a!=-1){
			inputfile>>a;
			if((a>0)&&(a<101)){
			array[arraySize]=a;
			arraySize++;
			}
			 
			}
			
			inputfile.close();
	
			int n=arraySize;
			int count ;
			cout<<"These are the numbers that was chosen the least\n "<<endl;	
			for(int i=1;i<101;i++){
			count =0;
			for(int j=0;j<n;j++){
			
			if(array[i]== array[j])
			count =count + 1;
								
		}
		if(count<2) 
		cout<<"The number "<<i<<"\t was chosen "<<count<<" times."<<endl;
		
	}	
	
	}




char perfectNumber(int n){
	
	
	int sum=0;
	for(int i=1;i<n/2;i++){
		if(n%i==0){
			sum=sum+ i;
		}
	}if(sum==n){
		return 'Y';
	}
	else{
		return 'N';
	}
	
	
}



char isPrime(int n){
	int i;
	for(i=2;i<n/2;i++){
	if(n%i==0)
	return 'N';
	}
	return 'Y';
	
}



char isPerfectSquare(int n){
	 
	 int Sq;
	 for(int i=1;i<n/2;i++){
	 	Sq =i * i;
	 	if(Sq==n){
	 		return 'Y';
		 }
	 }
	 
	 return 'N';
}



char isSphenic(int n){
	
	for(int i=2;i<n/2;i++){
	if((n%i==0) && isPrime(i))
	return 'Y';	
	}
	return 'N';
}



	string binaryEquivalent(int n){
	
		int d;
		char binaryNumber[7] ;
	
	
	for (int i=0;i<8;i++){
		d=n%2;
		if(d==0)
		binaryNumber[7-i]= 48 ;
		else
	    binaryNumber[7-i]= 49 ;
		n=n/2;
		}
		
		
	return binaryNumber;
}



	int table(){
	
	int n;
	int arraySize;
	int array[200];
	int a,i;
	int inside = 0;
	int count;
	
	ifstream numbers;	
	numbers.open("numbers.txt");
	while(!numbers.eof()){
	count=0;
	numbers>>a;
	if((a>0)&&(a<101)){
	
	for(i=0;i<=inside;i++){
		if(array[i]==a){
			count=count +1;
		}
	}if(count==0){

		array[inside]=a;
		inside++;
	}
	 arraySize = inside;
	}
	}
	numbers.close();
	
	

	
	cout<<"Number\tPerfect?\tPrime?\tPerfect Square?\tSphenic?\tBinary Equiv."<<endl;
	cout<<"------\t--------\t------\t---------------\t--------\t-------------"<<endl;
	cout<<"------\t--------\t------\t---------------\t--------\t-------------"<<endl;
	cout<<endl;
	
	for(i=0;i<arraySize;i++){
		
		n=array[i];
		
	cout<<n<<" \t"<< perfectNumber(n)<<"\t\t"<<isPrime(n)<<"\t";	
	cout<<isPerfectSquare(n)<<"\t\t"<<isSphenic(n)<<"\t\t"<<binaryEquivalent(n)<<endl;
	}
	
	
	cout<<"\n\n"<<endl;
	
	return 0;
	}



	string tally(int n){
	
	if((n>4)&&(n<10))
	return "*";
	
	if((n>9)&&(n<15))
	return "**";
	
	if((n>14)&&(n<20))
	return "***";
	
	if((n>19)&&(n<25))
	return "****";
	

}



int histogram (){
	
	int x=1;
	int y=10;
	
	ifstream inputnumbers;
	cout<<"Range\t\t\t"<<"Histogram"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"-----------------------------------"<<endl;
	for(int i=0;i<10;i++){
	int a;	
	int count = 0;	
	inputnumbers.open("numbers.txt");
	inputnumbers>>a;
	while(a!=-1){
		
	if((a>=x)&&(a<=y)){
		count = count + 1;
}
	
	inputnumbers>>a;
	
}
cout<<x<<"  - \t "<<y<<"\t\t"<<"|"<<tally(count)<<endl;	
	inputnumbers.close();
	x=x+10;
	y=y+10;	
}
cout<<"\n\n"<<endl;
return 0;
}



	statisticalInformation(){
	
	
	cout<<"The amount of student who specified valid favourite numbers are :\t "<<validNumbers()<<endl;
	cout<<"The amount of student who specified invalid favourite numbers are :\t "<<invalidNumbers(0)<<endl;
	cout<<"The amount of student who did not reveal their favourite numbers are :\t "<<favNumNotReveal()<<endl;
	mostChosenNum ();
	leastChosenNum ();
	
	
	
	
	
}



	
	int main()
	{
	readOutNumbers();
	
	
	table();
	
	invalidNumbers(1);
		
	 histogram ();
	
	
	statisticalInformation();
	
	
		return 0;
	}



