#include <cstdio>

#define NMAX 1030

using namespace std;

int n,m;
int a[NMAX],b[NMAX];
int ma[NMAX][NMAX];

void reconst_rec(int i,int j);

void read()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;++i)
        scanf("%d",&b[i]);
}

inline int maxim(const int a,const int b)
{
    return a>b?a:b;
}

void solve()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(a[i]==b[j])
                ma[i][j]=ma[i-1][j-1]+1;
            else
                ma[i][j]=maxim(ma[i-1][j],ma[i][j-1]);
        }
    printf("%d\n",ma[n][m]);
    reconst_rec(n,m);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    read();
    solve();
    return 0;
}

void reconst_rec(int i,int j)
{
    if(i&&j)
    {
        if(a[i]==b[j])
        {
            reconst_rec(i-1,j-1);
            printf("%d ",a[i]);
        }
        else
        {
            if(ma[i-1][j]>ma[i][j-1])
                reconst_rec(i-1,j);
            else
                reconst_rec(i,j-1);
        }
    }
}
