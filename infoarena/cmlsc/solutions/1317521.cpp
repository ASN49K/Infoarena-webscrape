/*
	Keep It Simple!
*/

#include <fstream>
#include <list>

#define maxV(a,b) ((a)>(b)?(a):(b))

using namespace std;

const int kMax_N = 1025;

int n, m;
int a[kMax_N], b[kMax_N], length[kMax_N][kMax_N];
list<int> cmlsc;

void ReadData()
{
	ifstream fin("cmlsc.in");
	fin >> n >> m;
	for (int i = 1; i <= n; ++i)
		fin >> a[i];
	for (int i = 1; i <= m; ++i)
		fin >> b[i];
	fin.close();
}

void ComputeLength()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i] == b[j])
				length[i][j] = length[i - 1][j - 1] + 1;
			else
				length[i][j] = maxV(length[i - 1][j], length[i][j - 1]);
}

void Computecmlsc()
{
	int i = n, j = m;
	while (i >= 1 && j >= 1)
	{
		if (a[i] == b[j])
		{
			cmlsc.push_front(a[i--]), --j;
		}
		else if (length[i-1][j] > length[i][j-1])
			--i;
		else 
			--j;
	}
}

void PrintResult()
{
	ofstream fout("cmlsc.out");
	fout << length[n][m] << '\n';
	for (auto i : cmlsc)
		fout << i << ' ';
	fout.close();
}

void Solve()
{
	ReadData();
	ComputeLength();
	Computecmlsc();
	PrintResult();
}
int main()
{
	Solve();
	return 0;
}