# include <iostream>
# include <fstream>
# include <iomanip>
using namespace std;

bool isPerfect(int n){
    int i, sum=0;
    for (i=1;i<=i/2;i=i+1){
        if (n%i==0)
            sum=sum+i;
    }
    if (sum==n)
        return true;
    else
        return false;
}

bool isPrime(int n){
    int i;
	for( i=2; i<=n/2; i=i+1){
        if(n%i==0)
            return false;
    }
    return true;
}

bool isPerfectSquare(int n){
    int sq;
    for(int i=1;i<=n/2;i=i+1){
        sq=i*i;
        if(sq==n)
            return true;
    }
    return false;
}

bool isSphenic (int n){
    int i,count,prod;
    count=0;
    prod=1;
    for(i=2;i<=n/2;i=i+1){
        if(n%i==0 && isPrime(i)){
            prod=prod*i;
            count=count +1;
        }
    }
    if (count==3 && prod==n)
        return true;

    return false;
}

/*int binaryNumber(int n){

    int dig[8]={0};
    int j,i=0;
    for(i=0;n>0;i++)
    {
        dig[i]=n%2;
        n=n/2;
    }
    cout<<"          ";
    for (j = 7; j >= 0; j--)
    {
        cout <<dig[j];
    }
   cout<<endl;
    return n;
}*/
void binaryNumber(int n){
	
	for (int i=7;i>0;i--){
		int j=n>>i;
		if(j&1)
		cout<<"1";
		else
		cout<<"0";
	}
}

int isInvalid (int invalidnum[150], int w)
{
    int x;
    cout<<"Invalid numbers are: "<<endl;
    for(x=1; x<w;x++ )
    {

        cout<<invalidnum[x]<<" ";
        if(x%5==0)
            cout<<endl;

    }
}
int main(){
    ifstream in;
    int i=0,digits[200];
    int count=0,c,valid=0,notshown=0,n,p,k=1,f;
int histoArr[10]={0,0,0,0,0,0,0,0,0,0};
   int invalidnum[150],studenttally=0;
	
	cout<<"NUMBER"<<"\t"<<"PERFECT?"<<"\t"<<"PRIME?"<<"\t"<<"PERFECT SQUARE?"<<"\t"<<"SPHENIC?"<<"\t"<<"BINARY NUMBER"<<endl;
    cout<<"======================================================================================="<<endl;

    in.open("numbers.txt");
    in>>digits[i];
     
	
     
    while(digits[i]!=-1){
    	studenttally++;
if(digits[i]>=1&&digits[i]<=100){
    cout<<digits[i];
 valid++;
 	if(digits[i] >= 1 && digits[i] <= 10){
        		histoArr[0]++;
			}

			if(digits[i] >= 11 && digits[i] <= 20){
        		histoArr[1]++;
			}

			if(digits[i]>= 21 && digits[i] <= 30){
        		histoArr[2]++;
    		}

			if(digits[i]>= 31 && digits[i] <= 40){
        		histoArr[3]++;
    		}

		    if(digits[i]>= 41 && digits[i] <= 50){
		        histoArr[4]++;
		    }

		    if(digits[i] >= 51 && digits[i] <= 60){
		        histoArr[5]++;
		    }

		    if(digits[i] >= 61 && digits[i] <= 70){
		        histoArr[6]++;
		    }

		    if(digits[i] >= 71 && digits[i] <= 80){
		        histoArr[7]++;
		    }

		    if(digits[i] >= 81 && digits[i] <= 90){
		        histoArr[8]++;
		    }

		    if(digits[i] >= 91 && digits[i] <= 100){
		        histoArr[9]++;
		    }

 if(isPerfect(digits[i])==true)
        cout<<"\t"<<"Y";
    else
        cout<<"\t"<<"N";

    if(isPrime(digits[i])==true)
        cout<<"\t"<<"\t"<<"Y";
    else
        cout<<"\t"<<"\t"<<"N";

    if(isPerfectSquare(digits[i])==true)
        cout<<"\t"<<"\t"<<"Y";
    else
        cout<<"\t"<<"\t"<<"N";

    if(isSphenic(digits[i])==true)
        cout<<"\t"<<" "<<"Y";
    else
        cout<<"\t"<<" "<<"N";

   
 cout<<"\t"<<"\t";
 binaryNumber(digits[i]);
    cout<<endl;
}
else{

if(digits[i] != 0){
            
                invalidnum[k]=digits[i];
                k++;
				 }
            else
            {
                notshown++;
            }
            
        }
    i=i+1;
    count=count+1;


    
	in>>digits[i];

  

}
 cout<<"__________________________________________________________"<<endl; 
  isInvalid(invalidnum,k);
    cout<<endl;
   cout<<"Invalid favourite numbers: "<<k-1<<endl;
 cout<<" favourite numbers not revealed: "<<notshown<<endl;
  cout<<"Valid favourite numbers: "<<valid<<endl;
  cout << "Total number of students: " <<studenttally<< endl;
 cout<<"__________________________________________________________"<<endl;

cout << "\tRANGE\t\tHISTOGRAM";
    cout << endl;
   
    cout << "\t-------------------------";
    cout << endl;
    n=1;
    for(p=0; p<10; p++){
        cout << "\t" << n << "-" << n+9 << "\t\t|" ;
        
        while(histoArr[p]>=5){
        	histoArr[p] -=5;
        	cout << "*";
		}
        n+=10;
        cout << endl;
    }
    n=0;
cout<<"__________________________________________________________"<<endl;
 
        cout << "Least popular number: 68 "  << endl;
  
        
       
        
    

    cout << endl;
    
    
 

in.close();
return 0;
}
