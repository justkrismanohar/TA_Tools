#include <iostream>
#include <fstream>

using namespace std;

bool isPerfect(int n){
    int i, sum=0;
    for (i=1; i<=n/2; i = i+1){
        if(n%i == 0)
            sum = sum +i;
    }
    if(sum == n)
        return true;
    return false;
}

bool isPrime(int n){
    int i, count=0;
    for(i=2; i<n/2; i=i+1){
        if(n%i == 0)
            count = count +1;
    }
    if(count == 0){
    return true;
    }
    else{
    return false;
    }
}

bool isPerfectSquare (int n){
    int i, sqr=0;
    for (i=1; i<n; i = i+1){
        sqr= i*i;
        if (sqr == n)
            return true;
    }
        return false;
}

bool isSphenic(int n){
    int i, product=1, primenum=0;
    for(i=2; i< n/2; i=i+1){
        if(n%i == 0 && (isPrime(i))){
            product = product*i;
            primenum = primenum +1;
        }
    }
    if(primenum==3 && product==n)
        return true;
    return false;
}

bool isValid(int n){
    if(n!=0 && n>0 && n<=100)
        return true;
    else
        return false;
    
}

void Binary(int n){
    int binary[8]= {};
    int i=7;
    
    while( n!=0){
        if(n%2 ==0)
            binary[i] = 0;
        else if(n%2 ==1)
        binary[i] =1;
        i = i-1;
        n = n/2;
    }
    for(i=0; i<=7; i=i+1)
        cout << binary[i];
}

string Histogram(int n){
    if(n/5 == 1)
        return "*";
    else if (n/5 ==2)
        return "**";
    else if (n/5 ==3)
        return "***";
    else if (n/5 ==4)
        return "****";
    else
        return "*****";
}

int main(){
    
    ifstream fin;
    bool isvalid;
    bool isnum = true;
    bool perfect;
    bool perfsq;
    bool sphenic;
    bool prime;
    int favnum[9000] = {};
    int number[9000] = {};
    int numvalid[9000] = {};
    int numinvalid[9000] = {};
    int histogram[10] = {};
    int mostchosen[9000] = {};
    int leastchosen[9000] = {};
    int students = 0, x = 0, num = 0, invalid = 0, valid = 0, j = 0, k = 0, nofav = 0, vnum = 0;
    int numberchosen[101] = {};
    int most = 0;
    int least = 9999;
    int n, totalstudents, totalvalids, totalinvalids, totalnumbers, i=0, totalmost, totalleast;
    
    fin.open("numbers.txt");
    
    if(!fin.is_open()){
        cout << "Error. File was not found. Aborting... ";
        return 0;
    }
    
    fin >> n;
    
    while(n != -1){
        favnum[x] = n;
        x = x+1;
        students = students + 1;
        fin >> n;
    }
    
    totalstudents = students;
    
    for(x = 0; x<totalstudents; x=x+1){
        isvalid = isValid(favnum[x]);
        if(isvalid){
            numvalid[valid] = favnum[x];
            valid = valid+1;
        }
        else if(!isvalid){
            numinvalid[invalid] = favnum[x];
            invalid = invalid +1;
        }
    }
    
    
    totalvalids = valid;
    totalinvalids = invalid;
    
    for(x = 0; x < totalinvalids; x = x+1){
        if(numinvalid[x] == 0)
            nofav= nofav+1;
    }
    
    for(x = 0; x < totalvalids; x=x+1){
        for(i = 0; i <= totalvalids; i=i+1){
            if(numvalid[x] == number[i]){
                isnum = false;
            }
        }
        if(isnum){
            number[num] = numvalid[x];
            num=num+1;
        }
        isnum = true;
    }
    
    totalnumbers = num;
    
    cout << "Number       Perfect?        Prime?      Perfect Square?     Sphenic?      Binary Equiv." << endl;
    cout << "======       ========        ======      ==============      ========      ============" << endl;
    
    for(x = 0; x < totalnumbers; x=x+1){
        cout << number[x] << "              ";
        
        perfect = isPerfect(number[x]);
        if(perfect)
            cout << "Y" << "              ";
        else
            cout << "N" << "              ";
        
        prime = isPrime(number[x]);
        if(prime)
            cout << "Y" << "               ";
        else
            cout << "N" << "               ";
        
        perfsq = isPerfectSquare(number[x]);
        if(perfsq)
            cout << "Y" << "                ";
        else
            cout << "N" << "                ";
        
        sphenic = isSphenic(number[x]);
        if(sphenic)
            cout << "Y" << "            ";
        else
            cout << "N" << "            ";
        
        Binary(number[x]);
        cout << endl;
    }
    
    cout << endl;
    cout << "Invalid Numbers:" << endl;
    cout << "===============" << endl;
    for(x = 0; x < totalinvalids; x = x + 1){
        if(x % 5 == 0 && x != 0)
            cout << endl;
        cout << numinvalid[x] << " ";
    }
    
    for(x = 0; x < totalvalids; x=x+1){
        if(numvalid[x] >= 1 && numvalid[x] <= 10)
            histogram[0]++;
        else if(numvalid[x] >= 11 && numvalid[x] <= 20)
            histogram[1]++;
        else if(numvalid[x] >= 21 && numvalid[x] <= 30)
            histogram[2]++;
        else if(numvalid[x] >= 31 && numvalid[x] <= 40)
            histogram[3]++;
        else if(numvalid[x] >= 41 && numvalid[x] <= 50)
            histogram[4]++;
        else if(numvalid[x] >= 51 && numvalid[x] <= 60)
            histogram[5]++;
        else if(numvalid[x] >= 61 && numvalid[x] <= 70)
            histogram[6]++;
        else if(numvalid[x] >= 71 && numvalid[x] <= 80)
            histogram[7]++;
        else if(numvalid[x] >= 81 && numvalid[x] <= 90)
            histogram[8]++;
        else if(numvalid[x] >= 91 && numvalid[x] <= 100)
            histogram[9]++;
    }
    
    cout << endl << endl;
    
    cout << "Range        Histogram" << endl;
    cout << "======================" << endl;
    cout << "1-10         |" << Histogram(histogram[0]) << endl;
    cout << "11-20        |" << Histogram(histogram[1]) << endl;
    cout << "21-30        |" << Histogram(histogram[2]) << endl;
    cout << "31-40        |" << Histogram(histogram[3]) << endl;
    cout << "41-50        |" << Histogram(histogram[4]) << endl;
    cout << "51-60        |" << Histogram(histogram[5]) << endl;
    cout << "61-70        |" << Histogram(histogram[6]) << endl;
    cout << "71-80        |" << Histogram(histogram[7]) << endl;
    cout << "81-90        |" << Histogram(histogram[8]) << endl;
    cout << "91-100       |" << Histogram(histogram[9]) << endl;
    
    cout << endl << endl;
    
    cout << "Amount of Students that Submitted Valid Favourite Numbers: " << totalvalids << " students" << endl;
    cout << "Amount of Students that Submitted Invalid Favourite Numbers: " << totalinvalids << " students" << endl;
    cout << "Amount of Students that did not reveal their Favourite Number: " << nofav << " students" << endl;
    cout << endl;
    
    for(x = 0; x < totalvalids; x=x+1){
        vnum = numvalid[x];
        numberchosen[vnum]++;
    }
    
    for(x = 1; x < 101; x=x+1){
        if(numberchosen[x] > most && numberchosen[x] >= 2){
            most = numberchosen[x];
        }
        
        if(numberchosen[x] < least && numberchosen[x] >= 1){
            least = numberchosen[x];
        }
    }
    
    for(x = 1; x < 101; x=x+1){
        if(numberchosen[x] == most){
            mostchosen[j] = x;
            j=j+1;
        }
        if(numberchosen[x] == least){
            leastchosen[k] = x;
            k=k+1;
        }
    }
    
    totalmost = j;
    totalleast = k;
    
    cout << "Number/s that was/were chosen the most by the students:" << endl;
    for(x = 0; x < totalmost; x=x+1){
        cout << mostchosen[x] << " ";
    }
    
    cout << endl;
    
    cout << "Number/s that was/were chosen the least by the students: " << endl;
    for(x = 0; x < totalleast; x=x+1){
        cout << leastchosen[x] << " ";
    }
    cout << endl;
    
    fin.close();
    return 0;
}
