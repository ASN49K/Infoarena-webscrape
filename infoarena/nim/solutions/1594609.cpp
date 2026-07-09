#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <iomanip>
#define MOD 1000000000
#define NMAX 1000010
#define INF (1<<30)

using namespace std;

FILE *fin = freopen("nim.in", "r", stdin);
FILE *fout = freopen("nim.out", "w", stdout);

typedef pair<int, int> pii;

const double EPS = 1e-9;

int main() {
	int n, t, i, nr,sum;
	
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		sum = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &nr);
			sum ^= nr;
		}

		if (sum == 0)
			printf("NU\n");
		else
			printf("DA\n");
	}

	return 0;
}
