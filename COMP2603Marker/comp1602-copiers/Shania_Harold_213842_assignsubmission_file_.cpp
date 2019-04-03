#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

bool perfect(int currNum);
bool prime(int currNum);
bool perfect_square(int currNum);
bool sphenic(int currNum);
void binaryEquivalent(void);
void histogram(void);

ifstream in;

int currNum = 0, originalNum = 0, binaryHolder = 0, binaryPointer = 0, pointerStart = 0, invalidPointer = 0, invalidNum = 0, newLine = 0, histogramPointer = 0;
int mostPopNum = 0, leastPopNum = 999, studentCount = 0, validCount = 0, invalidCount = 0, hiddenCount = 0, histogramCount = 0, resetArr = 0, counter = 0, i, n;
int allNum[101], binaryArr[8] = {'0','0','0','0','0','0','0','0'}, invalidArr[101], histogramArr[10] = {0,0,0,0,0,0,0,0,0,0}, mostPopValue[101];
int leastPopValue[101], favNum[101];
bool distinct = false;

bool perfect(int currNum){
    int currPointer = 1;
    int sum = 0;

    for (currPointer = 1; currPointer < currNum; currPointer++){
        if (currNum % currPointer == 0)
        {
            sum = sum + currPointer;
        }
    }

    if (sum == currNum){
        return true;
    }
    else{
        return false;
    }
}

bool prime(int currNum){
	int i, flag = 0;
	for (i=2; i<=currNum/2; i++){
		if (currNum%i == 0){
			flag = 1;
			break;
		}
	}
	if (flag == 0){
		return true;
	}
	else{
		return false;
	}
}

bool perfectSquare(int currNum){
    int square = 1;
    int squareStart = 1;

    for (squareStart = 1; squareStart <= currNum; squareStart++){
        square = (squareStart * squareStart);
        if (square == currNum){
            return true;
		}
    }
    return false;
}

bool sphenic(int currNum){
    int start;
    int count = 0;
    int prod = 1;
    int half = 0;
    half = currNum / 2;

    for (start = 2; start <= half ; start++){
        if ((currNum % start == 0) && (prime(start))){
            prod = prod * start;
            count++;
        }
    }

    if ((count == 3) && (prod == currNum)){
        return true;
    }
	else{
        return false;
    }

}

void binaryEquivalent(){
    binaryHolder = currNum;
    binaryPointer=7;
    
    while ((binaryHolder != 0) || (binaryPointer >=0)){
        binaryArr[binaryPointer] = (binaryHolder % 2);
        binaryHolder = (binaryHolder / 2);

        binaryPointer--;
    }
}


int main(){
	
	for(i=0; i<100; i++){
        favNum[i]= 0;
    }

	in.open("numbers.txt");

    if (!in.is_open()){
        cout << endl << endl;
        cout << "Error ... File cannot be opened ... Aborting\n";
        cout << endl << endl << endl;
        return 0;
	}
	else{
		cout << endl << endl;
    	cout << "                                        =====================================                                      "<<endl;
    	cout << "                                           STUDENT FAVOURITE NUMBER DATA                                      		"<<endl;
    	cout << "                                        =====================================                                      "<<endl;
    	cout << endl << endl << endl;
    	cout << "==================================================================================================================="<<endl;
    	cout << "Number\t\tPerfect?\tPrime?\t\tPerfect Square?\t\tSphenic?\tBinary Representation"<<endl;
    	cout << "==================================================================================================================="<<endl;
	}

	in >> currNum;
    originalNum = currNum;

	while (currNum != -1){
		studentCount++;
		
		if  ((currNum>0) && (currNum<=100)){
			for (i=0; i<100; i++){
				if (currNum == (i+1)){
					favNum[i]++;
					break;
				}
			}
		}

		if (currNum <= 100 && currNum >= 1){
			validCount++;

			if(currNum >= 1 && currNum <= 10){
        		histogramArr[0]++;
			}

			if(currNum >= 11 && currNum <= 20){
        		histogramArr[1]++;
			}

			if(currNum >= 21 && currNum <= 30){
        		histogramArr[2]++;
    		}

			if(currNum >= 31 && currNum <= 40){
        		histogramArr[3]++;
    		}

		    if(currNum >= 41 && currNum <= 50){
		        histogramArr[4]++;
		    }

		    if(currNum >= 51 && currNum <= 60){
		        histogramArr[5]++;
		    }

		    if(currNum >= 61 && currNum <= 70){
		        histogramArr[6]++;
		    }

		    if(currNum >= 71 && currNum <= 80){
		        histogramArr[7]++;
		    }

		    if(currNum >= 81 && currNum <= 90){
		        histogramArr[8]++;
		    }

		    if(currNum >= 91 && currNum <= 100){
		        histogramArr[9]++;
		    }

			if (allNum[currNum] == 0){
				distinct = true;
			}

			allNum[currNum]++;

			if (distinct == true){
				currNum = originalNum;
				perfect(currNum);

				currNum = originalNum;
				prime(currNum);

				currNum = originalNum;
				perfectSquare(currNum);

				currNum = originalNum;
				sphenic(currNum);

				currNum = originalNum;
				binaryEquivalent();

				cout << originalNum;

				if (perfect(currNum) == true){
        			cout << "\t\tY";
    			}
				else{
        			cout << "\t\tN";
				}

				if (prime(currNum) == true){
        			cout << "\t\tY";
    			}
				else{
        			cout << "\t\tN";
				}

				if (perfectSquare(currNum) == true){
        			cout << "\t\tY";
				}
				else{
        			cout << "\t\tN";
				}

				if (sphenic(currNum) == true){
        			cout << "\t\t\tY\t        ";
				}
				else{
        			cout << "\t\t\tN\t        ";
				}

				for (pointerStart = 0; pointerStart < 8; pointerStart++){
        			cout << binaryArr[pointerStart];
				}
				cout << endl;
			}
		}

		if (currNum == 0){
			hiddenCount++;
		}

		if ((currNum > 100) || (currNum <= -2)){
			invalidCount++;
			invalidPointer++;
			invalidArr[invalidPointer] = currNum;
		}

		binaryPointer = 0;

    	for (int resetArr = 0; resetArr < 7; resetArr++){
        	binaryArr[resetArr] = 0;
    	}
    	distinct = false;

    	in >> currNum;
    	originalNum = currNum;
	}

    for(i=0; i<100; i++){
        if(favNum[i]>=2){
            if(favNum[i]>mostPopNum){
                mostPopNum = favNum[i];
                mostPopValue[0] = i+1;
			}
        }

        if(favNum[i]>=1){
        	if(favNum[i]<leastPopNum){
                leastPopNum = favNum[i];
                leastPopValue[0] = i+1;
            }
        }
    }

    n = 1;
    counter = 1;

    for(i=0; i<100; i++){
        if(favNum[i]>2){
            if((favNum[i]==mostPopNum) && ((i+1)!=mostPopValue[0])){
                mostPopValue[n] = i+1;
                n++;
			}
        }

        if((favNum[i]==leastPopNum) && ((i+1)!=leastPopValue[0])){
            leastPopValue[counter] = i+1;
            counter++;
		}
    }
    cout <<endl;

	if (invalidPointer == 0){
        cout << endl << endl;
        cout << "There were no Invalid Numbers.";
        cout << endl << endl;
	}
    else{
        cout << endl << endl;
        cout << "Invalid Numbers were: ";
        cout << endl << endl;

        for (invalidNum = 1; invalidNum <= invalidPointer; invalidNum++){
            cout << invalidArr[invalidNum]<<"\t";
            newLine++;
            if (newLine % 5 == 0){
                cout << endl;
            }
        }
    }
    
    cout << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t\tRANGE\t\tHISTOGRAM";
    cout << endl;
    cout << "\t\t\t\t\t\t=========================";
    cout << endl;
    n=1;
    for(i=0; i<10; i++){
        cout << "\t\t\t\t\t\t" << n << "-" << n+9 << "\t\t|" ;
        
        while(histogramArr[i]>=5){
        	histogramArr[i] -=5;
        	cout << "*";
		}
        n+=10;
        cout << endl;
    }
    n=0;
    
    cout << "\t\t\t\t\t\t=========================";
    cout << endl << endl << endl << endl << endl << endl << endl;

    cout << "Total number of students: " << studentCount << endl;
    cout << "Total number of valid favourite numbers: " << validCount << endl;
    cout << "Total number of invalid favourite numbers: " << invalidCount << endl;
    cout << "Total number of students who did not reveal their favourtite number: " << hiddenCount << endl << endl;
    
    if(n==0){
        cout << "Least popular number: " << mostPopValue[0] << endl;
    }
    else{
        cout << "Least popular numbers: \n";
        for(i=0; i<n; i++){
            cout << mostPopValue[i] << endl;
        }
    }

    cout << endl;
    
    if(counter==0){
        cout << "Most popular number: " << leastPopValue[0] << endl;
    }
    else{
        cout << "Most popular numbers: \n";
        for(i=0; i<counter; i++){
            cout << leastPopValue[i] << " ";
        }
    }

    in.close();
    return 0;
}
