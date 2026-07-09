#include <cstdio>
#include <algorithm>
using namespace std;
#define TEST 0

void open_file(){
    if(TEST)
    {
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    } else
    {
        freopen("cmlsc.in","r",stdin);
        freopen("cmlsc.out","w",stdout);
    }
}


int n,m,a[1025],b[1025],c[1025][1025];

void dyn_pr(){
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(a[i] == b[j])c[i][j] = 1 + c[i-1][j-1]; else
        c[i][j] = max( c[i-1][j], c[i][j-1] );
}

void tipar(int n,int m){
    if( c[n][m] == 0 ) return ; else
    {
        if( a[n] == b[m] )
        {
            tipar( n-1,m-1 );
            printf("%d ",a[n]);
        } else
        if( c[n-1][m] > c[n][m-1] ) tipar( n-1,m ); else tipar( n,m-1 );
    }
}

int main(){

    open_file();

    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);

    dyn_pr();

    printf("%d\n",c[n][m]);
    tipar( n,m );

    return 0;
}
