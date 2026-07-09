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

int cmmdc(long long int a, long long int b)
{	
	while (b != 0)
	{
		long long int rest = a % b;
		a = b;
		b = rest;
	}
	return a;
}

int main()
{
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		long long int x, y;
		fin >> x >> y;
		fout << cmmdc(x, y) << endl;
	}
	return 0;

}