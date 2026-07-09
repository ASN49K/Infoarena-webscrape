#include <iostream>
#include <fstream>
using namespace std;
/*

int scalarProduct(vector<int>  const& a, vector<int>const& b, int nrThreads)
{
	int result = 0;
	vector<thread> threads;
	threads.reserve(nrThreads);

	int begin = 0;
	for (int i = 0; i < nrThreads; i++) {
		int end = begin + a.size() / nrThreads;
		cout << begin << " " << end << endl;
		threads.emplace_back([&a, &b, begin, end, &result]() {
			int part = 0;
			for (int i = begin; i < end; i++)
			{
				part += a[i] * b[i];
			}
			result += part;
			});
		begin = end;
	}
	for (int i = 0; i < nrThreads; i++)
	{
		threads[i].join();
	}
	return result;
}

int main()
{
	vector<int> a;
	a.reserve(1013);
	vector<int> b;
	b.reserve(1013);
	for (int i = 0; i < 1013; i++) {
		a.push_back(i);
		b.push_back(i);
	}

	cout << scalarProduct(a, b, 100);
}
*/
/*
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n, x, y, rest;

int main()
{
	n = 0;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> x >> y;
		while (y) {
			int m = x % y;
			x = y;
			y = m;
		}

		fout << x << "\n";
	}
	return 0;
}

*/
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int len1, len2, arr1[1025], arr2[1025], commonMatrix[1025][1025];
int main()
{
	fin >> len1 >> len2;
	for (int i = 1; i <= len1; i++)
	{
		fin >> arr1[i];
	}
	for (int i = 1; i <= len2; i++)
	{
		fin >> arr2[i];
	}

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				commonMatrix[i][j] = commonMatrix[i - 1][j - 1] + 1;
			}
			else
			{
				commonMatrix[i][j] = max(commonMatrix[i][j - 1], commonMatrix[i - 1][j]);
			}
		}
	}

	for (int i = 0; i <= len1; i++)
	{
		for (int j = 0; j <= len2; j++)
		{
			cout << commonMatrix[i][j] << " ";
		}
		cout << endl;
	}

	int sequence[1025];
	int i, j, k;
	k = commonMatrix[len1][len2];
	i = len1, j = len2;

	while (i > 0 && j > 0)
	{
		if (arr1[i] == arr2[j])
		{
			sequence[k] = arr1[i];
			--i;
			--j;
			--k;
		}
		else if (commonMatrix[i - 1][j] < commonMatrix[i][j - 1])
			--j;
		else
			--i;
	}

	fout << commonMatrix[len1][len2] << "\n";
	for (i = 1; i <= commonMatrix[len1][len2]; i++)
	{
		fout << sequence[i] << " ";
	}
	fout << endl;
	return 0;
}