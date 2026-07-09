#include <fstream>

using namespace std;
fstream fin("euclid2.in", ios::in);
fstream fout("euclid2.out", ios::out);
void test()
{
	fout << "test";
}
int main()
{
	test();
	fout.close();
	fin.close();
	return 0;
}
