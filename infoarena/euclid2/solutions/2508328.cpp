#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int cmmdc(int a, int b);

int main()
{

	int a, b;

	fin >> a >> b;
	fout << cmmdc(a, b);




}

int cmmdc(int a, int b)
{
	int r = a % b;
	if (r == 0)
		return b;
	else return cmmdc(b, r);
}