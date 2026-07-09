#include <fstream>

using namespace std;

int m, n, a[1025], b[1025];
int rez[1025], krez;

void citire()
{
    ifstream fin("cmlsc.in");
    fin >> m >> n;
    for(int i = 1; i <= m; i++)
        fin >> a[i];
    for(int i = 1; i <= n; i++)
        fin >> b[i];
}

void generare_rez()
{
    int endb = 0;
    for(int i = 1; i <= m && endb < n; i++)
    {
        bool ok = false;
        for(int j = endb+1; j <= m && !ok; j++)
            if(a[i] == b[j])
            {
                ok = true;
                endb = j;
                rez[++krez] = a[i];
            }
    }
}

void afisare()
{
    ofstream fout("cmlsc.out");
    fout << krez << '\n';
    for(int i = 1; i <= krez; i++)
        fout << rez[i] << ' ';
}

int main()
{
    citire();
    generare_rez();
    afisare();
    return 0;
}
