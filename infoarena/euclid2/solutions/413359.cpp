#include <fstream>

using namespace std;

int main()
{
	fstream f("euclid2.in",ios::in);
	fstream g("euclid2.out",ios::out);
	
	int n, a, b, aux;
	
	f>>n;
	
	for (;n;n--)
	{
		f>>a>>b;
		while (b)
		{
			aux = b;
			b = a % b;
			a = aux;
		}
		g<<a<<"\n";
	}
	
	return 0;
}