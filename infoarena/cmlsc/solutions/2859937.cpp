#include <fstream>

using namespace std;

int a[1024], b[1024], d[1024][1024], sir[1024];

int main()
{
    int n, m, k;
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];
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
    fout << k << '\n';
    for (int i = k; i >= 1; i--)
        fout << sir[i] << ' ';
    return 0;
}
