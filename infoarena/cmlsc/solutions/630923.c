#include <stdio.h>

short n,m,i,j,pd[1040][1040],a[1040],k;

void parc (short x,short y) {
    if (x==0||y==0) return;
    while (pd[x][y]==pd[x][y-1]) y--;
    while (pd[x][y]==pd[x-1][y]) x--;
    parc  (x-1,y-1);
    printf ("%hd ",a[y]);
}

int main () {
    freopen ("grader_test1.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    scanf ("%hd%hd",&n,&m);
    for (i=1; i<=n; i++) scanf ("%hd",a+i);
    for (i=1; i<=m; i++) {
        scanf ("%hd",&k);
        for (j=1; j<=n; j++) {
            if (k==a[j]) {
                pd[i][j]=pd[i-1][j-1]+1;
            }
            else
            if (pd[i][j-1]>=pd[i-1][j]) pd[i][j]=pd[i][j-1];
            else pd[i][j]=pd[i-1][j];
        }
    }
    printf ("%hd\n",pd[m][n]);
    parc (m,n);
    printf ("\n");
    fclose (stdin); fclose (stdout);
    return 0;
}
