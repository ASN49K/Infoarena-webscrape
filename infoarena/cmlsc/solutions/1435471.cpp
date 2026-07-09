using namespace std;
#include <fstream>
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int n,m,a[1030],b[1030],i,d[1030][1030],j,k,sir[1030];

int main ()
{


    f>>n>>m;

    for(i=1; i<=n; i++) f>>a[i];
    for(i=1; i<=m; i++) f>>b[i];

    for(i=n; i>=1; i--)
    {
        for(j=m; j>=1; j--)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i+1][j+1]+1;

            }
            else
            {
                if(d[i][j+1]>d[i+1][j]) d[i][j]=d[i][j+1];
                else d[i][j]=d[i+1][j];
            }
        }
    }

    for (i=1, j=1; i<=n && j<=m; )
    {
        if(a[i]==b[j])
        {
            sir[++k]=a[i];
            i++;
            j++;
        }
        else
        {
            if(d[i][j+1]>d[i+1][j]) j++;
            else i++;
        }
    }
    g<<d[1][1]<<'\n';
    for(i=1; i<=k; i++) g<<sir[i]<<' ';
    return 0;
}
