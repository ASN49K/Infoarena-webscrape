#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<list>
#define INF 0x3f3f3f3f
#define mp make_pair
#define pb push_back
#define maxn 1024
using namespace std;

int M[maxn][maxn],a[maxn],b[maxn],sol[maxn],n,m,i,j,k;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; ++i) scanf("%d",&a[i]);
    for(j=1; j<=m; ++j) scanf("%d",&b[j]);
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i] == b[j])
                M[i][j] = M[i-1][j-1]+1;
            else
                M[i][j] = max(M[i-1][j],M[i][j-1]);
    i=n; j=m;
    while(i)
        if(a[i] == b[j])    sol[++k]=a[i], i--, j--;
        else
            if(M[i-1][j] < M[i][j-1]) j--;
            else i--;
    printf("%d\n",k);
    for(i=k; i>0; --i)
        printf("%d ",sol[i]);
    return 0;
}
