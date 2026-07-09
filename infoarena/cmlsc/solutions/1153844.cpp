#include <cstdio>

using namespace std;

int m, n, a[1050], b[1050], d[1050][1050], t[1050], nq;

void traseu(int l, int c)
{
    if(l==0 || c==0)
        return;
    if(a[l] == b[c]){
        traseu(l-1, c-1);
        t[nq++] = a[l];
    }
    else if(d[l-1][c] > d[l][c-1])
        traseu(l-1, c);
    else
        traseu(l, c-1);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);
    for(int i=1; i<=m; i++)
        scanf("%d", &a[i]);
    for(int i=1; i<=n; i++)
        scanf("%d", &b[i]);
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(a[i] == b[j])
                d[i][j] = d[i-1][j-1]+1;
            else
                d[i][j] = d[i-1][j]>d[i][j-1]?d[i-1][j]:d[i][j-1];
    printf("%d\n", d[m][n]);
    traseu(m, n);
    for(int i=0; i<nq; i++)
        printf("%d ", t[i]);

    return 0;
}
