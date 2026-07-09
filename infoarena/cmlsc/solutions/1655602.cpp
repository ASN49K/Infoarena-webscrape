#include <cstdio>
int a[1025], b[1025] ,c[1025][1025], d[1025];
using namespace std;

int maxim(int a , int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    //    c[i][0]=0;
    }

    for(j=1;j<=m;j++)
    {
        scanf("%d",&b[j]);
      //  c[0][j]=0;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if (a[i] == b[j])
                c[i][j]= c[i-1][j-1] + 1;
            else
                c[i][j]= maxim(c[i-1][j], c[i][j-1]);
    printf("%d\n",c[n][m]);
    i=n;
    j=m;
    int cnt=0;
    while(i>0 && j>0)
    {
        if(a[i]==b[j]){
            d[++cnt]=a[i];
            i--;
            j--;
        }
        else if(c[i-1][j] < c[i][j-1])
            j--;
        else
            i--;
    }
    for(i=cnt;i>0;i--)
        printf("%d ",d[i]);
    return 0;
}
