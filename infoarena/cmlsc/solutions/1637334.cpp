#include <cstdio>
#include <vector>
#define max(a,b) (a>b?a:b)
#define NMAX 1100

using namespace std;
int n,m,i,j;
int a[NMAX],b[NMAX];
int s[NMAX][NMAX],last[NMAX][NMAX];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i) scanf("%d",&a[i]);
    for(j=1;j<=m;++j) scanf("%d",&b[j]);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            if(a[i] == b[j])
            {
                s[i][j]=s[i-1][j-1]+1;
                last[i][j]=1;
            }
            else if(s[i-1][j] > s[i][j-1])
            {
                s[i][j]=s[i-1][j];
                last[i][j]=2;
            }
            else
            {
                s[i][j]=s[i][j-1];
                last[i][j]=3;
            }
        }

    printf("%d\n",s[n][m]);
    i=n;j=m;
    vector<int>sol;
    while(i >= 1 && j>=1)
    {
        if(last[i][j] == 1)
        {
            sol.push_back(a[i]);
            --i;--j;
        }
        else if (last[i][j] == 2) --i;
            else --j;
    }
    for(i=sol.size()-1;i>=0;--i) printf("%d ",sol[i]);
    return 0;
}
