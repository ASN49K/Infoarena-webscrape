#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//ifstream fin("./date.txt");
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1025], b[1025], d[1025][1025];

vector <int> sol;

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i <= m; ++i)
        fin >> b[i];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            //cerr << a << " " << b << '\n';
            if (a[i] == b[j])
            {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]) + 1;
                sol.push_back(a[i]);
                break;
            }
            else
            {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }
    fout << d[n][m] << '\n';
    for (int i = 0; i < sol.size(); ++i)
    {
        fout << sol[i] << " ";
    }
}
