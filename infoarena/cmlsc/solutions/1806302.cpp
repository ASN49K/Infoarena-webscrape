#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], d[1025][1025], sir[1025];

int maxim(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    int n, m, i , j, bst = 0;
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        fin >> a[i];
    for(int i = 1; i <= m; ++i)
        fin >> b[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = maxim(d[i-1][j], d[i][j-1]);
        }
    i = n, j = m;

    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
    }
    fout << bst << '\n';
    for(int i = bst; i >= 1; --i)
        fout << sir[i] << " ";

    fin.close();
    fout.close();
    return 0;
}
