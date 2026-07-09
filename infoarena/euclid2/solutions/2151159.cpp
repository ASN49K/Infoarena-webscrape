/* Cel mai mare divizor comun a doua numere prin impartiri repetate */

# include <iostream>
# include <fstream>
using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");


/////////////////////////////////////

int euclid(int x, int y)
{
	int n;
	while (y != 0) {
		n = x % y;
		x = y;
		y = n;
	}
	return x;
}

/////////////////////////////////////

int a, b;

int main()
{
	f >> a >> b;
	g << euclid(a, b) <<'\n';

	return 0;
}
