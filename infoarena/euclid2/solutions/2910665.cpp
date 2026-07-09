#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid2(int a, int b);

int main()
{
    int t, a, b;
    fin >> t;
    for (int i = 1; i <= t; i++)
    {
	    fin >> a >> b;
	    fout << euclid2(a, b) << '\n';	
	}
}


int euclid2(int a, int b)
{
	while (b)
	{
		int aux =  a % b;
		a = b;
		b = aux;
	}
	return a;
}












