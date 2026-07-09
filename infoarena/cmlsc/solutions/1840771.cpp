#include <iostream>
#include <fstream>
using namespace std;

int n, m, i, j, a[100], b[100], v[100], poz, nr, mx;
int main () {
    
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    
    fin >> n;
    fin >> m;
    for (i = 1; i <= n; i++)    fin >> a[i];
    for (i = 1; i <= m; i++)    fin >> b[i];
    
    poz = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = poz; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                nr++;
                v[nr] = a[i];
                poz = j+1;
            }
        }
    }
    
    fout << nr << "\n";
    for (i = 1; i <= nr; i++)   fout << v[i] << " ";
}
