#include <fstream>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
#include <map>
#include <string>
#include <bitset>
#include <unordered_map>
#define oo 2000000
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");



int main()
{
	int n;
	int a, b;
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		fin >> a >> b;
		while (b)
		{
			int r = a % b;
			a = b;
			b = r;
		}
		fout << a<<endl;
	}


}















