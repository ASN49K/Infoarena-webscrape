#include <fstream>
using namespace std;

bool a[101];
int t;

void lire()
{
	int x,b,n;
	bool q;
	ifstream f("nim.in");
	f >> t;
	for (int i=1; i<=t; i++)
	{
		f >> n;
		q=true;
		if (n<3) a[i]=true;
		else
		{
			x=0;
			q=false;
			for (int j=1; j<=n; j++)
			{
				f >> b;
				x=x^b;
			}
			if (x!=0) a[i]=true;
		}
		if (q)
			for (int j=1; j<=n; j++)
				f >> b;
	}
	f.close();
}

void ecrire()
{
	ofstream f("nim.out");
	for (int i=1; i<=t; i++)
	{
		if (a[i]) f << "DA" ; else f << "NU" ;
		if (i!=t) f << endl;
	}
	f.close();
}

int main()
{
	lire();
	ecrire();
	return 0;
}