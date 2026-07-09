#include <cstdlib>
#include <fstream>
using namespace std;

int cmmdc (int a, int b)
{
	int t;
	while (b)
	{
		t = a;
		a = b;
		b = t % a;
	}
	return a;
}

int main ()
{
	ifstream fin ("euclid2.in");
	ofstream fout ("euclid2.out");

	int T, a, b;
	
	for (fin >> T; T; --T)
	{
		fin >> a >> b;
		fout << cmmdc (a, b) << '\n';
	}

	fout.close();
	return EXIT_SUCCESS;
}
