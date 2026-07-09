#include <fstream>
using namespace std;
int dc(int a, int b)
{
	if (!b) return a;
	return dc(b, a % b);
}
int main()
{
	unsigned int a,b,i,d;
	ifstream f1("euclid2.in");
	ofstream f2("euclid2.out");
	f1>>a;
	for (i=1;!f1.eof();i++) 
	{
		f1>>a>>b;
		if (b>=2) {d=dc(a,b);f2<<d<<"\n";}
		else
		{
			if (b==0) f2<<a<<"\n";
			else f2<<b<<"\n";
		}
	}
	f1.close();
	f2.close();
	return 0;
}
