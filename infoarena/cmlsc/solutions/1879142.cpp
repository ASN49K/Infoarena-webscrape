#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,i,j,a[1025],b[1025],d[1025][1025];
int s[1025],t;
void afis()
{
    int i,j;
    i=n;
    j=m;
    while (i && j)
        if (a[i]==b[j])
        {
            s[++t]=a[i];
            i--;
            j--;
        }
        else if (d[i][j-1]>d[i-1][j]) j--;
        else i--;
}

int main()
{
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    scanf("%i%i",&n,&m);
    for (i=1;i<=n;i++)
        scanf("%i",&a[i]);
    for (j=1;j<=m;j++)
        scanf("%i",&b[j]);

    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
            else d[i][j]=max(d[i][j-1],d[i-1][j]);

    printf("%i\n",d[n][m]);
    afis();
    for (i=t;i>=1;i--)
        printf("%i ",s[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
