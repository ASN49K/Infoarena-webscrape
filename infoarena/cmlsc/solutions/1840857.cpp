#include <iostream>
#include <fstream>
using namespace std;

int n, m, i, j, a[1025], b[1025], v[1025], c[1025], poz, nr, mx, t;
int main () {
    
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    
    fin >> n;
    fin >> m;
    for (i = 1; i <= n; i++)    fin >> a[i];
    for (i = 1; i <= m; i++)    fin >> b[i];
    
    poz = 1;
    
    for (t = 1; t <= n; t++)
    {
        for (i = t; i <= n; i++)
        {
            for (j = poz; j <= m; j++)
            {
                if (a[i] == b[j])
                {
                    nr++;
                    v[nr] = a[i];
                    poz = j+1;
                    j = m;
                }
            }
            if (nr > mx)
            {
                mx = nr;
                for (j = 1; j <= nr; j++)   c[j] = v[j];
            }
        }
        poz = 1;
        nr = 0;
    }
    
    fout << mx << "\n";
    for (i = 1; i <= mx; i++)   fout << c[i] << " ";
}
