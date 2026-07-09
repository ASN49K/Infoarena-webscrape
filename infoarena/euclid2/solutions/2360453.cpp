#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
ifstream in("euclid.in");
ofstream out("euclid.out");
int f(int a, int b)
{
	return (!b) ? a : f(b, a%b);
}
int main()
{
	int n;
	in >> n;
	for (int x, y, i = 0; i < n; ++i)
	{
		in >> x >> y;
		out << f(x, y) << '\n';
	}
	system("pause");
}
