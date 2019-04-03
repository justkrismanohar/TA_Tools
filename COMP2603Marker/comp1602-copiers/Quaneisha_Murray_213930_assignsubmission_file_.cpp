#include <iostream>
#include <fstream>
using namespace std;
char isPerfect(int arr[],int n){
	int i,sum=1;
	int p=arr[n];
	for(i=2;i<=p/2;i=i+1){
		if(p%i==0){
			sum=sum+i;
		}
	}
	if(sum==p&& sum!=1){
		return 'Y';
	}
	return 'N';
}
char isPrime(int arr[],int n){
	int i,r=0;
	int p=arr[n];
	for(i=2;i<=p/2;i=i+1){
		if(p%i==0){
			r=r+1;
		}
	}
	if(r==0&&p!=1){
		return 'Y';
	}
	return 'N';
}
char isPerfSq(int arr[],int n){
	int i,sq;
	int p=arr[n];
	for(i=1;i<=p/2;i=i+1){
		sq=i*i;
		if(sq==p){
			return 'Y';
		}
	}
	return 'N';
}
bool isPrime2(int p){
	int r=0;
	for(int i=2;i<=p/2;i=i+1){
		if(p%i==0){
			r=r+1;
		}
	}
	if(r==0&&p!=1){
		return true;
	}
	return false;
}
	
char isSphenic(int arr[], int n){
	int i,count=0,prod=1;
	int p = arr[n];
	bool prime;
	for(i=2;i<=p/2;i=i+1){
		prime=isPrime2(i);
		if(p%i==0 && prime==true){
			prod=prod*i;
			count=count+1;
		}
	}
	if(prod==p && count==3){
		return 'Y';
	}
	return 'N';
}
void Binary(int arr[], int n){
	int bin[8]={0,0,0,0,0,0,0,0};
	int i,rem;
	int p=arr[n];
	for(i=0;i<=7;i=i+1){
		rem=p%2;
		bin[i]=rem;
		p=p/2;
		cout<<bin[i];
	}
	
}
void printStars(int n){
	int i;
	for(i=1;i<=n/5;i=i+1){
		cout<<"*";
	}
	cout<<endl;
}
int main(){
	ifstream in;
	int fave[200];
	int fave_count[200];
	int invalid[200];
	int maxnum[200];
	int minnum[200];
	int distinct[200];
	int n,count=0,num=0,no_reveal=0,i,incr=0;
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,k=0,p,q=1,r=1,t;
	int max=2,min=200;
	bool found=false;
	char prime,sq,sph,perf;
	
	for(i=0;i<200;i=i+1){
		fave[i]=0;
		invalid[i]=0;
		fave_count[i]=0;
		maxnum[i]=0;
		minnum[i]=0;
		distinct[i]=0;
	}
	
	in.open("numbers.txt");
	if(!in.is_open()){
		cout<<"Error, file not found"<<endl;
		return 0;
	}
	
	in>>n;
	while(n!=-1){
		if(n<0 || n>100){
			invalid[num]=n;
			num=num+1;
			in>>n;
		}
		if(n==0){
			no_reveal=no_reveal+1;
			fave_count[0]=fave_count[0]+1;
			in>>n;
		}
		if(n>=1 && n<=100){
		fave[count]=n;
		fave_count[n]=fave_count[n]+1;
		count=count+1;
		in>>n;
		}
	}
	
	cout<<"Number\t   Perfect?\t Prime?\t    Perfect Square? \t  Sphenic?\t  Binary Equiv"<<endl;
	cout<<"=======\t   ========\t=======\t   ================\t===========\t==============="<<endl;
	for(i=0;i<count;i=i+1){
		perf=isPerfect(fave,i);
		prime=isPrime(fave,i);
		sq=isPerfSq(fave,i);
		sph=isSphenic(fave,i);
		
		cout<<fave[i]<<"\t      "<<perf<<"\t\t   "<<prime<<"\t\t  "<<sq<<"\t\t    "<<sph<<"\t\t   ";
		Binary(fave,i);
		cout<<endl;
	}
	cout<<endl<<endl;
	cout<<"   Distinct numbers"<<endl;
	cout<<"===================="<<endl;
	
	
	distinct[incr]=fave[0];
	for(i=1;i<count;i=i+1){
		found=false;
		for(t=0;t<count;t=t+1){
			if(fave[i]==distinct[t]){
				found=true;
			}
		}
		if(found==false){
			incr=incr+1;
			distinct[incr]=fave[i];
		}
	}
	
	
	for(i=0;i<count;i=i+1){
		if(distinct[i]!=0){
			cout<<distinct[i]<<" ";
		}
		
	}	
	
	cout<<endl<<endl;
	cout<<"   Invalid numbers"<<endl;
	cout<<"===================="<<endl;
	for(i=0;i<num;i=i+1){
		if(i%4==0&& i!=0){
			cout<<endl;
		}
		cout<<invalid[i]<<" ";
	}
	
	cout<<endl<<endl;
	
	for(i=0;i<count;i=i+1){
		n=fave[i];
		if(n<11){
			a=a+1;
		}
		else if(n<21){
				b=b+1;
			}
			else if(n<31){
					c=c+1;
				}
				else if(n<41){
						d=d+1;
					}
					else if(n<51){
							e=e+1;
						}	
						else if(n<61){
								f=f+1;
							}
							else if(n<71){
									g=g+1;
								}
								else if(n<81){
										h=h+1;
									}
									else if(n<91){
											j=j+1;
										}
										else{
											k=k+1;
										}
	}
	cout<<"\t Range   Histogram"<<endl;
	cout<<"===================================="<<endl;
	cout<<"\t 1-10\t|"; printStars(a);
	cout<<"\t 11-20\t|"; printStars(b);
	cout<<"\t 21-30\t|"; printStars(c);
	cout<<"\t 31-40\t|"; printStars(d);
	cout<<"\t 41-50\t|"; printStars(e);
	cout<<"\t 51-60\t|"; printStars(f);
	cout<<"\t 61-70\t|"; printStars(g);
	cout<<"\t 71-80\t|"; printStars(h);
	cout<<"\t 81-90\t|"; printStars(j);
	cout<<"\t 91-100\t|"; printStars(k);
	
	cout<<endl<<endl;
	cout<<"    \t\tStatistical Information"<<endl;
	cout<<"========================================================================="<<endl;
	cout<<"Number of students who specified valid favourite numbers: "<<count<<endl;
	cout<<"Number of students who specified invalid favourite numbers: "<<num<<endl;
	cout<<"Number of students who did not reveal their favourite number: "<<no_reveal<<endl;
	cout<<"Number(s) chosen most by the students: ";

	   
	for(i=1;i<count;i=i+1){
		if(max<fave_count[i]){
			max=fave_count[i];
			maxnum[0]=i;
		}
	}
	
	for(i=0;i<count;i=i+1){
		if(max==fave_count[i] && i!=maxnum[0]){
			maxnum[q]=i;
			q=q+1;
		}
	}
	
	for(i=0;i<count;i=i+1){
		if(maxnum[i]!=0){
			cout<<maxnum[i]<<" ";
		}
	}
	
	cout<<endl;
	cout<<"Number(s) chosen least by the students: ";
		
	for(i=0;i<count;i=i+1){
		if(min>fave_count[i] && fave_count[i]>=1){
			min=fave_count[i];
			minnum[0]=i;
		}
	}
	
	for(i=0;i<count;i=i+1){
		if(min==fave_count[i] && i!=minnum[0]){
			minnum[r]=i;
			r=r+1;
		}
	}
	
	for(i=0;i<count;i=i+1){
		if(minnum[i]!=0){
			cout<<minnum[i]<<" ";
		}
	}
	in.close();
return 0;
}

