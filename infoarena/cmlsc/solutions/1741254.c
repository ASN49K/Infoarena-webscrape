#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b)((a>b) ? a : b)



void LCS (int *v ,int *w, int n , int m)
{
   freopen("cmlsc.out","w",stdout);
    int a[n][m],b[1025], i,j;

    for(i=0;i<n;i++)
        a[i][0]=0;
    for(i=1;i<m;i++)
        a[0][i]=0;
    for(i=0;i<1025;i++)
        b[i]=0;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            a[i][j]=MAX(a[i][j-1],a[i-1][j] ) + ((v[i-1]==w[j-1]) ? 1 : 0);

    printf("%i\n",a[n][m]);
    i=n;j=m;

    int cnt=0;
    while(a[i][j]!=0)
    {
        if(a[i][j]!=a[i-1][j-1]){
            b[cnt++]=v[i-1];
            i--;
            j--;
        }
        else if (i>0) i--;
            else j--;
    }
    cnt--;
    while(cnt> -1)
        printf("%i",b[cnt--]);
}


int main()
{

    int n , m , i , v[1025],w[1025];

    freopen("cmlsc.in","r",stdin);

    scanf("%i %i",&n,&m);

    for ( i = 0 ; i<n ; i++)
        scanf("%i", &v[i]);
    for ( i = 0 ; i<m ; i++)
        scanf("%i", &w[i]);

    LCS(v,w,n,m);
    return 0;
}
