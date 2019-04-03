#include <iostream>
#include <fstream>
using namespace std;

int num_now = 0;
int num =0;
int array_binary_num[8] = {'0','0','0','0','0','0','0','0'};

bool perfect(int now){
    int num;
    int sum = 0;
    for (num = 1 ; num < now ; num = num + 1){
        if (now % num == 0){
            sum = sum + num;
        }
    }
    if (sum == now){
        return true;
    }
    else{
        return false;
    }
}

bool prime(int now){
    if (now % now == 0 && now % 1 == now){
        return true;
    }
    else{
        return false;
    }
}

bool perfectSquare(int now){
    int squared = 1;
    int num;
    for (num = 1 ; num <= now ; num = num + 1){
        squared = num * num;
        if ( squared == now ){
            return true;
        }
    }
    return false;
}

bool sphenic(int num_file_sphenic){
    int num;
    int count = 0;
    int prod = 1;
    for (num = 2; num <= num_file_sphenic / 2; num= num + 1){
    if (num_file_sphenic % num == 0 && prime(num) == true){
        prod = prod * num;
        count=count + 1;
        }
    }
if (count == 3 && prod == num_file_sphenic){
        return true;
    }
    else{
        return false;
    }
}
void binary(){
    int binary = num_now;
    
    while (binary != 0 || num < 8){
        array_binary_num[num] = binary % 2;
        binary = binary / 2;
        num = num + 1;
    }
}

int main (){
    ifstream anime;
    int array_all_num[101];
    int array_invalid[101];
    int array_histogram[11];
    int all_num_print = 0;
    int num_orginial = 0;
    int valid = 0;
    int invalid = 0;
    int non_reveal = 0;
    int beginning = 0;
    int invalid_begin = 0;
    int invalid_num = 0;
    bool filter = false;
    int most_pop = 0;
    int least_pop = 101;
    int new_five_num = 0;
    int reset = 0;

    anime.open("numbers.txt");
    if (!anime.is_open()){
        cout<<"File cannot be found. Try again."<<endl;
    }

    anime>>num_now;
    num_orginial = num_now;
    cout<<"Number          Perfect?          Prime?          Perfect Square?           Sphenic?          Binary Representation"<<endl;
    cout<<"======          ========          ======          ===============           ========          ====================="<<endl;
    while(num_now != -1)
    {
        if(num_now == 0)
        {
            non_reveal = non_reveal + 1;
        }
        else if(num_now > 100 || num_now < -1)
        {
            invalid = invalid + 1;
            invalid_num = invalid_num + 1;
            array_invalid[invalid_num] = num_now;
        }
        
        else if (num_now <= 100 && num_now >= 1)
        {
            valid = valid + 1;

                if(num_now >= 1 && num_now <= 10){
                    array_histogram[1] = array_histogram[1] + 1;
                }
                if(num_now >= 11 && num_now <= 20){
                    array_histogram[2] = array_histogram[2] + 1;
                }
                if(num_now >= 21 && num_now <= 30){
                    array_histogram[3] = array_histogram[3] + 1;
                }
                if(num_now >= 31 && num_now <= 40){
                    array_histogram[4] = array_histogram[4] + 1;
                }
                if(num_now >= 41 && num_now <= 50){
                    array_histogram[5] = array_histogram[5] + 1;
                }
                if(num_now >= 51 && num_now <= 60){
                    array_histogram[6] = array_histogram[6] + 1;
                }
                if(num_now >= 61 && num_now <= 70){
                    array_histogram[7] = array_histogram[7] + 1;
                }
                if(num_now >= 71 && num_now <= 80){
                    array_histogram[8] = array_histogram[8] + 1;
                }
                if(num_now >= 81 && num_now <= 90){
                    array_histogram[9] = array_histogram[9] + 1;
                }
                if(num_now >= 91 && num_now <= 100){
                    array_histogram[10] = array_histogram[10] + 1;
                }

             if(array_all_num[num_now] == 0){
                filter = true;
             }

             array_all_num[num_now] = array_all_num[num_now] + 1;

            
            
             if(filter == true){
                num_now = num_orginial;
                perfect(num_now);
                num_now = num_orginial;
                prime(num_now);
                num_now = num_orginial;
                perfectSquare(num_now);
                num_now = num_orginial;
                sphenic(num_now);
                num_now = num_orginial;
                binary();

                cout<<num_orginial<<"              ";
                if (perfect(num_now)){
                    cout<<"Y                 ";
                }
                else{
                    cout<<"N                 ";
                }
                if (prime(num_now)){
                    cout<<"Y               ";
                }
                else{
                    cout<<"N               ";
                }
                if (perfectSquare(num_now)){
                    cout<<"Y                         ";
                }
                else{
                    cout<<"N                         ";
                }
                if (sphenic(num_now)){
                    cout<<"Y                 ";
                }
                else{
                    cout<<"N                 ";
                }
    for(beginning = 0 ; beginning < 7 ; beginning = beginning + 1 ){
        cout<<array_binary_num[beginning];
    }
    cout<<endl;
    }
}
            
            num = 0;
            for (reset=0;reset<7;reset=reset+1){
                array_binary_num[reset]=0;
            }
            filter = false;
            
            
            anime>>num_now;
            num_orginial = num_now;
        }

for(all_num_print = 0; all_num_print <=100; all_num_print = all_num_print + 1){
    if(array_all_num[all_num_print] > most_pop && array_all_num[all_num_print] > 1){
        most_pop = array_all_num[all_num_print];
    }
    else if(array_all_num[all_num_print] < least_pop && array_all_num[all_num_print] > 0){
        least_pop = array_all_num[all_num_print];
    }
}

cout<<endl;
cout<<"Number of valid favorite numbers: "<<valid<<endl;
cout<<"Number of invalid favorite numbers: "<<invalid<<endl;
cout<<"Number of non-revealed favorite numbers: "<<non_reveal<<endl;
cout<<"The most popular number was: "<<most_pop<<endl;
cout<<"The least popular number was: "<<least_pop<<endl;
cout<<"Invalid numbers received from file were: "<<endl;

        for (invalid_begin = 1 ; invalid_begin <= invalid_num ; invalid_begin = invalid_begin + 1){
            cout<<array_invalid[invalid_begin]<<" , ";
            new_five_num = new_five_num + 1;
            if (new_five_num % 5 == 0){
                cout<<endl;
            }
        }
    cout<<endl<<endl;
    cout<<"RANGE           HISTOGRAM"<<endl;
    cout<<"========================="<<endl;
    cout<<"1 - 10            ";
    while(array_histogram[1] != 0)
    {
        if (array_histogram[1] % 5 == 0)
        {
            cout<<"*";
        }
        array_histogram[1] = array_histogram[1] - 1;
    }
    cout<<endl;


    cout<<"11 - 20           ";
    while(array_histogram[2] != 0)
    {
        if (array_histogram[2] % 5 == 0)
        {
            cout<<"*";
        }
        array_histogram[2] --;
    }
    cout<<endl;


    cout<<"21 - 30           ";
    while(array_histogram[3] != 0)
    {
        if (array_histogram[3] % 5 == 0)
        {
            cout<<"*";
        }
        array_histogram[3] --;
    }
    cout<<endl;


    cout<<"31 - 40           ";
    while(array_histogram[4] != 0)
    {
        if (array_histogram[4] % 5 == 0)
        {
            cout<<"*";
        }
        array_histogram[4] --;
    }
    cout<<endl;


    cout<<"41 - 50           ";
    while(array_histogram[5] != 0)
    {
        if (array_histogram[5] % 5 == 0)
        {
            cout<<"*";
        }
        array_histogram[5] --;
    }
    cout<<endl;


    cout<<"51 - 60           ";
    while(array_histogram[6] != 0)
    {
        if (array_histogram[6] % 5 == 0)
        {
            cout<<"*";
        }
        array_histogram[6] --;
    }
    cout<<endl;


    cout<<"61 - 70           ";
    while(array_histogram[7] != 0)
    {
        if (array_histogram[7] % 5 == 0)
        {
            cout<<"*";
        }
        array_histogram[7] --;
    }
    cout<<endl;


    cout<<"71 - 80           ";
    while(array_histogram[8] != 0)
    {
        if (array_histogram[8] % 5 == 0)
        {
            cout<<"*";
        }
        array_histogram[8] --;
    }
    cout<<endl;


    cout<<"81 - 90           ";
    while(array_histogram[9] != 0)
    {
        if (array_histogram[9] % 5 == 0)
        {
            cout<<"*";
        }
        array_histogram[9] --;
    }
    cout<<endl;


    cout<<"91 - 100          ";

    while(array_histogram[10] != 0)
    {
        if (array_histogram[10] % 5 == 0)
        {
            cout<<"*";
        }
        array_histogram[10] --;
    }
    cout<<endl;
    cout<<endl;



anime.close();
return 0;
}

