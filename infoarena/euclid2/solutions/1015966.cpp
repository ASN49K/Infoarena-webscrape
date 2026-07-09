#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iterator>
#include <assert.h>
using namespace std;

const string file = "euclid2";

const string infile = file + ".in";
const string outfile = file + ".out";

const int INF = 0x3f3f3f3f;

int cmmdc(int a, int b)
{
	while(b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	fstream fin(infile.c_str(), ios::in);
	fstream fout(outfile.c_str(), ios::out);
	int N;
	fin >> N;
	for(int i = 0; i < N; i++)
	{
		int a, b;
		fin >> a >> b;
		fout << cmmdc(a, b) << "\n";
	}


	fout.close();
	fin.close();
}
