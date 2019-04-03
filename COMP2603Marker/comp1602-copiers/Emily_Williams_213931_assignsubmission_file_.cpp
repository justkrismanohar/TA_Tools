#include <iostream>
#include <fstream>

using namespace std;

void Binary(int num);
bool isSphenic(int num);
bool isPerfectSquare(int num);
bool isPrime(int num);
bool isPerfect(int num);
void PrintStars(int CategoryCount);

int bit[8];

int main(){

    int choice, i=0, valid = 0, noNums = 0, invalidNums = 0, most = 0, least; 
	int favNum[100], invalid[100], numMost[10], numLeast[10], binaryNum[8], category[10]= {0,0,0,0,0,0,0,0,0,0};
	int n=0, count =0, line=0;

    ifstream inputFile;
    inputFile.open("numbers.txt");

    if(!inputFile.is_open()){
        cout << "File does not exist." << endl;
        return 0;
    }

    cout << "Number     Perfect?     Prime?     Perfect Square?     Sphenic?     Binary Equiv." << endl;
	cout << "======     ========     ======     ===============     ========     =============" << endl << endl;
    inputFile >> choice;

    while(choice!=-1){

        if((choice>0) && (choice<=100)){
            for(i=0; i<100; i++){
                if(choice == i+1){
                    favNum[i]++;
                }
            }
            
            valid++;
            
            if(choice>=1 && choice<=10){
                category[0]++;
            }
            
			else if((choice>10) && (choice<=20)){
                category[1]++;
            }
            
            else if((choice>20) && (choice<=30)){
                category[2]++;
            }
            
            else if((choice>30) && (choice<=40)){
                category[3]++;
            }
            
            else if((choice>40) && (choice<=50)){
                category[4]++;
            }
            
            else if((choice>50) && (choice<=60)){
                category[5]++;
            }
            
            else if((choice>60) && (choice<=70)){
                category[6]++;
            }
            
            else if((choice>70) && (choice<=80)){
                category[7]++;
            }
            
            else if((choice>80) && (choice<=90)){
                category[8]++;
            }
            
            else if((choice>90) && (choice<=100)){
                category[9]++;
            }
            
            Binary(choice);
            cout << choice;
            
            if(isPerfect(choice)){
                cout << "\t   Y\t\t";
            }
            
            else{
                cout << "\t   N\t\t";
            }
            
            if(isPrime(choice)){
                cout << "Y\t   ";
            }
            
            else{
                cout << "N\t   ";
            }
            
            if(isPerfectSquare(choice)){
                cout << "Y\t\t       ";
            }
            
            else{
                cout << "N\t\t       ";
            }
            
            if(isSphenic(choice)){
                cout << "Y\t    ";
            }
            
            else{
                cout << "N\t    ";
            }

            for(i=0; i<8; i++){
                cout << bit[i];
            }
            
            cout << endl;
        }
        
        else if(choice ==0){
            noNums++;
        }
        
        else{
            invalidNums++;
            invalid[count] = choice;
            count++;
        }

        inputFile >> choice;
    }
    
    cout << endl << "============================================================================" << endl;

    cout << endl << endl << "Invalid entries: " << endl;

    for(i=0; i<count; i++){
        cout << invalid[i] << "\t\t";
        line ++;
        
        if(line==5){
            cout << endl;
            line = 0;
        }
    }

    cout << endl << endl << endl << "Range\t\tHistogram" << endl;
    cout <<"==========================" << endl;
    n=1;
    
    for(i=0; i<10; i++){
        cout << n << "-" << n+9 << "\t\t" ;
        PrintStars(category[i]);
        n+=10;
        cout << endl;
    }
    
    n=0;

    cout << endl << endl << endl << "The amount of the students who specified valid favourite numbers: " << valid << endl;
    cout << "The amount of students who specified invalid favourite numbers: " << invalidNums << endl;
    cout << "The amount of students who did not reveal their favourite numbers: " << noNums << endl;

    for(i=0; i<100; i++){
    	
        if(favNum[i]>2){
            if(favNum[i]>most){
                most = favNum[i];
                numMost[0] = i+1;
            }
        }

        if(favNum[i]>=1){
            if(favNum[i]<least){
                least = favNum[i];
                numLeast[0] = i+1;
            }
        }
    }

    n= 0;
    count = 0;

    for(i=0; i<100; i++){
    	
        if(favNum[i]>2){
            if((favNum[i]==most) && ((i+1)!=numMost[0])){
                n++;
                numMost[n] = i+1;
            }
        }

        if(favNum[i]>=1){
            if((favNum[i]==least) && ((i+1)!=numLeast[0])){
                count++;
                numLeast[count] = i+1;
            }
        }
    }

    cout << endl;

    if(n==0){
        cout << "The number that was chosen the most by the students is: " << numMost[0] << endl;
    }
    
    else{
        cout << "The numbers that were chosen the most by the students are: ";
        for(i=0; i<n; i++){
            cout << numMost[i] <<endl;
        }
    }

    cout << endl;
    
    if(count==0){
        cout << "The number that was chosen the least by the students is: " << numLeast[0] << endl ;
    }
    
    else{
        cout << "The numbers that were chosen the least by the students are: " << endl;
        for(i=0; i<count; i++){
            cout << numLeast[i] <<endl;
        }
    }
    
    cout << endl << endl << endl << endl;

    inputFile.close();

    return 0;
}

bool isPerfect(int num){
    int sum = 0, i =0 ;

    for(i=1; i<num; i++){
        if(num%i==0){
            sum+=i;
        }
    }

    if(sum==num){
        return true;
    }

    return false;
}

bool isPrime(int num){
    int i;

    for(i=2; i<num; i++){
        if(num%i==0){
            return false;
        }
    }

    return true;
}

bool isPerfectSquare(int num){
    int i;

    for(i=1; i<num; i++){
        if(i*i==num){
            return true;
        }
    }

    return false;
}

bool isSphenic(int num){
    int i, primeNumbers[3], n, count=0;
    
    bool Prime;
    for(i=2; i<num; i++){
        if(num%i==0){
            Prime=true;

            if(i==2){
                primeNumbers[count]=2;
                count++;
            }
            
            else{
                for(n=2; n<i; n++){
                    if(i%n==0){
                        Prime = false;
                        break;
                    }
                }

                if(Prime==true){
                    primeNumbers[count] = i;
                    count++;
                }
            }
        }
    }

    if((primeNumbers[0])*(primeNumbers[1])*(primeNumbers[2])==num){
        return true;
    }

    return false;
}

void Binary(int num){
    int i=7;

    while(num!=0){
        bit[i] = num%2;
        num = num/2;
        i--;
    }
    while(num==0 && i!=0){
        bit[i]=0;
        i--;
    }
}

void PrintStars(int CategoryCount){
    while(CategoryCount>=5){
        CategoryCount -=5;
        cout << "*";
    }
}
