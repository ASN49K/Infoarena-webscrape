#include <fstream>
using namespace std;

int n, a, b;

int Cmmdc (int a, int b)
{
	if (!b)
		return a;
	else
		return Cmmdc (b, a % b);
}

int main ()
{
	ifstream fin ("euclid2.in");
	fin >> n;
	ofstream fout ("euclid2.out");
	for (int i = 0; i < n; ++i)
	{
		 fin >> a >> b;
		 fout << Cmmdc (a, b) << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
