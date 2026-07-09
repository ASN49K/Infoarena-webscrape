#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int maxs[1026][1026];

int main()
{
    int a[1026],b[1026];
    int m,n,i,j;
    in>>m>>n;

    for(i=1; i<=m; i++)
        in>>a[i];

    for(i=1; i<=n; i++)
        in>>b[i];

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            if(maxs[i-1][j] > maxs[i][j-1])
                maxs[i][j] = maxs[i-1][j];
            else
                maxs[i][j] = maxs[i][j-1];

            if(a[i] == b[j])
                maxs[i][j]++;
        }

    out<<maxs[m][n]<<'\n';

    int c = 0;
    i = m; j = n;
    while(i> 0 && j> 0)
    {
        if(maxs[i-1][j] == maxs[i][j]) i--;
        else if(maxs[i][j - 1] == maxs[i][j]) j--;
        else
        {
            b[c] = a[i];
            c++;
            i--; j--;
        }
    }

    for(i=c - 1;i>=0;i--)
        out<<b[i]<<' ';

    return 0;
}
