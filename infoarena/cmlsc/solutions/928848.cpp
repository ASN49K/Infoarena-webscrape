#include<iostream>
#include<cstdio>
#include<vector>
#define maxn 1025
using namespace std;
vector < int > sol;
int M[maxn][maxn],a[maxn],b[maxn],i,j,n,m;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; ++i) scanf("%d",&a[i]);
    for(i=1; i<=m; ++i) scanf("%d",&b[i]);
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i] == b[j])
                M[i][j] = M[i-1][j-1] + 1;
            else
                M[i][j] = max(M[i-1][j], M[i][j-1]);
    printf("%d\n",M[n][m]);
    i = n;  j = m;
    while(i)
        if(a[i] == b[j])    sol.push_back(a[i]), --i, --j;
        else    if(M[i][j-1] > M[i-1][j])   j--;
                else    i--;
    for(i=sol.size()-1; i>=0; --i)
        printf("%d ",sol[i]);
    return 0;
}
