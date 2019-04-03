#include <iostream>
#include <fstream>

using namespace std;

void perfect(int a){//perfect square
	int div, divsum;
	div = 0;
	divsum = 0;
	for(int i = 1; i < a; i++){
		if((a%i) == 0){
		div = i;
		divsum = div + divsum;
	}
}
	if (a == divsum){
	 cout<<"True";
	 }
	else
	 cout<<"False";
}

void prime(int a){//prime number
	bool primey;
	int i;
	for(i = 2; i < a; i++){
		if(a%i == 0){
			cout<<"False";
			break;
		}
	}
	if(a == i){
	cout<<"True";
}
}

bool prsphen(int a){//checking if number is prime for sphenic function
	int num;
	for(num = 2; num < a; num++){
		if(a % num == 0){
			return 0;
		}
	}
	return 1;
}

bool sphenic(int a){//finding if the number is sphenic??????
	bool sphen;
	int i;
	int counter = 0;
	int product = 1;
	for(i = 2; i < a; i++){
		if((a%i == 0) && prsphen(i)){
			product = product * i;
			counter++;
		}
		if((counter == 3) && (product ==a)){
			cout<<"True";
			return 1;
		}
	}
	cout<<"False";
	return 0;
}
	

void psquare(int a){//finding if the number is a perfect square
	int squarey = 0;
	for(int i = 1; i < a; i++){
		squarey = i * i;
		if(squarey == a){
			cout<<"True";
			break;
		}
	}
	if(squarey != a){
	cout<<"False";
}
}

void binary(int a){//finding if the number is a binary
	int i, numzero;
	int integers = 0;
	int bin[7] = {0};
	for(i = 0; a > 0; i++){
		bin[i] = a % 2;
		integers++;
		a = a / 2;
	}
	numzero = 8 - integers;//adding 0s to the front of the binary number
	for(int j = 0; j < numzero; j++){
		cout<<"0";
	}
	
	for(i = i - 1; i >=0 ; i--){
		cout<<bin[i];
	}
}


int printstar(int a){//printing stars for histogram
	
for (int i = 0; i < a; i++) 
    {
            cout << "*";
    }
}



int main(){
	
	int count, countzero, countinval, rcount, rcountzero, rcountinval, num;
	int numv[100] = {0};
	int numi[100] = {0};
	ifstream in;
	
	in.open("numbers.txt");
	if(!in.is_open()){
		cout<<"Error opening input file";
		return 0;
	}
	
	count = 0;//count of number of valid students
	countzero = 0;
	countinval = 0;
	
	
	//reading in values into array
	in>>num;
	while(num != -1){
		
		if (num > 0 && num <= 100){
			numv[count] = num;
			//cout<<numv[count]<<endl;
			count++;
		}
		
		else if(num < -1 || num > 100){
			numi[countinval] = num;
			//cout<<numi[countinval]<<endl;
			countinval++;
		}
		
		else{
			countzero++;
		}
		

		
		in>>num;
	}
	
	cout<<countinval<<endl;
	cout<<"Number		Perfect?		Prime?		Perfect Square?		Sphenic?		Binary Equiv."<<endl;
	cout<<"======		========		======		===============		========		============="<<endl;
	int b;
	for(int i = 0; i < count; i++){
		b = numv[i];
		cout<<b;
		cout<<"		";
		perfect(b);
		cout<<"			";
		prime(b);
		cout<<"		";
		psquare(b);
		cout<<"			";
		sphenic(b);
		cout<<"			";
		binary(b);
		cout<<endl;
	}
	
		for(int count2=0; count2 < countinval; count2++){//loop to print out 5 numbers a line
		cout<<numi[count2]<<", ";
		if(count2%5 == 0){
			cout<<endl;
		}
	}
	
	
	//histogram
	int histo;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	int c5 = 0;
	int c6 = 0;
	int c7 = 0;
	int c8 = 0;
	int c9 = 0;
	int c10 =0;
	for(int i = 0; i < count; i++){
		histo = numv[i];
		if(histo >= 1 && histo <= 10){
			c1++;
		}
		else if(histo >=11 && histo <= 20){
			c2++;
		}
		else if(histo >=21 && histo <= 30){
			c3++;
		}
		else if(histo >=31 && histo <= 40){
			c4++;
		}
		else if(histo >=41 && histo <= 50){
			c5++;
		}
		else if(histo >=51 && histo <= 60){
			c6++;
		}
		else if(histo >=61 && histo <= 70){
			c7++;
		}
		else if(histo >=71 && histo <= 80){
			c8++;
		}
		else if(histo >=81 && histo <= 90){
			c9++;
		}
		else if(histo >=91 && histo <= 100){
			c10++;
		}
	}
	cout<<endl;
	cout<<"Range		Histogram"<<endl;
	cout<<"======================"<<endl;
	cout<<"1-10		:";
	printstar(c1);
	cout<<endl;
	cout<<"11-20		:";
	printstar(c2);
	cout<<endl;
	cout<<"21-30		:";
	printstar(c3);
	cout<<endl;
	cout<<"31-40		:";
	printstar(c4);
	cout<<endl;
	cout<<"41-50		:";
	printstar(c5);
	cout<<endl;
	cout<<"51-60		:";
	printstar(c6);
	cout<<endl;
	cout<<"61-70		:";
	printstar(c7);
	cout<<endl;
	cout<<"71-80		:";
	printstar(c8);
	cout<<endl;
	cout<<"81-90		:";
	printstar(c9);
	cout<<endl;
	cout<<"91-100		:";
	printstar(c10);
	cout<<endl;
	
	
	cout<<"Number of students who specified valid numbers is "<<count<<endl;
	cout<<"Number of students who specified invalid numbers is "<<countinval<<endl;
	cout<<"Number of students who did not reveal their numbers is "<<countzero<<endl;

	int j;
	int scount = 0;
	int maxcount = 0;
	int val = 0;
	int i;
	//finding out the most frequent number chosen
	for(i = 0; i < count; i++){
		for(j = 0; j < count; j++){
			if(numv[j] == numv[i]){
				scount++;
			}
		}
		
		if(scount > maxcount){
			maxcount = scount;
			val = numv[i];
		}
		scount = 0;
	}
	cout<<"Most frequent is: "<<val<<endl;
	
	cout<<"The least frequent numbers chosen are: ";
	//finding the least frequent chosen
	int tcount = 0;
	int mincount = 100000;
	for(i = 0; i < count; i++){
		for(j = 0; j < count; j++){
			if(numv[j] == numv[i]){
				tcount++;
			}
		}
		
		if(tcount == 1){
			cout<<numv[i]<<",";
		}
		
		tcount = 0;
	}
	
	
		


}
	
	
	


