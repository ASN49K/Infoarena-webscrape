#include <stdio.h>
#define max(a,b) (a>b)?a:b

using namespace std;

int n;
int m;
int a[1050];
int b[1050];
int c[1050][1050];

void citire()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;++i)
        scanf("%d",&b[i]);
}

void subsir()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else
            {
                c[i][j]=max(c[i][j-1],c[i-1][j]);
            }
        }
    }
}

void afis(int i, int j)
{
    if(!i)
        return;
    if(a[i]==b[j])
    {
        afis(i-1,j-1);
        printf("%d ",a[i]);
        return;
    }
    if(c[i-1][j]==c[i][j])
        afis(i-1,j);
    else
        afis(i,j-1);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    subsir();
    printf("%d\n",c[n][m]);
    afis(n,m);
    return 0;
}
