#include <cstdio>
#include <stack>

using namespace std;

int d[1026][1026],a[1026],b[1026];
stack <int> s;

int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int n,m,i,j;

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(j=1;j<=m;j++) scanf("%d",&b[j]);

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);

    printf("%d\n",d[n][m]);

    while(d[n][m])
    {
        if(a[n]==b[m])
        {
            s.push(a[n]);
            n--;m--;
        }
        else
            if(d[n][m-1]>d[n-1][m]) m--;
            else n--;
    }

    while(!s.empty())
    {
         printf("%d ",s.top());
         s.pop();
    }

    return 0;
}
