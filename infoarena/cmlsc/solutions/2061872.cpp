#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");


int main()
{

    int i, j, n, m, k;
    in>>m>>n;

    int a[m+1],b[n+1], c[m+1][n+1], d[m+1];

    for(i=1; i<=m; i++)
       in>>a[i];

    for(j=1; j<=n; j++)
        in>>b[j];

    for(i=0; i<=m; i++)
        c[i][0] = 0;

    for(j=0; j<=n; j++)
        c[0][j] = 0;


    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {   if(a[i] == b[j])
                c[i][j] = c[i-1][j-1] + 1;
            else c[i][j] = max(c[i-1][j], c[i][j-1]);

        }


    i--;
    j--;

    k=0;
    while(c[i][j] !=0 )
    {
        if(a[i] == b[j])
        {
            d[k] = a[i];
            k++;
            i--;
            j--;
        }
        else if(c[i-1][j] < c[i][j-1])
        {
            j--;
        }
        else
        {
            i--;
        }

    }

    out<<c[m][n]<<'\n';
    for(i=k-1; i>=0;i--)
    {
        out<<d[i]<<" ";
    }


    return 0;
}
