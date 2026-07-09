#include <cstdio>
#include <vector>
using namespace std;

const int N_MAX = 1025;

int n,m;
int a[N_MAX], b[N_MAX];
int d[N_MAX][N_MAX];
vector<int> sol;

inline int max ( int a, int b, int c ) { return (a > b && a > c) ? a : (b > a && b > c) ? b : c; }
inline int pmax ( int a, int b, int c ) { return (a > b && a > c) ? 1 : (b > a && b > c) ? 2 : 3; }

int main() {
	freopen("cmlsc.in","rt",stdin);
	freopen("cmlsc.out","wt",stdout);
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; ++i) scanf("%d",&a[i]);
	for (int i = 1; i <= m; ++i) scanf("%d",&b[i]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			d[i][j] = max(d[i-1][j], d[i][j-1], (a[i] == b[j]) ? d[i-1][j-1] + 1 : 0);
	printf("%d\n",d[n][m]);
	for (int i = n, j = m; i && j; ) {
		switch (pmax(d[i-1][j], d[i][j-1], (a[i] == b[j]) ? d[i-1][j-1] + 1 : 0)) {
			case 1: --i; break;
			case 2: --j; break;
			case 3: sol.push_back(a[i]); --i; --j; break;
		}
	}
	for (vector<int>::reverse_iterator it = sol.rbegin(); it != sol.rend(); ++it) printf("%d ",*it);
	printf("\n");
	return 0;
}
