#include <stdio.h>

#define Nmax 1025

int x[Nmax][Nmax], a[Nmax], b[Nmax], n,m, rec[Nmax], sol;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    
    scanf("%d%d", &n,&m);
    
    for (int i=1;i<=n;++i)  scanf("%d", &a[i]);
    for (int j=1;j<=m;++j)  scanf("%d", &b[j]);

    for (int i=1;i<=n;++i)  
    for (int j=1;j<=m;++j)  
    if (a[i] == b[j]) x[i][j] = x[i-1][j-1] + 1;
        else
        {
            x[i][j] = x[i-1][j];
            if (x[i][j-1] > x[i][j]) x[i][j] = x[i][j-1];    
        }    
    sol = x[n][m];
        
    int i,j,tmp = sol;    
    
    for (i=n,j=m;i>0 && j>0;)
    if (a[i] == b[j])
    {
        rec[tmp--] = a[i];
        --i; --j;    
    }
    else
    if (x[i][j-1] == x[i][j])
    --j; else --i;
    
    printf("%d", sol);
    printf("\n");    
    for (i = 1;i<=sol;++i)
    printf("%d ", rec[i]);

    
    
    

    
    return 0;    
}
