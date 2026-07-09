#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
vector<int> v1, v2, sol;
int a[1024][1024];

int main()
{
    fin >> n >> m;
    int i, x, j;
    for (i = 0; i < n; i++)
    {
        fin >> x;
        v1.push_back(x);
    }
    for (i = 0; i < m; i++)
    {
        fin >> x;
        v2.push_back(x);
    }
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (v1[i] == v2[i])
            {
                a[i][j] = a[i - 1][j - 1] + 1;
            }
            else
            {
                a[i][j] = max(a[i][j - 1], a[i - 1][j]);
            }
        }
    }
    for (i = n, j = m; i;)
    {
        if (v1[i] == v2[j])
        {
            sol.push_back(v1[i]);
            i--;
            j--;
        }
        else
        {
            if (a[i][j - 1] > a[i - 1][j])
            {
                j--;
            }
            else
                i--;
        }
    }
    fout << sol.size() << '\n';
    reverse(sol.begin(), sol.end());
    for (int x : sol)
    {
        fout << x << ' ';
    }
    return 0;
}