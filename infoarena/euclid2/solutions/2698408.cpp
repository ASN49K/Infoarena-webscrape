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