#include <iostream>
#include <fstream>
using namespace std;
int array [8];
bool isPerfect (int n){
	int i, sum=1;
	for(i=2; i<=n/2; i++){
		if(n%i==0)
		sum=sum+i;
	}
	if(sum==n)
	return true;
	return false;
}

bool isPrime(int n){
	int i, counter=0;
	for(i=2; i<=n/2; i++){
		if(n%i==0)
		counter++;
	}
	if(counter==0)
	return true;
	return false;
}

bool isPerfectSquare (int n){
	int i, counter=0;
	i=1;
	while((i<=n/2)&&(counter==1)){
		if(i*i==n)
		counter++;
		i++;
	}
	if(counter==0)
	return false;
	return true;
}

bool isSphenic(int n){
	int i, counter, product;
	counter= 0;
	product=1;
	for(i=2;i<=n/2;i++){
		if(n%i==0 && isPrime(i)==true){
			product= product*i;
			counter++;
		}
	}
	if(counter==3 && product==n)
	return true;
	return false;
}
void binaryNo(int n){
	int i=0;
	while(n!=0 && i<8){
		array[i]=n%2;
		n=n/2;
		i++;
	}
}

void printStars(int n){
	int i;
	for(i=0;i<n; i++)
	cout<< "*";
	}
	
	int main(){
		int invalidArray[100], validArray[100], numArray[101];
		int counterValid,counterInvalid,count,star,mostNo,leastNo,mostCount,leastCount;
		int one,two,three,four,five,six,seven,eight,nine,ten,a,b,c,d,i,number;
		bool perfectNo, primeNo, sphenicNo, perfectSquareNo;
		char yes='Y';
		char no='N';
		for(b=0;b<101;b++)
		numArray[b]=0;
		counterValid=0;
		counterInvalid=0;
		count=0;
		one=0;
		two=0;
		three=0;
		four=0;
		five=0;
		six=0;
		seven=0;
		eight=0;
		nine=0;
		ten=0;
		d=1;
		mostCount=0;
		leastCount=100;
		ifstream in;
		in.open("numbers.txt");
		if(!in.is_open()){
			cout<<"File not found. Aborting..";
			return 0;
		}
		cout<<"Number		   Perfect?		    Prime?		   Perfect Square?		Sphenic?		   Binary"<<endl;
		cout<<"======================================================================================================================================="<<endl;	
		in>>number;
		while(number!=-1){	
			if(number==0)
			numArray[0]=numArray[0]+1;
			else{
				if(number>100||number<-1){
				invalidArray[counterInvalid]=number;
				counterInvalid++;
				}
				else{
				numArray[number]=numArray[number]+1;
				counterValid++;
					}
				}
				in>>number;
			}
		for(d=1;d<101;d++){
			if(numArray[d]>0){
				perfectNo=isPerfect(d);
				primeNo=isPrime(d);
				perfectSquareNo=isPerfectSquare(d);
				sphenicNo=isSphenic(d);
				for(a=0; a<8; a++)
				array [a]=0;
				binaryNo(d);
				cout<<d<<"          		";
					if(perfectNo==true)
					cout<<yes<<"          		";
					else
					cout<<no<<"          		";
						if(primeNo==true)
						cout<<yes<<"          		";
						else
						cout<<no<<"          		";
							if(perfectSquareNo==true)
							cout<<yes<<"          		";
							else
							cout<<no<<"          		";
								if(sphenicNo==true)
								cout<<yes<<"          		";
								else
								cout<<no<<"          		";
				for(a=0;a<8;a++)
				cout<<array[a];
				for(a=0;a<8;a++)
				array[a]=0;
				cout<<endl;
				}
			}
		cout<<endl;
		cout<<"Invalid Numbers:"<<endl;
		for(b=0;b<counterInvalid;b++){
			if(count%5==0)
			cout<<endl<<invalidArray[b]<<" ";
			else
			cout<<invalidArray[b]<<" ";
			count++;
		}
		cout<<endl<<endl;
		for(i=1;i<101;i++){
			if(i<=10&&i>=1)
			one=numArray[i]+one;
			else{
				if(i<=20&&i>=11)
				two=numArray[i]+two;
				else{
					if(i<=30&&i>=21)
					three=numArray[i]+three;
					else{
						if(i<=40&&i>=31)
						four=numArray[i]+four;
						else{
							if(i<=50&&i>=41)
							five=numArray[i]+five;
							else{
								if(i<=60&&i>=51)
								six=numArray[i]+six;
								else{
									if(i<=70&&i>=61)
									seven=numArray[i]+seven;
									else{
										if(i<=80&&i>=71)
										eight=numArray[i]+eight;	
										else{
											if(i<=90&&i>=81)
											nine=numArray[i]+nine;
											else
											ten=numArray[i]+ten;
										}		
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<"Range	 		    Histogram"<<endl;
		cout<<"1-10				|";
		star=one/5;
		printStars(star);
		cout<<endl;
		cout<<"11-20				|";
		star=two/5;
		printStars(star);
		cout<<endl;
		cout<<"21-30				|";
		star=three/5;
		printStars(star);
		cout<<endl;
		cout<<"31-40				|";
		star=four/5;
		printStars(star);
		cout<<endl;
		cout<<"41-50				|";
		star=five/5;
		printStars(star);
		cout<<endl;
		cout<<"51-60				|";
		star=six/5;
		printStars(star);
		cout<<endl;
		cout<<"61-70				|";
		star=seven/5;
		printStars(star);
		cout<<endl;
		cout<<"71-80				|";
		star=eight/5;
		printStars(star);
		cout<<endl;
		cout<<"81-90				|";
		star=nine/5;
		printStars(star);
		cout<<endl;
		cout<<"91-100				|";
		star=ten/5;
		printStars(star);
		cout<<endl;
		cout<<"Amount of Valid Numbers: "<<counterValid<<endl;
		cout<<"Amount of Invalid Numbers: "<<counterInvalid<<endl;
		cout<<"Amount of Non-specified Numbers: "<<numArray[0]<<endl;
		for(c=1;c<101;c++){
			if(numArray[c]>mostCount){
				mostCount=numArray[c];
				mostNo=c;
			}
			if(numArray[c]<leastCount&&numArray[c]>=1){
				leastCount=numArray[c];
				leastNo=c;
			}
		}
		cout<<"Most Number Chosen: ";
		for(c=1;c<101;c++){
			if(numArray[c]==mostCount){
				mostNo= c;
				cout<<mostNo<<" ";
			}
		}
		cout<<endl;
		cout<<"Least Number Chosen: ";
		for(c=1;c<101;c++){
			if(numArray[c]==leastCount){
				leastNo= c;
				cout<<leastNo<<" ";
			}
		}
		in.close();
		return 0;
			}
	
	
	
	
	
	
	
	
	

