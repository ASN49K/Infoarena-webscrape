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
using namespace std;

const string file = "euclid2";

const string infile = file + ".in";
const string outfile = file + ".out";

const int INF = 0x3f3f3f3f;


int cmmdc(int a, int b)
{
	int r = a % b;
	while(r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main()
{
	fstream fout(outfile.c_str(), ios::out);
	fstream fin(infile.c_str(), ios::in);
	int T;
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		int a, b;
		fin >> a >> b;
		fout << cmmdc(a, b) << "\n";
	}
	fin.close();


	fout.close();
}