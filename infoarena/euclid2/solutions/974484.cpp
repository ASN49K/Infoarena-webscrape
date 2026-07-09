#include <fstream>
using namespace std;

ifstream in("euclid2.in"); ofstream out("euclid2.out");
int T;

void cmmdc(int x, int y)
{
	int aux;
	if (x == y)
	{
		out << x << "\n";
		return;
	}
	else
		if (x < y)
		{
			aux = x; 
			x = y; 
			y = aux;
		}
	while (y)
	{
		aux = y;
		y = x % y;
		x = aux;
	}
	out << x << "\n";
}

void read()
{
	int a,b;
	in >> T;
	for (int i = 1; i <= T; i++)
	{
		in >> a >> b;
		cmmdc(a,b);
	}
}

int main()
{
	read();
	return 0;
}