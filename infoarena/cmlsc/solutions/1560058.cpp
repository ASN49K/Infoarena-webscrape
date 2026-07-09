#include <cstdio>
#define MAX 1024
using namespace std;
int d[MAX+1][MAX+1], x[MAX+1], y[MAX+1];
struct elemente{
    int lin, col;
};elemente last[MAX+1][MAX+1];
int maxim(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
void afisare(int l, int c)
{
    if(l==0||c==0)
        return;
    afisare(last[l][c].lin, last[l][c].col);
    if(x[l]==y[c])
        printf("%d ", x[l]);
}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m, i, j, poz=0;
    scanf("%d%d", &n, &m);
    for(i=1;i<=n;i++)
        scanf("%d", &x[i]);
    for(j=1;j<=m;j++)
        scanf("%d", &y[j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j]){
                d[i][j]=d[i-1][j-1]+1;
                last[i][j].lin=i-1;
                last[i][j].col=j-1;
            }
            else{
                if(d[i-1][j]>d[i][j-1])
                {
                    d[i][j]=d[i-1][j];
                    last[i][j].lin=i-1;
                    last[i][j].col=j;
                }
                else
                {
                    d[i][j]=d[i][j-1];
                    last[i][j].lin=i;
                    last[i][j].col=j-1;
                }
            }
        }
    printf("%d\n", d[n][m]);
    afisare(n, m);
    return 0;
}
