#include <stdio.h>
#include <vector>
#define Nmax 1025
using namespace std;
std::vector<int> a,b,c;
int n,m,x,d[Nmax][Nmax];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    a.push_back(0);b.push_back(0);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        a.push_back(x);
    }
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&x);
        b.push_back(x);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i]==b[j])d[i][j] = d[i-1][j-1]+1;
            else d[i][j] = ((d[i-1][j]>d[i][j-1])?d[i-1][j]:d[i][j-1]);
        }
    }
    for(int i=n,j=m;i;)
    {
        if(a[i]==b[j])c.push_back(a[i]),--i,--j;
        else ((d[i-1][j]<d[i][j-1])?--j:--i);
    }
    printf("%d\n",c.size());
    for(int i=c.size()-1;i>=0;--i)printf("%d ",c[i]);
    return 0;
}
