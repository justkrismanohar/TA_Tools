#include <iostream>
#include <fstream>
using namespace std;

void isNumPerfect(int num){
	
	int count;
	int div;
	int sum;
	sum = 0;
	
	for(count =1;count < (num / 2); count= count+1){
		div = num % count;
		
		if(div ==0){
			sum= sum + count;
		}
	}
	
	if (sum == num){
		cout<<"Yes";
	}
	else {
			cout<<"No";
		}
	}


void isNumPerfectSquare (int num){
	int count;
	int i;
	i = 0;
	
	for(count = 1; count <= (num / 2);count= count+1){
		if(count*count==num){
			i=i+1;
	}	
	}
	
	if(i>0){
		cout<<"Yes";
	}
	else
		{
  		cout<<"No";
	}
}

    bool isNumPrime (int num){
	
	int count;
	int div;
	int i;
	i = 0; 
	
	if(num==1){
		return false;
	}
	else{
	
	for(count = 2;count <= num / 2;count = count + 1){
		
		div = num % count;
	
	if(div == 0){
		return false;
	}
}
}
	return true;
	
 }

	
	bool isNumSphenic (int num){
		int l,i,count,p;
		bool sph;
		count = 0;
		p = 1;
		l = num;
		i = 2;
		
		for (i = 2; i <= l/2;i = i + 1){

		if (((l % i) == 0) && (isNumPrime(i))){
			p = p * i;
			count = count + 1;
		}
	}
		if ((count == 3) && (p == l)){
			sph = true;
		}
		else {
			sph = false;
		}
		return sph;
	}
	

	void Binary(int num){
		int rem[10];
		int count;
		int p;
		int bin;
		int i;
		i = 0;
 	    count = 0;
 	    
 	    for (i = 0;i <10;i = i + 1){
 	    	rem[i] = 0;
		 }
 	    
 	while( num > 0){
 		rem[count] = num % 2;
 		num = num/2;
 		count = count+1;
	 }
	
	for (p=7;p>=0;p=p-1){
		cout<< rem[p];
	}
	
	for (i = 0;i <10;i = i + 1){
 	    	rem[i] = 0;
		 }
	
}
	
	
	int main (){
		ifstream inputFile;
		int num,neutral,invalidNo;
		int invalidNos[10000];
		int i,validNo,o;
		int counter;
		int count,invalid,p,k,intervals;
		int ran[10];
		int votes[101];
		int max,highestnum;
		int numberhigh [1000];
		neutral = 0;
		intervals = 1;
		i = 0;
		o = 0;
		max = 0;
		counter = 0;
		validNo = 0;
		invalidNo = 0;
		
		inputFile.open("numbers.txt");
		
		if(!inputFile.is_open()){
			cout<<"Error in opening file!"<<endl;
			return 0;
		}
		
		for (count = 0;count < 101;count= count + 1){
			votes[count] = 0;
		}
	
	cout<<"Number        Perfect?        Prime?        Perfect Square?       Sphenic?      Binary Equivalent "<<endl;   
	cout<<"=======      =========       =======        ===============      =========      ================="<<endl;
	
	inputFile>>num;
	while(num!=-1){
	
    
	if(num>=1 && num<=100){
		
		validNo = validNo+1;
		votes[num]= votes[num] + 1;

	
		cout << num <<"             ";
		isNumPerfect(num);
		
		cout <<"                ";
		
		if(isNumPrime(num) == true){
		cout<<"Yes";
	}
	    else 
		cout<<"No";
	
		cout <<"                ";
		isNumPerfectSquare(num);
	
		cout <<"              ";
		
	    if(isNumSphenic(num) == true){
		cout<<"Yes";
	}
    	else 
		cout<<"No";
	
		cout <<"            ";
		Binary(num);
		cout <<endl;     
		
	
		
	
	if((num >= 1) && (num <= 10)){
		ran[1] = ran[1]+1;
	}
	
	if((num > 10)&& (num <= 20)){
		ran[2] = ran[2]+1;
	}
	
	if((num > 20) && (num <= 30)){
		ran[3] = ran[3]+1;
	}
	
	if((num > 30) && (num <= 40)){
		ran[4] = ran[4] +1;
	}
	if((num > 40) && (num <= 50)){
		ran[5] = ran[5] +1;
	}
	
	if((num > 50) && (num <= 60)){
		ran[6] = ran[6] +1;
	}
	
	if((num > 60) && (num <= 70)){
		ran[7] = ran[7] +1;
	}
	
	if((num > 70) && (num <= 80)){
		ran[8] = ran[8] +1;
	}
	
	if((num > 80) && (num <= 90)){
		ran[9] = ran[9] +1;
	}
	
	if((num > 90) && (num <= 100)){
		ran[10] = ran[10] +1;
	}
	}
	

	if(num == 0){
		neutral = neutral +1;
	}
	
	if( (num < 0 )|| (num > 100)){
		invalidNo = invalidNo + 1;
		invalidNos[i] = num;
		i= i+1;
	}
	inputFile>>num;
}
	cout<<endl;
	cout<<"----------------------------------------------------------------------------------------------"<<endl;
	cout<<"Invalid Numbers : "<<endl;
	
	for(count=0;count<i;count=count+1){
		invalid = invalidNos[count];
		cout << invalid;
		cout<<" ";
		
		counter=counter+1;
		
		if(counter==5){
		cout<<endl;
		counter=0;	
	}

}
	cout<<endl;
	cout<<"---------------------------------------------------------------------------------------------"<<endl;
	cout<<endl;
	
	cout<<"Range         |       Histogram"<<endl;
	cout<<"--------------------------------"<<endl;
	
    	 for (count = 1; count <= 10;count = count + 1){
		 cout << intervals << " - " << intervals + 9 << " | ";
    	p = ran[count] / 5;
        
    
    	for (k = 1 ; k <= p;k = k + 1){
    		
    		cout << "*";
    	}
    	intervals = intervals + 10;
    	cout<<endl;
		
	}
	
	cout<<endl<<endl;
	cout<<"-----------------------------------------------------------------------"<<endl;
	cout<<"                     Statistical INFO.                            "<<endl;
	cout<<"Amount of Valid favourite numbers : "<< validNo <<endl;
	cout<<"Amount of Invlaid Numbers : "<< invalidNo <<endl;
	cout<<"Amount of Anonymous favourite numbers : "<< neutral <<endl;
	
	cout<<"Number(s) with 2 or more votes : ";
	

    for (count = 1;count < 101;count = count + 1){
    	
	if (max < votes[count]){
		max = votes[count];
		highestnum = count;
}
	}
    for (count = 1; count < 101; count = count + 1){
    	if (max == votes[count]){
    		numberhigh[o] = count;
    		o = o + 1;
		}
	}


   for (count = 0;count < o; count = count + 1){
   	    cout << numberhigh[count] << " ";
   }
   
   cout << endl;
   cout <<"Numbers with 1 or less votes : " << endl;
   
   for (count = 1;count < 101;count = count + 1){
	if (votes[count] == 1){
	
	cout << count << " ";
}
}
    cout << endl;
    cout <<"-----------------------------------------------------------------------";
inputFile.close();
return 0;
}

