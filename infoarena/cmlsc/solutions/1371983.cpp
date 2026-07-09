#include <cstdio>
using namespace std;
int n, m, a[1030], b[1030], d[1030][1030], i, j, v[1030], k;

inline int maxim(int x, int y){
    return (x>y?x:y);
}

int main(){
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++)
        scanf("%d", &a[i]);
    for(j=1; j<=m; j++)
        scanf("%d", &b[j]);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=maxim(d[i][j-1], d[i-1][j]);
    printf("%d\n", d[n][m]);
    i=n;
    j=m;
    while(d[i][j]!=0)
        if(a[i]==b[j])
        {
            v[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
        }
    for(i=k; i>0; i--)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}
