#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int a[1025],b[1025],DP[1025][1025],n,m;
vector<int> v;
void read()
{
    scanf("%d%d",&n,&m);
    for(int i =1 ;i <= n;++i)
        scanf("%d",&a[i]);
    for(int i =1 ;i <= m;++i)
        scanf("%d",&b[i]);
}

void solve()
{
    for(int i = 1; i <= n;++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
}

void print(int i,int j)
{
    printf("%d\n",DP[i][j]);
    do
    {
        if(a[i] == b[j])
            v.push_back(a[i]),--i,--j;//printf("%d ",a[i]),--i,--j;
        else
        {
            if(DP[i][j-1]>DP[i-1][j]) --j;
            else --i;
        }
    }
    while(i && j);
    for(int i = v.size()-1 ;i >=0; --i)
        printf("%d ",v[i]);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    read();
    solve();
    print(n,m);

    return 0;
}
