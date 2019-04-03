#include <iostream>
#include <fstream>
using namespace std;

int size (){
	ifstream input;
	int x=0, num;
	input.open("numbers.txt");
		if(!input.is_open()){
			return -1;
		}
	input>>num;
		while(num!=-1){
			x=x+1;
			input>>num;
		}
	input.close();
return x;	
}
bool perf(int x){
	bool y;
	y=false;
	if (x==1){
	 return y;
	}
	int num=1;
		for(int a=2;a<=x/2;a=a+1){
			if(x%a==0)
				num=num+a;
		}
		if (x==num)
			y=true;
	return y;
}
bool pri(int x){
	bool y;
	y=true;
	if (x==1){
	 y=false;
	 return y;
	}
	for(int a=2;a<=x/2;a=a+1)
	if(x%a==0)
	y=false;
	return y;
}

bool perfect_s(int x){
	bool y;
	y=false;
	int square;
	int a;
	for(a=1;a<=x;a=a+1){
	square=a*a;
	if (x==square){
	y=true;
	return y;
	}
}
return y;	
}
bool isSph(int x){
	int i,j,k, count, product,pro1,pro2;
	product=1;
	bool y;
	y=false;
		for(i=2;i<x/2;i=i+1){
				if (pri(i)==1)
					pro1=i;
			j=i+1;
				while (j<=x/2){
						if (pri(j)==1){
							pro2=pro1*j;
							k=j+1;
							j=x;
								while (k<x/2){
										if (pri(k)==1){
											product=pro2*k;
												if (product==x){
													y=true;
													k=x;
												}
										}
									k=k+1;
								}
						}
					j=j+1;
				}
		
		}
	return y;
}

int bin(int x){
	int binary=0;
	binary=x%2;
	return binary;
}
int main(){
	int list_size;
	list_size=size();
		if (list_size==-1){
        	cout<<"NO FILE DETECTED"<<endl;
        	return 0;
		}
	int histo[10]={0,0,0,0,0,0,0,0,0,0}, binary[8]={0,0,0,0,0,0,0,0};
	int fav_num[list_size];
	int x=0,a=0,c=1, d=10, i ,dist_count=0 ,b,num;
	int no_rev=0,valid_count=0,invalid_count=0;
	int star_amt;
	ifstream num_input;
	num_input.open("numbers.txt");
	if(!num_input.is_open()){
        cout<<"NO FILE DETECTED"<<endl;
        return 0;
		}
	num_input>>fav_num[x];
		while(x<list_size){
			x=x+1;
			num_input>>fav_num[x];
		}
	x=x-1;
		while (a<10){
				for (i=0;i<x;i=i+1){
						if (fav_num[i]>=c && fav_num[i]<=d ){
		 					histo[a]=histo[a]+1;
						}
				}
			c=c+10;
			d=d+10;
			a=a+1;
		}
	bool test;
	b=0;
		for(a=0;a<10;a=a+1){
			dist_count=dist_count+histo[a];
		}
    int dist_num[dist_count];
	int invalid[dist_count];
		for(a=0;a<dist_count;a=a+1){
			dist_num[a]=-1;
   		}

		for(a=0;a<=x;a=a+1){
			test=true;
		        for(i=0;i<dist_count;i=i+1){
						if (fav_num[a]==dist_num[i]){
							test= false;
							i=dist_count;
						}
				}
				 		if (test==1){
				 				if (fav_num[a]>=1 && fav_num[a]<=100){
				 					dist_num[b]=fav_num[a];
				 					b=b+1;
				 					valid_count=valid_count+1;
								}
								else{
								
										if (fav_num[a]==0)
				  							no_rev=no_rev+1;
				   						else{
				   							invalid[invalid_count]=fav_num[a];
				   							invalid_count=invalid_count+1;
				   			    }
										}
						 }
		}
	bool perfect[dist_count],prime[dist_count],p_square[dist_count],shpenic[dist_count];
		for (a=0;a<valid_count;a=a+1){
				perfect[a]=perf(dist_num[a]);
				prime[a]=pri(dist_num[a]);
				p_square[a]=perfect_s(dist_num[a]);
				shpenic[a]= isSph(dist_num[a]);
		}
    cout<<endl<<"Number		Perfect?		Prime?		Perfect_square?		Shpenic		Binary";
    cout<<endl<<"======		========		======		===============		=======		======"<<endl;
		for(i=0;i<valid_count;i=i+1){
			cout<<dist_num[i]<<"\t \t";
				if (perfect[i]==1)
					cout<<"Y \t \t \t";
				else
					cout<<"N \t \t \t";
				if (prime[i]==1)
					cout<<"Y \t \t ";
				else
					cout<<"N \t \t ";
				if (p_square[i]==1)
					cout<<"Y \t \t \t";
				else
					cout<<"N \t \t \t";
				if (shpenic[i]==1)
					cout<<"Y \t \t";
				else
					cout<<"N \t \t";
			b=7;
			num=dist_num[i];
				while(num>0){
					binary[b]=bin(num);
					num=num/2;
					b=b-1;
				}
				for(int c=0;c<8;c=c+1){
					cout<<binary[c];
					binary[c]=0;
				}
			cout<<endl<<endl;
		}
		cout<<endl<<endl<<"INVALID NUMBERS"<<endl;
	i=1;
		for(a=0;a<invalid_count;a=a+1){
			cout<<invalid[a]<<"\t";
				if(i%5==0)
				cout<<endl;
			i=i+1;
		}
	cout<<endl<<endl<<"Range	Histogram"<<endl;
	cout<<"==================="<<endl;
	c=1;
	d=10;
		for(a=0;a<10;a=a+1){
			cout<<c<<"-"<<d<<"\t:";
    		star_amt=histo[a]/5;
				for(i=0;i<star_amt;i=i+1){
					cout<<"*";
				}
			cout<<endl;
			c=c+10;
			d=d+10;
		}

	cout<<endl<<endl<<endl;
	cout<<"Amount Of Students With Valid Favourite Numbers - "<<dist_count<<endl;
	cout<<"Amount Of Students With Invalid Favourite Numbers - "<<invalid_count<<endl;
	cout<<"Amount Of Students With NO Favourite Numbers - "<<no_rev<<endl;
	cout<<endl<<"Numbers that were chosen at least two times"<<endl;
	int con=0,most_amo=1,most_val=-1;
		for(a=0;a<dist_count;a=a+1){
			con=0;
	    		for(i=0;i<list_size;i=i+1){
	    				if (dist_num[a]==fav_num[i])
	    					con=con+1;
				}
				if (con>most_amo){
	   				most_amo=con;
	   				most_val=dist_num[a];
				}
		}
		
		if (most_val==-1)
    		cout<<"NO number appears more than once"<<endl;
    	else
			cout<<"Number with the most amount of votes - "<<most_val<<endl;
	cout<<endl<<"Numbers with least amount of votes"<<endl;
	
		for(a=0;a<dist_count;a=a+1){
			con=0;
	    		for(i=0;i<list_size;i=i+1){
	    				if (dist_num[a]==fav_num[i])
	    					con=con+1;
				}
				if (con==1){  
					cout<<dist_num[a]<<endl;
				}
		}
	return 0;
}

