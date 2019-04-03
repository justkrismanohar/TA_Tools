#include <iostream>
#include <fstream>

using namespace std;

bool isPerfect (int num){
	int i, sum=0;

		for(i=1; i<=num/2; i++)
			if(num%i==0)
				sum=sum+i;

		if(sum==num)
			return true;

	return false;
}

bool isPrime (int num){

		if(num==1)
            return false;

		for(int i=2; i<=num/2; i++)
			if(num%i==0)
				return false;

	return true;
}

bool isPerfectSquare (int num){
	int i, sq;

		for(i=1; i<=num; i++){
			sq=i*i;

				if( sq==num)
				return true;
		}

	return false;
}

bool isSphenic (int num){
	int i, count=0, prod=1;

		for(i=2; i<=num/2; i++)
			if(num%i==0 && isPrime(i)){
				prod=prod*i;
				count++;
			}

		if( count==3 && prod==num)
			return true;

	return false;
}

void printBinary (int num){
	int i, rem [9], count=1;

		for (i=1; i<9; i++)
			rem[i]=0;

		while (num!=0){
			rem[count]=num%2;
			num=num/2;
			count++;
		}

		for(i=8; i>=1; i--)
			cout<<rem[i];

}

void printStars(int n){

	for(int i=1; i<=n; i++)
		cout<<"*";

}

int main (){
	ifstream in;
	int i, num, number;
	int distinct[100], invalid[10000], counter[101], indistinct[10000];
	int nofav=0, invalidCount=0, count=0, total=0, start=1, end=10, n=0, tracker=0, max=0, min=99999, repeat=0;
	bool condition=false;


	in.open("numbers.txt");

		if (!in.is_open()){
			cout<<"Error opening input file. Aborting...";
			return 0;
		}

	in>>num;

		if (num==-1){
			in.close();
			return 0;
		}

	cout<<"Number \t Perfect? \t Prime? \t Perfect Square? \t Sphenic? \t Binary Equiv. "<<endl;
	cout<<"====== \t ======== \t ====== \t =============== \t ======== \t ============="<<endl<<endl;

		for(i=0; i<100; i++)
			distinct[i]=0;

		for(i=1; i<101; i++)
			counter[i]=0;

		while(num!=-1){
				if(num==0){
					nofav++;
					in>>num;
				}

				else{
					if(num<0||num>100){
						invalid[invalidCount]=num;
						invalidCount++;
						in>>num;
					}

					else{

						i=0;

							while (repeat==0 && i<count){
								if(num==distinct[i])
									repeat++;

									i++;
							}

							if(repeat==0){
								indistinct[total]=num;
								total++;

								distinct[count]=num;

								cout<<num<<"\t   ";

									if(isPerfect(num))
										cout<<"Y\t\t   ";

										else
											cout<<"N\t\t   ";

									if (isPrime(num))
										cout<<"Y\t\t\t";

										else
											cout<<"N\t\t\t";

									if (isPerfectSquare(num))
										cout<<"Y\t\t   ";

										else
											cout<<"N\t\t   ";

									if(isSphenic(num))
										cout<<"Y\t\t   ";

										else
											cout<<"N\t\t   ";


								printBinary(num);
								cout<<endl;
								count++;
								in>>num;
							}

							else{
								indistinct[total]=num;
								total++;
								repeat=0;
								in>>num;
							}

					}
				}
		}

	cout<<endl<<endl<<"Invalid Entries:"<<endl;
	cout<<"-------------------"<<endl;

		if (invalidCount==0)
			cout<<"None."<<endl;

		else{

			for(i=0; i<invalidCount; i++){
				cout<<invalid[i]<<" ";

					if((i+1)%5==0)
					cout<<endl;

			}

			if(i%5!=0)
				cout<<endl;

	}

	cout<<"-------------------"<<endl<<endl;


		for (i=0; i<total; i++){
			number=1;

				while (number<101 && !condition){
						if( indistinct[i]==number){
							counter[number]++;
							condition=true;
						}

					number++;
				}
				
			condition=false;
		}


	cout<<"Range \t Histogram"<<endl;
	cout<<"=========================="<<endl;

		while (end<101){
			for(i=start; i<=end; i++)
				n=n+counter[i];

			n=n/5;
			cout<<start<<"-"<<end<<"\t\t";
			printStars(n);
			cout<<endl;

			n=0;
			start=start+10;
			end=end+10;
		}

	cout<<endl<<"The amount of students who specified valid favourite numbers: "<<total<<endl;
	cout<<"The amount of students who specified invalid favourite numbers: "<<invalidCount<<endl;
	cout<<"The amount of students who did not reveal their favourite number: "<<nofav<<endl<<endl;

		for(i=1; i<101; i++){
			if(counter[i]>1)
				tracker=tracker+1;
		}

		if(tracker==0)
			cout<<"No specific number was chosen the most."<<endl;

		else{
			cout<<"The number/s that was/were chosen the most by the students: "<<endl;

				for(i=1; i<101; i++){
					if (counter[i]>max)
						max=counter[i];
				}

				if (max==2){

					for(i=1; i<101; i++)
						if( counter [i]==2)
							cout<<i<<" ";
				}

				else{

						for(i=1; i<101; i++)
							if(counter[i]==max)
								cout<<i<<" ";
				}
		}

	cout<<endl<<endl<<"The number/s that was/were chosen the least by the students: "<<endl;

		for(i=1; i<101; i++)
			if(counter[i]<min && counter[i]!=0)
				min=counter[i];

		for(i=1; i<101; i++)
			if(counter[i]==min)
				cout<<i<<" ";

		if(min==99999)
			cout<<"No specific number was chosen the least. ";

in.close();

return 0;

}

