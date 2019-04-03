#include<iostream>
#include<fstream>
using namespace std;


//print star
void printstar(int star){
	int count=0;
 for (int d=0;d<star;d++){
 	cout<<"*";
 	}
 }

//max
int frequent(int students[],int num){
	int list[200]={0},max=0;
	for(int i=0;i<num;i++){
		list[students[i]]=list[students[i]]+1;}
		
for(int w=0;w<num;w++){

	if(list[w]>=max)
	max=list[w];
		
}
	return max ;	
		
	}
//least
int frequent1(int students[],int num){
	int list[200]={0},min=100;
	for(int i=0;i<num;i++){
		list[students[i]]=list[students[i]]+1;}
		
for(int w=0;w<num;w++){

	if(list[w]<=min)
	min=list[w];
		
}
	return min ;	
		
	}






//perfect 
bool Perfect(int students){
	int sum=0;
	int i;
	//bool perfectnum=false;
	//if( students >0 ){
	for (i=1; i<students;i++){
	    if(students%i==0){
		sum=sum+i;	
		}
	}
 if (sum==students){
 	return true;
}
					
return false;}


// prime
bool prime(int students){
	bool isPrime=true;
	int i,count=0;
	for (i=1;i<students;i++ ){
                if (students% i == 0)
                    count++;
                }
    if (count > 1)
    isPrime=false;
    
    return isPrime;
}




//perfect square
bool square(int students){
	bool isSquare=false;
	int i;
	
	for(i=0;i<students/2;i++){
		int product = i*i;
		if ( product==students)
		isSquare=true;
	}
	return isSquare;
}


//sphenic
bool sphenic(int students){
	int t, count=0,product=1;
	
	for(t=2;t=students/2;t++){
	if((students%t==0)&& (prime(t))){
	product=product*t;
	count =count +1;

	}

if((count==3) && (product=students))

return true;
return false;
}
}

//binary
void binary(int students){	
int a[200], i,b[200];    
  
for(i=0; students>0; i++){    
a[i]=students%2;    
students= students/2;  
}    
    
for(i=i-1 ;i>=0 ;i--){    
    cout<<a[i];
}    

  }



// unique 
bool distinct(int students, int distinctarr[]){
	bool found=false;
	for( int i=0;i<100;i++){
	if (students==distinctarr[i])
     	found== true;
	}
	return found;
}



int main(){
	int i=0;
	int max,min,count=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0,countDis=0,countinvalid=0,zeros=0,numostudent=0;
	char result1,result2,result3,result4,binarynum;
	bool check,number,perfectn,primes, perfectsq, sphenicn;
	int students[200],distinctarr[200],invalid[200];

	
	cout<<" Number \t Perfect? \t Prime? \t Perfect square? \t Sphenic? \t Binary Equiv "<<endl;
	cout<<" ====== \t ======== \t ====== \t =============== \t ======== \t ============ "<<endl;
	cout<< endl;
	
	
//      cout<<sphenic(42)<<endl;
//	cout<<prime(3);
		
	ifstream input;
	input.open("numbers.txt");
	input>>students[i];
	while( students[i] !=-1){
				i++; numostudent=numostudent+1;
		input>>students[i];
		
	}


	
	int x=0,y=0;
	
	for(int z=0; z<i; z++){
	
if ((students[z]<1) || (students[z]>100)){
	invalid[y]=students[z];
	if(invalid[y]==0)
	zeros=zeros+1;
	y++;
	countinvalid=countinvalid+1;
	}
	else {
		check=distinct(students[z],distinctarr);
		
		if (check== false){
			distinctarr[x]= students[z];
		countDis=countDis+1;
		x++;
		}
		
		
		}
	}

	
	
	for (int e=0;e<countDis;e++){
		perfectn= Perfect(distinctarr[e]);
		primes=prime(distinctarr[e]);
		perfectsq=square(distinctarr[e]);
		sphenicn= sphenic(distinctarr[e]);
		
		
		if(perfectn==true)
			result1='Y';
			else
			result1='N';
		if(primes==true)
			result2='Y';
			else
			result2='N';
		if(perfectsq==true)
			result3='Y';
			else
			result3='N';
		if(sphenicn==true)
			result4='Y';
			else
			result4='N';
						
 cout<< distinctarr[e]<<"\t\t "<< result1<<"\t\t"<<result2<<"\t \t"<< result3<<"\t\t \t"<<result4<<" \t\t";
 binary(distinctarr[e]);
 cout<<endl;
	
}
cout<<endl;
cout<< "invalid numbers are :"<<endl;

//c
for (int j = 1; j <=countinvalid; j++){
      cout << invalid[j] << " ";
      if (j%5==0)
         cout << "\n";
              }
	
	cout<< endl;
	cout<<endl;
	//d
	cout<<"Range \t\t\tHistogram"<<endl;
	cout<<"=================================="<<endl;
	cout<<endl;
	
	
	
	cout<<"1-10  \t\t\t|";
	
		for (int d=0;d<=numostudent;d++){
		if((students[d]>=1)&&(students[d]<=10)){
			count=count+1;
		
		}
	}
printstar(count/5);cout<<endl;	

    cout<<"11-20 \t\t\t|";
for (int d=0;d<=numostudent;d++){
if((students[d]>=11)&&(students[d]<=20)){
			count2=count2+1;
	}
}

printstar(count2/5);cout<<endl;

cout<<"21-30 \t\t\t|";
for (int d=0;d<=numostudent;d++){
	if((students[d]>=21)&&(students[d]<=30)){
		count3=count3+1;
	}
	
}
printstar(count3/5); cout<<endl;

cout<<"31-40 \t\t\t|";

	
	for (int d=0;d<=numostudent;d++){
	if((students[d]>=31)&&(students[d]<=40)){
		count4=count4+1;
	
		
	}
}
	printstar(count4/5);cout<<endl;
	
	
	cout<<"41-50 \t\t\t|";
	
	for (int d=0;d<=numostudent;d++){
	if((students[d]>=41)&&(students[d]<=50)){
		count5=count5+1;
		
			
	}
}
printstar(count5/5);cout<<endl;	
	cout<<"51-60 \t\t\t|";
	
	
	
	for (int d=0;d<=numostudent;d++){
	if((students[d]>=51)&&(students[d]<=60)){
		count6=count6+1;
		
		
	}
}
	printstar(count6/5);cout<<endl;
	
	cout<<"61-70 \t\t\t|";
	for (int d=0;d<=numostudent;d++){
	if((students[d]>=61)&&(students[d]<=70)){
		count7=count7+1;
		
			
	}
}
	printstar(count7/5);cout<<endl;
	
	cout<<"71-80 \t\t\t|";
	for (int d=0;d<=numostudent;d++){
	if((students[d]>=71)&&(students[d]<=80)){
		count8=count8+1;
			
	}
}
printstar(count/5);cout<<endl;
	
	cout<<"81-90 \t\t\t|";
	for (int d=0;d<=numostudent;d++){
	if((students[d]>=81)&&(students[d]<=90)){
		count9=count9+1;
			
		
	}
}
	printstar(count9/5);cout<<endl;
	
	cout<<"91-100 \t\t\t|";
		for (int d=0;d<=numostudent;d++){
	if((students[d]>=91)&&(students[d]<=100)){
		count10=count10+1;
		
	}
}
	printstar(count10/5);cout<<endl;
		

	
	cout<<"number of students who had valid number: "<<countDis<<endl;
	cout<<"number of students who had invalid number: "<<countinvalid<<endl;
	cout<<"number of students who did not reveal their favourite number: "<<zeros<<endl;
	cout<<"numbers  that were choosen the most by students "<<frequent(students,100)<<endl;
	cout<<"numbers that were chosen the least by students"<<frequent1(students,100)<<endl;
	

	


	return 0;

}
