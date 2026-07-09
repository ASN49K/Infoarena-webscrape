#include<cstdio>
#include<algorithm>
using namespace std;
short n,m,i,j,x,y,ma,v[1024],a[1024],b[1024],c[1024][1024];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%hd %hd",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%hd",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%hd",&b[i]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
            if(c[i][j]>ma)
            {
                ma=c[i][j];
                x=i;
                y=j;
            }
        }
    }
    printf("%hd\n",c[n][m]);
    i=x;
    j=y;
    while(ma>0)
    {
        if(a[i]==b[j])
        {
            v[ma]=a[i];
            ma--;
            i--;
            j--;
        }
        else if(c[i][j-1]==c[i][j])j--;
        else i--;
    }
    for(i=1;i<=c[n][m];i++)
        printf("%hd ",v[i]);
    return 0;
}
