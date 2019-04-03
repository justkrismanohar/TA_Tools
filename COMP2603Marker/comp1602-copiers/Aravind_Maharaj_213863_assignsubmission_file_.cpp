#include <iostream>
#include <fstream>
using namespace std;

bool isPerfect (int p){
	int sum;
	for ( int y=1; y<p; y++)
	{
	int z = p % y;
	if ( z == 0)
		sum = sum + y;
	}
	if (sum == p)
		return true;
	else
		return false;
	}

bool isPrime (int p){
	for (int x=1;x<=p/2;x++){
		if (p%2 == 0)
			return false;//0
		else
			return true;//1
	}
}
	
bool perfectSq (int s){

	
	int x,y;
	
	while (x<s){
	x = y*y;
	y++;
	}
	if (x == s)
	return true;
	else 
	return false;
}
void binary (int n){
	int b[8], loop = 0, hold = 0, x = 0;
	
	for ( loop = 0; loop < 8; loop++)
		b[loop] = 0;
		
	for (loop = 0; loop < 8; loop++){
		b[loop] = n%2;
		n = n/2;
	}
	for (loop = 7; loop >=0;loop--){
		cout<<b[loop];
	}
		
	}


bool isSphenic (int r){
	int p = 1, cot = 0 ,prod = 1, n;
	
	for ( p = 2; p <= n/2; p++){
		if ( r % p == 0){
			cot++;
			prod = prod * p;
		}
	}
		if ((cot == 3) && (prod == r)){
			return true;
		}
		else return false;
	}


int main (){
	
	ifstream in;
	in.open("numbers.txt");
	
	int x = 0;
	int invalid [20], inva = 0;
	int r[10], range1 = 1, range2 = 10;
	int numbers[150], numbersC =0;
	int fave = 0, noFave = 0;
	int loop = 0, holder = 0, c = 0;
	char prime, perfect, pSq, isSp;
	int num[150], numC = 0;
	int count = 0, topCount = 0,topElement =0;
	int l1, l2;
	int invalidNum [10], inNum = 0;
	
	cout<<"Number"<<"	"<<"Perfect"<<"	"<<"Prime"<<"	"<<"Perfect Square"<<"	"<<"Sphenic"<<"	"<<"Binary"<<endl;
	for (loop = 0; loop<10; loop++){
		r[loop] = 0;
		invalidNum[loop]= 0;
	}
	for (loop = 0; loop <20; loop++)
		invalid[loop] = 0;
	for (loop = 0; loop < 150; loop++)
		num[loop] = 0;
	
	while( x != -1){
		if ((x > 0) && (x < 101)){
		
			if ((x>1) && (x<10))
				r[0]++;
			if ((x>11) && (x<20))
				r[1]++;
			if ((x>21) && (x<30))
				r[2]++;
			if ((x>31) && (x<40))
				r[3]++;
			if ((x>41) && (x<50))
				r[4]++;
			if ((x>51) && (x<60))
				r[5]++;
			if ((x>61) && (x<70))
				r[6]++;
			if ((x>71) && (x <80))
				r[7]++;
			if ((x>81) && (x<90))
				r[8]++;
			if ((x>91) && (x<100))
				r[9]++;	
				
			if(x > 0)
				fave++;
				
			
			
		if (isPrime(x) == true)
			prime = 'Y';
		else
			prime = 'N';
	
		if (isPerfect (x) == true)
			perfect = 'Y';
		else
			perfect = 'N';
	
		if(perfectSq (x) == true)
			pSq = 'Y';
		else
			pSq = 'N';
		
		if (isSphenic (x) == true)
			isSp = 'Y';
		else
			isSp = 'N';
			
		cout<<x<<"	"<<perfect<<"	"<<prime<<"	"<<pSq<<"		"<<isSp<<"	";
		binary(x);
		cout<<endl;
		num[numC] = x;
		numC++;		
		}
		else{
			invalid[inva] = x;
			inva++;
		}
		if (x == 0)
			noFave++;
	in>>x;	
}
cout<<endl;
cout<<"Range"<<"		"<<"Histogram"<<endl;
cout<<"============================"<<endl;
for (loop =0;loop <10;loop++){
	
		holder = r[loop]/5;
		
		cout<<range1<<"-"<<range2<<"		|";
		
		for (int a = 0; a < holder; a++) {
			cout << "*";
		}
		cout << endl;
		
		range1 = range1 + 10;
		range2 = range2 + 10;
}
cout<<endl;
cout<<"Most Popular Numbers:"<<endl;
for (l1 = 0; l1 <= numC; l1++){
	count = 0;
	int r = 0;
		for(l2 = 0; l2<numC; l2++){
			if (num[l1] == num[l2])
				count++;
		}
		if ( count >= 2){
			topCount = count;
			topElement = num[l1];
			
			cout<<topElement<<endl;
			
		}
	}
	cout<<endl;
	
holder = 0;
holder = inva - noFave;


cout<<"Favorite :"<<fave<<"	"<<"Did not reveal  favorite :"<<noFave<<"	"<<"Invalid Numbers: "<<holder<<endl;

	for(loop = 0; loop < 20;loop++){
		if (invalid [loop] != 0){
		invalidNum[inNum] = invalid[loop];
		inNum++;
		}
	}
	cout<<endl<<"Invalid Numbers:"<<endl;
	for (loop = 0; loop <10; loop++){
	
	cout<<invalidNum[loop]<<"  ";
	if (( loop + 1) % 5 == 0)
	cout<<endl;
}
}
