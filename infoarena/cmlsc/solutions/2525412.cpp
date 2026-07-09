#include <fstream>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int f[256];
int main()
{
    vector < int > a;
    vector < int > b;

    int n, m, i, j, k = 0, x, y, cnt = 0;
    fin >> n >> m;

    int gasit[1024];

    for (i = 0; i < n; ++i)
    {
        fin >> x;
        a.push_back(x);
    }

    for (i = 0; i < m; ++i)
    {
        fin >> y;
        b.push_back(y);
    }

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        if (f[b[j]] == 0)
        {
            if (a[i] == b[j])
            {
                gasit[k] = a[i];
                k++;
                break;
            }
        }
    }

    fout << k << "\n";

    for (i = 0; i < k; ++i)
        fout << gasit[i] << " ";
    return 0;
}
