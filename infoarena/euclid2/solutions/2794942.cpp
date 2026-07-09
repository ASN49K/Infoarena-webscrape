#include <fstream>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include<bitset>
#include <map>
#include <cstring>
#include<algorithm>

using namespace std;


int n;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
	int rest = a % b;
	while (rest != 0)
	{
		a = b;
		b = rest;
		rest = a % b;
	}
	return b;
}

int main()
{
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		fin >> x >> y;
		fout << cmmdc(x, y) << endl;
	}
	return 0;

}