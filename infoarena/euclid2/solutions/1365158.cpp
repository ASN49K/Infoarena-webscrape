#include <fstream>

using namespace std;
fstream fin("euclid2.in", ios::in);
fstream fout("euclid2.out", ios::out);
int v[1000000];
void test()
{
	fout << "test";
}
int main()
{
	for (int i = 1; i <= 1000; i++)
		v[i] = i;
	test();
	fout.close();
	fin.close();
	return 0;
}
