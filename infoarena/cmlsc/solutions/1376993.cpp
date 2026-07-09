#include<cstdio>
using namespace std;
int i, j, n, m, a[1025], b[1025], t[1025][1025], sol[1025], lg;
inline int max(int a, int b){if (a>=b) return a; else return b;}
int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d", &n, &m);
    for (i=1;i<=n;i++) {scanf("%d", &a[i]); t[i][0]=0;}
    for (i=1;i<=m;i++) scanf("%d", &b[i]);
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) {
        if (a[i]==b[j]) t[i][j]=t[i-1][j-1]+1;
            else t[i][j]=max(t[i-1][j], t[i][j-1]);
    }
    printf("%d\n", t[n][m]);
    i=n; j=m; lg=0;
    while (i>0 && j>0) {
        if (a[i]==b[j]) {
            sol[++lg]=a[i]; i--; j--;
        } else if (t[i-1][j]<t[i][j-1]) j--; else i--;
    }
    for (i=lg;i>=1;i--) printf("%d ", sol[i]);
    printf("\n");
    return 0;
}
