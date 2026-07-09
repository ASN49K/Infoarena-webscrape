#include <cstdio>
#define maximum(a,b)((a>b)?a:b)
using namespace std;

int a[1025],b[1025],d[1025][1025],s[1025],m,n;

int main()
{
    int i,j,cnt;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=maximum(d[i-1][j],d[i][j-1]);
        }
    }
    cnt=0;
    for(i=n,j=m;i;)
        if(a[i]==b[j])
            {
                s[cnt]=a[i];
                cnt++;
                --i;
                --j;
            }
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else i--;
    printf("%d\n",cnt);
    for(i=cnt-1;i>=0;--i)
        printf("%d ",s[i]);
    return 0 ;
}
