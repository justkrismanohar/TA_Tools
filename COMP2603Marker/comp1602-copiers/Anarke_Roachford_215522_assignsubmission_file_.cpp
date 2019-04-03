#include<iostream>//816009872
#include<fstream> 
using namespace std;
//B (I)
char perfect(int num){
	
	if (num%2==0)
	return 'Y';
	else return 'N';
}
//B (II)
char prime(int num){
		if (num%2!=0)
	return 'Y';
	else return 'N';
}
//B (III)
char persquare(int num){//recheck
	int i,count=1;
	double product;
		
	while (count!= 10){
		product=count*count;
		count++;
		if (product==num)
		return 'Y';
		
	}
	return 'N';
}
//B (IV)
char issphenic (int num){
	
	if(num==30) {
	   cout<<"Y";
	} else if( num==42) {
	   cout<<"Y";
	} else if(num==66) {
	  cout<<"Y";
	} else if( num==70) {
	   cout<<"Y";
	} else if(num==78) {
	  cout<<"Y";
	} else {
	  cout<<"N";
	}
}
//B (V)
int binary(int bin[],int num,int size){
int remain,i=0;
	
	while (i!=size){
		remain=num%2;
		num=num/2;
		bin[i]=remain;
		i++;
	}
return i;
}
int getmax(int value[],int totalstored){
    int max;  	
		int maxcount = 0;
		
		for (int i=0;i<totalstored;i++){
		   int count=1;
		   
		   for (int j=i+1;j<totalstored;j++)
		       if (value[i]==value[j])
		           count++;
		           
		   if (count>maxcount)
		      maxcount = count;
		}
		
		for (int i=0;i<totalstored;i++)
		{
		   int count=1;
		   for (int j=i+1;j<totalstored;j++)
		       if (value[i]==value[j])
		           count++;
		   if (count==maxcount)
		        max=value[i];
		}
	return max;
}
int getmin(int value[],int totalstored){
    int min;  	
		int mincount = 0;
		
		for (int i=0;i<totalstored;i++){
		   int count=1;
		   
		   for (int j=i+1;j<totalstored;j++)
		       if (value[i]!=value[j])
		           count++;
		           
		   if (count>mincount)
		      mincount = count;
		}
		
		for (int i=0;i<totalstored;i++)
		{
		   int count=1;
		   for (int j=i+1;j<totalstored;j++)
		       if (value[i]!=value[j])//recheck
		           count++;
		   if (count<mincount)
		   
		        min=value[i];
		}
	return min;
}
int perline(float num[],int length){
	for(int i = 1; i <= length; i++){
    cout << num[i] << "  ";
        if(i % 5 == 0)
            cout << endl;
}
return 0;
}
int starperline(int length){
	
	while(length>5){
	
        cout << "" << " * ";
        length=length-5;
}
return 0;
}
int main(){
// A	
	ifstream inputfile;
	int num;
	inputfile.open("number.txt");
	if(!inputfile.is_open()){
		cout<<"Error opening input file.Aborting....";
		return 0;
	}
	
	
	char per, pri, squ,sph;
	int bin[8],size=8,element,count;
	float invalid[200];
	int numinval,i=0,max,j;
	int Totalvaildfav=0,Totalinvaildfav=0,Totalnonrevealfav=0;
	int value[200],totalstored,numvalue=0;
	int line1=0,line2=0,line3=0,line4=0,line5=0,line6=0,line7=0,line8=0,line9=0,line10=0;
	
	inputfile>>num;

	cout<<"Number   perfect?   Prime?  Perfect Square?  Sphenic?  Binary Equiv. "<<endl;
	cout<<"======   ========   ======  ===============  ========  =============  "<<endl;
	
    while(num!=-1){
			
	
//		    
	
	if(num>=1&& num<=100){
//E (I)	
		Totalvaildfav++;
	
		per=perfect(num);
		pri=prime(num);
		squ=persquare(num);
		

	
		element=binary(bin,num,size);
		
		cout<<num<<"           "<<per<<"        "<<pri<<"            "<<squ<<"             ";
		cout<<issphenic(num);
		cout<<"         ";

		for(int i=0;i<element;i++){
    	cout<<bin[i];
		}
    	cout<<endl;
		
	}
	else{

		
			invalid[i]=num;
			i++;
			numinval=numinval+1;
			
			    if(num==0){
		    	Totalnonrevealfav++;
		    
		    	
			}else
	
				Totalinvaildfav=Totalinvaildfav+1; 
			
		}
		
		if ( num >= 1 && num <= 10 ){
		   line1++;
		} else if(num >= 11 && num <= 20) {
		   line2++;
		} else if(num >= 21 && num <= 30) {
		  line3++;
		} else if(num >= 31 && num <= 40) {
		   line4++;
		} else if(num >= 41 && num <= 50) {
		  line5++;
		} else if(num >= 51 && num <= 60) {
		  line6++;
		} else if(num >= 61 && num <= 70) {
		  line7++;
		} else if(num >= 71 && num <= 80) {
		  line8++;
		} else if(num >= 81 && num <= 90) {
		  line9++;
		} else if(num >= 91 && num <= 100) {
		  line10++;
		}
	
		  
		value[j]=num;
			j++;
			numvalue=numvalue+1;
				    
    inputfile>>num;
   }
   
    cout<<endl;
    cout<<"Invalid Numbers:"<<endl; 
	cout<< perline(invalid,numinval)<<endl<<endl;
	
	cout<<"Histogram                               Range"<<endl;
	cout<<"==========================================================="<<endl;
	cout<<"                                 1-10                            "<<starperline(line1)<<endl;
	cout<<"                              11-20                            "<<starperline(line2)<<endl;
	cout<<"                                 21-30                            "<<starperline(line3)<<endl;
	cout<<"                                    31-40                            "<<starperline(line4)<<endl;
	cout<<"                                    41-50                            "<<starperline(line5)<<endl;
	cout<<"                                    51-60                            "<<starperline(line6)<<endl;
	cout<<"                                 61-70                            "<<starperline(line7)<<endl;
	cout<<"                                    71-80                            "<<starperline(line8)<<endl;
	cout<<"                                    81-90                            "<<starperline(line9)<<endl;
	cout<<"                                    91-100                            "<<starperline(line10)<<endl;

   
   	cout<<endl;
	cout<<endl;
   	cout<<"The amount of students who specified valid favourite numbers:"<<Totalvaildfav<<endl;
   	cout<<"The amount of students who specified invalid favourite numbers:"<<Totalinvaildfav<<endl;
   	cout<<"The amount of students who did not reveal their favourite number. :"<<Totalnonrevealfav<<endl<<endl;
   	

	max=getmax(value,numvalue);
	cout<<"The number/s that was/were chosen the most by the students: "<<max<<endl;
	

	
	cout<<"The number/s that was/were chosen the least by the students: "<<getmin(value,numvalue)<<endl;
	
	
   	inputfile.close();
   	return 0;
}
	
