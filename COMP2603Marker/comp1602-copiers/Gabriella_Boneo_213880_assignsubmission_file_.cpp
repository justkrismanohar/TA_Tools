#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool isperfect(int n){
	int sum=0,i;
		for (i=1;i<=n/2;i++){
			if (n%i==0)
   			sum=sum+i;
		}
			if (sum==n&&n!=1)
			return true;
 			return false;
		}



bool isPrime(int n){
	
    	for(int i = 2; i <= n / 2; i++) {
       		if(n % i != 0) 
       		return true;
   			return false ; 
			   
		}
    
		}



bool perfectsquare(int n)
{
	int square, i;
	for (i=1;i<=n/2;i=i+1){
		square=i*i;
		if (square==n)
		
	 return true; 
	
}
  
   	return false;
   
}

bool isSphenic(int n){
	int i,j,prod;
	j=0;
	prod=1;
	for(i=2;i<=n/2;i++){
		if(n%i==0&&isPrime(i)){
			prod=prod*i;
			j=j+1;
			
		}
	}
	if(j==3&&prod==n)
	return true;
	return false;
	
}
void Binary(int n) { 
    int bNum[100]; 
  
   int a;
   
   			int i = 0; 
    		int j;
   			while (n > 0) { 
        bNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    for(a=8;a>i;a--){
    	cout<<"0";
    	
	}
    for (j = i - 1; j >= 0; j--) 
        cout << bNum[j]; 
} 
  void star(int n){
  	int i;
  	for(i=0;i<n;i++)
  	cout<<"*";
  	cout<<endl;
  	
  }
int main(){
	bool a,b,c,n,d;
	int arr[10];
	int j,g=1,k=0,t,count=0,i;
	
	int invalidfav[999];
	int validfav[999];
	int nofav[999];
	int numinvalid;
	int num;
	int histogram[10];
	int favnum[101];
	
		ifstream fin;

	fin.open("numbers.txt");
			if (!fin.is_open()){
			cout << "Error opening output file. Aborting ...";
			return 0;
						} 
						
								

cout<<"Number\t   Perfect?\t    Prime?\t  Perfect Square?\tSphenic?\tBinary Equiv."<<endl;
cout<<"======\t   ========\t    ======\t  ===============\t========\t============"<<endl;

for(int e=1;e<=100;e++){
	favnum[e]=0;
}
	
fin>>num;



while(num!=-1){
if (num>=1&&num<=100){
	 
validfav[k]=num;
k=k+1;

favnum[num]++;

	
cout<<num<<"		";


a=isperfect(num);
if (a==true)
	cout<<"Y		";
	else
	cout<<"N		";
	
	
	c=isPrime(num);
	if(c==true)
		cout<<"Y		";
		else
		cout<<"N		";
	
		i=perfectsquare(num);
		if(i==true)
		cout<<"Y		";
		else
		cout<<"N		";
	
	d=isSphenic(num);
	if(d==true)
	cout<<"Y		";
	else 
	cout<<"N		";
		
Binary(num);
cout<<endl;
}
else if(num==0){
	nofav[t]=num;
	t=t+1;
	
}
else{
	
invalidfav[g]=num;
g=g+1;


}	
if(num>=1&&num<=10){
		histogram[0]++;
	
	}
		if(num>=11&&num<=20){
	
		histogram[1]++;
	}
		if(num>=21&&num<=30){
	
		histogram[2]++;
	}
		if(num>=31&&num<=40){
		histogram[3]++;
	}
		if(num>=41&&num<=50){
		histogram[4]++;
	}
		if(num>=51&&num<=60){
		histogram[5]++;
	}
		if(num>=61&&num<=70){
		histogram[6]++;
	}
		if(num>=71&&num<=80){
		histogram[7]++;
	}
		if(num>=81&&num<=90){
		histogram[8]++;
	}
		if(num>=91&&num<=100){
		histogram[9]++;
	}
	
	fin>>num;


}
cout<<"Invalid Numbers are: "<<endl;
for(int d=1;d<g;d++){
cout<<invalidfav[d]<<" ";
if(d%5==0  ){
	cout<<endl;
	
}

}
cout<<endl;
cout<<endl;


	


	cout<<"Range        Histogram"<<endl;
    cout<<"======================"<<endl;


cout<<"1-10\t	:";
histogram[0]=histogram[0]/5;
star(histogram[0]);


cout<<"11-20\t	:";
histogram[1]=histogram[1]/5;
star(histogram[1]);

cout<<"21-30\t	:";
histogram[2]=histogram[2]/5;
star(histogram[2]);

cout<<"31-40\t	:";
histogram[3]=histogram[3]/5;
star(histogram[3]);

cout<<"41-50\t	:";
histogram[4]=histogram[4]/5;
star(histogram[4]);


cout<<"51-60\t	:";
histogram[5]=histogram[5]/5;
star(histogram[5]);

cout<<"61-70\t	:";
histogram[6]=histogram[6]/5;
star(histogram[6]);

cout<<"71-80\t	:";
histogram[7]=histogram[7]/5;
star(histogram[7]);


cout<<"81-90\t	:";
histogram[8]=histogram[8]/5;
star(histogram[8]);

cout<<"91-100\t	:";
histogram[9]=histogram[9]/5;
star(histogram[9]);
cout<<endl;

    cout<<k<<"	students specified valid favourite numbers"<<endl;
	cout<<g<<"	students specified invalid favourite numbers"<<endl;
	cout<<t<<"	students didnot reveal their favourite number"<<endl;
	cout<<endl;
	
int max=favnum[1];
int min=1;
cout<<"The number that was chosen the most by the students: ";
cout<<endl;

for(int r=1;r<=100;r++)	{
	if(favnum[r]>max){
		max=favnum[r];	
	}
}
for(int r=1;r<100;r++){
	if(favnum[r]==max){
		cout<<r<<" ";
		
	}
}
cout<<endl;
cout<<endl;

cout<<"The numbers that were chosen the least by the students:";
cout<<endl;
for(int r=1;r<=100;r++)	{
	if(favnum[r]<min && favnum[r]>0){
		min=favnum[r];	
	}
}
for(int r=1;r<100;r++){
	if(favnum[r]==min){
		cout<<r<<" ";
		
	}
}
cout<<endl;
fin.close();	
return 0;

}


	

