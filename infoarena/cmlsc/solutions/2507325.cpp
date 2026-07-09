#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int n, m, i, j, v[1025], x[1025], subsir[1026][1026], abscisa, ordonata, k ,rez[1025];


int main()
{
    f >> n >> m;
     for (i=1; i<=n; i++)
           f >> v[i];
     for (i=1; i<=m; i++)
          f >> x[i];
    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (x[i] != v[j])
                subsir[i][j] = max(subsir[i-1][j], subsir[i][j-1]);
                else {
                    subsir[i][j] = 1 + subsir[i-1][j-1];
                }
        }
    }
    abscisa = m; ordonata = n;
    g << subsir[m][n] << '\n';
    while (subsir[abscisa][ordonata])
    {
        while (subsir[abscisa-1][ordonata] == subsir[abscisa][ordonata])
              abscisa--;
        while (subsir[abscisa][ordonata-1] == subsir[abscisa][ordonata])
              ordonata --;
        k ++;
        rez[k] = x[abscisa];
        abscisa --; ordonata --;
    }
    for (i=k; i>=1; i--)
         g << rez[i] << " ";

    return 0;
}
