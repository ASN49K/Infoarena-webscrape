using namespace std;
#include <fstream>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int d[1200][1200];
int main ()
{

    int n,m,i,j,a[1200],b[1200];

    f>>n>>m;

    for(i=1; i<=n; i++)
        f>>a[i];

    for(i=1; i<=m; i++)
        f>>b[i];

    for(i=n; i>=1; i--)
        for(j=m; j>=1; j--)
        {
            if(a[i]==b[j]) d[i][j]=d[i+1][j+1]+1;
            else
            {
                if(d[i+1][j]>d[i][j+1]) d[i][j]=d[i+1][j];
                else d[i][j]=d[i][j+1];
            }
        }

    g<<d[1][1]<<'\n';

    for(i=1,j=1; i<=n && j<=m;)
    {
        if(a[i]==b[j])
        {
            g<<a[i]<<' ';
            i++;
            j++;
        }
        else
        {
            if(d[i+1][j]>d[i][j+1]) i++;
            else j++;

        }
    }



    return 0;
}

