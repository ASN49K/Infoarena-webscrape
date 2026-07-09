#include <cstdio>
#include <algorithm>
using namespace std;
short m,n,i,j,a[1025],b[1025],c[1025],d[1025][1025];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%hd%hd",&m,&n);
    for(i=1;i<=m;i++)
        scanf("%hd",&a[i]);
    for(j=1;j<=n;j++)
        scanf("%hd",&b[j]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    i=m;
    j=n;
    c[0]=0;
    while(i)
        if(a[i]==b[j])
        {
            c[0]++;
            c[c[0]]=a[i];
            i--;
            j--;
        }
        else
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
    printf("%hd\n",c[0]);
    for(i=c[0];i>=1;i--,printf(" "))
        printf("%hd",c[i]);
    printf("\n");
    return 0;
}
