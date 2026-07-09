# include <iostream>
# include <fstream>
using namespace std;
int main ()
{
	long a,b,r,i,T;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>T;
	for (i=1;i<=T;i++)
	{	f>>a;f>>b;
		if (a*b==0) g<<a+b<<"\n";
		else 
		{	r=a%b;
			while (b)
			{a=b;b=r;r=a%b;}
			g<<a<<"\n";
		}
	}
	f.close ();
	g.close ();
	return 0;
}
