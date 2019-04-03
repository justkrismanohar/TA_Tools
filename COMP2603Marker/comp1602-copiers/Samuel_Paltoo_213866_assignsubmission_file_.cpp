#include <iostream>
#include <fstream>
using namespace std;

bool per(int n) {
	
	if (n==6||n==28) 
	return true;
	else 
	return false;
}

bool pri(int n) {
	int i;
	for (i=2;n/2;i++) {
		if (n%i==0)
		return true;
		else
		return false;
	}
	
}
	bool persq(int n) {
	if (n==1||n==4||n==9||n==16||n==25||n==36||n==49||n==64||n==81||n==100)
	return true;
	else
	return false;
	}
	
	bool sph (int n) {
		if (n==30||n==42||n==66||n==70||n==78)
		return true;
		else 
		return false;
	}
	
	int bineq(int n) {
		int i, j, remain[64];
		j=0;
		while (n!=0) {
			remain[j]=n%2;
			n=n/2;
			j++;
		
		}
			for (i=j-1;i>=0;i--) {
				cout<<remain[i];
			}
		cout<<"\n";
		
	}

int main () {
	ifstream in;
	in.open("numbers.txt");
	if (!in.is_open()) {
		cout<<"\n Error opening up file\n Aborting...";
	}
	int perfect[15];
	int inval[4761],valid[4761],hidden,distinct[100], j, i,n,t,countval,countval1,count,countinval,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,q,fav,fir,z,a;
	int temp;
	j=i=t=n=count=countval=hidden=q=c1=c2=c3=c4=c5=c6=c7=c8=c9=c10=countval=a=countinval=0;
	in>>temp;
	while (temp!=-1) {
		if (temp==0) {
			hidden++;
		}
		
		if (temp>0 && temp<11) {
			c1++;
		}
		if (temp>10 && temp<21) {
			c2++;
		}
		if (temp>19 && temp<31) {
			c3++;
		}
		if (temp>30 && temp<41) {
			c4++;
		}
		if (temp>40 && temp<51) {
			c5++;
		}
		if (temp>50 && temp<61) {
			c6++;
		}
		if (temp>60 && temp<71) {
			c7++;
		}
		if (temp>70 && temp<81) {
			c8++;
		}
		if (temp>80 && temp<91) {
			c9++;
		}
		if (temp>90 && temp<101) {
			c10++;
		}
		
		if (temp<-1 || temp>100) {
			inval[j]=temp;
			countinval++;
			j++;
			
		}
		else 
		if (temp>0 && temp<101) {
		valid[i]=temp;
		countval++;
		i++;
	}
			in>>temp;
	}
	count=j+i;
	i=n=0;

	cout<<"Number\tPerfect?\tPrime?\t\tPerfect Square?\tSphenic?\tBinary equivalence\n";
	
		for (i=0;i<countval;i++) {
		n=valid[i];
		cout<<n<<"\t";
		
		per(n);
	
		if (per(n))
		cout<<"Yes\t\t";
		else
		cout<<"No\t\t";
		
		pri(n);
		
		if (pri(n))
		cout<<"Yes\t\t";
		else
		cout<<"No\t\t";
	
		persq(n);
		if (persq(n))
		cout<<"Yes\t\t";
		else
		cout<<"No\t\t";
		
		sph(n);
		if (sph(n))
		cout<<"Yes\t\t";
		else
		cout<<"No\t\t";
		
		bineq(n);
		
		
	}
				
	
		cout<<"\nInvalid numbers are as follows:\n\n";
		j=j-1;
		while (j>0) {
			if (j>=5) {
			cout<<inval[j]<<" "<<inval[j-1]<<" "<<inval[j-2]<<" "<<inval[j-3]<<" "<<inval[j-4]<<" \n";
			j=j-5;
		}
			else 
			if (j==4) {
			cout<<inval[j]<<" "<<inval[j-1]<<" "<<inval[j-2]<<" "<<inval[j-3]<<" \n";
			j=j-4;
		}
			else 
			if (j==3) {
			cout<<inval[j]<<" "<<inval[j-1]<<" "<<inval[j-2]<<" \n";
			j=j-3;
		}
			else
			if (j==2){
			cout<<inval[j]<<" "<<inval[j-1]<<" \n";
			j=j-2;
		}
			else 
			if (j==1){
			cout<<inval[j]<<" \n";
			j=j-1;
		}
			
		}
		
		cout<<"\nRange of numbers are as follows:\n";
		cout<<"\nRange\tHistogram(s)";
		cout<<"\n------------------------";
		cout<<"\n1-10\t";
		while (c1>=5) {
			cout<<"*";
			c1=c1-5;
		}
		cout<<"\n11-20\t";
		while (c2>=5) {
			cout<<"*";
			c2=c2-5;
		}
		cout<<"\n21-30\t";
		while (c3>=5) {
			cout<<"*";
			c3=c3-5;
		}
		cout<<"\n31-40\t";
		while (c4>=5) {
			cout<<"*";
			c4=c4-5;
		}
		cout<<"\n41-50\t";
		while (c5>=5) {
			cout<<"*";
			c5=c5-5;
		}
			cout<<"\n51-60\t";
		while (c6>=5) {
			cout<<"*";
			c6=c6-5;
		}
			cout<<"\n61-70\t";
		while (c7>=5) {
			cout<<"*";
			c7=c7-5;
		}
		cout<<"\n71-80\t";
		while (c8>=5) {
			cout<<"*";
			c8=c8-5;
		}
		cout<<"\n81-90\t";
		while (c9>=5) {
			cout<<"*";
			c9=c9-5;
		}
		cout<<"\n91-100\t";
		while (c10>=5) {
			cout<<"*";
			c10=c10-5;
		}
		cout<<"\nThe amount of student(s) who did not reveal their favorite number is/are "<<hidden;
		cout<<"\nThe amount of student(s) who specified their favorite number, and that particular number was valid is/are "<<countval;
		cout<<"\nThe amount of student(s) who specified and invalid number is/are "<<countinval;
	
	in.close();
	return 0;
}


