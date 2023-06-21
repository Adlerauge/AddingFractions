//ado.cpp      20.06.2023
//objektorientiert programmierte
//Addition zweier Brueche:
#include <iostream>
#include <cmath>//pow
#include <conio.h>//getch
#include <iomanip>//setprecision
using namespace std;

const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);
const int MAX = 654;
const int B = 2;//fuer zwei Brueche usw.

int prim[MAX];

void getchcls()
{
	cout << endl;
	cout << "Eine beliebige Taste dr"<<ue<<"cken, bitte!  ";
	getch();
	system("cls");
}//Funktion getchcls()

class Fractions
{
	private:
		int numerator[B];//Zaehler
		int denominator[B];//Nenner
		int exponent[B][MAX];//Exponent
		int biggestExponent[MAX] = {0};//Maximum zweier Exponenten
		int lcm;//least common multiple

void primeFactorization()
{
	cout << "Um das kgV zu ermitteln, kann man die Primfaktoren herausfinden."<<endl;
	cout << "(Jedenfalls ist das eine M"<<oe<<"glichkeit, es zu berechnen.)"<<endl;
	//
	for(int j=0; j<B; j++)//
	{
		int y = denominator[j];
		cout <<endl<< "Wir behandeln hier die "<<y<<":"<<endl;
		cout << "Primfaktor-Zerlegung:"<<endl;
		for(int i=0; i<y; i++)//Algorithmus zur Primfaktorzerlegung:
		{
			while(!(y%prim[i]))//
			//while(y/prim[i] == (float)y/prim[i])
			{
				int mantisse = prim[i];
				cout << y << " ist teilbar durch " << mantisse << endl;
				exponent[j][i]++;
				y /= mantisse;//y = y / prim[i];
			}//while
		}//for i
		cout<<endl;
	}//for j
	cout << endl;
}//funktion primeFactorization()

void result()
{
	cout << "Um das kgV zu erhalten, kannst Du folgende Potenzen multiplizieren:"<<endl;
	//Maximum von zwei Exponenten ermitteln:
	for(int j=0; j<MAX; j++)
		biggestExponent[j]=(exponent[0][j]>exponent[1][j]?exponent[0][j]:exponent[1][j]);	
	//was hoch was?:
	for(int m=0; m<MAX; m++)
	{
		if(biggestExponent[m]==0) continue;//ggf. einen Teil der for-Schleife ueberspringen
		cout << prim[m] << " hoch " << biggestExponent[m] << endl;
	}//for m
}//Funktion result

	public:
		Fractions()
		{ 
			//mit Null besetzen:
			for(int m=0; m<MAX; m++)
			{
				exponent[0][m]=0;
				exponent[1][m]=0;
			}//for m
		}
		
		bool unequalDenoms()//Funktion ungleicheNenner
		{  
			return (denominator[0]!=denominator[1]);
		}//Funktion unequalDenoms()

int GCD1(int number1, int number2)//rekursiv GGT1, greatest common divisor
{
	if(number2==0) return number1;
	return GCD1(number2, number1 % number2);
}

int LCM(int number1, int number2)//KGV, least common multiple
{
	return (number1*number2)/GCD1(number1, number2);
}

void input()
{
	for(int i=0; i<B; i++)
	{	
	do
	{
		cout << "Den "<<i+1<<". Z"<<ae<<"hler eingeben(0..20000): ";
		cin >> numerator[i];
	} while(numerator[i] < -20000 || numerator[i] > 20000);
	do
	{
		cout << "den "<<i+1<<". Nenner eingeben (1..21000, nicht null): ";
		cin >> denominator[i];
	} while(denominator[i] < -21000 || denominator[i] == 0 || denominator[i] > 21000);
	}//for i
}//input()

void GCD2()//GGT2
{
	int x=numerator[0];
	if(x==0)
	{
		cout<<"0 (Null)."<<endl;
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
	cout << "Der Bruch kann";
	if(gcd==1) cout<< " nicht";
	cout << " gek"<<ue<<"rzt werden." << endl;
	cout << "ggT (gr"<<oe<<ss<<"ter gem. Teiler): " << gcd << "."<<endl;
	//gleich kuerzen:
	numerator[0] /= gcd;
	denominator[0] /= gcd;
	cout << numerator[0] << " / " << denominator[0] << endl;
}//Funktion GCD2

bool properLcmCase()//echtes kgV. Hier ist nicht gemeint: Falls das kgV existiert,
      //sondern ein spezieller Fall: wenn ein ECHTES kgV vorliegt.
{
	lcm = LCM(denominator[0], denominator[1]);
	return (lcm < denominator[0]*denominator[1]);
}//properLcmCase()

bool denomsDivisible()//Test, ob der eine Nenner Teiler vom andern ist:
{ return denominator[0] % denominator[1] == 0 || denominator[1] % denominator[0] == 0; }

void makeCommonDenoms1()//Wenn der eine Teiler vom andern ist: machGleichnamig
{
	if(denominator[1] % denominator[0] == 0)
	{
		cout << "Der 2. Nenner ist ein Vielfaches vom 1." << endl;
		numerator[0] = numerator[0] * denominator[1]/denominator[0];
		denominator[0]=denominator[1];
	}
	else
	{
		cout << "Der 1. Nenner ist ein Vielfaches vom 2." << endl;
		numerator[1]=numerator[1]*denominator[0]/denominator[1];
	}//else
	cout << "Gleichnamig machen:  " << numerator[0] << " / " << denominator[0] <<
			" + " << numerator[1] << " / " << denominator[0] << endl;
}//Funktion makeCommonDenoms1

void makeCommonDenoms2()//machGleichnamig2: factor to multiply
{
	cout << "Man sollte das kgV (das kleinste gemeinsame Vielfache) nehmen,"<<endl;
	cout << "um die Br"<<ue<<"che gleichnamig zu machen."<< endl;
	cout << "Man multipliziert jeden Nenner mit einem Faktor," << endl;
	cout << "so dass das kleinste gemeinsame Vielfache in den Nennern steht." << endl;
	getchcls();
	//Zum kgV gelangen:
	//Funktionsaufruf prim...:
	primeFactorization();
	cout << "Man nimmt beim kgV jeweils nur den gr"<<oe<<ss<<"ten Exponenten jeder Potenz,"<<endl;
	cout << "schreibt diese eine Potenz auf und multipliziert dann."<<endl;
	getchcls();
	//Funktionsaufruf result:
	result();
	//Das errechnete lcm (kgV):
	cout << "Das kgV ist " <<lcm<<"."<<endl;
	int lcmfactor0 = lcm/denominator[0];
	int lcmfactor1 = lcm/denominator[1];
	cout << "Weitere Erkl"<<ae<<"rung dazu:" << endl;
	cout << "Der Bruch " << numerator[0] << "/" << denominator[0] << " wird erweitert mit " << lcmfactor0 << "."<<endl;
	cout << "Und "<<numerator[1] << "/"<<denominator[1] << " wird erweitert mit "<<lcmfactor1 << "."<<endl;
	cout << "Weil die Nenner dann gleichnamig werden."<<endl;
	numerator[0] *= lcmfactor0;
	numerator[1] *= lcmfactor1;
	denominator[0] = lcm;
	cout << "Mit gleichem Nenner (kgV): " << numerator[0] << " / " << denominator[0] << " + " << numerator[1] 
	<< " / " << denominator[0] << endl;
}//Funktion makeCommonDenoms2

void makeCommonDenoms3()//machGleichnamig3
{
	cout << "Man kann in diesem Fall ein einfaches Verfahren nehmen, die Br"<<
			 ue<<"che" << endl;
	cout << "gleichnamig zu machen. Man multipliziert einfach beide Nenner" <<
			 endl;
	cout << "miteinander und erweitert dann." << endl;
	numerator[0] *= denominator[1];
	numerator[1] *= denominator[0];
	denominator[0] *= denominator[1];
	cout << "Mit gleichem Nenner: " << numerator[0] << " / " << denominator[0] <<
	" + " << numerator[1] << " / " << denominator[0] << endl;
}//Funktion makeCommonDenoms3

void add()
{
	cout << "Die Nenner ";
	if (unequalDenoms()) cout << "sind jetzt";
	else cout << "waren ja schon";
	cout << " gleich." << endl;
	cout << "Die Bruch-Addition lautet: " << numerator[0] << " / " << denominator[0] <<
			" + " << numerator[1] << " / " << denominator[0] << endl;
	numerator[0] += numerator[1];
	cout << "Ergebnis der Addition: " << numerator[0] << " / " << denominator[0] <<endl;
}//Funktion add()

void ifResultImpropFrac()//Wenn das Resultat ein unechter Bruch ist (improper fraction),
//dann schreibt man eine gemischte Zahl
{
	if(numerator[0]>denominator[0] && denominator[0]!=1)
	{
		//Zuerst eine Ganzzahldivision, dann modulo:
		cout << numerator[0]/denominator[0] << "  " << numerator[0]%denominator[0] << " / " << denominator[0] << endl;
	}//if
}//Funktion ifResultImpropFrac

void resultDecimalFrac()//als Dezimalbruch:
{
	double result = (double)numerator[0]/denominator[0];
	cout << "Als Dezimalbruch bzw. als Ganzzahl: " << setprecision(12) << result << endl;
}//Funktion resultDecimalFrac

};//class
		
int main()
{
	//Preludium:
	unsigned int counter = 0;
	//
	//Primzahlen berechnen:
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
    //Hauptprogramm in main:
    //Vorrede:
	cout << "Addition zweier Br"<<ue<<"che ..."<<endl;
	cout << "------------------------------------------------------------------------------"<<endl;
	cout << "Du darfst Dir das so vorstellen:"<<endl;
	cout << "         1           1"<<endl;
	cout << "        ---    +    ---"<<endl;
	cout << "         3           3"<<endl;
	cout << endl;
	cout << "In einem Bruch steht der Z"<<ae<<"hler oben und der Nenner unten."<<endl;
	cout << "Erst gibt man hier den ersten Z"<<ae<<"hler, dann den ersten Nenner ein;"<<endl;
	cout << "Danach gibt man den zweiten Z"<<ae<<"hler und zuletzt den zweiten Nenner ein."<<endl;
	cout << endl;
	getchcls();
	cout << "--------------------------------------------------------------------------------------"<<endl;
	cout << "Die Zahlen gibt man je nacheinander ein."<<endl;
	cout << "Man muss jede Zahl oder Buchstaben mit RETURN abschlie"<<ss<<"en."<<endl<<endl;
	//
	char yesno;
	do
	{
		//Rede:
		cout << "#1: Gut f"<<ue<<"r den Anfang: 1 3 1 3."<<endl;
		cout << "#2: Auch: 1 3 1 6."<<endl;
		cout << "#3: Auch: 1 3 1 8."<<endl;
		cout << "#4: Komplizierter: 1 6 1 8."<<endl;
		cout << "#5: Erlaubt ist auch, 1 6 -1 3 einzugeben, also zu subtrahieren."<<endl;
		cout << "#6: Stellengenauigkeit testen: 6 7 7 8."<<endl;
		cout << "#7: Auch gut: 1 20 5 6."<<endl;
		cout << endl;
		cout << "#8:  Man kann auch k"<<ue<<"rzbare Br"<<ue<<"che eingeben: 3 6 4 6."<<endl;
		cout << "#9:  4 12 6 24."<<endl;
		cout << "#10: 1 39 4 45 (P:13)."<<endl;
		cout << "#11: 1 144 1 600."<<endl;
		cout << "#12: 1 138 1 69."<<endl;
		cout << "#13: 1 38 1 34 (P: 19 und 17)."<<endl;
		cout<<"------------------------------------------"<<endl;
		//
		Fractions f;
		//Eingabe:
		//Zwei Brueche einlesen:
		f.input();
		getchcls();
		//evtl. gleichnamig machen:
		if(f.unequalDenoms())
		{
			if(f.denomsDivisible())
				f.makeCommonDenoms1();
			else if(f.properLcmCase())//ordentlicher kgV-Fall
			{
				cout << "Es ist ein echtes kgV.\n";
				f.makeCommonDenoms2();	
			}//else if
			else f.makeCommonDenoms3();
		}//if aussen
		cout << endl;
		//Addition beider Brueche:
		f.add();
		cout << endl;
		//ggT:
		f.GCD2();
		//Bei unechtem Bruch als Ergebnis:
		f.ifResultImpropFrac();//If the result is an improper fraction:
		//zu deutsch: Behandlung des unechten Bruchs
		//Dezimal:
		f.resultDecimalFrac();
		cout << endl<<endl;
		//
		do
		{
			cout << "Noch eine "<<ae<<"hnliche Aufgabe? Ja oder nein (j/n) : ";
			cin >> yesno;
		}while(yesno!='j'&&yesno!='n');
		//
		system("cls");
		counter++;
	}while(yesno=='j');
	//Ende:
	cout << "Du hast "<<counter<<" Aufgabe"<<(counter==1?"":"n")<<" gemacht."<<endl<<endl;
	cout << "RETURN, weil jetzt schon Programm-Ende ist." <<endl;
	cin.sync();
	cin.get();
	return 0;
}//main()


