#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b)
{
	int aux;
	while(b!=0)
	{
		aux = b;
		b = a%b;
		a = aux;
	}
	return a;
}

int main()
{
	int n, x, y;
	in >> n;
	for (int i=1; i <=n ; i++)
	{
		in >> x >> y;
		out << euclid(x, y) << '\n';
	}

	return 0;

}
