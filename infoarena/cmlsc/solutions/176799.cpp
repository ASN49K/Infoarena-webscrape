#include <cstdio>
#include <vector>
using namespace std;

const int N = 5;//1024;

int n,m;
int a[N], b[N];
int d[N][N];

int main() {
	freopen("cmlsc.in","rt",stdin);
	freopen("cmlsc.out","wt",stdout);
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
	for (int i = 0; i < m; ++i) scanf("%d",&b[i]);
	d[0][0] = (a[0] == b[0]);
	for (int i = 1; i < n; ++i) d[i][0] = d[i-1][0] || (a[i] == b[0]);
	for (int j = 1; j < m; ++j) d[0][j] = d[0][j-1] || (a[0] == b[j]);
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (a[i] == a[j]) {
				d[i][j] = d[i-1][j-1]+1;
			} else {
				d[i][j] = max(d[i-1][j], d[i][j-1]);
			}
		}
	}
	printf("%d\n",d[n-1][m-1]);
	vector<int> v;
	for (int i = n-1, j = m-1; i >= 0 && j >= 0; ) {
		if (a[i] == b[j]) {
			v.push_back(a[i]);
			--i; --j;
		} else {
			if (d[i-1][j] > d[i][j-1])
				--i; else
				--j;
		}
	}
	for (int i = v.size()-1; i >= 0; --i) printf("%d ",v[i]);
	printf("\n");
	return 0;
}
