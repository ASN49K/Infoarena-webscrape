#include <cstdio>
#include <cstring>
using namespace std;
int d[1024][1024];
int m[1024][1024];
int v[1024];
int a[1024],b[1024];
void maxim(int &max,int n,int i,int &poz)
{
    if(max<d[n][i]){
        poz=i;
        max=d[n][i];
    }
}

int main()
{
    int n,i,j,m2;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m2);
    for(i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(j=1;j<=m2;++j)
        scanf("%d",&b[j]);
    for(i=1;i<=n;++i)
        for(j=1;j<=m2;++j){
            m[i][j]=1;
            d[i][j]=d[i-1][j];
            if(d[i][j]<d[i][j-1])
            {
                d[i][j]=d[i][j-1];
                m[i][j]=2;
            }
            if(a[i]==b[j]&&d[i][j]<d[i-1][j-1]+1)
            {
                d[i][j]=d[i-1][j-1]+1;
                m[i][j]=3;
            }
        }
    int poz=0,max=0;
    for(i=0;i<=n;++i)
        maxim(max,n,i,poz);
    printf("%d\n",max);
    int st[1024],top=0;
    int x=n,y=m2;
    while(x and y)
    {
        switch (m[x][y])
        {
            case 1: --x; break;
            case 2: --y; break;
            case 3: st[++top]=a[x]; --x; --y; break;
        }
    }
    while(top>0)
        printf("%d ",st[top--]);
    return 0;
}
