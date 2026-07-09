#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int cmmdc(int a, int b);

int main()
{

	int a, b, T;
	fin >> T;
	for (int i = 1; i <= T; i++) {
		fin >> a >> b;
		fout << cmmdc(a, b)<<'\n';
	}



}

int cmmdc(int a, int b)
{
	int r = a % b;
	if (r == 0)
		return b;
	else return cmmdc(b, r);
}
