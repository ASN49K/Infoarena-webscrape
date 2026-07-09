#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b);

int main()
{
	int n, a, b;
	fin >> n;
	for(int i = 1; i <= n; i++)
	{
		fin >> a >> b;
		fout << cmmdc(a, b) << '\n';
	}
	fin.close();
	fout.close();
	return 0;
}

int cmmdc(int a, int b)
{
	if(b == 0)
		return a;
	int rest;
	do
	{
		rest = a % b;
		a = b;
		b = rest;
	}while(rest);
	return a;
}