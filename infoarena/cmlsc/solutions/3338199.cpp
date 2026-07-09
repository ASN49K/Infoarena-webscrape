#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ifstream g("cmlsc.out");

vector<int> a;
vector<int> b;
vector<vector<int>> c;
vector<int> lcs;

int main()
{
    int m, n;
    f >> m >> n;
    a.resize(m);
    b.resize(n);
    for(int i = 0; i < m; i++)
        f >> a[i];
    for(int i = 0; i < n; i++)
        f >> b[i];

    c.assign(m + 1, vector<int> (n + 1, 0));
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            if(a[i - 1] == b[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
        }
    
    int i = m, j = n;
    while(i && j)
    {
        if(a[i - 1] == b[j - 1])
        {
            lcs.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if(c[i - 1][j] >= c[i][j - 1])
            i--;
        else
            j--;
    }

    g << c[m][n] << "\n";
    for(int i = lcs.size() - 1; i >= 0;  i--)
        g << lcs[i] << " ";
    return 0;
}