#include <fstream>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m, k;
int a[1030], b[1030], c[1030][1030];
int sol[1030];

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	for(int i=1; i<=m; i++)
		cin >> b[i];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(a[i] == b[j])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
	cout << c[n][m] << '\n';
	while(c[n][m])
		if(a[n] == b[m])
			sol[k++] = a[n], n--, m--;
		else
			if(c[n - 1][m] > c[n][m - 1])
				n--;
			else
				m--;
	while(k--)
		cout << sol[k] << ' ';
	return 0;
}

