#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
	int aux;
	if (b==0) return a;
	else 
	{
		aux = a;
		a = b;
		b = aux % b;
		return cmmdc(a, b);
	}
}

int main()
{
	fstream f("euclid2.in",ios::in);
	fstream g("euclid2.out",ios::out);
	
	int n, a, b, i;
	
	f>>n;
	
	for (;n;n--)
	{
		f>>a>>b;
		g<<cmmdc(a, b)<<"\n";
	}
	
	return 0;
}