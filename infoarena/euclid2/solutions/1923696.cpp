#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid()

int main()
{
	int x;
	int a, b, rest;
	in>>x;
	for (int i = 1; i <= x; i++)
	{
		in >> a >> b;
		while(b)
		{
			rest = a % b;
			a = b;
			b = rest;
		}
		
		out<< a << "\n";
	}
	return 0;
}
