#include <cstdio>

using namespace std;
int a[1025],b[1025],c[1025][1025],n,m;
int maxim(int x,int y)
{
    if(x>y)
        return x;
    return y;
}
void prelucrare()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=maxim(c[i][j-1],c[i-1][j]);
        }
    }
}
void afisare(int i,int j)
{
    if(c[i][j]==0)
    {
        return;
    }
    if(a[i]==b[j])
    {
        afisare(i-1,j-1);
        printf("%d ",a[i]);
        return;
    }
    if(c[i-1][j]>c[i][j-1])
    {
        afisare(i-1,j);
    }
    else
        afisare(i,j-1);
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    //freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int j=1;j<=n;j++)
        scanf("%d",&a[j]);
    prelucrare();
    printf("%d\n",c[n][m]);
    afisare(n,m);
    return 0;
}
