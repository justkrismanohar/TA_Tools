#include <iostream>
#include <fstream>
using namespace std;

bool is_perfect(int fav_num){
	int a=0,i,a1;
	
	for(i=1;i<fav_num;i=i+1){

        a1 = fav_num % i;
        if (a1 == 0)
            a = a + i;
    }
    if (a == fav_num)
			return true;
		return false;		
	

}

bool is_prime(int fav_num){
	int  b=0,i;
	for(i=2;i<fav_num;i=i+1){
		if(fav_num%i==0)
			b=b+1;	
	}
	if(b>1)
		return false;
	return true;
}

bool is_p_square(int fav_num){

	
	int c=1,i=1;
	while(c<fav_num)
	{
		i++;
		c=i*i;
	}
	
	if(c==fav_num)
		return true;
		return false;

}

bool is_sphenic(int fav_num){
	int d,i;
	for(i=2;i<=fav_num/2;i=i+1)
		if((d%i==0)&&is_prime(i)){
		d=d*i;
		if(d==fav_num)
			return true;
			return false;
		}
}
int binary(int fav_num){

	int e[50],i=0,ee=0;
	
	while(i!=0){
		e[ee]=fav_num%2;
		i=i/2;
		ee=ee+1;
	}
	return e[ee];
	
	}

void star(int f){
	int g;
	for(g=1;g<=f;g=g+1){
		cout<<"*";
	}
}

		


int main(){


	ifstream file_in; 
	
	int fav_num,valid=0,invalid=0,count=0,no_reveal=0,most=1,least=10000,f;
	int range_1=0,range_2=0,range_3=0,range_4=0,range_5=0,range_6=0,range_7=0,range_8=0,range_9=0,range_10=0;
	bool perfect,prime,square,sphenic,binary_num;
	file_in.open("numbers.txt");
	file_in>>fav_num;
	
	cout<<"Number   Perfect?   Prime?   Perfect?   Sphenic?    Binary Equiv."<<endl;
	cout<<"======   ========   ======   ========   ========    ============="<<endl;
	
	
	
	
	while(fav_num!=-1){
		if((fav_num>0)&&(fav_num<=100)){
			cout<<fav_num<<"        ";
			perfect=is_perfect(fav_num);
			if(perfect==true)
			cout<<"Y          ";
			else
			cout<<"N          ";
			prime=is_prime(fav_num);
			if(prime==true)
			cout<<"Y          ";
			else
			cout<<"N          ";
			square=is_p_square(fav_num);
			if(prime==true)
			cout<<"Y          ";
			else
			cout<<"N          ";
			sphenic=is_sphenic(fav_num);
			if(sphenic==true)
			cout<<"Y          ";
			else
			cout<<"N          ";
			binary_num=binary(fav_num);
			cout<<binary_num<<"          "<<endl;
			
			valid=valid+1;

			}
		
			file_in>>fav_num;
	}
	file_in.close();
		file_in.open("numbers.txt");
	file_in>>fav_num;

		while(fav_num!=-1){
		
		if((fav_num<-2)||(fav_num>100)){
			invalid=invalid+1;
			cout<<fav_num<<" ";
			if(count%5==0)
				cout<<endl;	
			count=count+1;
		}
				if(fav_num==0)
			no_reveal=no_reveal+1;		
     	file_in>>fav_num;
		}
	file_in.close();
	file_in.open("numbers.txt");
	file_in>>fav_num;
	cout<<endl<<endl<<"Range     Histogram"<<endl;
	cout<<"==================="<<endl;

	while(fav_num!=-1){
		
		if((fav_num>0)&&(fav_num<=100)){
			if((fav_num>=1)&&(fav_num<=10))
				range_1=range_1+1;
			else if((fav_num>=11)&&(fav_num<=20))
				range_2=range_2+1;
			else if((fav_num>=21)&&(fav_num<=30))
				range_3=range_3+1;
			else if((fav_num>=31)&&(fav_num<=40))
				range_4=range_4+1;
			else if((fav_num>=41)&&(fav_num<=50))
				range_5=range_5+1;
			else if((fav_num>=51)&&(fav_num<=60))
				range_6=range_6+1;
			else if((fav_num>=61)&&(fav_num<=70))
				range_7=range_7+1;
			else if((fav_num>=71)&&(fav_num<=80))
				range_8=range_8+1;
			else if((fav_num>=81)&&(fav_num<=90))
				range_9=range_9+1;
			else if((fav_num>=91)&&(fav_num<=100))
				range_10=range_10+1;
			}
		
	file_in>>fav_num;
	}
	;
	cout<<"1-10      ";
	f=range_1/5;
	star(f);

	cout<<endl;
	
	cout<<"11-20      ";
	f=range_2/5;
	star(f);
	cout<<endl;
    
    cout<<"21-30      ";
	f=range_3/5;
	star(f);
	cout<<endl;
	
	cout<<"31-40      ";
	f=range_4/5;
	star(f);
	cout<<endl;
		
	cout<<"41-50      ";
	f=range_5/5;
	star(f);
	cout<<endl;
	
	
	cout<<"51-60      ";
	f=range_6/5;
	star(f);
	cout<<endl;
	
	cout<<"61-70      ";
	f=range_7/5;
	star(f);
	cout<<endl;
    
	cout<<"71-80      ";
	f=range_8/5;
	star(f);
	cout<<endl;
    
	cout<<"81-90      ";
	f=range_9/5;
	star(f);
	cout<<endl;
    
	
	cout<<"91-100      ";
	f=range_10/5;
	star(f);
	cout<<endl;
    
			
	cout<<endl<<"Number of valid "<<valid<<endl<<"Number of Invalid "<<invalid<<endl<<"Number not revealed "<<no_reveal<<endl;
	file_in.close();
	return 0;
}

