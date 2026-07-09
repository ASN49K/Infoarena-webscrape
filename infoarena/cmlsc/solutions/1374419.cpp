#include <cstdio>
#include <iostream>
#define N 1026
using namespace std;
FILE *F=fopen("cmlsc.in","r");
FILE *G=fopen("cmlsc.out","w");
int a[N],b[N],d[N][N],rp[N],i,j,n,m;
int main()
{
    fscanf(F,"%d%d",&n,&m);
    for(i=1;i<=n;++i)
        fscanf(F,"%d",&a[i]);
    for(i=1;i<=m;++i)
        fscanf(F,"%d",&b[i]);
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j){
            if(a[i] == b[j]){
                d[i][j] += 1 + d[i-1][j-1];
                //rp[ d[i][j] ] = max( rp[ d[i][j] ] , a[i] );
            }
            else
                d[i][j] += max( d[i-1][j] , d[i][j-1] );
        }
    i = n; j = m;
    while(i > 0 && j > 0){
        if(d[i][j] > d[i-1][j] && d[i][j] > d[i][j-1] && a[i] == b[j]){
            rp[ d[i][j] ] = max( rp[ d[i][j] ] , a[i] );
            --i; --j;
        }
        else{
            if( d[i-1][j] > d[i][j-1])
                --i;
            else
                --j;
        }
    }
    fprintf(G,"%d\n",d[n][m]);
    for(i = 1; i <= d[n][m]; ++i)
        fprintf(G,"%d ",rp[i]);
    return 0;
}
