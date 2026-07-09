#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
unsigned long long x,y,n,m,m1,n1,i,j,h[1025][1025],a[1025],b[1025],p,Max,t[1025];
int main()
{
    f>>m1>>n1;
    for (i=1;i<=m1;i++)
        f>>a[i];
    for (i=1;i<=n1;i++)
        f>>b[i];

    m=x;
    n=y;
        for (i=1;i<=m1;i++)
            for(j=1;j<=n1;j++)
            if (a[i]==b[j])
            h[i][j]=1+h[i-1][j-1];
        else
        {
            if (h[i][j-1]>=h[i-1][j])
                h[i][j]=h[i][j-1];
            else
                h[i][j]=h[i-1][j];
        }

        Max=h[m1][n1];p=Max;g<<Max;
        g<<endl;
        for (i=m1;i>=1;i--)
            for (j=n1;j>=1;j--)
            {if (a[i]==b[j] && Max==h[i][j])
            {t[h[i][j]]=a[i];
            Max--;}

            }
            for (i=1;i<=p;i++)
                g<<t[i]<<" ";

    return 0;
}
