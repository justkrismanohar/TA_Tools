#include<iostream>
#include<fstream>
using namespace std;

//Functions

//isPerfect
bool isPerfect(int num, int i=1,int sum=0){
	while(i<num){
	if (num%i==0);
	int sum=sum+i;
	i++;
}

if(sum==num){
return true;
}
else{
return false;
}
}

//isPrime
bool isPrime(int num){
	int i, Y;
for(i=2; i < num/2; i=i+1);{

if(num%i==0)
{
	return true;
}
else
{
	return false;
}
}}
	
//isPerfectSquare
bool isPerfectSquare(int num){
	int r=1, i=1;

while(r<num){
	i++;
	r=i*i;
}
if(r==num)
{
	return true;
}
else
{
	return false;
}
}

//isSphenic
bool isSphenic (int num){
	int i, count = 0, product = 1;
for (i = 2; i <= num/2; i = i+1){
	if(num%i == 0 && isPrime(i)){
	product = product * i;
	count = count + 1;
}
if (count  == 3 && product == num)
{
	return true;
}
else
{
	return false;
}
}}

//Binary
bool Binary(int num){
	int a[50], i;
for(i=0; num>0; i++)
{
	a[i]=num%2;
	num=num/2;
}
for(i=i-1; i>=0 ;i--)
{
cout<<a[i];
}
}

//isDictinct
bool isDistinct(int num){
if(num>0 && num<=100)
{
return true;
}
else
{
return false;
}
}

//Histogram
void output (int number){
 int temp=0;
 int i;
 for(i=0;i<=number;i++){
 temp++;
 if(temp== 5){
 cout<<"*";
 temp=0;
}
}
}

//Main

int main(){
	
int num, x, z=0,temp=0,fst=0,snd=0,trd=0,frth=0,ffth=0,sxth=0,svth=0,egth=0,nith=0,tnth=0,a=0, nondisclosed=0, invalid[100];
bool perfect, prime, perfectsquare, sphenic;
ifstream inputFile;

inputFile.open("numbers.txt");
if(!inputFile.is_open()){
cout<<"No file found";
return 0;}
	
cout<<"Number"<<"\t\t"<<"Perfect?"<<"\t\t"<<"Prime?"<<"\t\t"<<"Perfect Square?"<<"\t\t\t"<<"Sphenic"<<"\t\t"<<"Binary Equiv"<<endl;
cout<<"====="<<"\t\t"<<"====="<<"\t\t\t"<<"====="<<"\t\t\t"<<"====="<<"\t\t\t"<<"====="<<"\t\t"<<"====="<<endl;

while(num!=-1){
inputFile>>num;	
	if (num==0){
	nondisclosed++;
	}	
if(!(isDistinct(num)) && (num!=0)){
	invalid[z]=num;
	z++;
}
			
if(isDistinct(num)){   
				
cout<<num<<"\t\t";

//isPerfect
bool perfect=isPerfect(num);
if(perfect==true){
	cout<<"Y";
}
else{
	cout<<"N";
}
cout<<"\t\t\t";

//isPrime
bool prime=isPrime(num);
if(prime==true){
	cout<<"Y";
}
else{
	cout<<"N";
}
cout<<"\t\t\t";

//isPerfectSquare
bool perfectsquare=isPerfectSquare(num);
if(perfectsquare==true){
	cout<<"Y";
}
else{
	cout<<"N";
}
cout<<"\t\t\t";

//isSphenic
bool sphenic=isSphenic(num);
if(sphenic==true){
	cout<<"Y";
}
else{
	cout<<"N";
}
cout<<"\t\t";

//Binary
cout<<Binary(num);
}

cout<<endl;

//Histogram

if(num>=1 && num <=10){
fst++;
}
else if(num>=11 && num <=20){
snd++;
}
else if(num>=21 && num <=30){
trd++;
}
else	if(num>=31 && num <=40){
frth++;
}
else 	if(num>=41 && num <=50){
ffth++;
}
else	if(num>=51 && num <=60){
sxth++;
}
else	if(num>=61 && num <=70){
svth++;
}
else 	if(num>=71 && num <=80){
egth++;
}
else	if(num>=81 && num <=90){
nith++;
}
else if(num>=91 && num <=100){
tnth++;
}

}

cout<<endl;

//inValid
cout<<"Invalid Numbers are: "<<endl;
for (a=0;a<z;a++){
cout<<invalid[a]<<" ";
temp++;	
if(temp==5) {
cout<<endl;
temp =0;
	}
}

cout<<endl<<endl;

//Histogram output
cout << "Range        Histogram" << endl;
cout << "-------------------------" << endl;
cout << "1-10         "; output(fst); cout<<endl;
cout << "11-20        "; output(snd);  cout<< endl;
cout << "21-30        "; output(trd);  cout<< endl;
cout << "31-40        "; output(frth); cout<< endl;
cout << "41-50        "; output(ffth); cout<< endl;
cout << "51-60        "; output(sxth); cout<< endl;
cout << "61-70        "; output(svth); cout<< endl;
cout << "71-80        "; output(egth); cout<< endl;
cout << "81-90        "; output(nith); cout<< endl;
cout << "91-100       "; output(tnth); cout<< endl;

cout<<endl<<endl;

//Statements
cout<<"Students who specified valid favourite numbers: "<<z<<endl;
cout<<"Students who specified invalid numbers: "<<a<<endl;
cout<<"Students that did not wish to disclose their favourite number: "<<nondisclosed<<endl;

cout<<"Numbers chosen most by the students:"<<endl;

cout<<"Numbers chosen least by the students: "<<endl;

inputFile.close();


return 0;
}
