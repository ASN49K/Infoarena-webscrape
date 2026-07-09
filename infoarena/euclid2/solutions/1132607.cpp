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
#include <random>
#include <assert.h>
using namespace std;

const string file = "euclid2";

const string infile = file + ".in";
const string outfile = file + ".out";

const int INF = 0x3f3f3f3f; 

//#define ONLINE_JUDGE

int cmmdc(int a, int b)
{
    while(b)
    {
        int d = b;
        b = a % b;
        a = d;
    }
    return a;
}
int main()
{
#ifdef ONLINE_JUDGE
	ostream &fout = cout;
	istream &fin = cin;
#else
	fstream fin(infile.c_str(), ios::in);
	fstream fout(outfile.c_str(), ios::out);
#endif	

    int T;
    fin >> T;
    for(int t = 0; t < T; t++)
    {
        int a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }

#ifdef ONLINE_JUDGE
#else
    fout.close();
	fin.close();
#endif
}
