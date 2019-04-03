#include <iostream>
#include <fstream>
 
using namespace std;
 
 
bool isPerfect(int n){ 
    int i;
    int sum = 0;
    for(i = 1; i <= n/2; i++){
        if(n % i == 0)
            sum = sum + i;
    }
    if(sum == n)
        return true;
    return false;
}

bool isValid(int n){ 
    if(n != 0 && n > 0 && n <= 100)
        return true;
    else
        return false;
}
 
bool isPrime(int n){
    int i;
    int prime;
    for(i = 2; i < n/2; i++){
        prime = n % i;
        if(prime == 0)
            return false;
    }
    return true;
}
 
bool isSphenic(int n){
    int product = 1;
    int primes = 0;
    int i;
    for(i = 2; i < n/2; i++){
        if(n % i == 0 && (isPrime(i))){
            product = product * i;
            primes++;
        }
    }
    if(primes == 3 && product == n)
        return true;
    return false;
}

bool isPerfectSquare(int n){
    int square, i;
    for(i = 1; i < n; i++){
        square = i * i;
        if(square == n)
            return true;
    }
    return false;
}
 
void toBinary(int n){
    int binary[8] = {};
    int i = 7;
     
    while(n != 0){
        if(n % 2 == 0)
            binary[i] = 0;
        else if(n % 2 == 1)
            binary[i] = 1;
        i--;
        n = n / 2;
    }
     
    for(i = 0; i <= 7; i++)
        cout << binary[i];
}
 
string Histogram(int n){
    if(n / 5 == 1)
        return "*";
    else if(n / 5 == 2)
        return "**";
    else if(n / 5 == 3)
        return "***";
    else if(n / 5 == 4)
        return "****";
    else if(n / 5 == 5)
        return "*****";
}
 
int main(){
     
    ifstream fin; 
    bool valid_; 
    bool dist_; 
    bool perfect; 
    bool psquare; 
    bool sphenic; 
    bool prime; 
    
    
    
    int valid[1000] = {};
    int distnum[1000] = {};
    int invalid[1000] = {};
    
    int mchosen[1000] = {};
    int lchosen[1000] = {};
    int dmchosen[1000] = {};
	int histogram[10] = {};
    int dlchosen[1000] = {}; 
    int numfav[1000] = {};  
    int students = 0; 
    int x = 0;
    int dis = 0; 
    int inv = 0; 
    int val = 0; 
    int z = 0;
    int k = 0;

    int numshare = 0;
    int vnum = 0;
    int chosen[101] = {};
    int most = 0;
    int least = 999;
    int num, totalstudents, totalvalids, totalinvalids, totaldistincts, a, totalmost, totaleast;
     
    fin.open("numbers.txt"); 
     
    if(!fin.is_open()){ 
        cout << "Error opening file. Closing program...";
        return 0;
    }
     
    fin >> num;
     
    while(num != -1){
        numfav[x] = num;
        x++;
        students++;
        fin >> num;
    }
     
    totalstudents = students; 
     
    for(x = 0; x < totalstudents; x++){
        valid_ = isValid(numfav[x]);
        if(valid_){
            valid[val] = numfav[x];
            val++; 
        }
        else if(!valid_){
            invalid[inv] = numfav[x];
            inv++; 
        }
    }
     
     
    totalvalids = val; 
    totalinvalids = inv; 
     
    for(x = 0; x < totalinvalids; x++){
        if(invalid[x] == 0)
            numshare++;
    }
     
    for(x = 0; x < totalvalids; x++){
        for(a = 0; a <= totalvalids; a++){
            if(valid[x] == distnum[a]){
                dist_ = false;
            }
        }
        if(dist_){
            distnum[dis] = valid[x];
            dis++;
        }
        dist_ = true;
    }
     
    totaldistincts = dis; 
     
    cout << "Number       Perfect?        Prime?      Perfect Square?     Sphenic?        Binary Equiv." << endl;
    cout << "------       --------        ------      ---------------     --------        -------------" << endl;
 
    for(x = 0; x < totaldistincts; x++){
        cout << distnum[x] << "        ";
         
        perfect = isPerfect(distnum[x]);
        if(perfect)
            cout << "Y" << "            ";
        else
            cout << "N" << "            ";
         
        prime = isPrime(distnum[x]);
        if(prime)
            cout << "Y" << "        ";
        else
            cout << "N" << "        ";
             
        psquare = isPerfectSquare(distnum[x]);
        if(psquare)
            cout << "Y" << "            ";
        else
            cout << "N" << "            ";
             
        sphenic = isSphenic(distnum[x]);
        if(sphenic)
            cout << "Y" << "            ";
        else
            cout << "N" << "            ";
             
        toBinary(distnum[x]);
        cout << endl; 
    }
     
    cout << endl << endl << endl;
    cout << "List of Invalid Numbers" << endl;
    cout << "-----------------------------------" << endl;
    for(x = 0; x < totalinvalids; x = x + 1){
        if(x % 5 == 0 && x != 0)
            cout << endl;
        cout << invalid[x] << " ";  
    }
     
    for(x = 0; x < totalvalids; x++){
        if(valid[x] >= 1 && valid[x] <= 10)
            histogram[0]++;
        else if(valid[x] >= 11 && valid[x] <= 20)
            histogram[1]++;
        else if(valid[x] >= 21 && valid[x] <= 30)
            histogram[2]++;
        else if(valid[x] >= 31 && valid[x] <= 40)
            histogram[3]++;
        else if(valid[x] >= 41 && valid[x] <= 50)
            histogram[4]++;
        else if(valid[x] >= 51 && valid[x] <= 60)
            histogram[5]++;
        else if(valid[x] >= 61 && valid[x] <= 70)
            histogram[6]++;
        else if(valid[x] >= 71 && valid[x] <= 80)
            histogram[7]++;
        else if(valid[x] >= 81 && valid[x] <= 90)
            histogram[8]++;
        else if(valid[x] >= 91 && valid[x] <= 100)
            histogram[9]++;
    }
     
    cout << endl << endl << endl;
     
    cout << "Range        Histogram" << endl;
    cout << "-------------------------" << endl;
    cout << "1-10     " << Histogram(histogram[0]) << endl;
    cout << "11-20        " << Histogram(histogram[1]) << endl;
    cout << "21-30        " << Histogram(histogram[2]) << endl;
    cout << "31-40        " << Histogram(histogram[3]) << endl;
    cout << "41-50        " << Histogram(histogram[4]) << endl;
    cout << "51-60        " << Histogram(histogram[5]) << endl;
    cout << "61-70        " << Histogram(histogram[6]) << endl;
    cout << "71-80        " << Histogram(histogram[7]) << endl;
    cout << "81-90        " << Histogram(histogram[8]) << endl;
    cout << "91-100       " << Histogram(histogram[9]) << endl;
     
    cout << endl << endl;
     
    cout << "Number of Students that submitted favourite valid numbers: " << totalvalids << " students" << endl;
    cout << endl;
    cout << "Number of Students that submitted favourite invalid numbers: " << totalinvalids << " students" << endl;
    cout << endl;
    cout << "Number of Students that did not reveal their favourite numbers: " << numshare << " students" << endl;
     
    for(x = 0; x < totalvalids; x++){
        vnum = valid[x];
            chosen[vnum]++;
    }
     
    for(x = 1; x < 101; x++){
        if(chosen[x] > most && chosen[x] >= 2){
            most = chosen[x];
        }
         
        if(chosen[x] < least && chosen[x] >= 1){
            least = chosen[x];
        }
    }
     
    for(x = 1; x < 101; x++){
        if(chosen[x] == most){
            mchosen[z] = x;
            z++;
        }
        if(chosen[x] == least){
            lchosen[k] = x;
            k++;
        }
    }
     
    totalmost = z; 
    totaleast = k; 
     
     
    cout << endl << endl;
     
    cout << "Number(s) chosen most by the students:" << endl;
    for(x = 0; x < totalmost; x++){
        cout << mchosen[x] << " ";
    }
     
    cout << endl;
     
    cout << "Number(s) chosen least by the students: " << endl;
    for(x = 0; x < totaleast; x++){
        cout << lchosen[x] << " ";
    }
     
    fin.close();
    return 0;
}
