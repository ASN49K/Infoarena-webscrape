#include <fstream>

using namespace std;

int t, n, x;
int ans = 0;

int main()
{
	ifstream fin("nim.in");
	ofstream fout("nim.out");
	fin >> t;
	for (int k = 1;k <= t;++k)
	{
		fin >> n;
		ans = 0;
		for (int i = 1;i <= n;++i)
		{
			fin >> x;
			ans ^= x;
		}
		if (ans != 0)
			fout << "DA\n";
		else
			fout << "NU\n";
	}
	fin.close();
	fout.close();
	return 0;
}