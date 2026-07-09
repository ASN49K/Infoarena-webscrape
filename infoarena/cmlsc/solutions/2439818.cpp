#include<fstream>

using namespace std;

#define NMax 1024

int a[NMax], b[NMax], c[NMax][NMax], sol[NMax];
int M, N, k;

int main()
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");

	fin >> M >> N;

	for (int i = 1; i <= M; i++)
	{
		fin >> a[i];
	}

	for (int i = 1; i <= N; i++)
	{
		fin >> b[i];
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (a[i] == b[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if (c[i - 1][j] > c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
			}
			else
			{
				c[i][j] = c[i][j - 1];
			}
		}
	}



	for (int i = M, j = N; i > 0; )
	{
		if (a[i] == b[j])
		{
			sol[k++] = a[i];
			i--;
			j--;
		}
		else if (c[i][j - 1] > c[i - 1][j])
			j--;
		else
			i--;
	}

	fout << k << endl;

	for (int i = k - 1; i >= 0; i--)
	{
		fout << sol[i] << " ";
	}

	return 0;
}