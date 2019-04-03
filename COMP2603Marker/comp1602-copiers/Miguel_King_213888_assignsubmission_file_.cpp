#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

bool IsPerfect(int num);
bool IsPrime(int num);
bool IsPerfectSquare(int num);
bool IsSphenic(int num);
void binary(void);
void histo(void);

int binHold=0,binPoint=0,LN=0;
int bin[8]={'0','0','0','0','0','0','0','0'},Harr[10],Nums[101],invArr[101];
int num,Numbers=0,Scount=0,Vcount=0,Mpop=0,Lpop=999,InvCount=0,InvPoint=0,HidCount=0;
int w=0,x=0,y=0,z=0;
bool uniq=false;


bool IsPrime(int num){
	int i=0;
	for(i=2;i<num/2;i++){
		if( (num%num==0) && (num%1==num) ){
			return true;
		}else{
			return false;
		}
	}
}

bool IsPerfectSquare(int num){
	int square,i;
	for(i=1;i<=num;i++){
		square=i*i;
		if(square==num){
			return true;
		}else{
			return false;
		}
	}
}

bool IsSphenic(int num){
	int x,count=0,prod=1;
	int h=num/2;
	for(x=2;x<=h;x++){
		if(num%x==0 && IsPrime(x)){
			prod=prod*x;
			count++;
		}
	}

	if(count==3 && prod==num){
		return true;
	}else{
		return false;
	}
}

bool IsPerfect(int num){
	int i,sum=0;
	for(i=1;i<num;i++){
		if(num%i==0){
			sum+=i;
		}
	}
		if(sum==num){
			return true;
		}
			return false;
}

void Binary(int num){
	binHold=num;
	while(binHold!=0 || binPoint<7){
		bin[binPoint]= (binHold%2);
		binHold=(binHold/2);
		binPoint++;
	}
}

int main () {

    int i;
    for(i=0; i<100; i++)
    {
        Nums[i] = 0;
    }

    ifstream in;
    in.open("numbers.txt");

	if(!(in.is_open())){
		cout<<"Error File Cannot Be Found.... Aborting"<<endl;
		return 0;
	}

	cout<<"Number \t"<<"Perfect \t"<<"Prime \t"<<"Perfect Square \t"<<"Sphenic \t"<<"Binary Equiv \t"<<endl;
	cout<<"====== \t"<<"======= \t"<<"===== \t"<<"============== \t"<<"======= \t"<<"============="<<endl;

	in >> num;
	Numbers=num;
	while(num!=-1){
		Scount=Scount+1;

		if(num<=100 && num>=1){
			Vcount=Vcount+1;
			if(num>=1&& num<=10){
				Harr[0]++;
			}
			if(num>=11 && num<=20){
				Harr[1]++;
			}
			if(num>=21 && num<=30){
				Harr[2]++;
			}
			if(num>=31 && num<=40){
				Harr[3]++;
			}
			if(num>=41 && num<=50){
				Harr[4]++;
			}
			if(num>=51 && num<=60){
				Harr[5]++;
			}
			if(num>=61 && num<=70){
				Harr[6]++;
			}
			if(num>=71 && num<=80){
				Harr[7]++;
			}
			if(num>=91 && num<=100){
				Harr[9]++;
			}

			if(Nums[num]==0){
				uniq=true;
			}

			Nums[num]++;

			if(uniq==true){
				num=Numbers;

				/*IsPerfect(num);

				num=Numbers;
				IsPrime(num);

				num=Numbers;
				IsPerfectSquare(num);

				num=Numbers;
				IsSphenic(num);

				num=Numbers;
				Binary(num);
                */
				cout<<Numbers<<"\t";

				if(IsPerfect(num)==true){
					cout<<"Y"<<"\t";
				}else{
					cout<<"N"<<"\t";
				}
				if(IsPrime(num)==true){
					cout<<"Y"<<"\t";
				}else{
					cout<<"N"<<"\t";
				}
				if(IsPerfectSquare(num)==true){
					cout<<"Y"<<"\t";
				}else{
					cout<<"N"<<"\t";
				}
				if(IsSphenic(num)==true){
					cout<<"Y"<<"\t";
				}else{
					cout<<"N"<<"\t";
				}
				for(x=0;x<7;x++){
					cout<<bin[x];
				}
				cout<<endl;
			}
		}
		if(num==0){
			HidCount=HidCount+1;
		}
		if(num>100 || num<=-2){
			InvCount=InvCount+1;
			InvPoint=InvPoint+1;
			invArr[InvPoint]=num;
		}
		binPoint=0;

		for(y=0;y<7;y++){
			bin[y]=0;
		}
		uniq=false;

		in>>num;
		Numbers=num;
	}

	for(z=0;z<=100;z++){
		if( (Nums[z]>Mpop) && (Nums[z]> 1) ){
			Mpop=z;
		}else if( (Nums[z]<Lpop) && (Nums[z]>0) ){
			Lpop=z;
		}
	}

	if(InvPoint==0){
		cout<<endl;
		cout<<"There were no invalid numbers";
		cout<<endl;
	}else{
		cout<<endl;
		cout<<"The Invalid  Numbers are:"<<endl;

		for(w=1;w<=InvPoint;w++){
			cout<<invArr[w]<<"  ";
			LN=LN+1;
			if(LN%5==0){
				cout<<endl;
			}
		}
	}
	cout<<endl<<endl<<endl;
	cout<<"\t \t \t RANGE \t \t HISTOGRAM"<<endl;
	cout<<"\t \t \t --------------------------"<<endl;
	cout<<"\t \t \t 1-10 \t \t ";
	while(Harr[0]!=0){
		if(Harr[0]%5==0){
			cout<<"*";
		}
		Harr[0]=Harr[0]-1;
		cout<<endl;
	}
	cout<<"\t \t \t 11-20 \t \t";
	while(Harr[1]!=0){
		if(Harr[1]%5==0){
			cout<<"*";
		}
		Harr[1]=Harr[1]-1;
		cout<<endl;
	}
	cout<<"\t \t \t 21-30 \t \t";
	while(Harr[2]!=0){
		if(Harr[2]%5==0){
			cout<<"*";
		}
		Harr[2]=Harr[2]-1;
		cout<<endl;
	}
	cout<<"\t \t \t 31-40 \t \t";
	while(Harr[3]!=0){
		if(Harr[3]%5==0){
			cout<<"*";
		}
		Harr[3]=Harr[3]-1;
		cout<<endl;
	}
	cout<<"\t \t \t 41-50 \t \t";
	while(Harr[4]!=0){
		if(Harr[4]%5==0){
			cout<<"*";
		}
		Harr[4]=Harr[4]-1;
		cout<<endl;
	}
	cout<<"\t \t \t 51-60 \t \t";
	while(Harr[5]!=0){
		if(Harr[5]%5==0){
			cout<<"*";
		}
		Harr[5]=Harr[5]-1;
		cout<<endl;
	}
	cout<<"\t \t \t 61-70 \t \t";
	while(Harr[6]!=0){
		if(Harr[6]%5==0){
			cout<<"*";
		}
		Harr[6]=Harr[6]-1;
		cout<<endl;
	}
	cout<<"\t \t \t 71-80 \t \t";
	while(Harr[7]!=0){
		if(Harr[7]%5==0){
			cout<<"*";
		}
		Harr[7]=Harr[7]-1;
		cout<<endl;
	}
	cout<<"\t \t \t 81-90 \t \t";
	while(Harr[8]!=0){
		if(Harr[8]%5==0){
			cout<<"*";
		}
		Harr[8]=Harr[8]-1;
		cout<<endl;
	}
	cout<<"\t \t \t 91-100 \t \t";
	while(Harr[9]!=0){
		if(Harr[9]%5==0){
			cout<<"*";
		}
		Harr[9]=Harr[9]-1;
		cout<<endl;
	}
	cout<<"\t \t \t --------------------------";
	cout<<endl<<endl<<endl;
	cout<<"Number of Students:" <<Scount<<endl;
	cout<<"Valid Numbers:"<<Vcount<<endl;
	cout<<"Invalid  Numbers:"<<InvCount<<endl;
	cout<<"Unrevealed Numbers:"<<HidCount<<endl;
	cout<<"Most Popular Number:"<<Mpop<<endl;
	cout<<"Least Popular Number:"<<Lpop<<endl;

	in.close();
	return 0;
}
