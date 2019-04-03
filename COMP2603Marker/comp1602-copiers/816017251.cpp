#include <iostream>
#include <fstream>
using namespace std;


void dumpArrayData(int arr[], int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
}

//helper function to align output aesthetically
void printSpaces(int n, int colWidth) {
   int width = colWidth - n + 5;
   for (int i = 0; i < width; i++)
      cout << " ";
}


//uses the distinct array's frequency values to find the most popular number(s)
void findMostPopularNumber(int arr[]) {
   int highFrequency = 0, j = 0;
   int popular[50] = {0}; //stores the numbers that have a similar frequency

   for (int i = 1; i < 101; i++) {
      if (arr[i] > highFrequency) { //more popular number found
         j = 0;
         highFrequency = arr[i];
         popular[j++] = i;
      }
      else if (arr[i] == highFrequency) //number with same frequency found
         popular[j++] = i;
   }

   if (highFrequency == 1)
      cout << "No number was picked by 2 or more students";
   else if (j == 1)
      cout << "The most chosen number is " << popular[0];
   else {
      cout << "The most chosen numbers are ";
      for (int k = 0; k < j; k++)
         cout << popular[k] << " ";
   }
   cout << endl;
}


//uses the distinct array's frequency values to find the numbers chosen the least 
void findLeastPopularNumber(int arr[]) {
   int check = 0;

   cout << "The least chosen number(s) is/are ";
   for (int i = 1; i < 101; i++) {
      if (arr[i] == 1) {
         check = 1;
         cout << i << " ";
      }
   }

   if (!check)
      cout << "(none)";
   cout << endl;
}


void displayHistogram(int arr[]) {
   int total = 0, numWidth = 0;

   cout << "Range     Histogram" << endl;
   cout << "===================" << endl;

   for (int i = 1; i < 101; i++) {
      total += arr[i];

      if (i % 10 == 0) { //start a new range
         cout << i - 9 << "-" << i;

         //determines the width of label e.g. 1-10 is 4 characters wide
         if (i > 90) numWidth = 6;
         else if (i > 10) numWidth = 5;
         else numWidth = 4;

         printSpaces(numWidth, 5);
         cout << "|";

         for (int j = 0; j < total / 5; j++)
            cout << "*";
         cout << endl;
         total = 0;
      }
   }
}


char isPrime(int n) {
   if (n <= 1) return 'N';
   if (n == 2) return 'Y';
   if (n % 2 == 0) return 'N'; // n is even and not 2
   for (int h = 3; h * h <= n; h += 2) //h will be set to 3, 5, 7, etc
      if (n % h == 0) return 'N';

   // all divisors have been tried and none are a factor
   return 'Y';
}


char isSphenic(int num) {
   int i = 0, n = num;
   int factor[10] = {0};

   if (isPrime(n) == 'Y') return 'N';

   //extract factors of 2, if any
   while (n > 1 && n % 2 == 0) {
      factor[i++] = 2;
      n = n / 2;
   }

   //n is now odd; try the odd divisors up to sqrt(n)
   int m = n;
   for (int h = 3; h * h <= m; h += 2) // h will be set to 3, 5, 7, etc
      while (n >= h && n % h == 0) {
         factor[i++] = h;
         n = n / h;
      }

   // if n > 1, it's the last factor
   if (n > 1) factor[i++] = n;

   //multiply factors to determine if num is sphenic
   int product = 1;
   for (int i = 0; i < 3; i++) {
      if (i > 0 && factor[i] == factor[i - 1])
         return 'N'; //not distinct
      product *= factor[i];
   }

   if (product == num)
      return 'Y';
   return 'N';
}


void findAndPrintBinary(int n) {
   int remainders[8] = {0};

   int i = 0;
   while (n > 0) {
      remainders[i++] = n % 2;
      n /= 2;
   }

   //need to print remainders in reverse order
   for (int i = 7; i > -1 ; i--)
      cout << remainders[i];
}


char isPerfectSquare(int n) {
   for (int i = 1; i < 11; i++) //1 to 10 since largest number is 100
      if (i * i == n) return 'Y';
   return 'N';
}


char isPerfect(int n) {
   int sumDiv = 1;

   if (n == 1) return 'N';

   for (int i = 2; i <= n / 2; i++)
      if (n % i == 0)
         sumDiv += i;

   if (n == sumDiv) return 'Y';
   return 'N';
}


//keeps a count of all numbers seen in array and is used to
//determine if the number was already processed
int isDistinct(int num, int arr[]) {
   arr[num]++;
   if (arr[num] == 1) return 1; //first time number is seen
   return 0;
}


//runs through the file once to determine the amount of numbers in file
int findAmountOfStudents(ifstream &input) {
   int count = 0, num = 0;

   input >> num;
   while (num != -1) {
      count++;
      input >> num;
   }

   return count;
}


int main(void) {
   ifstream input;

   input.open("numbers.txt");
   if (!input.is_open()) {
      cout << "numbers.txt was not found." << endl;
      cout << "Cannot proceed." << endl;
      cin.get(); //keeps the text on screen until user presses a key
      return -1;
   }

   int size = findAmountOfStudents(input);

   if (size == 0) {
      cout << "No numbers found in file." << endl;
      cout << "Cannot proceed." << endl;
      cin.get();
      return -1;
   }

   //reset file pointer to beginning of file
   input.clear();
   input.seekg(0);

   int numbers[size] = {0};
 //initializes each location in the array to 0

   for (int i = 0; i < size; i++)
      input >> numbers[i];

   input.close();

   int distinctArr[101] = {0};
   int totalValid = 0, totalInvalid = 0, totalNoReveal = 0;

   cout << "Number     Perfect?     Prime?     Perfect Square?     Sphenic?     Binary Rep." << endl;
   cout << "======     ========     ======     ===============     ========     =============" << endl;
   for (int i = 0; i < size; i++) {
      if (numbers[i] > 0 && numbers[i] < 101 && isDistinct(numbers[i], distinctArr)) {
         int numWidth = 0;
         if (numbers[i] == 100) numWidth = 3;
         else if (numbers[i] > 9) numWidth = 2;
         else numWidth = 1;

         cout << numbers[i];
         printSpaces(numWidth, 6);

         cout << isPerfect(numbers[i]);
         printSpaces(1, 8);

         cout << isPrime(numbers[i]);
         printSpaces(1, 6);

         cout << isPerfectSquare(numbers[i]);
         printSpaces(1, 15);

         cout << isSphenic(numbers[i]);
         printSpaces(1, 8);

         findAndPrintBinary(numbers[i]);
         cout << endl;
      }
   }

   int check = 0;
   cout << endl << "Invalid numbers" << endl;
   for (int i = 0; i < size; i++) {
      if (numbers[i] < 1 || numbers[i] > 100) {
         if (numbers[i] == 0)
            totalNoReveal++;
         else {
            totalInvalid++;
            cout << numbers[i] << " ";
            if (totalInvalid % 5 == 0) cout << endl;
         }
      }
      else totalValid++;
   }
   if (!check) 
      cout << "(none)";

   cout << endl << endl;
   displayHistogram(distinctArr);

   cout << endl << endl;
   cout << "Total students with valid favourite numbers..........." << totalValid << endl;
   cout << "Total students with invalid favourite numbers........." << totalInvalid << endl;
   cout << "Total students who did not reveal favourite numbers..." << totalNoReveal << endl;

   cout << endl << endl;
   findMostPopularNumber(distinctArr);

   cout << endl << endl;
   findLeastPopularNumber(distinctArr);

   cout << endl << endl;
  

    cout << "Press any key to continue. . .";
    cin.get();

   return 0;
}
