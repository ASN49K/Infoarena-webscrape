#include<fstream>
using namespace std;
int main()
{
	ifstream	fin("euclid2.in");
	ofstream fout("euclid2.out");
	long a, b, n, r;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> a;
		fin >> b;
		while (b != 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		fout << a << '\n';
	}

}