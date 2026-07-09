#include <cstdio>
#define DIM 1025
int n, m, i, j, c[DIM][DIM], x[DIM], y[DIM], v[DIM];
char b[DIM][DIM];
using namespace std;

void read()
{   
    scanf("%d%d\n",&n,&m);
    for(i=1; i<=n; ++i) scanf("%d",&x[i]);
    for(i=1; i<=m; ++i) scanf("%d",&y[i]);
}    
void solve()
{
     for(i=0; i<=n; ++i) c[i][0]=0;
     for(i=0; i<=m; ++i) c[0][i]=0;
     for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
                 if(x[i]==y[j])
                               c[i][j]=c[i-1][j-1]+1;
                 else
                 if(c[i-1][j]>=c[i][j-1])
                                c[i][j]=c[i-1][j];
                 else
                                c[i][j]=c[i][j-1];
} 
int write( int k, int l)
{        if(!k || !l) return 0;
         if(c[k][l]==c[k-1][l-1])
            write( k-1, l-1) ;           
         else if( c[k][l]==c[k-1][l] ) write( k-1, l);
         else write( k, l-1 );
         if(x[k]==y[l]) printf("%d ",y[l]);        
         
}                   
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    read();
    solve();
    printf("%d\n",c[n][m]);
    write(n,m);
    return 0;
}    
