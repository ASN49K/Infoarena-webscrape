#include<cstdio>

#include<fstream>

using namespace std;

#define maxim(a,b) ((a>b) ? a : b)

int n,m,a[1005],b[1005],d[1005][1005],sir[1005],br;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d",&b[i]);
    }
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(a[i]==b[j])
            {
                d[i][j]=1+d[i-1][j-1];
            }
            else
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);
        }
    }
    int i=n,j=m;
    while(d[i][j]>0&&i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            br++;
            sir[br]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i][j-1]<d[i-1][j])
                i--;
            else
                j--;
        }
    }
    printf("%d\n",br);
    for(int i=br; i>=1; i--)
        printf("%d ",sir[i]);

    return 0;
}
