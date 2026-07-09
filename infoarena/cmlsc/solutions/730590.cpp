#include <fstream>
#define NMAX 1024
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N, M, nr = 0, d[NMAX][NMAX], a[NMAX], b[NMAX], sir[NMAX];

int main()
{
	
	fin >> M >> N;
	for(int i = 1; i <= M; i++)
		fin >> a[i];
	for(int j = 1; j <= N; j++)
		fin >> b[j];
	for(int i = 1; i <= M; i++)
		for(int j = 1; j <= N; j++)
		{
			if(a[i] == b[j])
				d[i][j] = 1 + d[i - 1][j - 1];
			else
				if(d[i][j - 1] > d[i - 1][j])
					d[i][j] = d[i][j - 1];
				else
					d[i][j] = d[i - 1][j];
		}
	for(int i = M, j = N; i;)
	{
		if(a[i] == b[j])
		{
			sir[++nr] = a[i];
			--i;--j;
		}
		else
			if(d[i - 1][j] < d[i][j - 1])
				--j;
			else
				--i;
	}
	fout << nr << '\n';
	for(int i = nr; i; --i)
		fout << sir[i] << ' ';
	fin.close();
	fout.close();
	return 0;
}