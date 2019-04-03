#include<iostream>
#include<fstream>
using namespace std;
bool perfect(int n){
	int sum=0,i;
	for(i=1;i<n;i=i+1){
		if(n%i==0){
			sum=sum + i;
		}
	}
	if(sum==n)
	  return true;
	else
	  return false;  
		
	}
bool prime(int n){
	int rem=0;
	for(int i=1;i<=n/2;i=i+1){
		rem=n%i;
		if(rem==0)
		 return false;
	}
	return true;
}
bool perfectsquare(int n){
	int sq;
	for(int i=1;i<=n/2;i=i+1){
		sq=i*i;
		if(sq==n)
		return true;
	}
	return false;
}
bool sphenic(int n){
	int count=0,product=1;
		for(int i=2;i<=n/2;i=i+1){
			if(n%i==0 && prime(i) ){
				product=product*i;
				count=count+1;
			}
			if(count==3 && product==n){
				return true;
			}
			return false;
     	}
}
void binary(int n){
int binarynum[8];
   int i = 0; 
   for(i=0;i<8;i++){
   	binarynum[i]=0;
   }
   for(i=7;i>=0;i=i-1){
   	if(n>0){
   		binarynum[i]=n%2;
   		n=n/2;
   	}
   }
   for(i=0;i<8;i=i+1){
   	cout<<binarynum[i];
   }

}
int main(){
	ifstream in;
	in.open("numbers.txt");
	if(!in.is_open()){
		cout<<"File not found !";
		return 0;
	}
	int ans5=0;
	int num[200],county=0;
	int invalid[101],i=0,histogram[11], favourite=0,countv=0,countin=0,count=0,count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0;
	int histogram1=0,histogram2=0,histogram3=0,histogram4=0,histogram5=0,histogram6=0,histogram7=0,histogram8=0,histogram9=0,histogram10=0;
	string anss,ans2,ans3,ans4;
	bool ans=false ;
	char perfectnum,primenum;
	int n;
	cout<<" Binary Representation     Perfect?        Prime?       Perfect Square?          Sphenic?           Number "<<endl;
    cout<<"  =====================    ========        ======        ===============         ========           ====== "<<endl;
	in>>n;
	while(n!=-1){
		    if(n==0)
		      favourite=favourite+1;
		    if((n<1 || n>100)&&(n!=0)){
			 invalid[i]=n;
			  i=i+1;
			  countin=countin+1;
		    }
			if(n>=1&&n<=100){
	          countv=countv+1;
	          if(perfect(n)!=ans){
	          	anss="y";
	          }
	          else
			  anss="n";
			  if(prime(n)!=ans){
			  	ans2="y";
			  }
			  else
			    ans2="n";
			   if(perfectsquare(n)!=ans){
			   	ans3="y";
			   } 
			   else
			    ans3="n";
			    if(sphenic(n)!=ans){
			    	ans4="y";
			    }
			    else
			     ans4="n";
			     
			     
			     cout<<"   \t      "<<anss<<"       \t      "<<ans2<<"       \t    "<<ans3<<"      \t        "<<ans4<<"     \t    "<<n<<endl;
			      binary(n);
			     if(n >= 1 && n <= 10){
                    histogram1 = histogram1 + 1;
                    count=count+1;
                }
                
                if(n >= 11 && n <= 20){
                    histogram2 = histogram2 + 1;
                    count1=count1+1;
                }
                if(n >= 21 && n <= 30){
                    histogram3 = histogram3 + 1;
                    count2=count2+1;
                }
                if(n >= 31 && n <= 40){
                    histogram4 = histogram4 + 1;
                    count3=count3+1;
                }
                if(n >= 41 && n <= 50){
                    histogram5 = histogram5 + 1;
                    count4=count4+1;
                }
                if(n >= 51 && n <= 60){
                    histogram6 = histogram6 + 1;
                    count5=count5+1;
                }
                if(n >= 61 && n <= 70){
                    histogram7 = histogram7 + 1;
                    count6=count6+1;
                }
                if(n >= 71 && n <= 80){
                    histogram8 = histogram8 + 1;
                    count7=count7+1;
                }
                if(n >= 81 && n <= 90){
                    histogram9 = histogram9 + 1;
                    count8=count8+1;
                }
                if(n >= 91 && n <= 100){
                    histogram10 = histogram10 + 1;
                    count9=count9+1;
                }
                 
	     	}
	     	num[i]=n;
	     	county=county+1;
			
	 in>>n;
}
cout<<"invalid numbers"<<endl;
  for(int i=0;i<=countin;i=i+1){
  	cout<<invalid[i]<<"\t";
     if((i+1)%5==0)
      cout<<endl;
  
  	  
  }
  cout<<endl;
  cout<<"RANGE           HISTOGRAM"<<endl;
    cout<<"========================="<<endl;
    cout<<"1 - 10          ";
    for(int i=0;i<=count;i=i+1){
    
        if ((histogram1 /5) > 0.0 ){
             cout<<"*";
             histogram1=histogram1-5;
        }
}
    cout<<endl;
    cout<<"11 - 20         ";
    for(int i=0;i<=count1;i=i+1){
    
        if ((histogram2 /5 )> 0.0)
        {
            cout<<"*";
            histogram2=histogram2-5;
        }
}

    cout<<endl;
    cout<<"21 - 30           ";
   for(int i=0;i<=count2;i=i+1){
        if (histogram3 / 5 >0.0 ){
            cout<<"*";
            histogram3=histogram3-5;
            
        }
}
    cout<<endl;
    cout<<"31 - 40           ";
    
    for(int i=0;i<=count3;i=i+1){
        if (histogram4 / 5 > 0.0){
            cout<<"*";
            histogram4=histogram4-5;
        }
}
    cout<<endl;
    cout<<"41 - 50           ";
    for(int k = 0; k <= count4;  k = k + 1){
        if (histogram5 / 5 > 0.0){
            cout<<"*";
            histogram5=histogram5-5;
        }
    }
    cout<<endl;
    cout<<"51 - 60           ";
    for(int k = 0; k <= count5;  k = k + 1){
        if (histogram6 /5 >0.0){
            cout<<"*";
            histogram6=histogram6-5;
        }
}
    cout<<endl;
    cout<<"61 - 70           ";
    for(int k = 0; k <= count6;  k = k + 1){
        if (histogram7 / 5 > 0.0){
            cout<<"*";
            histogram7=histogram7-5;
        }
}
    cout<<endl;
    cout<<"71 - 80           ";
    for(int k = 0; k <= count7;  k = k + 1){
        if (histogram8 / 5 > 0.0){
            cout<<"*";
            histogram8=histogram8-5;
        }
}
    cout<<endl;
    cout<<"81 - 90           ";
   
    for(int k = 0; k <= count8;  k = k + 1){
        if (histogram9 / 5 > 0.0){
            cout<<"*";
            histogram9=histogram9-5;
        }
}
    cout<<endl;
    cout<<"91 - 100          ";
    for(int k = 0; k <= count9;  k = k + 1){
        if (histogram10 /5 > 0.0){
            cout<<"*";
            histogram10=histogram10-5;
        } 
	 }
     cout<<endl;
     cout<<"the number of students who did not revel their favourite number is :"<<favourite<<endl;
     cout<<"the number of students who specified their favourite valid number is :"<<countv<<endl;
     cout<<"the number of students that specified invalid favourite numbers is:"<<countin<<endl;
     int tempcount=0,countr=0;
     int temp=num[i],pop=0,least=0;
     for(int h=0;h<=200;h=h+1){
     	
     	if(num[h]==temp){
     	 tempcount=tempcount+1;
     	if(tempcount>countr)
     	   countr=tempcount;
     }
     for (int l=0;l<=200;l++){
     	if (num[l]==num[h])
           countr++;
   if (countr==tempcount)
       pop= num[i] ;
     }

     }
    
  
    cout<<"the most popular number is:"<<pop<<endl;
    
	return 0;
}
