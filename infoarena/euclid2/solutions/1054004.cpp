#include<fstream>

using namespace std;

ifstream fin;
ofstream fout;

int cmmdc(int a, int b)
{
	if (b == 0) return a;
	return cmmdc(b, a%b);
}

int main()
{
	fin.open("euclid2.in");
	fout.open("euclid2.out");
	int i, T, a, b;
	fin >> T;

	for (i = 1; i <= T; i++)
	{
		fin >> a >> b;
		fout << cmmdc(a, b) << '\n';
	}
	return 0;
}