#include <fstream>
using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int d[10001][10001];

int main()
{
    int n, m, i, j, a[10001], b[10001];
    in >> n >> m;
    for(i=1; i<=n; i++)
    {
        in >> a[i];
    }
    for(i=1; i<=m; i++)
    {
        in >> b[i];
    }
    i=1;
    j=1;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
        if(a[i]==b[j])
        {
            d[i][j]=d[i-1][j-1]+1;

        }
        if(a[i]!=b[j])
        {
            if(d[i-1][j]>d[i][j-1])
            {
                d[i][j]=d[i-1][j];
            }
            else
            {
                d[i][j]=d[i][j-1];
            }
        }
        }
    }
    out << d[n][m] << "\n";
    for(i=0; i<n; i++)
    {
        if(d[i][m]<d[i+1][m])
        {
            out << a[i+1] << " ";
        }
    }
    return 0;
}
