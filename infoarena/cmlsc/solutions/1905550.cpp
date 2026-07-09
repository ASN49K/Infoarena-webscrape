#include <cstdio>

#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int v[1025], w[1025], lcs[1025][1025], sol[1025], ct;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &v[i]);
    for(int i = 1; i <= m; ++i) scanf("%d", &w[i]);
    fclose(stdin);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(v[i] == w[j]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);

    for(int i = n, j = m; i;)
        {
            if(v[i] == w[j])
            {
                sol[++ct] = v[i];
                i--; j--;
            }
            else if(lcs[i-1][j] < lcs[i][j-1]) j--;
            else i--;
        }
    printf("%d\n", ct);
    for(int i = ct; i; --i) printf("%d ", sol[i]);
    fclose(stdin);
    return 0;
}
