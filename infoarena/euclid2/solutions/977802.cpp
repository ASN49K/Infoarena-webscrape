#include<iostream>
#include<fstream>
using namespace std;

class CMMDC
{
	int a,b;

public:

	CMMDC()
	{
	}

	int Rezolva()
	{
		int aux;
		ifstream f("euclid2.in");
		ofstream g("euclid2.out");
		f >> aux;
		for(int i = 0 ; i < aux; i++)
		{
			f >> a; 
			f >> b;
			g << Cmmdc(a,b) << endl;
		}
		return 0;
	}

	int Cmmdc(int a,int b)
	{
		if(!b)
			return a;
		return Cmmdc(b,a%b);
	}
};

int main()
{
	CMMDC numar;
	numar.Rezolva();
	return 0;
}

	