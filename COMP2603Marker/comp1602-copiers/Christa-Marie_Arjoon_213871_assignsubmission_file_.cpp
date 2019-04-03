#include <iostream>
#include <fstream>
using namespace std;

bool perfect(int n){
	bool tf =false;
	int sum, i;
	sum = 1;
	for(i=2; i<=n/2; i++){
		if((n%i) == 0)
		sum=sum + i;
	}
	if(sum==n){
		tf = true;
		return tf;
	}
	else{
		return tf;
	}
}

bool prime(int n){
	bool tf =false;
	int i;
	int count = 0;
	for(i=2; i<=n/2; i++){
	   if((n%i) == 0)
	   count = count + 1;	
	}
	if(count==0){
		tf =true;
		return tf;
	}else
	return tf;
}

bool perfectSquare(int n){
	bool tf = false;
	int square, i;
	for(i=1; i<=n/2; i++){
		square=i*i;
		if(square==n){
			tf = true;
			return tf;
		}else{
			return tf;			
		}
	}
}

/*bool sphenic(int n){
	bool tf = false;
	int a, b, c, i;
	for(i=1; i<=n; i++){
			if(prime(i))
			a =i;
        }
        for(i=a+1; i<=n; i++){
			if(prime(i))
			b =i;
     	}
		for(i=b+1; i<=n; i++){
			if(prime(i))
			c =i;
        }  
    if ((a*b*c) == n){
    	tf = true;
    	return tf;
	}
   	else
		return tf;
}*/

bool sphenic(int n){
	int i, j,prod;
	j=0;
	prod=1;
	for(i=2;i<=n/2;i++){
		if(n%i==0&&prime(i)){
			prod=prod*i;
			j=j+1;
		}
	}
	if(j==3&&prod==n)
	return true;
	return false;
}

void binary(int n){
	int i=7; 
	int arr[8];
	int modVal =0; 
	
	for(int j=0;j<8;j++){
		arr[j]=0;
	}
	
	while(n!=0){
		modVal = n%2;
		arr[i] = modVal;
		i--;
		n= n/2;
	}
	
	for(int j=0;j<8;j++){
		cout<<arr[j];
	}
}

void valInv(){
	int n = 0;
	int value = 0;
	ifstream inFile;
	inFile.open("numbers.txt");
    if (!inFile)
    {
        cout << "\nError opening file.\n"; 
    }
    cout<<"\n invalid numbers:\n";
    while (inFile >> value)
    {
        if (value != -1)
        {
            if(value>100 || value < 1){ //checks whether number is valid
            	cout<< value << " ";
				n++;	
			}
			if(n==5){
				cout<< "\n"; //ensures that only 5 values are printed per line
				n=0;
			}
        }
    }
    inFile.close();

}

void histPrint(){
	int arr[10] = {0,0,0,0,0,0,0,0,0,0};
	int value = 0;
	ifstream inFile;
	inFile.open("numbers.txt");
	
	while(inFile >> value){
			int i=0;
			if(value>0 && value<11){
				arr[i]++;
			}
			i++;
			if(value>11 && value<21){
				arr[1]++;
				//cout<<arr[1]<< " ";
			}
			i++;
			if(value>21 && value<31){
				arr[i]++;
				//cout<<arr[2]<< " ";
			}
			i++;
			if(value>31 && value<41){
				arr[i]++;
				//cout<<arr[3]<< " ";
			}
			i++;
			if(value>41 && value<51){
				arr[i]++;
				//cout<<arr[4]<< " ";
			}
			i++;
			if(value>51 && value<61){
				arr[i]++;
				//cout<<arr[5] << " ";
			}
			i++;
			if(value>61 && value<71){
				arr[i]++;
				//cout<<arr[6]<< " ";
			}
			i++;
			if(value>71 && value<81){
				arr[i]++;
				//cout<<arr[7]<< " ";
			}
			i++;
			if(value>81 && value<91){
				arr[i]++;
				//cout<<arr[8]<< " ";
			}
			i++;
			if(value>91 && value<101){
				arr[i]++;
				//cout<<arr[9]<< " \n";
			}
			i++;
		//for(int j=0;j<10;j++){
		//}
	}
	//cout<< "\n "<< arr[1];
	cout<<"\nRange\t" << "Histogram\n";
	cout<<"===================";
	
	cout<<"\n1-10\t";
	cout<<"|";
	for(int j=0;j<arr[0];j++){
		if(j%5==0){
			cout<<"*";
		}
	}
	cout<<"\n11-20\t";
	cout<<"|";
	for(int j=0;j<arr[1];j++){
		if(j%5==0){
			cout<<"*";
		}
	}
	cout<<"\n21-30\t";
	cout<<"|";
	for(int j=0;j<arr[2];j++){
		if(j%5==0){
			cout<<"*";
		}
	}
	cout<<"\n31-40\t";
	cout<<"|";
	for(int j=0;j<arr[3];j++){
		if(j%5==0){
			cout<<"*";
		}
	}
	cout<<"\n41-50\t";
	cout<<"|";
	for(int j=0;j<arr[4];j++){
		if(j%5==0){
			cout<<"*";
		}
	}
	cout<<"\n51-60\t";
	cout<<"|";
	for(int j=0;j<arr[5];j++){
		if(j%5==0){
			cout<<"*";
		}
	}cout<<"\n61-70\t";
	cout<<"|";
	for(int j=0;j<arr[6];j++){
		if(j%5==0){
			cout<<"*";
		}
	}
	cout<<"\n71-80\t";
	cout<<"|";
	for(int j=0;j<arr[7];j++){
		if(j%5==0){
			cout<<"*";
		};
	}
	cout<<"\n81-90\t";
	cout<<"| ";
	for(int j=0;j<arr[8];j++){
		if(j%5==0){
			cout<<"*";
		}
	}
	cout<<"\n91-100\t";
	cout<<"|";
	for(int j=0;j<arr[9];j++){
		if(j%5==0){
			cout<<"*";
		}
	}
	
	inFile.close();
}

void  invCount(){
	ifstream inFile;
    int value;
    inFile.open("numbers.txt");
    int valCount=0;
    int inVcount=0;
	int noChoice = 0;
	if (!inFile)
    {
        cout << "\nError opening file.\n"; 
    }
    
    while (inFile >> value)
    {
        if (value != -1)
        {
    		if(value<101 && value>0){
    			valCount++;
			}
			if(value == 0){
				noChoice++;
			}	
			if(value>100 || value<0){
    			inVcount++;
			}
		}
	}
	inFile.close();
	cout<<"\n Number of valid choices= " << valCount;
	cout<<"\n Number of invalid choices= "<<inVcount;
	cout<<"\n Number of students who did not choose a number = " <<noChoice;
}

void freqChec()
{
	int freq = 0;
	int fNum = 0;
	int value = 0;
	int currFreq = 0;
	int currVal = 0;
	int testVal = 0;	
	
	
	ifstream inFile;
	ifstream testFile;
	inFile.open("numbers.txt");
	
   while(inFile >> value){
   		if(value!=0){
		   if(value<101&&value>0){
		   
				fNum = value;
				testFile.open("numbers.txt");
		
				while(testFile >> testVal){
					if(testVal == fNum){
						freq++;
				
					}			
				}
		
				if(freq > currFreq){
					currFreq = freq;
					currVal = fNum;
				}
			
				testFile.close();
				freq = 0;
		}
		}
	}
	
	cout << "\n most frequently chosen value is: " << currVal;
		
}

void lfreqChec()
{
	int freq = 0;
	int fNum = 0;
	int value = 0;
	int currFreq = 999999;
	int currVal = 0;
	int testVal = 0;	
	
	
	ifstream inFile;
	ifstream testFile;
	inFile.open("numbers.txt");
	
   while(inFile >> value){
   		if(value!=0){
		   if(value<101&&value>0){
		   
				fNum = value;
				testFile.open("numbers.txt");
		
				while(testFile >> testVal){
					if(testVal == fNum){
						freq++;
					}			
				}
		
				if(freq < currFreq){
					currFreq = freq;
					currVal = fNum;
				}
			
				testFile.close();
				freq = 0;
		}
		}
	}
	
	cout << "\n least frequently chosen value is: " << currVal;
		
}

int main()
{
	ifstream inFile;
    int value;
    bool tf =false;
	
	inFile.open("numbers.txt");
    if (!inFile)
    {
        cout << "\nError opening file.\n"; 
        return 13;
    }

	int arr[1000];
	
	cout << "Number     " << "Perfect?    " << "Prime?   "<<"Perfect Square   "
		 << "Sphenic    " << "Binary Equiv    "; 
	
	
	
	while (inFile >> value)
    {
        if (value != -1)
        {
        	if(value<=100 && value>=1){
			
        		cout <<"\n "<<value<<"\t\t"; 
        	
        		tf = prime(value);
				if(tf){
					cout<<"Y\t";
				}else
					cout<<"N\t";
			
				tf = perfect(value);
				if(tf)
					cout<<"Y\t\t";
				else
					cout<<" N\t\t";
				
				tf = perfectSquare(value);
				if(tf)
					cout<<"Y\t    ";
				else
					cout<<"N\t    ";
			
				tf = sphenic(value);
				if(tf)
					cout<<"Y\t   ";
				else
					cout<<"N\t   ";
			
				cout << "   " ; 
					
				binary(value);
			}
				
		}
		
	}
	inFile.close();
	
	cout<<"\n\n\n";
	invCount();
	
	cout<<"\n\n\n";
	histPrint();
	cout<<"\n\n\n";
	valInv();
	cout<<"\n\n\n";
	freqChec();
	cout<<"\n\n\n";
	lfreqChec();
}
