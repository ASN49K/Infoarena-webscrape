#include <iostream>
#include <cstdio>
#define MAXN 1050

using namespace std;

int n, m, a[MAXN], b[MAXN];

void citire()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int j = 1; j <= m; j++)
		scanf("%d", &b[j]);
}
int din[MAXN][MAXN];
int solve()
{
    for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			din[i][j] = max(din[i-1][j], din[i][j-1]);
			if (a[i] == b[j])
				din[i][j] = din[i-1][j-1]+1;
		}
	return din[n][m];
}

int t[MAXN], nq;
void traseu()
{
    for (int i = n, j = m; i > 0 && j > 0; ) {
        if (a[i] == b[j]) {
			t[++nq] = a[i];
            i--, j--;
        }
        if (din[i-1][j] < din[i][j-1]) j--;
        else i--;
    }
    for (int i = nq; i >= 1; i--)
		printf("%d ", t[i]);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    citire();
    int rez = solve();
	printf("%d\n", rez);
    traseu();

    return 0;
}
