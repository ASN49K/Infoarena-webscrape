#include <fstream>

using namespace std;

int n, m, a[1024], b[1024], d[1024][1024], sir[1024], k;

void citire()
{
    ifstream fin("cmlsc.in");
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];
}

void rezolvare()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);

    int i = n;
    int j = m;
    while(i)
        if (a[i] == b[j])
        {
            sir[++k] = a[i];
            i--;
            j--;
        }
        else if (d[i-1][j] < d[i][j-1])
            j--;
        else
            i--;
}

void afisare()
{
    ofstream fout("cmlsc.out");
    fout << k << '\n';
    for (int i = k; i >= 1; i--)
        fout << sir[i] << ' ';
}

int main()
{
    citire();
    rezolvare();
    afisare();

    return 0;
}
