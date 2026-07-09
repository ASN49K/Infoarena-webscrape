#include<fstream>

using namespace std;

int main()
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");

	int *a, *b, *sol, **c;
	int M, N, k = 0;

	fin >> M >> N;

	a = new int[M];
	b = new int[N];

	sol = new int[M < N ? M : N];

	for (int i = 0; i < M; i++) 
	{
		fin >> a[i];
	}

	for (int i = 0; i < N; i++)
	{
		fin >> b[i];
	}

	c = new int* [M];

	for (int i = 0; i < M; i++)
	{
		c[i] = new int[N];
	}

	for(int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i] == b[j])
			{
				sol[k++] = a[i];
			}
		}
	}

	delete[] a;
	delete[] b;

	fout << k << "\n";

	for (int i = 0; i < k; i++)
	{
		fout << sol[i] << " ";
	}

	delete[] sol;

	return 0;
}