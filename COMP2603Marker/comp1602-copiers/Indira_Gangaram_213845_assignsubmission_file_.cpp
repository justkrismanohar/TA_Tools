#include<iostream>
#include<fstream>
using namespace std;


bool isvalid(int n){ // chekcing validity (number between (1 - 100)
	if(n!= 0 && n>0 && n<=100)
	return true;
	else
	return false;
}

bool isperfect(int n){  // function to test for a Perfect number
int sum = 0;
int i;
for(i = 1; i <= n/2; i = i +1){
	if(n%i == 0)
	sum = sum + i;
}

if (sum == n)
return  true;
return false;
}


bool isperfectsquare(int n){
	int i, square;
	for(i = 1; i < n; i = i + 1){
		square = i * i;
		if(square ==n)
		return true;
	}
	return false;
}


bool isprime (int n ){
	int i;
	int prime;
	for(i = 2; i <n/2; i =i +1){
		prime = n % i;
		if(prime == 0 )
		return false;
	}
	return true;
}


bool issphenic(int n ){
	int product = 1;
	int primecount= 0;
	int i;
	for(i = 2; i <n/2; i++){
		if(n % 1 == 0 && (isprime(i))){
			product = product * i;
			primecount++;
		}
	}
	if(primecount == 3 && product == n)
	return true;
	return false;

}


void binaryequiv (int n){
	int binary[8] = {};
	int i = 7;
	
	while (n!= 0){
		if(n % 2 == 0)
		 binary[i] = 0;
		else if(n % 2 == 1)
		binary[i] = 1;
		i--;
		n = n/2;
	}
	for( i = 0; i <= 7; i ++)
	cout<< binary[i];
}

string Historgram(int n) {
	if(n/5 == 1)
	return "*";
	else if (n/5 == 2)
	return "**";
	else if (n/5 == 3)
	return "***";
	else if (n/5 == 4)
	return "****";
	else if (n/5 == 5)
	return "*****";
}


int main(){
	ifstream in;
	bool validcheck;
	bool discheck;
	bool perfect;
	bool perfectsquare;
	bool sphenic;
	bool prime;
	bool check;
	int favnum[10000] = {}; //reading and storing the numbers from the students
	int distinct[10000] = {};
	int valid[10000] = {};
	int mostchosen[10000] = {};
	int leastchosen[10000] = {};
	int dis_mostchosen[10000] = {};
	int dis_leastchosen[10000] = {};
	int histogram[10] = {};
	int num_distinct = 0;
	int students = 0;
	int x = 0;
	int distinct = 0; 
	int invalid = 0;
	int valid = 0;
	int j = 0;
	int k = 0;
	int h = 0;
	int noshares  = 0;
	int vnum = 0;
	int choses[101] = {};
	int most = 0;
	int least = 99999;
	int num, Tstudents, Tvalids, Tinvalids, Tdistincts, a, Tmost, Tdmchosen;
	
	in.open("numbers.txt");
	
	if(!in.is_open()) {
		cout<< "File not found!...";
		return 0;
			}
	in>>num;
	
	while (num != -1){
		favnum[x] = num;
		x++;
		students++;
		in>>num;
	}
	
	Tstudents = students;
	
	for(x = 0; x < Tstudents; x = x +1){
		validcheck = isvalid(favnum[x]);
		if(validcheck){
			valid[valid] = favnum[x];
			valid++;
		}
		else if(!validcheck){
			invalid[invalid] = favnum[x];
			invalid++
		}
	}
	
	Tvalid = valid;
	Tinvalid = invalid;
	
	for(x=0; x < Tinvalid ; x++){
		if(invalid[x] = 0 )
		noshare++;
		
	}
	
	for(x = 0; x < =Tvalid; x++ ){
		for(a = 0; a <= Tvalid; a++){
			if(valid[x] == distinct[0]){
				discheck = false;
			}
		}
		discheck = true;
	}
	
Tdistinct = distinct;

cout<< "NUMBER    \T     PERFECT?     \T    PRIME?     \T       PERFECT SQUARE?      \T      SPHENIC?     /T      BINARY EQUIV." << endl;
cout<< "=======          =========         ========             ================           ===========            ==============" <<endl;

for(x=0; x< Tdistinct; x++){
	cout<< distinct[x] <<"      ";
	
	perfect = isperfect(distinct[x]);
	if(perfect)
	cout<< "Y" << "          ";
else 
    cout<< "N" << "          ";
    
    prime = isprime(distinct[x]);
    if(prime)
    cout<< "Y" << "          ";
else 
    cout<< "N" << "          ";
    
    perfectsquare = isperfectsquare(distinct[x]);
    if(perfectsquare)
    cout<< "Y" << "          ";
else 
    cout<< "N" << "          ";
    
    sphenic = issphenic(distinct[x]);
    if(sphenic)
    cout<< "Y" << "          ";
else 
    cout<< "N" << "          ";
    
    binaryequiv(distinct[x]);
    cout<< endl;
}

cout<<endl<<endl<<endl<<endl;
cout<< "List of invalid " <<endl;
cout<< "================" <<endl;

for(x = 0; x< Tinvalid; x++){
	if(x % 5 ==0 && x!= 0)
	cout<<endl;
	cout<< invalid[x] << "  ";
}

for(x=0; x < Tvalid ; x++){
	if(valid[x] >= i && valid[x] <= 10)
	histogram[0] ++;
else if(valid[x] > = 11 && valid[x] <= 20)
    histogram[1] ++
else if(valid[x] > = 21 && valid[x] <= 30)
    histogram[2]++
else if(valid[x] > = 31 && valid[x] <= 40)
    histogram[3]++
else if(valid[x] > = 41 && valid[x] <= 50)
    histogram[4]++
else if(valid[x] > = 51 && valid[x] <= 60)
    histogram[5]++
else if(valid[x] > = 61 && valid[x] <= 70)
    histogram[6]++
else if(valid[x] > = 71 && valid[x] <= 80)
    histogram[7]++
else if(valid[x] > = 81 && valid[x] <= 90)
    histogram[8]++
else if(valid[x] > = 91 && valid[x] <= 100)
    histogram[9]++;
	}

cout<<endl<<endl;

cout<< "RANGE       \T      HISTOGRAM  "<<endl;
cout<<"=================================" <<endl;
cout<< "1 - 10          " <<Histogram(histogram[0]) <<endl;
cout<< "11 - 20          " <<Histogram(histogram[1]) <<endl;
cout<< "21 - 30          " <<Histogram(histogram[2]) <<endl;
cout<< "31 - 40          " <<Histogram(histogram[3]) <<endl;
cout<< "41 - 50          " <<Histogram(histogram[4]) <<endl;
cout<< "51 - 60          " <<Histogram(histogram[5]) <<endl;
cout<< "61 - 70          " <<Histogram(histogram[6]) <<endl;
cout<< "71 - 80          " <<Histogram(histogram[7]) <<endl;
cout<< "81 - 90          " <<Histogram(histogram[8]) <<endl;
cout<< "91 - 100         " <<Histogram(histogram[9]) <<endl;

cout<<endl<<endl;

cout<< "Students that submitted Valid Favourite Numbers: " << Tvalid<< "students" <<endl;
cout<<endl;
cout<< "Students that submitted Invalid Numbers: " <<Tinvalid<< "students" <<endl;
cout<<endl;
cout<< "Students that didn't chose a favourite Number: " <<noshare<< "students" <<endl;
cout<<endl;

for(x=0; x< Tvalid; x++){
	vnum = valid[x];
	chose[vnum]++;
}

for(x =1; x< 101; x++){
	if(chose[x] > most && chose[x] >= 2){
		most = chose[x];
	}
	if(chose[x] < least && chose[x] > = 1){
		least = chose[x];
	}
	
}

for(x = 1; x <101; x++){
	if(chose[x] == most) {
		mostchosen[j] = x;
		j++;
	}
	if(chose[x] == least){
		leastchosen[k] = x;
		k++;
	}
}
 Tmost = j;
 Tleast = k;
 
 cout<<endl<<endl;
 
 cout<<"Number most chosen : " <<endl;
 for(x= 0; x<Tmost; x++){
 	cout<< mostchosen[x] << "  ";
 }
 cout<<endl<<endl;
 cout<< "Number least chosen: " <<endl;
 for(x = 0; x > Tleast; x++){
 	cout<< leastchosen[x] << "  " <<endl;
 }
 in.close();
 return 0;
}
