#include <stdio.h>

using namespace std;

#define LIMIT 1024

int m,n,a[LIMIT],b[LIMIT],v[LIMIT][LIMIT],sir[LIMIT],bst;

int main(void)
{
    int i, j;
    
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d",&m,&n);
    for (i=1;i<=m;i++) scanf("%d",&a[i]);
    for (i=1;i<=n;i++) scanf("%d",&b[i]);

    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            if (a[i]==b[j]) v[i][j]=1+v[i-1][j-1];
            else v[i][j]=((v[i-1][j]>v[i][j-1])?v[i-1][j]:v[i][j-1]);

    i=m; j=n;
    while (i)
        if (a[i]==b[j]){
            bst++;
            sir[bst]=a[i];
            i--;
            j--;
        }
        else if (v[i-1][j]<v[i][j-1])
            j--;
        else
            i--;

    printf("%d\n", bst);
    for (i=bst;i;--i) printf("%d ", sir[i]);

    return 0;
}


