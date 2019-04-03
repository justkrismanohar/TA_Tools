#include <iostream>
#include <sstream> 
#include <string>
#include <fstream>
using namespace std;

bool Perfectnumber(int input){
  int perfectsum =0;
  int i =0;
  for(i=1; i < input; i++){
             if(input%i == 0){
              perfectsum = perfectsum + i;
            }
            }
            if(perfectsum == input){
                   return true;
               }
               else{
                  return false;
               }
}

bool Primenumber(int input){
  int i = 0;
  if(input == 1){
    return false;
  }
  for(i = 1; i <= input; i++){
      if((i>1)&&(i<input)&&(input%i == 0)){
          return false;
      }
    }
  return true;
}

bool PerfectSquare(int input){
  int i =0;
  for(i=1; i < input; i++){
                      if(i*i == input){
                        return true;
                      }                      
                    }
    return false;
}

bool SphenicNumber(int input){
  if((input == 30)||(input == 42)||(input == 66)||(input == 70)||(input == 78)){
    return true;
  }
  else{
    return false;
  }
}

int Binary(int input){
  int i =0;
  int remain = input;
  int ar[8];
  for(i=7; i>=0; i=i-1){
    ar[i] = remain%2;
    if(remain%2 == 1){
      remain = remain -1;
    }
    remain = remain/2;
  }
  for(i=0; i<8; i++){
    cout << ar[i];
  }
  cout << endl;
}

string Histogram(int his){
  int i = 0;
  int left =0;
  if(his<5){
    cout << "*" << endl;
  }
  if(his>=5){
    left = his%5;
    his = his-left;
    his = his/5;
    for(i =0; i <his; i++){
      cout << "*";
    }

  }
  
  return " ";  
}



int main() {
    int n; //to take in value from number.txt
    int i = 0; //used for counter
    int input; // input from user to be put into array
    bool perfect = true; //to check if number is perfect
    bool prime = true; //to check if a number is prime
    bool perfectsquare = false; // to check if number is perfectsquare
    bool sphenic = false; // to check if number is sphenic
    int binary;
    int invalid[999];
    int invalidcount =0;
    int validcount =0;
    int noanswer =0;
    int a =0; //1 to 10
    int b =0; //11 to 20
    int c =0; //21 to 30
    int d =0; //31 to 40
    int e =0; //41 to 50
    int f =0; //51 to 60
    int g =0; //61 to 70
    int h =0; //71 to 80
    int p =0; //81 to 90
    int j =0; //91 to 100
    int his =0;
    int allnums[999];
    int num =0;
    int most =0;
    int mostnum =0;
    int least[100];
    int leastnum =0;
    ifstream in; // to use number.txt

            in.open("number.txt");

            cout << "Number\t\tPerfect?\t\tPrime?\t\tPerfect Square?\t\tSphenic?\t\tBinary Equiv:" << endl;
            cout << "=====\t\t========\t\t======\t\t===============\t\t========\t\t=============\n"<<endl;

              in >> n;
              while(n != -1){    
                  
                  bool perfect = false;
                  bool prime = true;
                  bool perfectsquare = false; 
                  bool sphenic = false;
                  // sphenic numbers under 100 are 30 42 66 70 78
                  
                  if(n == 0){
                  input = 0;      // for users who entered nothing
                  noanswer = noanswer + 1;
                  invalid[invalidcount] = input;
                  invalidcount = invalidcount + 1;            
                }

                 input = n; 
                 if(input>0){
                   num = num +1;
                   allnums[num] = input;
                  }

                 if((input>100)||(input <0)){                   invalid[invalidcount] = input;
                      invalidcount = invalidcount + 1;
                 }                                 

                  if((input > 0)&&(input <=100)){
                    perfect = Perfectnumber(input);
                    prime = Primenumber(input);
                    perfectsquare = PerfectSquare(input);
                    sphenic = SphenicNumber(input);
                    validcount = validcount + 1;

                    cout << input << "\t\t\t\t";
                    if(perfect){
                      cout << "Y\t\t\t  ";                      
                    }
                    if(!perfect){
                      cout << "N\t\t\t  ";
                    }

                    if(prime){
                      cout << "Y\t\t\t      ";
                    }
                    if(!prime){
                      cout << "N\t\t\t      ";
                    }

                    if(perfectsquare){
                      cout << "Y\t\t\t\t\t";                      
                    }
                    if(!perfectsquare){
                      cout << "N\t\t\t\t\t";
                    }

                    if(sphenic){
                      cout << "Y\t\t\t\t";                      
                    }
                    if(!sphenic){
                      cout << "N\t\t\t\t";
                    }
                    binary = Binary(input); 
                    }

                    if((input>=1)&&(input<=10)){
                      a = a+1;
                    }

                    if((input>=11)&&(input<=20)){
                      b = b+1;
                    }
                    
                    if((input>=21)&&(input<=30)){
                      c = c+1;
                    }

                    if((input>=31)&&(input<=40)){
                      d = d+1;
                    }

                    if((input>=41)&&(input<=50)){
                      e = e+1;
                    }

                    if((input>=51)&&(input<=60)){
                      f = f+1;
                    }

                    if((input>=61)&&(input<=70)){
                      g = g+1;
                    }

                    if((input>=71)&&(input<=80)){
                      h = h+1;
                    }

                    if((input>=81)&&(input<=90)){
                      p = i+1;
                    }

                    if((input>=91)&&(input<=100)){
                      j = j+1;
                    }

                    in >> n; //take in value from numbers.txt
                }

                for(i=1; i<invalidcount; i++){
                  cout << invalid[i] << " ";
                  if (i%5 == 0){
                    cout << endl;
                  }
                }

                cout << "\nRange\t\tHistogram\n========================"<<endl;

                his = a;
                cout << " 1 to 10     :"<< Histogram(a) << endl;
                cout << "11 to 20     :"<< Histogram(b) << endl;
                cout << "21 to 30     :"<< Histogram(c) << endl;
                cout << "31 to 40     :"<< Histogram(d) << endl;
                cout << "41 to 50     :"<< Histogram(e) << endl;
                cout << "51 to 60     :"<< Histogram(f) << endl;
                cout << "61 to 70     :"<< Histogram(g) << endl;
                cout << "71 to 80     :"<< Histogram(h) << endl;
                cout << "81 to 90     :"<< Histogram(p) << endl;
                cout << "91 to 100    :"<< Histogram(j) << endl;

                cout << "Valid favourite answers :" << validcount << endl;
                cout << "Invalid favourite answers :" << invalidcount << endl;
                cout << "No responses :" << noanswer << endl;

            for (int i=1;i<=100;i++) {
                int count=0;
            for (int j=1;j<100;j++) { 
            if (allnums[j]==i) count++;
            
            if(count > most){
                most = count;
                mostnum = i;              
            }
                        
            }
            if (count == 1){
              leastnum = leastnum + 1;
              least[leastnum] = i;
           } 
            }
           if(most>1){
             cout << "The number most chosen was :" << mostnum << endl;
           }      
           for(i=1; i<leastnum; i++){
             cout << least[i] << " was one of the least numbers chosen." << endl;
           }

            in.close();
            
             cout << "\nProgram finished..." << endl;

    return 0;  
}
