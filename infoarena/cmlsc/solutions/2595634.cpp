#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int m, n, a[1025], b[1025], i, j, mx = 0, c[1025];
    fin >> m >> n;
    for(i=1; i<=m; i++)
        fin >> a[i];
     for(j=1; j<=n; j++)
        fin >> b[j];
    for(i=1; i<=n; i++)
        for(j=i; j<=m-n+i; j++)
            if(b[i]==a[j])
                {
                    mx++;
                    i++;
                    c[mx]=a[j];
                }
    fout << mx << "\n";
    for(i=1; i<=mx; i++)
        fout << c[i] << ' ';

    return 0;
}
