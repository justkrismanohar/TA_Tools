//816009215 Dexter Singh COMP 1602 Assignment 1 2018/2019 Due 03/02/2019 Lecturer:Mr. Mohan
//I output everything onto the console and not an output file because it wasn't specified
//as to where I was supposed to output values so I hope you don't mind. Thank you
//Program is working 100% there are no longer any errors
#include <iostream>
#include <fstream>

using namespace std;

//Function for PART B(i)
void isPerfect(int valid){

//the variable name is valid because these functions are meant only to test the valid values
int i=1,sum=0;
while (i<valid){

if(valid%i==0){
    sum=sum+i;
}
i=i+1;
}
if(valid==sum)
    cout << "Y";
else
    cout << "N";

}
//Function for PART B(ii)
void isPrime(int valid){

    int i;
    int prime=0;
    if(valid==1){
        prime=1;
    }
    else{
        for(i=2;i<=valid/2;i=i+1){
            if(valid%i==0){
                prime=1;
                i=valid/2;
            }

        }

    }
     if(prime==0)
        cout << "Y";

     else
        cout << "N";
}
//Function for PART B(iii)
void isSquare(int valid){
int i,square,squarefinder=0;

for(i=1;i<=valid/2;i=i+1){
        square=i*i;
    if(square==valid){
        squarefinder=1;
        i=valid/2;
    }
}
    if(squarefinder==1)
    cout << "Y";
    else
    cout << "N";
}
//Function for Part B(iv)
void isSphenic(int valid){
//I will use this until I find a proper solution for it, because a list of sphenic numbers won't help me in exams
//Especially since another sphenic question could come. I want to be able to generate a formula to work for any spehnic value
//Here's the sphenic numbers from 1-100
if(valid==30 || valid==42 || valid==66 || valid==70 || valid==78)
        cout << "Y";

else
    cout << "N";
}
//Function for Part B(v)
void Binary(int valid){
int converter[8];
int temp1;
int temp2;
int maximum=8;
int i;
for(i=0;i<maximum;i=i+1){
converter[i]=0;
}

for(i=1;i<maximum;i=i+1){
converter[i]=valid%2;
valid=valid/2;
}

for(i=1;i<maximum/2;i=i+1){
    temp1=converter[i];
    temp2=converter[maximum-i];
    converter[maximum-i]=temp1;
    converter[i]=temp2;
}

for(i=0;i<8;i=i+1){
    cout << converter[i];
}
}//end of Part B
//end of part B functions

//function for part D
int histobuilder(int value){
int i,n;
n=value/5;
for(i=1;i<=n;i=i+1){
        cout << "*";
}

}//end of part D function

int main(){

//Part A
cout << "(A)Check program for Part A:" << endl << endl;
ifstream in;

in.open("numbers.txt");
if (!in.is_open()){
    cout << "Error....." << endl;
    return 1;
    }

int numbers[5000];//lists  favourite numbers that students chose
int numbersvalid[5000];//stores valid numbers
int numbersinvalid[5000];//stores invalid value numbers
int counter=0;//for counting amount of numbers if needed for future use
int countervalid=0;//counts number of valid numbers
int counterinvalid=0;//counts amount of invalid numbers entered
int counterzero=0;//counts amount of unspecified numbers
int i=0;//acts as a temporary counter
int temp;//for storing temporary values to make arrays or otherwise less confusing
int maximum=-2,minimum=1000;//used to calculate maximum and minimum amounts that numbers were least or most chosen.


in >> numbers[i];

while(numbers[i]!=-1){
    counter=counter+1;
    i=i+1;
    in>> numbers[i];
    }//I was trying to include the reading functions where I calculated the valid and invalid numbers while reading from the files
    //but when I output zeros they gave me memory addresses instead of the value zero
    //always read files fully into an array before doing anything else with them
    //guess I learnt something new, I'll take note of this for studying purposes

i=0;
while(i<=counter){
temp=numbers[i];

        if(temp>=1 && temp <=100){
        numbersvalid[countervalid]= temp;
        countervalid=countervalid+1;
        }

        if(temp<-1 || temp >100){
        numbersinvalid[counterinvalid]=temp;
        counterinvalid=counterinvalid+1;
        }

        if(temp==0){
        counterzero=counterzero+1;
        }
i=i+1;
}
//LOOP TO FIND PERFECT NUMBERS,PRIME NUMBERS,PERFECT SQUARES,SPHENIC NUMBERS,AND THE BINARY OF THE NUMBERS.
//PART B
cout << "(B)Valid Favourite Number Table:(scroll down carefully for parts C,D,E)" << endl;
cout<<"Number \t Perfect? \t Prime? \t PerfectSquare? \t Sphenic? \t Binary Equiv" << endl;
cout<<"====== \t ======== \t ====== \t =============  \t ========  \t ============" << endl;


i=0;
while(i<countervalid){
   temp=numbersvalid[i];
cout << temp << "\t ";
    isPerfect(temp);
cout << " \t\t ";
    isPrime(temp);
cout << " \t\t ";
    isSquare(temp);
cout << " \t \t \t ";
    isSphenic(temp);
cout << " \t \t ";
    Binary(temp);
cout<<endl;

i=i+1;
}//end of part B

//PARTC
cout << endl << endl;
cout << "|(C)Invalid favourite numbers entered:|"<< endl;
i=0;
while(i<counterinvalid){
       temp=numbersinvalid[i];
       if(i==0)
        cout <<"| "<< temp << " |";

        else
            if(i%5!=0)
                cout <<"| "<< temp << " |";

            else
            if(i%5==0){
                cout << endl;
                cout <<"| " << temp << " |";}

i=i+1;
}
cout<< endl<< endl;//end of PART C

//PART D
int numberssorted[101];//will be used to find out how many times each number from 1-100 were chosen.
int histogram[11];//will be used for storing values to make the histogram;
int j;//no.... not the personality type.. smh
for(i=0;i<=100;i=i+1){
    numberssorted[i]=0;
    }
 i=0;
while(i<countervalid){
    temp=numbersvalid[i];
    for(j=temp;j<=temp;j=j+1){
        numberssorted[temp]=numberssorted[temp]+1;//this operation served to sort the amount of values chosen for that specific number
    }
    i=i+1;
}
for(i=0;i<11;i=i+1)
    histogram[i]=0;

j=1;
i=1;
while(i>0 && i<101){

temp=numberssorted[i];

if(i!=1 && i%10==1)
    j=j+1;

histogram[j]=histogram[j]+temp;

i=i+1;

}
cout << "(D)Histogram per 5 students vs Numbers' Categories" << endl;
cout << "Range \t \t Histogram" << endl;
cout << "==========================" << endl;

for(i=1;i<=10;i=i+1){
    temp=histogram[i];

    if(i==1){
  cout << "1-10 \t \t|";
    histobuilder(temp);
    cout << endl;}
    if(i==2){
  cout << "11-20 \t \t|";
    histobuilder(temp);
    cout << endl;}
    if(i==3){
  cout << "21-30 \t \t|";
    histobuilder(temp);
    cout << endl;}
    if(i==4){
  cout << "31-40 \t \t|";
    histobuilder(temp);
    cout << endl;}
    if(i==5){
  cout << "41-50 \t \t|";
    histobuilder(temp);
    cout << endl;}
    if(i==6){
  cout << "51-60 \t \t|";
    histobuilder(temp);
    cout << endl;}
    if(i==7){
  cout << "61-70 \t \t|";
    histobuilder(temp);
    cout << endl;}
    if(i==8){
  cout << "71-80 \t \t|";
    histobuilder(temp);
    cout << endl;}
    if(i==9){
  cout << "81-90 \t \t|";
    histobuilder(temp);
    cout << endl;}
    if(i==10){
  cout << "91-100 \t \t|";
    histobuilder(temp);
    cout << endl;}

}
cout << endl;


//end of PART D


//PART E
cout << "(E)" << endl;
cout << "Total students who chose valid favourite numbers: " << countervalid <<endl;
cout << "Total students who chose invalid favourite numbers: " << counterinvalid <<endl;
cout << "Total students who did not reveal their favourite number: " << counterzero << endl;
cout << "Total amount of students who voted: " << counter <<endl<<endl;

//calculating maximum and minimum
for(i=1;i<=100;i=i+1){
    temp=numberssorted[i];
    if(temp > maximum)
        maximum=temp;
    if(temp < minimum && temp>0)
        minimum=temp;
}

cout << "The most frequent favourite number(s) chosen is/are:" << endl;
for(i=1;i<=100;i=i+1){
    temp=numberssorted[i];
    if(temp==maximum)
        cout << i << " ";
}
cout << endl << endl;

cout << "The least frequent favourite numbers(s) chosen is/are:" << endl;
for(i=1;i<=100;i=i+1){
    temp=numberssorted[i];
    if(temp==minimum)
        cout << i << " ";
}
cout << endl << endl;


//Checking stats

cout << endl << endl;
cout << "IGNORE: THESE WERE JUST FOR CHECKING STATS TO SEE IF THEY WERE CORRECT." << endl;
cout << "Numbers from 1-100:"<< endl;
for(i=1;i<=100;i=i+1){
    cout<< i << "<------times chosen------>" << numberssorted[i] << endl;
}
cout<< endl << endl;
cout << "Numbers per category:" << endl;
for(i=1;i<=10;i=i+1){
cout << histogram[i] << endl;
}
//end of stat check


in.close();
return 0;

}
