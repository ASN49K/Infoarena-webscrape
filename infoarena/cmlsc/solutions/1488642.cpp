#include <cstdio>

using namespace std;
int n, m , a[1025], b[1025], l[1025][1025], i, j, k;
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &m,&n);
    for(i=1; i<=m; i++) scanf("%d", &a[i]);
    for(i=1; i<=m; i++) scanf("%d", &b[i]);

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j])
                l[i][j]=1+l[i-1][j-1];
            else l[i][j]=l[i-1][j]>l[i][j-1]?l[i-1][j]:l[i][j-1];
    int sol[1025];
    i=m; j=n;
    while(i>=1&&j>=1)
        if(a[i]==b[j]){
            k++;
            sol[k]=a[i];
            i--;
            j--;
        }else l[i-1][j]>l[i][j-1]?i--:j--;

    printf("%d\n", l[m][n]);
    for(k-1; k>=1; k--) printf("%d ", sol[k]);
    return 0;
}
