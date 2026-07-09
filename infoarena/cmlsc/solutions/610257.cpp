#include <fstream.h>

int main ()
{
	int M, N, i, j;
	char v[2][1030][1030], X[1030], Y[1030];
	ifstream fin ("cmlsc.in");
	ofstream fout ("cmlsc.out");
	memset (v, 0, sizeof (v));
	fin >> M >> N;
	for (i = 1; i <= M; i++)
	{
		fin >> X[i];
	}
	for (j = 1; j <= N; j++)
	{
		fin >> Y[j];
	}
	fin.close ();
	for (i = 1; i <= M; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (X[i] == Y[j])
			{
				memcpy (v[i % 2][j], v[(i - 1) % 2][j - 1], sizeof (v[i % 2][j]));
				v[i % 2][j][0]++;
				v[i % 2][j][v[i % 2][j][0]] = X[i];
			}
			else
			{
				if (v[i % 2][j - 1][0] > v[(i - 1) % 2][j][0]) memcpy (v[i % 2][j], v[i % 2][j - 1], sizeof (v[i % 2][j]));
				else memcpy (v[i % 2][j], v[(i - 1) % 2][j % 2], sizeof (v[i % 2][j]));
			}
		}
	}
	fout << (int) v[M % 2][N][0] << "\n";
	for (i = 1; i <= (int) v[M % 2][N][0]; i++)
	{
		fout << v[M % 2][N][i] - 48 << " ";
	}
	fout.close ();
	return 0;
}
