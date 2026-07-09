#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<int>a,b;
int k[1025][1025];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&m,&n);
    int i,j;
    a.reserve(m+1);
    b.reserve(n+1);
    for(i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                k[i][j]=k[i-1][j-1]+1;
            else
                k[i][j]=max(k[i][j-1],k[i-1][j]);
        }
    printf("%d\n",k[m][n]);
    vector<int>d;
    for (i = m, j = n; i>0; )
        if (a[i] == b[j])
        {
            d.push_back(a[i]);
            --i, --j;
        }
        else if (k[i-1][j] < k[i][j-1])
            --j;
        else
            --i;
    for(i=d.size()-1;i>=0;i--)
        printf("%d ",d[i]);
    printf("\n");
    return 0;
}
