#include <cstdio>

using namespace std;

int a[1025][1025],s1[1025],s2[1025],n,m;

int maxim(int a, int b)

{
    if (a>b)
        return a;
    return b;
}

void read()
{
    scanf("%d %d",&m,&n);
    for (int i=1;i<=m;i++)
        scanf("%d",&s1[i]);
    for (int i=1;i<=n;i++)
        scanf("%d",&s2[i]);
}

void dinam()
{
//for (int i=0;i<=m;i++)
//  a[0][i]=0;
//for (int i=0;i<=n;i++)
// a[i][0]=0;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            if (s1[i]!=s2[j])
                a[i][j]=maxim(a[i-1][j],a[i][j-1]);
            else
                a[i][j]=1+a[i-1][j-1];
        }
    printf("%d",a[m][n]);
}

void rec(int i, int j)
{
    if(i<=1 && j<=1)
        return;
    if ((a[i][j]==a[i-1][j-1]+1 && a[i-1][j-1]!=0) || (a[i][j]==a[i-1][j-1]+1 && a[i][j-1]==0 && a[i-1][j]==0))
    {
        printf("%d ",s1[i]);
        rec(i-1,j-1);
    }
    else
    if (a[i-1][j]>a[i][j-1])
        rec(i-1,j);
    else
        rec(i,j-1);
    /*if (a[i][j]>a[i-1][j] && a[i][j]>a[i][j-1])
        printf("%d ",s1[i]);*/

}

int main()

{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    read();
    dinam();
    printf("\n");
    rec(m,n);
return 0;
}
