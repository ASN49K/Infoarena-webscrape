# include <fstream>
# include <iostream>
using namespace std;
short a[1025],b[1025];
short c[1025][1025];
short d[1025];
int main()
{
    int n1,n2,i,j;
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);

    scanf ("%d%d",&n1,&n2);
    for (i=1;i<=n1;i++)
    {
        scanf ("%d",&a[i]);
        c[i][0]=0;
    }
    for (i=1;i<=n2;i++)
    {
        scanf ("%d",&b[i]);
        c[0][i]=0;
    }
    for (i=1;i<=n1;i++)
    {
        for (j=1;j<=n2;j++)
        {
            if (a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
            else
            {
                if (c[i][j-1]>c[i-1][j]) c[i][j]=c[i][j-1];
                else c[i][j]=c[i-1][j];
            }
        }
        //cout<<c[i][j];
    }
    i=n1;j=n2;int k=0;
    while (c[i][j])
    {
        if (a[i]==b[j])
        {
            d[++k]=a[i];
            i--;
            j--;
        }
        else
        {
             if (c[i][j-1]>c[i-1][j]) j--;
             else i--;
        }
    }
    for (i=k;i>=1;i--) printf("%d ",d[i]);
    return 0;
}
