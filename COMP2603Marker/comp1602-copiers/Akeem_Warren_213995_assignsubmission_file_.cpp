#include <iostream>              //816001179
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

#define MAX 150

//b (v)
void NumtoBinary(int n){
	int binarynum[1000]={};

	int i=0;
	while(n>0){
		binarynum[i]=n%2;
		n=n/2;
		i++;
	}
	int numbits=8;
	if(i>8)
	numbits=8*((i+7)/8);



	for (int j=numbits-1;j>=0;j--){
            cout<<binarynum[j];
	}
}
//b (i)
bool isPerfect(int n){
	int i, divs;
	int sum=0;

	for(i=1; i<n; i++){
		divs=n%i;
		if(divs == 0)
		sum=sum+i;
	}
	if(sum==n)
		return true;
		else
		return false;

}
//b (ii)
bool isPrime(int n){
	int i;
	bool prime= true;

	for(i=2;i<=n/2;i++){
		if(n%i==0){
			return false;
		}
	}
return true;
}
//b (iii)
bool isPerfectsq(int n){
	int i=1;
	int p=1;

	while(p<n){
		i++;
		p=i*i;

	}
		if(p==n)
		return true;
	else
		return false;

}
//b (iv)
bool isSphenic(int n){
	int i;
	int count=0;
	int product=1;

	for(i=2;i<=n/2;i++){
		if(n%i==0 && isPrime(i)){
			product=product*i;
			count++;
		}
	}
	if((count==3) && (product==n))
			return true;
			else
			return false;
}

void printStars(int numStars){
int i;

for(i = 1; i<= numStars; i= i+1)
	cout<<"*";
	cout<<endl;
}


int main(){

	int countdup=0;
	int notreveal=0;
	int totalval=0;
	int countInval=0;
	int studentnum[MAX];
	int count=0;
	int rng1=0,rng2=0,rng3=0,rng4=0,rng5=0,rng6=0,rng7=0,rng8=0,rng9=0,rng10=0;
	
	//(a)
	ifstream read;
	read.open("numbers.txt");

	if(!read.is_open()){
		cout<<"Inventory file could not open for reading."<<endl;
		cout<<"Aborting"<<endl;
	}

	read>>studentnum[count];
	while(studentnum[count]!=-1 ){
		count++;

		read>>studentnum[count];
	}

	read.close();
	
	// the code below displays all the numberes read from the file. (a) never asked for the numbers to be displayed or outputed.**
	/*
		for (int j= 0; j<= count ;j++){

		cout<<studentnum[j]<<endl;
		cout<<endl;
	}
	*/
	
	
	cout<<"Numbrer"<<"\t"<<"Perfect?"<<"   "<<"Prime?"<<"   "<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"      "<<"Binary Equiv"<<endl;
	cout<<"-------"<<"\t"<<"--------"<<"   "<<"------"<<"   "<<"---------------"<<"\t"<<"--------"<<"      "<<"------------"<<endl;
	
	

	for (int j= 0; j<= count;j++){


		if(studentnum[j]>=1 && studentnum[j]<=100){

			cout<<studentnum[j]<<"\t";
			int studentn=studentnum[j];
			
			
			if(isPerfect(studentn)== true)
	cout<<"Y"<<"\t"<<"   ";
	else
	cout<<"N"<<"\t"<<"   ";

			if(isPrime(studentn)== true)
	cout<<"Y"<<"\t"<<"   ";
	else
	cout<<"N"<<"\t"<<"   ";

	
		if(isPerfectsq(studentn)== true)
	cout<<"Y"<<"                    ";
	else
	cout<<"N"<<"                    ";
if(isSphenic (studentn)==true)
	cout<<"Y"<<"\t"<<"       ";
	else
	cout<<"N"<<"\t"<<"       ";

     NumtoBinary(studentn);
     cout<<"\t"<<endl;
		}

}
	cout<<endl<<endl;
	//(d)
	cout<<"-----------------------------------------------------------------------"<<endl;
	for (int j= 0; j<= count ;j++){


		if(studentnum[j]>=1 && studentnum[j]<=10)
		rng1++;
		else if(studentnum[j]>=11 && studentnum[j]<=20)
				rng2++;
				else if(studentnum[j]>=21 && studentnum[j]<=30)
						rng3++;
						else if(studentnum[j]>=31 && studentnum[j]<=40)
								rng4++;
								else if(studentnum[j]>=41 && studentnum[j]<=50)
										rng5++;
										else if(studentnum[j]>=51 && studentnum[j]<=60)
												rng6++;
								else if(studentnum[j]>=61 && studentnum[j]<=70)
										rng7++;
						else if(studentnum[j]>=71 && studentnum[j]<=80)
								rng8++;
				else if(studentnum[j]>=81 && studentnum[j]<=90)
						rng9++;
		else if(studentnum[j]>=91 && studentnum[j]<=100)
				rng10++;
	}

	totalval=rng1+rng2+rng3+rng4+rng5+rng6+rng7+rng8+rng9+rng10;

	cout<<"Range \t Histogram"<<endl;
	cout<<"==========================="<<endl;
	cout<<"1-10 \t|";
	printStars(rng1/5);
	cout<<"11-20 \t|";
	printStars(rng2/5);
	cout<<"21-30 \t|";
	printStars(rng3/5);
	cout<<"31-40 \t|";
	printStars(rng4/5);
	cout<<"41-50 \t|";
	printStars(rng5/5);
	cout<<"51-60 \t|";
	printStars(rng6/5);
	cout<<"61-70 \t|";
	printStars(rng7/5);
	cout<<"71-80 \t|";
	printStars(rng8/5);
	cout<<"81-90 \t|";
	printStars(rng9/5);
	cout<<"91-100 \t|";
	printStars(rng10/5);

	cout<<endl<<endl;
	//(c)
	cout<<"-----------------------------------------------------------------------"<<endl;

	cout<<"List of invalid numbers, 5 per line; "<<endl<<endl;
	int inval=0;

	for (int i= 0; i<= count-1 ;i++){

		if(studentnum[i]<1 || studentnum[i]>100){  //c
			inval++;
			cout<<studentnum[i]<<" ";
			countInval++;
        if(countInval==5){
		    cout<<endl;
		    countInval=0;

		}
			
		}

		if(studentnum[i]==0){
			notreveal++;
		}

	}
	
	cout<<endl<<endl;
	//(e)
	cout<<"-----------------------------------------------------------------------"<<endl;
	cout<<"The amount of students who specified valid favourite numbers are: "<<totalval<<endl;
	cout<<"The amount of students who specified invalid favourite numbers are: "<<inval<<endl;
	cout<<"The amount of students who did not reveal their favourite number being(0)are: "<<notreveal<<endl;



	cout<<endl<<endl;


	for (int i = 0; i <=count; i++) {

  // look to the left in the array if the number was used before
  int found = 0;
  for (int j = 0; j < i; j++) {
    if (studentnum[i] == studentnum[j])
	found++;
  }

  // go on if it's the first occurance
  if (found == 0 && studentnum[i]>=1 && studentnum[i]<=100) {

    // we know of one occurance
    int frequent = 1;

    // look to the right in the array for other occurances
    for (int j = i + 1; j < count; j++) {
      if (studentnum[i] == studentnum[j])
	   frequent++;
    }

    cout<<"The valid number " << studentnum[i]<<" was chosen" << ": " << frequent<<" times."<< endl; 
    
    
	 }
}



	return 0;
}
