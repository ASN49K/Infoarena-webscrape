#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int maxs[1026][1026];

int main()
{
    int a[1026],b[1026],r[1026];
    int m,n,i,j;
    in>>m>>n;

    for(i=1; i<=m; i++)
        in>>a[i];

    for(i=1; i<=n; i++)
        in>>b[i];

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            if(a[i] == b[j])
                maxs[i][j] = maxs[i-1][j-1] + 1;
            else if(maxs[i-1][j] < maxs[i][j-1])
                maxs[i][j] = maxs[i][j-1];
            else
                maxs[i][j] = maxs[i-1][j];
        }

    out<<maxs[m][n]<<'\n';

    int c = 0;
    i = m;
    j = n;
    while(i> 0 && j> 0)
    {
        if (a[i] == b[j])
        {
            r[c] = a[i];
            c++;

            i--;
            j--;
        }
        else if(maxs[i - 1][j] >= maxs[i][j - 1]) i--;
        else j--;
    }

    for(i=c - 1; i>=0; i--)
        out<<r[i]<<' ';

    return 0;
}
