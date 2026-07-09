#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int m, n, a[1026], b[1026], v[260], lmax;
///d[i] - cea mai lunga secventa comuna ce incepe de pe pozitia i
int main()
{

    fin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        fin >> a[i];
        v[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        fin >> b[i];
        if (v[b[i]] == 0) v[b[i]] = -1;
        if (v[b[i]] == 1)
        {
            v[b[i]] = 2;
            lmax++;
        }
    }
    fout << lmax << "\n";
    for (int i = 0; i <= 256; i++)
        if (v[i] == 2) fout << i << " ";
    fin.close();
    fout.close();
    return 0;
}
