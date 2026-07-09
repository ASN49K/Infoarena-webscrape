/* Cel mai mare divizor comun a doua numere prin impartiri repetate */

# include <iostream>
# include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");


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

int n, a, b, i;

int main()
{
	f >> n;
	for (i = 1; i <= n; i ++) {
        f >> a >> b;
        g << euclid(a, b) <<'\n';
	}
	return 0;
}
