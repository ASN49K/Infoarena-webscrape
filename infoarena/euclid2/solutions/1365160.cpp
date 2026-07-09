
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	unsigned int t, a, b;
	fin >> t;
	for (; t; t--)
	{
		fin >> a >> b;
		while (b != 0)
		{
			unsigned int c = b;
			b = a % b;
			a = c;
		}
		fout << a << '\n';
	}
}
