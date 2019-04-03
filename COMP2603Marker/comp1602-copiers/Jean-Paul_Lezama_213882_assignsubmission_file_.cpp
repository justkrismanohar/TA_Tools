#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


using namespace std;

void prime(int num){
	if (num%2==0)
	 cout<<"T";
	else 
	 cout<<"F";
	
}

void perfect (int num){
	int sum;
 	for(int i;i<num;i=i+1){
    	if(num%i==0)
        	sum=sum+i;
	}
	if(sum==num)
    cout <<"T"; 
	else
    cout <<"F";
}

void persq(int num){
	int sum,div;
	for (int i=1; i < num; i++){
    div= num % i;
    if (div == 0)
    sum= sum + i;
    }
    if (sum==num)
    cout << "T";
    else
    cout << "F";
}

void sp(int num){
	
	if (num==30)
	cout<<"T";
	else if (num==42)
	cout<<"T";	
	else if (num==66)
	cout<<"T";
	else if (num==70)
	cout<<"T";	
	else if (num==78)
	cout<<"T";	
		
	else
	cout<<"F";
}

void hist1(int c1){
	int print, rem;
	print= (c1/5);
	rem=(c1%5);
	for(int i=1;i<=print;i=i+1){
	cout<<"*";
	}
	for(int a=1;a<=rem;a=a+1){
	cout<<"|";
	}	
}

void hist2(int c2){
	int print, rem;
	print= (c2/5);
	rem=(c2%5);
	for(int i=1;i<=print;i=i+1){
	cout<<"*";
	}
	for(int a=1;a<=rem;a=a+1){
	cout<<"|";
	}	
}

void hist3(int c3){
	int print, rem;
	print= (c3/5);
	rem=(c3%5);
	for(int i=1;i<=print;i=i+1){
	cout<<"*";
	}
	for(int a=1;a<=rem;a=a+1){
	cout<<"|";
	}	
}

void hist4(int c4){
	int print, rem;
	print= (c4/5);
	rem=(c4%5);
	for(int i=1;i<=print;i=i+1){
	cout<<"*";
	}
	for(int a=1;a<=rem;a=a+1){
	cout<<"|";
	}	
}

void hist5(int c5){
	int print, rem;
	print= (c5/5);
	rem=(c5%5);
	for(int i=1;i<=print;i=i+1){
	cout<<"*";
	}
	for(int a=1;a<=rem;a=a+1){
	cout<<"|";
	}	
}

void hist6(int c6){
	int print, rem;
	print= (c6/5);
	rem=(c6%5);
	for(int i=1;i<=print;i=i+1){
	cout<<"*";
	}
	for(int a=1;a<=rem;a=a+1){
	cout<<"|";
	}	
}

void hist7(int c7){
	int print, rem;
	print= (c7/5);
	rem=(c7%5);
	for(int i=1;i<=print;i=i+1){
	cout<<"*";
	}
	for(int a=1;a<=rem;a=a+1){
	cout<<"|";
	}	
}

void hist8(int c8){
	int print, rem;
	print= (c8/5);
	rem=(c8%5);
	for(int i=1;i<=print;i=i+1){
	cout<<"*";
	}
	for(int a=1;a<=rem;a=a+1){
	cout<<"|";
	}	
}

void hist9(int c9){
	int print, rem;
	print= (c9/5);
	rem=(c9%5);
	for(int i=1;i<=print;i=i+1){
	cout<<"*";
	}
	for(int a=1;a<=rem;a=a+1){
	cout<<"|";
	}	
}

void hist10(int c10){
	int print, rem;
	print= (c10/5);
	rem=(c10%5);
	for(int i=1;i<=print;i=i+1){
	cout<<"*";
	}
	for(int a=1;a<=rem;a=a+1){
	cout<<"|";
	}	
}

void deci_binary(int num){
	int deci[99],i;
	for(int i=0; num>0; i=i+1){    
	deci[i]=num%2;    
	num= num/2;  
	}
	cout<<deci[i];    
	
}

int main(){
	
	ifstream in;
	ofstream out;
	
	in.open ("numbers.txt");
	if(!in.is_open()){
	cout<<"Error opening file"<<endl;
	return 0;
	}
	
	else
	out.open("output.txt");
	int num;
	int invalid_num=0;
	int valid_num=0;
	int no_reveal=0;
	int c1=0;
	int c2=0;
	int c3=0;
	int c4=0;
	int c5=0;
	int c6=0;
	int c7=0;
	int c8=0;
	int c9=0;
	int c10=0;
	int i=0;
	int count=1;
	int sum = 0;
	int invalid[999];
	in>>num;
	cout<<"Number	Perfect?  Prime?   Perfect Square?    Sphenic?   Binary Equivalent"<<endl;
	cout<<"=======	========  ======   ===============    ========    ================="<<endl;
	cout<<""<<endl;
	while(num!=-1){
	
		cout<<num<<"	";
		perfect(num);
		cout<<"         ";
		prime(num);
		cout<<"        ";
		persq(num);
		cout<<"                  ";
		sp(num);
		cout<<endl;
		
		if((num< -1) || (num> 100)){
			i=i+1;
			invalid[i]=num;
			invalid_num=invalid_num+1;
		}
		
		if((num>=1) && (num<=10)){
			c1=c1+1;
		}
		
		else if((num>=11) && (num<=20)){
			c2=c2+1;
		}
		
		else if((num>=21) && (num<=30)){
			c3=c3+1;
		}
		
		else if((num>=31) && (num<=40)){
			c4=c4+1;
		}
		
		else if((num>=41) && (num<=50)){
			c5=c5+1;
		}
		
		else if((num>=51) && (num<=60)){
			c6=c6+1;
		}
		
		else if((num>=61) && (num<=70)){
			c7=c7+1;
		}
		
		else if((num>=71) && (num<=80)){
			c8=c8+1;
		}
		
		else if((num>=81) && (num<=90)){
			c9=c9+1;
		}
		
		else if((num>=91) && (num<=100)){
			c10=c10+1;
		}
		in>>num;
		
		valid_num=valid_num+1;
		if(num==0){
		no_reveal=no_reveal +1;
		}
}

cout<<""<<endl;
cout<<"Invalid Numbers: "<<endl;
while(i>-1){
cout<<invalid[i]<<"  "<<invalid[i-1]<<"  "<<invalid[i-2]<<"  "<<invalid[i-3]<<"  "<<invalid[i-4]<<"  "<<endl;
i=i-5;

}

cout<<endl;
cout<<"Range   "<<"Histogram"<<endl;
cout<<"====================="<<endl;
cout<<"1-10    ";
hist1(c1);
cout<<endl;
cout<<"11-20   ";
hist2(c2);
cout<<endl;
cout<<"21-30   ";
hist3(c3);
cout<<endl;
cout<<"31-40   ";
hist4(c4);
cout<<endl;
cout<<"41-50   ";
hist5(c5);
cout<<endl;
cout<<"51-60   ";
hist6(c6);
cout<<endl;
cout<<"61-70   ";
hist7(c7);
cout<<endl;
cout<<"71-80   ";
hist8(c8);
cout<<endl;
cout<<"81-90   ";
hist9(c9);
cout<<endl;
cout<<"91-100  ";
hist10(c10);



cout<<endl;

cout<<"Number of Invalid Numbers= "<<invalid_num<<endl;
cout<<"Number of Valid Numbers= "<<valid_num<<endl;
cout<<no_reveal<< " Students did not reveal their number"<<endl;

return 0;
}
