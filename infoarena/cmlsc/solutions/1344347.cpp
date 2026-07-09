#include <cstdio>

#define NMAX 100005

using namespace std;

int t[NMAX],r[NMAX];

void unite(int,int);
int dad(int);

void init(int n)
{
    for(int i=1;i<=n;++i)
    {
        t[i]=i;
        r[i]=1;
    }
}

void solve(int m)
{
    int q,x,y;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&q,&x,&y);
        if(q==1)
            unite(dad(x),dad(y));
        else
        {
            int dx=dad(x);
            int dy=dad(y);
            if(dx==dy)
                printf("DA\n");
            else
                printf("NU\n");
        }
    }
}

int main()
{
    int n,m;
    freopen("disjoint.in","r",stdin);
    freopen("disjoint.out","w",stdout);
    scanf("%d%d",&n,&m);
    init(n);
    solve(m);
    return 0;
}

void unite(int x,int y)
{
    if(r[x]>r[y])
        t[y]=x;
    else
        t[x]=y;
    if(r[x]==r[y])
        ++r[y];
}

int dad(int x)
{
    if(t[x]==x)
        return x;
    t[x]=dad(t[x]);
    return t[x];
}
