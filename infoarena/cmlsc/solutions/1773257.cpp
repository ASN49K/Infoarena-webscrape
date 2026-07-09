#include <iostream>
#include <cstdio>
#define MAXN 1040

using namespace std;

int n, m;
short a[MAXN], b[MAXN], d[2][MAXN], go[2][MAXN];

void read()
{
	scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
		scanf("%hd ", &a[i]);
	for (int j = 1; j <= m; j++)
		scanf("%hd ", &b[j]);
}

void solve(int alo, int ahi, int blo, int bhi)
{
	if (alo == ahi) {
        for (int i = blo; i <= bhi; i++)
			if (a[alo] == b[i]) {
				printf("%hd ", b[i]);
				return;
			}
		return;
	}
    int mid = (alo + ahi) >> 1;
    int crt = 1;
    for (int i = blo-1; i <= bhi; i++)
		d[!crt][i] = d[crt][i] = 0;
    for (int i = alo; i <= ahi; i++) {
		crt ^= 1;
        for (int j = blo; j <= bhi; j++) {
            if (a[i] == b[j]) {
                d[crt][j] = d[!crt][j-1] + 1;
                go[crt][j] = go[!crt][j-1];
            }
			else if (d[crt][j-1] > d[!crt][j]) {
				d[crt][j] = d[crt][j-1];
				go[crt][j] = go[crt][j-1];
			}
			else {
				d[crt][j] = d[!crt][j];
                go[crt][j] = go[!crt][j];
			}

        }
        if (i == mid)
			for (int j = blo-1; j <= bhi; j++)
				go[crt][j] = j;
    }
    if (alo == 1 && ahi == n && blo == 1 && bhi == m)
		printf("%hd\n", d[crt][m]);
	int to = go[crt][bhi];
	solve(alo, mid, blo, to);
    solve(mid+1, ahi, to, bhi);


}

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	read();
	solve(1, n, 1, m);

    return 0;
}
