#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int m, n, a[1025], b[1025], i, j, c[1025][1025];
    fin >> m >> n;
    for(i=1; i<=m; i++)
        fin >> a[i];
    for(j=1; j<=n; j++)
        fin >> b[j];

    for(i=0; i<=m; i++)
        c[i][0] = 0;
    for(i=1; i<=n; i++)
        c[0][i] = 0;

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i] == b[j])
                c[i][j] = 1 + c[i-1][j-1];
            else if(c[i-1][j] > c[i][j-1])
                    c[i][j] = c[i-1][j];
                 else c[i][j] = c[i][j-1];

    int index = c[m][n];
    fout << index;
    int sol[index + 1];
    i = m;
    j = n;

    while(i > 0 && j > 0)
        if(a[i] == b[j])
    {
            sol[index] = a[i];
            i--;
            j--;
            index--;
    }
        else if(c[i-1][j] > c[i][j-1])
                    i--;
             else j--;

    for(i=1; i<=c[m][n]; i++)
        fout << sol[i] << ' ';




    return 0;
}
