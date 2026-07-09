#include <iostream>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <iomanip>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef map<string, int> msi;
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int>::iterator vit;
typedef vector<ii>::iterator viit;
typedef vector<string>::iterator vst;

#define REP(i, n) for (int i = 1; i <= n; ++i)
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define MP make_pair
#define PB push_back
#define ALL(x) (x).begin(), x.end()
#define SIZE(x) (int)(x).size()
#define FOREACH(it, c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)
#define INF 1023456789
#define DEBUG(x) cerr << #x << ": " << x << endl;
#define ERR(...) fprintf(stderr, __VA_ARGS__);

ifstream f("nim.in");
ofstream g("nim.out");

int i, j, n, m, x, acumulator;

int main() {

	f >> n;
	while (n--) {
		f >> m;
		acumulator = 0;
		REP (i, m) {
			f >> x;
			acumulator ^= x;
		}

		g << (acumulator ? "DA\n" : "NU\n");
	}

}
