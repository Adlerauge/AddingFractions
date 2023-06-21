//adoe.cpp      21.06.2023
//addition of two fractions
#include <iostream>
#include <cmath>//pow
#include <conio.h>//getch
#include <iomanip>//setprecision
using namespace std;

const int MAX = 654;
const int B = 2;//for two fractions

int prim[MAX];

void getchcls()
{
	cout << endl;
	cout << "Press any key, please!  ";
	getch();
	system("cls");
}//getchcls()

class Fractions
{
	private:
		int numerator[B];
		int denominator[B];
		int exponent[B][MAX];
		int biggestExponent[MAX] = {0};//maximum of two exponents
		int lcm;//least common multiple

void primeFactorization()
{
	cout << "In order to get the lcm (least common multiple) get the primefactors."<<endl;
	//
	for(int j=0; j<B; j++)//
	{
		int y = denominator[j];
		cout <<endl<< "We deal with the "<<y<<":"<<endl;
		cout << "prime factorization:"<<endl;
		for(int i=0; i<y; i++)//prime factorization
		{
			while(!(y%prim[i]))//
			//while(y/prim[i] == (float)y/prim[i])
			{
				int mantisse = prim[i];
				cout << y << " is divisible by " << mantisse << endl;
				exponent[j][i]++;
				y /= mantisse;//y = y / prim[i];
			}//while
		}//for i
		cout<<endl;
	}//for j
	cout << endl;
}//function primeFactorization()

void result()
{
	cout << "In order to get the lcm, you should multiply following powers:"<<endl;
	//maximum:
	for(int j=0; j<MAX; j++)
		biggestExponent[j]=(exponent[0][j]>exponent[1][j]?exponent[0][j]:exponent[1][j]);	
	//
	for(int m=0; m<MAX; m++)
	{
		if(biggestExponent[m]==0) continue;
		cout << prim[m] << " to the power of " << biggestExponent[m] << endl;
	}//for m
}//result

	public:
		Fractions()
		{ 
			for(int m=0; m<MAX; m++)
			{
				exponent[0][m]=0;
				exponent[1][m]=0;
			}//for m
		}
		
		bool unequalDenoms()//unequal denominators
		{  
			return (denominator[0]!=denominator[1]);
		}//unequalDenoms()

int GCD1(int number1, int number2)//greatest common divisor
{
	if(number2==0) return number1;
	return GCD1(number2, number1 % number2);
}

int LCM(int number1, int number2)//least common multiple
{
	return (number1*number2)/GCD1(number1, number2);
}

void input()
{
	for(int i=0; i<B; i++)
	{	
	do
	{
		cout << "The "<<i+1<<". numerator (0..20000): ";
		cin >> numerator[i];
	} while(numerator[i] < -20000 || numerator[i] > 20000);
	do
	{
		cout << "The "<<i+1<<". denominator (1..21000, not zero): ";
		cin >> denominator[i];
	} while(denominator[i] < -21000 || denominator[i] == 0 || denominator[i] > 21000);
	}//for i
}//input()

void GCD2()//greatest common divisor
{
	int x=numerator[0];
	if(x==0)
	{
		cout<<"0 (Zero)."<<endl;
		cout<<"RETURN!"<<endl;
		cin.sync();
		cin.get();
		exit(0);
	}
	if(x<0)
	 x=-x;
	int y=denominator[0];
	if(y<0)
	y=-y;
	while(x!=y)
	if(x<y) y-=x; else x-=y;
	int gcd=x;
	cout << "The fraction can";
	if(gcd==1) cout<< " not";
	cout << " be cancelled." << endl;
	cout << "gcd (greatest common divisor): " << gcd << "."<<endl;
	//
	numerator[0] /= gcd;
	denominator[0] /= gcd;
	cout << numerator[0] << " / " << denominator[0] << endl;
}//GCD2

bool properLcmCase()//proper least common multiple
{
	lcm = LCM(denominator[0], denominator[1]);
	return (lcm < denominator[0]*denominator[1]);
}//properLcmCase()

bool denomsDivisible()
{ return denominator[0] % denominator[1] == 0 || denominator[1] % denominator[0] == 0; }

void makeCommonDenoms1()
{
	if(denominator[1] % denominator[0] == 0)
	{
		cout << "The 2. denominator is a multiple of the first." << endl;
		numerator[0] = numerator[0] * denominator[1]/denominator[0];
		denominator[0]=denominator[1];
	}
	else
	{
		cout << "The 1. denominator is a multiple of the 2." << endl;
		numerator[1]=numerator[1]*denominator[0]/denominator[1];
	}//else
	cout << "Making common denominators:  " << numerator[0] << " / " << denominator[0] <<
			" + " << numerator[1] << " / " << denominator[0] << endl;
}//Function makeCommonDenoms1

void makeCommonDenoms2()//factor to multiply
{
	cout << "You should take the lcm (the least common multiple),"<<endl;
	cout << "to make common denominators."<< endl;
	cout << "You multiply each denominator with a factor," << endl;
	cout << "so the lcm comes to the both denominators." << endl;
	getchcls();
	//
	primeFactorization();
	cout << "for the lcm, you take always the greatest exponent of each power,"<<endl;
	cout << "then multiply."<<endl;
	getchcls();
	//
	result();
	//
	cout << "The lcm is " <<lcm<<"."<<endl;
	int lcmfactor0 = lcm/denominator[0];
	int lcmfactor1 = lcm/denominator[1];
	cout << "Comment:" << endl;
	cout << "The fraction " << numerator[0] << "/" << denominator[0] << " is expanded with " << lcmfactor0 << "."<<endl;
	cout << "And "<<numerator[1] << "/"<<denominator[1] << " is expanded with "<<lcmfactor1 << "."<<endl;
	numerator[0] *= lcmfactor0;
	numerator[1] *= lcmfactor1;
	denominator[0] = lcm;
	cout << "With the same denominator (lcm): " << numerator[0] << " / " << denominator[0] << " + " << numerator[1] 
	<< " / " << denominator[0] << endl;
}//makeCommonDenoms2

void makeCommonDenoms3()
{
	cout << "In this case you should have an easy way:"<<endl;
	cout << "You multiply both denominators" << endl;
	cout << "and expand." << endl;
	numerator[0] *= denominator[1];
	numerator[1] *= denominator[0];
	denominator[0] *= denominator[1];
	cout << "With the same denominator: " << numerator[0] << " / " << denominator[0] <<
	" + " << numerator[1] << " / " << denominator[0] << endl;
}//Function makeCommonDenoms3

void add()
{
	cout << "The denominators ";
	if (unequalDenoms()) cout << "are now";
	else cout << "were already";
	cout << " same." << endl;
	cout << "addition of fractions: " << numerator[0] << " / " << denominator[0] <<
			" + " << numerator[1] << " / " << denominator[0] << endl;
	numerator[0] += numerator[1];
	cout << "added: " << numerator[0] << " / " << denominator[0] <<endl;
}//Funktion add()

void ifResultImpropFrac()//improper fraction
{
	if(numerator[0]>denominator[0] && denominator[0]!=1)
	{
		cout << numerator[0]/denominator[0] << "  " << numerator[0]%denominator[0] << " / " << denominator[0] << endl;
	}//if
}//Function ifResultImpropFrac

void resultDecimalFrac()
{
	double result = (double)numerator[0]/denominator[0];
	cout << "as a decimal fraction: " << setprecision(12) << result << endl;
}//Function resultDecimalFrac

};//class
		
int main()
{
	//Preludium:
	unsigned int counter = 0;
	//
	//Primes:
	unsigned int limit=4900;
    bool *Stroke = new bool[limit+1];
    Stroke[0]=1;
    Stroke[1]=1;
    for(unsigned i=2; i<=limit; ++i) Stroke[i] = 0;
    unsigned int prime=2;
    while(pow((double)prime,2.0)<=limit){
        for(unsigned int i = (int)pow((double)prime,2.0); i<=limit; i+=prime)
            Stroke[i]=1;
        do ++prime; while(Stroke[prime]);
    }//while
    int p = 0;
	for(unsigned int i=0; i<=limit; ++i){
        if(!Stroke[i]) prim[p++]=i;//p ist anders als i.
    }
    delete[] Stroke;
	//
    //main:
	cout << "Addition of two fractions ..."<<endl;
	cout << "------------------------------------------------------------------------------"<<endl;
	cout << "First you can input the first numerator, then the first denominator;"<<endl;
	cout << "After that you can input the second numerator and last the second denominator."<<endl;
	cout << endl;
	getchcls();
	//
	char yesno;
	do
	{
		//Rede:
		cout << "#1: A beginning: 1 3 1 3."<<endl;
		cout << "#2: 1 3 1 6."<<endl;
		cout << "#3: 1 3 1 8."<<endl;
		cout << "#4: 1 6 1 8."<<endl;
		cout << "#5: 1 6 -1 3 in order to subtract."<<endl;
		cout << "#6: 6 7 7 8."<<endl;
		cout << "#7: 1 20 5 6."<<endl;
		cout << endl;
		cout << "#8: 3 6 4 6."<<endl;
		cout << "#9: 4 12 6 24."<<endl;
		cout << "#10: 1 39 4 45 (Prime:13)."<<endl;
		cout << "#11: 1 144 1 600."<<endl;
		cout << "#12: 1 138 1 69."<<endl;
		cout << "#13: 1 38 1 34 (Primes: 19 und 17)."<<endl;
		cout<<"------------------------------------------"<<endl;
		//
		Fractions f;
		f.input();
		getchcls();
		if(f.unequalDenoms())
		{
			if(f.denomsDivisible())
				f.makeCommonDenoms1();
			else if(f.properLcmCase())
			{
				cout << "It is a proper lcm.\n";
				f.makeCommonDenoms2();	
			}//else if
			else f.makeCommonDenoms3();
		}//if
		cout << endl;
		//
		f.add();
		cout << endl;
		f.GCD2();
		f.ifResultImpropFrac();//If the result is an improper fraction:
		//
		f.resultDecimalFrac();
		cout << endl<<endl;
		//
		do
		{
			cout << "Once again another task (y/n) : ";
			cin >> yesno;
		}while(yesno!='y'&&yesno!='n');
		//
		system("cls");
		counter++;
	}while(yesno=='y');
	//Ende:
	cout << "You have done "<<counter<<" task"<<(counter==1?"":"s")<<endl<<endl;
	cout << "RETURN" <<endl;
	cin.sync();
	cin.get();
	return 0;
}//main()


