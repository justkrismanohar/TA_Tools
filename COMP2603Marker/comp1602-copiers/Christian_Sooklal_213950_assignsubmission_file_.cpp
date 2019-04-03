#include <iostream>
#include <fstream>
using namespace std;

bool perf(int no){
	int a = 0;
	int total;
	
	for (a=1;a<no/2;a=1+a){
		if(no%a==0){
			total = a+total;
		}
	}
	if(total==no){
		return true;
	}
	return false;
}

bool pri(int no){
	int a = 0;
	for (a=2;a<=no/2;a=1+a){
		if(no%a==0){
			return false;
		}
	}
	return true;
}

bool perfsq(int no){
	int a = 0;
	
	for(a=1;a<=no/2;a=1+a){
		if (a*a==no){
			return true;
		}
	}
	return false;
}

bool sphenic(int no){
	int pqr = 0;
	int a = 0;
	int prod = 1;
	for (a=2;a<=no/2;a=1+a){
		if(no%a==0&&pri(a)){
			prod = a * prod;
			pqr = 1 + pqr;
		}
	}
	if (pqr==3&prod==no){
		return true;
	}
	return false;
}

void birep(int no){
	int a = 0;
	int b = 0;
	int bits[8]={0};
	
	b = no;
	
	for(a=0;b>0;a=a+1){
		bits[a] = b%2;
		b=b/2;
	}
	cout << "\t\t";
	for (a=7;a>=0;a=a-1){
		cout << bits[a];
	}
}

void Histogram (int mnrg, int mxrg, int valid[], int novalid){
	int a = 0;
	int ct = 0;
	for(a=0;a<=novalid;a=1+a){
		if (valid[a]>=mnrg&&valid[a]<=mxrg){
			ct = ct + 1;
			if (ct%5==0){
				cout<<"*";
			}
			
		}
	}
	cout << endl;
}

int main ()
{
	ifstream read;
	
	int x = 0;
	int no = 0;
	int a = 0;
	
	int valid[500];
	int notvalid[500];
	int file[500];
	int rpts[100] = {0};
	
	int vts = 0;
	int lstvts = 9999;
	int novalid = 0;
	int noinvalid = 0;
	int nochoice = 0;
	int dst = 0;
	
	read.open("numbers.txt");
	
	read >> no;
	while (no!=-1)
	{
		file[a] = no;
		a = 1 + a;
		read >> no;
	}
	
	for (x=0;x<=a-1;x=1+x)
	{
		if (file[x]==0)
		{
			nochoice = 1 + nochoice;
		}
		else if (file[x]<0||file[x]>100)
		{
			notvalid[noinvalid] = file[x];
			noinvalid = noinvalid + 1;
		}
		else if (file[x]>0||file[x]<=100)
		{
			valid[novalid]=file[x];
			novalid = 1 + novalid; 
		}
	}
	
	cout<<"Number\tPerfect?\tPrime\tPerfectSquare?\tSphenic?\tBinaryEqv."<<endl;
	cout<<"================================================================================================================="<<endl;
	
	for (a=0;a<novalid;a=1+a)
	{
		dst = valid[a];
		if (rpts[dst-1]==0){
			rpts[dst-1]=rpts[dst-1]=1;
			cout << dst;
			
			if(perf(dst)==0){
				cout<<"\t"<<"N";
			}
			if (pri(dst)==0){
				cout<<"\t\t"<<"N";
			}
			else{
				cout<<"\t\t"<<"Y";
			}
			
			if(perfsq(dst)==0){
				cout<<"\t"<<"N";
			}
			else{
				cout<<"\t"<<"Y";
			}
			
			if(sphenic(dst)==0){
				cout<<"\t\t"<<"N";
		    	}
		    	else{
		    		cout<<"\t\t"<<"Y";
				}
				
				birep(dst);
				cout<<endl;
		}
		else
		{
			rpts[dst-1]=rpts[dst-1]+1;
		}
	
	}
	
	cout<<endl;
	cout<<"invalid list of numbers:"<<endl;
	for (x=1; x <= noinvalid; x = x+1){
	if (x % 5 == 0){
	cout<<notvalid[x-1]<<endl;
}
 	else
    cout<<notvalid[x-1]<<" ";
}
cout<<endl<<endl;


cout<<"Range\t\tHistogram"<<endl;
cout<<"======================="<<endl;

cout <<" 1 - 10\t\t";
Histogram (1,10,valid,novalid);
cout <<" 11 - 20\t";
Histogram (11,20,valid,novalid);
cout <<" 21 - 30\t";
Histogram (21,30,valid,novalid);
cout <<" 31 - 40\t";
Histogram (31,40,valid,novalid);
cout <<" 41 - 50\t";
Histogram (41,50,valid,novalid);
cout <<" 51 - 60\t";
Histogram (51,60,valid,novalid);
cout <<" 61 - 70\t";
Histogram (61,70,valid,novalid);
cout <<" 71 - 80\t";
Histogram (71,80,valid,novalid);
cout <<" 81 - 90\t";
Histogram (81,90,valid,novalid);
cout <<" 91 - 100\t";
Histogram (91,100,valid,novalid);

for (a=0; a<100; a = 1+a){
	if (rpts[a] > vts){
		vts=rpts[a];

	}
}

for (a=0; a<=100; a = 1+a){
	if (rpts[a] < lstvts && rpts[a] != 0){
		lstvts = rpts[a];
	}
}



cout<<endl<<endl;
cout<<"Students Who Did Not Choose : "<<nochoice<<endl;
cout<<" no. of Valid Choices : "<<novalid<<endl;
cout<<" no. of Invalid Choices : "<<noinvalid<<endl;
cout<<"Number most voted : ";
for (a=0; a<100; a = 1+a){
	if (rpts[a] == vts){
		cout<<a+1<<" ";
	}
}
cout<<endl<<"Number least voted : ";
for (a=0; a<100; a = 1+a){
	if (rpts[a] == lstvts){
		cout<<1+a<<" ";
	}
}



read.close();

return 0;

}	


