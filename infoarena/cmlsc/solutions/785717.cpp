#include <fstream>
using namespace std;

int lis(int v[], int n)
{
	int *best = new int [n];

	for(int i = 0; i < n; i++)
		best[i] = 1;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++)
			if(v[j] < v[i])
				best[i] = 1 + best[j];
	return best[n - 1];
}

int main()
{
	int n;
	int *v;
	ifstream f("scmax.in");
	ofstream g("scmax.out");

	f >> n;
	v = new int [n];
	for(int i = 0; i < n; i++)
		f >> v[i];
	g << lis(v, n);
}