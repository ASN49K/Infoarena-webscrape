#include <fstream>
using namespace std;

int main()
{
    ifstream fin("cmlsc.in");
    int a[1024] , b[1024], c[1024];
    int m, n, p, i, j, nr;
    
    fin >> n >> m;
    
    for ( i = 0; i < n; i++)
        fin >> a[i];
    for ( j = 0; j < m; j++)
        fin >> b[j];
        fin.close();
    
    ofstream fout("cmlsc.out");
    p = 0; nr = 0;
    int gasit;
    for ( i = 0; i < n; i++)
    {
        gasit = 0;
        for ( j = 0; j < m; j++)
            if ( a[i] == b[j] )
            {
                 gasit = 1;
                 nr++;
                 break;
            }
        if (gasit)
        c[p++] = a[i];
    }
    fout << nr << '\n';
    for ( i = 0; i < p; i++)
        fout << c[i] << ' ';
        fout.close();
        return 0;
}
