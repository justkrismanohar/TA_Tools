/******************************************************************************
COMP1602
ASSIGMENT 1



*******************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

//Function to determine if number is Perfect
char isPerfect(int n){
    
    char ans ='N';
    int sum=0;
    if(n%2!=0){
        
        ans='N';
        
        return ans;
        
    }
    else{
    
        for(int i=1;i<=n/2;i++){
        
            if(n%i==0){
                
            
            sum=sum +i;
            
            }
            
        }
        
        if(sum==n){
            
            ans='Y';
        }
        
        
        
    }
    return ans;
    
}
//Function to determine if number is Prime
char isPrime(int n){
    
    char ans='Y';
    if(n==1){
        
        ans='N';
    }
    for(int i=2;i<=n/2;i++){
        
        if(n%i==0){
            
            ans='N';
            
            return ans;
        }
    }
    
   return ans; 
}
//Function to determine if number is a perfect Square
char perfectSquare(int n){
    
    char ans='N';
    for(int i=1;i<=n/2;i++){
        
        if(i*i==n){
            
            ans='Y';
            
            return ans;
        }
        
    }
    
    return ans;
    
    
}
//Function to determine if number is Sphenic
char isSphenic(int n){
    
    int count=0;
    char ans='N';
    int pro=1;
    
    for(int i=2;i<n/2;i++){
        
        if(n%i==0&&isPrime(i)=='Y'){
            
            pro=pro*i;
            count = count+1;
        }
        
    }
    
    if(pro==n&&count==3){
        
        ans='Y';
    }
    
    return ans;
    
}
//Function to generate the binary equivalent of a number
void binaryEquiv(int arry[],int size,int n){
    
    int i=size-1;
    int rem;
    while(n>0){
        
        rem=n%2;
        arry[i]=rem;
        n=n/2;
        i--;
       
    }
}

int main()
{
    
    int countValid=0;
    int countInvalid=0;
    int countNoReveal;
    int numberChosenMost;
    int numberChosenLeast;
    int highest=-1;
    int lowest=9999;
    ifstream in;
    int num;
    int invalidNumbers[10];
    int rangeArray[10]={0};
    int numbers[101]={0};
    int binaryArray[8]={0};
    in.open("numbers.txt");
    if(in.is_open()==false){
        
        cout<<"Error !";
        
        return 0;
    }
    
    in>>num;
    while(num!=-1){
        
        if(num<=100&&num>=0){
            
                
                numbers[num]= numbers[num]+1;
            
        }else{
            
            invalidNumbers[countInvalid]=num;
                countInvalid++;
            
            
        }    
        
        
        in>>num;
        
        
    }
    int highestArray[15]={0};
    int lowestArray[42]={0};
    countNoReveal=numbers[0];
    int sum=0;
    int u=0;
    int y=0;
    for(int i=1;i<101;i++){
        
        if(numbers[i]!=0){
            
            sum = sum+numbers[i];
            
            if(numbers[i]>=highest){
                
                if(numbers[i]==highest){
                    
                    highestArray[u]=i;
                    u++;
                }else{
               
                highest=numbers[i];
                highestArray[15]={0};
                u=0;
                highestArray[u]=i;
                u++;
               
             }
            }
      
            
        }
        
    }
    
     for(int i=1;i<101;i++){
        
        if(numbers[i]!=0){
            
               if(numbers[i]<=lowest){
                
                	if(numbers[i]<lowest){
                
                		lowest=numbers[i];
						lowestArray[42]={0};
                   		y=0;
                		lowestArray[y]=i;
               			y++;
                    
                }else{
                
               
                lowestArray[y]=i;
                   y++;
                /*lowestArray[15]={0};
                y=0;
                lowestArray[y]=i;
                y++;*/
                }
                //numberChosenLeast=i;
            }
            
        }
        
    }
    
    
    cout<<"Number\tPerfect?\tPrime?\tPerfect Square?\tSphenic?\tBinary Equiv."<<endl;
   
    for(int i=1;i<101;i++){
        
        if(numbers[i]!=0){
            
            binaryEquiv(binaryArray,8,i);
            
            cout<<i<<"\t"<<isPerfect(i)<<"\t\t"<<isPrime(i)<<"\t"<<perfectSquare(i)<<"\t\t"<<isSphenic(i)<<"\t\t";
            
            for(int z=0;z<8;z++){
                cout<<binaryArray[z];
            }
            cout<<endl;
        }
        
        
    }
    cout<<endl;
    cout<<"Invalid numbers 5 a line are: "<<endl;
    for (int b=0;b<countInvalid;b++){
        
        
        cout<<invalidNumbers[b]<<" ";
        int val=b+1;
        if(val%5==0){
            
            cout<<endl;
        }
        
            
        
    }
    cout<<endl;
    
    for(int i=1;i<101;i++){
        
        if(numbers[i]!=0){
            
            if(i<=10&&i>=1){
                
               rangeArray[0]=rangeArray[0]+numbers[i]; 
            }else{
                
                if(i<=20&&i>=11){
                    
                    rangeArray[1]=rangeArray[1]+numbers[i];
                    
                }else{
                    
                    if(i<=30&&i>=21){
                        
                        rangeArray[2]=rangeArray[2]+numbers[i];
                    
                        
                    }else{
                        
                        
                        if(i<=40&&i>=31){
                            
                          rangeArray[3]=rangeArray[3]+numbers[i];  
                            
                        }else{
                            
                            
                            if(i<=50&&i>=41){
                                
                               rangeArray[4]=rangeArray[4]+numbers[i]; 
                                
                                
                            }else{
                                
                                
                                if(i<=60&&i>=51){
                                    
                                   rangeArray[5]=rangeArray[5]+numbers[i]; 
                                    
                                }else{
                                    
                                    
                                    if(i<=70&&i>=61){
                                        
                                        
                                        rangeArray[6]=rangeArray[6]+numbers[i];
                                        
                                        
                                    }else{
                                        
                                        if(i<=80&&i>=71){
                                            
                                            
                                            rangeArray[7]=rangeArray[7]+numbers[i];
                                            
                                            
                                        }else{
                                            
                                            if(i<=90&&i>=81){
                                                
                                              rangeArray[8]=rangeArray[8]+numbers[i];  
                                                
                                            }else{
                                                
                                                if(i<=100&&i>=91){
                                                    
                                                  rangeArray[9]=rangeArray[9]+numbers[i];  
                                                    
                                                }
                                                
                                            }
                                            
                                            
                                        }
                                        
                                        
                                    }
                                    
                                    
                                }
                                
                                
                            }
                            
                        }
                    }
                    
                }
            }
        }
        
    }
    cout<<endl;
    
    
    cout<<"Range\tHistogram"<<endl;
    cout<<"=================="<<endl;
    int val;
    for(int x=0;x<10;x++){
        
        if(x==0){
            val=(rangeArray[0])/5;
            
            cout<<"1-10\t";
            
            for(int s=0;s<val;s++){
                cout<<"*";
            }
            cout<<endl;
            
        }else{
            
            if(x==1){
                val=(rangeArray[1])/5;
            
                cout<<"11-20\t";
            
                for(int s=0;s<val;s++){
                    cout<<"*";
                }
                cout<<endl;
                
                
            }else{
                
                if(x==2){
                    
                   val=(rangeArray[2])/5;
            
                    cout<<"21-30\t";
            
                    for(int s=0;s<val;s++){
                        cout<<"*";
                    }
                    cout<<endl; 
                    
                }else{
                    
                    if(x==3){
                        
                        val=(rangeArray[3])/5;
            
                        cout<<"31-40\t";
            
                        for(int s=0;s<val;s++){
                            cout<<"*";
                        }
                        cout<<endl; 
                        
                    }else{
                        
                        if(x==4){
                           val=(rangeArray[4])/5;
            
                            cout<<"41-50\t";
            
                            for(int s=0;s<val;s++){
                                cout<<"*";
                            }
                            cout<<endl;   
                            
                        }else{
                            
                            if(x==5){
                               val=(rangeArray[5])/5;
            
                            cout<<"51-60\t";
            
                            for(int s=0;s<val;s++){
                                cout<<"*";
                            }
                            cout<<endl;  
                                
                            }else{
                                
                                if(x==6){
                                   val=(rangeArray[6])/5;
            
                                    cout<<"61-70\t";
            
                                for(int s=0;s<val;s++){
                                    cout<<"*";
                                }
                                cout<<endl;  
                                    
                                    
                                }else{
                                    
                                    
                                    if(x==7){
                                        
                                        val=(rangeArray[7])/5;
            
                                        cout<<"71-80\t";
            
                                        for(int s=0;s<val;s++){
                                            cout<<"*";
                                        }
                                    cout<<endl; 
                                        
                                    }else{
                                        
                                        if(x==8){
                                            val=(rangeArray[8])/5;
            
                                            cout<<"81-90\t";
            
                                            for(int s=0;s<val;s++){
                                                cout<<"*";
                                            }
                                        cout<<endl; 
                                            
                                            
                                        }else{
                                            
                                            if(x==9){
                                                val=(rangeArray[9])/5;
            
                                                cout<<"91-100\t";
            
                                                for(int s=0;s<val;s++){
                                                    cout<<"*";
                                                }
                                            cout<<endl; 
                                                
                                                
                                            }
                                        }
                                    }
                                }
                                
                            }
                            
                        }
                        
                        
                    }
                    
                    
                    
                }
                
            }
            
        }
        
        
    }
    cout<<endl;
    cout<<"The number of students who specified valid favorite numbers: "<<sum<<endl;
    cout<<"The number of students who specified invalid favorite numbers: "<<countInvalid<<endl;
    cout<<"The amount of students who did not reveal their favorite number: "<<countNoReveal<<endl; 
    cout<<"The number/s chosen most by students was: ";
    for(int i=0;i<u;i++){
        cout<<highestArray[i]<<" ";
    }
    cout<<endl;
    cout<<"The number/s chosen least by students was: ";
    for(int i=0;i<y;i++){
        cout<<lowestArray[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}

