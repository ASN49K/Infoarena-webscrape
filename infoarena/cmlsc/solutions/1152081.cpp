#include <cstdio>
#include <algorithm>

using namespace std;
int x[1028][1029],a[1029],b[1029],n,m,i,j;

void C()
{
    int i,j;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i]!=b[j])
                x[i][j]=max(x[i][j-1],x[i-1][j]);
            else
                x[i][j]=x[i-1][j-1]+1;


}

void af(int x1,int x2)
{

    if(a[x1]==b[x2])
    {
        if(x2 && x1) af(x1-1,x2-1);
        if(x1 || x2) printf("%d ",a[x1]);
    }
    else if(x2 && x1)
    {
        if(x[x1][x2-1]>=x[x1-1][x2]) af(x1,x2-1);
        else af(x1-1,x2);
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
        x[i][0]=x[i][m+1]=0;

    }

    x[0][0]=0;
    for(j=1; j<=m; ++j)
    {
        scanf("%d",&b[j]);
        x[0][j]=x[n+1][j]=0;

    }
    C();
    printf("%d\n",x[n][m]);
    af(n,m);
    printf("\n");

    return 0;
}
