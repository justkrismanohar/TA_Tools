#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
ifstream inhere; 
ofstream outhere; 
int num;

bool isPerfect(int num){
	int i,sum=0;
	bool status = false;
		for (i=1;i<num;i++){
		
		if (num%i==0)
		sum=sum+i;
	}

	if (sum==num&&num!=0){
		status = true;
	}
	return status;
}

bool isPrime(int num){
	int p,count;
	bool status = false;
	for (p=1;p<=num;p++){
		if (num%p==0)
		{
		count=count+1;	
		}
		
	}
	if (count==2){
	status = true;
}
	return status;
	
}

bool isSquare(int num){
	int i,temp2;
	bool status = false;
	for (i=0;i<=num;i=i+1){
	if (i*i==num&&num!=0){
		status= true;
	}
}
	return status;
}	

bool isSphenic(int num){
	int p,i,count=0, scount=0, temp5=1;
	bool status = false;
	for (i=2; i<num; i++){
		if(num % i ==0){
			count=0;
				for (p=1;p<=i;p++){
				if (i%p==0)
				{
				count=count+1;	
				}
				}
				if (count==2){
					scount=scount+1;
					temp5=temp5*i;
				}
		}
	}
	if (temp5 == num&&scount==3)
	status = true;
	
	return status;
}

int binaryNumber(int num){
	int i,bcount=0,temp,g;
	int a[100000];
	for(i=0; num>0; i++)    
	{	    
	a[i]=num%2;    
	num= num/2;
	bcount=bcount+1; 
	temp=0; 
	}    
	for(i=i-1 ;i>=0 ;i--)    
	{
		if (temp==0){
		for(g=0;g<8-bcount;g++){
		cout<<"0";}}
	temp=1;
	cout<<a[i];    
	}
	bcount=0;   

}


int main(){
	string perstat,primestat,squarestat,nicstat ;
	bool decide;
	int thingy[10000],hey=-1,checker=0,inchk,hn=0,highestnumbers[10000],fullvalnumbers[100000],highestamounts[1000],binaryform[9],dummy,firstcount=0,highestcount=0,winner,zerocount=0,d,valcount,starcount,temp,ho=0,ha,allnumbers[1000],valnumbers[1000],z=0,excel=0,j,r,x,invalidnumbers[1000],incount=0,y,o=0;
	int lowestfirstcount, lowestdummy, icount, lowestcount=1000000, lwinner, lowestamounts[10000], lowestnumbers[10000], ln=0, lo;
	inhere.open("numbers.txt");
	if(!inhere.is_open()){
		cout<<"File was not found."<<endl<<"Please locate file and try again."<<endl;
		return 0;
	}
	cout<<"      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"                             CLASS FAVOURITE NUMBERS                         "<<endl;
	cout<<"      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
	inhere>>num;
	cout<<"Number Perfect? Prime? Perfect Square? Sphenic? Binary Equiv."<<endl;
	cout<<"====== ======== ====== =============== ======== ============="<<endl;
	while(num!=-1){
		
		if(num!=0){
		allnumbers[o]=num;
		o=o+1;
		lo=lo+1;
	}
		
		if (num>0&&num<101){
		fullvalnumbers[valcount]=num;
		valcount=valcount+1;
		
	}
		
		if (num==0)
		zerocount=zerocount+1;
		
		if (num<0||num>100){
			invalidnumbers[incount]=num;
			incount=incount+1;
		}
	valnumbers[z]=num;
		
		if(num!=0){
			for (x=z-1;x>=0;x--){
				if (valnumbers[x]==num){
					excel=1;
					}
			}
		}

	if (excel==0){	
	if(num>0&&num<101){

		if(num>0&&num<10){
		cout<<"0";	
		}
		if(num>0&&num<100)
		cout<<num<<"     ";
		else 
		cout<<num<<"    ";
		
	
	
	if (isPerfect(num)==true)
		perstat="T";
		else
		perstat="F";
		
	cout<<perstat;
	
	if (isPrime(num)==true)
		primestat="T";
		else
		primestat="F";
	
	if(num>0&&num<100)
	cout<<"         "<<primestat;
	else
	cout<<"         "<<primestat;
	
	if (isSquare(num)==true)
		squarestat="T";
		else
		squarestat="F";
		
	if(num>0&&num<100)
	cout<<"         "<<squarestat;
	else
	cout<<"         "<<squarestat;
	
	if (isSphenic(num)==true)
		nicstat="T";
		else
		nicstat="F";
	
	if(num>0&&num<100)
	cout<<"           "<<nicstat;
	else
	cout<<"           "<<nicstat;
	
	
	if(num>0&&num<100)
	cout<<"        ";
	else 
	cout<<"        ";
	binaryNumber(num);
	cout<<endl;
	z=z+1;
}	
}		
	excel=0;
	inhere>>num;
}
	
	cout<<endl<<endl<<"Invalid Numbers"<<endl;
	cout<<"==================="<<endl;
	
	for(y=1;y<=incount;y++){
		temp=1;
		thingy[y-1]=invalidnumbers[y-1];
		checker=0;
		for (inchk=0;inchk<=incount;inchk++){ 
		if (invalidnumbers[y-1]==thingy[inchk]){
			checker=checker+1;
			}
		}
		if (checker==1){
		cout<<invalidnumbers[y-1]<<" ";
		icount=icount+1;
		temp=0;
		}
		if(icount%5==0&&temp==0){
		cout<<endl;
		}
	}
	
	cout<<endl<<endl<<endl;
	cout<<"Range    Histogram"<<endl;
	cout<<"==================";
	for (ha=1;ha<92;ha=ha+10){
		temp=1;
		ho=ho+10;
		starcount=0;
		cout<<endl;
	for (r=0;r<1000;r++){
		if(fullvalnumbers[r]>=ha&&fullvalnumbers[r]<=ho){
		starcount=starcount+1;
		decide=true;}
			if(starcount%5==0&&decide==true){
					if (temp==1){
						if (ha<5){
						cout<<ha<<"-"<<ho<<"       |";	
						}
						if (ha>10&&ha<90){
						cout<<ha<<"-"<<ho<<"      |";
						}
						if (ha>90){
						cout<<ha<<"-"<<ho<<"     |";
						}
					temp=0;}
			cout<<"*";
		}
			decide=false;
		}
		}	
	
	cout<<endl<<endl<<valcount<<" students specified valid numbers";
	cout<<endl<<incount<<" students specified invalid numbers";
	cout<<endl<<zerocount<<" students did not reveal their favourite number";
	
	cout<<endl<<endl<<"Number(s) chosen the most by students: "<<endl;
	cout<<"======================================"<<endl;
	
	for (j=0;j<o;j++){
		firstcount=0;
		dummy=fullvalnumbers[j];
		
			for (d=0;d<valcount;d++){
				if (fullvalnumbers[d]==dummy){
					firstcount=firstcount+1;
				}
			}
		if (firstcount>=highestcount){
			highestcount=firstcount;
			winner=dummy;
			highestamounts[hn]=highestcount;
			highestnumbers[hn]=winner;
			hn=hn+1;
		}	
	}
	
	if (highestcount>1){
	for (j=0;j<=hn;j++){
		if(highestcount==highestamounts[j]){
			cout<<highestnumbers[j]<<"|";
				for (d=0;d<=hn;d++){
					if (highestnumbers[j]==highestnumbers[d])
					highestamounts[d]=0;
						
				}
		}
	}
	cout<<" ---- chosen "<<highestcount<<" time";
		if (highestcount>1)
		cout<<"s.";
	}
	else
	{
		cout<<"No number was chosen by at least 2 students";
	}
	
		
	
	
	
	
	
	cout<<endl<<endl<<"Number(s) chosen the least by students: "<<endl;
	cout<<"======================================"<<endl;
	
	for (j=0;j<lo;j++){
		lowestfirstcount=0;
		lowestdummy=fullvalnumbers[j];
		
			for (d=0;d<lo;d++){
				if (fullvalnumbers[d]==lowestdummy){
					lowestfirstcount=lowestfirstcount+1;
					}
			}
		if (lowestfirstcount<=lowestcount){
			lowestcount=lowestfirstcount;
			lwinner=lowestdummy;
			lowestamounts[ln]=lowestcount;
			lowestnumbers[ln]=lwinner;
			ln=ln+1;
		}	
	}
	
	if (lowestcount>0){
	for (j=0;j<=ln;j++){
		if(lowestcount==lowestamounts[j]){
			cout<<lowestnumbers[j]<<"|";
				for (d=0;d<=ln;d++){
					if (lowestnumbers[j]==lowestnumbers[d])
					lowestamounts[d]=0;
						
				}
		}
	}
	cout<<" ---- chosen "<<lowestcount<<" time"<<endl<<endl<<endl;
	if (lowestcount>1)
		cout<<"s.";
	}
	else
	{
		cout<<"No number was chosen by at least 1 student"<<endl<<endl<<endl;
	}
	
	
	
	
	

	inhere.close();
	return 0;
}
