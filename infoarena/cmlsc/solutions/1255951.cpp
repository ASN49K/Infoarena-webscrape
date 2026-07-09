#include <cstdio>

using namespace std;

int n,m,a[1026],b[1026],i,j,v[1026][1026];

int max(int x,int y)
{
    if(x>y) return x;
    return y;
}

inline void solve(int i,int j)
{
    if(a[i]==b[j])
    v[i][j]=v[i-1][j-1]+1;
    else
    v[i][j]=max(v[i][j-1],v[i-1][j]);



}

void afis(int i,int j)
{
    if(i==0 || j==0) return;

    if(a[i]==b[j])
    {
       afis(i-1,j-1);
       printf("%d ",a[i]);

    }
    else
    {
       if(v[i][j]==v[i][j-1])
           afis(i,j-1) ;
           else afis(i-1,j);

    }



}


int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d",&n,&m);

    for(i=1; i<=n; ++i)
    {
        scanf("%d",&a[i]);
        v[i][0]=0;
    }

    for(i=1; i<=m; ++i)
    {
        scanf("%d",&b[i]);
        v[0][j]=0;
    }

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            solve(i,j);

    printf("%d\n",v[n][m]);

    afis(n,m);




    return 0;
}
