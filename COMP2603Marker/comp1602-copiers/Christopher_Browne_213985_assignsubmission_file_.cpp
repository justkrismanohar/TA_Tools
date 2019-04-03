#include<iostream>
#include<fstream>

using namespace std;

char isPerfect(int num) //Checks if the number is a perfect number
{
	
	int i, ans, ans2;

	ans2 = 0;
	
	for(i=1; i < num; i++)
	{
		ans = num % i;
		
		if(ans == 0)
		{
			ans2 = i + ans2;
		}
	}
	
	if(ans2 == num)
	{
		return 'Y';
		
	}
	else
	{
		
		
		return 'N';
	}
}

char isPrime(int num)//Checks if the number is a prime number
{
	int i, count;
	
	count = 0;
	
	for(i=1;i<=num;i++)
	{
		if(num % i == 0)
		{
			count++;
		}
	}
	
	if((count > 2) || (count==1))
	{
		return 'N';
	}
	else
	{
		return 'Y';
	}
	
	
}

char isPerfSquare(int num)//Checks if the number is a perfect square
{
	int i, cal1, cal2;
	
	for(i=1;i<num;i++)
	{
		cal1 = num / i;
		cal2 = cal1 * i;
	}
	
	if(cal2 == num)
	{
		
		return 'Y';
	}
	else
	{
		
		return 'N';
	}
}

char isSphenic(int num)//Checks if the number is a sphenic
{
	int i,z,q,count,countp,t;
	
	countp = 0;
	count =0;
	t=1;
	
	for(i=1; i < num; i++)
	{
		z = num % i;
		
		if(z==0)
		{
			for(q=1;q<=i;q++)
			{
				if(i%q == 0)
				{
					count++;
				}	
			}

			if((count==2)&&(count!=1))
			{
				countp++;
				t = t*i;
			}
			
			count = 0;
		}
	}
	
	if((t==num)&&(countp==3))
	{
		return 'Y';
	}
	else
	{
		return 'N';
	}
}

void Binary(int num)//Checks if the number is a binary number
{
	int x,i,z,q,l,r,m,arrval,val;
	arrval = 8;
	int bin[arrval];
	
	q = num;
	l = num;
	r=0;
	m =0;
	
	for(i=0;i<arrval; i++)
	{
		bin[i]= 0;/*Fill the array positions with zeros*/
	}
	
	for(i=0; i< q; i++) 
	{
		x = l % 2;/*conerts to binary*/
		
	
		
		bin[r] = x;
		
		
		l = l /2;
		
		if(l == 0)
		{
			i = q;
		}
		
		r= r + 1;	
	}
	
	m=arrval-1;
	
	for(i=m;i>=0;i--)
	{
		cout<<""<<bin[i];/*print out the array in reverse*/
	}
}


int main()//main function
{
	int num,countval,invalid,countno,v,countl,m,countr;
	char resisperf,re_isprime,re_isPerfSqu,reisSphenic;
	int arr[50],arrvalid[1000],arrcpt[1000];
	
	ifstream inputf1,inputf12;
	
	invalid = 0;  
	countval = 0;
	countno = 0;
	v=0;
	countl=0;
	countr = 0;
	
	inputf1.open("numbers.txt");
	
	if(inputf1.is_open()== false)
	{
		cout<<"Error Loading file"<<endl;
	}
	else
	{
		inputf1 >> num;
		
		cout<<"Number	"<<"Perfect? "<<"Prime? "<<"Perfect Square? "<<"Sphenic?  "<<"Binar Equiv	"<<endl;
		cout<<"======	"<<"=======	"<<"======	"<<"============== "<<"======	"<<" =============	"<<endl;
		
		while(num != -1)
		{
			
			if((num >= 1) && (num <=100))
			{
				arrvalid[countval++] = num;
				resisperf = isPerfect(num);
				re_isprime = isPrime(num);
				re_isPerfSqu=isPerfSquare(num);
				reisSphenic=isSphenic(num);
				cout<<""<<num;
				cout<<"\t"<<resisperf;
				cout<<"\t"<<re_isprime;
				cout<<"\t"<<re_isPerfSqu;
				cout<<"\t\t"<<reisSphenic;
				cout<<"\t  ";
				Binary(num);/*Calls binary function*/
				cout<<endl;	
			}
			else
			{
				if((num < 0) || (num >100)) 
				{
					invalid++;	
					arr[v] = num;
					v++;
				}
			}
			if(num == 0)
			{
				countno++;
			}
			
			inputf1>>num;
		}
	}
	
	cout<<endl;
	
	cout<<"List of all invalid characters:"<<endl;
	
	for(m=0;m<v;m++)
	{
		cout<<" "<<arr[m];
		countl++;
		
		if(countl == 5)
		{
			cout<<endl;
			countl=0;
		}	
	}
	cout<<endl;
	cout<<endl;
	
	cout<<"Range     "<<"Histogram"<<endl;
	cout<<"======================="<<endl;
	
	int stat=1;
	int last = 10;
	int x;
	int y = 0;
	int r = 0;
	int q;
	
	while(r < 10)
	{
		cout<<stat<<"-"<<last;
		cout<<"\t   ";
		for(x=0;x<countval;x++)
		{
			
			
			if((arrvalid[x] >= stat ) && (arrvalid[x] <=last))
			{
				y++;			
			}	
		}
		
		y = y / 5;
		
		for(q=0;q<y;q++)
		{
			cout<<"*";
		}
		
		y=0;
		
		stat= stat +10;
		last= last +10;
		r++;
		
		cout<<endl;	
	}
	
	for(x=0; x<countval;x++)
	{
		arrcpt[x]=0;
	}
	
	cout<<endl;
	cout<<endl;
	cout<<"Number of valid favourites: "<<countval<<endl;
	cout<<"Number of Invalid: "<<invalid<<endl;
	cout<<"Number of Hidden Choices: "<<countno<<endl;
	
	
	for(x=0; x < countval; x++)
	{
		//r = arrvalid[x];
		
		for(q=0;q<countval;q++)
		{
			if(arrvalid[x]==arrvalid[q])
			{
				arrcpt[x] = arrcpt[x] + 1;
			}
		}
		
	//	cout<<arrvalid[x]<<" "<<arrcpt[x]<<endl;
	}
	
	cout<<endl;
	
	
	int dup[100];
	int z =0;
	int max = 0;
	int number;
	
	for(x=0;x<countval;x++)
	{
		for(q=1;q<countval/2;q++)
		{
			if(arrcpt[q]>max)
			{
				max = arrcpt[x];
				number= arrvalid[x];
			}
		}
	}
	cout<<"Number Picked most: "<<number<<" Chosen " <<max <<" Times"<<endl;
	cout<<endl;
	
	cout<<"Other Recurrent Numbers: ";
	for(x=0;x<countval;x++)
	{
		if(arrcpt[x] >=2)
		{
		  cout<<" "<<arrvalid[x];
		}
	}
	
	cout<<endl;
	cout<<endl;
	
	cout<<"Least chosen numbers: ";
	
	for(x=0;x<countval;x++)
	{
		if(arrcpt[x] == 1)
		{
		 cout<<" "<<arrvalid[x];
		}
	}
	inputf1.close();
	
	return 0;
}
