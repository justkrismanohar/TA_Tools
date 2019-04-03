# include <iostream>
# include <fstream>
# include <cstring>
# include <cmath>
using namespace std;



bool primenumber(int num){
		int i;
	char prime;
	int y=89;
    int n=78;
		
		bool isprime=true; //prime number
    	for(i=2;i<=num/2;++i){
			if(num%i==0){
				isprime = false;
			}
		}
		if(isprime==true){
			prime=(char)y;
		}else{
			prime=(char)n;		
		}
		cout<<prime;
		return 0;
}

int perfectnumber(int num){
	int j=1, sum=0;
	char perfect;
	int y=89;
    int n=78;
	
	while(j<num){  //perfect number
			if(num%j==0)
			sum=sum+j;
			j++;
		}
		if(sum==num){
			perfect=(char)y;
		}else{
			perfect=(char)n;
		}
		cout<<perfect;
		return 0;
}

int perfectsquare(int num){
	int q=1, w=1;
	char square;
	int y=89;
    int n=78;
    
    while(q<num){//perfect square
			w++;
			q=w*w;
		}
		if(q==num){
			square=(char)y;
		}else{
			square=(char)n;
		}
		cout<<square;
		return 0;
}

int main(){
	int valid, invalid;
	int count1,count11,count21,count31,count41,count51,count61,count71,count81,count91;
	int countx,count2,count3,count4,count5,count6,count7,count8,count9,count10;
	int bin,rem ,a=1,no,c;
	int num, x, count, arr[1000];
	char y[]="y";
    char n[]="n";
    char perfect[1];
    char prime[1];
    char square[1];
	ofstream output;
	output.open("numbers.txt");
	
	while(num!=-1){
		cout<<"Enter your favourite number from 1 to 100: "<<endl;
		cin>>num;
		count++;
		output<<num<<endl;
		
		
		
		if(num>0 && num<11){
			count1++;
		}
		if(num>10 && num<21){
			count11++;
		}
		if(num>20 && num<31){
			count21++;
		}
		if(num>30 && num<41){
			count31++;
		}
		if(num>40 && num<51){
			count41++;
		}
		if(num>50 && num<61){
			count41++;
		}
		if(num>60 && num<71){
			count61++;
		}
		if(num>70 && num<81){
			count71++;
		}
		if(num>80 && num<91){
			count81++;
		}
		if(num>90 && num<101){
			count91++;
		}
		
	
		
		if(num > 0 && num < 101){
	 		valid++;
		 }
		else{
			invalid++;
	}                              
	
	}
	
	

	ifstream read;
	read.open("numbers.txt");
	cout<<"Number"<<"\t"<<"Perfect?"<<"\t"<<"Prime?"<<"\t"<<"Perfect Square?"<<"\t"<<"Sphenic?"<<"\t"<<"Binary Equiv."<<endl;
	cout<<"======"<<"\t"<<"========"<<"\t"<<"======"<<"\t"<<"==============="<<"\t"<<"========"<<"\t"<<"============="<<endl;
	 for(x=2;x<count;x++){
	 	read>>arr[x];
	 	cout<<arr[x]<<"\t"<<perfect<<"\t"<<prime<<"\t"<<square<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<bin<<endl;

	 	for(int u=0; u<count; u++){
	 		if(arr[u]>num){
	 			num=arr[u];
			 }
		 }
	 }
	 	
		int r;
		for(r=0; r<count; r++){
			cout<<arr[num]<<" ";
			if((num+1)%5==0){
				cout<<endl;
			}
		}

	cout<<endl;
	cout<<"Range"<<"\t"<<"histogram"<<endl;
	cout<<"=================="<<endl;
	
	cout<<"1-10"<<"\t"<<"|";
	count1=count1/5;
	for(countx=0;countx<count1;countx++){
		cout<<"*";
	}
	cout<<endl;
	
	cout<<"11-20"<<"\t"<<"|";
	count11=count11/5;
	for(count2=0;count2<count11;count2++){
		cout<<"*";
	}	
	cout<<endl;
	
	cout<<"21-30"<<"\t"<<"|";
	count21=count21/5;
	for(count3=0;count3<count21;count3++){
		cout<<"*";
	}	
	cout<<endl;
	
	cout<<"31-40"<<"\t"<<"|";
	count31=count31/5;
	for(count4=0;count4<count31;count4++){
		cout<<"*";
	}	
	cout<<endl;
	
	cout<<"41-50"<<"\t"<<"|";
	count41=count41/5;
	for(count5=0;count5<count41;count5++){
		cout<<"*";
	}	
	cout<<endl;
	
	cout<<"51-60"<<"\t"<<"|";
	count51=count51/5;
	for(count6=0;count6<count51;count6++){
		cout<<"*";
	}		
	cout<<endl;
	
	cout<<"61-70"<<"\t"<<"|";
	count61=count61/5;
	for(count7=0;count7<count61;count7++){
		cout<<"*";	
	}
	cout<<endl;
	
	cout<<"71-80"<<"\t"<<"|";
	count71=count71/5;
	for(count8=0;count8<count71;count8++){
		cout<<"*";	
	}	
	cout<<endl;
	cout<<"81-90"<<"\t"<<"|";
	count81=count81/5;
	for(count9=0;count9<count81;count9++){
		cout<<"*";	
	}	
	cout<<endl;
	cout<<"91-100"<<"\t"<<"|";
	count91=count91/5;
	for(count10=0;count10<count91;count10++){
		cout<<"*";	
	}	
	cout<<endl;
	
	cout<<"===================================="<<endl;
	cout<<"Number of valid numbers: "<<valid<<endl;
	cout<<"Number of Invalid numbers: "<<invalid<<endl;
	
	read.close();
	output.close();
}

long long dtob(int num){
	
    long long bin = 0;
    int rem, a = 1, step = 1;

    while (num!=0)
    {
        rem = num%2;
        num /= 2;
        bin += rem*a;
        a *= 10;
    }
    cout<<bin;
}

