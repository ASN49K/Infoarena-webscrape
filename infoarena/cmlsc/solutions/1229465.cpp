#include <cstdio>
#define max(a,b)(a>b?a:b)
using namespace std;

int a[1025],b[1025],d[1025][1025],s[1025],m,n,count;

int main()
{
    int i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w"stdout);
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<m;i++)
        scanf("%d",&b[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1],d[j-1]);
        }
    }
    count=0;
    for(i=n,j=m;i;)
        if(a[i]=b[j])
            s[++count]=a[i],--i,--j;
        else if(d[i-1][j]<d[i][j-1])
            --j;
        else --i;
    printf("%d\n",count);
    for(i=count;i;--i)
        printf("%d",s[i]);
    return 0 ;
}
